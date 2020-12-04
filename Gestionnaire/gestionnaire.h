
#ifndef GESTIONNAIRE_H
#define GESTIONNAIRE_H

#include <iostream>
#include "../GestionnairesDeDialogue/dialogueproducteurs.h"
#include "../responsable.h"

class responsable;


/**
 * @brief
 * @version 1
 * @author CAI Yunfan
 */

class Gestionnaire
{
public:

    /**
     * @brief gestion qui appartient à responsable
     * @param dp gestionnaire de dialogue associé au producteur
     */
    Gestionnaire(DialogueProducteurs &dp);


    /**
     * @brief Calculer le montant d'euro à payer
     */
    void CalculerMontantPayement(int producteurID);

    /**
     * @brief Permet de vérifeir le montant de payment
     * @param ProducteurID id de producteur
     * @param montant de payment pas trop grand ou moins
     */
    bool VérifierMontant(int ProducteurID, int montant);

    /**
     * @brief Permet de payer le montant de payment
     */
    void Payer();

    /**
     * @brief Permet de notifier le payment reçu à dialogueproducteur
     */
    void NotifierDialogueProducteur(int producteurID);

    /**
     * @brief Permet de notifier le payment reçu à responsable
     */
    void NotifierResponsable();



private:

     /**
     * @brief Montant d'euro à payer
     */
    int montantPayement;

    /**
     * @brief GestionnaireDeDialogueProducteur qui fait le lien entre les requêtes du gestionnaire et les actions réellement effectuées
     *
     */
    DialogueProducteurs &gestionnaireDialogueProducteur;


};

#endif
