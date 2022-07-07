#include "connectdialog.h"
#include "mainwindow.h"
#include "connection.h"
#include "extravalues.h"
#include "Security_Custom.h"
#include "RegisterDlg.h"
#include "confrmpwddlg.h"

#include <QApplication>
#include <QSystemTrayIcon>
#include <qsettings.h>
#include <QtSql>
#include <QDateTime>

QSettings *settings;

int main(int argc, char *argv[])
{
    //! [0]
    QApplication a(argc, argv);

    //! [0]

    //! [1]
    if (createConnection() != true) {
        QMessageBox::warning(0, "Warning",
                             "Database Connection Failed!\nProduct history may not be saved.");
    }
    //! [1]
	settings = new QSettings("HKEY_CURRENT_USER\\Software\\SUPERVISOR_FOR_MATERIAL",
		QSettings::NativeFormat);
    //! [2]

    /// check expire
    QDate date = QDate::currentDate();
    QDate date1 = QDate(2021, 8, 5);
    if (date.daysTo(date1) < 0) {
      //  QMessageBox::warning(0, "Warning",
      //                       "Please get genuine version.");
      //  return -2;
    }

	//! [2]
	QApplication::setQuitOnLastWindowClosed(true);
	//! [2]

	QString licenseKey = settings->value(REG_LICENSE).toString();

	if (licenseKey != GenMD5LicenKey(GetComputerProductKey()))
	{
		RegisterDlg *dlg = new RegisterDlg();
		if (dlg->exec() != QDialog::Accepted) {
			return -1;
		}
	}

	//! [2]
	QSqlQueryModel model;
	model.setQuery("SELECT password FROM Users WHERE ID=1");
	if (!model.record(0).value(0).toString().isEmpty()) {
		ConfrmPwdDlg dlg;
		if (dlg.exec() != QDialog::Accepted) return -2;
	}

	MainWindow w;
    w.showMaximized();

    return a.exec();
}
