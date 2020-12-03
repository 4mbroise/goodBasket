#ifndef DIALOGUECONSOMMATEUR_H
#define DIALOGUECONSOMMATEUR_H


#include <iostream>
#include <QHash>

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

class DialogueConsommateur
{
public:

    /**
     * @brief Constructeur  DialogueConsommateur
     *
     */
    DialogueConsommateur();

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
    void ajouterPanier(Livraison l);

    /**
     * @brief chositPC:on choit un PC par un paramètre d'adresse PC
     * après la validité de l'existance du pc ,il va revenir consommateur à exécuter la même fonction
     * @param adressePC:adresse du pc sélectionné
     */
    void chositPC(QString adressePC);


    /**
     * @brief ajouterConsommateur:on ajoute le consommateur au dialogue
     * cette fonction est appelée lors de la creation d'un @ref pc
     * @param c
     */
    void ajouterConsommateur(Consommateur c);


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
    const std::string toString();


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



};

#endif // DIALOGUECONSOMMATEUR_H
