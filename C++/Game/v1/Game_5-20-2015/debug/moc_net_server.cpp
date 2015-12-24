/****************************************************************************
** Meta object code from reading C++ file 'net_server.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Communications/net_server.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'net_server.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_net_server_t {
    QByteArrayData data[21];
    char stringdata[271];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_net_server_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_net_server_t qt_meta_stringdata_net_server = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 17),
QT_MOC_LITERAL(2, 29, 0),
QT_MOC_LITERAL(3, 30, 15),
QT_MOC_LITERAL(4, 46, 7),
QT_MOC_LITERAL(5, 54, 12),
QT_MOC_LITERAL(6, 67, 11),
QT_MOC_LITERAL(7, 79, 14),
QT_MOC_LITERAL(8, 94, 12),
QT_MOC_LITERAL(9, 107, 11),
QT_MOC_LITERAL(10, 119, 13),
QT_MOC_LITERAL(11, 133, 16),
QT_MOC_LITERAL(12, 150, 10),
QT_MOC_LITERAL(13, 161, 10),
QT_MOC_LITERAL(14, 172, 12),
QT_MOC_LITERAL(15, 185, 9),
QT_MOC_LITERAL(16, 195, 19),
QT_MOC_LITERAL(17, 215, 11),
QT_MOC_LITERAL(18, 227, 12),
QT_MOC_LITERAL(19, 240, 15),
QT_MOC_LITERAL(20, 256, 14)
    },
    "net_server\0ExternalDataReady\0\0"
    "ClientNeedsData\0request\0AboutToClose\0"
    "StartServer\0CloseOffServer\0SendToClient\0"
    "private_msg\0client_number\0SendToAllClients\0"
    "public_msg\0SendToSelf\0internal_msg\0"
    "SendToAll\0ReceiveExternalData\0ClientCount\0"
    "AddTcpClient\0RemoveTcpClient\0"
    "ReadSocketData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_net_server[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x06 /* Public */,
       3,    1,   85,    2, 0x06 /* Public */,
       5,    0,   88,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   89,    2, 0x0a /* Public */,
       7,    0,   90,    2, 0x0a /* Public */,
       8,    2,   91,    2, 0x0a /* Public */,
      11,    1,   96,    2, 0x0a /* Public */,
      13,    1,   99,    2, 0x0a /* Public */,
      15,    1,  102,    2, 0x0a /* Public */,
      16,    0,  105,    2, 0x0a /* Public */,
      17,    0,  106,    2, 0x0a /* Public */,
      18,    0,  107,    2, 0x08 /* Private */,
      19,    0,  108,    2, 0x08 /* Private */,
      20,    0,  109,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QChar,    4,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray, QMetaType::Int,    9,   10,
    QMetaType::Void, QMetaType::QByteArray,   12,
    QMetaType::Void, QMetaType::QByteArray,   14,
    QMetaType::Void, QMetaType::QByteArray,   12,
    QMetaType::QByteArray,
    QMetaType::Int,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void net_server::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        net_server *_t = static_cast<net_server *>(_o);
        switch (_id) {
        case 0: _t->ExternalDataReady(); break;
        case 1: _t->ClientNeedsData((*reinterpret_cast< QChar(*)>(_a[1]))); break;
        case 2: _t->AboutToClose(); break;
        case 3: _t->StartServer(); break;
        case 4: _t->CloseOffServer(); break;
        case 5: _t->SendToClient((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->SendToAllClients((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 7: _t->SendToSelf((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 8: _t->SendToAll((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 9: { QByteArray _r = _t->ReceiveExternalData();
            if (_a[0]) *reinterpret_cast< QByteArray*>(_a[0]) = _r; }  break;
        case 10: { int _r = _t->ClientCount();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 11: _t->AddTcpClient(); break;
        case 12: _t->RemoveTcpClient(); break;
        case 13: _t->ReadSocketData(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (net_server::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&net_server::ExternalDataReady)) {
                *result = 0;
            }
        }
        {
            typedef void (net_server::*_t)(QChar );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&net_server::ClientNeedsData)) {
                *result = 1;
            }
        }
        {
            typedef void (net_server::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&net_server::AboutToClose)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject net_server::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_net_server.data,
      qt_meta_data_net_server,  qt_static_metacall, 0, 0}
};


const QMetaObject *net_server::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *net_server::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_net_server.stringdata))
        return static_cast<void*>(const_cast< net_server*>(this));
    return QWidget::qt_metacast(_clname);
}

int net_server::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void net_server::ExternalDataReady()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void net_server::ClientNeedsData(QChar _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void net_server::AboutToClose()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
