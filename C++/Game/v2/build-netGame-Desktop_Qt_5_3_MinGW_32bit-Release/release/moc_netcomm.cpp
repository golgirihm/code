/****************************************************************************
** Meta object code from reading C++ file 'netcomm.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../netGame/netcomm.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'netcomm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_netComm_t {
    QByteArrayData data[9];
    char stringdata[119];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_netComm_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_netComm_t qt_meta_stringdata_netComm = {
    {
QT_MOC_LITERAL(0, 0, 7),
QT_MOC_LITERAL(1, 8, 17),
QT_MOC_LITERAL(2, 26, 0),
QT_MOC_LITERAL(3, 27, 12),
QT_MOC_LITERAL(4, 40, 19),
QT_MOC_LITERAL(5, 60, 17),
QT_MOC_LITERAL(6, 78, 18),
QT_MOC_LITERAL(7, 97, 6),
QT_MOC_LITERAL(8, 104, 14)
    },
    "netComm\0externalDataReady\0\0aboutToClose\0"
    "receiveExternalData\0connectionMessage\0"
    "threadedTcpSocket*\0socket\0readSocketData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_netComm[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   46,    2, 0x0a /* Public */,
       5,    1,   47,    2, 0x09 /* Protected */,
       5,    0,   50,    2, 0x29 /* Protected | MethodCloned */,
       8,    0,   51,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::QByteArray,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void netComm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        netComm *_t = static_cast<netComm *>(_o);
        switch (_id) {
        case 0: _t->externalDataReady(); break;
        case 1: _t->aboutToClose(); break;
        case 2: { QByteArray _r = _t->receiveExternalData();
            if (_a[0]) *reinterpret_cast< QByteArray*>(_a[0]) = _r; }  break;
        case 3: _t->connectionMessage((*reinterpret_cast< threadedTcpSocket*(*)>(_a[1]))); break;
        case 4: _t->connectionMessage(); break;
        case 5: _t->readSocketData(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< threadedTcpSocket* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (netComm::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&netComm::externalDataReady)) {
                *result = 0;
            }
        }
        {
            typedef void (netComm::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&netComm::aboutToClose)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject netComm::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_netComm.data,
      qt_meta_data_netComm,  qt_static_metacall, 0, 0}
};


const QMetaObject *netComm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *netComm::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_netComm.stringdata))
        return static_cast<void*>(const_cast< netComm*>(this));
    return QObject::qt_metacast(_clname);
}

int netComm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void netComm::externalDataReady()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void netComm::aboutToClose()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
