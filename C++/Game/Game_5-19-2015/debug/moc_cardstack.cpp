/****************************************************************************
** Meta object code from reading C++ file 'cardstack.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../cardstack.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cardstack.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_cardstack_t {
    QByteArrayData data[18];
    char stringdata[164];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_cardstack_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_cardstack_t qt_meta_stringdata_cardstack = {
    {
QT_MOC_LITERAL(0, 0, 9),
QT_MOC_LITERAL(1, 10, 12),
QT_MOC_LITERAL(2, 23, 0),
QT_MOC_LITERAL(3, 24, 10),
QT_MOC_LITERAL(4, 35, 5),
QT_MOC_LITERAL(5, 41, 14),
QT_MOC_LITERAL(6, 56, 7),
QT_MOC_LITERAL(7, 64, 7),
QT_MOC_LITERAL(8, 72, 4),
QT_MOC_LITERAL(9, 77, 7),
QT_MOC_LITERAL(10, 85, 10),
QT_MOC_LITERAL(11, 96, 4),
QT_MOC_LITERAL(12, 101, 8),
QT_MOC_LITERAL(13, 110, 7),
QT_MOC_LITERAL(14, 118, 8),
QT_MOC_LITERAL(15, 127, 11),
QT_MOC_LITERAL(16, 139, 13),
QT_MOC_LITERAL(17, 153, 10)
    },
    "cardstack\0StackChanged\0\0cardstack*\0"
    "stack\0ToStandardDeck\0Shuffle\0AddCard\0"
    "card\0newCard\0ClearStack\0Look\0position\0"
    "TopCard\0TakeCard\0TakeTopCard\0NumberOfCards\0"
    "PrintCards"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_cardstack[] = {

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
       5,    0,   72,    2, 0x0a /* Public */,
       6,    0,   73,    2, 0x0a /* Public */,
       7,    1,   74,    2, 0x0a /* Public */,
      10,    0,   77,    2, 0x0a /* Public */,
      11,    1,   78,    2, 0x0a /* Public */,
      13,    0,   81,    2, 0x0a /* Public */,
      14,    1,   82,    2, 0x0a /* Public */,
      15,    0,   85,    2, 0x0a /* Public */,
      16,    0,   86,    2, 0x0a /* Public */,
      17,    0,   87,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,
    0x80000000 | 8, QMetaType::Int,   12,
    0x80000000 | 8,
    0x80000000 | 8, QMetaType::Int,   12,
    0x80000000 | 8,
    QMetaType::Int,
    QMetaType::Void,

       0        // eod
};

void cardstack::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        cardstack *_t = static_cast<cardstack *>(_o);
        switch (_id) {
        case 0: _t->StackChanged((*reinterpret_cast< cardstack*(*)>(_a[1]))); break;
        case 1: _t->ToStandardDeck(); break;
        case 2: _t->Shuffle(); break;
        case 3: _t->AddCard((*reinterpret_cast< const card(*)>(_a[1]))); break;
        case 4: _t->ClearStack(); break;
        case 5: { card _r = _t->Look((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< card*>(_a[0]) = _r; }  break;
        case 6: { card _r = _t->TopCard();
            if (_a[0]) *reinterpret_cast< card*>(_a[0]) = _r; }  break;
        case 7: { card _r = _t->TakeCard((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< card*>(_a[0]) = _r; }  break;
        case 8: { card _r = _t->TakeTopCard();
            if (_a[0]) *reinterpret_cast< card*>(_a[0]) = _r; }  break;
        case 9: { int _r = _t->NumberOfCards();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 10: _t->PrintCards(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
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
            typedef void (cardstack::*_t)(cardstack * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&cardstack::StackChanged)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject cardstack::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_cardstack.data,
      qt_meta_data_cardstack,  qt_static_metacall, 0, 0}
};


const QMetaObject *cardstack::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *cardstack::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_cardstack.stringdata))
        return static_cast<void*>(const_cast< cardstack*>(this));
    return QObject::qt_metacast(_clname);
}

int cardstack::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void cardstack::StackChanged(cardstack * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
