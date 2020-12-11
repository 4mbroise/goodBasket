#ifndef PRODUCTEURPANEL_H
#define PRODUCTEURPANEL_H

#include <string>
#include <QPushButton>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QWidget>
#include "../../../produit.h"
#include "../../../producteur.h"
#include "../../../Outils/idGenerator.h"
#include "../../../GestionnairesDeDialogue/dialogueProducteurs.h"
#include "../ajouterProduitIG/Widget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class producteurPanel; }
QT_END_NAMESPACE

class producteurPanel : public QWidget
{
    Q_OBJECT

public:
    producteurPanel(QWidget *parent = nullptr, Producteur *p = nullptr);
    producteurPanel(Producteur *p);
    ~producteurPanel();

private slots:
    void mettreAJourTable();

    void on_pushButton_clicked();

private:
    Widget *formulaire;
    Producteur *prod;
    QStandardItemModel *model;
    Ui::producteurPanel *ui;
};
#endif // PRODUCTEURPANEL_H
