#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "extravalues.h"
#include "connectdialog.h"
#include "confrmpwddlg.h"

#include <qsettings.h>
#include <qsqlquerymodel.h>
#include <qsqlrecord.h>
#include <qmessagebox.h>

#include <QDebug>

extern QSettings *settings;

void MainWindow::loadMaterials()
{
	ui->table_TableMaterialList->clearContents();
	ui->table_TableMaterialList->setRowCount(16);

	isMaterialLoading = true;
    for (int i=0; i<16; i++) {

		QTableWidgetItem *item = new QTableWidgetItem(tr("Table %1").arg(i + 1));
		ui->table_TableMaterialList->setItem(i, 0, item);

        model.setQuery(tr("SELECT material_name, status, enabled FROM MaterialTable WHERE table_id = %1")
                       .arg(i+1));
		
        int mCount = model.rowCount();
        for (int j=0; j<mCount; j++) {
            QSqlRecord record = model.record(j);
			int enabled = record.value(2).toInt();
			if (enabled == 0) continue;
            //! [0-material name]
            QTableWidgetItem *item = new QTableWidgetItem(record.value(0).toString());
            item->setTextAlignment(Qt::AlignCenter);
            item->setTextColor(Qt::white);
            item->setFlags(Qt::ItemIsEnabled);
            //! [0]

            //! [1-material status]
            int status = record.value(1).toInt();
            switch (status) {
            case 0:
                item->setBackgroundColor(Qt::gray);
                break;
            case 1:
                item->setBackgroundColor(Qt::darkGreen);
                break;
            default:
                item->setBackgroundColor(Qt::red);
                break;
            }

            //! [1]

            ui->table_TableMaterialList->setItem(i, j+1, item);
        }
    }
	isMaterialLoading = false;

}

void MainWindow::showMaterialtoInputTable(int table_id)
{
    ui->label_MList->setText(tr("Table %1").arg(table_id));

    model.setQuery(tr("SELECT material_name, input_date, input_time, status FROM MaterialTable WHERE table_id = %1 AND enabled=1")
                   .arg(table_id));
    int rCount = model.rowCount();
    ui->table_InputMaterial->setRowCount(rCount);
	materialStatusList.clear();
    for (int i=0; i<rCount; i++) {

        QSqlRecord record = model.record(i);
        //! [0]
        QTableWidgetItem *item = new QTableWidgetItem(record.value(0).toString());
        ui->table_InputMaterial->setItem(i, 0, item);
        //! [0]

        //! [1]
        QString dateStr = record.value(1).toString();
        dateStr = dateStr.insert(4, "/");  /// 2020/0323;
        dateStr = dateStr.insert(7, "/");

        QString timeStr = record.value(2).toString(); //2323
        timeStr = timeStr.length()==3? timeStr.insert(1, ":") : timeStr.insert(2, ":");

        item = new QTableWidgetItem(dateStr + " " + timeStr);
        item->setTextAlignment(Qt::AlignCenter);
        item->setFlags(Qt::ItemIsEnabled);
        ui->table_InputMaterial->setItem(i, 1, item);
        //! [1]

        //! [2---state]
        int status = record.value(3).toInt();
        QComboBox *combo = new QComboBox();
        QStringList sList;
        sList<<"USED UP"<<"READY";
        combo->addItems(sList);
        materialStatusList.push_back(combo);
        materialStatusList.at(i)->setCurrentIndex(status);
        ui->table_InputMaterial->setCellWidget(i, 2, materialStatusList.at(i));
        //! [2]
    }
}

void MainWindow::on_btn_IMPlus_clicked()
{
    if (ui->table_InputMaterial->rowCount() < 8) {
        int id_toInsert = ui->table_InputMaterial->rowCount();
        ui->table_InputMaterial->insertRow(id_toInsert);

        //! [0]
        QTableWidgetItem *item = new QTableWidgetItem("");
        ui->table_InputMaterial->setItem(id_toInsert, 0, item);
        //! [0]
        QComboBox *combo = new QComboBox();
        QStringList sList;
        sList<<"REQUIRE"<<"ON PROGRESS";
        combo->addItems(sList);
		combo->setCurrentIndex(1);
        materialStatusList.push_back(combo);
        ui->table_InputMaterial->setCellWidget(id_toInsert, 2, combo);
        materialInputChanged = true;
    }
}

void MainWindow::on_btn_IMMinus_clicked()
{
    ui->table_InputMaterial->removeCellWidget(ui->table_InputMaterial->currentRow(), 2);
    materialStatusList.removeAt(ui->table_InputMaterial->currentRow());
    ui->table_InputMaterial->removeRow(ui->table_InputMaterial->currentRow());
    materialInputChanged = true;
}

void MainWindow::on_btn_UpdateMaterial_clicked()
{
    if (runQuestion("Are you sure to update?") != QMessageBox::Yes) return;
    updateCurTableMaterial(ui->table_TableMaterialList->currentRow() + 1);
    loadMaterials();
    statusBar()->showMessage(STS_UPDATE_SUCCESS, 5000);
}

void MainWindow::updateCurTableMaterial(int table_id)
{
    //! [0--check]
    int new_count = ui->table_InputMaterial->rowCount();
    for (int i=0; i<new_count; i++) {
        if (ui->table_InputMaterial->item(i, 0)->text() == "") {
            QMessageBox::warning(0, tr("Input or Update Material"),
                                 tr("Please input correct name for Material#%1").arg(i+1));
            return;
        }
    }
    //! [0]

    /// date, time
    QDateTime datetime = QDateTime::currentDateTime();
    int input_date = datetime.date().year() * 10000 +
            datetime.date().month() * 100 + datetime.date().day();
    int input_time = datetime.time().hour() * 100 + datetime.time().minute();

    model.setQuery(tr("SELECT ID FROM MaterialTable WHERE table_id = %1")
                   .arg(table_id));

    int input_count = model.rowCount();
	QString qStr;
    bool flag = false;
    if (new_count >= input_count) {
        /// update 0 to input_count
        for (int i=0; i<input_count; i++) {
            flag = query.exec(tr("UPDATE MaterialTable SET material_name = '%1', status=%2, "
                                 "enabled = 1, input_date=%5, input_time=%6 WHERE table_id=%3 AND material_id=%4")
                       .arg(ui->table_InputMaterial->item(i, 0)->text())
                       .arg(materialStatusList.at(i)->currentIndex())
                       .arg(table_id)
                       .arg(i+1)
                       .arg(input_date).arg(input_time));
        }

        /// Insert from input_count, to new_count
        for (int i=input_count; i<new_count; i++) {
            qStr = tr("INSERT INTO MaterialTable (material_name, status, enabled, material_id, table_id, input_date, input_time)"
                " VALUES('%1', %2, 1, %3, %4, %5, %6)")
				.arg(ui->table_InputMaterial->item(i, 0)->text())
				.arg(materialStatusList.at(i)->currentIndex())
				.arg(i + 1)
                .arg(table_id)
                .arg(input_date).arg(input_time);
				
            flag = query.exec(qStr);
        }
    }
    else {
        /// update 0 to new_count
        for (int i=0; i<new_count; i++) {
            flag = query.exec(tr("UPDATE MaterialTable SET material_name = '%1', status=%2, "
                                 "enabled = 1, input_date = %5, input_time = %6 WHERE table_id=%3 AND material_id=%4")
                       .arg(ui->table_InputMaterial->item(i, 0)->text())
                       .arg(materialStatusList.at(i)->currentIndex())
                       .arg(table_id)
                       .arg(i+1).arg(input_date).arg(input_time));
        }

        /// disable new_count to insert_count
        for (int i=new_count; i<input_count; i++) {
            flag = query.exec(tr("UPDATE MaterialTable SET enabled=0 "
                                 "WHERE table_id=%1 AND material_id=%2")
                       .arg(table_id)
                       .arg(i+1));
        }
    }

	loadMaterials();
    showMaterialtoInputTable(table_id);
}

void MainWindow::on_table_InputMaterial_cellChanged(int row, int column)
{
    materialInputChanged = true;
}

void MainWindow::on_btn_updatePrapare_clicked()
{
    if (ui->tableList->currentRow() < 0) return;
    updatePreparation(lastPrepId + 1);
    statusBar()->showMessage(STS_UPDATE_SUCCESS, 5000);
}

void MainWindow::on_tableList_currentRowChanged(int currentRow)
{
	if (currentRow == lastPrepId) return;
	updatePreparation(lastPrepId + 1);
    showPreparation(currentRow+1);
	lastPrepId = currentRow;
}

void MainWindow::showPreparation(int table_id)
{
    ui->label_prep->setText(tr("Material Preparation for Table %1")
                            .arg(table_id));
    model.setQuery(tr("SELECT material_prep FROM MaterialTable "
                      "WHERE table_id=%1 ORDER BY material_id ASC")
                   .arg(table_id));
    for (int i=0; i<model.rowCount(); i++) {
        QString curPrep = model.record(i).value(0).toString();
        ui->table_Prepare->item(i, 1)->setText(curPrep);
    }
}

void MainWindow::updatePreparation(int table_id)
{
	/// check
    for (int i = 0; i < 7; i++)
	{
		if (ui->table_Prepare->item(i, 1)->text()=="" && ui->table_Prepare->item(i+1, 1)->text() !="") {
			QMessageBox::warning(0, tr("Material Preparation"), tr("Please input materials one by one without any blanks"));
			return;
		}
    }

	bool flag = false;
    for (int i=0; i<8; i++) {
        QString curPrep = ui->table_Prepare->item(i, 1)->text();
        flag = query.exec(tr("UPDATE MaterialTable SET material_prep = '%1' "
                      "WHERE table_id=%2 AND material_id=%3")
                   .arg(curPrep).arg(table_id).arg(i+1));
    }
}

void MainWindow::on_btn_GepPrep_clicked()
{

    bool flag = false;
    QMessageBox msg;
	QSqlQueryModel tmpModel;
    QSqlQuery tmpQuery;
	QString qStr;
    msg.setWindowTitle(tr("Get material list from preparation database"));
    msg.setText(tr("Are you sure to replace all materials?"));
    msg.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    if (msg.exec() != QMessageBox::Yes) return;

    /// store last status
    tmpModel.setQuery("SELECT ID,material_name,status,enabled FROM MaterialTable");
    for (int i=0; i<tmpModel.rowCount(); i++) {
        QSqlRecord tmpRecord = tmpModel.record(i);
        qStr = tr("UPDATE MaterialTable SET last_material_name='%1',last_status=%2,last_enabled=%3 "
                  "WHERE(ID=%4)")
                .arg(tmpRecord.value(1).toString())
                .arg(tmpRecord.value(2).toInt())
                .arg(tmpRecord.value(3).toInt())
                .arg(tmpRecord.value(0).toInt());
        tmpQuery.exec(qStr);
    }

    tmpModel.setQuery(tr("SELECT ID, material_prep FROM MaterialTable ORDER BY ID ASC"));
    while (tmpModel.canFetchMore()) tmpModel.fetchMore();

	int rCount = tmpModel.rowCount();
	QString tmpStr;
	for (int i = 0; i < rCount; i++)
	{
		int curId = tmpModel.record(i).value(0).toInt();
		tmpStr = tmpModel.record(i).value(1).toString();
		int enabled = 1;
		if (tmpStr.isEmpty()) enabled = 0;
		qStr = "UPDATE MaterialTable SET material_name ='" + tmpStr + tr("', status=%1, enabled=%1"
			" WHERE ID=%2").arg(enabled).arg(curId);
		flag = query.exec(qStr);
	}

	loadMaterials();
    ui->table_TableMaterialList->setCurrentCell(lastMaterialListId, 1);
    showMaterialtoInputTable(lastMaterialListId + 1);

    ui->btn_UndoPrep->setEnabled(true);
}

void MainWindow::on_btn_PrepClear_clicked()
{
    if (runQuestion("Are you sure to clear the matarial prepatation list for current table?") != QMessageBox::Yes)
        return;
    for (int i=0; i<8; i++) {
        ui->table_Prepare->item(i, 1)->setText("");
    }

    updatePreparation(lastPrepId + 1);
    showPreparation(lastPrepId + 1);
}

void MainWindow::on_btn_PrepClearAll_clicked()
{
    if (runQuestion("Are you sure to clear all material prepatation list?") != QMessageBox::Yes)
        return;

    query.exec(tr("UPDATE MaterialTable SET material_prep = ''"));

    showPreparation(lastPrepId + 1);
}


void MainWindow::on_table_TableMaterialList_cellClicked(int row, int column)
{
    /*if (materialInputChanged  == true && isMaterialLoading == false) {
        updateCurTableMaterial(previousRow + 1);
        materialInputChanged = false;
    }*/
    lastMaterialListId = row;
    showMaterialtoInputTable(row+1);
}
