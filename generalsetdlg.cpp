#include "generalsetdlg.h"
#include "ui_generalsetdlg.h"
#include "extravalues.h"

#include <QUrl>
#include <QFileDialog>
#include <QTime>
#include <QtSql>
#include <QMessageBox>
#include <QFont>

extern QSettings *settings;

GeneralSetDlg::GeneralSetDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GeneralSetDlg)
{
    ui->setupUi(this);
    loadSettings();
}

GeneralSetDlg::~GeneralSetDlg()
{
    delete ui;
}

void GeneralSetDlg::loadSettings()
{
    /// tab 1
    ui->check_AutoConnect->setChecked(settings->value(REG_AUTOCONNECT).toBool());

    int refreshTime = settings->value(REG_REFRESHTIME).toInt();
    if (refreshTime == 0) refreshTime = 1;
    ui->combo_refreshTime->setCurrentIndex(ui->combo_refreshTime->findText(tr("%1").arg(refreshTime)));

    int saveHistTime = settings->value(REG_SAVEHISTTIME).toInt();
    if (saveHistTime == 0) saveHistTime = 1;
    ui->edt_SaveTimeInterval->setText(tr("%1").arg(saveHistTime));
    ui->check_NodifyStatusSaved->setChecked(settings->value(REG_NODIFYSAVE).toBool());

    ui->radio_timer->setChecked(settings->value(REG_EVENT_FLAG).toBool());

    /// tab 2
    ui->check_AutoDailySave->setChecked(settings->value(REG_AUTOEXPORTLOG).toBool());
    ui->groupBox->setEnabled(ui->check_AutoDailySave->isChecked());

    QString savePath = settings->value(REG_EXPORTPATH).toString();
    if (savePath.isEmpty()) savePath = "D:/";
    ui->edt_FoderPath->setText(savePath);

	QString eTimeStr = settings->value(REG_EXPORTTIME).toString();
    if (eTimeStr.isEmpty()) eTimeStr = "19:00";
    ui->edt_ExportTime->setText(eTimeStr);

    ui->check_DeletePastLog->setChecked(settings->value(REG_DELETEPASTLOG).toBool());

    int deleteDay = settings->value(REG_DELETEPASTDAY).toInt();
    if (deleteDay == 0) deleteDay = 2;
    ui->edt_DeleteDay->setText(tr("%1").arg(deleteDay));

    // tab 3
    ui->check_AutoRunLED->setChecked(settings->value(REG_IS_AUTOLED).toBool());
    QString LED_Font = settings->value(REG_LED_FONT, "Arial").toString();
    ui->fontComboBox->setCurrentFont(QFont(LED_Font));
    ui->spinBox_FontSize->setValue(settings->value(REG_LED_FONTSIZE, "28").toInt());
}

void GeneralSetDlg::on_btn_OK_clicked()
{
    /// check
    QString eTimeStr = ui->edt_ExportTime->text();
    if (eTimeStr.left(2).toInt() < 0 || eTimeStr.left(2).toInt() > 24 ||
            eTimeStr.right(2).toInt() < 0 || eTimeStr.right(2).toInt() > 59) {
        ui->edt_ExportTime->setFocus();
        return;
    }

    /// save settings
    settings->setValue(REG_AUTOCONNECT, ui->check_AutoConnect->isChecked());
    settings->setValue(REG_REFRESHTIME, ui->combo_refreshTime->currentText().toInt());
    settings->setValue(REG_SAVEHISTTIME, ui->edt_SaveTimeInterval->text().toInt());
    settings->setValue(REG_NODIFYSAVE, ui->check_NodifyStatusSaved->isChecked());
    settings->setValue(REG_EVENT_FLAG, ui->radio_timer->isChecked());

    settings->setValue(REG_AUTOEXPORTLOG, ui->check_AutoDailySave->isChecked());
    settings->setValue(REG_EXPORTPATH, ui->edt_FoderPath->text());
    settings->setValue(REG_EXPORTTIME, eTimeStr);

    settings->setValue(REG_DELETEPASTLOG, ui->check_DeletePastLog->isChecked());
    settings->setValue(REG_DELETEPASTDAY, ui->edt_DeleteDay->text().toInt());

    settings->setValue(REG_IS_AUTOLED, ui->check_AutoRunLED->isChecked());
    settings->setValue(REG_LED_FONT, ui->fontComboBox->currentFont().family());
    settings->setValue(REG_LED_FONTSIZE, ui->spinBox_FontSize->value());

    QMessageBox::information(0, "Settings saved", "All settings have been saved successfully.");
    this->accept();
}

void GeneralSetDlg::on_btn_SaveFolderBrowse_clicked()
{
    QString dirPath = settings->value(REG_EXPORTPATH).toString();
    dirPath = QFileDialog::getExistingDirectory(0, tr("Select Folder to Save Logs"), dirPath);

    ui->edt_FoderPath->setText(dirPath);
}

void GeneralSetDlg::on_check_AutoDailySave_toggled(bool checked)
{
    ui->groupBox->setEnabled(checked);
}

void GeneralSetDlg::on_reset_database_clicked()
{
    if (QMessageBox::question(0, tr("Question"), tr("Are you sure to remove all data from database?\nAll data will be lost.")) != QMessageBox::Yes)
        return;

    QSqlQuery query;

    // StatusHistoryTable
    query.exec("DELETE FROM StatusHistoryTable");

    // TimeHistoryTable
    query.exec("DELETE FROM TimeHistoryTable");

    // tb_pd
    query.exec("DELETE FROM tb_pd");

    // MaterialTable
    QString qstr = tr("UPDATE MaterialTable SET material_name='', material_prep='', last_material_name=''");
    query.exec(qstr);

    // StatusTable
    query.exec("UPDATE StatusTable SET message_y='', message_r=''");

    QMessageBox::information(0, tr("Database Reset"), tr("All data has been removed."));
}

void GeneralSetDlg::on_radio_button_toggled(bool checked)
{
    ui->edt_SaveTimeInterval->setEnabled(!checked);
}
