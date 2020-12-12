#ifndef LIVRAISON_H
#define LIVRAISON_H

#include "produit.h"
#include <ctime>
/**
 * @brief Livraison
 * la livraison est associé à un produit
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
    /**
     * @brief Livraison:constructeur de la livraison
     * @param p:produit
     * @param commande:nombre du produit commandé
     */
    Livraison(Produit p,int commande);


    /**
     * @brief getProduit:obtenir le produit
     * @return produit qui est en livraison
     */
    const Produit& getProduit();

    /**
     * @brief getCommande:obtenir le nombre du produit
     * @return nombre du produit
     */
    const int& getCommande();

    /**
     * @brief getDateAchat:obtenir la date d'achat
     * @return le date d'achat
     */
    const time_t& getDateAchat();

    /**
     * @brief getDateLivraison:obtenir la date de la livraison
     * @return la date de la livraison
     */
    const time_t& getDateLivraison();

    /**
     * @brief setLivraison:fixer la livraison
     * @param p:produit
     * @param commande:nombre du produit
     */
    void setLivraison(Produit p,int commande);

    /**
     * @brief setDateAchat:fixer la date d'achat
     * @param date:date d'achat
     */
    void setDateAchat(time_t date);

    /**
     * @brief setDateLivraison:fixer la date de la livraison
     * @param date:la date de la livraison
     */
    void setDateLivraison(time_t date);

    /**
     * @brief ajouterCommande:augmenter la quantité commandée
     * @param extra:la quantité commandée supplémentaire
     */
    void ajouterCommande(int extra);

    /**
     * @brief operator ==:redéfinition du == de la livraison
     * @param l: livraison
     * @return true si le produit de la livraison est équivalent ,false sinon
     */
    bool operator==(const Livraison& l);

    /**
     * @brief toSring de la livraison
     * @return le string du produit avec le quantité
     */
    const std::string toSring();



    private:

    /**
     * @brief produit:produit qui en livraison
     */
    Produit produit;

    /**
     * @brief commande:la quantité du produit
     */
    int commande;

    /**
     * @brief dateAchat:la date d'achat
     */
    time_t dateAchat;

    /**
     * @brief dateLivraison:la date de la livraison
     */
    time_t dateLivraison;


};

#endif // LIVRAISON_H
