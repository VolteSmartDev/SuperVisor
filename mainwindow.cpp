#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "extravalues.h"
#include "connectdialog.h"
#include "generalsetdlg.h"
#include "changepwddlg.h"

#include <qsettings.h>
#include <qsqlquerymodel.h>
#include <qsqlrecord.h>
#include <qmessagebox.h>
#include <QListWidgetItem>
#include "gridtableheaderview.h"
#include <QDebug>
#include <QDateTime>
#include "filtertabledlg.h"

extern QSettings *settings;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //! [0]
    ui->setupUi(this);
    QStringList arg_monitor;
    arg_monitor<<"Hello"<<"My Dear";
    proc_Led1 = new QProcess();
    proc_Led1->setProgram("TABLE_MONITOR1.exe");
    proc_Led1->setArguments(arg_monitor);
    connect(proc_Led1, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(on_LED1_finished(int, QProcess::ExitStatus)));
    proc_Led2 = new QProcess();
    proc_Led2->setProgram("TABLE_MONITOR2.exe");
    proc_Led2->setArguments(arg_monitor);
    connect(proc_Led2, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(on_LED2_finished(int, QProcess::ExitStatus)));


    //! [3]
    udpSocket = new QUdpSocket(this);
    udpSocket2 = new QUdpSocket(this);
    hostAddr.setAddress("127.0.0.1");
    //! [3]

    loadSettings();
    createInterface();
    createTrayIconMenu();
    trayIcon->show();
    //! [0]

    //! [1]
    connect(&timer, &QTimer::timeout, this, &MainWindow::onCheckTimerout);
	tryCount = 0;

    connect(&logTimer, &QTimer::timeout, this, &MainWindow::saveStatusToDB);

    //! [1]

    //! [2]
	modbusDevice = new QModbusTcpClient(this);
    //! [2]

	//! [4]
	ui->actionDisconnect->setEnabled(false);
	connect(ui->actionDisconnect, &QAction::triggered, this, &MainWindow::on_actionDisconnect_triggered);
	//! [4]

	//! [5-tstatuslist]
	for (int i = 0; i < 48; i++)
	{
		entryList[i] = 0;
	}
	for (int i = 0; i < 16; i++)
	{
		stateList[i] = 3;
		laststateList[i] = 3;
        laststateList2[i] = 3;
	}
	//! [5]

	//! [5]
	loadMaterials();
    lastMaterialListId = 0;
	lastPrepId = 0;
	ui->tableList->setCurrentRow(0);
	showMaterialtoInputTable(1);
    materialInputChanged = false;
    lastPrepId = 0;
    setWindowIcon(QIcon(":/png/icon.png"));
	//! [5]

	/// auto connect
	if (isAutoConnect == true) {
		QTimer::singleShot(500, this, SLOT(connectModbus()));
	}

    // today product
    ui->date_todayproduct->setDate(QDate::currentDate());
    refresh_pduration();
}

MainWindow::~MainWindow()
{
    if (timer.isActive())
        timer.stop();

    if (modbusDevice)
        modbusDevice->disconnectDevice();
    delete modbusDevice;

    delete ui;
}

void MainWindow::loadSettings()
{
    isAutoConnect = settings->value(REG_AUTOCONNECT).toBool();
    isNodifySaved = settings->value(REG_NODIFYSAVE).toBool();
    refTimeInterval = settings->value(REG_REFRESHTIME).toInt();
    is_save_timer = settings->value(REG_EVENT_FLAG).toBool();
    if (refTimeInterval == 0) refTimeInterval = 1;
    saveTimeInterval = settings->value(REG_SAVEHISTTIME).toInt();
    deviceID = settings->value(SET_DEVICEID).toInt();
	timer.setInterval(refTimeInterval * 1000);

    saveLogInterval = settings->value(REG_SAVEHISTTIME).toInt();
    if (saveLogInterval == 0) saveLogInterval = 1;
    logTimer.setInterval(saveLogInterval * 60000);

    ui->checkBox_AutoRefresh->setChecked(settings->value(REG_AUTOREFRESH).toBool());
    bool is_auto_led = settings->value(REG_IS_AUTOLED).toBool();
    if (is_auto_led) {
        ui->actionLed1->setChecked(is_auto_led);
        ui->actionLED2->setChecked(is_auto_led);
        on_actionLed1_triggered(true);
        on_actionLED2_triggered(true);
    }

    // auto delete log
    is_auto_delete_log = settings->value(REG_DELETEPASTLOG).toBool();
    auto_delete_month = settings->value(REG_DELETEPASTDAY).toInt();
    if (is_auto_delete_log == true)
        delete_logs();

}

void MainWindow::createInterface()
{
    /// 0
    QFont listFont("Arial", 16 , 75);

    /// preparation
    ui->table_Prepare->setColumnWidth(1, 700);
    for (int i=0; i<8; i++) {
        QTableWidgetItem *item = new QTableWidgetItem("");
        ui->table_Prepare->setItem(i, 1, item);
    }
    showPreparation(1);

    //! [1]
    ui->table_YStatus->setColumnWidth(0, 120);
    ui->table_YStatus->setColumnWidth(1, 500);

    ui->table_RStatus->setColumnWidth(0, 120);
    ui->table_RStatus->setColumnWidth(1, 500);

    //! [1]

	//! [tablewidgetitems for status table]
    for (int i = 0; i < 16; i++)
	{
        /// message management
        QTableWidgetItem *item = new QTableWidgetItem("");
        ui->table_YStatus->setItem(i, 1, item);

        item = new QTableWidgetItem("");
        ui->table_RStatus->setItem(i, 1, item);

        /// table list
        QListWidgetItem *listWidgetItem = new QListWidgetItem(tr("TABLE  %1").arg(i+1));
        listWidgetItem->setFont(listFont);
        listWidgetItem->setTextColor(Qt::darkGray);
        ui->tableList->addItem(listWidgetItem);

	}
	//! []

    //! [2]
    ui->table_TableMaterialList->setColumnWidth(0, 100);
    int mCWidth = (this->width()-160-ui->table_InputMaterial->width()) / 8;
    for (int i=1; i<ui->table_TableMaterialList->rowCount(); i++) {
        ui->table_TableMaterialList->setColumnWidth(i, mCWidth);
    }

    ui->table_InputMaterial->setColumnWidth(0, 150);
    ui->table_InputMaterial->setColumnWidth(1, 120);
    ui->table_InputMaterial->setColumnWidth(2, 80);
    //! [2]

    //! [3]
    QVBoxLayout *layout = new QVBoxLayout();
    layout->setContentsMargins(16, 24, 16, 16);

    QFont headerFont("Ms Shell Dlg 2", 18, 81);
    QLabel *tab3Header = new QLabel("Logging Graphs");
    tab3Header->setFont(headerFont);
    tab3Header->setAlignment(Qt::AlignCenter);
    tab3Header->setStyleSheet("color: rgb(255, 85, 0);");

    QDate curDate = QDate::currentDate();
    QTime curTime = QTime::currentTime();
    ui->dateTimeEdit2->setDate(curDate);
    ui->dateTimeEdit2->setTime(curTime);

    ui->dateTimeEdit1->setDate(curDate.addDays(-1));
    ui->dateTimeEdit1->setTime(curTime);

    ui->dateTimeEdit21->setDate(curDate.addDays(-1));
    ui->dateTimeEdit21->setTime(curTime);
    ui->dateTimeEdit22->setDate(curDate);
    ui->dateTimeEdit22->setTime(curTime);
    ///

    //! [3]

    //! [4--message]
	loadMessage();
    ui->btn_UndoPrep->setEnabled(false);
    //! [4]

    /// table_TableStatus
    statusLabels<<"ON PROCESS"<<"WAITING"<<"STOP"<<"NO SIGNAL";
    statusHeaderLabels<<"Date"<<"Time";
    ui->table_TableStatus->setColumnCount(34);


    GridTableHeaderView *header_Status = new GridTableHeaderView(Qt::Horizontal, 2, 34);

    ui->table_TableStatus->setHorizontalHeader(header_Status);
    header_Status->setSpan(0, 0, 2, 0);
    header_Status->setCellLabel(0, 0, "Date");
    header_Status->setSpan(0, 1, 2, 0);
    header_Status->setCellLabel(0, 1, "Time");



    for (int i = 2; i < 34; i += 2) {
        header_Status->setSpan(0, i, 0, 2);
        header_Status->setCellLabel(0, i, tr("Table %1").arg(i/2));
        header_Status->setCellLabel(1, i, "Status");
        header_Status->setCellLabel(1, i+1, tr("Message"));
    }

    for (int i=1; i<=16; i++) {
        statusHeaderLabels<<tr("Table %1").arg(i);
    }

    header_Status->setRowHeight(0, 26);
    header_Status->setRowHeight(1, 26);

    ui->table_TableStatus->resizeRowsToContents();
    refresh_table_filter();
   // ui->table_TableStatus->setHorizontalHeaderLabels(statusHeaderLabels);

	/// table_message
	ui->table_Message->setColumnWidth(4, 500);


    /// product count
    ui->dateFrom_pd->setDate(curDate.addDays(-1));
    ui->dateTo_pd->setDate(curDate);
    show_productCount();

    ui->date_from_pdlog->setDate(curDate.addDays(-1));
    ui->date_to_pdlog->setDate(curDate);
}

void MainWindow::createTrayIconMenu()
{
    act_restore = new QAction("Restore", this);
	act_restore->setEnabled(false);
    connect(act_restore, &QAction::triggered, this, &MainWindow::showMaximized);
    act_connect = ui->actionConnect;
    act_disconnect = ui->actionDisconnect;
    act_setting = ui->actionSettings;
    act_quit = new QAction("Quit", this);
    connect(act_quit, &QAction::triggered, qApp, &QApplication::quit);

    QMenu *trayMenu = new QMenu(this);
    //trayMenu->addAction(act_restore);
    //trayMenu->addSeparator();
    trayMenu->addAction(act_connect);
    trayMenu->addAction(act_disconnect);
    trayMenu->addSeparator();
    trayMenu->addAction(act_setting);
    trayMenu->addSeparator();
    trayMenu->addAction(act_quit);

    trayIcon = new QSystemTrayIcon(QIcon(":/png/icon.png"),this);
    trayIcon->setContextMenu(trayMenu);
}


QModbusDataUnit MainWindow::readRequest() const
{
    int startAddress = settings->value(SET_STARTADDR).toInt()-1;
    int numberOfEntries = settings->value(SET_ENTRYCOUNT).toInt();
    return QModbusDataUnit(QModbusDataUnit::DiscreteInputs, startAddress, numberOfEntries);
}

void MainWindow::on_actionConnect_triggered()
{
	ConnectDialog *dlg = new ConnectDialog();
	if (dlg->exec() != QDialog::Accepted) return;

	bool rslt = connectModbus();
	if (!rslt) {
		on_actionConnect_triggered();
	}
}

bool MainWindow::connectModbus()
{
    //! [0]
    if (modbusDevice) {
        modbusDevice->disconnectDevice();
        delete modbusDevice;
        modbusDevice = nullptr;
    }

    modbusDevice = new QModbusTcpClient(this);
    connect(modbusDevice, &QModbusClient::stateChanged,
            this, &MainWindow::onStateChanged);
    statusBar()->clearMessage();
    //! [0]

    //! [1]
    int port = settings->value(SET_PORT).toInt();
    QString host = settings->value(SET_IPADDRESS).toString();
    deviceID = settings->value(SET_DEVICEID).toInt();
    modbusDevice->setConnectionParameter(QModbusDevice::NetworkPortParameter, port);
    modbusDevice->setConnectionParameter(QModbusDevice::NetworkAddressParameter, host);

    //modbusDevice->setTimeout(m_settingsDialog->settings().responseTime);
    //modbusDevice->setNumberOfRetries(m_settingsDialog->settings().numberOfRetries);
	
    if (!modbusDevice->connectDevice()) {
        statusBar()->showMessage(tr("Connect failed: ") + modbusDevice->errorString(), 5000);
        return false;
    } else {
        // on success
        statusBar()->showMessage(tr("Connecting to %1:%2").arg(host).arg(port));
        isFirstConnectTime = true;
        timer.start();
        if (is_save_timer)
            logTimer.start();
		tryCount = 0;
		ui->actionConnect->setEnabled(false);
        ui->actionDisconnect->setEnabled(true);
        return true;
    }
    //! [1]
}

void MainWindow::readReady()
{
    auto reply = qobject_cast<QModbusReply *>(sender());
    if (!reply)
        return;

    if (reply->error() == QModbusDevice::NoError) {
        if (isFirstConnectTime) {
            trayIcon->showMessage("Connected", "Connected to PLC tables, getting status...");
            isFirstConnectTime = false;
        }
        const QModbusDataUnit unit = reply->result();

        for (uint i = 0; i < unit.valueCount(); i++) {
            const QString entry = tr("Address: %1, Value: %2").arg(unit.startAddress() + i)
                                     .arg(unit.value(i));

			int curTrigger = unit.value(i);

			/// save status
			if (i < 48) entryList[i] = curTrigger;
        }
		
		/// refresh state
		refreshTState();
    }
	/// handle error
	else if (reply->error() == QModbusDevice::ProtocolError) {
        trayIcon->showMessage(tr("Response Error"), tr("Read response error. Please check PLC device ID.")
                    ,QSystemTrayIcon::Warning, 5000);
        for (int i=0; i<48; i++) entryList[i] = 0;
    }
	else {
        trayIcon->showMessage(tr("Response Error"), tr("Read response error. Please check PLC device ID.")
                    ,QSystemTrayIcon::Warning, 5000);
        for (int i=0; i<48; i++) entryList[i] = 0;
    }

    reply->deleteLater();
}

void MainWindow::onStateChanged(int state)
{
    bool connected = (state != QModbusDevice::UnconnectedState);
    ui->actionConnect->setEnabled(!connected);
    ui->actionDisconnect->setEnabled(connected);

    //trayIcon->showMessage("Connected", "Connected to PLC tables, getting status...");

}

void MainWindow::onCheckTimerout()
{
    if (!modbusDevice)
        return;

    statusBar()->clearMessage();

    if (auto *reply = modbusDevice->sendReadRequest(readRequest(), deviceID)) {
        if (!reply->isFinished())
            connect(reply, &QModbusReply::finished, this, &MainWindow::readReady);
        else
            delete reply; // broadcast replies return immediately
    } else {
		statusBar()->showMessage(tr("Read error: %1").arg(modbusDevice->errorString()), 5000);
        trayIcon->showMessage("Disconnected", "Disconnected to PLC tables", QSystemTrayIcon::Warning);
        timer.stop();
        logTimer.stop();
    }
}

void MainWindow::saveStatusToDB()
{
    QDate tdate = QDate::currentDate();
    QTime ttime = QTime::currentTime();

    int this_date = tdate.year()*10000 + tdate.month()*100 + tdate.day();
    int this_time = ttime.hour()*100 + ttime.minute();

    QString qStr;
    bool flag = false;

    qStr = tr("INSERT INTO TimeHistoryTable (this_date,this_time,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,"
              "m_t1,m_t2,m_t3,m_t4,m_t5,m_t6,m_t7,m_t8,m_t9,m_t10,m_t11,m_t12,m_t13,m_t14,m_t15,m_t16) "
            "VALUES (%1,%2,%3,%4,%5,%6,%7,%8,%9,%10,%11,%12,%13,%14,%15,%16,%17,%18,"
            "'%19','%20','%21','%22','%23','%24','%25','%26','%27','%28','%29','%30','%31','%32','%33','%34')")
			.arg(this_date)
			.arg(this_time)
			.arg(stateList[0]).arg(stateList[1]).arg(stateList[2]).arg(stateList[3]).arg(stateList[4])
			.arg(stateList[5]).arg(stateList[6]).arg(stateList[7]).arg(stateList[8]).arg(stateList[9])
			.arg(stateList[10]).arg(stateList[11]).arg(stateList[12]).arg(stateList[13]).arg(stateList[14])
            .arg(stateList[15])
            .arg(messageList[0]).arg(messageList[1]).arg(messageList[2]).arg(messageList[3]).arg(messageList[4])
            .arg(messageList[5]).arg(messageList[6]).arg(messageList[7]).arg(messageList[8]).arg(messageList[9])
            .arg(messageList[10]).arg(messageList[11]).arg(messageList[12]).arg(messageList[13]).arg(messageList[14])
            .arg(messageList[15]);
    flag = query.exec(qStr);

    if (flag == true && isNodifySaved == true) trayIcon->showMessage(tr("Timing Status Saved"), tr("Status for each table saved into database successfully."));

    qDebug()<<flag;

    if (ui->checkBox_AutoRefresh->isChecked()){
        ui->dateTimeEdit2->setDate(tdate);
        ui->dateTimeEdit2->setTime(ttime);
        QTimer::singleShot(10, this, SLOT(on_btn_DisplayLogs_clicked()));
    }

	/// if this time as automatic export time
	QString regAutoExpTime = settings->value(REG_EXPORTTIME).toString();
	QString curTimeStr = ttime.toString("hh:mm");

	if (regAutoExpTime == curTimeStr) {
		exportDailyStatus();
	}
}

void MainWindow::on_actionDisconnect_triggered()
{
    //if (runQuestion("Are you sure to disconnect?") != QMessageBox::Yes) return;

	timer.stop();
	logTimer.stop();
	modbusDevice->disconnectDevice();
	ui->actionConnect->setEnabled(true);
	ui->actionDisconnect->setEnabled(false);
	statusBar()->showMessage("Succesfully disconnected.", 5000);
    trayIcon->showMessage("Disconnected", "Disconnected to PLC tables", QSystemTrayIcon::Warning);
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event)

    int mCWidth = (this->width()-160-ui->table_InputMaterial->width()) / 8;
    for (int i=1; i<ui->table_TableMaterialList->rowCount(); i++) {
        ui->table_TableMaterialList->setColumnWidth(i, mCWidth);
    }
}

void MainWindow::closeEvent(QCloseEvent* event) {

        if (timer.isActive() && runQuestion("This program is communicating with PLC tables.\nAre you sure to disconnect and close it?") != QMessageBox::Yes)
        {
            event->ignore();
            return;
        }
        proc_Led1->kill();
        proc_Led2->kill();
        event->accept();
}

void MainWindow::on_actionSettings_triggered()
{
    GeneralSetDlg *dlg = new GeneralSetDlg();
    if (dlg->exec() == QDialog::Accepted)
		loadSettings();
}

void MainWindow::on_btn_DisplayLogs_clicked()
{
    QDate date1 = ui->dateTimeEdit1->date();
    QTime time1 = ui->dateTimeEdit1->time();

    QDate date2 = ui->dateTimeEdit2->date();
    QTime time2 = ui->dateTimeEdit2->time();

    qint64 this_date1 = date1.year()*10000 + date1.month()*100 + date1.day();
    qint64 this_time1 = time1.hour()*100 + time1.minute();

    qint64 this_date2 = date2.year()*10000 + date2.month()*100 + date2.day();
    qint64 this_time2 = time2.hour()*100 + time2.minute();

    qint64 trigger1 = this_date1 * 10000 + this_time1;
    qint64 trigger2 = this_date2 * 10000 + this_time2;

    QSqlQueryModel tmpModel;
    QString qStr = tr("SELECT * FROM TimeHistoryTable WHERE this_date*10000+this_time >= %1 AND this_date*10000+this_time <= %2 "
                      "ORDER BY ID ASC")
            .arg(trigger1).arg(trigger2);

    tmpModel.setQuery(qStr);
	while (tmpModel.canFetchMore()) tmpModel.fetchMore();

    int rCnt = tmpModel.rowCount();
    ui->table_TableStatus->clearContents();
    ui->table_TableStatus->setRowCount(rCnt);

    QTableWidgetItem *item;

    for (int i=0; i<rCnt; i++) {
        QSqlRecord record = tmpModel.record(i);
        for (int j=0; j<18; j++) {

            if (j==0) {
                /// date
                QString dateStr = record.value(1).toString();
                dateStr = dateStr.insert(4, "/");  /// 2020/0323;
                dateStr = dateStr.insert(7, "/");

                item = new QTableWidgetItem(tr("%1").arg(dateStr));
                item->setTextAlignment(Qt::AlignCenter);
                ui->table_TableStatus->setItem(i, j, item);

                continue;
            }

            if (j==1) {
                QString timeStr = record.value(2).toString(); //2323
                timeStr = timeStr.length()==3? timeStr.insert(1, ":") : timeStr.insert(2, ":");
                item = new QTableWidgetItem(tr("%1").arg(timeStr));
                item->setTextAlignment(Qt::AlignCenter);
                ui->table_TableStatus->setItem(i, j, item);

                continue;
            }

            int int_curState = record.value(j+1).toInt();
            QString curState = statusLabels.at(int_curState);
            item = new QTableWidgetItem(tr("%1").arg(curState));
            item->setTextAlignment(Qt::AlignCenter);

            QString curMsg = record.value(j+17).toString();
            QTableWidgetItem *item1 = new QTableWidgetItem(tr("%1").arg(curMsg));

            switch(int_curState) {

            case 0: item->setBackgroundColor(Qt::darkGreen);
                item->setTextColor(Qt::white);
                item1->setBackgroundColor(Qt::darkGreen);
                item1->setTextColor(Qt::white);
                break;
            case 1: item->setBackgroundColor(Qt::yellow);
                item1->setBackgroundColor(Qt::yellow);
                break;
            case 2: item->setBackgroundColor(Qt::red);
                item->setTextColor(Qt::white);
                item1->setBackgroundColor(Qt::red);
                item1->setTextColor(Qt::white);
                break;
            case 3: item->setBackgroundColor(Qt::gray);
                item->setTextColor(Qt::white);
                item1->setBackgroundColor(Qt::gray);
                item1->setTextColor(Qt::white);
                break;
            default:
                item->setBackgroundColor(Qt::gray);
                item1->setBackgroundColor(Qt::gray);
                break;
            }

            ui->table_TableStatus->setItem(i, 2*(j-1), item);
            ui->table_TableStatus->setItem(i, 2*j-1, item1);

        }
    }

    ui->table_TableStatus->resizeColumnToContents(0);
    ui->table_TableStatus->resizeColumnToContents(1);
    ui->table_TableStatus->showRow(ui->table_TableStatus->rowCount()-1);

}

void MainWindow::on_checkBox_AutoRefresh_toggled(bool checked)
{
    settings->setValue(REG_AUTOREFRESH, checked);
    if (checked) on_btn_DisplayLogs_clicked();
}

void MainWindow::on_btn_ExportToCSV_clicked()
{
    if (ui->table_TableStatus->rowCount() == 0) {
        QMessageBox::warning(0, tr("Export to CSV File"), tr("There are not any data to export. please check date/time interval and click Display logs button."));
        return;
    }
    
	QDate date = QDate::currentDate();
	QTime time = QTime::currentTime();

	QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
		tr("statuslog_%1%2%3_%4%5%6.csv").arg(date.year()).arg(date.month()).arg(date.day()).arg(time.hour()).arg(time.minute()).arg(time.second()),
		tr("CSV Files (*.csv)"));

	if (fileName.isEmpty()) return;

	QFile file(fileName);
	if (!file.open(QIODevice::WriteOnly)) {
		QMessageBox::critical(0, tr("Export File"), tr("Cannot write this file. This file path is incorrect or this file is read-only.")); 
		return;
	}

	QTextStream out(&file);

    out<<"Date,Time";

    for (int i = 0; i < 16; i++)
	{
        out<<tr(",Table %1 Status,Message").arg(i+1);
	}

	out << endl;

	for (int i = 0; i < ui->table_TableStatus->rowCount(); i++)
	{
		for (int j = 0; j < ui->table_TableStatus->columnCount(); j++)
		{
			if (j == 0) out << ui->table_TableStatus->item(i, j)->text();
            else {
                QString a = ui->table_TableStatus->item(i, j)->text();
                if((a.indexOf(",") > -1)||(a.indexOf("\"") > -1)){
                    if(a.indexOf("\"") > -1){
                        a = a.replace("\"", "\"\"");
                    }
                    a = "\"" + a + "\"";
                }
                out << tr(",%1").arg(a);
            }
		}
		out << endl;
	}
	
	file.close();

	statusBar()->showMessage(tr("File Exported"), 5000);
	trayIcon->showMessage(tr("File Exported"), tr("%1 has been save successfully.").arg(fileName));
}


void MainWindow::exportDailyStatus()
{
	QDate date2 = QDate::currentDate();
	QTime time2 = QTime::currentTime();

	QDate date1 = date2.addDays(-1);
	QTime time1 = time2;

	qint64 this_date1 = date1.year() * 10000 + date1.month() * 100 + date1.day();
	qint64 this_time1 = time1.hour() * 100 + time1.minute();

	qint64 this_date2 = date2.year() * 10000 + date2.month() * 100 + date2.day();
	qint64 this_time2 = time2.hour() * 100 + time2.minute();

	qint64 trigger1 = this_date1 * 10000 + this_time1;
	qint64 trigger2 = this_date2 * 10000 + this_time2;

	QSqlQueryModel tmpModel;
	QString qStr = tr("SELECT * FROM TimehistoryTable WHERE this_date*10000+this_time > %1 AND this_date*10000+this_time <= %2 "
		"ORDER BY ID ASC")
		.arg(trigger1).arg(trigger2);

	tmpModel.setQuery(qStr);
	while (tmpModel.canFetchMore()) tmpModel.fetchMore();

	int rCnt = tmpModel.rowCount();

	QString fileName = settings->value(REG_EXPORTPATH).toString() + tr("/statuslog-%1-%2.csv")
																	.arg(date1.toString("yyyy-MM-dd")).arg(time1.toString("hh-mm"));

	QFile file(fileName);
	if (!file.open(QIODevice::WriteOnly)) {
		trayIcon->showMessage("Automatic Timing Status Export Failed", tr("Cannot write file: %1").arg(fileName));
	}


	QTextStream out(&file);

	//// header
	for (int i = 0; i < statusHeaderLabels.count(); i++)
	{
		if (i == 0) out << statusHeaderLabels.at(i);
		else out << tr(",%1").arg(statusHeaderLabels.at(i));
	}

	out << endl;

	/// content
	for (int i = 0; i<rCnt; i++) {
		QSqlRecord record = tmpModel.record(i);
		for (int j = 0; j<18; j++) {

			if (j == 0) {
				/// date
				QString dateStr = record.value(1).toString();
				dateStr = dateStr.insert(4, "/");  /// 2020/0323;
				dateStr = dateStr.insert(7, "/");

				out << dateStr;
				continue;
			}

			if (j == 1) {
				QString timeStr = record.value(2).toString(); //2323
				timeStr = timeStr.length() == 3 ? timeStr.insert(1, ":") : timeStr.insert(2, ":");
				out << "," << timeStr;
				continue;
			}

			int int_curState = record.value(j + 1).toInt();
			QString curState = statusLabels.at(int_curState);
			out << "," << curState;
		}
		out << endl;
	}

	file.close();
    trayIcon->showMessage(tr("Automatic Timing Status Export"), tr("%1 has been save successfully.").arg(fileName));
}

QString MainWindow::dateTime2String(QDateTime datetime)
{
    return datetime.toString("yyyy-MM-dd hh:mm:ss");
}

QString MainWindow::date2String(QDate date)
{
    return date.toString("yyyy-MM-dd 00:00:00");
}

int MainWindow::date2Int(QDate date)
{
    int input_date = date.year() * 10000 +
            date.month() * 100 + date.day();
    return input_date;
}

void MainWindow::delete_logs()
{
    QDate cdate = QDate::currentDate();
    QDate lastdate = cdate.addMonths(-auto_delete_month);
    int input_date = lastdate.year() * 10000 +
            lastdate.month() * 100 + lastdate.day();
    QSqlQuery tquery;

    // StatusHistoryTable
    tquery.exec(tr("DELETE FROM StatusHistoryTable WHERE this_date < %1").arg(input_date));
    // TimeHistoryTable
    tquery.exec(tr("DELETE FROM TimeHistoryTable WHERE this_date < %1").arg(input_date));
}

void MainWindow::refresh_table_filter()
{
    QStringList filterList = settings->value(REG_TABLE_FILTER).toStringList();
    if(filterList.count() < 16) return;
    for (int i=0; i<16; i++) {
        bool is_hide = filterList.at(i) == "0";
        ui->table_TableStatus->setColumnHidden(2 + 2 * i, is_hide);
        ui->table_TableStatus->setColumnHidden(3 + 2 * i, is_hide);
    }
}


void MainWindow::on_btn_DisplayLogs2_clicked()
{
	QDateTime curDTime = QDateTime::currentDateTime();
	ui->dateTimeEdit22->setDateTime(curDTime);

    QSqlQueryModel tmpModel;
    QString qStr = tr("SELECT [datetime], table_id, status, message FROM StatusHistoryTable WHERE message<>'' AND datetime >= #%1# AND datetime <= #%2# "
                      "ORDER BY ID ASC")
            .arg(dateTime2String(ui->dateTimeEdit21->dateTime()))
            .arg(dateTime2String(ui->dateTimeEdit22->dateTime()));

    tmpModel.setQuery(qStr);
    while (tmpModel.canFetchMore()) tmpModel.fetchMore();

    int rCnt = tmpModel.rowCount();
    ui->table_Message->clearContents();
    ui->table_Message->setRowCount(rCnt);

    QTableWidgetItem *item;

    for (int i=0; i<rCnt; i++) {
        QSqlRecord record = tmpModel.record(i);
        // 0 -- date, time 0, 1
        QDateTime tmpdatetime = record.value(0).toDateTime();

        item = new QTableWidgetItem(tmpdatetime.toString("yyyy-MM-dd"));
        item->setTextAlignment(Qt::AlignCenter);
        ui->table_Message->setItem(i, 0, item);

        item = new QTableWidgetItem(tmpdatetime.toString("hh:mm:ss"));
        item->setTextAlignment(Qt::AlignCenter);
        ui->table_Message->setItem(i, 1, item);

        // 1 table number 2
        item = new QTableWidgetItem(record.value(1).toString());
        item->setTextAlignment(Qt::AlignCenter);
        ui->table_Message->setItem(i, 2, item);

        // 2 status 3
        int int_curState = record.value(2).toInt();

        QString curState;

        if (int_curState == 5)
            curState = "(WAITING)";
        else if (int_curState == 6)
            curState = "(STOP)";
        else
            curState = statusLabels.at(int_curState);

        item = new QTableWidgetItem(tr("%1").arg(curState));
        item->setTextAlignment(Qt::AlignCenter);

        switch(int_curState) {

        case 0: item->setBackground(QBrush(Qt::darkGreen));
            break;
        case 1: item->setBackground(QBrush(Qt::yellow));
            break;
        case 2: item->setBackground(QBrush(Qt::red));
            break;
        case 3: item->setBackground(QBrush(Qt::gray));
            break;
        case 5: item->setBackground(QBrush(Qt::yellow));
            break;
        case 6: item->setBackground(QBrush(Qt::red));
            break;
        default:
            item->setBackgroundColor(Qt::gray);
            break;
        }

        ui->table_Message->setItem(i, 3, item);

        // 3 message 4
        QString tmpStr = record.value(3).toString();
        if (tmpStr.isEmpty()) tmpStr = "  ";
        item = new QTableWidgetItem(tmpStr);
        ui->table_Message->setItem(i, 4, item);
    }
}

void MainWindow::on_btn_ExportToCSV2_clicked()
{
	if (ui->table_Message->rowCount() == 0) {
		QMessageBox::warning(0, tr("Export to CSV File"), tr("There are not any data to export. please check date/time interval and click Display logs button."));
		return;
	}

	QDate date = QDate::currentDate();
	QTime time = QTime::currentTime();

	QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
		tr("messagelog_%1%2%3_%4%5%6.csv").arg(date.year()).arg(date.month()).arg(date.day()).arg(time.hour()).arg(time.minute()).arg(time.second()),
		tr("CSV Files (*.csv)"));

	if (fileName.isEmpty()) return;

	QFile file(fileName);
	if (!file.open(QIODevice::WriteOnly)) {
		QMessageBox::critical(0, tr("Export File"), tr("Cannot write this file. This file path is incorrect or this file is read-only."));
		return;
	}

	QTextStream out(&file);

	out << "Date,Time,TableNumber,Status,Message"<<endl;

	for (int i = 0; i < ui->table_Message->rowCount(); i++)
	{
		for (int j = 0; j < ui->table_Message->columnCount(); j++)
		{
			if (j == 0) out << ui->table_Message->item(i, j)->text();
            else {
                QString a = ui->table_Message->item(i, j)->text();
                if((a.indexOf(",") > -1)||(a.indexOf("\"") > -1)){
                    if(a.indexOf("\"") > -1){
                        a = a.replace("\"", "\"\"");
                    }
                    a = "\"" + a + "\"";
                }
                out << tr(",%1").arg(a);
            }
		}
		out << endl;
	}

	file.close();

	statusBar()->showMessage(tr("File Exported"), 5000);
	trayIcon->showMessage(tr("File Exported"), tr("%1 has been save successfully.").arg(fileName));
}

void MainWindow::on_actionChangePwd_triggered()
{
    ChangePwdDlg *dlg = new ChangePwdDlg();
    dlg->exec();
}

void MainWindow::on_btn_UndoPrep_clicked()
{
    if (runQuestion("Are you sure to undo preparation?") != QMessageBox::Yes) return;

    QSqlQueryModel tmpModel;
    QSqlQuery tmpQuery;

    tmpModel.setQuery("SELECT ID,last_material_name,last_status,last_enabled FROM MaterialTable");
    for (int i=0; i<tmpModel.rowCount(); i++) {

        QSqlRecord tmpRecord = tmpModel.record(i);
        QString qStr = tr("UPDATE MaterialTable SET material_name='%1',status=%2,enabled=%3 "
                          "WHERE ID=%4")
                .arg(tmpRecord.value(1).toString())
                .arg(tmpRecord.value(2).toInt())
                .arg(tmpRecord.value(3).toInt())
                .arg(tmpRecord.value(0).toInt());
        tmpQuery.exec(qStr);
    }

    loadMaterials();
    lastMaterialListId = 0;
    ui->table_TableMaterialList->setCurrentCell(lastMaterialListId, 1);
    showMaterialtoInputTable(lastMaterialListId + 1);
    ui->btn_UndoPrep->setEnabled(false);
}

void MainWindow::on_LED1_finished(int exitCode, QProcess::ExitStatus exitStatus)
{
    Q_UNUSED(exitCode);
    Q_UNUSED(exitStatus);

    ui->actionLed1->setChecked(false);
}

void MainWindow::on_LED2_finished(int exitCode, QProcess::ExitStatus exitStatus)
{
    Q_UNUSED(exitCode);
    Q_UNUSED(exitStatus);

    ui->actionLED2->setChecked(false);
}

void MainWindow::on_actionLed1_triggered(bool checked)
{
    if (checked) {
        proc_Led1->start();
    }
    else
    {
        proc_Led1->kill();
    }
}

void MainWindow::on_actionLED2_triggered(bool checked)
{
    if (checked) {
        proc_Led2->start();
    }
    else {
        proc_Led2->kill();
    }
}

void MainWindow::on_btn_tablefilter_clicked()
{
    FilterTableDlg *filterdlg = new FilterTableDlg();
    if (filterdlg->exec() == QDialog::Accepted)
        refresh_table_filter();
}

void MainWindow::on_btn_resetProdCount_clicked()
{
    for (int row = 0; row < ui->tb_prodcount->rowCount(); row++) {
        QString date = ui->tb_prodcount->item(row, 0)->text();
        for (int col = 1; col < 17; col++) {
            int v = ui->tb_prodcount->item(row, col)->text().toInt();
            if (v > 0) {
                QDateTime datetime = QDateTime::currentDateTime();
				QString qstr = tr("INSERT INTO tb_pd([datetime], table_id, old_count, product_count, is_auto, [modified_date]) "
					"VALUES(#%1#, %2, %3, %4, 0, #%5#)")
					.arg(date)
					.arg(col - 1)
					.arg(v)
					.arg(0)
					.arg(datetime.toString("yyyy-MM-dd hh:mm:ss"));
				QSqlQuery query;
                query.exec(qstr);
            }
        }
    }
    show_productCount();
}



