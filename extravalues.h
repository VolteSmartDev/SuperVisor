#ifndef EXTRAVALUES_H
#define EXTRAVALUES_H

#include <QtGlobal>
#include <qapplication.h>
#include <QMessageBox>
#include <QSettings>

#define		SET_PATH			qApp->applicationDirPath() + "/settings.ini"
#define     SET_STARTADDR       "StartAddress"
#define     SET_ENTRYCOUNT      "EntryCount"
#define     SET_PORT            "Port"
#define     SET_IPADDRESS       "IPAddress"
#define		SET_DEVICEID		"DeviceID"

#define		LANPORT		48512
#define		LANPORT2	48513

#define		REG_LICENSE			"LicenseKey"
#define     REG_AUTOCONNECT     "AutoConnect"
#define     REG_REFRESHTIME     "RefeshTime"
#define     REG_SAVEHISTTIME    "HistoryTime"
#define     REG_EVENT_FLAG      "EventFlag" // button event = 0, time event
#define     REG_NODIFYSAVE      "NodifyStatusSave"

#define     REG_EXPORTPATH        "TimingExportPath"
#define     REG_AUTOEXPORTLOG       "IsAutoExportLog"
#define     REG_EXPORTTIME          "ExportTime"
#define     REG_IS_AUTOLED      "IsAutoLED"
#define     REG_LED_FONT        "LEDFont"
#define     REG_LED_FONTSIZE    "LEDFontSize"
#define     REG_TABLE_FILTER    "TableFilter"

#define     REG_AUTOREFRESH     "AutoRefresh"

#define     REG_DELETEPASTLOG   "DeletePastLog"
#define     REG_DELETEPASTDAY   "DeletePastDay"

#define		STR_REGISTER_PRODUCT	"Please Register"
#define		STR_REGISTER_FAIL		"Your license key does not match. Please try again."
#define		STR_REGISTER_SUCCESS	"License key has been applied."

#define     MAX_MCOUNT       8

#define		STS_UPDATE_SUCCESS		"Successfully updated."

static int runQuestion(QString qStr)
{
    QMessageBox msg;
    msg.setWindowTitle("Question");
    msg.setText(qStr);
    msg.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    return msg.exec();
}

#endif // EXTRAVALUES_H
