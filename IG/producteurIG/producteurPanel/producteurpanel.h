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
#include "../ajouterProduitIG/widget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class producteurPanel; }
QT_END_NAMESPACE

class producteurPanel : public QWidget
{
    Q_OBJECT

public:
    producteurPanel(QWidget *parent = nullptr, Producteur p = Producteur(-1));
    producteurPanel(Producteur *p);
    ~producteurPanel();

private slots:
    void mettreAJourTable();
    void on_pushButton_clicked();

    void on_pushButton_2_released();

private:
    Widget *formulaire;
    Producteur prod;
    QSqlQueryModel *modelProduits;
    QSqlQueryModel *modelLivraisons;
    Ui::producteurPanel *ui;
};
#endif // PRODUCTEURPANEL_H
