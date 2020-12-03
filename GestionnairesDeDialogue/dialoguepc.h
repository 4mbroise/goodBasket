#ifndef DIALOGUEPC_H
#define DIALOGUEPC_H


#include "pc.h"
#include <QtCore/QString>
#include <QtCore/QHash>


class DialoguePc{
    public:

    /**
     * @brief Constructeur  DialoguePc
     *
     */
    DialoguePc();

    /**
     * @brief consulterCatalgue:permet d'afficher tous les produits d'un producteur
     * après la validité de l'existance du pc ,il va revenir PC à exécuter la même fonction
     * @param idProducteur:Id unique associé au producteur
     */
    void consulterCatalgue(int idProducteur);

    /**
     * @brief pcExiste:vérifier s'il existe le PC
     * @param adressePC:adresse du PC,non null
     * @return true si le PC existe dans le goodbasket
     * @return false sinon
     */
    bool pcExiste(QString adressePC);


    /**
     * @brief ajouterPC:on ajoute le pc au dialogue
     * cette fonction est appelée lors de la creation d'un @ref pc
     * @param pc
     */
    void ajouterPC(PC pc);

    /**
     * @brief nbPC:Fonction qui retourne le nombre  du PC enregistré
     * @return le nombre du PC enregistré
     */
    int nbPC();

    private:
    /**
     * @brief HashTable dont la clé est un IdConsommatuer et la valeur est le Consommateur associé à cet Id,
     * elle représente la liste des consommateur dans goodBasket
     */
    QHash <QString,PC*> pcs;


    /**
     * @brief producteurExiste:vérifier s'il existe le producteur
     * @param pc:PC sélectionné
     * @param idProducteur:Id unique associé au producteur
     * @return true si le producteur existe dans le PC sélectionné
     * @return false sinon
     */
    bool producteurExiste(PC pc,int idProducteur);


    /**
     * @brief estDepasse:vérifier si la commande dépasse le stock
     * @param id:id du produit
     * @param nom: nom du produit
     * @param commande:nombre de la commande du produit
     * @return true si la commande dépasse le stock
     * @return false sinon
     */
    bool estDepasse(int id,QString nom,int commande);

    /**
     * @brief getPC: retourner un consommateur associé à une adresse
     * @param adressePC:adresse associé au PC
     * @return PC associé à cette adresse
     */
    PC* getPC(QString adressePC);


};

#endif // DIALOGUEPC_H
