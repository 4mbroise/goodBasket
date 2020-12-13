#include <QCoreApplication>
#include "../../producteur.h"

#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    DialogueProducteurs dp = DialogueProducteurs();
    Producteur pr1 = Producteur(0,dp);

    pr1.ajouterProduitBDD(48,5.26,"patate douce");

    return 0;
}
