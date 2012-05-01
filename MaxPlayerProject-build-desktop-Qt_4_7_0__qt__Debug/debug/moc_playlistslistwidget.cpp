/****************************************************************************
** Meta object code from reading C++ file 'playlistslistwidget.h'
**
** Created: Tue 1. May 16:39:20 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MaxPlayerProject/playlistslistwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'playlistslistwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PlaylistsListWidget[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      21,   20,   20,   20, 0x05,

 // slots: signature, parameters, type, tag, flags
      45,   20,   20,   20, 0x0a,
      75,   20,   20,   20, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_PlaylistsListWidget[] = {
    "PlaylistsListWidget\0\0PlaylistChangedSignal()\0"
    "RemoveSelectedPlaylistsSlot()\0"
    "PlaylistButtonClickSlot()\0"
};

const QMetaObject PlaylistsListWidget::staticMetaObject = {
    { &QScrollArea::staticMetaObject, qt_meta_stringdata_PlaylistsListWidget,
      qt_meta_data_PlaylistsListWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PlaylistsListWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PlaylistsListWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PlaylistsListWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PlaylistsListWidget))
        return static_cast<void*>(const_cast< PlaylistsListWidget*>(this));
    return QScrollArea::qt_metacast(_clname);
}

int PlaylistsListWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QScrollArea::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: PlaylistChangedSignal(); break;
        case 1: RemoveSelectedPlaylistsSlot(); break;
        case 2: PlaylistButtonClickSlot(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void PlaylistsListWidget::PlaylistChangedSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
