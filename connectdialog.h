#ifndef CONNECTDIALOG_H
#define CONNECTDIALOG_H

#include <QDialog>

namespace Ui {
class ConnectDialog;
}

class ConnectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ConnectDialog(QWidget *parent = 0);
    ~ConnectDialog();

private slots:
    void on_btn_Connect_clicked();

private:
    Ui::ConnectDialog *ui;
};

#endif // CONNECTDIALOG_H
