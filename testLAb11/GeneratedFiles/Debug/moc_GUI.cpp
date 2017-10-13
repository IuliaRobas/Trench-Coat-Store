/****************************************************************************
** Meta object code from reading C++ file 'GUI.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../GUI.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GUI.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GUI_t {
    QByteArrayData data[20];
    char stringdata0[307];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GUI_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GUI_t qt_meta_stringdata_GUI = {
    {
QT_MOC_LITERAL(0, 0, 3), // "GUI"
QT_MOC_LITERAL(1, 4, 18), // "coatsUpdatedSignal"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 19), // "addTrenchCoatSignal"
QT_MOC_LITERAL(4, 44, 2), // "ID"
QT_MOC_LITERAL(5, 47, 4), // "size"
QT_MOC_LITERAL(6, 52, 6), // "length"
QT_MOC_LITERAL(7, 59, 11), // "std::string"
QT_MOC_LITERAL(8, 71, 6), // "colour"
QT_MOC_LITERAL(9, 78, 5), // "price"
QT_MOC_LITERAL(10, 84, 8), // "quantity"
QT_MOC_LITERAL(11, 93, 10), // "photograph"
QT_MOC_LITERAL(12, 104, 22), // "updateTrenchCoatSignal"
QT_MOC_LITERAL(13, 127, 26), // "addTrenchCoatButtonHandler"
QT_MOC_LITERAL(14, 154, 29), // "deleteTrenchCoatButtonHandler"
QT_MOC_LITERAL(15, 184, 29), // "updateTrenchCoatButtonHandler"
QT_MOC_LITERAL(16, 214, 29), // "sortedTrenchCoatButtonHandler"
QT_MOC_LITERAL(17, 244, 31), // "shuffledTrenchCoatButtonHandler"
QT_MOC_LITERAL(18, 276, 16), // "updateTrenchCoat"
QT_MOC_LITERAL(19, 293, 13) // "addTrenchCoat"

    },
    "GUI\0coatsUpdatedSignal\0\0addTrenchCoatSignal\0"
    "ID\0size\0length\0std::string\0colour\0"
    "price\0quantity\0photograph\0"
    "updateTrenchCoatSignal\0"
    "addTrenchCoatButtonHandler\0"
    "deleteTrenchCoatButtonHandler\0"
    "updateTrenchCoatButtonHandler\0"
    "sortedTrenchCoatButtonHandler\0"
    "shuffledTrenchCoatButtonHandler\0"
    "updateTrenchCoat\0addTrenchCoat"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GUI[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    7,   65,    2, 0x06 /* Public */,
      12,    7,   80,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    0,   95,    2, 0x0a /* Public */,
      14,    0,   96,    2, 0x0a /* Public */,
      15,    0,   97,    2, 0x0a /* Public */,
      16,    0,   98,    2, 0x0a /* Public */,
      17,    0,   99,    2, 0x0a /* Public */,
      18,    7,  100,    2, 0x0a /* Public */,
      19,    7,  115,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Double, QMetaType::Double, 0x80000000 | 7, QMetaType::Double, QMetaType::Double, 0x80000000 | 7,    4,    5,    6,    8,    9,   10,   11,
    QMetaType::Void, QMetaType::Int, QMetaType::Double, QMetaType::Double, 0x80000000 | 7, QMetaType::Double, QMetaType::Double, 0x80000000 | 7,    4,    5,    6,    8,    9,   10,   11,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Double, QMetaType::Double, 0x80000000 | 7, QMetaType::Double, QMetaType::Double, 0x80000000 | 7,    4,    5,    6,    8,    9,   10,   11,
    QMetaType::Void, QMetaType::Int, QMetaType::Double, QMetaType::Double, 0x80000000 | 7, QMetaType::Double, QMetaType::Double, 0x80000000 | 7,    4,    5,    6,    8,    9,   10,   11,

       0        // eod
};

void GUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GUI *_t = static_cast<GUI *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->coatsUpdatedSignal(); break;
        case 1: _t->addTrenchCoatSignal((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const double(*)>(_a[2])),(*reinterpret_cast< const double(*)>(_a[3])),(*reinterpret_cast< const std::string(*)>(_a[4])),(*reinterpret_cast< const double(*)>(_a[5])),(*reinterpret_cast< const double(*)>(_a[6])),(*reinterpret_cast< const std::string(*)>(_a[7]))); break;
        case 2: _t->updateTrenchCoatSignal((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const double(*)>(_a[2])),(*reinterpret_cast< const double(*)>(_a[3])),(*reinterpret_cast< const std::string(*)>(_a[4])),(*reinterpret_cast< const double(*)>(_a[5])),(*reinterpret_cast< const double(*)>(_a[6])),(*reinterpret_cast< const std::string(*)>(_a[7]))); break;
        case 3: _t->addTrenchCoatButtonHandler(); break;
        case 4: _t->deleteTrenchCoatButtonHandler(); break;
        case 5: _t->updateTrenchCoatButtonHandler(); break;
        case 6: _t->sortedTrenchCoatButtonHandler(); break;
        case 7: _t->shuffledTrenchCoatButtonHandler(); break;
        case 8: _t->updateTrenchCoat((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const double(*)>(_a[2])),(*reinterpret_cast< const double(*)>(_a[3])),(*reinterpret_cast< const std::string(*)>(_a[4])),(*reinterpret_cast< const double(*)>(_a[5])),(*reinterpret_cast< const double(*)>(_a[6])),(*reinterpret_cast< const std::string(*)>(_a[7]))); break;
        case 9: _t->addTrenchCoat((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const double(*)>(_a[2])),(*reinterpret_cast< const double(*)>(_a[3])),(*reinterpret_cast< const std::string(*)>(_a[4])),(*reinterpret_cast< const double(*)>(_a[5])),(*reinterpret_cast< const double(*)>(_a[6])),(*reinterpret_cast< const std::string(*)>(_a[7]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GUI::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GUI::coatsUpdatedSignal)) {
                *result = 0;
            }
        }
        {
            typedef void (GUI::*_t)(const int & , const double & , const double & , const std::string & , const double & , const double & , const std::string & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GUI::addTrenchCoatSignal)) {
                *result = 1;
            }
        }
        {
            typedef void (GUI::*_t)(const int & , const double & , const double & , const std::string & , const double & , const double & , const std::string & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GUI::updateTrenchCoatSignal)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject GUI::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_GUI.data,
      qt_meta_data_GUI,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GUI::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GUI.stringdata0))
        return static_cast<void*>(const_cast< GUI*>(this));
    return QWidget::qt_metacast(_clname);
}

int GUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void GUI::coatsUpdatedSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void GUI::addTrenchCoatSignal(const int & _t1, const double & _t2, const double & _t3, const std::string & _t4, const double & _t5, const double & _t6, const std::string & _t7)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void GUI::updateTrenchCoatSignal(const int & _t1, const double & _t2, const double & _t3, const std::string & _t4, const double & _t5, const double & _t6, const std::string & _t7)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
