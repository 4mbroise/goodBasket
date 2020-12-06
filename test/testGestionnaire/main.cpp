#include <QCoreApplication>

#include "../../produit.h"
#include "../../producteur.h"
#include "../../erreur.h"
#include "../../responsable.h"
#include "../../utilisateur.h"
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
    Responsable res1 = Responsable("X","Y","W",12,"Z",gs1);
//    Responsable res1 = Responsable(dp);

    cout <<"On paye le producteur\n"<<endl;

    res1.PayerProducteurs(pr1.getId());

    cout <<"Responsable reçu un message\n "<< res1.GetMessage() <<endl;



    return 0;
}
