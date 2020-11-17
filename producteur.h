#ifndef PRODUCTEUR_H
#define PRODUCTEUR_H

#include <QtCore/QHash>
#include "produit.h"

#include "Outils/idgenerator.h"
#include "GestionnairesDeDialogue/dialogueproducteurs.h"

class Producteur
{
    public:
        Producteur();
        void demanderAjoutProduit(int quantite, double prix, std::string nom, std::string imagePath);
        void demanderRetirerProduit(int idProduit);
        bool produitExiste(int idProduit);
        void ajouterProduit(int quantite, double prix, std::string nom, std::string imagePath);
        void retirerProduit(int idProduit);
    private:
        int id;
        DialogueProducteurs gestionnaireDialogue;
        QHash<int,Produit> boutique;
};

#endif // PRODUCTEUR_H
