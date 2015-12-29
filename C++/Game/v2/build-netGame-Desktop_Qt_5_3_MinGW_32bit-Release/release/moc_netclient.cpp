/****************************************************************************
** Meta object code from reading C++ file 'netclient.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../netGame/netclient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'netclient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_netclient_t {
    QByteArrayData data[11];
    char stringdata[144];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_netclient_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_netclient_t qt_meta_stringdata_netclient = {
    {
QT_MOC_LITERAL(0, 0, 9),
QT_MOC_LITERAL(1, 10, 17),
QT_MOC_LITERAL(2, 28, 0),
QT_MOC_LITERAL(3, 29, 14),
QT_MOC_LITERAL(4, 44, 11),
QT_MOC_LITERAL(5, 56, 16),
QT_MOC_LITERAL(6, 73, 12),
QT_MOC_LITERAL(7, 86, 4),
QT_MOC_LITERAL(8, 91, 19),
QT_MOC_LITERAL(9, 111, 17),
QT_MOC_LITERAL(10, 129, 14)
    },
    "netclient\0ExternalDataReady\0\0"
    "ConnectionMade\0isConnected\0attemptToConnect\0"
    "SendToServer\0data\0ReceiveExternalData\0"
    "connectionMessage\0ReadSocketData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_netclient[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    0,   55,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   56,    2, 0x0a /* Public */,
       5,    0,   57,    2, 0x0a /* Public */,
       6,    1,   58,    2, 0x0a /* Public */,
       8,    0,   61,    2, 0x0a /* Public */,
       9,    0,   62,    2, 0x0a /* Public */,
      10,    0,   63,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    7,
    QMetaType::QByteArray,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void netclient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        netclient *_t = static_cast<netclient *>(_o);
        switch (_id) {
        case 0: _t->ExternalDataReady(); break;
        case 1: _t->ConnectionMade(); break;
        case 2: { bool _r = _t->isConnected();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 3: _t->attemptToConnect(); break;
        case 4: _t->SendToServer((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 5: { QByteArray _r = _t->ReceiveExternalData();
            if (_a[0]) *reinterpret_cast< QByteArray*>(_a[0]) = _r; }  break;
        case 6: _t->connectionMessage(); break;
        case 7: _t->ReadSocketData(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (netclient::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&netclient::ExternalDataReady)) {
                *result = 0;
            }
        }
        {
            typedef void (netclient::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&netclient::ConnectionMade)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject netclient::staticMetaObject = {
    { &QTcpSocket::staticMetaObject, qt_meta_stringdata_netclient.data,
      qt_meta_data_netclient,  qt_static_metacall, 0, 0}
};


const QMetaObject *netclient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *netclient::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_netclient.stringdata))
        return static_cast<void*>(const_cast< netclient*>(this));
    return QTcpSocket::qt_metacast(_clname);
}

int netclient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpSocket::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void netclient::ExternalDataReady()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void netclient::ConnectionMade()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
