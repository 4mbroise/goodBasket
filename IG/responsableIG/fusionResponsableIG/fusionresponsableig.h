#ifndef FUSIONRESPONSABLEIG_H
#define FUSIONRESPONSABLEIG_H

#include <QWidget>
#include "../gestionOuverturePCIG/gestionouverturepcpanel.h"
#include "../ResponsablePanel/widgetresponsable.h"
#include "../../../responsable.h"

QT_BEGIN_NAMESPACE
namespace Ui { class fusionResponsableIg; }
QT_END_NAMESPACE

/**
 * @brief fusionResponsableIg ig qui réunit toutes les fonctionnalité du gestionnaire en utilisant un tab widget
 * @version 1
 * @author Elliot FAUGIER
 */
class fusionResponsableIg : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief fusionResponsableIg constructeur
     * @param parent ig parent du widget
     * @param r le responsable qui utilise l'ig
     */
    fusionResponsableIg(QWidget *parent = nullptr, Responsable r = Responsable(-1));
    ~fusionResponsableIg();

private:
    /**
     * @brief responsablePanel
     */
    WidgetResponsable *responsablePanel;
    /**
     * @brief gestionOuvertureWidget, widget de gestion des cycles de vente
     */
    GestionOuverturePCPanel *gestionOuvertureWidget;
    /**
     * @brief responsable qui utilise l'IG
     */
    Responsable responsable;
    Ui::fusionResponsableIg *ui;
};
#endif // FUSIONRESPONSABLEIG_H
