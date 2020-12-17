QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../../../produit.cpp \
    ../../../producteur.cpp \
    ../../../livraison.cpp \
    ../../../utilisateur.cpp \
    ../../../Outils/idGenerator.cpp \
    ../../../Outils/sqltool.cpp \
    ../../../GestionnairesDeDialogue/dialogueProducteurs.cpp \
    main.cpp \
    Widgetp.cpp

HEADERS += \
    ../../../produit.h \
    ../../../producteur.h \
    ../../../livraison.h \
    ../../../utilisateur.h \
    ../../../Outils/sqltool.h \
    ../../../Outils/idGenerator.h \
    ../../../GestionnairesDeDialogue/dialogueProducteurs.h \
    Widgetp.h

FORMS += \
    Widgetp.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
