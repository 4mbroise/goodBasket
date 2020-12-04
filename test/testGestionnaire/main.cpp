#include <QCoreApplication>

#include "../../produit.h"
#include "../../producteur.h"
#include "../../erreur.h"
#include "../../Outils/idGenerator.h"
#include "../../GestionnairesDeDialogue/dialogueProducteurs.h"
#include "../../Gestionnaire/gestionnaire.h"

#include <iostream>
using namespace std;


int main(int argc, char *argv[])
{
    DialogueProducteurs dp = DialogueProducteurs();
    Erreur e =Erreur();
    Producteur pr1 = Producteur(dp);
    Gestionnaire gs1 = Gestionnaire(dp, e);
//    Responsable res1 = Responsable(dp);

    cout <<"On paye le producteur\n"<<endl;

    gs1.CalculerMontantPayement(pr1.getId());
    gs1.Payer();

    cout <<"Responsable reçu un message "<<endl;

    //gs1.NotifierResponsable();
    gs1.NotifierDialogueProducteur(pr1.getId());

     /* reste à modifier plus tard si le responsbale est complet */

    cout <<"Producteur reçu un message\n "<< pr1.getMessage() <<endl;


    return 0;
}
