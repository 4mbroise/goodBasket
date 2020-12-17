QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    ../../../Outils/sqltool.cpp \
    ../../../utilisateur.cpp \
    ../../../pc.cpp \
    ../../../responsable.cpp \
    ../../../producteur.cpp \
    ../../../produit.cpp \
    ../formulaireCycle/formulairecycle.cpp \
    ../../../Outils/idgenerator.cpp \
    gestionouverturepcpanel.cpp

HEADERS += \
    ../../../Outils/sqltool.h \
    ../../../utilisateur.h \
    ../../../pc.h \
    ../../../responsable.h \
    ../../../producteur.h \
    ../../../produit.h \
    ../formulaireCycle/formulairecycle.h \
    ../../../Outils/idgenerator.h \
    gestionouverturepcpanel.h

FORMS += \
    ../formulaireCycle/formulairecycle.ui \
    gestionouverturepcpanel.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
