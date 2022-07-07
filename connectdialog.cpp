#include "connectdialog.h"
#include "ui_connectdialog.h"
#include "extravalues.h"

#include <QSettings>

extern QSettings *settings;

ConnectDialog::ConnectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConnectDialog)
{
    ui->setupUi(this);
    //! [0]
    QString strIP = settings->value(SET_IPADDRESS).toString();
	int deviceID = settings->value(SET_DEVICEID).toInt();
    int port = settings->value(SET_PORT).toInt();
    int startAddress = settings->value(SET_STARTADDR).toInt();
    int entryCount = settings->value(SET_ENTRYCOUNT).toInt();
    //! [0]

    //! [1]
    ui->edt_IP->setText(strIP.isEmpty() ? "127.0.0.1" : strIP);
    ui->edt_DeviceID->setText(tr("%1").arg(deviceID == 0? 1 : deviceID));
    ui->edt_Port->setText(tr("%1").arg(port <= 0 ? 502 : port));
    ui->edt_Start->setText(tr("%1").arg(startAddress <= 0 ? 20 : startAddress));
    ui->edt_ValCont->setText(tr("%1").arg(entryCount == 0 ? 48 : entryCount));
    //! [1]

}

ConnectDialog::~ConnectDialog()
{
    delete ui;
}

void ConnectDialog::on_btn_Connect_clicked()
{
    //! [0]
    QString strIP = ui->edt_IP->text();
    if (strIP.isEmpty()) {ui->edt_IP->setFocus(); return;}
    int deviceID = ui->edt_DeviceID->text().toInt();
    if (deviceID <= 0) {ui->edt_DeviceID->setFocus(); return;}
    int port = ui->edt_Port->text().toInt();
    if (port <= 0) {ui->edt_Port->setFocus(); return;}
    int startAddress = ui->edt_Start->text().toInt();
    if (startAddress <= 0) {ui->edt_Start->setFocus(); return;}
    int entryCount = ui->edt_ValCont->text().toInt();
    if (entryCount <= 0) {ui->edt_ValCont->setFocus(); return;}
    //! [0]

    //! [1]
    settings->setValue(SET_IPADDRESS, strIP);
    settings->setValue(SET_DEVICEID, deviceID);
    settings->setValue(SET_PORT, port);
    settings->setValue(SET_STARTADDR, startAddress);
    settings->setValue(SET_ENTRYCOUNT, entryCount);
    //! [1]

    accept();
}
