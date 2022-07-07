#ifndef FILTERTABLEDLG_H
#define FILTERTABLEDLG_H

#include <QDialog>

namespace Ui {
class FilterTableDlg;
}

class FilterTableDlg : public QDialog
{
    Q_OBJECT

public:
    explicit FilterTableDlg(QWidget *parent = nullptr);
    ~FilterTableDlg();

private slots:
    void on_btn_apply_clicked();

    void on_ck_All_toggled(bool checked);

private:
    Ui::FilterTableDlg *ui;
};

#endif // FILTERTABLEDLG_H
