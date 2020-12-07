#include <QtTest>
#include <QCoreApplication>
#include <iostream>
#include <QDebug>
#include "../../../producteur.h"
#include "../../../producteur.cpp"
#include "../../../GestionnairesDeDialogue/dialogueproducteurs.cpp"
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
#include "../../../Outils/idgenerator.cpp"
#include "../../../utilisateur.cpp"
// add necessary includes here

using namespace std;

class testConsommateur : public QObject
{
    Q_OBJECT

public:
    testConsommateur();
    ~testConsommateur();

private slots:
    void case1_id();
    void case2_nom();
    void case3_prenom();
    void case4_panier();
    void case5_ajouter();
    void case6_ajouterExtra();
    void test_supprimer();
};

testConsommateur::testConsommateur()
{

}

testConsommateur::~testConsommateur()
{

}

void testConsommateur::case1_id()
{
    DialogueConsommateurs dc;
    Consommateur c("Abricot","Bill","Nord",03,"gmail",dc);
    cout<<"id:"+to_string(c.getId())<<endl;
}

void testConsommateur::case2_nom()
{
    DialogueConsommateurs dc;
    Consommateur c("Abricot","Bill","Nord",03,"gmail",dc);
    QVERIFY(c.getNom()=="Abricot");
}

void testConsommateur::case3_prenom()
{
    DialogueConsommateurs dc;
    Consommateur c("Abricot","Bill","Nord",03,"gmail",dc);
    QVERIFY(c.getPrenom()=="Bill");
}

void testConsommateur::case4_panier()
{
    DialogueConsommateurs dc;
    Consommateur c("Abricot","Bill","Nord",03,"gmail",dc);
    QVERIFY(c.nbLivraison()==0);
}

void testConsommateur::case5_ajouter()
{
    DialogueConsommateurs dc;
    Consommateur c("Abricot","Bill","Nord",03,"gmail",dc);
    Produit p(1,10,50,"carrot","..");
    c.demanderAjouter(p,5);
    QVERIFY(c.nbLivraison()==1);
    qDebug()<<p.getQuantite()<<endl;
}

void testConsommateur::case6_ajouterExtra()
{
    DialogueConsommateurs dc;
    Consommateur c("Abricot","Bill","Nord",03,"gmail",dc);
    Produit p(1,10,50,"carrot","..");
    c.demanderAjouter(p,5);
    QVERIFY(c.nbLivraison()==1);
    qDebug()<<p.getQuantite()<<endl;
    c.demanderExtraAjouter(p,3);
    qDebug()<<p.getQuantite()<<endl;
}

void testConsommateur::test_supprimer()
{
   Produit p(1,10,50,"carrot","..");
   DialogueConsommateurs dc;
   Consommateur c("Abricot","Bill","Nord",03,"gmail",dc);
   c.demanderAjouter(p,5);
   QVERIFY(c.nbLivraison()==1);
   c.demanderSupprimerProduit(p);
   QVERIFY(c.getPanier().size()==0);
}



QTEST_APPLESS_MAIN(testConsommateur)

#include "tst_testconsommateur.moc"
