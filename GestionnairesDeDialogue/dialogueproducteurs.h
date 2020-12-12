#ifndef DIALOGUEPRODUCTEURS_H
#define DIALOGUEPRODUCTEURS_H

#include <iostream>
#include <QHash>
#include "../livraison.h"

class Producteur;
class Gestionnaire;
/**
 * @brief DialogueProducteurs permet à un producteur qui connait 1 DialogueProducteurs
 * de dialoguer avec l'interface, d'effectuer des actions sur le systeme
 * @version 2
 * @author Elliot Faugier
 * @author CAI Yunfan
 */
class DialogueProducteurs
{
public:

    /**
     * @brief Constructeur  DialogueProducteurs
     * 
     */
    DialogueProducteurs();

    void ajouterProducteur();

    /**
     * @brief Permet d'ajouter un producteur à la liste des producteur du systeme,
     *  cette fonction est appelée lors de la creation d'un @ref producteur
     * @param pr le nouveau producteur qu'on ajoute à la liste des producteurs de goodBasket
     */
    void ajouterProducteur(Producteur* pr);

    /**
    * @brief Fonction permettant de vérifier l'existance d'un producteur dans goodBasket
    * 
    * @param idProducteur id du producteur dont on veut vérifier l'existence
    * @return true si le producteur existe dans goodbasket
    * @return false si le producteur n'existe pas dans goodbasket
    */
    bool producteurExiste(int idProducteur);

    /**
     * @brief Fonction qui appelle la fonction ajouterProduit de la classe @ref producteur 
     * après avoir vérifié la validité de chacun des paramètres fourni
     * @param quantite quantite mise en vente du nouveau produit
     * @param prix prix de vente du nouveau produit
     * @param nom nom du nouveau produit
     * @param imagePath chemin d'accès à l'image associée au nouveau produit
     * @param producteurId Id du producteur emetteur de la requête d'ajout de produit
     */
    void ajouterProduit(double prix, int quantite, std::string nom, std::string imagePath, int producteurId);

    /**
     * @brief Fonction qui appelle la fonction retirerProduit de la classe @ref producteur 
     * après avoir vérifié la validité de chacun des paramètres fourni
     * 
     * @param idProduit Id du produit à supprimer
     * @param producteurId Id du producteur emetteur de la requête de supression de produit
     */
    void retirerProduit(int idProduit, int idProducteur);

   // void demanderPC(std::string villes,int codePostal,int numéro,std::string nomRue);


    /**
     * @brief Fonction qui retourne le nombre de producteur dans goodbasket
     * 
     * @return le nombre de producteur dans goodBasket
     */
    int nbProducteur();

    /**
     * @brief Fonction qui notifier payment à producteur
     * @param producteurId Id du producteur
     * @param montant de payment
     */
    void notifierProducteurPayment(int idProducteur,int montant);

    /**
     * @brief supprimerLivraison :permet l'suppression du livraison de producteur
     * il va revenir au idproducteur à exécuter la même fonction
     * @param  Livraison:livraison
     * @param  idproducteur:Id de producteur
     */
    void supprimerLivraison(Livraison livraison,int idproducteur);



    /**
     * @brief getter de producteur par Id avec vérification
     * @param producteurId Id du producteur
     * @return un pointeur vers le producteur trouvé si il existe, sinon renvoie nullptr
     */
    Producteur* getProducteurById(int producteurId);

    /**
     * @brief Fonction qui retourne le nombre de producteur dans goodBasket
     * et le toString de chacun d'entre eux
     * @return un std::string qui contient le nombre de producteur dans goodBasket et 
     * la description de tout les producteurs contenu dans celui ci
     */
    const std::string toString();

    void recruteProducteur(int idResponsable,std::string recrutement);

    void recevoirDemande(int idResponsable,int idProducteur,std::string demande);


    QHash<int,std::string>& getDemande();


private:

     /**
     * @brief HashTable dont la clé est un IdProducteur et la valeur est le Producter associé à cet Id, 
     * elle représente la liste des producteur dans goodBasket
     */
    QHash <int,Producteur*> producteurs;

    /**
     * @brief permet de retouver un producteur dans la liste des producteurs grâce à son id, 
     * cette fonction n'est pas appelée sans vérification au préalable
     * @param ProducteurID Id du producteur à retrouver
     * @return Producteur* trouvé grâce à son Id
     */
    Producteur* retrouverProducteur(int ProducteurID);

    /**
     * @brief Fonction vérifiant la validité des paramètres fournis dans la fonction @ref ajouterProduit
     * 
     * @param prix prix à vérifier >= 0
     * @param quantite quantité à vérifié >0
     * @param nom nom, non null
     * @param imagePath chemin, non null, il faudra vérifier l'existence du fichier plus tard dans l'implémentation du systeme
     * @param producteurId Id du producteur qui effectue la requête 
     * @return true si tous les paramètres sont satisfaisant
     * @return false sinon
     */
    bool formulaireOk(double prix, int quantite, std::string nom, std::string imagePath, int producteurId);

    /**
     * @brief Fonction vérifiant si le producteur associée à l'idProducteur existe
     * puis si le le produit associé à l'idProduit fourni existe dans la boutique du Producteur associé au producteurId fourni
     * 
     * @param idProduit Id du produit à supprimer
     * @param producteurId Id du producteur qui demande la supression de produit
     * @return true si le producteur associé à l'idProducteur existe ET si le produit associé à l'idProduit existe dans la boutique du producteur
     * @return false sinon
     */
    bool produitExiste(int idProduit, int producteurId);


    QHash<int,std::string> demande;

    QHash<int, QHash<int,std::string>> demandeByIdResposable;
};

#endif // DIALOGUEPRODUCTEURS_H
