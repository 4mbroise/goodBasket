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

    cout << "nb Producteur = " + to_string(dp.nbProducteur()) << endl;

    Producteur pr = Producteur(dp);

    pr.demanderAjoutProduit(10,5.5,"courgettes","courgettes.jpg");
    pr.demanderAjoutProduit(25,2.285,"tomates","tomates.jpg");

    cout <<"PRINTF DANS MAIN:\n"+ pr.toString() <<endl;

    cout << "nb Producteur = " + to_string(dp.nbProducteur()) << endl;


    return 0;
}
