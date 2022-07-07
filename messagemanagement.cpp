#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "extravalues.h"
#include "connectdialog.h"

#include <qsettings.h>
#include <qsqlquerymodel.h>
#include <qsqlrecord.h>
#include <qmessagebox.h>
#include <QDebug>

extern QSettings *settings;

void MainWindow::loadMessage()
{
    lastYMessageList.clear();
    lastRMessageList.clear();
    /// message_y
    model.setQuery("SELECT message_y FROM StatusTable ORDER BY table_id ASC");
    for (int i = 0; i < 16; i++)
    {
        QString curMsg = model.record(i).value(0).toString();
        QTableWidgetItem *item = new QTableWidgetItem(curMsg);
        ui->table_YStatus->setItem(i, 1, item);
        lastYMessageList.push_back(curMsg);
    }

    /// message_r
    model.setQuery("SELECT message_r FROM StatusTable ORDER BY table_id ASC");
    for (int i = 0; i < 16; i++)
    {
        QString curMsg = model.record(i).value(0).toString();
        QTableWidgetItem *item = new QTableWidgetItem(curMsg);
        ui->table_RStatus->setItem(i, 1, item);
        lastRMessageList.push_back(curMsg);
    }
}

void MainWindow::refreshTState()
{
    QByteArray datagram;
    bool flag = false;
    QString qstr;

    /// check expire
    /// check expire
    QDate date = QDate::currentDate();
    QDate date1 = QDate(2021, 8, 5);
 //   if (date.daysTo(date1) < 0) {
 //       return;
 //   }

    /// date, time
    QDateTime datetime = QDateTime::currentDateTime();
    int input_date = datetime.date().year() * 10000 +
            datetime.date().month() * 100 + datetime.date().day();
    int input_time = datetime.time().hour() * 100 + datetime.time().minute();

    bool isStatusChanged = false;
    load_today_products();

    // if date changed, load products automatically.
    if (last_date != datetime.date())
        show_productCount();

    for (int i = 0; i < 16; i++)
    {

        /// ON PROGRESS
        if (entryList[i * 3] == 1) {
            /// find first material on process
            model.setQuery(tr("SELECT material_name, material_id FROM MaterialTable WHERE status=1 AND table_id=%1 ORDER BY material_id ASC")
                .arg(i + 1));
            QString onPrcessingMaterial = model.record(0).value(0).toString();
            int mat_id = model.record(0).value(1).toInt();

            stateList[i] = 0;

            messageList[i] = onPrcessingMaterial;

            /// if last status is STOP, it means new ticket start
            if (laststateList2[i] == 0 && laststateList[i] == 2) {
                qstr = tr("INSERT INTO tb_pduration(table_id, material_id, material_name, [start_time]) "
                          "VALUES(%1, %2, '%3', #%4#)")
                        .arg(i+1).arg(mat_id).arg(onPrcessingMaterial).arg(dateTime2String(datetime));
                query.exec(qstr);
                refresh_pduration();
            }

            /// if last status differs from current, save status history
            if (stateList[i] != laststateList[i]) {
                /// if state changed, save into database
                qstr = tr("INSERT INTO StatusHistoryTable([datetime], table_id, status, message) "
                          "VALUES(#%1#,%2,%3,'%4')")
                       .arg(dateTime2String(datetime)).arg(i+1).arg(0).arg(onPrcessingMaterial);
                query.exec(qstr);

                /// if YELLO->GREEN, calculate break time and add it
                int this_breaktime = breakstart->secsTo(datetime);
                breakstart[i] = QDateTime();

                /// get last break time
                model.setQuery(tr("SELECT material_id, ID FROM MaterialTable WHERE table_id=%1 AND status=1 ORDER BY material_id ASC")
                    .arg(i+1));

                int mat_id = model.record(0).value(0).toInt();

                /// update tb_pduration
                model.setQuery(tr("SELECT ID FROM tb_pduration WHERE table_id=%1 AND material_id=%2 ORDER BY ID DESC")
                               .arg(i+1).arg(mat_id));
                int pd_id = model.record(0).value(0).toInt();

                /// update tb_pduration
                qstr = tr("UPDATE tb_pduration SET break_secs=break_secs+%1 WHERE ID=%2")
                        .arg(this_breaktime).arg(pd_id);
                qDebug()<<qstr;
                qDebug()<<query.exec(qstr);
                refresh_pduration();

                laststateList2[i] = laststateList[i];
                if (laststateList2[i] == 3) laststateList2[i] = 0;
                laststateList[i] = 0;
                isStatusChanged = true;

                /// clear yellow and red message
                query.exec(tr("UPDATE StatusTable SET message_y='', message_r='' WHERE table_id=%1").arg(i+1));
                loadMessage();
            }

            ui->tableList->item(i)->setTextColor(Qt::darkGreen);
            /// send to TV
            datagram = tr("%1^^%2^^%3").arg(i).arg(0).arg(onPrcessingMaterial).toLatin1();
			if (i < 8) udpSocket->writeDatagram(datagram.data(), datagram.size(), hostAddr, LANPORT);
			else udpSocket2->writeDatagram(datagram.data(), datagram.size(), hostAddr, LANPORT2);
			continue;
		}

        /// ADDITIONAL MESSAGE
		if (entryList[i * 3 + 1] == 1) {
			stateList[i] = 1;
            messageList[i] = ui->table_YStatus->item(i, 1)->text();

            if (stateList[i] != laststateList[i]) {
                /// if state changed, save into database
                //query.exec(tr("INSERT INTO StatusHistoryTable([datetime], table_id, status, message) "
                 //                    "VALUES(#%1#,%2,%3,'%4')")
                  //                .arg(dateTime2String(datetime)).arg(i+1).arg(1).arg(ui->table_YStatus->item(i, 1)->text()));

                /// if GREEN->YELLOW, start break time
                if (laststateList[i] == 0) {
                    breakstart[i] = datetime;
                }

                laststateList2[i] = laststateList[i];
                if (laststateList2[i] == 3) laststateList2[i] = 1;
                laststateList[i] = 1;
				isStatusChanged = true;

            }

            ui->tableList->item(i)->setTextColor(QColor(255, 85, 0));
            /// send to TV
            datagram = tr("%1^^%2^^%3").arg(i).arg(1).arg(ui->table_YStatus->item(i, 1)->text()).toLatin1();
			if (i < 8) udpSocket->writeDatagram(datagram.data(), datagram.size(), hostAddr, LANPORT);
			else udpSocket2->writeDatagram(datagram.data(), datagram.size(), hostAddr, LANPORT2);
			continue;
		}

        /// STOP
		if (entryList[i * 3 + 2] == 1) {

            // GREEN-RED, plus product count
            if (laststateList[i] == 0) {
                productCount[i] += 1;
                QSqlQuery tmpquery;
                QString qstr = tr("INSERT INTO tb_pd([datetime], table_id, old_count, product_count, is_auto, [modified_date]) "
                                  "VALUES(#%1#, %2, %3, %4, 1, #%5#)")
                        .arg(datetime.toString("yyyy-MM-dd"))
                        .arg(i)
                        .arg(productCount[i]-1)
                        .arg(productCount[i])
                        .arg(datetime.toString("yyyy-MM-dd hh:mm:ss"));
                flag = tmpquery.exec(qstr);
                show_productCount();
            }

            /// check if onprocess to stop, then ticket finish
            if (laststateList[i] == 0) {
				/// change on progress material to require
				model.setQuery(tr("SELECT material_id, ID FROM MaterialTable WHERE table_id=%1 AND status=1 ORDER BY material_id ASC")
					.arg(i+1));
				
                int mat_id = model.record(0).value(0).toInt();
				int last_id = model.record(0).value(1).toInt();

                /// update tb_pduration
                model.setQuery(tr("SELECT ID FROM tb_pduration WHERE table_id=%1 AND material_id=%2 ORDER BY ID DESC")
                               .arg(i+1).arg(mat_id));
                int pd_id = model.record(0).value(0).toInt();

                /// update tb_pduration
                qstr = tr("UPDATE tb_pduration SET [end_time]=#%1# WHERE ID=%2")
                        .arg(dateTime2String(datetime)).arg(pd_id);
                query.exec(qstr);
                refresh_pduration();

                /// update MaterialTable
                flag = query.exec(tr("UPDATE MaterialTable SET status = 0, input_date=%2, input_time=%3 WHERE (ID = %1)")
                    .arg(last_id).arg(input_date).arg(input_time));
				loadMaterials();
				showMaterialtoInputTable(i+1);
			}

			stateList[i] = 2;
            messageList[i] = ui->table_RStatus->item(i, 1)->text();
            if (stateList[i] != laststateList[i]) {
                /// if state changed, save into database
                //query.exec(tr("INSERT INTO StatusHistoryTable([datetime], table_id, status, message) "
                //                     "VALUES(#%1#,%2,%3,'%4')")
                 //                 .arg(dateTime2String(datetime)).arg(i+1).arg(2).arg(ui->table_RStatus->item(i, 1)->text()));

                laststateList2[i] = laststateList[i];
                if (laststateList2[i] == 3) laststateList2[i] = 2;
                laststateList[i] = 2;
				isStatusChanged = true;
            }

            ui->tableList->item(i)->setTextColor(Qt::red);
            /// send to TV
            datagram = tr("%1^^%2^^%3").arg(i).arg(2).arg(ui->table_RStatus->item(i, 1)->text()).toLatin1();
			if (i < 8) udpSocket->writeDatagram(datagram.data(), datagram.size(), hostAddr, LANPORT);
			else udpSocket2->writeDatagram(datagram.data(), datagram.size(), hostAddr, LANPORT2);
			continue;
		}

		stateList[i] = 3;
        messageList[i] = "Please check connection.";
        ui->tableList->item(i)->setTextColor(Qt::gray);
		/// send to TV : table_id, status, msg;
        datagram = tr("%1^^%2^^%3").arg(i).arg(3).arg("Please check connection.").toLatin1();
		if (i < 8) udpSocket->writeDatagram(datagram.data(), datagram.size(), hostAddr, LANPORT);
		else udpSocket2->writeDatagram(datagram.data(), datagram.size(), hostAddr, LANPORT2);
	}

	if (isStatusChanged == true) {
		ui->dateTimeEdit22->setDateTime(datetime);
        saveStatusToDB();
        QTimer::singleShot(10, this, SLOT(on_btn_DisplayLogs_clicked()));
		QTimer::singleShot(1, this, SLOT(on_btn_DisplayLogs2_clicked()));
	}
}

void MainWindow::on_btn_UpdateYMsg_clicked()
{
    if (runQuestion("Are you sure to update messages?") != QMessageBox::Yes) return;

    /// date, time
    QDateTime datetime = QDateTime::currentDateTime();
    int this_date = datetime.date().year() * 10000 +
            datetime.date().month() * 100 + datetime.date().day();
    int this_time = datetime.time().hour() * 100 + datetime.time().minute();
    QString qStr;
    bool isLastChanged = false;

    for (int i = 0; i < 16; i++)
    {
        /// update message_y status table///
        QString curMsg = ui->table_YStatus->item(i, 1)->text();
        query.exec(tr("UPDATE StatusTable SET status = %1, message_y = '%2' WHERE table_id = %3")
            .arg(stateList[i])
            .arg(curMsg)
            .arg(i+1));

        if (curMsg != lastYMessageList.at(i)) {
            /// if changed, insert into StatusHistoryTable
            qStr = tr("INSERT INTO StatusHistoryTable([datetime], table_id, status, message) "
                      "VALUES(#%1#,%2,%3,'%4')")
                    .arg(dateTime2String(datetime)).arg(i+1).arg(1).arg(curMsg);
            query.exec(qStr);
			lastYMessageList[i] = curMsg;
            isLastChanged = true;
        }
    }

	statusBar()->showMessage(STS_UPDATE_SUCCESS, 5000);
    refreshTState();
    if (isLastChanged == true) on_btn_DisplayLogs2_clicked();
}

void MainWindow::on_btn_UpdateRMsg_clicked()
{
    if (runQuestion("Are you sure to update messages?") != QMessageBox::Yes) return;

	/// date, time
	QDateTime datetime = QDateTime::currentDateTime();
	int this_date = datetime.date().year() * 10000 +
		datetime.date().month() * 100 + datetime.date().day();
	int this_time = datetime.time().hour() * 100 + datetime.time().minute();
	QString qStr;
	bool isLastChanged = false;

    for (int i = 0; i < 16; i++)
    {
        /// message_r
        QString curMsg = ui->table_RStatus->item(i, 1)->text();
        query.exec(tr("UPDATE StatusTable SET status = %1, message_r = '%2' WHERE table_id = %3")
            .arg(stateList[i])
            .arg(curMsg)
            .arg(i+1));

		/// if changed, insert into StatusHistoryTable
		if (curMsg != lastRMessageList.at(i)) {
            qStr = tr("INSERT INTO StatusHistoryTable([datetime], table_id, status, message) "
                "VALUES(#%1#,%2,%3,'%4')")
                .arg(dateTime2String(datetime)).arg(i+1).arg(2).arg(curMsg);
            qDebug()<<query.exec(qStr);
			lastRMessageList[i] = curMsg;
			isLastChanged = true;
		}
    }
	statusBar()->showMessage(STS_UPDATE_SUCCESS, 5000);
    refreshTState();

	if (isLastChanged == true) on_btn_DisplayLogs2_clicked();
}

