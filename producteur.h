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
        void ajouterProduit(int quantite, double prix, std::string nom, std::string imagePath);
    private:
        DialogueProducteurs gestionnaireDialogue;
        QHash<int,Produit> boutique;
};

#endif // PRODUCTEUR_H
