#include "RegisterDlg.h"
#include "extravalues.h"
#include "Security_Custom.h"

#include <qsettings.h>
#include <qmessagebox.h>

extern QSettings *settings;

RegisterDlg::RegisterDlg(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	this->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);

	ui.edt_P->setText(QString(GetComputerProductKey()));

	connect(ui.btn_Apply, SIGNAL(clicked()), this, SLOT(on_Apply_Clicked()));
}

RegisterDlg::~RegisterDlg()
{

}

void RegisterDlg::on_Apply_Clicked()
{
	QString inputLicenseKey = ui.edt_L->text();

	if (inputLicenseKey.count() < 24) {
		QMessageBox::warning(0, STR_REGISTER_PRODUCT, tr("It's wrong! Please input correct license key."));
		return;
	}

	if (inputLicenseKey == GenMD5LicenKey(GetComputerProductKey())) {
		QMessageBox::information(0, STR_REGISTER_PRODUCT, STR_REGISTER_SUCCESS);
		settings->setValue(REG_LICENSE, ui.edt_L->text());
		this->accept();
	}
	else
	{
		QMessageBox::warning(0, STR_REGISTER_PRODUCT, STR_REGISTER_FAIL);
	}	
}