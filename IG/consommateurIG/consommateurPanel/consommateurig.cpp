#include "consommateurig.h"
#include "ui_consommateurig.h"
#include "livraisonsousig.h"
#include "ui_livraisonsousig.h"
#include "pcsousig.h"
#include "ui_pcsousig.h"
#include "cataloguesousig.h"
#include "ui_cataloguesousig.h"
#include "produitsousig.h"
#include "ui_produitsousig.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QDebug>
#include <QListWidget>


Consommateurig::Consommateurig(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Consommateurig)
{
    ui->setupUi(this);

    //creer et connect à muSql maze
    QSqlDatabase  db =QSqlDatabase::addDatabase("QSQLITE");    // type
                  db.setDatabaseName("maze");                     //nom de database
                  db.setHostName("127.0.0.1");                    //Host
                  db.setPort(3306);                               //Porte
                  db.setUserName("root");                         //login
                  db.setPassword("root");                       //mot de passe
    db.setDatabaseName("../../../db.sqlite");

    if (! db.open()) {
        qDebug()<<"open database error!";
        return;
    }
    else{
        qDebug()<<"open database success!";
    }

    //sqlquery
    QSqlQuery sqlQuery;




    //creer tableau Livraison
    // creer tableau
    if(!sqlQuery.exec())
    {
        qDebug() << "Défaut de création d’une table. " << sqlQuery.lastError();
    }
    else
    {     qDebug() << "Tableau créé!";  }


    //inserer
    if(!sqlQuery.exec("INSERT INTO Consommateur VALUES()"))
    {
        qDebug() << "Erreur: Défaut de insertion d’une table. " << sqlQuery.lastError();
    }
    else
    {
        qDebug() << "InsertionLivraison!";
    }


    setLivraison(QString(1));
    setLivraisonPrevue(QString(1));
    setPC();
}

void Consommateurig::setLivraison(const QString& idConsommateur){
    QSqlQuery query;

    qDebug() << "erreur---------------------" << idConsommateur;

    if(!query.exec("select * from Livraison where idConsommateur=\""+idConsommateur+"\",and prevue=false"))
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
        QString  dateLivraison= query.value(5).toString();
        QString  adressePC= query.value(6).toString();
        QString  dateAchat= query.value(7).toString();
        LivraisonSousConsommateur* pItemWidget = new LivraisonSousConsommateur(this);
        pItemWidget->setData(livraisonId,nom,produitId,quantite,dateLivraison,adressePC,dateAchat);
        QListWidgetItem* pItem = new QListWidgetItem();
        pItem->setSizeHint(QSize(240,640 ));
        ui->Livraison->addItem(pItem);
        ui->Livraison->setItemWidget(pItem,pItemWidget);

    }
    ui->LivraisonLabel->setText("La liste de la Livraison\nTotal:"+QString(total));
}

void Consommateurig::setLivraisonPrevue(const QString &idConsommateur){
    QSqlQuery query;

    qDebug() << "erreur---------------------" << idConsommateur;

    if(query.exec("select * from Livraison where idConsommateur=\""+idConsommateur+"\",and prevue=true"))
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
        QString  dateLivraison= query.value(5).toString();
        QString  adressePC= query.value(6).toString();
        QString  dateAchat= query.value(7).toString();

        LivraisonSousConsommateur* pItemWidget = new LivraisonSousConsommateur(this);
        pItemWidget->setData(livraisonId,nom,produitId,quantite,dateLivraison,adressePC,dateAchat);
        QListWidgetItem* pItem = new QListWidgetItem();
        pItem->setSizeHint(QSize(240,640 ));
        ui->LivraisonPrevue->addItem(pItem);
        ui->LivraisonPrevue->setItemWidget(pItem,pItemWidget);

    }
     ui->LivraisonPrevueLabel->setText("La liste de la Livraison\nTotal:"+QString(total));
}

void Consommateurig::setPC(){
    QSqlQuery query;

    qDebug() << "erreur---------------------" << endl;

    if(query.exec("select * from PointDeCollecte;"))
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

        PcSousConsommateur* pItemWidget = new PcSousConsommateur(this);
        pItemWidget->setData(adresse);
        QListWidgetItem* pItem = new QListWidgetItem();
        pItem->setSizeHint(QSize(240,640 ));
        ui->PCListe->addItem(pItem);
        ui->PCListe->setItemWidget(pItem,pItemWidget);
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
        if(!query.exec("select Produit.idProduit,Produit.nom,Produit.prix,Produit.quantite,Produit.idProducteur from Produit,Producteurs,PointDeCollecte"
                      "where Produit.idProducteur=Producteurs.id"
                      "and Producteurs.adressePC=PointDeCollecte.adresse"
                      "and PointDeCollecte.adresse=\""+adresse+"\";"))
        {
            qDebug() << "Erreur: recherche ce producteur. " <<query.lastError();
        }
        else
        {
            qDebug() << "Trouvé!";
        }
         CatalogueSousConsommateur* pListe =new CatalogueSousConsommateur(this);
        while(query.next())
        {
            QString idProduit=query.value(0).toString();
            QString nom=query.value(0).toString();
            QString prix=query.value(0).toString();
            QString quantite=query.value(0).toString();
            QString idProducteur=query.value(0).toString();
            QString idConsommateur=ui->ID->text();
            QString adressePC=ui->PC->text();
            pListe->setData(adresse,idConsommateur);
            ProduitsousCatalogue* pItemWidget = new ProduitsousCatalogue(pListe);
            pItemWidget->setData(idProduit,nom,prix,quantite,idProducteur,idConsommateur,adressePC);
            QListWidgetItem* pItem = new QListWidgetItem();
            pItem->setSizeHint(QSize(240,640 ));
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

