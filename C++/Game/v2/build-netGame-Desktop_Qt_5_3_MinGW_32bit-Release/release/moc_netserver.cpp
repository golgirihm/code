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
    char stringdata[204];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_netserver_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_netserver_t qt_meta_stringdata_netserver = {
    {
QT_MOC_LITERAL(0, 0, 9),
QT_MOC_LITERAL(1, 10, 11),
QT_MOC_LITERAL(2, 22, 0),
QT_MOC_LITERAL(3, 23, 11),
QT_MOC_LITERAL(4, 35, 11),
QT_MOC_LITERAL(5, 47, 14),
QT_MOC_LITERAL(6, 62, 11),
QT_MOC_LITERAL(7, 74, 12),
QT_MOC_LITERAL(8, 87, 11),
QT_MOC_LITERAL(9, 99, 13),
QT_MOC_LITERAL(10, 113, 16),
QT_MOC_LITERAL(11, 130, 10),
QT_MOC_LITERAL(12, 141, 10),
QT_MOC_LITERAL(13, 152, 12),
QT_MOC_LITERAL(14, 165, 9),
QT_MOC_LITERAL(15, 175, 12),
QT_MOC_LITERAL(16, 188, 15)
    },
    "netserver\0clientAdded\0\0StartServer\0"
    "isListening\0CloseOffServer\0ClientCount\0"
    "SendToClient\0private_msg\0client_number\0"
    "SendToAllClients\0public_msg\0SendToSelf\0"
    "internal_msg\0SendToAll\0AddTcpClient\0"
    "RemoveTcpClient"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_netserver[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   72,    2, 0x0a /* Public */,
       4,    0,   73,    2, 0x0a /* Public */,
       5,    0,   74,    2, 0x0a /* Public */,
       6,    0,   75,    2, 0x0a /* Public */,
       7,    2,   76,    2, 0x0a /* Public */,
      10,    1,   81,    2, 0x0a /* Public */,
      12,    1,   84,    2, 0x0a /* Public */,
      14,    1,   87,    2, 0x0a /* Public */,
      15,    0,   90,    2, 0x08 /* Private */,
      16,    0,   91,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::UChar,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Int,
    QMetaType::Void, QMetaType::QByteArray, QMetaType::Int,    8,    9,
    QMetaType::Void, QMetaType::QByteArray,   11,
    QMetaType::Void, QMetaType::QByteArray,   13,
    QMetaType::Void, QMetaType::QByteArray,   11,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void netserver::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        netserver *_t = static_cast<netserver *>(_o);
        switch (_id) {
        case 0: _t->clientAdded((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 1: _t->StartServer(); break;
        case 2: { bool _r = _t->isListening();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 3: _t->CloseOffServer(); break;
        case 4: { int _r = _t->ClientCount();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 5: _t->SendToClient((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->SendToAllClients((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 7: _t->SendToSelf((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 8: _t->SendToAll((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 9: _t->AddTcpClient(); break;
        case 10: _t->RemoveTcpClient(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (netserver::*_t)(quint8 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&netserver::clientAdded)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject netserver::staticMetaObject = {
    { &netComm::staticMetaObject, qt_meta_stringdata_netserver.data,
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
    return netComm::qt_metacast(_clname);
}

int netserver::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = netComm::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void netserver::clientAdded(quint8 _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
