#include "consommateurig.h"
#include "ui_consommateurig.h"
#include "livraisonsousig.h"
#include "ui_livraisonsousig.h"
#include "cataloguesousig.h"
#include "ui_cataloguesousig.h"
#include "produitsousig.h"
#include "ui_produitsousig.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QListWidget>
#include <thread>

Consommateurig::Consommateurig(QWidget *parent,Consommateur c)
    : QWidget(parent)
    , ui(new Ui::Consommateurig)
    ,consommateur(c)
{
    this->idConsommateur=c.getId();
    ui->setupUi(this);
    setPC();
    metterAJour();
    ui->ID->setText("ID: "+QString::number(idConsommateur));
}


Consommateurig::~Consommateurig(){
    delete this->ui;
}


void Consommateurig::setLivraison(int idConsommateur){
    QSqlQuery query;

    for(int i=0;i<ui->Livraison->count();i++){
        ui->Livraison->takeItem(i);
    }
    qDebug() << "erreur---------------------" << idConsommateur;
    query.prepare("select * from Livraisons where idConsommateur=:id and prevue=false");
    query.bindValue(":id",idConsommateur);
    if(!query.exec())
    {
        qDebug() << "Erreur: " <<query.lastError();
    }
    else
    {
        qDebug() << "Trouvé!";
    }
    double total=0;
    while(query.next())
    {
        total++;
        QString  livraisonId= query.value(0).toString();
        QString  nom=query.value(1).toString();
        QString  prix=query.value(5).toString();
        QString  produitId= query.value(3).toString();
        QString  quantite= query.value(4).toString();
        QString  dateLivraison= query.value(8).toString();
        QString  dateAchat= query.value(7).toString();
        QString  adressePC= query.value(6).toString();

        total+=quantite.toUInt()*prix.toDouble();
        LivraisonSousConsommateur* pItemWidget = new LivraisonSousConsommateur(this);
        pItemWidget->setData(livraisonId,nom,produitId,prix,quantite,dateLivraison,adressePC);
        QListWidgetItem* pItem = new QListWidgetItem();
        pItem->setSizeHint(QSize(1240,50));
        ui->Livraison->addItem(pItem);
        ui->Livraison->setItemWidget(pItem,pItemWidget);

        qDebug()<<livraisonId<<nom<<quantite<<dateLivraison<<adressePC<<dateAchat;

    }
    ui->LivraisonLabel->setText("La liste de la Livraison\n Prix Total:"+QString::number(total));
}

void Consommateurig::setLivraisonPrevue(int idConsommateur){
    QSqlQuery query;


    for(int i=0;i<ui->LivraisonPrevue->count();i++){
        ui->LivraisonPrevue->takeItem(i);
    }
    query.prepare("select * from Livraisons where idConsommateur=:id and prevue=1");
    query.bindValue(":id",idConsommateur);
    if(!query.exec()){
        qDebug() << "Erreur: " <<query.lastError();
     } else {
             qDebug() << "Trouvé!";
         }
    int total=0;
    while(query.next())
    {
        QString  livraisonId= query.value(0).toString();
        QString  nom=query.value(1).toString();
        QString  produitId= query.value(3).toString();
        QString  quantite= query.value(4).toString();
        QString  prix=query.value(5).toString();
        QString  dateLivraison= query.value(8).toString();
        QString  dateAchat= query.value(7).toString();
        QString  adressePC= query.value(6).toString();

        total+=quantite.toUInt()*prix.toDouble();
        LivraisonSousConsommateur* pItemWidget = new LivraisonSousConsommateur(this);
        pItemWidget->setDataPrevue(livraisonId,nom,produitId,prix,quantite,dateLivraison,adressePC,dateAchat);
        QListWidgetItem* pItem = new QListWidgetItem();
        pItem->setSizeHint(QSize(1240,50));
        ui->LivraisonPrevue->addItem(pItem);
        ui->LivraisonPrevue->setItemWidget(pItem,pItemWidget);


        qDebug()<<livraisonId<<nom<<quantite<<dateLivraison<<adressePC<<dateAchat;

    }
     ui->LivraisonPrevueLabel->setText("La liste de la LivraisonPrevue\nPrix Total:"+QString::number(total));
}

void Consommateurig::setPC(){
    QSqlQuery query;
    if(!query.exec("select PointDeCollecte.adresse from PointDeCollecte;"))
    {
        qDebug() << "Erreur:  " <<query.lastError();
    }
    else
    {
        qDebug() << "Trouvé!";
    }
    while(query.next())
    {

        QString adresse =query.value(0).toString();
        qDebug()<<adresse<<endl;
        QListWidgetItem* pItem = new QListWidgetItem(adresse);
        pItem->setSizeHint(QSize(1240,50));
        ui->PCListe->addItem(pItem);
    }
}

void Consommateurig::on_ConsulterCatalogue_clicked(){
        QListWidgetItem* pc=ui->PCListe->currentItem();
        if(pc==nullptr){
            qDebug()<<"il faut choisir un PC pour consulter"<<endl;
            return;
        }
        QString adresse=pc->text();
        qDebug()<<adresse<<endl;
        QSqlQuery query;
        query.prepare("select distinct Produit.idProduit, Produit.prix, Produit.nom, Produit.quantite, Produit.idProducteur\
                      from Produit join Producteurs join PointDeCollecte join AppartenanceProducteur\
                      where Produit.idProducteur=Producteurs.id\
                      and AppartenanceProducteur.idProducteur=Producteurs.id\
                      and AppartenanceProducteur.idPC=PointDeCollecte.idPointDeCollecte\
                      and PointDeCollecte.adresse=:adresse;");
        query.bindValue(":adresse",adresse);

        if(!query.exec())
        {
            qDebug() << "Erreur: " <<query.lastError();
        }
        else
        {
            qDebug() << "Trouvé!";
        }
        CatalogueSousConsommateur* pListe =new CatalogueSousConsommateur(nullptr,adresse,this->consommateur);
        while(query.next())
        {
            QString idProduit=query.value(0).toString();
            QString prix=query.value(1).toString();
            QString nom=query.value(2).toString();
            QString quantite=query.value(3).toString();
            QString idProducteur=query.value(4).toString();
            qDebug()<<idProduit<<nom<<prix<<idProducteur<<endl;
            QString idConsommateur=QString::number(this->idConsommateur);
            pListe->setData();
            ProduitSousCatalogue* pItemWidget = new ProduitSousCatalogue(pListe);
            pItemWidget->setData(idProduit,nom,prix,quantite,idProducteur,this->idConsommateur,adresse);
            QListWidgetItem* pItem = new QListWidgetItem();
            pItem->setSizeHint(QSize(1240,50));
            pListe->getUI().Catalogue->addItem(pItem);
            pListe->getUI().Catalogue->setItemWidget(pItem,pItemWidget);
        }
        this->close();
        connect(pListe,SIGNAL(sendsignal()),this,SLOT(reshow()));
        pListe->show();
}

void Consommateurig::on_CommanderPanier_clicked(){
    this->consommateur.commanderPanier();
    metterAJour();
}

void Consommateurig::reshow(){
    this->show();
    metterAJour();
}


void Consommateurig::metterAJour(){
    setLivraison(idConsommateur);
    setLivraisonPrevue(idConsommateur);
}
