#include "dialogueproducteurs.h"

#include "../producteur.h"

#include <iostream>
using namespace std;

DialogueProducteurs::DialogueProducteurs()
{
    cout << "Creation Gestionnaire dialogue Producteur" << endl;
}


void DialogueProducteurs::ajouterProduit(double prix, int quantite, std::string nom, std::string imagePath,int producteurId)
{
    if(formulaireOk(prix, quantite, nom,imagePath,producteurId))
    {
        Producteur pr = retrouverProducteur(producteurId);
        pr.ajouterProduit(quantite, prix, nom, imagePath);
    }
}

bool DialogueProducteurs::formulaireOk(double prix, int quantite, std::string nom, std::string imagePath, int producteurId)
{
    if(producteurExiste(producteurId) && prix>=0 && quantite >0 && !nom.empty() && !imagePath.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool DialogueProducteurs::producteurExiste(int producteurId)
{
    return this->producteurs.contains(producteurId);
}

const Producteur DialogueProducteurs::retrouverProducteur(int producteurId)
{
    return this->producteurs.value(producteurId);
}
