#ifndef GESTIONOUVERTUREPCPANEL_H
#define GESTIONOUVERTUREPCPANEL_H

#include <QWidget>
#include <QPushButton>
#include <QSqlQueryModel>

#include "../formulaireCycle/formulairecycle.h"
#include "../../../responsable.h"

QT_BEGIN_NAMESPACE
namespace Ui { class GestionOuverturePCPanel; }
QT_END_NAMESPACE
/**
 * @brief The GestionOuverturePCPanel widget qui réunit la gestion des cycle en 1 widget
 * @version 1
 * @author Elliot Faugier
 */
class GestionOuverturePCPanel : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief constructeur GestionOuverturePCPanel
     * @param parent ig parent du widget
     * @param r le responsable qui utilise l'ig
     */
    GestionOuverturePCPanel(QWidget *parent = nullptr, Responsable r = Responsable(-1));

    ~GestionOuverturePCPanel();

private slots:
    /**
     * @brief mettreAJourTable signale qu'il faut mettre à jour la table des cycles de vente
     */
    void mettreAJourTable();

    /**
     * @brief on_pushButton_released ecouteur du bouton permettant de supprimer un cycle de vente
     */
    void on_pushButton_released();

    /**
     * @brief on_pushButton_2_released ecouteur du bouton permmettant de fermer le point de collecte auquel le producteuur est rattaché
     */
    void on_pushButton_2_released();

private:
    QSqlQueryModel *model;
    formulaireCycle *formulaire;
    Responsable responsable;
    Ui::GestionOuverturePCPanel *ui;
};
#endif // GESTIONOUVERTUREPCPANEL_H
