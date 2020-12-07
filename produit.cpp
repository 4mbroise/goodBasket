#include "produit.h"


Produit::Produit(int id, int q, double prix, std::string nom, std::string imagePath)
{
    this->nom = QString(nom.c_str());
    this->id = id;
    this->image = QImage(imagePath.c_str());
    this->prix = prix;
    this->quantite = q;
}


const int& Produit::getId()
{
    return this->id;
}

const int& Produit::getQuantite()
{
    return this->quantite;
}

const double& Produit::getPrix()
{
    return this->prix;
}

const QString& Produit::getNom()
{
    return this->nom;
}

const QImage& Produit::getImage()
{
    return this->image;
}

void Produit::operator=(const Produit& pd){
    this->id=pd.id;
    this->nom=pd.nom;
    this->prix=pd.prix;
    this->image=pd.image;
    this->quantite=pd.quantite;
}

void Produit::setPrix(double prix)
{
    this->prix = prix;
}

bool Produit::operator==(const Produit &p){
    return this->id==p.id;
}

void Produit::baisserQuantite(int q){
    this->quantite=quantite-q;
}

void Produit::augmenterQuantite(int q){
    this->quantite=quantite+q;
}
const std::string Produit::toString()
{
    std::string returned = "Produit [ID-"+std::to_string(this->getId())+"] : ";
    returned = returned.append(this->getNom().toStdString()+", ");
    returned = returned.append(std::to_string(this->getPrix())+"€ ");
    returned = returned.append("("+ std::to_string(this->getQuantite()) +"kg) ");

    return returned;
}



