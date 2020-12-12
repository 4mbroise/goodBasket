#include "producteur.h"
#include <QDebug>
#include <iostream>
using namespace std;

Producteur::Producteur(DialogueProducteurs &dp):gestionnaireDialogue(dp)
{
    IdGenerator& gen = IdGenerator::Instance();
    int newId = gen.getNewIdProducteur();
    this->id = newId;
    gestionnaireDialogue = dp;
    gestionnaireDialogue.ajouterProducteur(this);
};



void Producteur::demanderAjoutProduit(int quantite, double prix, std::string nom, std::string imagePath)
{
    qDebug() << "DemanderAjoutProduit" << endl;
    gestionnaireDialogue.ajouterProduit(prix, quantite, nom, imagePath, this->id);
}

void Producteur::ajouterProduit(int quantite, double prix, std::string nom, std::string imagePath)
{
    IdGenerator& gen = IdGenerator::Instance();
    int idProduit = gen.getNewIdProduit();
    Produit produitAjoute = Produit(idProduit, quantite, prix, nom, imagePath);

    boutique.insert(idProduit,produitAjoute);
}

bool Producteur::produitExiste(int idProduit)
{
    return this->boutique.contains(idProduit);
}

void Producteur::demanderRetirerProduit(int idProduit)
{
    this->gestionnaireDialogue.retirerProduit(idProduit, this->id);
}

const int& Producteur::getId()
{
    return this->id;
}

const std::string Producteur::getMessage()
{
    return this->message;
}

void Producteur::setMessage(std::string mess)
{
    this->message=mess;
}

void Producteur::retirerProduit(int idProduit)
{
    this->boutique.remove(idProduit);
}

void Producteur::setGestionnaireDialogue(DialogueProducteurs &dp)
{
    this->gestionnaireDialogue = dp;

}

void Producteur::supprimerLivraison(Livraison livraison)
{
    this->LivraisonProducteur.removeOne(livraison);
}

void Producteur::demanderRecrutement(int idResponsable,std::string demande){
    gestionnaireDialogue.recevoirDemande(this->id,idResponsable,demande);
}

QHashIterator<int,Produit> Producteur::iterator(){
    QHashIterator<int,Produit> i(this->boutique);
    return i;
}

void Producteur::operator=(const Producteur& p ){
    this->id=p.id;
    this->boutique=p.boutique;
    this->message=p.message;
    this->gestionnaireDialogue=p.gestionnaireDialogue;

}

const std::string  Producteur::toString()
{
    std::string returned = "Producteur [ID-"+std::to_string(this->getId())+"]\n";
    QHashIterator<int,Produit> i=this->iterator();
    while(i.hasNext())
    {
        i.next();
        returned.append("      -(key = "+std::to_string(i.key())+")- ");
        Produit pr= i.value();
        returned.append(pr.toString()+"\n");
    }

    return returned;
}


