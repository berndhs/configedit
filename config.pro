# qmake .pro file

TEMPLATE = app
TARGET = cfgedit

QT += gui quick widgets
QT -= dbus

CONFIG += c++11

OBJECTS_DIR = obj
MOC_DIR = tmp
UI_DIR = tmp
RCC_DIR = tmp

RESOURCES = config.qrc


INCLUDEPATH += include/

HEADERS = \
  include/agpl2.h \
  include/main.h \
    include/version.h \
    include/agpl2.h \
    include/deliberate.h \
    include/config-edit.h \
    include/cmdoptions.h \
    include/editor.h \
    include/configview.h

SOURCES = \
  src/main.cpp \
    src/version.cpp \
    src/deliberate.cpp \
    src/config-edit.cpp \
    src/cmdoptions.cpp \
    src/editor.cpp \
    src/configview.cpp
