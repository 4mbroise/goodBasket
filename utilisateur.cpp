#include "utilisateur.h"
#include <QDebug>
#include <iostream>

Utilisateur::Utilisateur(QString nom,QString prenom,QString adresse,QString phone,QString email,QString pass)
{
    IdGenerator& gen = IdGenerator::Instance();
    int newId = gen.getNewIdUtilisateur();
    this->id = newId;
    this->nom = nom;
    this->prenom =prenom;
    this->adresse=adresse;
    this->phone = phone;
    this->email =email;
    this->pass=pass;
    estResponsable=false;
    estConsommateur=false;
    estProducteur=false;
    cout << "Utilisateur est créé" << endl;
}

Utilisateur::Utilisateur(int id)
{
    this->id = id;
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
const QString& Utilisateur::getPhone(){
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

void Utilisateur::changePhone(std::string phone){
    this->phone=QString(phone.c_str());
}


void Utilisateur::changeEmail(std::string email){
    this->email=QString(email.c_str());
}



