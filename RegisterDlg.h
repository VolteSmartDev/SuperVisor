#pragma once

#include <QDialog>
#include "ui_RegisterDlg.h"

class RegisterDlg : public QDialog
{
	Q_OBJECT

public:
	RegisterDlg(QWidget *parent = Q_NULLPTR);
	~RegisterDlg();

private:
	Ui::RegisterDlg ui;

private slots:
	void on_Apply_Clicked();
};
