######################################################################
# Automatically generated by qmake (3.1) Sat Apr 4 15:21:05 2020
######################################################################

TEMPLATE = app
TARGET = graph_final
INCLUDEPATH += . \
		/usr/local/include/

# You can make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# Please consult the documentation of the deprecated API in order to know
# how to port your code away from it.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
HEADERS += controller.h edge.h graphwidget.h max_spanning.h node.h
SOURCES += controller.cpp \
           edge.cpp \
           graphwidget.cpp \
           main.cpp \
           max_spanning.cpp \
           Node.cpp
QT += core gui widgets
