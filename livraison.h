#ifndef LIVRAISON_H
#define LIVRAISON_H

#include "produit.h"
#include <ctime>
/**
 * @brief Livraison
 * le livraison est associé à un produit
 * qui contient
 * Produit
 * nombre de commande
 * date d'achat
 * date du livraison
 * @version 1
 * @author GE Yuxuan
 */


class Livraison{


    private:

    Produit produit;

    int commande;

    time_t dateAchat;

    time_t dateLivraison;


};

#endif // LIVRAISON_H
