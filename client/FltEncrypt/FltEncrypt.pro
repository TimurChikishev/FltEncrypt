QT += core gui quick quickcontrols2

SOURCES += \
        ui/app/appcore.cpp \
        domain/driver/drivercontroller.cpp \
        app/main.cpp

HEADERS += \
    ui/app/appcore.h \
    domain/driver/drivercontroller.h \
    utils/utils.h

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

resources.files = main.qml
#resources.prefix = /$${TARGET}
RESOURCES += res/res.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# fltLib
win32: LIBS += -L'C:/Program Files (x86)/Windows Kits/10/Lib/10.0.19041.0/um/x64/' -lfltLib

INCLUDEPATH += 'C:/Program Files (x86)/Windows Kits/10/Lib/10.0.19041.0/um/x64'
DEPENDPATH += 'C:/Program Files (x86)/Windows Kits/10/Lib/10.0.19041.0/um/x64'

win32:!win32-g++: PRE_TARGETDEPS += 'C:/Program Files (x86)/Windows Kits/10/Lib/10.0.19041.0/um/x64/fltLib.lib'

# User32
win32: LIBS += -L'C:/Program Files (x86)/Windows Kits/10/Lib/10.0.19041.0/um/x64/' -lUser32

win32:!win32-g++: PRE_TARGETDEPS += 'C:/Program Files (x86)/Windows Kits/10/Lib/10.0.19041.0/um/x64/User32.lib'

# kernel32
win32: LIBS += -L'C:/Program Files (x86)/Windows Kits/10/Lib/10.0.19041.0/um/x64/' -lkernel32

win32:!win32-g++: PRE_TARGETDEPS += 'C:/Program Files (x86)/Windows Kits/10/Lib/10.0.19041.0/um/x64/kernel32.lib'

# fltMgr
win32: LIBS += -L'C:/Program Files (x86)/Windows Kits/10/Lib/10.0.19041.0/km/x64/' -lfltMgr

INCLUDEPATH += 'C:/Program Files (x86)/Windows Kits/10/Lib/10.0.19041.0/km/x64'
DEPENDPATH += 'C:/Program Files (x86)/Windows Kits/10/Lib/10.0.19041.0/km/x64'

win32:!win32-g++: PRE_TARGETDEPS += 'C:/Program Files (x86)/Windows Kits/10/Lib/10.0.19041.0/km/x64/fltMgr.lib'

DISTFILES +=

FORMS +=


