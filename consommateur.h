#ifndef CONSOMMATEUR_H
#define CONSOMMATEUR_H

#include "utilisateur.h"
#include "responsable.h"
#include "producteur.h"
#include "livraison.h"
#include <QtCore/QString>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

/**
 * @brief Consommateur
 * une fois le utilisateur s'incrire il va devnir le consommateur
 * il peut envoyer une demande à Gestionnaire pour devenir le responsable
 * il possède tous les livraison et livraisonprévue
 * il peut ajouter le produit au panier
 * il peut consulter le catalogue
 * @version 3
 * @author GE Yuxuan
 * @author CAI Yunfan
 */

class Utilisateur;

class Consommateur:public Utilisateur
{
    public:
     /**
       * @brief Consommateur :construction
       * @param nom :Nom du utilisateur
       * @param prenom: Prénom du utlisateur
       * @param adresse:Adresse du utlisateur
       * @param phone:numéro de téléphone
       */
    Consommateur(QString nom,QString prenom,QString adresse,QString phone,QString email, QString pass);

    /**
     * @brief Consommateur:il va céer un consommateur qui contient que id pour consulter tous les données dans BDD
     * @param idConsommateur:id unique du Consommateur
     */
    Consommateur(int idConsommateur);

    /**
     * @brief ajouterConsommateurBDD:ajouter tous les données du consommateur dans le BDD
     */
    void ajouterConsommateurBDD();

    /**
     * @brief commande des produit du panier du consommateur
     */
    void commanderPanier();


    /**
     * @brief ajouterProduitAuPanier:retourner tous les donnée des produits dans le pc sélèctionné.
     * @param nom:nom du PC
     * @param idConsommateur:id du Consommateur
     * @param idProduit:id du Produit
     * @param quantite:quantite du Produit
     * @param prix:prix du Produit
     * @param adressePC:adresse du PC sélèctionné
     */
    void ajouterProduitAuPanier(QString nom,int idConsommateur,int idProduit,int quantite,double prix,QString adressePC);


     /**
      * @brief toString:information du consommateur
      * @return un string qui contient l'id du consommateur et le toString de tous les tostring et nombre du livraison dans le panier et livraisonprévue
      */
     const std::string toString();


    private:


};

#endif // CONSOMMATEUR_H
