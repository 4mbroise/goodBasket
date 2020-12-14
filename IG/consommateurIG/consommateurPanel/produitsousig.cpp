#include "produitsousig.h"
#include "ui_produitsousig.h"
#include "../../../Outils/idgenerator.h"
#include "../../../livraison.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QDebug>

ProduitsousCatalogue::ProduitsousCatalogue(QWidget *parent)
    : QWidget(parent), ui(new Ui::ProduitsousCatalogue)
{
    ui->setupUi(this);

}

ProduitsousCatalogue::~ProduitsousCatalogue()
{
    delete ui;
}


void ProduitsousCatalogue::setData(const QString& id,const QString& nom,const QString& prix,const QString& quantite,const QString &idProducteur,const QString&idConsommateur,const QString& adressePC)
{
    ui->ID->setText("ID:"+id);
    ui->Nom->setText("Nom:"+nom);
    ui->Prix->setText("Prix:"+prix);
    ui->Quantite->setText("Quantite:"+quantite);
    ui->IdProducteur->setText("IdProducteur:"+idProducteur);
    ui->Nombre->setMaximum(quantite.toInt());
    ui->Nombre->setMinimum(0);
    this->idConsommateur=idConsommateur;
    this->adressePC=adressePC;
}


void ProduitsousCatalogue::on_AjouterAuPanier_clicked(){
    QSqlQuery query;
    QString idConsommateur=this->idConsommateur;
    QString idProduit=ui->ID->text();
    QString nom=ui->Nom->text();
    QString prix=ui->Prix->text();
    QString quantite=ui->Quantite->text();
    QString idProducteur=ui->IdProducteur->text();
    IdGenerator& gen = IdGenerator::Instance();
    int newId = gen.getNewIdUtilisateur();
    int id = newId;

    if(!query.exec("INSERT INTO Livraison(id,nom,idConsommatuer,idProduit,quantite,dateAchat,adressePC,prevue) VALUES( '"+QString(id)+"','"+nom+"','"+idConsommateur+"','"+idProduit+"','"+quantite+"',NOW(),'"+adressePC+"',false)"))
    {
        qDebug() << "Erreur: recherche ce produit. " <<query.lastError();
    }
    else
    {
        qDebug() << "Trouvé!";
    }

}
