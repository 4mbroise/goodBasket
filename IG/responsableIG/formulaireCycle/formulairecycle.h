#ifndef FORMULAIRECYCLE_H
#define FORMULAIRECYCLE_H

#include <QWidget>

#include "../../../responsable.h"
#include "../../../utilisateur.h"
#include "../../../pc.h"
#include "../../../produit.h"

QT_BEGIN_NAMESPACE
namespace Ui { class formulaireCycle; }
QT_END_NAMESPACE

/**
 * @brief formulaireCycle est un formulaire pour responsable lui permettant de programmer de nouveaux cycles de vente
 * @version 1
 * @author FAUGIER Elliot
 */
class formulaireCycle : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief constructeur formulaireCycle
     * @param parent ig parent du widget
     * @param r le responsable qui ajoute un nouveau cycle
     */
    formulaireCycle(QWidget *parent = nullptr, Responsable r =Responsable(1));

    ~formulaireCycle();

signals:
    /**
     * @brief miseAJourTableCycle signale qu'il mettre à jour l'affichage de la table des cycles
     */
    void miseAJourTableCycle();

private slots:
    /**
     * @brief on_pushButton_released ecouteur du bouton permettant d'ajouter un nouveau cycle
     */
    void on_pushButton_released();

private:
    /**
     * @brief responsable qui utilise l'IG
     */
    Responsable responsable;
    Ui::formulaireCycle *ui;
};
#endif // FORMULAIRECYCLE_H
