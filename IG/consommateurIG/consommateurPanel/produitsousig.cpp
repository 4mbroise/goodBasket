#include "produitsousig.h"
#include "ui_produitsousig.h"
#include "../../../Outils/idgenerator.h"
#include "../../../livraison.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QDebug>

ProduitsousCatalogue::ProduitsousCatalogue(CatalogueSousConsommateur *parent)
    : QWidget(parent), ui(new Ui::ProduitsousCatalogue),parent(parent)
{
    ui->setupUi(this);

}

ProduitsousCatalogue::~ProduitsousCatalogue()
{
    delete ui;
}


void ProduitsousCatalogue::setData(const QString& id,const QString& nom,const QString& prix,const QString& quantite,const QString &idProducteur,const int&idConsommateur,const QString& adressePC)
{
    ui->ID->setText("ID : "+id);
    ui->Nom->setText("Nom: "+nom);
    ui->Prix->setText("Prix: "+prix +" €/Kg");
    ui->Quantite->setText("Quantite : "+quantite+" Kg");
    ui->IdProducteur->setText("IdProducteur : "+idProducteur);
    ui->Nombre->setMaximum(quantite.toInt());
    ui->Nombre->setMinimum(0);
    this->idConsommateur=idConsommateur;
    this->adressePC=adressePC;
}


void ProduitsousCatalogue::on_AjouterAuPanier_clicked(){
    QString idConsommateur=QString::number(this->idConsommateur);
    QString idProduit=ui->ID->text();
    QString nom=ui->Nom->text();
    QString prix=ui->Prix->text();
    QString quantite=ui->Quantite->text();
    QString idProducteur=ui->IdProducteur->text();
    Consommateur consommateur=parent->getConsommateur();
    consommateur.ajouterProduitAuPanier(nom,this->idConsommateur,idProduit.toInt(),quantite.toInt(), prix.toInt(), adressePC);
}



