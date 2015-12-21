/****************************************************************************
** Meta object code from reading C++ file 'net_client.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Game_5-20-2015/Communications/net_client.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'net_client.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_net_client_t {
    QByteArrayData data[22];
    char stringdata[252];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_net_client_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_net_client_t qt_meta_stringdata_net_client = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 14),
QT_MOC_LITERAL(2, 26, 0),
QT_MOC_LITERAL(3, 27, 17),
QT_MOC_LITERAL(4, 45, 12),
QT_MOC_LITERAL(5, 58, 9),
QT_MOC_LITERAL(6, 68, 12),
QT_MOC_LITERAL(7, 81, 11),
QT_MOC_LITERAL(8, 93, 11),
QT_MOC_LITERAL(9, 105, 7),
QT_MOC_LITERAL(10, 113, 9),
QT_MOC_LITERAL(11, 123, 16),
QT_MOC_LITERAL(12, 140, 11),
QT_MOC_LITERAL(13, 152, 7),
QT_MOC_LITERAL(14, 160, 7),
QT_MOC_LITERAL(15, 168, 9),
QT_MOC_LITERAL(16, 178, 7),
QT_MOC_LITERAL(17, 186, 12),
QT_MOC_LITERAL(18, 199, 19),
QT_MOC_LITERAL(19, 219, 14),
QT_MOC_LITERAL(20, 234, 12),
QT_MOC_LITERAL(21, 247, 4)
    },
    "net_client\0ConnectionMade\0\0ExternalDataReady\0"
    "AboutToClose\0getHostIP\0QHostAddress\0"
    "getHostPort\0setHostInfo\0host_IP\0"
    "host_port\0attemptToConnect\0isConnected\0"
    "Request\0request\0SendToAll\0message\0"
    "SendToServer\0ReceiveExternalData\0"
    "ReadSocketData\0SendToSocket\0data"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_net_client[] = {

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
       3,    0,   85,    2, 0x06 /* Public */,
       4,    0,   86,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   87,    2, 0x0a /* Public */,
       7,    0,   88,    2, 0x0a /* Public */,
       8,    2,   89,    2, 0x0a /* Public */,
      11,    0,   94,    2, 0x0a /* Public */,
      12,    0,   95,    2, 0x0a /* Public */,
      13,    1,   96,    2, 0x0a /* Public */,
      15,    1,   99,    2, 0x0a /* Public */,
      17,    1,  102,    2, 0x0a /* Public */,
      18,    0,  105,    2, 0x0a /* Public */,
      19,    0,  106,    2, 0x08 /* Private */,
      20,    1,  107,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    0x80000000 | 6,
    QMetaType::UShort,
    QMetaType::Void, 0x80000000 | 6, QMetaType::UShort,    9,   10,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Char,   14,
    QMetaType::Void, QMetaType::QByteArray,   16,
    QMetaType::Void, QMetaType::QByteArray,   16,
    QMetaType::QByteArray,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,   21,

       0        // eod
};

void net_client::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        net_client *_t = static_cast<net_client *>(_o);
        switch (_id) {
        case 0: _t->ConnectionMade(); break;
        case 1: _t->ExternalDataReady(); break;
        case 2: _t->AboutToClose(); break;
        case 3: { QHostAddress _r = _t->getHostIP();
            if (_a[0]) *reinterpret_cast< QHostAddress*>(_a[0]) = _r; }  break;
        case 4: { quint16 _r = _t->getHostPort();
            if (_a[0]) *reinterpret_cast< quint16*>(_a[0]) = _r; }  break;
        case 5: _t->setHostInfo((*reinterpret_cast< const QHostAddress(*)>(_a[1])),(*reinterpret_cast< const quint16(*)>(_a[2]))); break;
        case 6: _t->attemptToConnect(); break;
        case 7: { bool _r = _t->isConnected();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 8: _t->Request((*reinterpret_cast< char(*)>(_a[1]))); break;
        case 9: _t->SendToAll((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 10: _t->SendToServer((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 11: { QByteArray _r = _t->ReceiveExternalData();
            if (_a[0]) *reinterpret_cast< QByteArray*>(_a[0]) = _r; }  break;
        case 12: _t->ReadSocketData(); break;
        case 13: _t->SendToSocket((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (net_client::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&net_client::ConnectionMade)) {
                *result = 0;
            }
        }
        {
            typedef void (net_client::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&net_client::ExternalDataReady)) {
                *result = 1;
            }
        }
        {
            typedef void (net_client::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&net_client::AboutToClose)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject net_client::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_net_client.data,
      qt_meta_data_net_client,  qt_static_metacall, 0, 0}
};


const QMetaObject *net_client::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *net_client::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_net_client.stringdata))
        return static_cast<void*>(const_cast< net_client*>(this));
    return QWidget::qt_metacast(_clname);
}

int net_client::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void net_client::ConnectionMade()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void net_client::ExternalDataReady()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void net_client::AboutToClose()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
