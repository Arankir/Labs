/****************************************************************************
** Meta object code from reading C++ file 'portie.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Cli/Labs/MI_Client/portie.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'portie.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Portie_t {
    QByteArrayData data[20];
    char stringdata0[340];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Portie_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Portie_t qt_meta_stringdata_Portie = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Portie"
QT_MOC_LITERAL(1, 7, 9), // "loginOpen"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 15), // "on_Hide_clicked"
QT_MOC_LITERAL(4, 34, 17), // "on_LogOut_clicked"
QT_MOC_LITERAL(5, 52, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(6, 76, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(7, 100, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(8, 122, 23), // "on_Result_networkPortie"
QT_MOC_LITERAL(9, 146, 8), // "Network*"
QT_MOC_LITERAL(10, 155, 6), // "portie"
QT_MOC_LITERAL(11, 162, 25), // "on_P1ButtonAccept_clicked"
QT_MOC_LITERAL(12, 188, 24), // "on_P2ButtonApply_clicked"
QT_MOC_LITERAL(13, 213, 17), // "on_ResultNewGuest"
QT_MOC_LITERAL(14, 231, 21), // "on_P3TVGuests_clicked"
QT_MOC_LITERAL(15, 253, 11), // "QModelIndex"
QT_MOC_LITERAL(16, 265, 5), // "index"
QT_MOC_LITERAL(17, 271, 23), // "on_pushButton_4_clicked"
QT_MOC_LITERAL(18, 295, 23), // "on_pushButton_5_clicked"
QT_MOC_LITERAL(19, 319, 20) // "on_ResultChangeGuest"

    },
    "Portie\0loginOpen\0\0on_Hide_clicked\0"
    "on_LogOut_clicked\0on_pushButton_2_clicked\0"
    "on_pushButton_3_clicked\0on_pushButton_clicked\0"
    "on_Result_networkPortie\0Network*\0"
    "portie\0on_P1ButtonAccept_clicked\0"
    "on_P2ButtonApply_clicked\0on_ResultNewGuest\0"
    "on_P3TVGuests_clicked\0QModelIndex\0"
    "index\0on_pushButton_4_clicked\0"
    "on_pushButton_5_clicked\0on_ResultChangeGuest"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Portie[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   85,    2, 0x08 /* Private */,
       4,    0,   86,    2, 0x08 /* Private */,
       5,    0,   87,    2, 0x08 /* Private */,
       6,    0,   88,    2, 0x08 /* Private */,
       7,    0,   89,    2, 0x08 /* Private */,
       8,    1,   90,    2, 0x08 /* Private */,
      11,    0,   93,    2, 0x08 /* Private */,
      12,    0,   94,    2, 0x08 /* Private */,
      13,    1,   95,    2, 0x08 /* Private */,
      14,    1,   98,    2, 0x08 /* Private */,
      17,    0,  101,    2, 0x08 /* Private */,
      18,    0,  102,    2, 0x08 /* Private */,
      19,    1,  103,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,    2,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,    2,

       0        // eod
};

void Portie::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Portie *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->loginOpen(); break;
        case 1: _t->on_Hide_clicked(); break;
        case 2: _t->on_LogOut_clicked(); break;
        case 3: _t->on_pushButton_2_clicked(); break;
        case 4: _t->on_pushButton_3_clicked(); break;
        case 5: _t->on_pushButton_clicked(); break;
        case 6: _t->on_Result_networkPortie((*reinterpret_cast< Network*(*)>(_a[1]))); break;
        case 7: _t->on_P1ButtonAccept_clicked(); break;
        case 8: _t->on_P2ButtonApply_clicked(); break;
        case 9: _t->on_ResultNewGuest((*reinterpret_cast< Network*(*)>(_a[1]))); break;
        case 10: _t->on_P3TVGuests_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 11: _t->on_pushButton_4_clicked(); break;
        case 12: _t->on_pushButton_5_clicked(); break;
        case 13: _t->on_ResultChangeGuest((*reinterpret_cast< Network*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Network* >(); break;
            }
            break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Network* >(); break;
            }
            break;
        case 13:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Network* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Portie::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Portie::loginOpen)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Portie::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_Portie.data,
    qt_meta_data_Portie,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Portie::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Portie::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Portie.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Portie::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void Portie::loginOpen()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
