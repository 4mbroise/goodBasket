#ifndef ERREUR_H
#define ERREUR_H

#include <QHash>
#include <iostream>
#include "livraison.h"

/**
 * @brief erreur
 * l'ensemble des erreurs dans gestionnaire
 * @version 1
 * @author CAI Yunfan
 */

class Erreur{

    public:

    /**
    * @brief Constructeur de la classe Erreur,
    * seul livaison pour creer erreur
    *
    * @param l erreur dans quelle livraison
    */
    Erreur();

    /**
    * @brief ajouter contenu d'erreur dans table
    */
    void AjouterErreur(std::string erreur);

    /**
    * @brief Fonction qui retourne le nombre de erreur
    *
    * @return le nombre de erreur
    */
    int nbErreur();

    /**
    * @brief Verifier s'il y a une erreur dans le class
    *
    * @return true s'il y a une erreur dans le class
    * @return false s'il n'y a pas de erreur dans le class
    */
    bool Verifier();

    /**
     * @brief toString du erreur
     *
     * @return retourne un string qui contient les erreurs dans class erreur
     */
    std::string toString();

    private:

    /**
    * @brief quantitie des erreurs
    */
    int quantiteErreur;

    /*
     * réfléchir que si on ajoute plus tard

    **
    * @brief erreur dans quelle livraison
    *
    Livraison livraison;
       */


    /**
    * @brief HashTable dont la clé est un index et la valeur est le contenu d'erreur
    */
    QHash <int,std::string> erreurs;


};

#endif // ERREUR_H
