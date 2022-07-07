#include "filtertabledlg.h"
#include "ui_filtertabledlg.h"
#include <QSettings>
#include "extravalues.h"

extern QSettings *settings;

FilterTableDlg::FilterTableDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FilterTableDlg)
{
    ui->setupUi(this);

    QStringList list = settings->value(REG_TABLE_FILTER).toStringList();
    if (list.count() < 16) return;

    ui->ck_1->setChecked(list.at(0) == "1");
    ui->ck_2->setChecked(list.at(1) == "1");
    ui->ck_3->setChecked(list.at(2) == "1");
    ui->ck_4->setChecked(list.at(3) == "1");
    ui->ck_5->setChecked(list.at(4) == "1");
    ui->ck_6->setChecked(list.at(5) == "1");
    ui->ck_7->setChecked(list.at(6) == "1");
    ui->ck_8->setChecked(list.at(7) == "1");
    ui->ck_9->setChecked(list.at(8) == "1");
    ui->ck_10->setChecked(list.at(9) == "1");
    ui->ck_11->setChecked(list.at(10) == "1");
    ui->ck_12->setChecked(list.at(11) == "1");
    ui->ck_13->setChecked(list.at(12) == "1");
    ui->ck_14->setChecked(list.at(13) == "1");
    ui->ck_15->setChecked(list.at(14) == "1");
    ui->ck_16->setChecked(list.at(15) == "1");

}

FilterTableDlg::~FilterTableDlg()
{
    delete ui;
}

void FilterTableDlg::on_btn_apply_clicked()
{
    QStringList list;
    list.append(ui->ck_1->isChecked() == true ? "1" : "0");
    list.append(ui->ck_2->isChecked() == true ? "1" : "0");
    list.append(ui->ck_3->isChecked() == true ? "1" : "0");
    list.append(ui->ck_4->isChecked() == true ? "1" : "0");
    list.append(ui->ck_5->isChecked() == true ? "1" : "0");
    list.append(ui->ck_6->isChecked() == true ? "1" : "0");
    list.append(ui->ck_7->isChecked() == true ? "1" : "0");
    list.append(ui->ck_8->isChecked() == true ? "1" : "0");
    list.append(ui->ck_9->isChecked() == true ? "1" : "0");
    list.append(ui->ck_10->isChecked() == true ? "1" : "0");
    list.append(ui->ck_11->isChecked() == true ? "1" : "0");
    list.append(ui->ck_12->isChecked() == true ? "1" : "0");
    list.append(ui->ck_13->isChecked() == true ? "1" : "0");
    list.append(ui->ck_14->isChecked() == true ? "1" : "0");
    list.append(ui->ck_15->isChecked() == true ? "1" : "0");
    list.append(ui->ck_16->isChecked() == true ? "1" : "0");

    settings->setValue(REG_TABLE_FILTER, list);
    this->accept();
}

void FilterTableDlg::on_ck_All_toggled(bool checked)
{
    ui->ck_1->setChecked(checked);
    ui->ck_2->setChecked(checked);
    ui->ck_3->setChecked(checked);
    ui->ck_4->setChecked(checked);
    ui->ck_5->setChecked(checked);
    ui->ck_6->setChecked(checked);
    ui->ck_7->setChecked(checked);
    ui->ck_8->setChecked(checked);
    ui->ck_9->setChecked(checked);
    ui->ck_10->setChecked(checked);
    ui->ck_11->setChecked(checked);
    ui->ck_12->setChecked(checked);
    ui->ck_13->setChecked(checked);
    ui->ck_14->setChecked(checked);
    ui->ck_15->setChecked(checked);
    ui->ck_16->setChecked(checked);
}
