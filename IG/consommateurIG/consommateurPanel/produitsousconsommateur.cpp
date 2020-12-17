#include "produitsousconsommateur.h"
#include "ui_produitsousconsommateur.h"
#include "../../../Outils/idgenerator.h"
#include "../../../livraison.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QDebug>

ProduitSousCatalogue::ProduitSousCatalogue(CatalogueSousConsommateur *parent)
    : QWidget(parent), ui(new Ui::ProduitsousCatalogue),parent(parent)
{
    ui->setupUi(this);

}

ProduitSousCatalogue::~ProduitSousCatalogue()
{
    delete ui;
}


void ProduitSousCatalogue::setData(const QString& id,const QString& nom,const QString& prix,const QString& quantite,const QString &idProducteur,const int&idConsommateur,const QString& adressePC)
{
    this->id=id;
    this->nom=nom;
    this->prix=prix;
    this->quantite=quantite;
    this->idProducteur=idProducteur;
    this->idConsommateur=idConsommateur;
    this->adressePC=adressePC;
    ui->ID->setText("ID : "+id);
    ui->Nom->setText("Nom: "+nom);
    ui->Prix->setText("Prix: "+prix +" €/Kg");
    ui->Quantite->setText("Quantite : "+quantite+" Kg");
    ui->IdProducteur->setText("IdProducteur : "+idProducteur);
    ui->Nombre->setMaximum(quantite.toInt());
    ui->Nombre->setMinimum(0);
}


void ProduitSousCatalogue::on_AjouterAuPanier_clicked(){
    Consommateur consommateur=parent->getConsommateur();
    consommateur.ajouterProduitAuPanier(nom,this->idConsommateur,id.toInt(),ui->Nombre->value(), prix.toDouble(), adressePC);
    QSqlQuery query;
    query.prepare("select quantite from Produit where idProduit=:idP");
    query.bindValue(":idP",id);
    if(!query.exec())
    {
        qDebug() << "Erreur: " <<query.lastError();
    }
    else
    {
        qDebug() << "Réussi!";
    }
    query.next();
    QString q=query.value(0).toString();
    ui->Quantite->setText("Quantite :"+q+" Kg");
}



