/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Fri Oct 21 16:17:27 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../eCopy/mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      35,   11,   11,   11, 0x08,
      64,   11,   11,   11, 0x08,
      89,   76,   11,   11, 0x08,
     112,   11,   11,   11, 0x08,
     141,   11,   11,   11, 0x08,
     164,   11,   11,   11, 0x08,
     200,   11,   11,   11, 0x08,
     224,   11,   11,   11, 0x08,
     246,   11,   11,   11, 0x08,
     280,  273,   11,   11, 0x08,
     333,   11,   11,   11, 0x08,
     344,   11,   11,   11, 0x08,
     362,  360,   11,   11, 0x08,
     385,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0on_message_b_clicked()\0"
    "on_actionReduire_triggered()\0maximiser()\0"
    "type,message\0evenement(int,QString)\0"
    "on_actionQuitter_triggered()\0"
    "on_valider_b_clicked()\0"
    "on_actionSe_reconnecter_triggered()\0"
    "on_chercher_b_clicked()\0on_retour_b_clicked()\0"
    "on_inscription_b_clicked()\0raison\0"
    "systray_activated(QSystemTrayIcon::ActivationReason)\0"
    "chatFini()\0transfertFini()\0,\0"
    "gtw_event(int,QString)\0on_fichier_b_clicked()\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    if (!strcmp(_clname, "Ui::MainWindow"))
        return static_cast< Ui::MainWindow*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_message_b_clicked(); break;
        case 1: on_actionReduire_triggered(); break;
        case 2: maximiser(); break;
        case 3: evenement((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: on_actionQuitter_triggered(); break;
        case 5: on_valider_b_clicked(); break;
        case 6: on_actionSe_reconnecter_triggered(); break;
        case 7: on_chercher_b_clicked(); break;
        case 8: on_retour_b_clicked(); break;
        case 9: on_inscription_b_clicked(); break;
        case 10: systray_activated((*reinterpret_cast< QSystemTrayIcon::ActivationReason(*)>(_a[1]))); break;
        case 11: chatFini(); break;
        case 12: transfertFini(); break;
        case 13: gtw_event((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 14: on_fichier_b_clicked(); break;
        default: ;
        }
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
