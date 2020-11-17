#ifndef DIALOGUEPRODUCTEURS_H
#define DIALOGUEPRODUCTEURS_H

#include <QHash>

class Producteur;

class DialogueProducteurs
{
public:
    DialogueProducteurs();


    //Cas ajouter Produit
    void ajouterProduit(double prix, int quantite, std::string nom, std::string imagePath, int producteurId);

    //Cas retirer Produit
    void retirerProduit(int idProduit, int idProducteur);

private:
    QHash <int,Producteur> producteurs;

    const Producteur retrouverProducteur(int ProducteurID);

    //Cas ajouter Produit
    bool formulaireOk(double prix, int quantite, std::string nom, std::string imagePath, int producteurId);

    //Cas retirer Produit
    bool producteurExiste(int idProducteur);
    bool produitExiste(int idProduit, int producteurId);

};

#endif // DIALOGUEPRODUCTEURS_H
