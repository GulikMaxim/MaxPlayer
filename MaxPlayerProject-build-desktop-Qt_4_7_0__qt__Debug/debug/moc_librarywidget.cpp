/****************************************************************************
** Meta object code from reading C++ file 'librarywidget.h'
**
** Created: Tue 1. May 16:39:14 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MaxPlayerProject/librarywidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'librarywidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LibraryWidget[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x08,
      44,   14,   14,   14, 0x08,
      80,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_LibraryWidget[] = {
    "LibraryWidget\0\0LibraryMenuButtonClickSlot()\0"
    "MultiSellectionCheckBoxChangeSlot()\0"
    "PlaylistsListChangedSlot()\0"
};

const QMetaObject LibraryWidget::staticMetaObject = {
    { &TitleWidget::staticMetaObject, qt_meta_stringdata_LibraryWidget,
      qt_meta_data_LibraryWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LibraryWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LibraryWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LibraryWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LibraryWidget))
        return static_cast<void*>(const_cast< LibraryWidget*>(this));
    return TitleWidget::qt_metacast(_clname);
}

int LibraryWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = TitleWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: LibraryMenuButtonClickSlot(); break;
        case 1: MultiSellectionCheckBoxChangeSlot(); break;
        case 2: PlaylistsListChangedSlot(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
