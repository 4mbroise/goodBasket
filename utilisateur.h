#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include <QtCore/QList>
#include <QtCore/QString>
#include "Outils/idgenerator.h"
#include "Gestionnaire/gestionnaire.h"
using namespace std;

/**
 * @brief Utilisateur peut devenir le responsable ou le consommateur
 * @version 1
 * @author GE Yuxuan
 */

class Utilisateur {

    public:
        /**
         * @brief constructure du utilisateur
         * @param nom :Nom du utilisateur
         * @param prenom: Prénom du utlisateur
         * @param adresse:Adresse du utlisateur
         * @param phone:numéro du téléphone
         */
         Utilisateur(std::string nom,std::string prenom,std::string adresse,double phone,std::string email);


         /**
          * @brief Destructeur de la classe utilisatuer,si le sous-class exécute le destructeur ,il va aussi exécuter.
          */
         virtual ~Utilisateur();

         /**
          * @brief getId:retourner identifié
          * @return Id unique associé à un utilisateur
          */
         virtual const int& getId();

         /**
          * @brief getNom
          * @return nom d'un utilisateur
          */
         virtual const QString& getNom();

         /**
          * @brief getPrenom
          * @return prénom d'un utilisateur
          */
         virtual const QString& getPrenom();

         /**
          * @brief getAdresse
          * @return adresse d'un utilisateur
          */
         virtual const QString& getAdresse();

         /**
          * @brief getPhone
          * @return numéro de téléphone d'un utilisateur
          */
         virtual const double& getPhone();

         /**
          * @brief getEmail
          * @return email d'un utilisateur
          */
         virtual const QString& getEmail();

         /**
          * @brief changeNom:modifier ou ajouter le nom d'un utilisateur
          * @param nom:nouveau nom
          */
         virtual void changeNom(std::string nom);

         /**
          * @brief changePrenom:changeNom:modifier ou ajouter le prénom d'un utilisateur
          * @param prenom:noveau prénom
          */
         virtual void changePrenom(std::string prenom);

         /**
          * @brief changeAdresse:modifier ou ajouter l'adresse d'un utilisateur
          * @param adresse:nouveau adresse
          */
         virtual void changeAdresse(std::string adresse);

         /**
          * @brief changePhone:modifier ou ajouter le numéro de téléphone d'un utilisateur
          * @param phone:nouveau nom
          */
         virtual void changePhone(double phone);

         /**
          * @brief changeEmail:modifier ou ajouter l'email d'un utilisateur
          * @param email:noveau email
          */
        virtual void changeEmail(std::string email);



    protected:
        /**
         * @brief Id unique associé au Utilisateur
         */
        int id;

        /**
         * @brief nom réel du un utilisateur
         */
        QString nom;

        /**
         * @brief nom réel du utilisateur
         */
        QString prenom;

        /**
         * @brief prénom réel du utilisateur
         */
        QString adresse;


        /**
         * @brief numéro de téléphone du utlisateur
         */
        double phone;

        /**
         * @brief l'adresse email du utlisateur
         */
        QString email;


        /**
         * @brief vérifier si Utilisateur est un Consommateur retourner vrai , faux sinon
         */
        bool estConsommateur;

        /**
         * @brief vérifier si Utilisateur est un Responsable retourner vrai , faux sinon
         */
        bool estResponsable;


        Gestionnaire gestionnaire;
};

#endif // UTILISATEUR_H
