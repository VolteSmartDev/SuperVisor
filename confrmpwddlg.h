#ifndef CONFRMPWDDLG_H
#define CONFRMPWDDLG_H

#include <QDialog>

namespace Ui {
class ConfrmPwdDlg;
}

class ConfrmPwdDlg : public QDialog
{
    Q_OBJECT

public:
    explicit ConfrmPwdDlg(QWidget *parent = 0);
    ~ConfrmPwdDlg();

private slots:
    void on_btn_OK_clicked();

private:
    Ui::ConfrmPwdDlg *ui;
};

#endif // CONFRMPWDDLG_H
