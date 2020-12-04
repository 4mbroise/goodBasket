QT += core gui

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
DEFINES += QT_NO_DEBUG_OUTPUT QT_NO_WARNING_OUTPUT
SOURCES += \
        main.cpp \
        ../../produit.cpp \
        ../../producteur.cpp \
        ../../responsable.cpp \
        ../../Outils/idGenerator.cpp \
        ../../Gestionnaire/gestionnaire.cpp \
        ../../GestionnairesDeDialogue/dialogueProducteurs.cpp

HEADERS += \
        ../../produit.h \
        ../../producteur.h \
        ../../responsable.h \
        ../../Outils/idGenerator.h \
        ../../Gestionnaire/gestionnaire.h \
        ../../GestionnairesDeDialogue/dialogueProducteurs.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
