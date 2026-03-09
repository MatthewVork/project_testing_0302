/****************************************************************************
** Meta object code from reading C++ file 'menu_teacher.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../menu_teacher.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'menu_teacher.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.10.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN12menu_TeacherE_t {};
} // unnamed namespace

template <> constexpr inline auto menu_Teacher::qt_create_metaobjectdata<qt_meta_tag_ZN12menu_TeacherE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "menu_Teacher",
        "signal_createClassReq",
        "",
        "className",
        "signal_getClassesReq",
        "on_btn_createClass_clicked",
        "handleGetClassesResult",
        "QJsonArray",
        "classes"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'signal_createClassReq'
        QtMocHelpers::SignalData<void(QString)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 },
        }}),
        // Signal 'signal_getClassesReq'
        QtMocHelpers::SignalData<void()>(4, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'on_btn_createClass_clicked'
        QtMocHelpers::SlotData<void()>(5, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'handleGetClassesResult'
        QtMocHelpers::SlotData<void(QJsonArray)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 7, 8 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<menu_Teacher, qt_meta_tag_ZN12menu_TeacherE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject menu_Teacher::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12menu_TeacherE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12menu_TeacherE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN12menu_TeacherE_t>.metaTypes,
    nullptr
} };

void menu_Teacher::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<menu_Teacher *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->signal_createClassReq((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->signal_getClassesReq(); break;
        case 2: _t->on_btn_createClass_clicked(); break;
        case 3: _t->handleGetClassesResult((*reinterpret_cast<std::add_pointer_t<QJsonArray>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (menu_Teacher::*)(QString )>(_a, &menu_Teacher::signal_createClassReq, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (menu_Teacher::*)()>(_a, &menu_Teacher::signal_getClassesReq, 1))
            return;
    }
}

const QMetaObject *menu_Teacher::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *menu_Teacher::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12menu_TeacherE_t>.strings))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int menu_Teacher::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void menu_Teacher::signal_createClassReq(QString _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void menu_Teacher::signal_getClassesReq()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
