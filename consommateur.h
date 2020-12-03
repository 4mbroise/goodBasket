#ifndef CONSOMMATEUR_H
#define CONSOMMATEUR_H

#include "Utilisateur.h"
#include "producteur.h"
#include "livraison.h"
#include <QtCore/QString>

/**
 * @brief Consommateur
 * une fois le utilisateur s'incrire il va devnir le consommateur
 * il peut envoyer une demande à Gestionnaire pour devenir le responsable
 * il possède tous les livraison et livraisonprévue
 * il peut ajouter le produit au panier
 * il peut consulter le catalogue
 * @version 1
 * @author GE Yuxuan
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
     Consommateur(std::string nom,std::string prenom,std::string adresse,double phone,std::string email);

     /**
      * @brief Destructeur de la classe utilisatuer,si le sous-class exécute le destructeur ,il va aussi exécuter.
      */
     ~Consommateur();

     /**
      * @brief getId
      * @return
      */
     const int& getId();

     /**
      * @brief getNom
      * @return Nom du utlisateur
      */
     const QString& getNom();

     /**
      * @brief getPrenom
      * @return
      */
     const QString& getPrenom();

     /**
      * @brief getAdresse
      * @return
      */
     const QString& getAdresse();

     /**
      * @brief getPhone
      * @return
      */
     const int& getPhone();

     /**
      * @brief getEmail
      * @return
      */
     const QString& getEmail();

     /**
      * @brief selectPC:on chosit d'abord le PC pour consulter tous les producteur dans ce PC
      * @param adressePC:adresse du PC
      */
     void selectPC(QString adressePC);

     /**
      * @brief consulterCatalogue:on chosit Producteur pour consulter le catalogue
      * @param pdct: producteur dans le pc
      */
     void consulterCatalogue(Producteur pdct);

     /**
      * @brief liv:on met le produit comme livraison
      * @param p:produit
      * @param quantite:quantité du produit q'on chosit
      * @return
      */
     Livraison liv(Produit p,int quantite);


     /**
      * @brief ajouterProduitAuPanier:ajouter le prouduit au panier
      * @param l:le prouduit en livraison
      */
     void ajouterProduitAuPanier(Livraison l);



    private:

         /**
          * @brief une liste de tous les  produits dans le panier
          */
         QList<Livraison> Panier;

         /**
          * @brief une liste de tous les livraisons(produits) acheté avant
          */
         QList<Livraison> LivraisonPrevues;


};

#endif // CONSOMMATEUR_H
