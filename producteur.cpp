#include "producteur.h"

Producteur::Producteur()
{
    IdGenerator& gen = IdGenerator::Instance();
    int newId = gen.getNewIdProducteur();
    this->id = newId;
}

void Producteur::demanderAjoutProduit(int quantite, double prix, std::string nom, std::string imagePath)
{
    this->gestionnaireDialogue.ajouterProduit(prix, quantite, nom, imagePath, this->id);
}

void Producteur::ajouterProduit(int quantite, double prix, std::string nom, std::string imagePath)
{
    IdGenerator& gen = IdGenerator::Instance();
    int idProduit = gen.getNewIdProduit();
    Produit produitAjoute = Produit(idProduit, quantite, prix, nom, imagePath);
    this->boutique.insert(idProduit,produitAjoute);
}

bool Producteur::produitExiste(int idProduit)
{
    return this->boutique.contains(idProduit);
}

void Producteur::demanderRetirerProduit(int idProduit)
{
    this->gestionnaireDialogue.retirerProduit(idProduit, this->id);
}

void Producteur::retirerProduit(int idProduit)
{
    this->boutique.remove(idProduit);
}
