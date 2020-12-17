QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../../../Outils/idgenerator.cpp \
    ../../../Outils/sqltool.cpp \
    ../../../consommateur.cpp \
    ../../../livraison.cpp \
    ../../../pc.cpp \
    ../../../producteur.cpp \
    ../../../produit.cpp \
    ../../../responsable.cpp \
    ../../../utilisateur.cpp \
    ../../consommateurIG/consommateurPanel/cataloguesousig.cpp \
    ../../consommateurIG/consommateurPanel/consommateurig.cpp \
    ../../consommateurIG/consommateurPanel/livraisonsousconsommateur.cpp \
    ../../consommateurIG/consommateurPanel/produitsousconsommateur.cpp \
    ../../producteurIG/producteurPanel/producteurpanel.cpp \
    ../../producteurIG/ajouterProduitIG/widgetp.cpp \
    ../../responsableIG/fusionResponsableIG/fusionresponsableig.cpp \
    ../../responsableIG/ResponsablePanel/consommateursousig.cpp \
    ../../responsableIG/ResponsablePanel/erreursousig.cpp \
    ../../responsableIG/ResponsablePanel/livraisonsousig.cpp \
    ../../responsableIG/ResponsablePanel/producteuritemsousig.cpp \
    ../../responsableIG/ResponsablePanel/producteursousig.cpp \
    ../../responsableIG/ResponsablePanel/produitsousig.cpp \
    ../../responsableIG/ResponsablePanel/widgetresponsable.cpp \
    ../../responsableIG/formulaireCycle/formulairecycle.cpp \
    ../../responsableIG/gestionOuverturePCIG/gestionouverturepcpanel.cpp \
    connecterig.cpp \
    demanderpcig.cpp \
    inscriptionig.cpp \
    main.cpp \
    selectionig.cpp


HEADERS += \
    ../../consommateurIG/consommateurPanel/cataloguesousig.h \
    ../../consommateurIG/consommateurPanel/consommateurig.h \
    ../../consommateurIG/consommateurPanel/livraisonsousconsommateur.h \
    ../../consommateurIG/consommateurPanel/produitsousconsommateur.h \
    ../../producteurIG/producteurPanel/producteurpanel.h \
    ../../producteurIG/ajouterProduitIG/widgetp.h \
    ../../responsableIG/fusionResponsableIG/fusionresponsableig.h \
    ../../responsableIG/formulaireCycle/formulairecycle.h \
    ../../responsableIG/gestionOuverturePCIG/gestionouverturepcpanel.h \
    ../../responsableIG/ResponsablePanel/widgetresponsable.h \
    ../../responsableIG/ResponsablePanel/consommateursousig.h \
    ../../responsableIG/ResponsablePanel/erreursousig.h \
    ../../responsableIG/ResponsablePanel/livraisonsousig.h \
    ../../responsableIG/ResponsablePanel/producteuritemsousig.h \
    ../../responsableIG/ResponsablePanel/producteursousig.h \
    ../../responsableIG/ResponsablePanel/produitsousig.h \
    ../../responsableIG/ResponsablePanel/widgetresponsable.h \
    connecterig.h \
    demanderpcig.h \
    inscriptionig.h \
    selectionig.h\
    ../../../utilisateur.h\
    ../../../consommateur.h\
    ../../../producteur.h\
    ../../../produit.h\
    ../../../livraison.h\
    ../../../Outils/idgenerator.h\
    ../../../Outils/sqltool.h\
    ../../../responsable.h\


FORMS += \
    ../../consommateurIG/consommateurPanel/cataloguesousig.ui \
    ../../consommateurIG/consommateurPanel/consommateurig.ui \
    ../../consommateurIG/consommateurPanel/livraisonsousconsommateur.ui \
    ../../consommateurIG/consommateurPanel/produitsousconsommateur.ui \
    ../../consommateurIG/consommateurPanel/widget.ui \
    ../../producteurIG/producteurPanel/producteurpanel.ui \
    ../../producteurIG/ajouterProduitIG/widgetp.ui \
    ../../responsableIG/fusionResponsableIG/fusionresponsableig.ui \
    ../../responsableIG/ResponsablePanel/widgetresponsable.ui \
    ../../responsableIG/formulaireCycle/formulairecycle.ui \
    ../../responsableIG/gestionOuverturePCIG/gestionouverturepcpanel.ui \
    ../../responsableIG/ResponsablePanel/consommateursousig.ui \
    ../../responsableIG/ResponsablePanel/erreursousig.ui \
    ../../responsableIG/ResponsablePanel/livraisonsousig.ui \
    ../../responsableIG/ResponsablePanel/producteuritemsousig.ui \
    ../../responsableIG/ResponsablePanel/producteursousig.ui \
    ../../responsableIG/ResponsablePanel/produitsousig.ui \
    ../../responsableIG/ResponsablePanel/widgetresponsable.ui \
    connecterig.ui \
    demanderpcig.ui \
    inscriptionig.ui \
    selectionig.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

SUBDIRS += \
    ../../consommateurIG/consommateurPanel/consommateurPanel.pro
