#include "correctpd.h"
#include "ui_correctpd.h"

#include <QMessageBox>
#include <QDateTime>
#include <QSqlQuery>
#include <QDebug>

CorrectPD::CorrectPD(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CorrectPD)
{
    ui->setupUi(this);
}

CorrectPD::~CorrectPD()
{
    delete ui;
}

void CorrectPD::setParams(int tid, int cp, QString dt)
{
    table_id = tid;
    current_products = cp;
    date = dt;

    ui->edt_tableid->setText(QString::number(table_id));
    ui->edt_curproducts->setText(QString::number(current_products));
    ui->edt_newproducts->setText(QString::number(current_products));
    ui->edt_date->setText(date);

    ui->edt_newproducts->setFocus();
}

void CorrectPD::on_btn_cancel_clicked()
{
    this->reject();
}

void CorrectPD::on_btn_correct_clicked()
{
    if (QMessageBox::question(0, tr("Manual Proucts Correction"),
                              tr("Are you sure to correct Products of selected table?")) != QMessageBox::Yes)
        return;

    QDateTime datetime = QDateTime::currentDateTime();

    QString qstr = tr("INSERT INTO tb_pd([datetime], table_id, old_count, product_count, is_auto, [modified_date]) "
                      "VALUES(#%1#, %2, %3, %4, 0, #%5#)")
            .arg(date)
            .arg(table_id - 1)
            .arg(ui->edt_curproducts->text().toUInt())
            .arg(ui->edt_newproducts->text().toUInt())
            .arg(datetime.toString("yyyy-MM-dd hh:mm:ss"));

    QSqlQuery query;
    bool flag = query.exec(qstr);

    if (flag == true)
        this->accept();
    else {
        QMessageBox::warning(0, tr("Manual Proucts Correction"),
                             tr("Correction failed."));
    }
}
