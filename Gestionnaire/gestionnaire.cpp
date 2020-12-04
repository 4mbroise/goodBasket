#include <QtDebug>
#include "gestionnaire.h"
#include "../GestionnairesDeDialogue/dialogueproducteurs.h"
#include "../responsable.h"

#include <iostream>
using namespace std;


Gestionnaire::Gestionnaire(DialogueProducteurs &dp,Erreur &e):gestionnaireDialogueProducteur(dp), erreur(e)
{
    /*gestion fabrique tous les gestionnaireDialogue*/
    this->montantPayement=0;
    qDebug() << "Creation Gestionnaire " <<endl;
}

void Gestionnaire::CalculerMontantPayement(int producteurID)
{
    // à compléter
    cout << "payer prodcuteur ID :" << producteurID << endl;
    this->montantPayement=1000;
}

void Gestionnaire::AjouteResponsable(Responsable* respons)
{
  //  this->responsables.insert(respons->getId(),respons);
}


bool Gestionnaire::VerifierMontant(int ProducteurID, int montant)
{
    qDebug() << "Verfier le montant" << endl;

    if(this->gestionnaireDialogueProducteur.producteurExiste(ProducteurID) && montant>0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Gestionnaire::Payer()
{
    //à compléter
    //sql si besoin
}

void Gestionnaire::NotifierDialogueProducteur(int producteurID)
{
    this->gestionnaireDialogueProducteur.notifierProducteurPayment(producteurID, this->montantPayement);
}

void Gestionnaire::NotifierResponsable(int responsableID)
{
  //  this->responsables.value(responsableID)->RecevoirMessage("payment reussi");
  //  this->responsables.value(responsableID)->AffichierMessage();
    cout << "payment reussi" << endl;

}

bool Gestionnaire::VerifierErreur()
{
    if(this->erreur.nbErreur()>0){
        return true;
    }else{
        return false;
    }
}

void Gestionnaire::NotifierErreur(int responsableID)
{
    if(VerifierErreur()){
   //     this->responsables.value(responsableID)->RecevoirMessage(this->erreur.toString());
   //     this->responsables.value(responsableID)->AffichierMessage();
    }else{
        cout << "rien affichier" << endl;
    }
}

