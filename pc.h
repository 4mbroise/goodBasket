#ifndef PC_H
#define PC_H

#include <QtCore/QString>
#include <QtCore/QHash>
#include "producteur.h"

/**
 * @brief PC:point de collecte
 * chaque responsable geste un PC
 * PC contient
 * plusieur producteur
 * état présente que PC ouvert ou pas
 * adresse du PC
 *
 * @version 1
 * @author GE Yuxuan
 */
class PC{
    public:

    /**
     * @brief PC:constructeur du Point de collecte avec l'adresse du PC
     * @param adressePC:l'adresse du PC
     */
    PC(std::string adressePC);

    /**
     * @brief PC:constructeur du Constructeur par défaut
     */
    PC();

    /**
     * @brief constructeur se servant d'une base de donnée, on retourve les infos du PC via l'id de son sresponsable
     * @param idResponsable
     */
    PC(int idResponsable);

    //----------------ATTENTION
    //PC();


    /**
     * @brief getAdressePC:obtenir l'adresse du PC
     * @return l'adresse du PC
     */
    const QString& getAdressePC();

    /**
     * @brief getProducteur:obtenir le producteur associé à id
     * @param idProducteur:id du producteur
     * @return le producteur associé à id
     */
    const Producteur getProducteur(int idProducteur);

    /**
     * @brief setAdresse:installer l'adresse du PC
     * @param adressePC:nouvelle adresse du PC
     */
    void setAdresse(std::string adressePC);

    /**
     * @brief ouvrirPC:ouvrir le PC
     */
    void ouvrirPC();

    /**
     * @brief fermerPC:fermer le PC
     */
    void fermerPC();

    /**
     * @brief nbProducteur:obtenir le nombre du producteur
     * @return le nombre du producteur
     */
   int nbProducteur();

    /**
     * @brief getEtat :obtenir l'état du PC
     * @return état du PC
     */
    const bool& getEtat();

    /**
     * @brief ajouterProducteur:ajouter le producteur au pc
     * @param pdct:producteur
     */
    void ajouterProducteur(Producteur pdct);

    /**
     * @brief iterator de tous les producteur dans le pc
     * @return iterator hashmap
     */
    QHashIterator<int,Producteur> iterator();

    /**
     * @brief getCatalogue:obtenir le catalogue du pc
     * @return catalogue de tous les producteurs dans le pc
     */
    void setCatalogue();



    /**
     * @brief toString du pc
     * @return un string de pc qui présente l'adresse du PC et le string de catalogue
     */
    const std::string toString();


    private:

    /**
     * @brief adresse du pc
     */
    QString adresse;

    /**
     * @brief etat présente le pc ouvert ou pas
     */
    bool etat;



    /**
     * @brief producteurs:Tous les producteurs stockés dans une table de hachage, la clé est l'id du producteur
     */
    QHash<int,Producteur> producteurs;

    QHash<int,Produit> catalogue;


};

#endif // PC_H
