#ifndef GENERALSETDLG_H
#define GENERALSETDLG_H

#include <QDialog>

namespace Ui {
class GeneralSetDlg;
}

class GeneralSetDlg : public QDialog
{
    Q_OBJECT

public:
    explicit GeneralSetDlg(QWidget *parent = 0);
    ~GeneralSetDlg();

private slots:
    void on_btn_OK_clicked();

    void on_btn_SaveFolderBrowse_clicked();

    void on_check_AutoDailySave_toggled(bool checked);

    void on_reset_database_clicked();

    void on_radio_button_toggled(bool checked);

private:
    Ui::GeneralSetDlg *ui;

    void loadSettings();
};

#endif // GENERALSETDLG_H
