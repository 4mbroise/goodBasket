
#ifndef GESTIONNAIRE_H
#define GESTIONNAIRE_H

#include <iostream>
#include "../GestionnairesDeDialogue/dialogueproducteurs.h"
#include "../GestionnairesDeDialogue/dialogueconsommateurs.h"
#include "../responsable.h"
#include "../erreur.h"
#include "../consommateur.h"

class Responsable;


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
     * @param e associé au erreur
     * @param dc gestionnaire de dialogue associé au consommtauer
     */
    Gestionnaire(DialogueProducteurs &dp, Erreur &e, DialogueConsommateurs &dc);


    /**
     * @brief Calculer le montant d'euro à payer
     * @param responsableID id de responsable
     * @param producteurID id de producteur
     */
    void CalculerMontantPayement(int responsableID, int producteurID);

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
     * @param responsableID id de responsable
     * @param producteurID id de producteur
     */
    void Payer(int responsableID, int producteurID);

    /**
     * @brief Permet de set Rsponsable
     */
    void AjouteResponsable(Responsable* responsable);

    Responsable* getResponsable(int idResponsable);

    /**
     * @brief Permet de notifier le payment reçu à dialogueproducteur
     */
    void NotifierDialogueProducteur(int producteurID);

    /**
     * @brief Permet de notifier le payment reçu à responsable
     * @param responsableID id de responsable
     * @param s message envoi
     */
    void NotifierResponsable(int responsableID,std::string s);

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

    /**
     * @brief Permet de calculer le montant d'euro à remboursement et raison de erreur
     *
     * @return true le montant d'euro à remboursement > 0
     * @return false le montant d'euro à remboursement =0 0
     * @param consommateurID id de consommateur
     * @param responsbaleID id de responsable
     */
    bool VerifeirRemboursement(int consommateurID,int ResponsableId);

    /**
     * @brief Permet de rembourser le concommateur
     *
     * @param consommateurID id de consommateur
     * @param responsableID id de ressponsbale
     */
    void Rembourser(int consommateurId,int reponsableId);

    void demanderPC(int id,std::string villes,int codePostal,int numero,std::string nomRue);

    QHashIterator<int,Responsable*> iterator();

    DialogueConsommateurs& getDialogueConsommateurs();

    DialogueProducteurs& getDialogueProducteurs();

    bool inscrire(std::string phone,std::string email);



private:

     /**
     * @brief Montant d'euro à payer
     */
    int montantPayement;

    /**
    * @brief Montant d'euro à rembourser
    */
   int montantRemboursement;

    /**
     * @brief GestionnaireDeDialogueProducteur qui fait le lien entre les requêtes du gestionnaire et les actions réellement effectuées
     *
     */
    DialogueProducteurs &gestionnaireDialogueProducteur;

    /**
     * @brief GestionnaireDeDialogueConsommtauer qui fait le lien entre les requêtes du gestionnaire et les actions réellement effectuées
     *
     */
    DialogueConsommateurs &gestionnaireDialogueConsommateur;

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
