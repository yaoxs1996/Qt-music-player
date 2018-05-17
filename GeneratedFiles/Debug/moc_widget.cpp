/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Widget_t {
    QByteArrayData data[24];
    char stringdata0[272];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Widget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Widget_t qt_meta_stringdata_Widget = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Widget"
QT_MOC_LITERAL(1, 7, 10), // "timerEvent"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 12), // "QTimerEvent*"
QT_MOC_LITERAL(4, 32, 5), // "event"
QT_MOC_LITERAL(5, 38, 14), // "slot_playMusic"
QT_MOC_LITERAL(6, 53, 8), // "FilePath"
QT_MOC_LITERAL(7, 62, 16), // "slot_setPosition"
QT_MOC_LITERAL(8, 79, 5), // "value"
QT_MOC_LITERAL(9, 85, 20), // "slot_durationChanged"
QT_MOC_LITERAL(10, 106, 8), // "duration"
QT_MOC_LITERAL(11, 115, 20), // "slot_positionChanged"
QT_MOC_LITERAL(12, 136, 8), // "position"
QT_MOC_LITERAL(13, 145, 24), // "slot_player_stateChanged"
QT_MOC_LITERAL(14, 170, 19), // "QMediaPlayer::State"
QT_MOC_LITERAL(15, 190, 5), // "state"
QT_MOC_LITERAL(16, 196, 15), // "slot_updateList"
QT_MOC_LITERAL(17, 212, 9), // "slot_stop"
QT_MOC_LITERAL(18, 222, 9), // "playAudio"
QT_MOC_LITERAL(19, 232, 4), // "next"
QT_MOC_LITERAL(20, 237, 4), // "last"
QT_MOC_LITERAL(21, 242, 4), // "open"
QT_MOC_LITERAL(22, 247, 13), // "volumeChanged"
QT_MOC_LITERAL(23, 261, 10) // "createFile"

    },
    "Widget\0timerEvent\0\0QTimerEvent*\0event\0"
    "slot_playMusic\0FilePath\0slot_setPosition\0"
    "value\0slot_durationChanged\0duration\0"
    "slot_positionChanged\0position\0"
    "slot_player_stateChanged\0QMediaPlayer::State\0"
    "state\0slot_updateList\0slot_stop\0"
    "playAudio\0next\0last\0open\0volumeChanged\0"
    "createFile"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Widget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x09 /* Protected */,
       5,    1,   87,    2, 0x08 /* Private */,
       7,    1,   90,    2, 0x08 /* Private */,
       9,    1,   93,    2, 0x08 /* Private */,
      11,    1,   96,    2, 0x08 /* Private */,
      13,    1,   99,    2, 0x08 /* Private */,
      16,    1,  102,    2, 0x08 /* Private */,
      17,    0,  105,    2, 0x08 /* Private */,
      18,    0,  106,    2, 0x08 /* Private */,
      19,    0,  107,    2, 0x08 /* Private */,
      20,    0,  108,    2, 0x08 /* Private */,
      21,    0,  109,    2, 0x08 /* Private */,
      22,    0,  110,    2, 0x08 /* Private */,
      23,    0,  111,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::LongLong,   10,
    QMetaType::Void, QMetaType::LongLong,   12,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Widget *_t = static_cast<Widget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->timerEvent((*reinterpret_cast< QTimerEvent*(*)>(_a[1]))); break;
        case 1: _t->slot_playMusic((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->slot_setPosition((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->slot_durationChanged((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 4: _t->slot_positionChanged((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 5: _t->slot_player_stateChanged((*reinterpret_cast< QMediaPlayer::State(*)>(_a[1]))); break;
        case 6: _t->slot_updateList((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->slot_stop(); break;
        case 8: _t->playAudio(); break;
        case 9: _t->next(); break;
        case 10: _t->last(); break;
        case 11: _t->open(); break;
        case 12: _t->volumeChanged(); break;
        case 13: _t->createFile(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMediaPlayer::State >(); break;
            }
            break;
        }
    }
}

const QMetaObject Widget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Widget.data,
      qt_meta_data_Widget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Widget.stringdata0))
        return static_cast<void*>(const_cast< Widget*>(this));
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
