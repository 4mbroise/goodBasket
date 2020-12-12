#include "consommateur.h"
#include <QDebug>
#include <iostream>

using namespace std;

Consommateur::Consommateur(string nom,string prenom,string adresse,double phone,string email,DialogueConsommateurs &dc):Utilisateur(nom,prenom,adresse,phone,email),gestionnaireDialogue(dc)){
    this->gestionnaireDialogue.ajouterConsommateur(this);
    estConsommateur=true;
    qDebug() << "Consommateur est créé" << endl;
}

/*Consommateur::Consommateur(){
    IdGenerator& gen = IdGenerator::Instance();
    int newId = gen.getNewIdProducteur();
    this->id = newId;
    qDebug() << "Consommateur est créé" << endl;
}*/

Consommateur::~Consommateur(){
    qDebug() << "Consommateur est enlevé" << endl;
}

const int& Consommateur::getId(){
    return this->id;
    qDebug()<<"get id du Consommateur"<<endl;
}


const QString& Consommateur::getNom(){
    return  this->nom;
    qDebug()<<"get nom du Consommateur"<<endl;
}


const QString& Consommateur::getPrenom(){
    return  this->prenom;
    qDebug()<<"get prenom du Consommateur"<<endl;
}

const QString& Consommateur::getAdresse(){
    return this->adresse;
    qDebug()<<"get adresse du Consommateur"<<endl;
}

const double& Consommateur::getPhone(){
    return this->phone;
    qDebug()<<"get numéro de téléphon du Consommateur"<<endl;
}

const QString& Consommateur::getEmail(){
    return this->email;
    qDebug()<<"get email du Consommateur"<<endl;
}


void Consommateur::changeNom(std::string nom){
    this->nom=QString(nom.c_str());
    qDebug()<<"changer ou setter nom du Consommateur"<<endl;
}


void Consommateur::changePrenom(std::string prenom){
    this->prenom=QString(prenom.c_str());
    qDebug()<<"changer ou setter prenom du Consommateur"<<endl;
}


void Consommateur::changeAdresse(std::string adresse){
    this->adresse=QString(adresse.c_str());
    qDebug()<<"changer ou setter adresse du Consommateur"<<endl;
}

void Consommateur::changePhone(double phone){
    this->phone=phone;
    qDebug()<<"changer ou setter numéro de téléphone du Consommateur"<<endl;
}


void Consommateur::changeEmail(std::string email){
    this->email=QString(email.c_str());
    qDebug()<<"changer ou setter email du Consommateur"<<endl;
}


const std::string Consommateur::getMessage()
{
    return this->message;
}

void Consommateur::setMessage(std::string mess)
{
    this->message=mess;
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

void Consommateur::demanderSupprimerProduit(Produit p){
    this->gestionnaireDialogue.supprimerProduit(p,this->id);
}

void Consommateur::demanderSupprimerProduit(){
    for(Livraison l:this->Panier)
    {
        this->gestionnaireDialogue.supprimerProduit(l.getProduit(),this->id);
    }
}

void Consommateur::supprimerProduit(Livraison l){
    this->Panier.removeOne(l);
}

QList<Livraison> Consommateur::getPanier(){
    return Panier;
}

int Consommateur::nbLivraison(){
    return Panier.count();
}

int Consommateur::nbLivraisonPrevues(){
    return LivraisonPrevues.count();
}

const std::string Consommateur::toString(){
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
