/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../mainwindow.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN10MainWindowE_t {};
} // unnamed namespace

template <> constexpr inline auto MainWindow::qt_create_metaobjectdata<qt_meta_tag_ZN10MainWindowE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "MainWindow",
        "signal_broadcastTime",
        "",
        "timeStr",
        "signal_loginResult",
        "success",
        "msg",
        "role",
        "signal_logoutResult",
        "signal_registerResult",
        "signal_joinExamResult",
        "subject",
        "duration",
        "signal_createClassResult",
        "signal_getClassesResult",
        "QJsonArray",
        "classes",
        "signal_getClassesReq",
        "signal_joinClassResult",
        "signal_getMyClassesResult",
        "on_clientReadData"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'signal_broadcastTime'
        QtMocHelpers::SignalData<void(QString)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 },
        }}),
        // Signal 'signal_loginResult'
        QtMocHelpers::SignalData<void(bool, QString, int)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 5 }, { QMetaType::QString, 6 }, { QMetaType::Int, 7 },
        }}),
        // Signal 'signal_logoutResult'
        QtMocHelpers::SignalData<void(bool, QString)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 5 }, { QMetaType::QString, 6 },
        }}),
        // Signal 'signal_registerResult'
        QtMocHelpers::SignalData<void(bool, QString)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 5 }, { QMetaType::QString, 6 },
        }}),
        // Signal 'signal_joinExamResult'
        QtMocHelpers::SignalData<void(bool, QString, QString, int)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 5 }, { QMetaType::QString, 6 }, { QMetaType::QString, 11 }, { QMetaType::Int, 12 },
        }}),
        // Signal 'signal_createClassResult'
        QtMocHelpers::SignalData<void(bool, QString)>(13, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 5 }, { QMetaType::QString, 6 },
        }}),
        // Signal 'signal_getClassesResult'
        QtMocHelpers::SignalData<void(QJsonArray)>(14, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 15, 16 },
        }}),
        // Signal 'signal_getClassesReq'
        QtMocHelpers::SignalData<void()>(17, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'signal_joinClassResult'
        QtMocHelpers::SignalData<void(bool, QString)>(18, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 5 }, { QMetaType::QString, 6 },
        }}),
        // Signal 'signal_getMyClassesResult'
        QtMocHelpers::SignalData<void(QJsonArray)>(19, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 15, 16 },
        }}),
        // Slot 'on_clientReadData'
        QtMocHelpers::SlotData<void()>(20, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<MainWindow, qt_meta_tag_ZN10MainWindowE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10MainWindowE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10MainWindowE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN10MainWindowE_t>.metaTypes,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<MainWindow *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->signal_broadcastTime((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->signal_loginResult((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[3]))); break;
        case 2: _t->signal_logoutResult((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2]))); break;
        case 3: _t->signal_registerResult((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2]))); break;
        case 4: _t->signal_joinExamResult((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[4]))); break;
        case 5: _t->signal_createClassResult((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2]))); break;
        case 6: _t->signal_getClassesResult((*reinterpret_cast<std::add_pointer_t<QJsonArray>>(_a[1]))); break;
        case 7: _t->signal_getClassesReq(); break;
        case 8: _t->signal_joinClassResult((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2]))); break;
        case 9: _t->signal_getMyClassesResult((*reinterpret_cast<std::add_pointer_t<QJsonArray>>(_a[1]))); break;
        case 10: _t->on_clientReadData(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (MainWindow::*)(QString )>(_a, &MainWindow::signal_broadcastTime, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (MainWindow::*)(bool , QString , int )>(_a, &MainWindow::signal_loginResult, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (MainWindow::*)(bool , QString )>(_a, &MainWindow::signal_logoutResult, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (MainWindow::*)(bool , QString )>(_a, &MainWindow::signal_registerResult, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (MainWindow::*)(bool , QString , QString , int )>(_a, &MainWindow::signal_joinExamResult, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (MainWindow::*)(bool , QString )>(_a, &MainWindow::signal_createClassResult, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (MainWindow::*)(QJsonArray )>(_a, &MainWindow::signal_getClassesResult, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (MainWindow::*)()>(_a, &MainWindow::signal_getClassesReq, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (MainWindow::*)(bool , QString )>(_a, &MainWindow::signal_joinClassResult, 8))
            return;
        if (QtMocHelpers::indexOfMethod<void (MainWindow::*)(QJsonArray )>(_a, &MainWindow::signal_getMyClassesResult, 9))
            return;
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10MainWindowE_t>.strings))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::signal_broadcastTime(QString _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void MainWindow::signal_loginResult(bool _t1, QString _t2, int _t3)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1, _t2, _t3);
}

// SIGNAL 2
void MainWindow::signal_logoutResult(bool _t1, QString _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1, _t2);
}

// SIGNAL 3
void MainWindow::signal_registerResult(bool _t1, QString _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1, _t2);
}

// SIGNAL 4
void MainWindow::signal_joinExamResult(bool _t1, QString _t2, QString _t3, int _t4)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1, _t2, _t3, _t4);
}

// SIGNAL 5
void MainWindow::signal_createClassResult(bool _t1, QString _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 5, nullptr, _t1, _t2);
}

// SIGNAL 6
void MainWindow::signal_getClassesResult(QJsonArray _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 6, nullptr, _t1);
}

// SIGNAL 7
void MainWindow::signal_getClassesReq()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void MainWindow::signal_joinClassResult(bool _t1, QString _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 8, nullptr, _t1, _t2);
}

// SIGNAL 9
void MainWindow::signal_getMyClassesResult(QJsonArray _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 9, nullptr, _t1);
}
QT_WARNING_POP
