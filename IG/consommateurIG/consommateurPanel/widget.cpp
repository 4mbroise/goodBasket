#include "widget.h"
#include "ui_widget.h"
#include "livraisonsousig.h"
#include "ui_livraisonsousig.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QDebug>
#include <QListWidget>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
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
    if(!sqlQuery.exec("INSERT INTO Livraison VALUES(1, 1, 1, '2020-12-12','2020-12-30')"))
    {
        qDebug() << "Erreur: Défaut de insertion d’une table. " << sqlQuery.lastError();
    }
    else
    {
        qDebug() << "InsertionLivraison!";
    }



}

void Widget::setLivraison(const QString& idConsommateur){
    QSqlQuery query;

    qDebug() << "erreur---------------------" << idConsommateur;

    if(query.exec("select * from Livraison where idConsommateur=\""+idConsommateur+"\",and prevue=false"))
    {
        qDebug() << "Erreur: recherche ce producteur. " <<query.lastError();
    }
    else
    {
        qDebug() << "Trouvé!";
    }
    while(query.next())
    {

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

}

void setLivraisonPrevue(const QString &idConsommateur){
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
    while(query.next())
    {

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
}

void Widget::on_consulter_catalogue_clicked(){{
    QSqlQuery query;

    ui->SousList->clear();

    if(!query.exec("select * from Produit where"))
    {
        qDebug() << "Erreur: recherche ce Erreur. " <<query.lastError();
    }
    else
    {
        qDebug() << "Trouvé!";
    }
    while(query.next())
    {
        QString  id= query.value(0).toString();
        QString  apercu= query.value(1).toString();
        qDebug()<<id<<apercu;

        ErreurSousResponsable* pItemWidget = new ErreurSousResponsable(this);
        pItemWidget->setData(apercu);
        QListWidgetItem* pItem = new QListWidgetItem();
        pItem->setSizeHint(QSize(240, 120));
        ui->SousList->addItem(pItem);
        ui->SousList->setItemWidget(pItem,pItemWidget);

    }

}

Widget::~Widget()
{
    delete ui;
}

