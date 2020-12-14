#include "livraisonsousig.h"
#include "ui_livraisonsousig.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QDebug>

LivraisonSousConsommateur::LivraisonSousConsommateur(QWidget *parent)
    : QWidget(parent), ui(new Ui::LivraisonSousConsommateur)
{
    ui->setupUi(this);

}

LivraisonSousConsommateur::~LivraisonSousConsommateur()
{
    delete ui;
}


void LivraisonSousConsommateur::setData(const QString& id,const QString& nom,const QString& idProduit,const QString& quantite,const QString& adressePC,const QString& dateLivraison,const QString& dateAchat)
{
    ui->id->setText("id:"+id);
    ui->nom->setText("nom:"+nom);
    ui->idProduit->setText("idProduit:"+idProduit);
    ui->quantite->setText("quantite:"+quantite);
    ui->adressePC->setText("adressePC:"+adressePC);
    ui->dateLivraison->setText("dateLivraison:"+dateLivraison);
    ui->dateAchat->setText("dateAchat:"+dateAchat);
}

void LivraisonSousConsommateur::on_Supprimer_clicked(){

}
