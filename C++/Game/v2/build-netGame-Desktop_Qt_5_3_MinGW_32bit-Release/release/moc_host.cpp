/****************************************************************************
** Meta object code from reading C++ file 'host.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../netGame/host.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'host.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_host_t {
    QByteArrayData data[12];
    char stringdata[199];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_host_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_host_t qt_meta_stringdata_host = {
    {
QT_MOC_LITERAL(0, 0, 4),
QT_MOC_LITERAL(1, 5, 17),
QT_MOC_LITERAL(2, 23, 0),
QT_MOC_LITERAL(3, 24, 17),
QT_MOC_LITERAL(4, 42, 20),
QT_MOC_LITERAL(5, 63, 28),
QT_MOC_LITERAL(6, 92, 26),
QT_MOC_LITERAL(7, 119, 13),
QT_MOC_LITERAL(8, 133, 15),
QT_MOC_LITERAL(9, 149, 5),
QT_MOC_LITERAL(10, 155, 24),
QT_MOC_LITERAL(11, 180, 18)
    },
    "host\0playerListChanged\0\0initialLobbySetUp\0"
    "pbLobbyAcceptEnabler\0pbLobbyChangeUserNameEnabler\0"
    "processSelfUserNameRequest\0acceptClicked\0"
    "clientConnected\0newID\0processReadyExternalData\0"
    "updateCurrentUsers"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_host[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    0,   63,    2, 0x08 /* Private */,
       7,    0,   64,    2, 0x08 /* Private */,
       8,    1,   65,    2, 0x08 /* Private */,
      10,    0,   68,    2, 0x08 /* Private */,
      11,    0,   69,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UChar,    9,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void host::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        host *_t = static_cast<host *>(_o);
        switch (_id) {
        case 0: _t->playerListChanged(); break;
        case 1: _t->initialLobbySetUp(); break;
        case 2: _t->pbLobbyAcceptEnabler(); break;
        case 3: _t->pbLobbyChangeUserNameEnabler(); break;
        case 4: _t->processSelfUserNameRequest(); break;
        case 5: _t->acceptClicked(); break;
        case 6: _t->clientConnected((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 7: _t->processReadyExternalData(); break;
        case 8: _t->updateCurrentUsers(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (host::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&host::playerListChanged)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject host::staticMetaObject = {
    { &player::staticMetaObject, qt_meta_stringdata_host.data,
      qt_meta_data_host,  qt_static_metacall, 0, 0}
};


const QMetaObject *host::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *host::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_host.stringdata))
        return static_cast<void*>(const_cast< host*>(this));
    return player::qt_metacast(_clname);
}

int host::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = player::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void host::playerListChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
