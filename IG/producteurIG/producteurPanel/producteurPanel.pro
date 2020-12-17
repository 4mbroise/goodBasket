QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../ajouterProduitIG/Widget.cpp \
    ../../../produit.cpp \
    ../../../producteur.cpp \
    ../../../livraison.cpp \
    ../../../utilisateur.cpp \
    ../../../Outils/sqltool.cpp \
    ../../../Outils/idGenerator.cpp \
    ../../../GestionnairesDeDialogue/dialogueProducteurs.cpp \
    main.cpp \
    producteurpanel.cpp

HEADERS += \
    ../ajouterProduitIG/AjouterProduitIG.h \
    ../../../produit.h \
    ../../../producteur.h \
    ../../../livraison.h \
    ../../../utilisateur.h \
    ../../../Outils/sqltool.h \
    ../../../Outils/idGenerator.h \
    ../../../GestionnairesDeDialogue/dialogueProducteurs.h \
    ../ajouterProduitIG/Widget.h \
    producteurpanel.h

FORMS += \
    ../ajouterProduitIG/Widget.ui \
    producteurpanel.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
