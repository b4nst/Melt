#-------------------------------------------------
#
# Project created by QtCreator 2015-05-03T11:50:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QMelt
TEMPLATE = app

CONFIG += c++14

SOURCES += src/app/meltapplication.cpp \
           src/ableton/als_ableton.cpp \
           src/app/main.cpp\
           src/io/alsfilesystem.cpp \
           src/io/alstextstream.cpp \
           src/parser/xml_object.cpp \
           src/ui/mainwindow.cpp

HEADERS  += src/ableton/als_ableton.h \
            src/app/meltapplication.h \
            src/io/alsfilesystem.h \
            src/io/alsfilestreambase.h \
            src/io/alstextstream.h \
            src/parser/xml_object.h \
            src/ui/mainwindow.h
