/****************************************************************************
** Meta object code from reading C++ file 'songslistwidget.h'
**
** Created: Sat 28. Apr 16:05:52 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MaxPlayerProject/songslistwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'songslistwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SongsListWidget[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x05,
      42,   16,   16,   16, 0x05,

 // slots: signature, parameters, type, tag, flags
      66,   16,   16,   16, 0x0a,
      89,   16,   16,   16, 0x0a,
     116,   16,   16,   16, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_SongsListWidget[] = {
    "SongsListWidget\0\0TrackButtonClickSignal()\0"
    "songListChangedSignal()\0TrackButtonClickSlot()\0"
    "RemoveSelectedTracksSlot()\0"
    "LeaveSelectedTracksSlot()\0"
};

const QMetaObject SongsListWidget::staticMetaObject = {
    { &QScrollArea::staticMetaObject, qt_meta_stringdata_SongsListWidget,
      qt_meta_data_SongsListWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SongsListWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SongsListWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SongsListWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SongsListWidget))
        return static_cast<void*>(const_cast< SongsListWidget*>(this));
    return QScrollArea::qt_metacast(_clname);
}

int SongsListWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QScrollArea::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: TrackButtonClickSignal(); break;
        case 1: songListChangedSignal(); break;
        case 2: TrackButtonClickSlot(); break;
        case 3: RemoveSelectedTracksSlot(); break;
        case 4: LeaveSelectedTracksSlot(); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void SongsListWidget::TrackButtonClickSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void SongsListWidget::songListChangedSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
