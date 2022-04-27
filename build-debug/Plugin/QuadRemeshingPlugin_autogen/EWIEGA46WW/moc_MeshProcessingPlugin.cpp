/****************************************************************************
** Meta object code from reading C++ file 'MeshProcessingPlugin.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "MeshProcessingPlugin.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/qplugin.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MeshProcessingPlugin.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QuadRemeshing__QuadRemshingPlugin_t {
    QByteArrayData data[3];
    char stringdata0[48];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QuadRemeshing__QuadRemshingPlugin_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QuadRemeshing__QuadRemshingPlugin_t qt_meta_stringdata_QuadRemeshing__QuadRemshingPlugin = {
    {
QT_MOC_LITERAL(0, 0, 33), // "QuadRemeshing::QuadRemshingPl..."
QT_MOC_LITERAL(1, 34, 12), // "askForUpdate"
QT_MOC_LITERAL(2, 47, 0) // ""

    },
    "QuadRemeshing::QuadRemshingPlugin\0"
    "askForUpdate\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QuadRemeshing__QuadRemshingPlugin[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,

       0        // eod
};

void QuadRemeshing::QuadRemshingPlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QuadRemshingPlugin *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->askForUpdate(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QuadRemshingPlugin::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QuadRemshingPlugin::askForUpdate)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject QuadRemeshing::QuadRemshingPlugin::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_QuadRemeshing__QuadRemshingPlugin.data,
    qt_meta_data_QuadRemeshing__QuadRemshingPlugin,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QuadRemeshing::QuadRemshingPlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QuadRemeshing::QuadRemshingPlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QuadRemeshing__QuadRemshingPlugin.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ra::Plugins::RadiumPluginInterface"))
        return static_cast< Ra::Plugins::RadiumPluginInterface*>(this);
    if (!strcmp(_clname, "RadiumEngine.PluginInterface"))
        return static_cast< Ra::Plugins::RadiumPluginInterface*>(this);
    return QObject::qt_metacast(_clname);
}

int QuadRemeshing::QuadRemshingPlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void QuadRemeshing::QuadRemshingPlugin::askForUpdate()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

QT_PLUGIN_METADATA_SECTION
static constexpr unsigned char qt_pluginMetaData[] = {
    'Q', 'T', 'M', 'E', 'T', 'A', 'D', 'A', 'T', 'A', ' ', '!',
    // metadata version, Qt version, architectural requirements
    0, QT_VERSION_MAJOR, QT_VERSION_MINOR, qPluginArchRequirements(),
    0xbf, 
    // "IID"
    0x02,  0x78,  0x1c,  'R',  'a',  'd',  'i',  'u', 
    'm',  'E',  'n',  'g',  'i',  'n',  'e',  '.', 
    'P',  'l',  'u',  'g',  'i',  'n',  'I',  'n', 
    't',  'e',  'r',  'f',  'a',  'c',  'e', 
    // "className"
    0x03,  0x72,  'Q',  'u',  'a',  'd',  'R',  'e', 
    'm',  's',  'h',  'i',  'n',  'g',  'P',  'l', 
    'u',  'g',  'i',  'n', 
    // "MetaData"
    0x04,  0xa2,  0x78,  0x1b,  'c',  'o',  'm',  '.', 
    's',  't',  'o',  'r',  'm',  '-',  'i',  'r', 
    'i',  't',  '.',  'R',  'a',  'd',  'i',  'u', 
    'm',  'E',  'n',  'g',  'i',  'n',  'e',  0x66, 
    'p',  'l',  'u',  'g',  'i',  'n',  0x67,  'i', 
    's',  'D',  'e',  'b',  'u',  'g',  0x64,  't', 
    'r',  'u',  'e', 
    0xff, 
};
using namespace QuadRemeshing;
QT_MOC_EXPORT_PLUGIN(QuadRemeshing::QuadRemshingPlugin, QuadRemshingPlugin)

QT_WARNING_POP
QT_END_MOC_NAMESPACE
