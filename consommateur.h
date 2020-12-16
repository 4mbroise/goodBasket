#ifndef CONSOMMATEUR_H
#define CONSOMMATEUR_H

#include "utilisateur.h"
#include "responsable.h"
#include "producteur.h"
#include "livraison.h"
#include "GestionnairesDeDialogue/dialogueconsommateurs.h"
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
 * @version 2
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


    Consommateur(int idConsommateur);

     /**
      * @brief getPanier:Obtener une liste d'articles dans le panier
      * @return la liste des produits
      */
     QList<Livraison> getPanier();

     /**
      * @brief nbLivraison:obtenir le nombre du livraison dans le panier
      * @return nombre du livraison dans le panier
      */
     int nbLivraison();

     /**
      * @brief nbLivraisonPrevues:obtenir le nombre du livraison dans le livraison prévue
      * @return nombre du livraison dans le livraison prévue
      */
     int nbLivraisonPrevues();

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
      * @brief consulterCatalogue:consutter les catalogues du Goodbasket
      */
     void consulterCatalogue();

     /**
      * @brief demanderAjouter:Demande d'ajout de produit au panier
      * @param p:produit
      * @param commande:nombre du produit commandé
      */
     void demanderAjouter(Produit p,int commande);

     /**
      * @brief ajouterProduitAuPanier:ajouter le prouduit au panier
      * @param l:le prouduit en livraison
      */
     void ajouterProduitAuPanier(Livraison l);

     /**
      * @brief demanderExtraAjouter:demander d'ajoute le produit qui est déjà dans le panier
      * @param p:produit déjà dans le panier
      * @param extra:nombre de produit supplémentaire
      */
     void demanderExtraAjouter(Produit p, int extra);

     /**
      * @brief ajouterExtraAuPanier:mise à jour de produit dans le panier
      * @param position:la position du produit dans le panier
      * @param l:livraison du produit
      */
     void ajouterExtraAuPanier(int position,Livraison l);

     /**
      * @brief demanderSuppressionProduit:demander de supprimer le produit qui est déjà dans le panier
      * @param p:produit déjà dans le panier
      */
     void demanderSupprimerProduit(Produit p);

     /**
      * @brief demanderSuppressionProduit:demander de supprimer tous les produit en cas pas param
      */
     void demanderSupprimerProduit();

     /**
      * @brief ajouterExtraAuPanier:mise à jour de produit dans le livraison
      * @param l:livraison du produit
      */
     void supprimerProduit(Livraison l);

     void ajouterConsommateurBDD();

     /**
      * @brief toString:information du consommateur
      * @return un string qui contient l'id du consommateur et le toString de tous les tostring et nombre du livraison dans le panier et livraisonprévue
      */
     const std::string toString();


    private:

         /**
          * @brief une liste de tous les  produits dans le panier
          */
         QList<Livraison> Panier;

         /**
          * @brief une liste de tous les livraisons(produits) acheté avant
          */
         QList<Livraison> LivraisonPrevues;


         /**
          * @brief gestionnaire:DialogueGestionnaireDeDialogue qui fait le lien entre les requêtes du consommateur et les actions réellement effectuées
          */
          //DialogueConsommateurs &gestionnaireDialogue;

         /**
          * @brief message recu par dialogue
          */
         std::string message;
};

#endif // CONSOMMATEUR_H
