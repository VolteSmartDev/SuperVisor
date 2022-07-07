#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QModbusDataUnit>
#include <QModbusClient>
#include <QModbusTcpClient>
#include <QModbusReply>
#include <QSettings>
#include <QTimer>
#include <qudpsocket.h>
#include <qsqlquery.h>
#include <qsqlquerymodel.h>
#include <QtCharts>
#include <QSystemTrayIcon>
#include <QProcess>
#include <QToolBar>

#include "confrmpwddlg.h"
#include "correctpd.h"

QT_CHARTS_USE_NAMESPACE


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void loadSettings();
	void createInterface();

    QAction *act_restore, *act_connect, *act_disconnect, *act_setting, *act_quit;
    QSystemTrayIcon *trayIcon;
    ConfrmPwdDlg *conPwdDlg;
	void createTrayIconMenu();

    QModbusDataUnit readRequest() const;
    QModbusReply *lastRequest;
    QModbusClient *modbusDevice;
    bool isFirstConnectTime;
    int deviceID;

    QTimer timer;
	qint64 tryCount;

	QUdpSocket *udpSocket, *udpSocket2;
	QHostAddress hostAddr;
	
	QSqlQuery query;
	QSqlQueryModel model;

    QProcess *proc_Led1, *proc_Led2;

    /// for settings
    bool isAutoConnect;
    int refTimeInterval, saveTimeInterval;
    bool is_save_timer;

    /// For Message
	int entryList[48];
	int stateList[16];
    QString messageList[16];
	int laststateList[16];
    int laststateList2[16];
    void refreshTState();
	void loadMessage();
    QStringList lastYMessageList;
	QStringList lastRMessageList;
    QDateTime breakstart[16];

    /// For Material
    QList <QComboBox *> materialStatusList;
    void loadMaterials();
    void showMaterialtoInputTable(int table_id);
    bool materialInputChanged;
    int lastMaterialListId;
	bool isMaterialLoading;
    void updateCurTableMaterial(int table_id);

    /// for preparation
    void showPreparation(int table_id);
    void updatePreparation(int table_id);
    int lastPrepId;

    /// for save state history every 1 minutes
    QTimer logTimer;
    int saveLogInterval;
    bool isNodifySaved;
    QStringList statusLabels;
	QStringList statusHeaderLabels;
    void exportDailyStatus();

    // For Product Count
    int productCount[16];

    void show_productCount(bool last_only = false);
    void load_today_products();

    QDate last_date;

    // common
    QString dateTime2String(QDateTime datetime);
    QString date2String(QDate date);
    int date2Int(QDate date);
    int time2Int(QDateTime datetime);

    // delete log
    void delete_logs();
    bool is_auto_delete_log;
    int auto_delete_month;

    // table filter on status log
    void refresh_table_filter();

    /// product duration
    void refresh_pduration();




private slots:
    bool connectModbus();
    void readReady();
    void onStateChanged(int state);
    void onCheckTimerout();
    void saveStatusToDB();

    void on_actionConnect_triggered();
	void on_actionDisconnect_triggered();
    void on_btn_UpdateMaterial_clicked();
    void on_btn_IMPlus_clicked();
    void on_btn_IMMinus_clicked();
    void on_btn_UpdateYMsg_clicked();
    void on_btn_UpdateRMsg_clicked();
    void on_table_InputMaterial_cellChanged(int row, int column);
    void on_btn_updatePrapare_clicked();
    void on_tableList_currentRowChanged(int currentRow);
    void on_btn_GepPrep_clicked();
    void on_btn_PrepClear_clicked();
    void on_btn_PrepClearAll_clicked();
    void on_table_TableMaterialList_cellClicked(int row, int column);
    void on_actionSettings_triggered();
    void on_btn_DisplayLogs_clicked();

    void on_checkBox_AutoRefresh_toggled(bool checked);
    void on_btn_ExportToCSV_clicked();
    void on_btn_DisplayLogs2_clicked();
    void on_btn_ExportToCSV2_clicked();
    void on_actionChangePwd_triggered();

    void on_btn_UndoPrep_clicked();

    void on_LED1_finished(int exitCode, QProcess::ExitStatus exitStatus);
    void on_LED2_finished(int exitCode, QProcess::ExitStatus exitStatus);

    void on_actionLed1_triggered(bool checked);

    void on_actionLED2_triggered(bool checked);

    void on_dateFrom_pd_dateChanged(const QDate &date);

    void on_dateTo_pd_dateChanged(const QDate &date);

    void on_btn_displayProdCount_clicked();

    void on_btn_modifyProdCount_clicked();

    void on_btn_exportProd_clicked();

    void on_tb_prodcount_cellDoubleClicked(int row, int column);

    void on_btn_clearlog_clicked();

    void on_btn_refreshlog_clicked();

    void on_btn_tablefilter_clicked();

    void on_btn_resetProdCount_clicked();

    void on_btn_today_clicked();

    void on_date_todayproduct_dateChanged(const QDate &date);

    void on_btn_tablefilter2_clicked();

    void on_btn_exporttoday_clicked();

protected:
    virtual void resizeEvent(QResizeEvent *event);
	void closeEvent(QCloseEvent *event);
};

#endif // MAINWINDOW_H
