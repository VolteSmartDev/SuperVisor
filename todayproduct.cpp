#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "extravalues.h"
#include "connectdialog.h"
#include "confrmpwddlg.h"
#include "filtertabledlg.h"


#include <qsettings.h>
#include <qsqlquerymodel.h>
#include <qsqlrecord.h>
#include <qmessagebox.h>

#include <QDebug>

extern QSettings *settings;

void MainWindow::on_btn_today_clicked()
{
    ui->date_todayproduct->setDate(QDate::currentDate());
}

void MainWindow::on_date_todayproduct_dateChanged(const QDate &date)
{
    Q_UNUSED(date);
    refresh_pduration();
}

void MainWindow::on_btn_tablefilter2_clicked()
{
    FilterTableDlg *filterdlg = new FilterTableDlg();
    if (filterdlg->exec() == QDialog::Accepted)
        refresh_pduration();
}

void MainWindow::refresh_pduration()
{
    QStringList filterList = settings->value(REG_TABLE_FILTER).toStringList();
    if(filterList.count() < 16) return;

    ui->table_today->clearContents();

    while(ui->table_today->rowCount() > 0)
        ui->table_today->removeRow(0);

    int filtered_table_count = 0;
    for (int i=0; i<16; i++) {
        if (filterList.at(i) == "1") filtered_table_count++;
    }

    int cur_row = 0;
    QString qstr;
    QSqlQueryModel qModel;
    QSqlQuery qQuery;
    QDate curdate = ui->date_todayproduct->date();

    QPen whitepen(Qt::white);
    QPen blackpen(Qt::black);
    QBrush b_tableheader(Qt::darkRed);
    QBrush b_colheader(Qt::darkBlue);
    QFont f_tableheader("Arial", 18, 75);

    bool is_first_table = true;

    for (int i=0; i<16; i++) {
        bool is_hide = filterList.at(i) == "0";
        if (is_hide) continue;

        if (is_first_table) is_first_table = false;
        else cur_row++;

        // table header
        ui->table_today->insertRow(ui->table_today->rowCount());
        QTableWidgetItem *item = new QTableWidgetItem(tr("TABLE %1").arg(i + 1));
        item->setFont(f_tableheader);
        item->setBackground(b_tableheader);
        item->setForeground(QBrush(Qt::white));
        item->setTextAlignment(Qt::AlignCenter);
        ui->table_today->setItem(cur_row, 0, item);
        ui->table_today->setSpan(cur_row, 0, 1, 7);

        /// column header
        cur_row++;
        ui->table_today->insertRow(ui->table_today->rowCount());
        QStringList colheaders;
        colheaders<<" START "<<" END "<<" PRODUCT/TICKET "<<" DURATION "<<" WAITING MESSAGE "
                 <<" STOP MESSAGE "<<" CUMULATIVE DURATION ";

        for (int k=0; k<7; k++) {
            item = new QTableWidgetItem(colheaders.at(k));
            item->setBackground(QBrush(Qt::lightGray));
            item->setForeground(QBrush(Qt::black));
            item->setTextAlignment(Qt::AlignCenter);
            ui->table_today->setItem(cur_row, k, item);
        }

        /// calculate duration
        // get material id
        qstr = tr("SELECT * FROM tb_pduration "
                  "WHERE table_id=%1 AND start_time >= #%2# AND start_time <= #%3#")
                .arg(i+1)
                .arg(date2String(curdate))
                .arg(date2String(curdate.addDays(1)));
        qModel.setQuery(qstr);
        int material_count = qModel.rowCount();

        qint64 total_duration = 0;

        //
        for (int j=0; j<material_count; j++) {

            cur_row++;
            ui->table_today->insertRow(ui->table_today->rowCount());
            QSqlRecord record = qModel.record(j);

            QSqlQueryModel modely, modelr;

            // start
            QDateTime start_time = record.value("start_time").toDateTime();
            item = new QTableWidgetItem(start_time.toString("MM-dd hh:mm:ss"));
            item->setTextAlignment(Qt::AlignCenter);
            ui->table_today->setItem(cur_row, 0, item);

            // material_name
            item = new QTableWidgetItem(record.value("material_name").toString());
            item->setTextAlignment(Qt::AlignCenter);
            ui->table_today->setItem(cur_row, 2, item);


            // end
            QDateTime end_time = record.value("end_time").toDateTime();

            QDateTime break00(end_time.date(), QTime(9, 30));
            QDateTime break01(end_time.date(), QTime(9, 45));
            QDateTime break10(end_time.date(), QTime(12, 0));
            QDateTime break11(end_time.date(), QTime(13, 0));
            QDateTime break20(end_time.date(), QTime(14, 30));
            QDateTime break21(end_time.date(), QTime(14, 45));

            if (end_time != QDateTime()) {
                item = new QTableWidgetItem(end_time.toString("MM-dd hh:mm:ss"));
                item->setTextAlignment(Qt::AlignCenter);
                ui->table_today->setItem(cur_row, 1, item);

                // break time
                //int break_secs = record.value("break_secs").toInt();
                int break_secs = 0;

                if (start_time < end_time) {
                    /// 09:30-09:45
                    ///
                    /// 09:25-09:50 = 25-15=10
                    if (start_time < break00 && break01 <= end_time) {
                        break_secs += break00.secsTo(break01);
                        qDebug()<<"break0"<<break01<<end_time<<break01.secsTo(end_time);
                    }

                    /// 09:35-09:50=15-10=5
                    if (start_time >= break00 && start_time < break01 && break01 <= end_time) {
                        break_secs += start_time.secsTo(break01);
                    }

                    // 09:20->09:40 = 20-10 = 10
                    if (start_time < break00 && end_time > break00 && break01 > end_time) {
                        break_secs += break00.secsTo(end_time);
                        qDebug()<<break00<<end_time<<break00.secsTo(end_time);
                    }

                    if (start_time > break00 && end_time < break01) {
                        break_secs += start_time.secsTo(end_time);
                    }

                    /// 12:00->13:00
                    if (start_time < break10 && break11 <= end_time) {
                        break_secs += break10.secsTo(break11);
                    }

                    ///
                    if (start_time >= break10 && start_time < break11 && break11 <= end_time) {
                        break_secs += start_time.secsTo(break11);
                        qDebug()<<start_time<<end_time;
                    }

                    if (start_time < break10 && end_time > break10 && break11 > end_time) {
                        break_secs += break10.secsTo(end_time);
                    }

                    if (start_time > break10 && end_time < break11) {
                        break_secs += start_time.secsTo(end_time);
                    }

                    /// 14:30->14:45
                    if (start_time < break20 && break21 <= end_time) {
                        break_secs += break20.secsTo(break21);
                    }

                    ///
                    if (start_time >= break20 && start_time < break21 && break21 <= end_time) {
                        break_secs += start_time.secsTo(break21);
                    }

                    if (start_time < break20 && end_time > break20 && end_time < break21) {
                        break_secs += break20.secsTo(end_time);
                    }

                    if (start_time > break20 && end_time < break21) {
                        break_secs += start_time.secsTo(end_time);
                    }


                    /// message
                    qstr = tr("SELECT * FROM StatusHistoryTable WHERE message<>'' AND status=1 AND table_id=%3 AND "
                              "datetime BETWEEN #%1# AND #%2# ORDER BY ID ASC")
                            .arg(dateTime2String(start_time)).arg(dateTime2String(end_time)).arg(i+1);
                    qDebug()<<qstr;
                    modely.setQuery(qstr);

                    qstr = tr("SELECT * FROM StatusHistoryTable WHERE message<>'' AND status=2 AND table_id=%3 AND "
                              "datetime BETWEEN #%1# AND #%2# ORDER BY ID ASC")
                            .arg(dateTime2String(start_time)).arg(dateTime2String(end_time)).arg(i+1);
                    qDebug()<<qstr;
                    modelr.setQuery(qstr);
                }

                qDebug()<<break_secs;

                // duration
                qint64 sec_total = start_time.secsTo(end_time) - break_secs;
                total_duration += sec_total;
                int hrs = sec_total / 3600;
                qDebug()<<hrs;
                int mins = (sec_total - hrs * 3600) / 60;
                int secs = sec_total % 60;
                item = new QTableWidgetItem(tr("%1:%2:%3")
                                            .arg(hrs).arg(mins).arg(secs));
                item->setTextAlignment(Qt::AlignCenter);
                ui->table_today->setItem(cur_row, 3, item);




                // cumulative duration 6
                hrs = total_duration / 3600;
                mins = (total_duration - hrs * 3600) / 60;
                secs = total_duration % 60;
                item = new QTableWidgetItem(tr("%1:%2:%3")
                                            .arg(hrs).arg(mins).arg(secs));
                item->setTextAlignment(Qt::AlignCenter);
                ui->table_today->setItem(cur_row, 6, item);

            }
            else {
                /// message
                qstr = tr("SELECT * FROM StatusHistoryTable WHERE message<>'' AND status=1 AND datetime >= #%1# AND table_id=%2")
                        .arg(dateTime2String(start_time)).arg(i);
                modely.setQuery(qstr);

                qstr = tr("SELECT * FROM StatusHistoryTable WHERE message<>'' AND status=2 AND datetime >= #%1# AND table_id=%2")
                        .arg(dateTime2String(start_time)).arg(i);
                modelr.setQuery(qstr);
            }

            // waiting message 4
            QString total_msg = "";
            QString msg = modely.record(0).value("message").toString();
            if (!msg.isEmpty())
                total_msg = "[" + modely.record(0).value("datetime").toDateTime().toString("hh:mm:ss") + "]" + msg;

            for (int msgi=1; msgi<modely.rowCount(); msgi++) {
                msg = modely.record(msgi).value("message").toString();
                qDebug()<<msg;
                if (!msg.isEmpty())
                    total_msg += "\n[" + modely.record(msgi).value("datetime").toDateTime().toString("hh:mm:ss") + "]" + msg;
            }

            item = new QTableWidgetItem(total_msg);
            item->setTextAlignment(Qt::AlignVCenter | Qt::AlignLeft);
            ui->table_today->setItem(cur_row, 4, item);

            // stop message 5
            total_msg = "";
            msg = modelr.record(0).value("message").toString();
            if (!msg.isEmpty())
                total_msg = "[" + modelr.record(0).value("datetime").toDateTime().toString("hh:mm:ss") + "]" + msg;

            for (int msgi=1; msgi<modelr.rowCount(); msgi++) {
                msg = modelr.record(msgi).value("message").toString();
                if (!msg.isEmpty())
                    total_msg += "\n[" + modelr.record(msgi).value("datetime").toDateTime().toString("hh:mm:ss") + "]" + msg;
            }

            item = new QTableWidgetItem(total_msg);
            item->setTextAlignment(Qt::AlignVCenter | Qt::AlignLeft);
            ui->table_today->setItem(cur_row, 5, item);

            if (modely.rowCount() > 1 || modelr.rowCount() > 1)
                ui->table_today->resizeRowToContents(cur_row);
        }

        cur_row ++;
        ui->table_today->insertRow(ui->table_today->rowCount());
    }

    ui->table_today->resizeColumnsToContents();

}

void MainWindow::on_btn_exporttoday_clicked()
{
    if (ui->table_today->rowCount() == 0) {
        QMessageBox::warning(0, tr("Export to CSV File"), tr("There are not any data to export."));
        return;
    }

    QDate date = QDate::currentDate();
    QTime time = QTime::currentTime();

    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
        tr("today_product_%1%2%3_%4%5%6.csv").arg(date.year()).arg(date.month()).arg(date.day()).arg(time.hour()).arg(time.minute()).arg(time.second()),
        tr("CSV Files (*.csv)"));

    if (fileName.isEmpty()) return;

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::critical(0, tr("Export File"), tr("Cannot write this file. This file path is incorrect or this file is read-only."));
        return;
    }

    QTextStream out(&file);

    for (int i = 0; i < ui->table_today->rowCount(); i++)
    {
        for (int j = 0; j < ui->table_today->columnCount(); j++)
        {
            if (j == 0) {
                QString a = " ";
                if (ui->table_today->item(i, j))
                    a = ui->table_today->item(i, j)->text();
                out << a;
            }
            else {
                QString a = " ";
                if (ui->table_today->item(i, j))
                    a = ui->table_today->item(i, j)->text();
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

