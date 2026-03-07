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
        "signal_joinExamReq",
        "code",
        "signal_gotoTestPage",
        "signal_getScoresReq",
        "signal_changePwdReq",
        "oldPwd",
        "newPwd",
        "signal_changeSuccess",
        "on_logoutBtn_clicked",
        "updateUserName",
        "name",
        "on_btn_joinExam_clicked",
        "on_btn_confirm_clicked",
        "handleJoinExamResult",
        "success",
        "msg",
        "subject",
        "duration"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'signal_callbackLoginMenu'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'signal_LogoutData'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'signal_joinExamReq'
        QtMocHelpers::SignalData<void(QString)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 5 },
        }}),
        // Signal 'signal_gotoTestPage'
        QtMocHelpers::SignalData<void()>(6, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'signal_getScoresReq'
        QtMocHelpers::SignalData<void()>(7, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'signal_changePwdReq'
        QtMocHelpers::SignalData<void(QString, QString)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 9 }, { QMetaType::QString, 10 },
        }}),
        // Signal 'signal_changeSuccess'
        QtMocHelpers::SignalData<void()>(11, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'on_logoutBtn_clicked'
        QtMocHelpers::SlotData<void()>(12, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'updateUserName'
        QtMocHelpers::SlotData<void(QString)>(13, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 14 },
        }}),
        // Slot 'on_btn_joinExam_clicked'
        QtMocHelpers::SlotData<void()>(15, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'on_btn_confirm_clicked'
        QtMocHelpers::SlotData<void()>(16, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'handleJoinExamResult'
        QtMocHelpers::SlotData<void(bool, QString, QString, int)>(17, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 18 }, { QMetaType::QString, 19 }, { QMetaType::QString, 20 }, { QMetaType::Int, 21 },
        }}),
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
        case 2: _t->signal_joinExamReq((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->signal_gotoTestPage(); break;
        case 4: _t->signal_getScoresReq(); break;
        case 5: _t->signal_changePwdReq((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2]))); break;
        case 6: _t->signal_changeSuccess(); break;
        case 7: _t->on_logoutBtn_clicked(); break;
        case 8: _t->updateUserName((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 9: _t->on_btn_joinExam_clicked(); break;
        case 10: _t->on_btn_confirm_clicked(); break;
        case 11: _t->handleJoinExamResult((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[4]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (MainMenuWidget::*)()>(_a, &MainMenuWidget::signal_callbackLoginMenu, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (MainMenuWidget::*)()>(_a, &MainMenuWidget::signal_LogoutData, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (MainMenuWidget::*)(QString )>(_a, &MainMenuWidget::signal_joinExamReq, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (MainMenuWidget::*)()>(_a, &MainMenuWidget::signal_gotoTestPage, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (MainMenuWidget::*)()>(_a, &MainMenuWidget::signal_getScoresReq, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (MainMenuWidget::*)(QString , QString )>(_a, &MainMenuWidget::signal_changePwdReq, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (MainMenuWidget::*)()>(_a, &MainMenuWidget::signal_changeSuccess, 6))
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
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
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
void MainMenuWidget::signal_joinExamReq(QString _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void MainMenuWidget::signal_gotoTestPage()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
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
void MainMenuWidget::signal_changeSuccess()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}
QT_WARNING_POP
