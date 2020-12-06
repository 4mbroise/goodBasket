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
    this->montantRemboursement=0;
    qDebug() << "Creation Gestionnaire " <<endl;
}

void Gestionnaire::CalculerMontantPayement(int responsableID, int producteurID)
{
    // à compléter maintenant on directement parameter 1000
    this->montantPayement=1000;
    cout << "Calculer doit payer prodcuteur ID :" << producteurID << " "<< this->montantPayement << endl;

    if(VerifierMontant(producteurID,this->montantPayement))
    {
        //renvoie à responsable par interface graphique maintenant on directement parameter oui
        if(1){
            this->responsables.value(responsableID)->Confirmer();
        }
    }
}

void Gestionnaire::AjouteResponsable(Responsable* respons)
{
    responsables.insert(respons->getId(),respons);
}


bool Gestionnaire::VerifierMontant(int ProducteurID, int montant)
{
    qDebug() << " Verfier le montant" << endl;

    if(this->gestionnaireDialogueProducteur.producteurExiste(ProducteurID) && montant>0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Gestionnaire::Payer(int responsableID, int producteurID)
{
    //à compléter
    //sql si besoin
    std::string s="Gesionnaire payer :" + to_string(producteurID) + " " + to_string(this->montantPayement);
    cout << s << endl;
    this->responsables.value(responsableID)->RecevoirMessage(s);
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

bool Gestionnaire::VerifeirRemboursement(int consommateurID)
{
    /* condition de verification directement oui maintenant*/
    if(1){
        /* le parametrer plus tard*/
        this->montantRemboursement=1000;
        this->erreur.AjouterErreur("manque chou rouge");
        return true;
    }

    return false;
}

void Rembourser()
{
    /* reste à compléter*/
    /*NotifierResponsable();*/
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

