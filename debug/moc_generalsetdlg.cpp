/****************************************************************************
** Meta object code from reading C++ file 'generalsetdlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../generalsetdlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'generalsetdlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GeneralSetDlg_t {
    QByteArrayData data[8];
    char stringdata0[154];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GeneralSetDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GeneralSetDlg_t qt_meta_stringdata_GeneralSetDlg = {
    {
QT_MOC_LITERAL(0, 0, 13), // "GeneralSetDlg"
QT_MOC_LITERAL(1, 14, 17), // "on_btn_OK_clicked"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 31), // "on_btn_SaveFolderBrowse_clicked"
QT_MOC_LITERAL(4, 65, 30), // "on_check_AutoDailySave_toggled"
QT_MOC_LITERAL(5, 96, 7), // "checked"
QT_MOC_LITERAL(6, 104, 25), // "on_reset_database_clicked"
QT_MOC_LITERAL(7, 130, 23) // "on_radio_button_toggled"

    },
    "GeneralSetDlg\0on_btn_OK_clicked\0\0"
    "on_btn_SaveFolderBrowse_clicked\0"
    "on_check_AutoDailySave_toggled\0checked\0"
    "on_reset_database_clicked\0"
    "on_radio_button_toggled"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GeneralSetDlg[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    1,   41,    2, 0x08 /* Private */,
       6,    0,   44,    2, 0x08 /* Private */,
       7,    1,   45,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    5,

       0        // eod
};

void GeneralSetDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GeneralSetDlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_btn_OK_clicked(); break;
        case 1: _t->on_btn_SaveFolderBrowse_clicked(); break;
        case 2: _t->on_check_AutoDailySave_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->on_reset_database_clicked(); break;
        case 4: _t->on_radio_button_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GeneralSetDlg::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_GeneralSetDlg.data,
    qt_meta_data_GeneralSetDlg,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GeneralSetDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GeneralSetDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GeneralSetDlg.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int GeneralSetDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
