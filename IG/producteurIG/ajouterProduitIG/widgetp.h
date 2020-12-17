#ifndef WIDGETP_H
#define WIDGETP_H

#include <QWidget>

#include "../../../produit.h"
#include "../../../producteur.h"
#include "../../../Outils/idGenerator.h"
#include "../../../GestionnairesDeDialogue/dialogueProducteurs.h"

QT_BEGIN_NAMESPACE
namespace Ui { class WidgetProducteur; }
QT_END_NAMESPACE



/**
 * @brief WidgetProducteur est un formulaire pour producteur qui une fois remplis correctement permet d'ajouter un produit dans la base de donnée
 * @version 1
 * @author Elliot FAUGIER
 * @author CAI Yunfan
 */
class WidgetProducteur : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief constructeur WidgetProducteur
     * @param parent ig parent du widget
     * @param p le producteur qui ajoute le produit
     */
    WidgetProducteur(QWidget *parent = nullptr, Producteur p = Producteur(-1));

    /**
     * @brief constructeur WidgetProducteur sans ui parent
     * @param parent ig parent du widget
     */
    WidgetProducteur(Producteur p);

    ~WidgetProducteur();

signals:
    /**
     * @brief miseAjourBoutique, signal qu'il faut mettre jour la table qui montre la boutique du producteur et sa table des livraisons prévues
     */
    void miseAjourBoutique();

private slots:
    /**
     * @brief on_buttonAjouterProduit_released ecouteur du bouton permettant de vérifier le formulair et si c'est bon de créer une nouvelle ligne dans la table Produit de la bdd
     */
    void on_buttonAjouterProduit_released();

private:
    /**
     * @brief isFormulaireOK on verifie ce qu'il y a dans le formulaire
     * @return true si le formulaire est correctement remplis, false sinon
     */
    bool isFormulaireOK();

    /**
     * @brief model est le producteur qui utilise l'IG
     */
    Producteur model;

    Ui::WidgetProducteur *ui;
};
#endif // WIDGET_H
