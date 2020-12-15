#ifndef RESPONSABLE_H
#define RESPONSABLE_H

#include "utilisateur.h"
#include "pc.h"
#include "consommateur.h"
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
 * @author FAUGIER Elliot
 */
class Utilisateur;

class Responsable:public Utilisateur
{
    public:
     /**
       * @brief Consommateur :construction
       * @param nom :Nom du utilisateur
       * @param prenom: Prénom du utlisateur
       * @param adresse:Adresse du utlisateur
       * @param phone:A
       */
     Responsable(QString nom,QString prenom,QString adresse,QString phone,QString email);

     /**
      * @brief Destructeur de la classe utilisatuer,si le sous-class exécute le destructeur ,il va aussi exécuter.
      */

     /**
      * @brief Constructeur avec qu'un id ( les autres infos étant dans la BDD )
      * @param id du responsable
      */
     Responsable(int id);

     /**
      * @brief Responsable, constructeur par défaut
      */
     Responsable();

     ~Responsable();

     /**
      * @brief getId:retourner identifié
      * @return Id unique associé à un Responsable
      */

     virtual const int& getId();

     /**
      * @brief getNom
      * @return nom d'un Responsable
      */
     virtual const QString& getNom();

     /**
      * @brief getPrenom
      * @return prénom d'un Responsable
      */
     virtual const QString& getPrenom();

     /**
      * @brief getAdresse
      * @return adresse d'un Responsable
      */
     virtual const QString& getAdresse();

     /**
      * @brief getPhone
      * @return numéro de téléphone d'un Responsable
      */
     virtual const QString& getPhone();

     /**
      * @brief getEmail
      * @return email d'un Responsable
      */
     virtual const QString& getEmail();

     /**
      * @brief changeNom:modifier ou ajouter le nom d'un Responsable
      * @param nom:nouveau nom
      */
     virtual void changeNom(std::string nom);

     /**
      * @brief changePrenom:changeNom:modifier ou ajouter le prénom d'un Responsable
      * @param prenom:noveau prénom
      */
     virtual void changePrenom(std::string prenom);

     /**
      * @brief changeAdresse:modifier ou ajouter l'adresse d'un Responsable
      * @param adresse:nouveau adresse
      */
     virtual void changeAdresse(std::string adresse);

     /**
      * @brief changePhone:modifier ou ajouter le numéro de téléphone d'un Responsable
      * @param phone:nouveau nom
      */
     virtual void changePhone(std::string phone);

     /**
      * @brief changeEmail:modifier ou ajouter l'email d'un Responsable
      * @param email:noveau email
      */
    virtual void changeEmail(std::string email);


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

    /**
     * @brief responsable demande rembourser les producteurs
     */
    void DemanderRembourser(int consommateurId);

    void demanderPC(int id,std::string villes,int codePostal,int numero,std::string nomRue);

    void setPC(PC pc);

    PC& getPC();

    void recruterProducteur(std::string recrutement);

    QHash<int,std::string>& consulterDemande();

    bool reponseRecrutement(int idProducteur,std::string demande);

    void ajouterProducteur(int idProducteur,std::string demande);

    /**
     * @brief isCycleValide retourne vrai si c'est un cycle valide (dateDebutCycle < dateVente < dateFinVente < dateLivraison )
     * fonction appelée avant l'ajout d'un nouveau cycle
     * @param dateDebutCycle
     * @param dateVente
     * @param dateFinVente
     * @param dateLivraison
     * @return
     */
    bool isCycleValide(QDate dateDebutCycle, QDate dateVente, QDate dateFinVente, QDate dateLivraison);

    /**
     * @brief ajouterCycle, ajoute un cycle au pc lié au responsable dans la table cycle de la BDD
     * @param dateDebutCycle
     * @param dateVente
     * @param dateFinVente
     * @param dateLivraison
     */
    void ajouterCycle(QDate dateDebutCycle, QDate dateVente, QDate dateFinVente, QDate dateLivraison);

    /**
     * @brief retirerCycle on retire le ou les cycles définis par les dates en paramètres
     * @param dateDebutCycle
     * @param dateVente
     * @param dateFinVente
     * @param dateLivraison
     */
    void retirerCycle(QDate dateDebutCycle, QDate dateVente, QDate dateFinVente, QDate dateLivraison);

    /**
     * @brief fermerPointDeCollecte, revient à supprimer tous les cycles de vente du point de collecte
     */
    void fermerPointDeCollecte();

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
        QString nom;

        /**
         * @brief prenom
         */
        QString prenom;

        /**
         * @brief adresse
         */
        QString adresse;

        /**
         * @brief numero de telephone
         */
        QString phone;

        /**
         * @brief adresse mail
         */
        QString email;
/*
        /**
         * @brief GestionnaireDeDialogue qui fait le lien entre les requêtes du producteur et les actions réellement effectuées
         *

        Gestionnaire &gestionnaire;
*/
        /**
         * @brief Pour chaque renvoi on choisi oui ou non
         *
         */
        bool confirmer;

        PC pc;

        QList<Producteur> demande;

};

#endif // RESPONSABLE_H
