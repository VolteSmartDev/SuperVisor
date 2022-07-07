/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[56];
    char stringdata0[1254];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 13), // "connectModbus"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 9), // "readReady"
QT_MOC_LITERAL(4, 36, 14), // "onStateChanged"
QT_MOC_LITERAL(5, 51, 5), // "state"
QT_MOC_LITERAL(6, 57, 15), // "onCheckTimerout"
QT_MOC_LITERAL(7, 73, 14), // "saveStatusToDB"
QT_MOC_LITERAL(8, 88, 26), // "on_actionConnect_triggered"
QT_MOC_LITERAL(9, 115, 29), // "on_actionDisconnect_triggered"
QT_MOC_LITERAL(10, 145, 29), // "on_btn_UpdateMaterial_clicked"
QT_MOC_LITERAL(11, 175, 21), // "on_btn_IMPlus_clicked"
QT_MOC_LITERAL(12, 197, 22), // "on_btn_IMMinus_clicked"
QT_MOC_LITERAL(13, 220, 25), // "on_btn_UpdateYMsg_clicked"
QT_MOC_LITERAL(14, 246, 25), // "on_btn_UpdateRMsg_clicked"
QT_MOC_LITERAL(15, 272, 34), // "on_table_InputMaterial_cellCh..."
QT_MOC_LITERAL(16, 307, 3), // "row"
QT_MOC_LITERAL(17, 311, 6), // "column"
QT_MOC_LITERAL(18, 318, 28), // "on_btn_updatePrapare_clicked"
QT_MOC_LITERAL(19, 347, 30), // "on_tableList_currentRowChanged"
QT_MOC_LITERAL(20, 378, 10), // "currentRow"
QT_MOC_LITERAL(21, 389, 22), // "on_btn_GepPrep_clicked"
QT_MOC_LITERAL(22, 412, 24), // "on_btn_PrepClear_clicked"
QT_MOC_LITERAL(23, 437, 27), // "on_btn_PrepClearAll_clicked"
QT_MOC_LITERAL(24, 465, 38), // "on_table_TableMaterialList_ce..."
QT_MOC_LITERAL(25, 504, 27), // "on_actionSettings_triggered"
QT_MOC_LITERAL(26, 532, 26), // "on_btn_DisplayLogs_clicked"
QT_MOC_LITERAL(27, 559, 31), // "on_checkBox_AutoRefresh_toggled"
QT_MOC_LITERAL(28, 591, 7), // "checked"
QT_MOC_LITERAL(29, 599, 26), // "on_btn_ExportToCSV_clicked"
QT_MOC_LITERAL(30, 626, 27), // "on_btn_DisplayLogs2_clicked"
QT_MOC_LITERAL(31, 654, 27), // "on_btn_ExportToCSV2_clicked"
QT_MOC_LITERAL(32, 682, 28), // "on_actionChangePwd_triggered"
QT_MOC_LITERAL(33, 711, 23), // "on_btn_UndoPrep_clicked"
QT_MOC_LITERAL(34, 735, 16), // "on_LED1_finished"
QT_MOC_LITERAL(35, 752, 8), // "exitCode"
QT_MOC_LITERAL(36, 761, 20), // "QProcess::ExitStatus"
QT_MOC_LITERAL(37, 782, 10), // "exitStatus"
QT_MOC_LITERAL(38, 793, 16), // "on_LED2_finished"
QT_MOC_LITERAL(39, 810, 23), // "on_actionLed1_triggered"
QT_MOC_LITERAL(40, 834, 23), // "on_actionLED2_triggered"
QT_MOC_LITERAL(41, 858, 26), // "on_dateFrom_pd_dateChanged"
QT_MOC_LITERAL(42, 885, 4), // "date"
QT_MOC_LITERAL(43, 890, 24), // "on_dateTo_pd_dateChanged"
QT_MOC_LITERAL(44, 915, 31), // "on_btn_displayProdCount_clicked"
QT_MOC_LITERAL(45, 947, 30), // "on_btn_modifyProdCount_clicked"
QT_MOC_LITERAL(46, 978, 25), // "on_btn_exportProd_clicked"
QT_MOC_LITERAL(47, 1004, 33), // "on_tb_prodcount_cellDoubleCli..."
QT_MOC_LITERAL(48, 1038, 23), // "on_btn_clearlog_clicked"
QT_MOC_LITERAL(49, 1062, 25), // "on_btn_refreshlog_clicked"
QT_MOC_LITERAL(50, 1088, 26), // "on_btn_tablefilter_clicked"
QT_MOC_LITERAL(51, 1115, 29), // "on_btn_resetProdCount_clicked"
QT_MOC_LITERAL(52, 1145, 20), // "on_btn_today_clicked"
QT_MOC_LITERAL(53, 1166, 32), // "on_date_todayproduct_dateChanged"
QT_MOC_LITERAL(54, 1199, 27), // "on_btn_tablefilter2_clicked"
QT_MOC_LITERAL(55, 1227, 26) // "on_btn_exporttoday_clicked"

    },
    "MainWindow\0connectModbus\0\0readReady\0"
    "onStateChanged\0state\0onCheckTimerout\0"
    "saveStatusToDB\0on_actionConnect_triggered\0"
    "on_actionDisconnect_triggered\0"
    "on_btn_UpdateMaterial_clicked\0"
    "on_btn_IMPlus_clicked\0on_btn_IMMinus_clicked\0"
    "on_btn_UpdateYMsg_clicked\0"
    "on_btn_UpdateRMsg_clicked\0"
    "on_table_InputMaterial_cellChanged\0"
    "row\0column\0on_btn_updatePrapare_clicked\0"
    "on_tableList_currentRowChanged\0"
    "currentRow\0on_btn_GepPrep_clicked\0"
    "on_btn_PrepClear_clicked\0"
    "on_btn_PrepClearAll_clicked\0"
    "on_table_TableMaterialList_cellClicked\0"
    "on_actionSettings_triggered\0"
    "on_btn_DisplayLogs_clicked\0"
    "on_checkBox_AutoRefresh_toggled\0checked\0"
    "on_btn_ExportToCSV_clicked\0"
    "on_btn_DisplayLogs2_clicked\0"
    "on_btn_ExportToCSV2_clicked\0"
    "on_actionChangePwd_triggered\0"
    "on_btn_UndoPrep_clicked\0on_LED1_finished\0"
    "exitCode\0QProcess::ExitStatus\0exitStatus\0"
    "on_LED2_finished\0on_actionLed1_triggered\0"
    "on_actionLED2_triggered\0"
    "on_dateFrom_pd_dateChanged\0date\0"
    "on_dateTo_pd_dateChanged\0"
    "on_btn_displayProdCount_clicked\0"
    "on_btn_modifyProdCount_clicked\0"
    "on_btn_exportProd_clicked\0"
    "on_tb_prodcount_cellDoubleClicked\0"
    "on_btn_clearlog_clicked\0"
    "on_btn_refreshlog_clicked\0"
    "on_btn_tablefilter_clicked\0"
    "on_btn_resetProdCount_clicked\0"
    "on_btn_today_clicked\0"
    "on_date_todayproduct_dateChanged\0"
    "on_btn_tablefilter2_clicked\0"
    "on_btn_exporttoday_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      45,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  239,    2, 0x08 /* Private */,
       3,    0,  240,    2, 0x08 /* Private */,
       4,    1,  241,    2, 0x08 /* Private */,
       6,    0,  244,    2, 0x08 /* Private */,
       7,    0,  245,    2, 0x08 /* Private */,
       8,    0,  246,    2, 0x08 /* Private */,
       9,    0,  247,    2, 0x08 /* Private */,
      10,    0,  248,    2, 0x08 /* Private */,
      11,    0,  249,    2, 0x08 /* Private */,
      12,    0,  250,    2, 0x08 /* Private */,
      13,    0,  251,    2, 0x08 /* Private */,
      14,    0,  252,    2, 0x08 /* Private */,
      15,    2,  253,    2, 0x08 /* Private */,
      18,    0,  258,    2, 0x08 /* Private */,
      19,    1,  259,    2, 0x08 /* Private */,
      21,    0,  262,    2, 0x08 /* Private */,
      22,    0,  263,    2, 0x08 /* Private */,
      23,    0,  264,    2, 0x08 /* Private */,
      24,    2,  265,    2, 0x08 /* Private */,
      25,    0,  270,    2, 0x08 /* Private */,
      26,    0,  271,    2, 0x08 /* Private */,
      27,    1,  272,    2, 0x08 /* Private */,
      29,    0,  275,    2, 0x08 /* Private */,
      30,    0,  276,    2, 0x08 /* Private */,
      31,    0,  277,    2, 0x08 /* Private */,
      32,    0,  278,    2, 0x08 /* Private */,
      33,    0,  279,    2, 0x08 /* Private */,
      34,    2,  280,    2, 0x08 /* Private */,
      38,    2,  285,    2, 0x08 /* Private */,
      39,    1,  290,    2, 0x08 /* Private */,
      40,    1,  293,    2, 0x08 /* Private */,
      41,    1,  296,    2, 0x08 /* Private */,
      43,    1,  299,    2, 0x08 /* Private */,
      44,    0,  302,    2, 0x08 /* Private */,
      45,    0,  303,    2, 0x08 /* Private */,
      46,    0,  304,    2, 0x08 /* Private */,
      47,    2,  305,    2, 0x08 /* Private */,
      48,    0,  310,    2, 0x08 /* Private */,
      49,    0,  311,    2, 0x08 /* Private */,
      50,    0,  312,    2, 0x08 /* Private */,
      51,    0,  313,    2, 0x08 /* Private */,
      52,    0,  314,    2, 0x08 /* Private */,
      53,    1,  315,    2, 0x08 /* Private */,
      54,    0,  318,    2, 0x08 /* Private */,
      55,    0,  319,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   16,   17,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   16,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   28,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 36,   35,   37,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 36,   35,   37,
    QMetaType::Void, QMetaType::Bool,   28,
    QMetaType::Void, QMetaType::Bool,   28,
    QMetaType::Void, QMetaType::QDate,   42,
    QMetaType::Void, QMetaType::QDate,   42,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   16,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QDate,   42,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { bool _r = _t->connectModbus();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 1: _t->readReady(); break;
        case 2: _t->onStateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->onCheckTimerout(); break;
        case 4: _t->saveStatusToDB(); break;
        case 5: _t->on_actionConnect_triggered(); break;
        case 6: _t->on_actionDisconnect_triggered(); break;
        case 7: _t->on_btn_UpdateMaterial_clicked(); break;
        case 8: _t->on_btn_IMPlus_clicked(); break;
        case 9: _t->on_btn_IMMinus_clicked(); break;
        case 10: _t->on_btn_UpdateYMsg_clicked(); break;
        case 11: _t->on_btn_UpdateRMsg_clicked(); break;
        case 12: _t->on_table_InputMaterial_cellChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 13: _t->on_btn_updatePrapare_clicked(); break;
        case 14: _t->on_tableList_currentRowChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->on_btn_GepPrep_clicked(); break;
        case 16: _t->on_btn_PrepClear_clicked(); break;
        case 17: _t->on_btn_PrepClearAll_clicked(); break;
        case 18: _t->on_table_TableMaterialList_cellClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 19: _t->on_actionSettings_triggered(); break;
        case 20: _t->on_btn_DisplayLogs_clicked(); break;
        case 21: _t->on_checkBox_AutoRefresh_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 22: _t->on_btn_ExportToCSV_clicked(); break;
        case 23: _t->on_btn_DisplayLogs2_clicked(); break;
        case 24: _t->on_btn_ExportToCSV2_clicked(); break;
        case 25: _t->on_actionChangePwd_triggered(); break;
        case 26: _t->on_btn_UndoPrep_clicked(); break;
        case 27: _t->on_LED1_finished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QProcess::ExitStatus(*)>(_a[2]))); break;
        case 28: _t->on_LED2_finished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QProcess::ExitStatus(*)>(_a[2]))); break;
        case 29: _t->on_actionLed1_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 30: _t->on_actionLED2_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 31: _t->on_dateFrom_pd_dateChanged((*reinterpret_cast< const QDate(*)>(_a[1]))); break;
        case 32: _t->on_dateTo_pd_dateChanged((*reinterpret_cast< const QDate(*)>(_a[1]))); break;
        case 33: _t->on_btn_displayProdCount_clicked(); break;
        case 34: _t->on_btn_modifyProdCount_clicked(); break;
        case 35: _t->on_btn_exportProd_clicked(); break;
        case 36: _t->on_tb_prodcount_cellDoubleClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 37: _t->on_btn_clearlog_clicked(); break;
        case 38: _t->on_btn_refreshlog_clicked(); break;
        case 39: _t->on_btn_tablefilter_clicked(); break;
        case 40: _t->on_btn_resetProdCount_clicked(); break;
        case 41: _t->on_btn_today_clicked(); break;
        case 42: _t->on_date_todayproduct_dateChanged((*reinterpret_cast< const QDate(*)>(_a[1]))); break;
        case 43: _t->on_btn_tablefilter2_clicked(); break;
        case 44: _t->on_btn_exporttoday_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 45)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 45;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 45)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 45;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
