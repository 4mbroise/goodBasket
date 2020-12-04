#include <QtDebug>
#include "gestionnaire.h"
#include "../GestionnairesDeDialogue/dialogueproducteurs.h"
#include "../responsable.h"

#include <iostream>
using namespace std;


Gestionnaire::Gestionnaire(DialogueProducteurs &dp):gestionnaireDialogueProducteur(dp)
{
    /*gestion fabrique tous les gestionnaireDialogue*/
    gestionnaireDialogueProducteur=dp;
    this->montantPayement=0;
    qDebug() << "Creation Gestionnaire " <<endl;
}

void Gestionnaire::CalculerMontantPayement(int producteurID)
{
    // à compléter
    cout << "payer prodcuteur ID :" << producteurID << endl;
    this->montantPayement=1000;
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

void Gestionnaire::NotifierResponsable()
{
    cout << "payment reussi" << endl;
}

