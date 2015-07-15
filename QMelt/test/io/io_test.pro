#-------------------------------------------------
#
# Project created by QtCreator 2015-07-15T18:13:51
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_io
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

#Test sources
SOURCES += src/alsfilesystemtest.cpp

#Testing sources
SOURCES += ../../src/io/alsfilesystem.cpp \
           ../../src/io/alstextstream.cpp \

HEADERS += ../../src/io/alsfilesystem.h \
           ../../src/io/alstextstream.h \
    src/alsfilesystemtest.h

DEFINES += SRCDIR=\\\"$$PWD/src\\\"
