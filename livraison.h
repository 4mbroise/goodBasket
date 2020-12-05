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
    public:
    Livraison(Produit p,int commande);

    ~Livraison();

    const Produit& getProduit();

    const int& getCommande();

    const time_t& getDateAchat();

    const time_t& getDateLivraison();

    void setLivraison(Produit p,int commande);

    void setDateAchat(time_t date);

    void setDateLivraison(time_t date);

    void ajouterCommande(int extra);

    std::string toSring();

    private:

    Produit produit;

    int commande;

    time_t dateAchat;

    time_t dateLivraison;


};

#endif // LIVRAISON_H
