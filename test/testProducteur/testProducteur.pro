QT += core sql

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp \
        ../../Producteur.cpp \
        ../../Outils/idGenerator.cpp \
        ../../livraison.cpp \
        ../../GestionnairesDeDialogue/dialogueProducteurs.cpp \
        ../../Produit.cpp

HEADERS += \
        ../../Producteur.h \
        ../../Outils/idGenerator.h \
        ../../livraison.h \
        ../../GestionnairesDeDialogue/dialogueProducteurs.h \
        ../../Produit.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
