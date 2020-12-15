#include "producteuritemsousig.h"
#include "ui_producteuritemsousig.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>


ProducteurItemSousResponsable::ProducteurItemSousResponsable(QWidget *parent)
    : QWidget(parent), ui(new Ui::ProducteurItemSousResponsable)
{
    ui->setupUi(this);
}

ProducteurItemSousResponsable::~ProducteurItemSousResponsable()
{
    delete ui;
}


void ProducteurItemSousResponsable::setData(const QString& idProducteur,const QString& nom,const QString& tele,const QString& adresse,const QString& accord, const QString& idpc)
{
    ui->NumProducteur->setText("Nom : "+nom);
    ui->Adresse->setText("Adresse : "+adresse);
    ui->Tele->setText(tele);
    ui->Etat->setText("Etat : \n"+accord);
    idproducteur=idProducteur.toInt();
    idPC=idpc.toInt();
}




void ProducteurItemSousResponsable::on_recruter_clicked()
{
    QSqlQuery query;

    if(ui->Etat->text()=="Etat : \npas encore")
    {
        if(!query.exec("INSERT INTO AppartenanceProducteur VALUES("+QString::number(idPC)+", "+QString::number(idproducteur)+",\"en attente\")"))
        {
            qDebug() << "Erreur: Défaut de insertion d’une table. " << query.lastError();
        }
        else
        {
            qDebug() << "Insertion!";
        }
        ui->Etat->setText("Etat : \nen attente");
    }
}
