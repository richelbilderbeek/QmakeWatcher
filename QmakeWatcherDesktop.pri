include(QmakeWatcherConsole.pri)

INCLUDEPATH += \
    ../QmakeWatcher

SOURCES += \
    ../QmakeWatcher/qtqmakewatchermaindialog.cpp \
    ../QmakeWatcher/qtqmakewatchermenudialog.cpp

HEADERS += \
    ../QmakeWatcher/qtqmakewatchermaindialog.h \
    ../QmakeWatcher/qtqmakewatchermenudialog.h

FORMS    += \
    ../QmakeWatcher/qtqmakewatchermaindialog.ui \
    ../QmakeWatcher/qtqmakewatchermenudialog.ui
