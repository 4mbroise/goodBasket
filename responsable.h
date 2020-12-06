#ifndef RESPONSABLE_H
#define RESPONSABLE_H

#include "utilisateur.h"
#include "Gestionnaire/gestionnaire.h"
#include <QtCore/QString>

/**
 * @brief Responsable
 * une fois le utilisateur s'incrire il va devnir le consommateur
 * il peut envoyer une demande à Gestionnaire pour devenir le responsable
 * il possède tous les livraison et livraisonprévue
 * il peut ajouter le produit au panier
 *
 * @version 2
 * @author GE Yuxuan
 * @author CAI Yunfan
 */
class Utilisateur;

//:public Utilisateur (supprimer pour instant)

class Responsable
{
    public:
     /**
       * @brief Consommateur :construction
       * @param nom :Nom du utilisateur
       * @param prenom: Prénom du utlisateur
       * @param adresse:Adresse du utlisateur
       * @param phone:A
       * @param Gestionnaire: gestionnaire
       */
     Responsable(std::string nom,std::string prenom,std::string adresse,double phone,std::string email,Gestionnaire &gestionnaire);

     /**
      * @brief Destructeur de la classe utilisatuer,si le sous-class exécute le destructeur ,il va aussi exécuter.
      */
    // ~Responsable(); (supprimer pour instant)


     void ajouterProduitAuPanier();

     /**
      * @brief fonction qui retourner id
      * @return int id
      */
    int getId();

     /**
      * @brief demander à gestionnaire de payer les producteurs
      */
    void PayerProducteurs(int producteurid);

     /**
      * @brief Confirmer la demande
      */
    void Confirmer();

    /**
     * @brief fonction qui retourner le message recu
     * @return std::string message recu
     */
    std::string GetMessage();

    /**
     * @brief procedure qui recoit message envoyé par gestionnaire
     */
    void RecevoirMessage(std::string mess);

    /**
     * @brief procedure qui consulter les erreurs
     */
    void ConsulterReports();





    private:

        /**
         * @brief message renvoyé par gestionaire
         */
        std::string message;

        /**
         * @brief id
         */
        int id;

        /**
         * @brief nom
         */
        std::string nom;

        /**
         * @brief prenom
         */
        std::string prenom;

        /**
         * @brief adresse
         */
        std::string adresse;

        /**
         * @brief numero de telephone
         */
        double phone;

        /**
         * @brief adresse mail
         */
        std::string email;

        /**
         * @brief GestionnaireDeDialogue qui fait le lien entre les requêtes du producteur et les actions réellement effectuées
         *
         */
        Gestionnaire &gestionnaire;

        /**
         * @brief Pour chaque renvoi on choisi oui ou non
         *
         */
        bool confirmer;

};

#endif // RESPONSABLE_H
