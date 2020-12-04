#include "Utilisateur.h"
#include <QDebug>
#include <iostream>

Utilisateur::Utilisateur(std::string nom,std::string prenom,std::string adresse,double phone,std::string email)
{
    IdGenerator& gen = IdGenerator::Instance();
    int newId = gen.getNewIdProducteur();
    this->id = newId;
    this->nom = QString(nom.c_str());
    this->prenom =QString(prenom.c_str());
    this->adresse=QString(adresse.c_str());
    this->phone = phone;
    this->email =QString(email.c_str());
    cout << "Utilisateur est créé" << endl;
}

Utilisateur::Utilisateur(){
    IdGenerator& gen = IdGenerator::Instance();
    int newId = gen.getNewIdProducteur();
    this->id = newId;
    cout << "Utilisateur est créé" << endl;
}

Utilisateur::~Utilisateur(){
    cout << "Utilisateur est enlevé" << endl;
}

const int& Utilisateur::getId(){
    return this->id;
}


const QString& Utilisateur::getNom(){
    return  this->nom;
}


const QString& Utilisateur::getPrenom(){
    return  this->prenom;
}

const QString& Utilisateur::getAdresse(){
    return this->adresse;
}

const double& Utilisateur::getPhone(){
    return this->phone;
}

const QString& Utilisateur::getEmail(){
    return this->email;
}


void Utilisateur::changeNom(std::string nom){
    this->nom=QString(nom.c_str());
}


void Utilisateur::changePrenom(std::string prenom){
    this->prenom=QString(prenom.c_str());
}


void Utilisateur::changeAdresse(std::string adresse){
    this->adresse=QString(adresse.c_str());
}

void Utilisateur::changePhone(double phone){
    this->phone=phone;
}


void Utilisateur::changeEmail(std::string email){
    this->email=QString(email.c_str());
}

