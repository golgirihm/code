/****************************************************************************
** Meta object code from reading C++ file 'mainscreen.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Game_5-20-2015/Forms_Code/mainscreen.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainscreen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_mainscreen_t {
    QByteArrayData data[13];
    char stringdata[141];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_mainscreen_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_mainscreen_t qt_meta_stringdata_mainscreen = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 16),
QT_MOC_LITERAL(2, 28, 0),
QT_MOC_LITERAL(3, 29, 7),
QT_MOC_LITERAL(4, 37, 10),
QT_MOC_LITERAL(5, 48, 4),
QT_MOC_LITERAL(6, 53, 16),
QT_MOC_LITERAL(7, 70, 14),
QT_MOC_LITERAL(8, 85, 12),
QT_MOC_LITERAL(9, 98, 12),
QT_MOC_LITERAL(10, 111, 13),
QT_MOC_LITERAL(11, 125, 4),
QT_MOC_LITERAL(12, 130, 10)
    },
    "mainscreen\0ChatMessageReady\0\0SetHand\0"
    "cardstack*\0Hand\0SetPlayersStatus\0"
    "PlayersDisplay\0SetDeckCount\0NumDeckCards\0"
    "SetPlayedCard\0card\0FaceUpCard"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_mainscreen[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   40,    2, 0x0a /* Public */,
       6,    1,   43,    2, 0x0a /* Public */,
       8,    1,   46,    2, 0x0a /* Public */,
      10,    1,   49,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, 0x80000000 | 11,   12,

       0        // eod
};

void mainscreen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        mainscreen *_t = static_cast<mainscreen *>(_o);
        switch (_id) {
        case 0: _t->ChatMessageReady(); break;
        case 1: _t->SetHand((*reinterpret_cast< cardstack*(*)>(_a[1]))); break;
        case 2: _t->SetPlayersStatus((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->SetDeckCount((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->SetPlayedCard((*reinterpret_cast< card(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< cardstack* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (mainscreen::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&mainscreen::ChatMessageReady)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject mainscreen::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_mainscreen.data,
      qt_meta_data_mainscreen,  qt_static_metacall, 0, 0}
};


const QMetaObject *mainscreen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *mainscreen::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_mainscreen.stringdata))
        return static_cast<void*>(const_cast< mainscreen*>(this));
    return QDialog::qt_metacast(_clname);
}

int mainscreen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void mainscreen::ChatMessageReady()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
