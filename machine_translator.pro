TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    translator.cpp

HEADERS += \
    translator.h


QMAKE_CXXFLAGS += -std=c++17
