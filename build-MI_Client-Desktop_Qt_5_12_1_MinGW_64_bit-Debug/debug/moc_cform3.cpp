/****************************************************************************
** Meta object code from reading C++ file 'cform3.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MI_Client/cform3.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cform3.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_cForm3_t {
    QByteArrayData data[11];
    char stringdata0[113];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_cForm3_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_cForm3_t qt_meta_stringdata_cForm3 = {
    {
QT_MOC_LITERAL(0, 0, 6), // "cForm3"
QT_MOC_LITERAL(1, 7, 9), // "chbChange"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 5), // "state"
QT_MOC_LITERAL(4, 24, 17), // "on_Cancel_clicked"
QT_MOC_LITERAL(5, 42, 17), // "on_Applay_clicked"
QT_MOC_LITERAL(6, 60, 11), // "dishRequest"
QT_MOC_LITERAL(7, 72, 9), // "MyClient*"
QT_MOC_LITERAL(8, 82, 6), // "client"
QT_MOC_LITERAL(9, 89, 9), // "idRequest"
QT_MOC_LITERAL(10, 99, 13) // "insertRequest"

    },
    "cForm3\0chbChange\0\0state\0on_Cancel_clicked\0"
    "on_Applay_clicked\0dishRequest\0MyClient*\0"
    "client\0idRequest\0insertRequest"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_cForm3[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x08 /* Private */,
       4,    0,   47,    2, 0x08 /* Private */,
       5,    0,   48,    2, 0x08 /* Private */,
       6,    1,   49,    2, 0x08 /* Private */,
       9,    1,   52,    2, 0x08 /* Private */,
      10,    1,   55,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 7,    8,

       0        // eod
};

void cForm3::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<cForm3 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->chbChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_Cancel_clicked(); break;
        case 2: _t->on_Applay_clicked(); break;
        case 3: _t->dishRequest((*reinterpret_cast< MyClient*(*)>(_a[1]))); break;
        case 4: _t->idRequest((*reinterpret_cast< MyClient*(*)>(_a[1]))); break;
        case 5: _t->insertRequest((*reinterpret_cast< MyClient*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MyClient* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MyClient* >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MyClient* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject cForm3::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_cForm3.data,
    qt_meta_data_cForm3,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *cForm3::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *cForm3::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_cForm3.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int cForm3::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
