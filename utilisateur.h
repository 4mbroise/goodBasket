#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include <QtCore/QList>
#include <QtCore/QString>
#include "Outils/idgenerator.h"

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
          * @brief Utilisateur:constructure sans paramètre
          */
         Utilisateur();

         /**
          * @brief Destructeur de la classe utilisatuer,si le sous-class exécute le destructeur ,il va aussi exécuter.
          */
         virtual ~Utilisateur();

         /**
          * @brief getId:retourner identifié
          * @return Id unique associé à un utilisateur
          */
         const int& getId();

         /**
          * @brief getNom
          * @return nom d'un utilisateur
          */
         const QString& getNom();

         /**
          * @brief getPrenom
          * @return prénom d'un utilisateur
          */
         const QString& getPrenom();

         /**
          * @brief getAdresse
          * @return adresse d'un utilisateur
          */
         const QString& getAdresse();

         /**
          * @brief getPhone
          * @return numéro de téléphone d'un utilisateur
          */
         const double& getPhone();

         /**
          * @brief getEmail
          * @return email d'un utilisateur
          */
         const QString& getEmail();

         /**
          * @brief changeNom:modifier ou ajouter le nom d'un utilisateur
          * @param nom:nouveau nom
          */

         void changeNom(std::string nom);

         /**
          * @brief changePrenom:changeNom:modifier ou ajouter le prénom d'un utilisateur
          * @param prenom:noveau prénom
          */
         void changePrenom(std::string prenom);

         /**
          * @brief changeAdresse:modifier ou ajouter l'adresse d'un utilisateur
          * @param adresse:nouveau adresse
          */
         void changeAdresse(std::string adresse);

         /**
          * @brief changePhone:modifier ou ajouter le numéro de téléphone d'un utilisateur
          * @param phone:nouveau nom
          */
         void changePhone(double phone);

         /**
          * @brief changeEmail:modifier ou ajouter l'email d'un utilisateur
          * @param email:noveau email
          */
         void changeEmail(std::string email);


    private:
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


};

#endif // UTILISATEUR_H
