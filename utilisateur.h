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
          * @brief Destructeur de la classe utilisatuer,si le sous-class exécute le destructeur ,il va aussi exécuter.
          */
         virtual ~Utilisateur();


         const int& getId();

         const QString& getNom();

         const QString& getPrenom();

         const QString& getAdresse();

         const int& getPhone();

         const QString& getEmail();

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
