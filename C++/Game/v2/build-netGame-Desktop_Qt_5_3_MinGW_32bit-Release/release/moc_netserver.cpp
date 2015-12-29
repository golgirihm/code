/****************************************************************************
** Meta object code from reading C++ file 'netserver.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../netGame/netserver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'netserver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_netserver_t {
    QByteArrayData data[17];
    char stringdata[222];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_netserver_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_netserver_t qt_meta_stringdata_netserver = {
    {
QT_MOC_LITERAL(0, 0, 9),
QT_MOC_LITERAL(1, 10, 17),
QT_MOC_LITERAL(2, 28, 0),
QT_MOC_LITERAL(3, 29, 12),
QT_MOC_LITERAL(4, 42, 11),
QT_MOC_LITERAL(5, 54, 14),
QT_MOC_LITERAL(6, 69, 12),
QT_MOC_LITERAL(7, 82, 11),
QT_MOC_LITERAL(8, 94, 13),
QT_MOC_LITERAL(9, 108, 16),
QT_MOC_LITERAL(10, 125, 10),
QT_MOC_LITERAL(11, 136, 9),
QT_MOC_LITERAL(12, 146, 19),
QT_MOC_LITERAL(13, 166, 11),
QT_MOC_LITERAL(14, 178, 12),
QT_MOC_LITERAL(15, 191, 15),
QT_MOC_LITERAL(16, 207, 14)
    },
    "netserver\0ExternalDataReady\0\0AboutToClose\0"
    "StartServer\0CloseOffServer\0SendToClient\0"
    "private_msg\0client_number\0SendToAllClients\0"
    "public_msg\0SendToAll\0ReceiveExternalData\0"
    "ClientCount\0AddTcpClient\0RemoveTcpClient\0"
    "ReadSocketData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_netserver[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x06 /* Public */,
       3,    0,   75,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   76,    2, 0x0a /* Public */,
       5,    0,   77,    2, 0x0a /* Public */,
       6,    2,   78,    2, 0x0a /* Public */,
       9,    1,   83,    2, 0x0a /* Public */,
      11,    1,   86,    2, 0x0a /* Public */,
      12,    0,   89,    2, 0x0a /* Public */,
      13,    0,   90,    2, 0x0a /* Public */,
      14,    0,   91,    2, 0x08 /* Private */,
      15,    0,   92,    2, 0x08 /* Private */,
      16,    0,   93,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray, QMetaType::Int,    7,    8,
    QMetaType::Void, QMetaType::QByteArray,   10,
    QMetaType::Void, QMetaType::QByteArray,   10,
    QMetaType::QByteArray,
    QMetaType::Int,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void netserver::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        netserver *_t = static_cast<netserver *>(_o);
        switch (_id) {
        case 0: _t->ExternalDataReady(); break;
        case 1: _t->AboutToClose(); break;
        case 2: _t->StartServer(); break;
        case 3: _t->CloseOffServer(); break;
        case 4: _t->SendToClient((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->SendToAllClients((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 6: _t->SendToAll((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 7: { QByteArray _r = _t->ReceiveExternalData();
            if (_a[0]) *reinterpret_cast< QByteArray*>(_a[0]) = _r; }  break;
        case 8: { int _r = _t->ClientCount();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 9: _t->AddTcpClient(); break;
        case 10: _t->RemoveTcpClient(); break;
        case 11: _t->ReadSocketData(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (netserver::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&netserver::ExternalDataReady)) {
                *result = 0;
            }
        }
        {
            typedef void (netserver::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&netserver::AboutToClose)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject netserver::staticMetaObject = {
    { &QTcpServer::staticMetaObject, qt_meta_stringdata_netserver.data,
      qt_meta_data_netserver,  qt_static_metacall, 0, 0}
};


const QMetaObject *netserver::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *netserver::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_netserver.stringdata))
        return static_cast<void*>(const_cast< netserver*>(this));
    return QTcpServer::qt_metacast(_clname);
}

int netserver::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpServer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void netserver::ExternalDataReady()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void netserver::AboutToClose()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
