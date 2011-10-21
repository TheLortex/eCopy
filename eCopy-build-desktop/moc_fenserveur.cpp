/****************************************************************************
** Meta object code from reading C++ file 'fenserveur.h'
**
** Created: Mon Sep 5 17:57:20 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../eCopy_serveur/fenserveur.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fenserveur.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FenServeur[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      32,   11,   11,   11, 0x08,
      48,   11,   11,   11, 0x08,
      68,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_FenServeur[] = {
    "FenServeur\0\0nouvelleConnexion()\0"
    "donneesRecues()\0deconnexionClient()\0"
    "act()\0"
};

const QMetaObject FenServeur::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_FenServeur,
      qt_meta_data_FenServeur, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FenServeur::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FenServeur::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FenServeur::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FenServeur))
        return static_cast<void*>(const_cast< FenServeur*>(this));
    if (!strcmp(_clname, "Ui::MainWindow"))
        return static_cast< Ui::MainWindow*>(const_cast< FenServeur*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int FenServeur::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: nouvelleConnexion(); break;
        case 1: donneesRecues(); break;
        case 2: deconnexionClient(); break;
        case 3: act(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
