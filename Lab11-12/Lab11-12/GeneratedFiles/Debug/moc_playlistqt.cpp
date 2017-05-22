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
    QByteArrayData data[22];
    char stringdata0[337];
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
QT_MOC_LITERAL(3, 28, 23), // "listItemChangedPlayList"
QT_MOC_LITERAL(4, 52, 14), // "addNewTutorial"
QT_MOC_LITERAL(5, 67, 14), // "updateTutorial"
QT_MOC_LITERAL(6, 82, 14), // "deleteTutorial"
QT_MOC_LITERAL(7, 97, 22), // "deletePlayListTutorial"
QT_MOC_LITERAL(8, 120, 19), // "filterRepoTutorials"
QT_MOC_LITERAL(9, 140, 22), // "moveTutorialToPlaylist"
QT_MOC_LITERAL(10, 163, 16), // "moveAllTutorials"
QT_MOC_LITERAL(11, 180, 12), // "playTutorial"
QT_MOC_LITERAL(12, 193, 19), // "sortedButtonHandler"
QT_MOC_LITERAL(13, 213, 7), // "checked"
QT_MOC_LITERAL(14, 221, 21), // "shuffledButtonHandler"
QT_MOC_LITERAL(15, 243, 20), // "CSVOpenButtonHandler"
QT_MOC_LITERAL(16, 264, 17), // "likeButtonHandler"
QT_MOC_LITERAL(17, 282, 8), // "tokenize"
QT_MOC_LITERAL(18, 291, 24), // "std::vector<std::string>"
QT_MOC_LITERAL(19, 316, 6), // "string"
QT_MOC_LITERAL(20, 323, 3), // "str"
QT_MOC_LITERAL(21, 327, 9) // "delimiter"

    },
    "PlaylistQt\0listItemChanged\0\0"
    "listItemChangedPlayList\0addNewTutorial\0"
    "updateTutorial\0deleteTutorial\0"
    "deletePlayListTutorial\0filterRepoTutorials\0"
    "moveTutorialToPlaylist\0moveAllTutorials\0"
    "playTutorial\0sortedButtonHandler\0"
    "checked\0shuffledButtonHandler\0"
    "CSVOpenButtonHandler\0likeButtonHandler\0"
    "tokenize\0std::vector<std::string>\0"
    "string\0str\0delimiter"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PlaylistQt[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x08 /* Private */,
       3,    0,   90,    2, 0x08 /* Private */,
       4,    0,   91,    2, 0x08 /* Private */,
       5,    0,   92,    2, 0x08 /* Private */,
       6,    0,   93,    2, 0x08 /* Private */,
       7,    0,   94,    2, 0x08 /* Private */,
       8,    0,   95,    2, 0x08 /* Private */,
       9,    0,   96,    2, 0x08 /* Private */,
      10,    0,   97,    2, 0x08 /* Private */,
      11,    0,   98,    2, 0x08 /* Private */,
      12,    1,   99,    2, 0x08 /* Private */,
      14,    1,  102,    2, 0x08 /* Private */,
      15,    0,  105,    2, 0x08 /* Private */,
      16,    0,  106,    2, 0x08 /* Private */,
      17,    2,  107,    2, 0x08 /* Private */,

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
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   13,
    QMetaType::Void, QMetaType::Bool,   13,
    QMetaType::Void,
    QMetaType::Void,
    0x80000000 | 18, 0x80000000 | 19, QMetaType::Char,   20,   21,

       0        // eod
};

void PlaylistQt::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PlaylistQt *_t = static_cast<PlaylistQt *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->listItemChanged(); break;
        case 1: _t->listItemChangedPlayList(); break;
        case 2: _t->addNewTutorial(); break;
        case 3: _t->updateTutorial(); break;
        case 4: _t->deleteTutorial(); break;
        case 5: _t->deletePlayListTutorial(); break;
        case 6: _t->filterRepoTutorials(); break;
        case 7: _t->moveTutorialToPlaylist(); break;
        case 8: _t->moveAllTutorials(); break;
        case 9: _t->playTutorial(); break;
        case 10: _t->sortedButtonHandler((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->shuffledButtonHandler((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->CSVOpenButtonHandler(); break;
        case 13: _t->likeButtonHandler(); break;
        case 14: { std::vector<std::string> _r = _t->tokenize((*reinterpret_cast< const string(*)>(_a[1])),(*reinterpret_cast< char(*)>(_a[2])));
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
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
