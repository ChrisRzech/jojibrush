#-------------------------------------------------
#
# Project created by QtCreator 2018-10-25T22:17:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Jojibrush
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    src/main.cpp \
    src/Canvas.cpp \
    src/account.cpp \
    src/windows/login.cpp \
    src/windows/mainwindow.cpp \
    src/windows/aboutus.cpp \
    src/utils/exceptions.cpp \
    src/utils/filehandler.cpp \
    src/shapes/Shape.cpp \
    src/shapes/GeometricShape.cpp \
    src/shapes/FilledShape.cpp \
    src/shapes/Rectangle.cpp \
    src/shapes/Ellipse.cpp \
    src/shapes/Polygon.cpp \
    src/shapes/Line.cpp \
    src/shapes/Polyline.cpp \
    src/shapes/Text.cpp \
    src/menus/ShapeSelectMenu.cpp \
    src/menus/TextPropertiesMenu.cpp \
    src/menus/PropertiesMenu.cpp \
    src/menus/FillPropertiesMenu.cpp \
    src/menus/BorderPropertiesMenu.cpp

HEADERS += \
    src/Canvas.hpp \
    src/account.hpp \
    src/windows/login.hpp \
    src/windows/mainwindow.hpp \
    src/windows/aboutus.hpp \
    src/utils/exceptions.hpp \
    src/utils/filehandler.hpp \
    src/utils/constants.hpp \
    src/shapes/Shape.hpp \
    src/shapes/GeometricShape.hpp \
    src/shapes/FilledShape.hpp \
    src/shapes/Rectangle.hpp \
    src/shapes/Ellipse.hpp \
    src/shapes/Polygon.hpp \
    src/shapes/Line.hpp \
    src/shapes/Polyline.hpp \
    src/shapes/Text.hpp \
    src/menus/ShapeSelectMenu.hpp \
    src/menus/TextPropertiesMenu.hpp \
    src/menus/PropertiesMenu.hpp \
    src/menus/FillPropertiesMenu.hpp \
    src/menus/BorderPropertiesMenu.hpp

FORMS += \
    src/windows/mainwindow.ui \
    src/windows/aboutus.ui \
    src/windows/login.ui \
    src/menus/ShapeSelectMenu.ui \
    src/menus/TextPropertiesMenu.ui \
    src/menus/PropertiesMenu.ui \
    src/menus/FillPropertiesMenu.ui \
    src/menus/BorderPropertiesMenu.ui

RESOURCES += \
    res/login.qrc \
    res/global.qrc \
    res/menus.qrc
