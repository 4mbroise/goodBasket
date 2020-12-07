#ifndef CONSOMMATEUR_H
#define CONSOMMATEUR_H

#include "utilisateur.h"
#include "producteur.h"
#include "livraison.h"
#include "GestionnairesDeDialogue/dialogueconsommateurs.h"
#include <QtCore/QString>

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

class Consommateur: public Utilisateur
{
    public:
     /**
       * @brief Consommateur :construction
       * @param nom :Nom du utilisateur
       * @param prenom: Prénom du utlisateur
       * @param adresse:Adresse du utlisateur
       * @param phone:numéro de téléphone
       */
     Consommateur(std::string nom,std::string prenom,std::string adresse,double phone,std::string email,DialogueConsommateurs& dc);

     /**
      * @brief Consommateur:constructure de la classe consommateur sans paramètre
      */
     Consommateur();

     /**
      * @brief Destructeur de la classe utilisatuer,si le sous-class exécute le destructeur ,il va aussi exécuter.
      */
     ~Consommateur();

     /**
      * @brief getId:obtenir le id du consommateur
      * @return id unique de consommateur
      */
     virtual const int& getId();

     /**
      * @brief getNom:obtenir le nom du consommateur
      * @return Nom du consommateur
      */
     virtual const QString& getNom();

     /**
      * @brief getPrenom:obtenir le prénom du consommateur
      * @return Nom du consommateur
      */
     virtual const QString& getPrenom();

     /**
      * @brief getAdresse:obtenir l'adresse du consommateur
      * @return Prénom du consommateur
      */
     virtual const QString& getAdresse();

     /**
      * @brief getPhone:obtenir le numéro de téléphone du consommateur
      * @return numéro de téléphone du consommateur
      */
     virtual const double& getPhone();

     /**
      * @brief getEmail:obtenir l'email du consommateur
      * @return email du consommateur
      */
     virtual const QString& getEmail();

     /**
      * @brief changeNom:modifier ou ajouter le nom d'un consommateur
      * @param nom:nouveau nom
      */
     virtual void changeNom(std::string nom);

     /**
      * @brief changePrenom:changeNom:modifier ou ajouter le prénom d'un consommateur
      * @param prenom:noveau prénom
      */
     virtual void changePrenom(std::string prenom);

     /**
      * @brief changeAdresse:modifier ou ajouter l'adresse d'un consommateur
      * @param adresse:nouveau adresse
      */
     virtual void changeAdresse(std::string adresse);

     /**
      * @brief changePhone:modifier ou ajouter le numéro de téléphone d'un consommateur
      * @param phone:nouveau nom
      */
     virtual void changePhone(double phone);

     /**
      * @brief changeEmail:modifier ou ajouter l'email d'un consommateur
      * @param email:noveau email
      */
     virtual void changeEmail(std::string email);

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
         DialogueConsommateurs &gestionnaireDialogue;
};

#endif // CONSOMMATEUR_H
