#-------------------------------------------------
#
# Project created by QtCreator 2015-03-10T08:22:42
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = task_1
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

INCLUDEPATH += C:\\opencv-2.3.1\\opencv-2.3.1_build\\install\\include
INCLUDEPATH += C:\\opencv-2.3.1\\opencv-2.3.1_build\\install\\include\\opencv

LIBS += C:\\opencv-2.3.1\\opencv-2.3.1_build\\install\\lib\\libopencv_calib3d231d.dll.a
LIBS += C:\\opencv-2.3.1\\opencv-2.3.1_build\\install\\lib\\libopencv_contrib231d.dll.a
LIBS += C:\\opencv-2.3.1\\opencv-2.3.1_build\\install\\lib\\libopencv_core231d.dll.a
LIBS += C:\\opencv-2.3.1\\opencv-2.3.1_build\\install\\lib\\libopencv_features2d231d.dll.a
LIBS += C:\\opencv-2.3.1\\opencv-2.3.1_build\\install\\lib\\libopencv_flann231d.dll.a
LIBS += C:\\opencv-2.3.1\\opencv-2.3.1_build\\install\\lib\\libopencv_gpu231d.dll.a
LIBS += C:\\opencv-2.3.1\\opencv-2.3.1_build\\install\\lib\\libopencv_highgui231d.dll.a
LIBS += C:\\opencv-2.3.1\\opencv-2.3.1_build\\install\\lib\\libopencv_imgproc231d.dll.a
LIBS += C:\\opencv-2.3.1\\opencv-2.3.1_build\\install\\lib\\libopencv_legacy231d.dll.a
LIBS += C:\\opencv-2.3.1\\opencv-2.3.1_build\\install\\lib\\libopencv_ml231d.dll.a
LIBS += C:\\opencv-2.3.1\\opencv-2.3.1_build\\install\\lib\\libopencv_objdetect231d.dll.a
LIBS += C:\\opencv-2.3.1\\opencv-2.3.1_build\\install\\lib\\libopencv_ts231d.a
LIBS += C:\\opencv-2.3.1\\opencv-2.3.1_build\\install\\lib\\libopencv_video231d.dll.a

SOURCES += main.cpp \
    barcodedetector.cpp

HEADERS += \
    barcodedetector.h
