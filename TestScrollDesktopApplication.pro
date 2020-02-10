QT += quick
QT += sql
QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        Database/querybuilder.cpp \
        Models/title.cpp \
        Repositories/baserepository.cpp \
        Repositories/clubsrepository.cpp \
        Repositories/connection.cpp \
        Repositories/irepository.cpp \
        Repositories/playerjourneyrepository.cpp \
        Repositories/playerrepository.cpp \
        Repositories/stadiumrepository.cpp \
        Services/clubservice.cpp \
        Services/playerservice.cpp \
        ViewModels/playerviewmodel.cpp \
        clubsviewmodel.cpp \
        main.cpp \
        test.cpp

RESOURCES += qml.qrc \
    qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    Database/querybuilder.h \
    Models/ModelsHeader.h \
    Models/basemodel.h \
    Models/club.h \
    Models/clubstaff.h \
    Models/coach.h \
    Models/imodel.h \
    Models/player.h \
    Models/playerjourney.h \
    Models/record.h \
    Models/stadium.h \
    Models/staff.h \
    Models/title.h \
    Repositories/baserepository.h \
    Repositories/clubsrepository.h \
    Repositories/connection.h \
    Repositories/irepository.h \
    Repositories/playerjourneyrepository.h \
    Repositories/playerrepository.h \
    Repositories/stadiumrepository.h \
    Services/clubservice.h \
    Services/playerservice.h \
    ViewModels/playerviewmodel.h \
    clubsviewmodel.h \
    test.h

DISTFILES += \
    ClubsView.qml \
    home.qml \
    main.qml \
    page2.qml \
    page3.qml \
    qtquickcontrols2.conf \
    soccerleague.db
