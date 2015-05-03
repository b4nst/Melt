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

SOURCES += src/app/main.cpp\
           src/app/meltapplication.cpp \
           src/ui/mainwindow.cpp \
           src/io/alsfilesystem.cpp \
           src/io/alstextstream.cpp \           
           src/parser/xml_object.cpp \
           src/ableton/als_ableton.cpp \
           src/ableton/ableton_object.cpp \
           src/ableton/als_device_chain.cpp \
           src/ableton/als_track_delay.cpp \
           src/ableton/als_name.cpp \
           src/ableton/als_track.cpp

HEADERS  += src/ableton/als_ableton.h \
            src/app/meltapplication.h \
            src/ableton/als_ableton.h \
            src/ableton/ableton_object.h \
            src/ableton/als_device_chain.h \
            src/ableton/als_track_delay.h \
            src/ableton/als_name.h \
            src/ableton/als_track.h
            src/io/alsfilesystem.h \
            src/io/alsfilestreambase.h \
            src/io/alstextstream.h \
            src/parser/xml_object.h \
            src/ui/mainwindow.h