/****************************************************************************
** Meta object code from reading C++ file 'mainmenuwidget.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../mainmenuwidget.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainmenuwidget.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN14MainMenuWidgetE_t {};
} // unnamed namespace

template <> constexpr inline auto MainMenuWidget::qt_create_metaobjectdata<qt_meta_tag_ZN14MainMenuWidgetE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "MainMenuWidget",
        "signal_callbackLoginMenu",
        "",
        "signal_LogoutData",
        "signal_gotoTestPage",
        "code",
        "signal_joinExamReq",
        "signal_getScoresReq",
        "signal_changePwdReq",
        "oldPwd",
        "newPwd",
        "signal_joinClassReq",
        "signal_getMyClassesReq",
        "signal_changeSuccess",
        "on_logoutBtn_clicked",
        "on_btn_joinExam_clicked",
        "on_btn_joinClass_clicked",
        "on_btn_confirm_clicked"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'signal_callbackLoginMenu'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'signal_LogoutData'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'signal_gotoTestPage'
        QtMocHelpers::SignalData<void(QString)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 5 },
        }}),
        // Signal 'signal_joinExamReq'
        QtMocHelpers::SignalData<void(QString)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 5 },
        }}),
        // Signal 'signal_getScoresReq'
        QtMocHelpers::SignalData<void()>(7, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'signal_changePwdReq'
        QtMocHelpers::SignalData<void(QString, QString)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 9 }, { QMetaType::QString, 10 },
        }}),
        // Signal 'signal_joinClassReq'
        QtMocHelpers::SignalData<void(QString)>(11, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 5 },
        }}),
        // Signal 'signal_getMyClassesReq'
        QtMocHelpers::SignalData<void()>(12, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'signal_changeSuccess'
        QtMocHelpers::SignalData<void()>(13, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'on_logoutBtn_clicked'
        QtMocHelpers::SlotData<void()>(14, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btn_joinExam_clicked'
        QtMocHelpers::SlotData<void()>(15, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btn_joinClass_clicked'
        QtMocHelpers::SlotData<void()>(16, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btn_confirm_clicked'
        QtMocHelpers::SlotData<void()>(17, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<MainMenuWidget, qt_meta_tag_ZN14MainMenuWidgetE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject MainMenuWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14MainMenuWidgetE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14MainMenuWidgetE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN14MainMenuWidgetE_t>.metaTypes,
    nullptr
} };

void MainMenuWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<MainMenuWidget *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->signal_callbackLoginMenu(); break;
        case 1: _t->signal_LogoutData(); break;
        case 2: _t->signal_gotoTestPage((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->signal_joinExamReq((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->signal_getScoresReq(); break;
        case 5: _t->signal_changePwdReq((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2]))); break;
        case 6: _t->signal_joinClassReq((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 7: _t->signal_getMyClassesReq(); break;
        case 8: _t->signal_changeSuccess(); break;
        case 9: _t->on_logoutBtn_clicked(); break;
        case 10: _t->on_btn_joinExam_clicked(); break;
        case 11: _t->on_btn_joinClass_clicked(); break;
        case 12: _t->on_btn_confirm_clicked(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (MainMenuWidget::*)()>(_a, &MainMenuWidget::signal_callbackLoginMenu, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (MainMenuWidget::*)()>(_a, &MainMenuWidget::signal_LogoutData, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (MainMenuWidget::*)(QString )>(_a, &MainMenuWidget::signal_gotoTestPage, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (MainMenuWidget::*)(QString )>(_a, &MainMenuWidget::signal_joinExamReq, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (MainMenuWidget::*)()>(_a, &MainMenuWidget::signal_getScoresReq, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (MainMenuWidget::*)(QString , QString )>(_a, &MainMenuWidget::signal_changePwdReq, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (MainMenuWidget::*)(QString )>(_a, &MainMenuWidget::signal_joinClassReq, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (MainMenuWidget::*)()>(_a, &MainMenuWidget::signal_getMyClassesReq, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (MainMenuWidget::*)()>(_a, &MainMenuWidget::signal_changeSuccess, 8))
            return;
    }
}

const QMetaObject *MainMenuWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainMenuWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14MainMenuWidgetE_t>.strings))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int MainMenuWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void MainMenuWidget::signal_callbackLoginMenu()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MainMenuWidget::signal_LogoutData()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MainMenuWidget::signal_gotoTestPage(QString _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void MainMenuWidget::signal_joinExamReq(QString _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void MainMenuWidget::signal_getScoresReq()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void MainMenuWidget::signal_changePwdReq(QString _t1, QString _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 5, nullptr, _t1, _t2);
}

// SIGNAL 6
void MainMenuWidget::signal_joinClassReq(QString _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 6, nullptr, _t1);
}

// SIGNAL 7
void MainMenuWidget::signal_getMyClassesReq()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void MainMenuWidget::signal_changeSuccess()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}
QT_WARNING_POP
