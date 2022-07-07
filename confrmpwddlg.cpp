#include "confrmpwddlg.h"
#include "ui_confrmpwddlg.h"

#include <QMessageBox>
#include <QtSql>

ConfrmPwdDlg::ConfrmPwdDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConfrmPwdDlg)
{
    ui->setupUi(this);
}

ConfrmPwdDlg::~ConfrmPwdDlg()
{
    delete ui;
}

void ConfrmPwdDlg::on_btn_OK_clicked()
{
    QSqlQueryModel model;
    model.setQuery("SELECT password FROM Users");
    QString pwd = model.record(0).value(0).toString();

    if (pwd == ui->edt_Pwd->text()) this->accept();
    else {
        QMessageBox::warning(0, tr("Wrong Password"), tr("This password is incorrect. Please try again."));
        ui->edt_Pwd->setFocus();
    }
}
