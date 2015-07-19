#-------------------------------------------------
#
#                  IO_TEST PROJECT
#
#\Author    Bastien Arata
#\Date      07-18-2015 12:20 AM
#\Brief     Unittest project for io namespace
#-------------------------------------------------

QT       += testlib gui declarative

TARGET = io_test

CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

include( io_test.pri )
include( ../testing_files.pri )

OBJECTS_DIR = $$PWD/build/obj
DESTDIR = $$PWD/build/bin
MOC_DIR = $$PWD/build/moc

SOURCES +=
DEFINES += SRCDIR=\\\"$$PWD/\\\"
