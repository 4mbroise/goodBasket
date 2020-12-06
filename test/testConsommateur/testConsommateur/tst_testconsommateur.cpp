#include <QtTest>
#include <QCoreApplication>
#include "../../../producteur.h"
#include "../../../producteur.cpp"
#include "../../../produit.h"
#include "../../../produit.cpp"
#include "../../../pc.h"
#include "../../../pc.cpp"
#include "../../../livraison.h"
#include "../../../livraison.cpp"
#include "../../../consommateur.h"
#include "../../../consommateur.cpp"
#include "../../../GestionnairesDeDialogue/dialogueconsommateurs.h"
#include "../../../GestionnairesDeDialogue/dialogueconsommateurs.cpp"
#include "../../../Outils/idgenerator.h"
// add necessary includes here

class testConsommateur : public QObject
{
    Q_OBJECT

public:
    testConsommateur();
    ~testConsommateur();

private slots:
    void test_case1();
    void test_supprimer();
};

testConsommateur::testConsommateur()
{

}

testConsommateur::~testConsommateur()
{

}

void testConsommateur::test_case1()
{

}

void testConsommateur::test_supprimer()
{
   Produit p(1,10,50,"carrot","..");
   DialogueConsommateurs dc;
   Consommateur c("Abricot","Bill","Nord",03,"gmail",dc);
   c.demanderAjouter(p,5);
   QVERIFY(c.getPanier().size()==1);
   c.demanderSupprimerProduit(p);
   QVERIFY(c.getPanier().size()==0);
}



QTEST_APPLESS_MAIN(testConsommateur)

#include "tst_testconsommateur.moc"
