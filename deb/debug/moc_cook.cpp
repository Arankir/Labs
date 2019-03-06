/****************************************************************************
** Meta object code from reading C++ file 'cook.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MI_Client/cook.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cook.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Cook_t {
    QByteArrayData data[20];
    char stringdata0[288];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Cook_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Cook_t qt_meta_stringdata_Cook = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Cook"
QT_MOC_LITERAL(1, 5, 9), // "loginOpen"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 12), // "stateChanged"
QT_MOC_LITERAL(4, 29, 5), // "state"
QT_MOC_LITERAL(5, 35, 8), // "Network*"
QT_MOC_LITERAL(6, 44, 4), // "cook"
QT_MOC_LITERAL(7, 49, 21), // "on_whatchDish_clicked"
QT_MOC_LITERAL(8, 71, 28), // "on_whatchIngredients_clicked"
QT_MOC_LITERAL(9, 100, 15), // "on_Hide_clicked"
QT_MOC_LITERAL(10, 116, 21), // "on_createMenu_clicked"
QT_MOC_LITERAL(11, 138, 19), // "on_prevMenu_clicked"
QT_MOC_LITERAL(12, 158, 17), // "on_LogOut_clicked"
QT_MOC_LITERAL(13, 176, 13), // "OnResultCook1"
QT_MOC_LITERAL(14, 190, 13), // "OnResultCook2"
QT_MOC_LITERAL(15, 204, 13), // "OnResultCook3"
QT_MOC_LITERAL(16, 218, 13), // "OnResultCook4"
QT_MOC_LITERAL(17, 232, 13), // "rbCook1Change"
QT_MOC_LITERAL(18, 246, 20), // "on_C2BSearch_clicked"
QT_MOC_LITERAL(19, 267, 20) // "on_C4BSearch_clicked"

    },
    "Cook\0loginOpen\0\0stateChanged\0state\0"
    "Network*\0cook\0on_whatchDish_clicked\0"
    "on_whatchIngredients_clicked\0"
    "on_Hide_clicked\0on_createMenu_clicked\0"
    "on_prevMenu_clicked\0on_LogOut_clicked\0"
    "OnResultCook1\0OnResultCook2\0OnResultCook3\0"
    "OnResultCook4\0rbCook1Change\0"
    "on_C2BSearch_clicked\0on_C4BSearch_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Cook[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x06 /* Public */,
       3,    2,   90,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   95,    2, 0x08 /* Private */,
       8,    0,   96,    2, 0x08 /* Private */,
       9,    0,   97,    2, 0x08 /* Private */,
      10,    0,   98,    2, 0x08 /* Private */,
      11,    0,   99,    2, 0x08 /* Private */,
      12,    0,  100,    2, 0x08 /* Private */,
      13,    1,  101,    2, 0x08 /* Private */,
      14,    1,  104,    2, 0x08 /* Private */,
      15,    1,  107,    2, 0x08 /* Private */,
      16,    1,  110,    2, 0x08 /* Private */,
      17,    0,  113,    2, 0x08 /* Private */,
      18,    0,  114,    2, 0x08 /* Private */,
      19,    0,  115,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 5,    4,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Cook::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Cook *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->loginOpen(); break;
        case 1: _t->stateChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< Network*(*)>(_a[2]))); break;
        case 2: _t->on_whatchDish_clicked(); break;
        case 3: _t->on_whatchIngredients_clicked(); break;
        case 4: _t->on_Hide_clicked(); break;
        case 5: _t->on_createMenu_clicked(); break;
        case 6: _t->on_prevMenu_clicked(); break;
        case 7: _t->on_LogOut_clicked(); break;
        case 8: _t->OnResultCook1((*reinterpret_cast< Network*(*)>(_a[1]))); break;
        case 9: _t->OnResultCook2((*reinterpret_cast< Network*(*)>(_a[1]))); break;
        case 10: _t->OnResultCook3((*reinterpret_cast< Network*(*)>(_a[1]))); break;
        case 11: _t->OnResultCook4((*reinterpret_cast< Network*(*)>(_a[1]))); break;
        case 12: _t->rbCook1Change(); break;
        case 13: _t->on_C2BSearch_clicked(); break;
        case 14: _t->on_C4BSearch_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Network* >(); break;
            }
            break;
        case 8:
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
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Network* >(); break;
            }
            break;
        case 11:
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
            using _t = void (Cook::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Cook::loginOpen)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Cook::*)(int , Network * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Cook::stateChanged)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Cook::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_Cook.data,
    qt_meta_data_Cook,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Cook::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Cook::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Cook.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Cook::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void Cook::loginOpen()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Cook::stateChanged(int _t1, Network * _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
