#ifndef DIALOGUEPRODUCTEURS_H
#define DIALOGUEPRODUCTEURS_H

#include <QHash>

class Producteur;

class DialogueProducteurs
{
public:
    DialogueProducteurs();


    //Cas ajouter Produit
    void ajouterProduit(double prix, int quantite, std::string imagePath);

    //Cas retirer Produit
    void retirerProduit(int idProduit);

private:
    QHash <int,Producteur> producteurs;

    //Cas ajouter Produit
    bool formulaireOk(double prix, int quantite, std::string nom, int producteurId);

    //Cas retirer Produit
    bool producteurExiste(int idProducteur);
    bool produitExiste(int idProduit);

};

#endif // DIALOGUEPRODUCTEURS_H
