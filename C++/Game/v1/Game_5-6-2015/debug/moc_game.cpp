/****************************************************************************
** Meta object code from reading C++ file 'game.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../game.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'game.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_game_t {
    QByteArrayData data[17];
    char stringdata[275];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_game_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_game_t qt_meta_stringdata_game = {
    {
QT_MOC_LITERAL(0, 0, 4),
QT_MOC_LITERAL(1, 5, 35),
QT_MOC_LITERAL(2, 41, 0),
QT_MOC_LITERAL(3, 42, 16),
QT_MOC_LITERAL(4, 59, 13),
QT_MOC_LITERAL(5, 73, 16),
QT_MOC_LITERAL(6, 90, 14),
QT_MOC_LITERAL(7, 105, 12),
QT_MOC_LITERAL(8, 118, 10),
QT_MOC_LITERAL(9, 129, 28),
QT_MOC_LITERAL(10, 158, 4),
QT_MOC_LITERAL(11, 163, 19),
QT_MOC_LITERAL(12, 183, 15),
QT_MOC_LITERAL(13, 199, 16),
QT_MOC_LITERAL(14, 216, 12),
QT_MOC_LITERAL(15, 229, 16),
QT_MOC_LITERAL(16, 246, 28)
    },
    "game\0process_opening_screen_button_click\0"
    "\0QAbstractButton*\0ClickedButton\0"
    "lobby_pb_handler\0SendToChatroom\0"
    "server_ready\0start_game\0"
    "server_process_external_data\0deal\0"
    "UpdatePlayersStatus\0UpdateDeckCount\0"
    "UpdatePlayedCard\0client_ready\0"
    "client_connected\0client_process_external_data"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_game[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x08 /* Private */,
       5,    0,   82,    2, 0x08 /* Private */,
       6,    0,   83,    2, 0x08 /* Private */,
       7,    0,   84,    2, 0x08 /* Private */,
       8,    0,   85,    2, 0x08 /* Private */,
       9,    0,   86,    2, 0x08 /* Private */,
      10,    0,   87,    2, 0x08 /* Private */,
      11,    0,   88,    2, 0x08 /* Private */,
      12,    0,   89,    2, 0x08 /* Private */,
      13,    0,   90,    2, 0x08 /* Private */,
      14,    0,   91,    2, 0x08 /* Private */,
      15,    0,   92,    2, 0x08 /* Private */,
      16,    0,   93,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void game::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        game *_t = static_cast<game *>(_o);
        switch (_id) {
        case 0: _t->process_opening_screen_button_click((*reinterpret_cast< QAbstractButton*(*)>(_a[1]))); break;
        case 1: _t->lobby_pb_handler(); break;
        case 2: _t->SendToChatroom(); break;
        case 3: _t->server_ready(); break;
        case 4: _t->start_game(); break;
        case 5: _t->server_process_external_data(); break;
        case 6: _t->deal(); break;
        case 7: _t->UpdatePlayersStatus(); break;
        case 8: _t->UpdateDeckCount(); break;
        case 9: _t->UpdatePlayedCard(); break;
        case 10: _t->client_ready(); break;
        case 11: _t->client_connected(); break;
        case 12: _t->client_process_external_data(); break;
        default: ;
        }
    }
}

const QMetaObject game::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_game.data,
      qt_meta_data_game,  qt_static_metacall, 0, 0}
};


const QMetaObject *game::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *game::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_game.stringdata))
        return static_cast<void*>(const_cast< game*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int game::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
