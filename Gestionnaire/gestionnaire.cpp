#include <QtDebug>
#include "gestionnaire.h"
#include "../GestionnairesDeDialogue/dialogueproducteurs.h"
#include "../GestionnairesDeDialogue/dialogueconsommateurs.h"
#include "../responsable.h"

#include <iostream>
using namespace std;


Gestionnaire::Gestionnaire(DialogueProducteurs &dp,Erreur &e, DialogueConsommateurs &dc):gestionnaireDialogueProducteur(dp), erreur(e), gestionnaireDialogueConsommateur(dc)
{
    /*gestion fabrique tous les gestionnaireDialogue*/
    this->montantPayement=0;
    this->montantRemboursement=0;
    qDebug() << "Creation Gestionnaire " <<endl;
}

void Gestionnaire::CalculerMontantPayement(int responsableID, int producteurID)
{
    // à compléter, maintenant on directement parameter 1000
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
    //à compléter, sql
    std::string s="Gesionnaire payer :" + to_string(producteurID) + " " + to_string(this->montantPayement);
    cout << s << endl;
    this->responsables.value(responsableID)->RecevoirMessage(s);
    this->gestionnaireDialogueProducteur.notifierProducteurPayment(producteurID,this->montantPayement);
}

void Gestionnaire::NotifierDialogueProducteur(int producteurID)
{
    this->gestionnaireDialogueProducteur.notifierProducteurPayment(producteurID, this->montantPayement);
}

void Gestionnaire::NotifierResponsable(int responsableID,std::string s)
{
    this->responsables.value(responsableID)->RecevoirMessage(s);
}

bool Gestionnaire::VerifierErreur()
{
    if(this->erreur.nbErreur()>0){
        return true;
    }else{
        return false;
    }
}

bool Gestionnaire::VerifeirRemboursement(int consommateurID,int responsableId)
{
    /* condition de verification directement oui maintenant*/
    if(1){
        /* le parametrer plus tard*/
        this->montantRemboursement=1000;
        // ecrire des manques
        std::string s=this->erreur.toString();
        this->responsables.value(responsableId)->RecevoirMessage(s);
        this->gestionnaireDialogueConsommateur.notifierConsommateur(consommateurID,s);
        this->responsables.value(responsableId)->Confirmer();
        return true;
    }

    return false;
}

void Gestionnaire::Rembourser(int consommateurId,int responsableId)
{
    /* reste à compléter dans sql*/
    std::string s="payer 1000 euro";
   NotifierResponsable(responsableId,s);
}

void Gestionnaire::NotifierErreur(int responsableID)
{
    if(VerifierErreur()){
        NotifierResponsable(responsableID,this->erreur.toString());
    }else{
        cout << "rien affichier" << endl;
    }
}

