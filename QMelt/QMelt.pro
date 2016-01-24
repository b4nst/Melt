#-------------------------------------------------
#
# Project created by QtCreator 2015-05-03T11:50:51
#
#-------------------------------------------------

QT       += core qml quick widgets

greaterThan(QT_MAJOR_VERSION, 4):

TARGET = QMelt
TEMPLATE = app

CONFIG += c++11

SOURCES += \
# ableton
src/ableton/alsliveset.cpp \
src/ableton/alsaudiotrack.cpp \
src/ableton/alsmiditrack.cpp \
src/ableton/alsableton.cpp \
src/ableton/alstrackdelay.cpp \
src/ableton/alstrack.cpp \
src/ableton/alsname.cpp \
src/ableton/alsdevicechain.cpp \
src/ableton/alsmastertrack.cpp \
src/ableton/alsreturntrack.cpp \
src/ableton/alsmasterchain.cpp \
src/ableton/alsmainsequencer.cpp \
src/ableton/alsclipslot.cpp \
src/ableton/alsinnerclipslot.cpp \
src/ableton/alsclipslotvalue.cpp \
src/ableton/alsmidiclip.cpp \
src/ableton/alsfactory.cpp \
src/ableton/alsgrouptrack.cpp \
# app
src/app/main.cpp\
src/app/meltapplication.cpp \
src/app/meltcommandline.cpp \
src/app/melt.cpp\
# diff
src/diff/diffengine.cpp \
# io
src/io/alsfilesystem.cpp \
src/io/alstextstream.cpp \
# parser
src/parser/xmlobject.cpp \
src/parser/xmlcontext.cpp \
src/parser/xmlcontenthandler.cpp \
src/parser/corexmlparser.cpp \
src/parser/alsxmlcontenthandler.cpp \
src/test/melttestcore.cpp

HEADERS  += \
# ableton
src/ableton/alsliveset.h \
src/ableton/alsaudiotrack.h \
src/ableton/alsmiditrack.h \
src/ableton/abletonobject.h \
src/ableton/alsableton.h \
src/ableton/alstrack.h \
src/ableton/alsname.h \
src/ableton/alsdevicechain.h \
src/ableton/alsfactory.h \
src/ableton/alstrackdelay.h \
src/ableton/alsmastertrack.h \
src/ableton/alsreturntrack.h \
src/ableton/alsgrouptrack.h \
src/ableton/alsmasterchain.h \
src/ableton/alsmainsequencer.h \
src/ableton/alsclipslot.h \
src/ableton/alsinnerclipslot.h \
src/ableton/alsclipslotvalue.h \
src/ableton/alsmidiclip.h \
# app
src/app/melt.h \
src/app/meltapplication.h \
src/app/meltcommandline.h \
# common
src/common/common.h \
# diff
src/diff/diffengine.h \
# io
src/io/alsfilesystem.h \
src/io/alsfilestreambase.h \
src/io/alstextstream.h \
# parser
src/parser/xmlobject.h \
src/parser/xmlcontext.h \
src/parser/xmlcontenthandler.h \
src/parser/corexmlparser.h \
src/parser/alsxmlcontenthandler.h \
# tests
src/test/melttestcore.h \
# utils
src/utils/colormap.h

RESOURCES += resources/qml.qrc \
    resources/icons.qrc
