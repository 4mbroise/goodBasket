#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include "../../../produit.h"
#include "../../../producteur.h"
#include "../../../Outils/idGenerator.h"
#include "../../../GestionnairesDeDialogue/dialogueProducteurs.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr, Producteur *p = nullptr);
    Widget(Producteur *p);
    ~Widget();

signals:
    void miseAjourBoutique();

private slots:
    void on_buttonAjouterProduit_released();

private:
    Producteur *model;
    Ui::Widget *ui;
};
#endif // WIDGET_H
