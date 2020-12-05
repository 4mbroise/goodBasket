#include "consommateur.h"
#include <QDebug>
#include <iostream>

using namespace std;

Consommateur::Consommateur(string nom,string prenom,string adresse,double phone,string email,DialogueConsommateur& dc):Utilisateur(nom,prenom,adresse,phone,email),gestionnaireDialogue(dc)
{
    IdGenerator& gen = IdGenerator::Instance();
    int newId = gen.getNewIdProducteur();
    this->id = newId;
    dc.ajouterConsommateur(this);
    qDebug() << "Consommateur est créé" << endl;
}

Utilisateur::Utilisateur(){
    IdGenerator& gen = IdGenerator::Instance();
    int newId = gen.getNewIdProducteur();
    this->id = newId;
    qDebug() << "Consommateur est créé" << endl;
}

Utilisateur::~Utilisateur(){
    qDebug() << "Consommateur est enlevé" << endl;
}

const int& Utilisateur::getId(){
    return this->id;
    qDebug()<<"get id du Consommateur"<<endl;
}


const QString& Utilisateur::getNom(){
    return  this->nom;
    qDebug()<<"get nom du Consommateur"<<endl;
}


const QString& Utilisateur::getPrenom(){
    return  this->prenom;
    qDebug()<<"get prenom du Consommateur"<<endl;
}

const QString& Utilisateur::getAdresse(){
    return this->adresse;
    qDebug()<<"get adresse du Consommateur"<<endl;
}

const double& Utilisateur::getPhone(){
    return this->phone;
    qDebug()<<"get numéro de téléphon du Consommateur"<<endl;
}

const QString& Utilisateur::getEmail(){
    return this->email;
    qDebug()<<"get email du Consommateur"<<endl;
}


void Utilisateur::changeNom(std::string nom){
    this->nom=QString(nom.c_str());
    qDebug()<<"changer ou setter nom du Consommateur"<<endl;
}


void Utilisateur::changePrenom(std::string prenom){
    this->prenom=QString(prenom.c_str());
    qDebug()<<"changer ou setter prenom du Consommateur"<<endl;
}


void Utilisateur::changeAdresse(std::string adresse){
    this->adresse=QString(adresse.c_str());
    qDebug()<<"changer ou setter adresse du Consommateur"<<endl;
}

void Utilisateur::changePhone(double phone){
    this->phone=phone;
    qDebug()<<"changer ou setter numéro de téléphone du Consommateur"<<endl;
}


void Utilisateur::changeEmail(std::string email){
    this->email=QString(email.c_str());
    qDebug()<<"changer ou setter email du Consommateur"<<endl;
}

void Consommateur::consulterCatalogue(){

}

void Consommateur::demanderAjouter(Produit p,int commande){
    this->gestionnaireDialogue.ajouterPanier(p,commande,this->id);
}

void Consommateur::ajouterProduitAuPanier(Livraison l){
    this->Panier.append(l);
}

void Consommateur::demanderExtraAjouter(Produit p,int extra){
    this->gestionnaireDialogue.extraAjouter(p,extra,this->id);
}

void Consommateur::ajouterExtraAuPanier(int position,Livraison l){
    this->Panier.insert(position,l);
}

int Consommateur::nbLivraison(){
    return Panier.count();
}

int Consommateur::nbLivraisonPrevues(){
    return LivraisonPrevues.count();
}

std::string Consommateur::toString(){
    string resultat="Consommateur [ID-"+std::to_string(this->getId())+"]\n";
    resultat.append("Panier:\n");
    resultat.append("livraisons totales:"+to_string(nbLivraison()));
    for(int i=0;i<Panier.count();i++){
        Livraison l=Panier.at(i);
        resultat.append("No.:"+to_string(i)+l.toSring());
    }
    resultat.append("LivraisonPrevue:\n");
    resultat.append("livraisonPrevues totales:"+to_string(nbLivraisonPrevues()));
    for(int i=0;i<LivraisonPrevues.count();i++){
        Livraison lp=LivraisonPrevues.at(i);
        resultat.append("No.:"+to_string(i)+lp.toSring());
    }
    return resultat;
}
