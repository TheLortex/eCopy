/****************************************************************************
** Meta object code from reading C++ file 'chat.h'
**
** Created: Fri Oct 21 16:17:34 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../eCopy/chat.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chat.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_chat[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
       6,    5,    5,    5, 0x05,

 // slots: signature, parameters, type, tag, flags
      15,    5,    5,    5, 0x08,
      50,    5,    5,    5, 0x08,
      73,    5,    5,    5, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_chat[] = {
    "chat\0\0quitte()\0on_messageAEnvoyer_returnPressed()\0"
    "on_envoyer_b_clicked()\0termine()\0"
};

const QMetaObject chat::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_chat,
      qt_meta_data_chat, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &chat::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *chat::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *chat::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_chat))
        return static_cast<void*>(const_cast< chat*>(this));
    if (!strcmp(_clname, "Ui::chat"))
        return static_cast< Ui::chat*>(const_cast< chat*>(this));
    return QDialog::qt_metacast(_clname);
}

int chat::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: quitte(); break;
        case 1: on_messageAEnvoyer_returnPressed(); break;
        case 2: on_envoyer_b_clicked(); break;
        case 3: termine(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void chat::quitte()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
