/****************************************************************************
** Meta object code from reading C++ file 'cardstack.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Game_5-20-2015/cardstack.h"
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
    QByteArrayData data[23];
    char stringdata[223];
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
QT_MOC_LITERAL(10, 85, 7),
QT_MOC_LITERAL(11, 93, 7),
QT_MOC_LITERAL(12, 101, 10),
QT_MOC_LITERAL(13, 112, 4),
QT_MOC_LITERAL(14, 117, 8),
QT_MOC_LITERAL(15, 126, 7),
QT_MOC_LITERAL(16, 134, 10),
QT_MOC_LITERAL(17, 145, 8),
QT_MOC_LITERAL(18, 154, 11),
QT_MOC_LITERAL(19, 166, 14),
QT_MOC_LITERAL(20, 181, 13),
QT_MOC_LITERAL(21, 195, 16),
QT_MOC_LITERAL(22, 212, 10)
    },
    "cardstack\0StackChanged\0\0cardstack*\0"
    "stack\0ToStandardDeck\0Shuffle\0AddCard\0"
    "card\0newCard\0NewRank\0NewSuit\0ClearStack\0"
    "Look\0position\0TopCard\0BottomCard\0"
    "TakeCard\0TakeTopCard\0TakeBottomCard\0"
    "NumberOfCards\0CompressedString\0"
    "PrintCards"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_cardstack[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   92,    2, 0x0a /* Public */,
       6,    0,   93,    2, 0x0a /* Public */,
       7,    1,   94,    2, 0x0a /* Public */,
       7,    2,   97,    2, 0x0a /* Public */,
      12,    0,  102,    2, 0x0a /* Public */,
      13,    1,  103,    2, 0x0a /* Public */,
      15,    0,  106,    2, 0x0a /* Public */,
      16,    0,  107,    2, 0x0a /* Public */,
      17,    1,  108,    2, 0x0a /* Public */,
      18,    0,  111,    2, 0x0a /* Public */,
      19,    0,  112,    2, 0x0a /* Public */,
      20,    0,  113,    2, 0x0a /* Public */,
      21,    0,  114,    2, 0x0a /* Public */,
      22,    0,  115,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::QChar, QMetaType::QChar,   10,   11,
    QMetaType::Void,
    0x80000000 | 8, QMetaType::Int,   14,
    0x80000000 | 8,
    0x80000000 | 8,
    0x80000000 | 8, QMetaType::Int,   14,
    0x80000000 | 8,
    0x80000000 | 8,
    QMetaType::Int,
    QMetaType::QString,
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
        case 4: _t->AddCard((*reinterpret_cast< const QChar(*)>(_a[1])),(*reinterpret_cast< const QChar(*)>(_a[2]))); break;
        case 5: _t->ClearStack(); break;
        case 6: { card _r = _t->Look((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< card*>(_a[0]) = _r; }  break;
        case 7: { card _r = _t->TopCard();
            if (_a[0]) *reinterpret_cast< card*>(_a[0]) = _r; }  break;
        case 8: { card _r = _t->BottomCard();
            if (_a[0]) *reinterpret_cast< card*>(_a[0]) = _r; }  break;
        case 9: { card _r = _t->TakeCard((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< card*>(_a[0]) = _r; }  break;
        case 10: { card _r = _t->TakeTopCard();
            if (_a[0]) *reinterpret_cast< card*>(_a[0]) = _r; }  break;
        case 11: { card _r = _t->TakeBottomCard();
            if (_a[0]) *reinterpret_cast< card*>(_a[0]) = _r; }  break;
        case 12: { int _r = _t->NumberOfCards();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 13: { QString _r = _t->CompressedString();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 14: _t->PrintCards(); break;
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
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
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
