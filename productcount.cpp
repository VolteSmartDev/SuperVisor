#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "extravalues.h"

#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include <QMessageBox>
#include <QFileDialog>

void MainWindow::show_productCount(bool last_only)
{

    QDate date_from = ui->dateFrom_pd->date();
    QDate date_to = ui->dateTo_pd->date();
    int day_count = date_from.daysTo(date_to) + 1;

    if (day_count > 100) {
        QMessageBox::warning(0, tr("Products Count"),
                             tr("Too many days are selected to display and this is not allowed for functionality."));
        return;
    }

    ui->tb_prodcount->clearContents();
    ui->tb_prodcount->setRowCount(day_count);

    QSqlQueryModel tmpmodel;
    QTableWidgetItem *item;

    for (int i=0; i<day_count; i++) {
        if (last_only && i < (day_count - 1)) continue;
        QDate cur_date = date_from.addDays(i);
        item = new QTableWidgetItem(cur_date.toString("yyyy-MM-dd"));
        item->setTextAlignment(Qt::AlignCenter);
        item->setFlags(Qt::ItemIsEnabled);
        item->setForeground(Qt::blue);
        ui->tb_prodcount->setItem(i, 0, item);

        int pCount_date = 0;

        for (int j=0; j<16; j++) {
            QString qstr = tr("SELECT product_count FROM tb_pd WHERE table_id=%1 AND datetime >= #%2# AND datetime < #%3# "
                              "ORDER BY id DESC")
                    .arg(j)
                    .arg(date2String(cur_date)).arg(date2String(cur_date.addDays(1)));

            tmpmodel.setQuery(qstr);

            int cur_count = tmpmodel.record(0).value("product_count").toInt();
            pCount_date += cur_count;

            item = new QTableWidgetItem(QString::number(cur_count));
            item->setTextAlignment(Qt::AlignCenter);
            item->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
            ui->tb_prodcount->setItem(i, j+1, item);
        }

        // date total count
        item = new QTableWidgetItem(QString::number(pCount_date));
        item->setTextAlignment(Qt::AlignCenter);
        item->setForeground(Qt::red);
        item->setFlags(Qt::ItemIsEnabled);
        ui->tb_prodcount->setItem(i, 17, item);
    }

    ui->tb_prodcount->resizeColumnsToContents();

}

void MainWindow::load_today_products()
{
    QSqlQueryModel tmpmodel;
    QDate cur_date = QDate::currentDate();
    ui->dateTo_pd->setDate(cur_date);

    last_date = cur_date;
    for (int j=0; j<16; j++) {
        QString qstr = tr("SELECT product_count FROM tb_pd WHERE table_id=%1 AND datetime >= #%2# AND datetime < #%3# "
                          "ORDER BY id DESC")
                .arg(j)
                .arg(date2String(cur_date)).arg(date2String(cur_date.addDays(1)));
        tmpmodel.setQuery(qstr);
        int cur_count = tmpmodel.record(0).value("product_count").toInt();
        productCount[j] = cur_count;

        QByteArray datagram = tr("%1^^%2^^%3").arg(j).arg(4).arg(productCount[j]).toLatin1();
        if (j < 8)
            udpSocket->writeDatagram(datagram.data(), datagram.size(), hostAddr, LANPORT);
        else udpSocket2->writeDatagram(datagram.data(), datagram.size(), hostAddr, LANPORT2);
    }
}

void MainWindow::on_dateFrom_pd_dateChanged(const QDate &)
{

}

void MainWindow::on_dateTo_pd_dateChanged(const QDate &)
{

}

void MainWindow::on_btn_displayProdCount_clicked()
{
    QDate dt = QDate::currentDate();
    if (dt.daysTo(ui->dateTo_pd->date()) > 0)
        ui->dateTo_pd->setDate(dt);

    show_productCount();
}

void MainWindow::on_btn_modifyProdCount_clicked()
{
    int cur_r = ui->tb_prodcount->currentRow();
    int cur_c = ui->tb_prodcount->currentColumn();
    if (cur_r < 0 || cur_c < 0) {
        QMessageBox::warning(0, tr("Manual Products Correction"),
                             tr("Please select a cell that you want to correct."));
        return;
    }

    on_tb_prodcount_cellDoubleClicked(cur_r, cur_c);
}

void MainWindow::on_btn_exportProd_clicked()
{
    if (ui->tb_prodcount->rowCount() == 0) {
        QMessageBox::warning(0, tr("Export to CSV File"), tr("There are not any data to export. please check date/time interval and click Display logs button."));
        return;
    }

    QDate date = QDate::currentDate();
    QTime time = QTime::currentTime();

    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
        tr("products_log_%1%2%3_%4%5%6.csv").arg(date.year()).arg(date.month()).arg(date.day()).arg(time.hour()).arg(time.minute()).arg(time.second()),
        tr("CSV Files (*.csv)"));

    if (fileName.isEmpty()) return;

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::critical(0, tr("Export File"), tr("Cannot write this file. This file path is incorrect or this file is read-only."));
        return;
    }

    QTextStream out(&file);

    out<<"Date";

    for (int i = 0; i < 16; i++)
    {
        out<<tr(",Table %1").arg(i+1);
    }

    out <<",Total Count"<<endl;

    for (int i = 0; i < ui->tb_prodcount->rowCount(); i++)
    {
        for (int j = 0; j < ui->tb_prodcount->columnCount(); j++)
        {
            if (j == 0) out << ui->tb_prodcount->item(i, j)->text();
            else out << tr(",%1").arg(ui->tb_prodcount->item(i, j)->text());
        }
        out << endl;
    }

    file.close();

    statusBar()->showMessage(tr("File Exported"), 5000);
    trayIcon->showMessage(tr("File Exported"), tr("%1 has been save successfully.").arg(fileName));
}

void MainWindow::on_btn_refreshlog_clicked()
{
    QSqlQueryModel qmodel;
    QString qstr = tr("SELECT [datetime], table_id, old_count, product_count, is_auto, modified_date FROM tb_pd "
                      "WHERE [datetime] BETWEEN #%1# AND #%2#")
            .arg(ui->date_from_pdlog->date().toString("yyyy-MM-dd"))
            .arg(ui->date_to_pdlog->date().toString("yyyy-MM-dd"));
    qmodel.setQuery(qstr);

    while(qmodel.canFetchMore())
        qmodel.fetchMore();

    int log_count = qmodel.rowCount();
    ui->tb_pdlog->clearContents();
    ui->tb_pdlog->setRowCount(log_count);

    for (int i=0; i<log_count; i++) {
        QSqlRecord record = qmodel.record(i);
        QTableWidgetItem *item;
        // datetime
        item = new QTableWidgetItem(record.value(0).toDateTime().toString("yyyy-MM-dd"));
        item->setTextAlignment(Qt::AlignCenter);
        ui->tb_pdlog->setItem(i, 0, item);
        // table_id
        item = new QTableWidgetItem(QString::number(record.value("table_id").toInt() + 1));
        item->setTextAlignment(Qt::AlignCenter);
        ui->tb_pdlog->setItem(i, 1, item);
        // old_count
        item = new QTableWidgetItem(record.value("old_count").toString());
        item->setTextAlignment(Qt::AlignCenter);
        ui->tb_pdlog->setItem(i, 2, item);

        // new_counnt
        item = new QTableWidgetItem(record.value("product_count").toString());
        item->setTextAlignment(Qt::AlignCenter);
        ui->tb_pdlog->setItem(i, 3, item);

        // is_auto
        item = new QTableWidgetItem();
        item->setFlags(Qt::ItemIsUserCheckable);
        if (record.value("is_auto").toBool() == true) item->setCheckState(Qt::Checked);
        ui->tb_pdlog->setItem(i, 4, item);

        // modified
        item = new QTableWidgetItem(record.value(5).toDateTime().toString("yyyy-MM-dd hh:mm:ss"));
        item->setTextAlignment(Qt::AlignCenter);
        ui->tb_pdlog->setItem(i, 5, item);
    }

    ui->tb_pdlog->resizeColumnsToContents();
}

void MainWindow::on_btn_clearlog_clicked()
{
    if (QMessageBox::question(0, tr("Question"),
                              tr("Are you sure to clear last product logs?")) != QMessageBox::Yes)
        return;
    QSqlQuery tquery;
    QString qstr = tr("DELETE FROM tb_pd WHERE([datetime] < #%1#)")
            .arg(QDate::currentDate().toString("yyyy-MM-dd"));

    tquery.exec(qstr);
    on_btn_refreshlog_clicked();
}

void MainWindow::on_tb_prodcount_cellDoubleClicked(int row, int column)
{
	if (column == 0 || column == 17) return;

	CorrectPD* corpd = new CorrectPD();
	corpd->setParams(column, ui->tb_prodcount->item(row, column)->text().toInt()
		, ui->tb_prodcount->item(row, 0)->text());

	if (corpd->exec() == QDialog::Accepted) {
		show_productCount();
	}
}

