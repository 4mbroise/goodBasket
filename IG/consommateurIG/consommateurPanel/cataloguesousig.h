#ifndef CATALOGUESOUSIG_H
#define CATALOGUESOUSIG_H

#include <QWidget>
#include "../../../consommateur.h"


/**
 * @brief CatalogueSousConsommateur
 * c'est une listwidget qui contient tous les produits dans le catalogue du pc
 * on peut chosir le produit à ajouter au panier
 * on peut retourner l'interface graphique du consommateur
 * @version 2
 * @author GE Yuxuan
 */


QT_BEGIN_NAMESPACE
namespace Ui { class CatalogueSousConsommateur; }
QT_END_NAMESPACE

class CatalogueSousConsommateur : public QWidget
{
    Q_OBJECT

public:
    /**
      * @brief CatalogueSousConsommateur:constructeur de la liste du catalogue
      * @param parent:consommateurig
      * @param adressPC:adresse du pc;
      * @param c:consommateur qui consulte
      */
     CatalogueSousConsommateur(QWidget *parent = nullptr,QString adressPC="",Consommateur c =Consommateur(-1));

     /**
      * destructeur du consommateurig
      */
     ~CatalogueSousConsommateur();

     /**
     * @brief setData:installer le donnée du catalogue
     */
    void setData();

    /**
     * @brief getUI:retourner un ui du catalogue
     * @return ui
     */
    Ui::CatalogueSousConsommateur& getUI();

    /**
     * @brief getConsommateur:retourner consommateur
     * @return Consommateur
     */
    Consommateur& getConsommateur();

    /**
     * @brief mettreAJour:mettre à jour le donnée
     */
    void mettreAJour();

private slots:

    /**
     * @brief on_Retourner_clicked:bouton signal pour revenir le consommmateurig
     */
    void on_Retourner_clicked();

signals:
    /**
     * @brief sendsignal:signal
     */
    void sendsignal();

private:
    /**
     * @brief ui:ui contient tous les layouts et outils
     */
    Ui::CatalogueSousConsommateur *ui;

    /**
     * @brief adressePC:adresse du PC
     */
    QString adressePC;

    /**
     * @brief consommateur:consommateur qui consulte le catalogue
     */
    Consommateur consommateur;

    /**
     * @brief idConsommateur:id du consommateur
     */
    int idConsommateur;
};

#endif // CATALOGUESOUSIG_H
