QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    ../gestionOuverturePCIG/gestionouverturepcpanel.cpp \
    ../ResponsablePanel/erreursousig.cpp \
    ../ResponsablePanel/consommateursousig.cpp \
        ../ResponsablePanel/livraisonsousig.cpp \
    ../ResponsablePanel/producteursousig.cpp \
    ../ResponsablePanel/produitsousig.cpp \
    ../../../pc.cpp \
    ../../../utilisateur.cpp \
    ../../../responsable.cpp \
    ../formulaireCycle/formulairecycle.cpp \
    ../../../Outils/sqltool.cpp \
    ../ResponsablePanel/widget.cpp \
    fusionresponsableig.cpp

HEADERS += \
    ../../../pc.h \
    ../gestionOuverturePCIG/gestionouverturepcpanel.h \
    ../ResponsablePanel/erreursousig.h \
    ../ResponsablePanel/consommateursousig.h \
        ../ResponsablePanel/livraisonsousig.h \
    ../ResponsablePanel/producteursousig.h \
    ../ResponsablePanel/produitsousig.h \
    ../../../utilisateur.h \
    ../../../responsable.h \
    ../../../Outils/sqltool.h \
    ../formulaireCycle/formulairecycle.h \
    ../ResponsablePanel/widget.h \
    fusionresponsableig.h

FORMS += \
    ../formulaireCycle/formulairecycle.ui \
    ../ResponsablePanel/consommateursousig.ui \
    ../ResponsablePanel/livraisonsousig.ui \
    ../gestionOuverturePCIG/gestionouverturepcpanel.ui \
    ../ResponsablePanel/widget.ui \
    ../ResponsablePanel/producteursousig.ui \
    ../ResponsablePanel/erreursousig.ui \
    ../ResponsablePanel/produitsousig.ui \
    fusionresponsableig.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
