#include "livraison.h"
#include "Outils/idgenerator.h"
#include <QDebug>
#include <iostream>

using namespace std;


Livraison::Livraison(Produit p,int commande):produit(p){
    IdGenerator& gen = IdGenerator::Instance();
    int newId = gen.getNewIdUtilisateur();
    this->id = newId;
    this->commande=commande;
    this->produit=p;
    qDebug() << "Livraison est créé" << endl;
}
/*
Livraison::~Livraison(){
    qDebug() << "Livraison est enlevé" << endl;
}
*/
const Produit& Livraison::getProduit(){
    return this->produit;
}

const int& Livraison::getCommande(){
    return  this->commande;
}

const time_t& Livraison::getDateAchat(){
    return  this->dateAchat;
}

const time_t& Livraison::getDateLivraison(){
    return  this->dateLivraison;
}

const int& Livraison::getID(){
    return this->id;
}

void Livraison::setLivraison(Produit p,int commande){
    this->produit=p;
    this->commande=commande;
    p.baisserQuantite(commande);
}

void Livraison::setDateAchat(time_t date){
    this->dateAchat=date;
}

void Livraison::setDateLivraison(time_t date){
    this->dateLivraison=date;
}

void Livraison::ajouterCommande(int extra){
    this->commande+=extra;
    this->produit.baisserQuantite(extra);
}

bool Livraison::operator==(const Livraison &l){
    return this->produit==l.produit;
}

const std::string Livraison::toSring(){
    string resultat="Livraison: \n";
    Produit p=this->produit;
    string nom=p.getNom().toStdString();
    int id =p.getId();
    resultat.append("Produit:"+nom+"[ID-"+to_string(id)+"]\n");
    resultat.append("nombre:"+to_string(commande)+"\n");
    return resultat;
}
