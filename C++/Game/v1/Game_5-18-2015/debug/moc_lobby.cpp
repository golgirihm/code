/****************************************************************************
** Meta object code from reading C++ file 'lobby.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Game_5-20-2015/Forms_Code/lobby.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lobby.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_lobby_t {
    QByteArrayData data[6];
    char stringdata[76];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_lobby_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_lobby_t qt_meta_stringdata_lobby = {
    {
QT_MOC_LITERAL(0, 0, 5),
QT_MOC_LITERAL(1, 6, 19),
QT_MOC_LITERAL(2, 26, 0),
QT_MOC_LITERAL(3, 27, 19),
QT_MOC_LITERAL(4, 47, 11),
QT_MOC_LITERAL(5, 59, 16)
    },
    "lobby\0ServerAcceptClicked\0\0"
    "ClientAcceptClicked\0TextChanged\0"
    "StartGameClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_lobby[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    0,   35,    2, 0x06 /* Public */,
       4,    0,   36,    2, 0x06 /* Public */,
       5,    0,   37,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void lobby::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        lobby *_t = static_cast<lobby *>(_o);
        switch (_id) {
        case 0: _t->ServerAcceptClicked(); break;
        case 1: _t->ClientAcceptClicked(); break;
        case 2: _t->TextChanged(); break;
        case 3: _t->StartGameClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (lobby::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&lobby::ServerAcceptClicked)) {
                *result = 0;
            }
        }
        {
            typedef void (lobby::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&lobby::ClientAcceptClicked)) {
                *result = 1;
            }
        }
        {
            typedef void (lobby::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&lobby::TextChanged)) {
                *result = 2;
            }
        }
        {
            typedef void (lobby::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&lobby::StartGameClicked)) {
                *result = 3;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject lobby::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_lobby.data,
      qt_meta_data_lobby,  qt_static_metacall, 0, 0}
};


const QMetaObject *lobby::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *lobby::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_lobby.stringdata))
        return static_cast<void*>(const_cast< lobby*>(this));
    return QDialog::qt_metacast(_clname);
}

int lobby::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void lobby::ServerAcceptClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void lobby::ClientAcceptClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void lobby::TextChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void lobby::StartGameClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
