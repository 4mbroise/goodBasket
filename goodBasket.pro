QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Gestionnaire/gestionnaire.cpp \
    GestionnairesDeDialogue/dialogueconsommateurs.cpp \
    GestionnairesDeDialogue/dialogueproducteurs.cpp \
    Outils/idgenerator.cpp \
    Outils/sqltool.cpp \
    consommateur.cpp \
    erreur.cpp \
    livraison.cpp \
    main.cpp \
    mainwindow.cpp \
    pc.cpp \
    producteur.cpp \
    produit.cpp \
    utilisateur.cpp \
    responsable.cpp

HEADERS += \
    Gestionnaire/gestionnaire.h \
    GestionnairesDeDialogue/dialogueconsommateurs.h \
    GestionnairesDeDialogue/dialogueproducteurs.h \
    Outils/idgenerator.h \
    Outils/sqltool.h \
    consommateur.h \
    cycle.h \
    erreur.h \
    livraison.h \
    main.h \
    mainwindow.h \
    pc.h \
    producteur.h \
    produit.h \
    utilisateur.h \
    responsable.h


FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
