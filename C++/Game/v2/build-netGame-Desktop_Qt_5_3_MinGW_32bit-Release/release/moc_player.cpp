/****************************************************************************
** Meta object code from reading C++ file 'player.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../netGame/player.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'player.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_player_t {
    QByteArrayData data[11];
    char stringdata[178];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_player_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_player_t qt_meta_stringdata_player = {
    {
QT_MOC_LITERAL(0, 0, 6),
QT_MOC_LITERAL(1, 7, 15),
QT_MOC_LITERAL(2, 23, 0),
QT_MOC_LITERAL(3, 24, 17),
QT_MOC_LITERAL(4, 42, 20),
QT_MOC_LITERAL(5, 63, 28),
QT_MOC_LITERAL(6, 92, 26),
QT_MOC_LITERAL(7, 119, 13),
QT_MOC_LITERAL(8, 133, 24),
QT_MOC_LITERAL(9, 158, 11),
QT_MOC_LITERAL(10, 170, 7)
    },
    "player\0userNameChanged\0\0initialLobbySetUp\0"
    "pbLobbyAcceptEnabler\0pbLobbyChangeUserNameEnabler\0"
    "processSelfUserNameRequest\0acceptClicked\0"
    "processReadyExternalData\0setUserName\0"
    "newName"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_player[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   55,    2, 0x09 /* Protected */,
       4,    0,   56,    2, 0x09 /* Protected */,
       5,    0,   57,    2, 0x09 /* Protected */,
       6,    0,   58,    2, 0x09 /* Protected */,
       7,    0,   59,    2, 0x09 /* Protected */,
       8,    0,   60,    2, 0x09 /* Protected */,
       9,    1,   61,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   10,

       0        // eod
};

void player::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        player *_t = static_cast<player *>(_o);
        switch (_id) {
        case 0: _t->userNameChanged(); break;
        case 1: _t->initialLobbySetUp(); break;
        case 2: _t->pbLobbyAcceptEnabler(); break;
        case 3: _t->pbLobbyChangeUserNameEnabler(); break;
        case 4: _t->processSelfUserNameRequest(); break;
        case 5: _t->acceptClicked(); break;
        case 6: _t->processReadyExternalData(); break;
        case 7: _t->setUserName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (player::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&player::userNameChanged)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject player::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_player.data,
      qt_meta_data_player,  qt_static_metacall, 0, 0}
};


const QMetaObject *player::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *player::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_player.stringdata))
        return static_cast<void*>(const_cast< player*>(this));
    return QObject::qt_metacast(_clname);
}

int player::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void player::userNameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
