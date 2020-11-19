#include <QCoreApplication>

#include "../../produit.h"
#include "../../producteur.h"
#include "../../Outils/idGenerator.h"
#include "../../GestionnairesDeDialogue/dialogueProducteurs.h"

#include <iostream>
using namespace std;


int main(int argc, char *argv[])
{
    DialogueProducteurs dp = DialogueProducteurs();
    Producteur pr1 = Producteur(dp);

    pr1.demanderAjoutProduit(10,5.5,"courgettes","courgettes.jpg");
    pr1.demanderAjoutProduit(25,2.285,"tomates","tomates.jpg");

    cout<<"Ajout de 2 produit dans le producteur 1 " << dp.toString() <<endl;

    Producteur pr2 = Producteur(dp);
    pr2.demanderAjoutProduit(10,5.5,"courgettes","courgettes.jpg");

    cout <<"Ajout d'un producteur et ajout d'un produit dans celui ci "<<  dp.toString() <<endl;

    pr1.demanderRetirerProduit(2);


    cout <<"On retire le produit du producteur 2"<< dp.toString() <<endl;

    pr1.demanderRetirerProduit(2);

    cout <<"On demande de retirer un produit introuvable dans le producteur 1"<< dp.toString() <<endl;

    pr1.demanderAjoutProduit(25,2.285,"tomates","");

    cout <<"On demande d'ajouter un produit sans imagePath"<< dp.toString() <<endl;

    pr1.demanderAjoutProduit(25,-0.5,"tomates","tomates.jpg");

    cout <<"On demande l'ajout d'un produit au prix négatif"<< dp.toString() <<endl;

    pr1.demanderAjoutProduit(0,2.285,"tomates","tomates.jpg");

    cout <<"On demande l'ajout d'un produit de quantitée nul"<< dp.toString() <<endl;

    pr1.demanderAjoutProduit(0,2.285,"","tomates.jpg");

    cout <<"On demande l'ajout d'un produit de nom nul"<< dp.toString() <<endl;


    return 0;
}
