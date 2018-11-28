TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    complexnumber.cpp \
    fraction.cpp \
    fraction-friends.cpp \
    memories.cpp \
    mixednumber.cpp \
    mixednumber-friends.cpp \
    complexnumber-friends.cpp \
    calculator.cpp

HEADERS += \
    complexnumber.h \
    fraction.h \
    memories.h \
    mixednumber.h \
    calculator.h \
    myexception.h

DISTFILES += \
    notes.md
