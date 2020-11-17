#include "dialogueproducteurs.h"

#include "../producteur.h"

#include <iostream>
using namespace std;

DialogueProducteurs::DialogueProducteurs()
{
    cout << "Creation Gestionnaire dialogue Producteur" << endl;
}

void DialogueProducteurs::retirerProduit(int idProduit, int idProducteur)
{
    if(produitExiste(idProduit, idProducteur))
    {
        Producteur pr = retrouverProducteur(idProducteur);
        pr.retirerProduit(idProduit);
    }
    else
    {
        cout<<"PRODUIT INEXISTANT"<<endl;
    }
}

void DialogueProducteurs::ajouterProduit(double prix, int quantite, std::string nom, std::string imagePath,int producteurId)
{
    if(formulaireOk(prix, quantite, nom,imagePath,producteurId))
    {
        Producteur pr = retrouverProducteur(producteurId);
        pr.demanderAjoutProduit(quantite, prix, nom, imagePath);
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

bool DialogueProducteurs::produitExiste(int idProduit, int producteurId)
{
    if(producteurExiste(producteurId))
    {
        Producteur pr = retrouverProducteur(producteurId);
        return pr.produitExiste(idProduit);
    }
    else
    {
        return false;
    }
}

const Producteur DialogueProducteurs::retrouverProducteur(int producteurId)
{
    return this->producteurs.value(producteurId);
}

void DialogueProducteurs::ajouterProducteur()
{
    Producteur pr = Producteur();
    pr.setGestionnaireDialogue(*this);
    this->producteurs.insert(pr.getId(),pr);
}

void DialogueProducteurs::ajouterProducteur(Producteur( pr))
{
    this->producteurs.insert(pr.getId(),pr);
}
