
#ifndef GESTIONNAIRE_H
#define GESTIONNAIRE_H

#include <iostream>
#include "../GestionnairesDeDialogue/dialogueproducteurs.h"
#include "../responsable.h"
#include "../erreur.h"
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
    Gestionnaire(DialogueProducteurs &dp, Erreur &e);


    /**
     * @brief Calculer le montant d'euro à payer
     */
    void CalculerMontantPayement(int producteurID);

    /**
     * @brief Permet de vérifeir le montant de payment
     * @param ProducteurID id de producteur
     * @param montant de payment pas trop grand ou moins
     * @return true si le montant est bien
     * @return false si le montant a problème
     */
    bool VerifierMontant(int ProducteurID, int montant);

    /**
     * @brief Permet de payer le montant de payment
     */
    void Payer();

    /**
     * @brief Permet de set Rsponsable
     */
    void AjouteResponsable(Responsable* responsable);

    /**
     * @brief Permet de notifier le payment reçu à dialogueproducteur
     */
    void NotifierDialogueProducteur(int producteurID);

    /**
     * @brief Permet de notifier le payment reçu à responsable
     */
    void NotifierResponsable(int responsableID);

    /**
     * @brief Permet de vérifeir s'il y erreur dans gestion
     * @return true quantité erreur inférieur à 0
     * @return false quantité erreur égale à 0
     */
    bool VerifierErreur();

    /**
     * @brief Permet de notifier les erreurs à responsable
     */
    void NotifierErreur(int responsableID);



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

    /**
     * @brief erreur qui fait le lien entre les erreurs reportés et le responsable
     *
     */
    Erreur &erreur;

    /**
    * @brief HashTable dont la clé est un IdResponsable et la valeur est le Responsable associé à cet Id,
    * elle représente la liste des responsables dans goodBasket
    */
    QHash <int,Responsable*> responsables;


};

#endif
