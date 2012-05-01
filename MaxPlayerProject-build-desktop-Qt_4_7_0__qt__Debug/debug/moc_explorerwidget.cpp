/****************************************************************************
** Meta object code from reading C++ file 'explorerwidget.h'
**
** Created: Wed 2. May 00:12:23 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MaxPlayerProject/explorerwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'explorerwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ExplorerWidget[] = {

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
      16,   15,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      43,   15,   15,   15, 0x0a,
      73,   15,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ExplorerWidget[] = {
    "ExplorerWidget\0\0AddSongsInPlaylistSignal()\0"
    "ExplorerMenuButtonClickSlot()\0"
    "AddSongsInPlaylistButtonClickSlot()\0"
};

const QMetaObject ExplorerWidget::staticMetaObject = {
    { &TitleWidget::staticMetaObject, qt_meta_stringdata_ExplorerWidget,
      qt_meta_data_ExplorerWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ExplorerWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ExplorerWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ExplorerWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ExplorerWidget))
        return static_cast<void*>(const_cast< ExplorerWidget*>(this));
    return TitleWidget::qt_metacast(_clname);
}

int ExplorerWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = TitleWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: AddSongsInPlaylistSignal(); break;
        case 1: ExplorerMenuButtonClickSlot(); break;
        case 2: AddSongsInPlaylistButtonClickSlot(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void ExplorerWidget::AddSongsInPlaylistSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
