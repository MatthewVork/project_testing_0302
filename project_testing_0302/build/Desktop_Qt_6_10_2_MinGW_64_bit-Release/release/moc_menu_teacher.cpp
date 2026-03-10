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
        "signal_getClassStudentsReq",
        "classCode",
        "signal_getClassesReq",
        "signal_addQuestionReq",
        "QJsonObject",
        "data",
        "signal_publishExamReq",
        "signal_getClassExamsReq",
        "signal_getExamScoresReq",
        "examCode",
        "signal_logoutReq",
        "on_btn_createClass_clicked",
        "on_btn_finishExam_clicked",
        "on_btn_searchStudents_clicked",
        "on_btn_addQuestion_clicked",
        "on_btn_generateExam_clicked",
        "on_comboBox_scoreClass_currentIndexChanged",
        "index",
        "on_btn_searchScores_clicked"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'signal_createClassReq'
        QtMocHelpers::SignalData<void(QString)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 },
        }}),
        // Signal 'signal_getClassStudentsReq'
        QtMocHelpers::SignalData<void(QString)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 5 },
        }}),
        // Signal 'signal_getClassesReq'
        QtMocHelpers::SignalData<void()>(6, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'signal_addQuestionReq'
        QtMocHelpers::SignalData<void(QJsonObject)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 8, 9 },
        }}),
        // Signal 'signal_publishExamReq'
        QtMocHelpers::SignalData<void(QJsonObject)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 8, 9 },
        }}),
        // Signal 'signal_getClassExamsReq'
        QtMocHelpers::SignalData<void(QString)>(11, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 5 },
        }}),
        // Signal 'signal_getExamScoresReq'
        QtMocHelpers::SignalData<void(QString)>(12, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 13 },
        }}),
        // Signal 'signal_logoutReq'
        QtMocHelpers::SignalData<void()>(14, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'on_btn_createClass_clicked'
        QtMocHelpers::SlotData<void()>(15, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btn_finishExam_clicked'
        QtMocHelpers::SlotData<void()>(16, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btn_searchStudents_clicked'
        QtMocHelpers::SlotData<void()>(17, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'on_btn_addQuestion_clicked'
        QtMocHelpers::SlotData<void()>(18, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'on_btn_generateExam_clicked'
        QtMocHelpers::SlotData<void()>(19, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'on_comboBox_scoreClass_currentIndexChanged'
        QtMocHelpers::SlotData<void(int)>(20, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 21 },
        }}),
        // Slot 'on_btn_searchScores_clicked'
        QtMocHelpers::SlotData<void()>(22, 2, QMC::AccessPublic, QMetaType::Void),
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
        case 1: _t->signal_getClassStudentsReq((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->signal_getClassesReq(); break;
        case 3: _t->signal_addQuestionReq((*reinterpret_cast<std::add_pointer_t<QJsonObject>>(_a[1]))); break;
        case 4: _t->signal_publishExamReq((*reinterpret_cast<std::add_pointer_t<QJsonObject>>(_a[1]))); break;
        case 5: _t->signal_getClassExamsReq((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 6: _t->signal_getExamScoresReq((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 7: _t->signal_logoutReq(); break;
        case 8: _t->on_btn_createClass_clicked(); break;
        case 9: _t->on_btn_finishExam_clicked(); break;
        case 10: _t->on_btn_searchStudents_clicked(); break;
        case 11: _t->on_btn_addQuestion_clicked(); break;
        case 12: _t->on_btn_generateExam_clicked(); break;
        case 13: _t->on_comboBox_scoreClass_currentIndexChanged((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 14: _t->on_btn_searchScores_clicked(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (menu_Teacher::*)(QString )>(_a, &menu_Teacher::signal_createClassReq, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (menu_Teacher::*)(QString )>(_a, &menu_Teacher::signal_getClassStudentsReq, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (menu_Teacher::*)()>(_a, &menu_Teacher::signal_getClassesReq, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (menu_Teacher::*)(QJsonObject )>(_a, &menu_Teacher::signal_addQuestionReq, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (menu_Teacher::*)(QJsonObject )>(_a, &menu_Teacher::signal_publishExamReq, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (menu_Teacher::*)(QString )>(_a, &menu_Teacher::signal_getClassExamsReq, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (menu_Teacher::*)(QString )>(_a, &menu_Teacher::signal_getExamScoresReq, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (menu_Teacher::*)()>(_a, &menu_Teacher::signal_logoutReq, 7))
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
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void menu_Teacher::signal_createClassReq(QString _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void menu_Teacher::signal_getClassStudentsReq(QString _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void menu_Teacher::signal_getClassesReq()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void menu_Teacher::signal_addQuestionReq(QJsonObject _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void menu_Teacher::signal_publishExamReq(QJsonObject _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1);
}

// SIGNAL 5
void menu_Teacher::signal_getClassExamsReq(QString _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 5, nullptr, _t1);
}

// SIGNAL 6
void menu_Teacher::signal_getExamScoresReq(QString _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 6, nullptr, _t1);
}

// SIGNAL 7
void menu_Teacher::signal_logoutReq()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}
QT_WARNING_POP
