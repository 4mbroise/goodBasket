#include "producteur.h"

Producteur::Producteur()
{
}

void Producteur::ajouterProduit(int quantite, double prix, std::string nom, std::string imagePath)
{
    IdGenerator& gen = IdGenerator::Instance();
    int idProduit = gen.getNewIdProduit();

    Produit produitAjoute = Produit(idProduit, quantite, prix, nom, imagePath);
    this->boutique.insert(idProduit,produitAjoute);
    //this->boutique[idProduit]= produitAjoute;
}
