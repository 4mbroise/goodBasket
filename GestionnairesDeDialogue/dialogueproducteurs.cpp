#include "dialogueproducteurs.h"

#include "../producteur.h"

#include <iostream>
using namespace std;

int DialogueProducteurs::nbProducteur()
{
    return this->producteurs.size();
}

DialogueProducteurs::DialogueProducteurs()
{
    cout << "Creation Gestionnaire dialogue Producteur" << endl;
}

void DialogueProducteurs::retirerProduit(int idProduit, int idProducteur)
{
    if(produitExiste(idProduit, idProducteur))
    {
        Producteur* pr = retrouverProducteur(idProducteur);
        pr->retirerProduit(idProduit);
    }
    else
    {
        cout<<"PRODUIT INEXISTANT"<<endl;
    }
}

void DialogueProducteurs::ajouterProduit(double prix, int quantite, std::string nom, std::string imagePath,int producteurId)
{
    cout << "AjoutProduit" << endl;
    cout << "nbProducteur dans ajouterProduit = "+to_string(nbProducteur())<<endl;
    if(formulaireOk(prix, quantite, nom,imagePath,producteurId))
    {
        cout << "Formulaire OK" << endl;

        retrouverProducteur(producteurId)->ajouterProduit(quantite, prix, nom, imagePath);

        //Producteur pr = retrouverProducteur(producteurId);

        std::map<int, Producteur*>::iterator it = producteurs.find(producteurId);
        //return it->second.ajouterProduit(quantite, prix, nom, imagePath);

        //pr.ajouterProduit(quantite, prix, nom, imagePath);
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
        cout << "Nombre de producteur:"+to_string(nbProducteur()) <<endl;
        cout<<"formulaire not ok"<<endl;
        return false;
    }
}

bool DialogueProducteurs::producteurExiste(int producteurId)
{

    cout << producteurId<<endl;
    map<int,Producteur*>::iterator it = producteurs.find(producteurId);
    if(it != producteurs.end())
    {
       return true;
    }
    else
    {
        return false;
    }
}

bool DialogueProducteurs::produitExiste(int idProduit, int producteurId)
{
    if(producteurExiste(producteurId))
    {
        Producteur* pr = retrouverProducteur(producteurId);
        return pr->produitExiste(idProduit);
    }
    else
    {
        return false;
    }
}

Producteur* DialogueProducteurs::retrouverProducteur(int producteurId)
{
    std::map<int, Producteur*>::iterator it = producteurs.find(producteurId);
    return it->second;
    //return producteurs.at(producteurId);
}

void DialogueProducteurs::ajouterProducteur(Producteur* pr)
{
    producteurs.insert(std::make_pair(pr->getId(), pr));
}
