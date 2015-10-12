#In Example 1.6 , you can see common qmake variable settings that can be helpful to
#add to all of your projects. By placing a copy of this file in a convenient location and
#adding the line include (/path/to/wherever you put/common.pri)
# required if you want to see qDebug () messages
CONFIG += debug
# place auto-generated files in "invisible" subdirectories
win32 {
MOC_DIR = _moc
UI_DIR = _ui
OBJECTS_DIR = _obj
} else {
UI_DIR = .ui
MOC_DIR = .moc
OBJECTS_DIR = .obj
}
# rules below apply to TEMPLATE=app projects only:
app {
# place executable in same folder:
DESTDIR=$$OUT_PWD
# don't place executables in an app bundle on mac os
# this also permits console apps to work on the mac
mac {
CONFIG -= app_bundle
}
# Open a console for stdin, stdout, and stderr Windows:
win32 {
CONFIG += console
}
}

