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

class WidgetProducteur : public QWidget
{
    Q_OBJECT

public:
    WidgetProducteur(QWidget *parent = nullptr, Producteur p = Producteur(-1));
    WidgetProducteur(Producteur p);
    ~WidgetProducteur();

signals:
    void miseAjourBoutique();

private slots:
    void on_buttonAjouterProduit_released();

private:
    bool isFormulaireOK();
    Producteur model;
    Ui::WidgetProducteur *ui;
};
#endif // WIDGET_H
