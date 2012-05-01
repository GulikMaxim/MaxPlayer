/****************************************************************************
** Meta object code from reading C++ file 'audioplayerwidget.h'
**
** Created: Tue 1. May 16:02:40 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MaxPlayerProject/audioplayerwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'audioplayerwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AudioPlayerWidget[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      19,   18,   18,   18, 0x0a,
      46,   18,   18,   18, 0x0a,
      63,   18,   18,   18, 0x0a,
      88,   18,   18,   18, 0x0a,
     108,   18,   18,   18, 0x0a,
     134,   18,   18,   18, 0x0a,
     157,   18,   18,   18, 0x0a,
     185,   18,   18,   18, 0x0a,
     214,   18,   18,   18, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_AudioPlayerWidget[] = {
    "AudioPlayerWidget\0\0PlayPauseButtonClickSlot()\0"
    "StopButtonSlot()\0PlaylistTrackClickSlot()\0"
    "PlayNextTrackSlot()\0PrevTracButtonClickSlot()\0"
    "VolumButtonClickSlot()\0"
    "SeekSliderButtonClickSlot()\0"
    "RandomPlayButtonClickeSlot()\0"
    "ReplayButtonClickSlot()\0"
};

const QMetaObject AudioPlayerWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_AudioPlayerWidget,
      qt_meta_data_AudioPlayerWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AudioPlayerWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AudioPlayerWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AudioPlayerWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AudioPlayerWidget))
        return static_cast<void*>(const_cast< AudioPlayerWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int AudioPlayerWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: PlayPauseButtonClickSlot(); break;
        case 1: StopButtonSlot(); break;
        case 2: PlaylistTrackClickSlot(); break;
        case 3: PlayNextTrackSlot(); break;
        case 4: PrevTracButtonClickSlot(); break;
        case 5: VolumButtonClickSlot(); break;
        case 6: SeekSliderButtonClickSlot(); break;
        case 7: RandomPlayButtonClickeSlot(); break;
        case 8: ReplayButtonClickSlot(); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
