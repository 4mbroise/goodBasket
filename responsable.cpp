#include "responsable.h"
#include "GestionnairesDeDialogue/dialogueproducteurs.h"
#include "Gestionnaire/gestionnaire.h"
#include <QDebug>
#include <iostream>
using namespace std;


Responsable::Responsable(std::string nom,std::string prenom,std::string adresse,double phone,std::string email,Gestionnaire &gestionnaire):gestionnaire(gestionnaire)
{
    this->nom=nom;
    this->prenom=prenom;
    this->adresse=adresse;
    this->phone=phone;
    this->email=email;
  //  this->estResponsable=true;
  //  this->estConsommateur=false;
    this->confirmer=false;
    this->gestionnaire.AjouteResponsable(this);
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

const int& Responsable::getId()
{
    return this->id;
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

