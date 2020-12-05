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

const std::string Produit::toString()
{
    std::string returned = "Produit [ID-"+std::to_string(this->getId())+"] : ";
    returned = returned.append(this->getNom().toStdString()+", ");
    returned = returned.append(std::to_string(this->getPrix())+"€ ");
    returned = returned.append("("+ std::to_string(this->getQuantite()) +"kg) ");

    return returned;
}

void Produit::setPrix(double prix)
{
    this->prix = prix;
}

Produit::~Produit()
{

}
