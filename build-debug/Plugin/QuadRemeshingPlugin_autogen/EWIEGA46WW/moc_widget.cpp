/****************************************************************************
** Meta object code from reading C++ file 'widget.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "widget.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QuadRemeshing__MyWidget_t {
    QByteArrayData data[13];
    char stringdata0[256];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QuadRemeshing__MyWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QuadRemeshing__MyWidget_t qt_meta_stringdata_QuadRemeshing__MyWidget = {
    {
QT_MOC_LITERAL(0, 0, 23), // "QuadRemeshing::MyWidget"
QT_MOC_LITERAL(1, 24, 20), // "computationRequested"
QT_MOC_LITERAL(2, 45, 0), // ""
QT_MOC_LITERAL(3, 46, 22), // "QuadRemeshingParameter"
QT_MOC_LITERAL(4, 69, 1), // "p"
QT_MOC_LITERAL(5, 71, 24), // "on__remeshButton_clicked"
QT_MOC_LITERAL(6, 96, 23), // "on__step1Button_clicked"
QT_MOC_LITERAL(7, 120, 23), // "on__step2Button_clicked"
QT_MOC_LITERAL(8, 144, 23), // "on__step3Button_clicked"
QT_MOC_LITERAL(9, 168, 23), // "on__step4Button_clicked"
QT_MOC_LITERAL(10, 192, 23), // "on__step5Button_clicked"
QT_MOC_LITERAL(11, 216, 15), // "getSelectedMesh"
QT_MOC_LITERAL(12, 232, 23) // "Ra::Engine::Data::Mesh*"

    },
    "QuadRemeshing::MyWidget\0computationRequested\0"
    "\0QuadRemeshingParameter\0p\0"
    "on__remeshButton_clicked\0"
    "on__step1Button_clicked\0on__step2Button_clicked\0"
    "on__step3Button_clicked\0on__step4Button_clicked\0"
    "on__step5Button_clicked\0getSelectedMesh\0"
    "Ra::Engine::Data::Mesh*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QuadRemeshing__MyWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   57,    2, 0x08 /* Private */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    0,   59,    2, 0x08 /* Private */,
       8,    0,   60,    2, 0x08 /* Private */,
       9,    0,   61,    2, 0x08 /* Private */,
      10,    0,   62,    2, 0x08 /* Private */,
      11,    0,   63,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    0x80000000 | 12,

       0        // eod
};

void QuadRemeshing::MyWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MyWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->computationRequested((*reinterpret_cast< QuadRemeshingParameter(*)>(_a[1]))); break;
        case 1: _t->on__remeshButton_clicked(); break;
        case 2: _t->on__step1Button_clicked(); break;
        case 3: _t->on__step2Button_clicked(); break;
        case 4: _t->on__step3Button_clicked(); break;
        case 5: _t->on__step4Button_clicked(); break;
        case 6: _t->on__step5Button_clicked(); break;
        case 7: { Ra::Engine::Data::Mesh* _r = _t->getSelectedMesh();
            if (_a[0]) *reinterpret_cast< Ra::Engine::Data::Mesh**>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MyWidget::*)(QuadRemeshingParameter );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyWidget::computationRequested)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QuadRemeshing::MyWidget::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_QuadRemeshing__MyWidget.data,
    qt_meta_data_QuadRemeshing__MyWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QuadRemeshing::MyWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QuadRemeshing::MyWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QuadRemeshing__MyWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int QuadRemeshing::MyWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void QuadRemeshing::MyWidget::computationRequested(QuadRemeshingParameter _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
