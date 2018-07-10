#-------------------------------------------------
#
# Project created by QtCreator 2015-11-25T16:24:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Calc
TEMPLATE = app
CONFIG += c++11

static { # everything below takes effect with CONFIG ''= static
 CONFIG += static
 CONFIG += staticlib # this is needed if you create a static library, not a static executable
 DEFINES += STATIC
 message("~~~ static build ~~~") # this is for information, that the static build is done
 win32: TARGET = $$join(TARGET,,,s) #this adds an s in the end, so you can seperate static build from
    #non static build
}

SOURCES += main.cpp\
        calc.cpp \
    playableclasses.cpp

HEADERS  += calc.hh \
    playableclasses.hh

FORMS    += calc.ui
