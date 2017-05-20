/****************************************************************************
** Meta object code from reading C++ file 'playlistqt.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../playlistqt.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'playlistqt.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_PlaylistQt_t {
    QByteArrayData data[16];
    char stringdata0[224];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PlaylistQt_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PlaylistQt_t qt_meta_stringdata_PlaylistQt = {
    {
QT_MOC_LITERAL(0, 0, 10), // "PlaylistQt"
QT_MOC_LITERAL(1, 11, 15), // "listItemChanged"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 14), // "addNewTutorial"
QT_MOC_LITERAL(4, 43, 14), // "updateTutorial"
QT_MOC_LITERAL(5, 58, 14), // "deleteTutorial"
QT_MOC_LITERAL(6, 73, 22), // "deletePlayListTutorial"
QT_MOC_LITERAL(7, 96, 19), // "filterRepoTutorials"
QT_MOC_LITERAL(8, 116, 22), // "moveTutorialToPlaylist"
QT_MOC_LITERAL(9, 139, 16), // "moveAllTutorials"
QT_MOC_LITERAL(10, 156, 12), // "playTutorial"
QT_MOC_LITERAL(11, 169, 8), // "tokenize"
QT_MOC_LITERAL(12, 178, 24), // "std::vector<std::string>"
QT_MOC_LITERAL(13, 203, 6), // "string"
QT_MOC_LITERAL(14, 210, 3), // "str"
QT_MOC_LITERAL(15, 214, 9) // "delimiter"

    },
    "PlaylistQt\0listItemChanged\0\0addNewTutorial\0"
    "updateTutorial\0deleteTutorial\0"
    "deletePlayListTutorial\0filterRepoTutorials\0"
    "moveTutorialToPlaylist\0moveAllTutorials\0"
    "playTutorial\0tokenize\0std::vector<std::string>\0"
    "string\0str\0delimiter"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PlaylistQt[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08 /* Private */,
       3,    0,   65,    2, 0x08 /* Private */,
       4,    0,   66,    2, 0x08 /* Private */,
       5,    0,   67,    2, 0x08 /* Private */,
       6,    0,   68,    2, 0x08 /* Private */,
       7,    0,   69,    2, 0x08 /* Private */,
       8,    0,   70,    2, 0x08 /* Private */,
       9,    0,   71,    2, 0x08 /* Private */,
      10,    0,   72,    2, 0x08 /* Private */,
      11,    2,   73,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    0x80000000 | 12, 0x80000000 | 13, QMetaType::Char,   14,   15,

       0        // eod
};

void PlaylistQt::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PlaylistQt *_t = static_cast<PlaylistQt *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->listItemChanged(); break;
        case 1: _t->addNewTutorial(); break;
        case 2: _t->updateTutorial(); break;
        case 3: _t->deleteTutorial(); break;
        case 4: _t->deletePlayListTutorial(); break;
        case 5: _t->filterRepoTutorials(); break;
        case 6: _t->moveTutorialToPlaylist(); break;
        case 7: _t->moveAllTutorials(); break;
        case 8: _t->playTutorial(); break;
        case 9: { std::vector<std::string> _r = _t->tokenize((*reinterpret_cast< const string(*)>(_a[1])),(*reinterpret_cast< char(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< std::vector<std::string>*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObject PlaylistQt::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PlaylistQt.data,
      qt_meta_data_PlaylistQt,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *PlaylistQt::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PlaylistQt::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_PlaylistQt.stringdata0))
        return static_cast<void*>(const_cast< PlaylistQt*>(this));
    return QWidget::qt_metacast(_clname);
}

int PlaylistQt::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
