#include <QCoreApplication>

#include "../../produit.h"
#include "../../producteur.h"
#include "../../Outils/idGenerator.h"
#include "../../GestionnairesDeDialogue/dialogueProducteurs.h"

#include <iostream>
using namespace std;


int main(int argc, char *argv[])
{
    Producteur pr = Producteur();

    DialogueProducteurs& dialoguePr = DialogueProducteurs::Instance();
    if(dialoguePr.producteurExiste(pr.getId()))
    {
        cout << "prod ajoutazeatr" <<endl;
    }

    pr.demanderAjoutProduit(10,5.5,"courgettes","courgettes.jpg");


    cout <<"PRINTF DANS MAIN:\n"+ pr.toString() <<endl;

    return 0;
}
