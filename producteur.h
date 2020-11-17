#ifndef PRODUCTEUR_H
#define PRODUCTEUR_H

#include <QtCore/QHash>
#include "produit.h"

#include "GestionnairesDeDialogue/dialogueproducteurs.h"

class Producteur
{
    public:
        Producteur();
    private:
        DialogueProducteurs gestionnaireDialogue;
        QHash<int,Produit> boutique;
};

#endif // PRODUCTEUR_H
