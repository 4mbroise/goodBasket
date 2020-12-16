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


void LivraisonSousConsommateur::setData(const QString& id,const QString& nom,const QString& idProduit,const QString& quantite,const QString& adressePC,const QString& dateLivraison)
{
    ui->id->setText("ID: "+id);
    ui->nom->setText("Nom: "+nom);
    ui->idProduit->setText("IdProduit: "+idProduit);
    ui->quantite->setText("Quantite: "+quantite);
    ui->adressePC->setText("AdressePC: "+adressePC);
    ui->dateLivraison->setText("DateLivraison: "+dateLivraison);
    ui->dateAchat->setText("DateAchat: pas encore confirmé");
}

void LivraisonSousConsommateur::setDataPrevue(const QString &id, const QString &nom, const QString &idProduit, const QString &quantite, const QString &adressePC, const QString &dateLivraison, const QString &dateAchat){
    this->idLivraison = std::stoi(id.toStdString());
    ui->id->setText("ID: "+id);
    ui->nom->setText("Nom: "+nom);
    ui->idProduit->setText("IdProduit: "+idProduit);
    ui->quantite->setText("Quantite: "+quantite);
    ui->adressePC->setText("AdressePC: "+adressePC);
    ui->dateLivraison->setText("DateLivraison: "+dateLivraison);
    ui->dateAchat->setText("DateAchat: "+dateAchat);
}
void LivraisonSousConsommateur::on_Supprimer_clicked(){

    QSqlQuery sqlQuery;

    QString query= QString("DELETE FROM Livraisons WHERE id = ");
    query.append(QString::number(ui));
    sqlQuery.prepare(query);

    if(!sqlQuery.exec())
    {
        qDebug() << "ERREUR DELETE Livraison SQL" << sqlQuery.lastError();
    }
    else
    {
        qDebug() << "SUCCES DELETE Livraisons SQL";
    }

}
