#ifndef DIALOGUECONSOMMATEUR_H
#define DIALOGUECONSOMMATEUR_H


#include <iostream>
#include <QHash>
#include <QList>
#include "pc.h"
#include "livraison.h"
#include "produit.h"
class Consommateur;

class PC;

/**
 * @brief DialogueConsommateur permet à un consommateur qui connait 1 DialogueConsommateur
 * de dialoguer avec l'interface, d'effectuer des actions sur le systeme
 * @version 1
 * @author GE Yuxuan
 */

class DialogueConsommateurs
{
public:

    /**
     * @brief Constructeur  DialogueConsommateur
     *
     */
    DialogueConsommateurs();

    ~DialogueConsommateurs();

    /**
     * @brief liv:permet mettre le produit en livraison
     * après vérifier la validité de l'ajoute,il va revenir au consommateur à exécuter la même fonction
     * @param p:Produit
     * @param quantite: quantité du produit
     * @return un livraison
     */
    Livraison liv(Produit p,int quantite);

    /**
     * @brief ajouterPanier:permet l'ajoute le livraison au panier
     * il va revenir au consommateur à exécuter la même fonction
     * @param l
     */
    void ajouterPanier(Produit p,int commande,int idConsommateur);


    /**
     * @brief ajouterConsommateur:on ajoute le consommateur au dialogue
     * cette fonction est appelée lors de la creation d'un @ref pc
     * @param c
     */
    void ajouterConsommateur(Consommateur* c);


    /**
     * @brief nbConsommateur:Fonction qui retourne le nombre  du consommateur enregistré
     * @return le nombre du consommateur
     */
    int nbConsommateur();

    /**
     * @brief Fonction qui retourne le nombre de producteur dans goodBasket
     * et le toString de chacun d'entre eux
     * @return un std::string qui contient le nombre de producteur dans goodBasket et
     * la description de tout les producteurs contenu dans celui ci
     */

    void extraAjouter(Produit p,int extra,int idConsommateur);

    /**
     * @brief Fonction qui notifier remboursement à consommateur
     * @param consomateurId Id du consommateur
     * @param montant de payment
     */
    void notifierProducteurPayment(int idConcommateur,int montant);

    std::string toSring();


private:

     /**
     * @brief HashTable dont la clé est un IdConsommatuer et la valeur est le Consommateur associé à cet Id,
     * elle représente la liste des consommateur dans goodBasket
     */
    QHash <int,Consommateur*> consommateurs;

    /**
     * @brief getConsommateur: retourner un consommateur associé à un Id
     * @param idConsommateur:id unique associé au consommateur
     * @return  consommateur associé à ce Id
     */
    Consommateur* getConsommateur(int idConsommateur);

    /**
     * @brief estDepasse:vérifier si la commande dépasse le stock
     * @param Produit:produit qui est vérifié pour ajouter au panier
     * @param commande:nombre de la commande du produit
     * @return true si la commande dépasse le stock
     * @return false sinon
     */
    bool estDepasse(Produit p,int commande);

};

#endif // DIALOGUECONSOMMATEUR_H
