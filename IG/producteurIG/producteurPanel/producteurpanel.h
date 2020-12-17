#ifndef PRODUCTEURPANEL_H
#define PRODUCTEURPANEL_H

#include <string>
#include <QPushButton>
#include <QSqlQueryModel>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QWidget>

#include "../../../produit.h"
#include "../../../producteur.h"
#include "../../../Outils/idgenerator.h"
#include "../../../GestionnairesDeDialogue/dialogueproducteurs.h"
#include "../ajouterProduitIG/widgetp.h"

QT_BEGIN_NAMESPACE
namespace Ui { class producteurPanel; }
QT_END_NAMESPACE

/**
 * @brief producteurPanel, ig qui réunit tous les outils pour un producteur (parcourir sa boutique et ses livraisons prévues et ajouter de nouveaux produits)
 */
class producteurPanel : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief constructeur producteurPanel
     * @param parent ig parent du widget
     * @param p le producteur qui ajoute le produit
     */
    producteurPanel(QWidget *parent = nullptr, Producteur p = Producteur(-1));

    /**
     * @brief constructeur producteurPanel sans ui parent
     * @param parent ig parent du widget
     */
    producteurPanel(Producteur *p);


    ~producteurPanel();

private slots:

    /**
     * @brief miseAjourBoutique, signal qu'il faut mettre jour la table qui montre la boutique du producteur et la table des livraisons prévues
     */
    void mettreAJourTable();

    /**
     * @brief ecouteur du bouton retirer produit
     */
    void on_pushButton_clicked();

    /**
     * @brief ecouteur du bouton annuler livraison
     */
    void on_pushButton_2_released();

private:
    /**
     * @brief le widget formulaire pour ajouter des produit child de cet ig
     */
    WidgetProducteur *formulaire;
    /**
     * @brief prod est le producteur qui utilise l'IG
     */
    Producteur prod;
    /**
     * @brief modelProduits model sql pour faire le lien entre la bdd et la table de la boutique
     */
    QSqlQueryModel *modelProduits;

    /**
     * @brief modelProduits model sql pour faire le lien entre la bdd et la table des livraisons
     */
    QSqlQueryModel *modelLivraisons;
    Ui::producteurPanel *ui;
};
#endif // PRODUCTEURPANEL_H
