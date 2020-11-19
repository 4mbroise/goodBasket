#ifndef DIALOGUEPRODUCTEURS_H
#define DIALOGUEPRODUCTEURS_H

#include <iostream>
#include<map>
#include <QHash>

class Producteur;

class DialogueProducteurs
{
public:

    DialogueProducteurs();

    void ajouterProducteur();
    void ajouterProducteur(Producteur* pr);

    bool producteurExiste(int idProducteur);

    //Cas ajouter Produit
    void ajouterProduit(double prix, int quantite, std::string nom, std::string imagePath, int producteurId);

    //Cas retirer Produit
    void retirerProduit(int idProduit, int idProducteur);

    int nbProducteur();

private:
    //QHash <int,Producteur> producteurs;

    std::map <int,Producteur*> producteurs;

    Producteur* retrouverProducteur(int ProducteurID);

    //Cas ajouter Produit
    bool formulaireOk(double prix, int quantite, std::string nom, std::string imagePath, int producteurId);

    //Cas retirer Produit
    bool produitExiste(int idProduit, int producteurId);


};

#endif // DIALOGUEPRODUCTEURS_H
