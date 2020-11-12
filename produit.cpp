#include "produit.h"

Produit::Produit(const int& quantite,const double& prix,const QString& nom,const QImage& image)
{
    IdProduitGenerator& idGenerator =IdProduitGenerator::Instance();

    this->nom = nom;
    this->id = idGenerator.getNewIdProduit();
    this->image = image;
    this->prix = prix;
    this->quantite = quantite;
}
