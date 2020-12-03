QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    GestionnairesDeDialogue/dialogueconsommateur.cpp \
    GestionnairesDeDialogue/dialoguepc.cpp \
    GestionnairesDeDialogue/dialogueproducteurs.cpp \
    Outils/idgenerator.cpp \
    consommateur.cpp \
    consommateur.cpp \
    livraison.cpp \
    main.cpp \
    mainwindow.cpp \
    pc.cpp \
    producteur.cpp \
    produit.cpp \
    utilisateur.cpp

HEADERS += \
    GestionnairesDeDialogue/dialogueconsommateur.h \
    GestionnairesDeDialogue/dialoguepc.h \
    GestionnairesDeDialogue/dialogueproducteurs.h \
    Outils/idgenerator.h \
    consommateur.h \
    livraison.h \
    mainwindow.h \
    pc.h \
    producteur.h \
    produit.h \
    responsable.h \
    utilisateur.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
