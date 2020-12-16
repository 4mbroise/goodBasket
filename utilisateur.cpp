#include "utilisateur.h"
#include <QDebug>
#include <iostream>

Utilisateur::Utilisateur(QString nom,QString prenom,QString adresse,QString phone,QString email)
{
    IdGenerator& gen = IdGenerator::Instance();
    int newId = gen.getNewIdUtilisateur();
    this->id = newId;
    this->nom = nom;
    this->prenom =prenom;
    this->adresse=adresse;
    this->phone = phone;
    this->email =email;
    estResponsable=false;
    estConsommateur=false;
    cout << "Utilisateur est créé" << endl;
}

/*Utilisateur::Utilisateur(int id)
{
    this->id = id;


    QString query = QString::fromStdString("SELECT nom,prenom,adresse,telephone,email,estConsommateur,estResponsable, estProducteur FROM Utilisateurs WHERE UtilisateurID = ");
    query.append(QString::number(id));

    QSqlQuery sqlQuery;

    sqlQuery.prepare(query);

    if(!sqlQuery.exec())
    {
        qDebug() << "ERREUR SELECT utilisateur SQL" << sqlQuery.lastError();
    }
    else
    {
        sqlQuery.next();
        this->nom = sqlQuery.value(0).toString();
        this->prenom = sqlQuery.value(1).toString();
        this->adresse= sqlQuery.value(2).toString();
        this->phone = sqlQuery.value(3).toString();
        this->email = sqlQuery.value(4).toString();
        this->estConsommateur = sqlQuery.value(5).toBool();
        this->estResponsable = sqlQuery.value(6).toBool();
        this->estProducteur = sqlQuery.value(7).toBool();

        qDebug() << "SUCCESS SELECT utilisateur SQL";
    }
    cout << "Utilisateur est créé" << endl;
}*/


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



