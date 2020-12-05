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
     Consommateur(std::string nom,std::string prenom,std::string adresse,double phone,std::string email,DialogueConsommateurs& dc);

     Consommateur();
     /**
      * @brief Destructeur de la classe utilisatuer,si le sous-class exécute le destructeur ,il va aussi exécuter.
      */
     ~Consommateur();

     /**
      * @brief getId
      * @return
      */
     virtual const int& getId();

     /**
      * @brief getNom
      * @return Nom du utlisateur
      */
     virtual const QString& getNom();

     /**
      * @brief getPrenom
      * @return
      */
     virtual const QString& getPrenom();

     /**
      * @brief getAdresse
      * @return
      */
     virtual const QString& getAdresse();

     /**
      * @brief getPhone
      * @return
      */
     virtual const double& getPhone();

     /**
      * @brief getEmail
      * @return
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

      const QList<Livraison> getPanier();

     /**
      * @brief consulterCatalogue:on chosit Producteur pour consulter le catalogue
      */
     void consulterCatalogue();

     void demanderAjouter(Produit p,int commande);

     /**
      * @brief ajouterProduitAuPanier:ajouter le prouduit au panier
      * @param l:le prouduit en livraison
      */
     void ajouterProduitAuPanier(Livraison l);

     void demanderExtraAjouter(Produit p, int extra);

     void ajouterExtraAuPanier(int position,Livraison l);

     std::string toString();

     int nbLivraison();

     int nbLivraisonPrevues();

    private:

         /**
          * @brief une liste de tous les  produits dans le panier
          */
         QList<Livraison> Panier;

         /**
          * @brief une liste de tous les livraisons(produits) acheté avant
          */
         QList<Livraison> LivraisonPrevues;

         DialogueConsommateurs &gestionnaireDialogue;
};

#endif // CONSOMMATEUR_H
