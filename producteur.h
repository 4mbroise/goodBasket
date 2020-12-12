#ifndef PRODUCTEUR_H
#define PRODUCTEUR_H

#include <QtCore/QHash>
#include "produit.h"

#include "Outils/idgenerator.h"
#include "GestionnairesDeDialogue/dialogueproducteurs.h"

#include <iostream>
using namespace std;


/**
 * @brief Producteur, décrit par un id unique et sa boutique,
 * il connait un Gestionnaire de dialogue pour ajouter un produit à la vente
 * et/ou
 * retirer des produits de la vente
 * @version 2
 * @author Elliot Faugier
 * @author CAI Yunfan
 * @author GE Yuxuan
 */
class Producteur
{
    public:
        /**
        * @brief Constructeur de la classe Producteur,
        * seul un gestionnaire DialogueProducteur est requis pour créer un nouveau producteur
        * 
        * @param dp gestionnaire de dialogue associé au producteur
        */
        Producteur(DialogueProducteurs &dp);


        /**
         * @brief Envoie une requête d'ajout de produit au gestionnaire de dialogue associé,
         * le producteur doit fournir une quantité, un prix, un nom et une image pour
         * parvenir à un succès
         * 
         * @param quantite quantité en kg mis en vente
         * @param prix prix/ €/kg mis en vente
         * @param nom nom du produit
         * @param imagePath chemin local de pour obtenir l'image du produit
         */
        void demanderAjoutProduit(int quantite, double prix, std::string nom, std::string imagePath);

        /**
         * @brief Envoie une requête de supression de produit préalablement mis en vente au gestionnaire de dialogue associé,
         * le producteur doit l'id du produit qu'il souhaite supprimer de sa boutique pour parvenir à un succès
         * parvenir à un succès
         * 
         * @param idProduit id du produit de la boutique du producteur à retirer de la boutique
         */
        void demanderRetirerProduit(int idProduit);

        /**
         * @brief Fonction permettant de vérifier l'existance d'un produit dans la boutique du producteur via son ID
         * 
         * @param idProduit id du produit dont on veut vérifier l'existence dans la boutique
         * @return true si le produit existe dans la boutique
         * @return false sile produit n'existe pas dans la boutique
         */
        bool produitExiste(int idProduit);

        /**
         * @brief fonction appelée par le gestionnaire de dialogue associé au producteur qui 
         * permet de lui ajouter un nouveau produit dans sa boutique grâce aux paramètres fournis
         * 
         * @param quantite quantite mise en vente du nouveau produit
         * @param prix prix de vente du nouveau produit
         * @param nom nom du nouveau produit
         * @param imagePath chemin d'accès à l'image associée au nouveau produit
         */
        void ajouterProduit(int quantite, double prix, std::string nom, std::string imagePath);


        /**
         * @brief fonction appelée par le gestionnaire de dialogue associé au producteur qui 
         * permet de lui retirer un produit de sa boutique grâce à l'id du ce produit
         * 
         * @param idProduit Id du produit à supprimer
         */
        void retirerProduit(int idProduit);

        /**
         * @brief Getter de l'Id producteur
         * 
         * @return Id du Producteur 
         */
        const int&  getId();

        /**
         * @brief Getter de message par dialogue
         *
         * @return le message
         */
        const std::string  getMessage();

        /**
         * @brief Setter du message
         *
         * @param mess message envoyé par dialogue
         */
        void setMessage(std::string message);

        /**
         * @brief Setter du Gestionnaire de DialogueProducteur
         * 
         * @param dp le gestionnaire de dialogue qu'on associera à ce producteur
         */
        void setGestionnaireDialogue(DialogueProducteurs& dp);


        void demanderRecrutement(int idResponsable,std::string demande);

        /**
         * @brief iterator de tous les produits du producteur
         * @return iterator hashmap
         */
        QHashIterator<int,Produit> iterator();


        /**
         * @brief procedure supprimer livaison
         * @param livraison livaison que le producteur demande de supprimer
         */
        void supprimerLivraison(Livraison livraison);

        /**
         * @brief operator = : redéfinition du = du producteur
         * @param p:producteur,on assigne des paramètres à cette classe
         */
        void operator=(const Producteur& p);

        /**
         * @brief toString du producteur
         * 
         * @return retourne un string qui contient l'id du producteur et le toString de chacun des produits dans sa boutique
         */
        const std::string toString();

    private:
        /**
         * @brief Id unique associé au producteur
         * 
         */
        int id;
        /**
         * @brief GestionnaireDeDialogue qui fait le lien entre les requêtes du producteur et les actions réellement effectuées
         * 
         */
        DialogueProducteurs &gestionnaireDialogue;
        /**
         * @brief HashTable dont la clé est un IdProduit et la valeur est un le Produit associé à cet Id, 
         * elle représente la boutique du producteur.
         */
        QHash<int,Produit> boutique;

        /**
         * @brief une liste de tous les livraisons de producteur
         */
        QList<Livraison> LivraisonProducteur;

        /**
         * @brief Notification reçu par Dialogue
         */
        std::string message;
};

#endif // PRODUCTEUR_H
