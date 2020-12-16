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
    ui->Nom->setText(nom);
    ui->Prix->setText("Prix: "+prix +" €/Kg");
    ui->Quantite->setText("Quantite : "+quantite+" Kg");
    ui->IdProducteur->setText("IdProducteur : "+idProducteur);
    ui->Nombre->setMaximum(quantite.toInt());
    ui->Nombre->setMinimum(0);
    this->idConsommateur=idConsommateur;
    this->adressePC=adressePC;
}


void ProduitsousCatalogue::on_AjouterAuPanier_clicked(){
    QSqlQuery query;
    QString idConsommateur=QString::number(this->idConsommateur);
    QString idProduit=ui->ID->text();
    QString nom=ui->Nom->text();
    QString prix=ui->Prix->text();
    QString quantite=ui->Quantite->text();
    QString idProducteur=ui->IdProducteur->text();
    IdGenerator& gen = IdGenerator::Instance();
    int newId = gen.getNewIdUtilisateur();
    int id = newId;
    query.prepare("INSERT INTO Livraison(id,nom,idConsommatuer,idProduit,quantite,prix,adressePC,prevue)"
                  "VALUES(:id,:nom,:idConsommateur,:idProduit,:quantite,:prix,:adressePC,:prevue)");
    query.bindValue(":id",id);
    query.bindValue(":nom",nom);
    query.bindValue(":idConsommateur",idConsommateur);
    query.bindValue(":idProduit",idProduit);
    query.bindValue(":quantite",quantite);
    query.bindValue(":prix",prix);
    query.bindValue(":adressePC",adressePC);
    query.bindValue(":prevue",false);

    if(!query.exec())
    {
        qDebug() << "Erreur: " <<query.lastError();
    }
    else
    {
        qDebug() << "Trouvé!";
    }
    query.clear();
    query.prepare("select quantite from Produit where idProduit=:idP");
    query.bindValue(":idP",idProduit);
    if(!query.exec())
    {
        qDebug() << "Erreur: " <<query.lastError();
    }
    else
    {
        qDebug() << "Trouvé!";
    }
    query.next();
    int q=query.value(0).toInt();
    query.prepare("UPDATE Produit SET quantite=:quantite whereidProduit=:idP");
    query.bindValue(":idP",idProduit);
    q=q-quantite.toInt();
    query.bindValue(":quantite",q);
    if(!query.exec())
    {
        qDebug() << "Erreur: " <<query.lastError();
    }
    else
    {
        qDebug() << "Trouvé!";
    }

    parent->mettreAJour();
}



