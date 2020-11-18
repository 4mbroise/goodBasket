#ifndef DIALOGUEPRODUCTEURS_H
#define DIALOGUEPRODUCTEURS_H

#include <QHash>

class Producteur;

class DialogueProducteurs
{
public:

    void ajouterProducteur();
    void ajouterProducteur(Producteur pr);

    bool producteurExiste(int idProducteur);

    //Cas ajouter Produit
    void ajouterProduit(double prix, int quantite, std::string nom, std::string imagePath, int producteurId);

    //Cas retirer Produit
    void retirerProduit(int idProduit, int idProducteur);

    //Implémentation Singleton
    static DialogueProducteurs& Instance();

private:
    QHash <int,Producteur> producteurs;

    const Producteur retrouverProducteur(int ProducteurID);

    //Cas ajouter Produit
    bool formulaireOk(double prix, int quantite, std::string nom, std::string imagePath, int producteurId);

    //Cas retirer Produit
    bool produitExiste(int idProduit, int producteurId);

    //Implémentation Singleton
    static DialogueProducteurs m_instance;
    DialogueProducteurs();


};

#endif // DIALOGUEPRODUCTEURS_H
