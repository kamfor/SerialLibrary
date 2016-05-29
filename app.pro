TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    src/serial.cpp \
    src/rs232.c \
    src/interface.cpp \
    src/buffer.cpp \
    src/handlefile.cpp

HEADERS += \
    include/serial.h \
    include/rs232.h \
    include/plot.h \
    include/interface.h \
    include/buffer.h \
    include/handlefile.h
