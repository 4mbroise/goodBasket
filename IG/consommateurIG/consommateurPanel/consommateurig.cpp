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


Consommateurig::Consommateurig(QWidget *parent,Consommateur c)
    : QWidget(parent)
    , ui(new Ui::Consommateurig)
    ,consommateur(c)
{
    ui->setupUi(this);
    this->idConsommateur=c.getId();
    metterAJour();

}

void Consommateurig::setLivraison(const QString& idConsommateur){
    QSqlQuery query;

    qDebug() << "erreur---------------------" << idConsommateur;

    if(!query.exec("select * from Livraisons where idConsommateur=\""+idConsommateur+"\" and prevue=false"))
    {
        qDebug() << "Erreur: recherche ce producteur. " <<query.lastError();
    }
    else
    {
        qDebug() << "Trouvé!";
    }
    int total=0;
    while(query.next())
    {
        total++;
        QString  livraisonId= query.value(0).toString();
        QString  nom=query.value(1).toString();
        QString  produitId= query.value(3).toString();
        QString  quantite= query.value(4).toString();
        QString  dateLivraison= query.value(8).toString();
        QString  dateAchat= query.value(7).toString();
        QString  adressePC= query.value(6).toString();

        LivraisonSousConsommateur* pItemWidget = new LivraisonSousConsommateur(this);
        pItemWidget->setData(livraisonId,nom,produitId,quantite,dateLivraison,adressePC);
        QListWidgetItem* pItem = new QListWidgetItem();
        pItem->setSizeHint(QSize(1243,137));
        ui->Livraison->addItem(pItem);
        ui->Livraison->setItemWidget(pItem,pItemWidget);



        qDebug()<<livraisonId<<nom<<quantite<<dateLivraison<<adressePC<<dateAchat;

    }
    ui->LivraisonLabel->setText("La liste de la Livraison\nTotal:"+QString::number(total));
}

void Consommateurig::setLivraisonPrevue(const QString &idConsommateur){
    QSqlQuery query;

    qDebug() << "erreur---------------------" << idConsommateur;

    if(!query.exec("select * from Livraisons where idConsommateur=\""+idConsommateur+"\" and prevue=true"))
    {
        qDebug() << "Erreur: recherche ce producteur. " <<query.lastError();
    }
    else
    {
        qDebug() << "Trouvé!";
    }
    int total=0;
    while(query.next())
    {
        total++;
        QString  livraisonId= query.value(0).toString();
        QString  nom=query.value(1).toString();
        QString  produitId= query.value(3).toString();
        QString  quantite= query.value(4).toString();
        QString  dateLivraison= query.value(8).toString();
        QString  dateAchat= query.value(7).toString();
        QString  adressePC= query.value(6).toString();

        LivraisonSousConsommateur* pItemWidget = new LivraisonSousConsommateur(this);
        pItemWidget->setDataPrevue(livraisonId,nom,produitId,quantite,dateLivraison,adressePC,dateAchat);
        QListWidgetItem* pItem = new QListWidgetItem();
        pItem->setSizeHint(QSize(1240,50));
        ui->LivraisonPrevue->addItem(pItem);
        ui->LivraisonPrevue->setItemWidget(pItem,pItemWidget);


        qDebug()<<livraisonId<<nom<<quantite<<dateLivraison<<adressePC<<dateAchat;

    }
     ui->LivraisonPrevueLabel->setText("La liste de la Livraison\nTotal:"+QString(total));
}

void Consommateurig::setPC(){
    QSqlQuery query;

    qDebug() << "erreur---------------------" << endl;

    if(query.exec("select * from PointDeCollecte"))
    {
        qDebug() << "Erreur: recherche ce producteur. " <<query.lastError();
    }
    else
    {
        qDebug() << "Trouvé!";
    }
    while(query.next())
    {

        QString adresse =query.value(0).toString();
        qDebug()<<adresse<<endl;
        QListWidgetItem* pItem = new QListWidgetItem("adressePC:"+adresse);
        pItem->setSizeHint(QSize(1240,50));
        ui->PCListe->addItem(pItem);
    }
}

void Consommateurig::on_ConsulterCatalogue_clicked(){
        QSqlQuery query;

        qDebug() << "erreur---------------------" << endl;

        QListWidgetItem* pc=ui->PCListe->currentItem();
        if(pc==nullptr){
            qDebug()<<"il faut choisir un PC pour consulter"<<endl;
            return;
        }
       QString adresse=pc->text();

        /*query.prepare("select Produit.idProduit,Produit.nom,Produit.prix,Produit.quantite,Produit.idProducteur from Produit,Producteurs,PointDeCollecte\
                              where Produit.idProducteur=Producteurs.id\
                              and Producteurs.adressePC=PointDeCollecte.adresse\
                              and PointDeCollecte.adresse=:adresse;");*/
        query.prepare("select * from Produit,Producteurs,PointDeCollecte\
                              where Produit.idProducteur=Producteurs.id;");
        //query.bindValue(":adresse",adresse);

        if(!query.exec())
        {
            qDebug() << "Erreur:consulter catalogue. " <<query.lastError();
        }
        else
        {
            qDebug() << "Trouvé!";
        }
        CatalogueSousConsommateur* pListe =new CatalogueSousConsommateur(nullptr,adresse,this->idConsommateur);
        while(query.next())
        {
            QString idProduit=query.value(0).toString();
            QString nom=query.value(1).toString();
            QString prix=query.value(2).toString();
            QString quantite=query.value(3).toString();
            QString idProducteur=query.value(4).toString();
            qDebug()<<idProduit<<nom<<prix<<idProducteur<<endl;
            QString idConsommateur=QString::number(this->idConsommateur);
            pListe->setData();
            ProduitsousCatalogue* pItemWidget = new ProduitsousCatalogue(pListe);
            pItemWidget->setData(idProduit,nom,prix,quantite,idProducteur,this->idConsommateur,adresse);
            QListWidgetItem* pItem = new QListWidgetItem();
            pItem->setSizeHint(QSize(1240,50));
            pListe->getUI().Catalogue->addItem(pItem);
            pListe->getUI().Catalogue->setItemWidget(pItem,pItemWidget);
        }
        this->hide();
        connect(pListe,SIGNAL(sendsignal()),this,SLOT(reshow()));
        pListe->show();
}

Consommateurig::~Consommateurig(){
    delete this->ui;
}
void Consommateurig::reshow(){
    this->show();
}

void Consommateurig::metterAJour(){
    setLivraison(QString::number(idConsommateur));
    setLivraisonPrevue(QString::number(idConsommateur));
    setPC();
}
