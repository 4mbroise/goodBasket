#include "livraisonsousconsommateur.h"
#include "ui_livraisonsousconsommateur.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
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


void LivraisonSousConsommateur::setData(const QString& id,const QString& nom,const QString& idProduit,const QString& prix,const QString& quantite,const QString& adressePC,const QString& dateLivraison)
{
    this->idLivraison = id.toInt();
    ui->id->setText("ID: "+id);
    ui->nom->setText("Nom: "+nom);
    ui->idProduit->setText("IdProduit: "+idProduit);
    ui->Prix->setText("Prix: "+prix);
    ui->quantite->setText("Quantite: "+quantite);
    ui->adressePC->setText("AdressePC: "+adressePC);
    ui->dateLivraison->setText("DateLivraison: "+dateLivraison);
    ui->dateAchat->setText("DateAchat: pas encore confirmé");
}

void LivraisonSousConsommateur::setDataPrevue(const QString& id,const QString& nom,const QString& idProduit,const QString& prix,const QString& quantite,const QString& adressePC,const QString& dateLivraison,const QString& dateAchat)
{
    this->idLivraison = id.toInt();
    ui->id->setText("ID: "+id);
    ui->nom->setText("Nom: "+nom);
    ui->idProduit->setText("IdProduit: "+idProduit);
    ui->Prix->setText("Prix: "+prix);
    ui->quantite->setText("Quantite: "+quantite);
    ui->adressePC->setText("AdressePC: "+adressePC);
    ui->dateLivraison->setText("DateLivraison: "+dateLivraison);
    ui->dateAchat->setText("DateAchat: "+dateAchat);
    ui->Supprimer->hide();
}
void LivraisonSousConsommateur::on_Supprimer_clicked(){

    QSqlQuery sqlQuery;

     sqlQuery.prepare("DELETE FROM Livraisons WHERE id =:id ");
     sqlQuery.bindValue(":id",idLivraison);

    if(!sqlQuery.exec())
    {
        qDebug() << "ERREUR DELETE Livraison SQL" << sqlQuery.lastError();
    }
    else
    {
        qDebug() << "SUCCES DELETE Livraisons SQL";
    }
    delete this;

}
