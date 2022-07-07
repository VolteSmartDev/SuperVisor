#ifndef CHANGEPWDDLG_H
#define CHANGEPWDDLG_H

#include <QDialog>

namespace Ui {
class ChangePwdDlg;
}

class ChangePwdDlg : public QDialog
{
    Q_OBJECT

public:
    explicit ChangePwdDlg(QWidget *parent = 0);
    ~ChangePwdDlg();

private slots:
    void on_btn_OK_clicked();

private:
    Ui::ChangePwdDlg *ui;
};

#endif // CHANGEPWDDLG_H
