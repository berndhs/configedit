# qmake .pro file

TEMPLATE = app
TARGET = cfgedit

QT += gui quick widgets

CONFIG += c++11

OBJECTS_DIR = tmp
MOC_DIR = tmp
UI_DIR = tmp

INCLUDEPATH += include/

HEADERS = \
  include/agpl.h \
  include/main.h \
    include/version.h \
    include/agpl2.h \
    include/deliberate.h \
    include/config-edit.h \
    include/cmdoptions.h \
    include/editor.h \

SOURCES = \
  src/main.cpp \
    src/version.cpp \
    src/deliberate.cpp \
    src/config-edit.cpp \
    src/cmdoptions.cpp \
    src/editor.cpp
