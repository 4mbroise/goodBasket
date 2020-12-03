#ifndef RESPONSABLE_H
#define RESPONSABLE_H

#include "Utilisateur.h"
#include <QtCore/QString>

/**
 * @brief Responsable
 * une fois le utilisateur s'incrire il va devnir le consommateur
 * il peut envoyer une demande à Gestionnaire pour devenir le responsable
 * il possède tous les livraison et livraisonprévue
 * il peut ajouter le produit au panier
 *
 * @version 1
 * @author GE Yuxuan
 */
class Utilisateur;

class Responsable: public Utilisateur
{
    public:
     /**
       * @brief Consommateur :construction
       * @param nom :Nom du utilisateur
       * @param prenom: Prénom du utlisateur
       * @param adresse:Adresse du utlisateur
       * @param phone:A
       */
     Responsable(std::string nom,std::string prenom,std::string adresse,double phone,std::string email);

     /**
      * @brief Destructeur de la classe utilisatuer,si le sous-class exécute le destructeur ,il va aussi exécuter.
      */
     ~Responsable();


     void ajouterProduitAuPanier();





    private:



};

#endif // RESPONSABLE_H
