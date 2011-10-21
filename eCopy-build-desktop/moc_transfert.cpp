/****************************************************************************
** Meta object code from reading C++ file 'transfert.h'
**
** Created: Fri Oct 21 16:17:40 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../eCopy/transfert.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'transfert.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_transfert[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      20,   10,   10,   10, 0x08,
      50,   44,   10,   10, 0x08,
      95,   10,   10,   10, 0x08,
     116,   10,   10,   10, 0x08,
     136,   10,   10,   10, 0x08,
     159,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_transfert[] = {
    "transfert\0\0quitte()\0on_choose_f_b_clicked()\0"
    "index\0on_liste_fichiers_doubleClicked(QModelIndex)\0"
    "on_envoi_b_clicked()\0on_quit_b_clicked()\0"
    "on_quitter_b_clicked()\0on_stop_all_clicked()\0"
};

const QMetaObject transfert::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_transfert,
      qt_meta_data_transfert, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &transfert::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *transfert::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *transfert::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_transfert))
        return static_cast<void*>(const_cast< transfert*>(this));
    if (!strcmp(_clname, "Ui::transfert"))
        return static_cast< Ui::transfert*>(const_cast< transfert*>(this));
    return QDialog::qt_metacast(_clname);
}

int transfert::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: quitte(); break;
        case 1: on_choose_f_b_clicked(); break;
        case 2: on_liste_fichiers_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 3: on_envoi_b_clicked(); break;
        case 4: on_quit_b_clicked(); break;
        case 5: on_quitter_b_clicked(); break;
        case 6: on_stop_all_clicked(); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void transfert::quitte()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
