/****************************************************************************
** Meta object code from reading C++ file 'guest.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../netGame/guest.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'guest.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_guest_t {
    QByteArrayData data[8];
    char stringdata[141];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_guest_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_guest_t qt_meta_stringdata_guest = {
    {
QT_MOC_LITERAL(0, 0, 5),
QT_MOC_LITERAL(1, 6, 17),
QT_MOC_LITERAL(2, 24, 0),
QT_MOC_LITERAL(3, 25, 20),
QT_MOC_LITERAL(4, 46, 28),
QT_MOC_LITERAL(5, 75, 26),
QT_MOC_LITERAL(6, 102, 13),
QT_MOC_LITERAL(7, 116, 24)
    },
    "guest\0initialLobbySetUp\0\0pbLobbyAcceptEnabler\0"
    "pbLobbyChangeUserNameEnabler\0"
    "processSelfUserNameRequest\0acceptClicked\0"
    "processReadyExternalData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_guest[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void guest::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        guest *_t = static_cast<guest *>(_o);
        switch (_id) {
        case 0: _t->initialLobbySetUp(); break;
        case 1: _t->pbLobbyAcceptEnabler(); break;
        case 2: _t->pbLobbyChangeUserNameEnabler(); break;
        case 3: _t->processSelfUserNameRequest(); break;
        case 4: _t->acceptClicked(); break;
        case 5: _t->processReadyExternalData(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject guest::staticMetaObject = {
    { &player::staticMetaObject, qt_meta_stringdata_guest.data,
      qt_meta_data_guest,  qt_static_metacall, 0, 0}
};


const QMetaObject *guest::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *guest::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_guest.stringdata))
        return static_cast<void*>(const_cast< guest*>(this));
    return player::qt_metacast(_clname);
}

int guest::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = player::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
