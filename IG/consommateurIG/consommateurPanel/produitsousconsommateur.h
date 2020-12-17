#ifndef PRODUITSOUSCONSOMMATEUR_H
#define PRODUITSOUSCONSOMMATEUR_H

#include <QWidget>
#include "cataloguesousig.h"

/**
 * @brief ProduitsousCatalogue
 * Il fait partie du catalogue, qui contient principalement des informations sur le produits dans le catalogue qui contient
 * id du produit
 * nom du produit
 * prix du produit
 * quantite du produit
 * id duProducteur
 * id du Consommateur
 * adresse du PC
 * @version 2
 * @author GE Yuxuan
 */

QT_BEGIN_NAMESPACE
namespace Ui { class ProduitsousCatalogue; }
QT_END_NAMESPACE
class CatalogueSousConsommateur;

class ProduitSousCatalogue : public QWidget
{
    Q_OBJECT

public:
    /**
      * @brief ProduitSousCatalogue:constructeur du produit  dans le catalogue interface graphique
      * @param parent:catalogueig
      */
     ProduitSousCatalogue(CatalogueSousConsommateur* parent = nullptr);

     /**
      * destructeur du ProduitSousCatalogueig
      */
    ~ProduitSousCatalogue();

    /**
     * @brief setData:installer tous les labels du produit
     * @param id:id du produit
     * @param nom:nom du produit
     * @param prix:prix du produit par kg
     * @param quantite:quantite(kg) du stock(produits)
     * @param idProducteur:id du producteur
     * @param idConsommateur:id du consommateur
     * @param adressePC:adresse du pc
     */
    void setData(const QString& id,const QString& nom,const QString& prix,const QString& quantite,const QString &idProducteur,const int& idConsommateur,const QString& adressePC);



private slots:
    /**
     * @brief on_AjouterAuPanier_clicked:bouton signal si on clicke sur le bouton,la fonction va exécuter
     * on peut choisir un produit choisir un produit à ajouter au panier
     */
    void on_AjouterAuPanier_clicked();

private:
    /**
     * @brief ui。ui contient tous les layouts et outils
     */
    Ui::ProduitsousCatalogue *ui;

    /**
     * @brief id:id du produit
     */
    QString id;

    /**
     * @brief nom:nom du produit
     */
    QString nom;

    /**
     * @brief prix du produit
     */
    QString prix;

    /**
     * @brief quantite:quantite du produit
     */
    QString quantite;

    /**
     * @brief idProducteur:id du producteur
     */
    QString idProducteur;

    /**
     * @brief idConsommateur:id du consommateur
     */
    int idConsommateur;

    /**
     * @brief adressePC:adresse du pc
     */
    QString adressePC;

    /**
     * @brief parent:catalogueig
     */
    CatalogueSousConsommateur* parent;

};
#endif // PRODUITSOUSIG_H
