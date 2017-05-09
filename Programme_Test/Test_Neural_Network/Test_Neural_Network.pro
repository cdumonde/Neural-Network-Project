#-------------------------------------------------
#
# Project created by QtCreator 2017-04-11T15:09:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Test_Neural_Network
TEMPLATE = app
CONFIG += c++11

SOURCES += main.cpp\
	    mainwindow.cpp \
	    fonctions.cpp \
	    Sources/Data.cpp \
	    Sources/Network.cpp \
	    Sources/Neuron.cpp \
	    Sources/Neuron_Linear.cpp \
	    Sources/Neuron_Sigmoid.cpp \
	    Sources/Neuron_Step.cpp

HEADERS  += mainwindow.h \
	    fonctions.h \
	    Sources/Data.h \
	    Sources/Network.h \
	    Sources/Neuron.h \
	    Sources/Neuron_Linear.h \
	    Sources/Neuron_Sigmoid.h \
	    Sources/Neuron_Step.h

FORMS    += mainwindow.ui

INCLUDEPATH += /usr/local/include/opencv2
LIBS += -L/usr/local/lib \
-lopencv_core \
-lopencv_imgproc \
-lopencv_imgcodecs \
-lopencv_highgui \
-lopencv_ml \
-lopencv_video \
-lopencv_features2d \
-lopencv_calib3d \
-lopencv_objdetect \
-lopencv_flann
