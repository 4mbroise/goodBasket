#include "cataloguesousig.h"
#include "ui_cataloguesousig.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QDebug>
#include <QListWidget>


CatalogueSousConsommateur::CatalogueSousConsommateur(QWidget *parent)
    : QWidget(parent), ui(new Ui::CatalogueSousConsommateur)
{
    ui->setupUi(this);

}

CatalogueSousConsommateur::~CatalogueSousConsommateur()
{
    delete ui;
}


void CatalogueSousConsommateur::setData(const QString& id,const QString& nom,const QString& quantite,const QString& adresse,const QString& date,const QString& nomProducteur)
{
   /* ui->id->setText("id:"+id);
    ui->nom->setText("nom:"+nom);
    ui->idProduit->setText("idProduit:"+idProduit);
    ui->quantite->setText("quantite:"+quantite);
    ui->adressePC->setText("adressePC:"+adressePC);
    ui->dateLivraison->setText("dateLivraison:"+dateLivraison);
    ui->dateAchat->setText("dateAchat:"+dateAchat);*/

}
