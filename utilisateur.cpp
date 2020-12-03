#include "Utilisateur.h"
#include <QDebug>
#include <iostream>

Utilisateur::Utilisateur(std::string nom,std::string prenom,std::string adresse,double phone)
{
    IdGenerator& gen = IdGenerator::Instance();
    int newId = gen.getNewIdProducteur();
    this->id = newId;
    this->nom = QString(nom.c_str());
    this->prenom =QString(prenom.c_str());
    this->adresse=QString(adresse.c_str());
    this->phone = phone;

}

const int& Utilisateur::getId()
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
    returned = returned.append("("+ std::to_string(this->getQuantite()) +"kg), ");

    return returned;
}

void Produit::setPrix(double prix)
{
    this->prix = prix;
}

Produit::~Produit()
{

}
