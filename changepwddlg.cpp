#include "changepwddlg.h"
#include "ui_changepwddlg.h"

#include <QtSql>
#include <QMessageBox>

ChangePwdDlg::ChangePwdDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangePwdDlg)
{
    ui->setupUi(this);
}

ChangePwdDlg::~ChangePwdDlg()
{
    delete ui;
}

void ChangePwdDlg::on_btn_OK_clicked()
{
    QSqlQueryModel tmpModel;
    QSqlQuery tmpQuery;

    tmpModel.setQuery("SELECT password FROM Users WHERE ID=1");
    QString dbPwd = tmpModel.record(0).value(0).toString();
    QString oldPwd = ui->edt_OldPwd->text();
    if (dbPwd != oldPwd) {
        QMessageBox::warning(0, tr("Wrong Password"), tr("Please type current password."));
        ui->edt_OldPwd->setFocus();
        return;
    }

    QString newPwd = ui->edt_NewPwd1->text();
    QString newPwd2 = ui->edt_NewPwd2->text();

    if (newPwd != newPwd2) {
        QMessageBox::warning(0, "Confirm New Password", "Please retype new password correctly.");
        ui->edt_NewPwd2->setFocus();
        return;
    }
     bool flag = tmpQuery.exec(tr("UPDATE Users SET password='%1' WHERE ID=1")
                              .arg(newPwd));
     if (flag == true) {
         QMessageBox::information(0, "Change Manager Password", "Password has been changed.");
         this->accept();
     }
}
