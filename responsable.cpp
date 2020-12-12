#include "responsable.h"
#include "GestionnairesDeDialogue/dialogueproducteurs.h"
#include "Gestionnaire/gestionnaire.h"
#include <QDebug>
#include <iostream>
using namespace std;


Responsable::Responsable(std::string nom,std::string prenom,std::string adresse,double phone,std::string email,PC pc,Gestionnaire &gestionnaire):Utilisateur(nom,prenom,adresse,phone,email),gestionnaire(gestionnaire),pc(pc)
{
    this->nom=nom.c_str();
    this->prenom=prenom.c_str();
    this->adresse=adresse.c_str();
    this->phone=phone;
    this->email=email.c_str();
    this->estResponsable=true;
    this->estConsommateur=false;
    this->confirmer=false;
    this->gestionnaire.AjouteResponsable(this);
}

const int& Responsable::getId(){
    return this->id;
    qDebug()<<"get id du Responsable"<<endl;
}


const QString& Responsable::getNom(){
    return  this->nom;
    qDebug()<<"get nom du Responsable"<<endl;
}


const QString& Responsable::getPrenom(){
    return  this->prenom;
    qDebug()<<"get prenom du Responsable"<<endl;
}

const QString& Responsable::getAdresse(){
    return this->adresse;
    qDebug()<<"get adresse du Responsable"<<endl;
}

const double& Responsable::getPhone(){
    return this->phone;
    qDebug()<<"get numéro de téléphon du Responsable"<<endl;
}

const QString& Responsable::getEmail(){
    return this->email;
    qDebug()<<"get email du Responsable"<<endl;
}


void Responsable::changeNom(std::string nom){
    this->nom=QString(nom.c_str());
    qDebug()<<"changer ou setter nom du Responsable"<<endl;
}


void Responsable::changePrenom(std::string prenom){
    this->prenom=QString(prenom.c_str());
    qDebug()<<"changer ou setter prenom du Responsable"<<endl;
}


void Responsable::changeAdresse(std::string adresse){
    this->adresse=QString(adresse.c_str());
    qDebug()<<"changer ou setter adresse du Responsable"<<endl;
}

void Responsable::changePhone(double phone){
    this->phone=phone;
    qDebug()<<"changer ou setter numéro de téléphone du Responsable"<<endl;
}


void Responsable::changeEmail(std::string email){
    this->email=QString(email.c_str());
    qDebug()<<"changer ou setter email du Responsable"<<endl;
}


void Responsable::PayerProducteurs(int producteurid)
{
    this->gestionnaire.CalculerMontantPayement(this->id, producteurid);
    /* procedure que gestionnaire retourner montant confirmer ou non*/
    if(this->confirmer){
        this->gestionnaire.Payer(this->id, producteurid);
    }
    this->confirmer=false;  // reinitialiser
}

void Responsable::Confirmer()
{
    this->confirmer=true;
}

std::string Responsable::GetMessage()
{
    return this->message;
}

void Responsable::RecevoirMessage(std::string mess)
{
    this->message=mess;
}

void Responsable::ConsulterReports()
{
    this->gestionnaire.NotifierErreur(this->id);
}


PC& Responsable::getPC(){
    return  this->pc;
}

void Responsable::DemanderRembourser(int consommateurId)
{
    if(this->gestionnaire.VerifeirRemboursement(consommateurId,this->id))
    {
         qDebug()<<"attente confirmer"<<endl;
    }
    if(this->confirmer)
    {
        this->gestionnaire.Rembourser(consommateurId,this->id);
    }
}


void Responsable::demanderPC(int id,std::string villes, int codePostal, int numéro, std::string nomRue){
    gestionnaire.demanderPC(id,villes,codePostal,numéro,nomRue);
}

void Responsable::setPC(PC pc){
    this->pc=pc;
}

void Responsable::recruterProducteur(std::string recrutement){
   gestionnaire.getDialogueProducteurs().recruteProducteur(this->id,recrutement);
}

QHash<int,std::string>& Responsable::consulterDemande(){
    return  gestionnaire.getDialogueProducteurs().getDemande();
}

bool Responsable::reponseRecrutement(int idResponsable ,int idProducteur, std::string demande){
    return true;
}

void Responsable::ajouterProducteur(int idProducteur,std::string demande){
    if(reponseRecrutement(id,demande)){
        Producteur *p=gestionnaire.getDialogueProducteurs().getProducteurById(id);
        pc.ajouterProducteur(*p);
    }
}
