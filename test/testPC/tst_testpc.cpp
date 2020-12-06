#include <QtTest>
#include <QCoreApplication>
#include "../../pc.h"
#include "../../pc.cpp"
#include "../../producteur.h"
#include "../../producteur.cpp"
#include "../../produit.cpp"
#include "../../GestionnairesDeDialogue/dialogueproducteurs.cpp"
#include "../../Outils/idgenerator.cpp"
// add necessary includes here

class testPC : public QObject
{
    Q_OBJECT

public:
    testPC();
    ~testPC();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void case1_adresse();
    void case2_etat();
};



testPC::testPC()
{

}

testPC::~testPC()
{

}

void testPC::initTestCase()
{

}

void testPC::cleanupTestCase()
{

}

void testPC::case1_adresse()
{   
    PC pc("Nancy");
   QVERIFY(pc.getAdressePC()=="Nancy");
}



void testPC::case2_etat(){
    PC pc("Nancy");
    QVERIFY(pc.getEtat()==false);
    pc.ouvrirPC();
    QVERIFY(pc.getEtat()==true);
    pc.fermerPC();
    QVERIFY(pc.getEtat()==false);
}



QTEST_MAIN(testPC)

#include "tst_testpc.moc"
