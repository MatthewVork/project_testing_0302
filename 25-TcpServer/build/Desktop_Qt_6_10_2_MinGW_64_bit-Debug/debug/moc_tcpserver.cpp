/****************************************************************************
** Meta object code from reading C++ file 'tcpserver.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../tcpserver.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tcpserver.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN9TcpServerE_t {};
} // unnamed namespace

template <> constexpr inline auto TcpServer::qt_create_metaobjectdata<qt_meta_tag_ZN9TcpServerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "TcpServer",
        "new_client",
        "",
        "read_data",
        "on_startBtn_clicked",
        "on_clearSendBtn_clicked",
        "on_clearRecvBtn_clicked",
        "on_sendBtn_clicked",
        "handleRegister",
        "QTcpSocket*",
        "socket",
        "QJsonObject",
        "data",
        "handleLogin",
        "handleJoinExam",
        "handleGetPaper",
        "handleSubmitExam",
        "handleGetScores",
        "handleChangePwd",
        "handleLogout",
        "handleCreateClass",
        "handleGetClasses",
        "handleJoinClass",
        "handleGetMyClasses",
        "init_Database"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'new_client'
        QtMocHelpers::SlotData<void()>(1, 2, QMC::AccessProtected, QMetaType::Void),
        // Slot 'read_data'
        QtMocHelpers::SlotData<void()>(3, 2, QMC::AccessProtected, QMetaType::Void),
        // Slot 'on_startBtn_clicked'
        QtMocHelpers::SlotData<void()>(4, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_clearSendBtn_clicked'
        QtMocHelpers::SlotData<void()>(5, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_clearRecvBtn_clicked'
        QtMocHelpers::SlotData<void()>(6, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_sendBtn_clicked'
        QtMocHelpers::SlotData<void()>(7, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'handleRegister'
        QtMocHelpers::SlotData<void(QTcpSocket *, const QJsonObject &)>(8, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 9, 10 }, { 0x80000000 | 11, 12 },
        }}),
        // Slot 'handleLogin'
        QtMocHelpers::SlotData<void(QTcpSocket *, const QJsonObject &)>(13, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 9, 10 }, { 0x80000000 | 11, 12 },
        }}),
        // Slot 'handleJoinExam'
        QtMocHelpers::SlotData<void(QTcpSocket *, const QJsonObject &)>(14, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 9, 10 }, { 0x80000000 | 11, 12 },
        }}),
        // Slot 'handleGetPaper'
        QtMocHelpers::SlotData<void(QTcpSocket *, const QJsonObject &)>(15, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 9, 10 }, { 0x80000000 | 11, 12 },
        }}),
        // Slot 'handleSubmitExam'
        QtMocHelpers::SlotData<void(QTcpSocket *, const QJsonObject &)>(16, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 9, 10 }, { 0x80000000 | 11, 12 },
        }}),
        // Slot 'handleGetScores'
        QtMocHelpers::SlotData<void(QTcpSocket *, const QJsonObject &)>(17, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 9, 10 }, { 0x80000000 | 11, 12 },
        }}),
        // Slot 'handleChangePwd'
        QtMocHelpers::SlotData<void(QTcpSocket *, const QJsonObject &)>(18, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 9, 10 }, { 0x80000000 | 11, 12 },
        }}),
        // Slot 'handleLogout'
        QtMocHelpers::SlotData<void(QTcpSocket *, const QJsonObject &)>(19, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 9, 10 }, { 0x80000000 | 11, 12 },
        }}),
        // Slot 'handleCreateClass'
        QtMocHelpers::SlotData<void(QTcpSocket *, const QJsonObject &)>(20, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 9, 10 }, { 0x80000000 | 11, 12 },
        }}),
        // Slot 'handleGetClasses'
        QtMocHelpers::SlotData<void(QTcpSocket *, const QJsonObject &)>(21, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 9, 10 }, { 0x80000000 | 11, 12 },
        }}),
        // Slot 'handleJoinClass'
        QtMocHelpers::SlotData<void(QTcpSocket *, const QJsonObject &)>(22, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 9, 10 }, { 0x80000000 | 11, 12 },
        }}),
        // Slot 'handleGetMyClasses'
        QtMocHelpers::SlotData<void(QTcpSocket *, const QJsonObject &)>(23, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 9, 10 }, { 0x80000000 | 11, 12 },
        }}),
        // Slot 'init_Database'
        QtMocHelpers::SlotData<bool()>(24, 2, QMC::AccessPrivate, QMetaType::Bool),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<TcpServer, qt_meta_tag_ZN9TcpServerE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject TcpServer::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9TcpServerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9TcpServerE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN9TcpServerE_t>.metaTypes,
    nullptr
} };

void TcpServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<TcpServer *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->new_client(); break;
        case 1: _t->read_data(); break;
        case 2: _t->on_startBtn_clicked(); break;
        case 3: _t->on_clearSendBtn_clicked(); break;
        case 4: _t->on_clearRecvBtn_clicked(); break;
        case 5: _t->on_sendBtn_clicked(); break;
        case 6: _t->handleRegister((*reinterpret_cast<std::add_pointer_t<QTcpSocket*>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QJsonObject>>(_a[2]))); break;
        case 7: _t->handleLogin((*reinterpret_cast<std::add_pointer_t<QTcpSocket*>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QJsonObject>>(_a[2]))); break;
        case 8: _t->handleJoinExam((*reinterpret_cast<std::add_pointer_t<QTcpSocket*>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QJsonObject>>(_a[2]))); break;
        case 9: _t->handleGetPaper((*reinterpret_cast<std::add_pointer_t<QTcpSocket*>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QJsonObject>>(_a[2]))); break;
        case 10: _t->handleSubmitExam((*reinterpret_cast<std::add_pointer_t<QTcpSocket*>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QJsonObject>>(_a[2]))); break;
        case 11: _t->handleGetScores((*reinterpret_cast<std::add_pointer_t<QTcpSocket*>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QJsonObject>>(_a[2]))); break;
        case 12: _t->handleChangePwd((*reinterpret_cast<std::add_pointer_t<QTcpSocket*>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QJsonObject>>(_a[2]))); break;
        case 13: _t->handleLogout((*reinterpret_cast<std::add_pointer_t<QTcpSocket*>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QJsonObject>>(_a[2]))); break;
        case 14: _t->handleCreateClass((*reinterpret_cast<std::add_pointer_t<QTcpSocket*>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QJsonObject>>(_a[2]))); break;
        case 15: _t->handleGetClasses((*reinterpret_cast<std::add_pointer_t<QTcpSocket*>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QJsonObject>>(_a[2]))); break;
        case 16: _t->handleJoinClass((*reinterpret_cast<std::add_pointer_t<QTcpSocket*>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QJsonObject>>(_a[2]))); break;
        case 17: _t->handleGetMyClasses((*reinterpret_cast<std::add_pointer_t<QTcpSocket*>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QJsonObject>>(_a[2]))); break;
        case 18: { bool _r = _t->init_Database();
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QTcpSocket* >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QTcpSocket* >(); break;
            }
            break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QTcpSocket* >(); break;
            }
            break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QTcpSocket* >(); break;
            }
            break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QTcpSocket* >(); break;
            }
            break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QTcpSocket* >(); break;
            }
            break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QTcpSocket* >(); break;
            }
            break;
        case 13:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QTcpSocket* >(); break;
            }
            break;
        case 14:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QTcpSocket* >(); break;
            }
            break;
        case 15:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QTcpSocket* >(); break;
            }
            break;
        case 16:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QTcpSocket* >(); break;
            }
            break;
        case 17:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QTcpSocket* >(); break;
            }
            break;
        }
    }
}

const QMetaObject *TcpServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TcpServer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9TcpServerE_t>.strings))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int TcpServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    }
    return _id;
}
QT_WARNING_POP
