#ifndef PRODUIT_H
#define PRODUIT_H

#include <QtGui/QImage>
#include <QtCore/QString>
/**
 * @brief Produit mis en vente, décrit par une quantité disponible, un prix, le chemin d'accès à une image et un nom
 * @version 1
 * @author Elliot Faugier 
 */
class Produit
{
public:
    /**
     * @brief Constructeur de la classe Produit, il remplit les champs grâce au paramètres et au Singleton idGenerator pour avoir un Id unique.
     * 
     * @param id id unique du produit
     * @param q quantitée mise disponible à la vente
     * @param prix prix /kg de vente
     * @param nom nom du produit
     * @param imagePath chemin de l'image du produit
     */
    Produit(int id, int q,double prix,std::string nom,std::string imagePath);

    /**
     * @brief Getter du nom du produit
     * 
     * @return le nom du produit
     */
    QString const& getNom();

    /**
     * @brief Getter de l'image associée au produit
     * 
     * @return l'image du produit
     */
    QImage const& getImage();

    /**
     * @brief Getter de l'ID du produit
     * 
     * @return l'id du produit
     */
    const int& getId();

    /**
     * @brief Getter de la quantitée de produit disponible à la vente
     * 
     * @return le nom du produit
     */
    const int& getQuantite();

    /**
     * @brief Getter du prix de vente du produit
     * 
     * @return le nom du produit
     */
    const  double& getPrix();

    void operator=(const Produit& pd);

    /**
     * @brief toString() de la classe produit qui décrit le produit
     * 
     * @return la description du produit
     */
    const std::string toString();

    /**
     * @brief setter du prix du produit
     * 
     * @return la description du produit
     */
    void setPrix(double prix);

    /**
     * @brief baisserQuantite:on baisse le stock du produit
     * @param q:quantité
     */
    void baisserQuantite(int q);

    /**
     * @brief augmenterQuantite:on augmente le stock du produit
     * @param q:quantité
     */
    void augmenterQuantite(int q);

    /**
     * @brief operator ==:redéfinition == du produit
     * @param p:produit
     * @return true si tous les informations du produit est équivalent,false sinon
     */
    bool operator==(const Produit& p);

private:
    /**
    * @brief  id unique du produit, chaque produit a un ID unique fournit grâce au singleton IdGenerator
    * 
    */
    int id;
    /**
     * @brief quantitée de produit disponible à la vente
     * 
     */
    int quantite;
    /**
     * @brief prix de vente au kilos du produit
     * 
     */
    double  prix;
    /**
     * @brief nom du produit
     * 
     */
    QString nom;
    /**
     * @brief image associée au produit
     * 
     */
    QImage image;
};

#endif // PRODUIT_H
