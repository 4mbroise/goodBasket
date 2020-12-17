#ifndef LIVRAISONSOUSCONSOMMATEUR_H
#define LIVRAISONSOUSCONSOMMATEUR_H

#include <QWidget>
#include "../../../livraison.h"


/**
 * @brief LivraisonSousConsommateur
 * QWidget comme une liste d'un produit dans le panier(qwidgetitem dans le listwidget du consommateurig)
 * il affiche  id du consommateur, nom du produit,id du Produit, prix du produit,quantite du produit, adresse du PC, date de la Livraison
 * et un bouton,qui permet qu'on supprime le livraison,les données va aussi enlever
 * @version 2
 * @author GE Yuxuan
 */

QT_BEGIN_NAMESPACE
namespace Ui { class LivraisonSousConsommateur; }
QT_END_NAMESPACE

class LivraisonSousConsommateur : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief LivraisonSousConsommateur:constructeur du livraison interface graphique
     * @param parent:consommateurig
     */
    LivraisonSousConsommateur(QWidget *parent = nullptr);

    /**
     * destructeur du LivraisonSousConsommateur
     */
    ~LivraisonSousConsommateur();

    /**
     * @brief setData:installer tous les labels de la livraison
     * @param id:id du consommateur
     * @param nom: nom du produit
     * @param idProduit:id du Produit
     * @param prix:prix du produit
     * @param quantite:quantite du produit
     * @param adressePC: adresse du PC,
     * @param dateLivraison:date de la Livraison
     */
    void setData(const QString& id,const QString& nom,const QString& idProduit,const QString& prix,const QString& quantite,const QString& adressePC,const QString& dateLivraison);

    /**
     * @brief setData:installer tous les labels de la livraisonprevue
     * @param id:id du consommateur
     * @param nom: nom du produit
     * @param idProduit:id du Produit
     * @param prix:prix du produit
     * @param quantite:quantite du produit
     * @param adressePC: adresse du PC,
     * @param dateLivraison:date de la Livraison
     */
    void setDataPrevue(const QString& id,const QString& nom,const QString& idProduit,const QString& prix,const QString& quantite,const QString& adressePC,const QString& dateLivraison,const QString& dateAchat);
private slots:
    /**
     * @brief on_Supprimer_clicked:bouton signal si on clicke sur le bouton,la fonction va exécuter
     * pour supprimer la livraison pas déterminée
     */
    void on_Supprimer_clicked();

private:
    /**
     * @brief idLivraison:id du livraison
     */
    int idLivraison;
    /**
     * @brief ui:ui contient tous les layouts et outils
     */
    Ui::LivraisonSousConsommateur *ui;
};

#endif // LIVRAISONSOUSIG_H
