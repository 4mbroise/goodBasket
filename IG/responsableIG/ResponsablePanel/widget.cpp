#include "widget.h"
#include "ui_widget.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QListWidget>
#include "erreursousig.h"
#include "producteursousig.h"


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


    QSqlQuery sqlQuery;


    //inserer
    if(!sqlQuery.exec("INSERT INTO Erreurs VALUES(0, \" manque responsable \")"))
    {
        qDebug() << "Erreur: Défaut de insertion d’une table. " << sqlQuery.lastError();
    }
    else
    {
        qDebug() << "InsertionErreur!";
    }



    //inserer
    if(!sqlQuery.exec("INSERT INTO Producteurs VALUES(0, 1000)"))
    {
        qDebug() << "Erreur: Défaut de insertion d’une table. " << sqlQuery.lastError();
    }
    else
    {
        qDebug() << "InsertionProducteur!";
    }


    //inserer
    if(!sqlQuery.exec("INSERT INTO Livraisons VALUES(0, \"tomate\",0 ,0 ,0 , 2004-05-23, \" UL\")"))
    {
        qDebug() << "Erreur: Défaut de insertion d’une table. " << sqlQuery.lastError();
    }
    else
    {
        qDebug() << "Insertion!";
    }

    //inserer
    if(!sqlQuery.exec("INSERT INTO Produit VALUES(0, 10.0 ,\"tomate\",5 , 0)"))
    {
        qDebug() << "Erreur: Défaut de insertion d’une table. " << sqlQuery.lastError();
    }
    else
    {
        qDebug() << "Insertion!";
    }


}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_ConsulterReports_clicked()
{
    QSqlQuery query;

    ui->SousList->clear();

    //verifier id de Erreur
    if(!query.exec("select * from Erreurs"))
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


void Widget::on_PayerProducteur_clicked()
{
    QSqlQuery query;


    ui->SousList2->clear();


    //verifier id de producteur
    if(!query.exec("select * from Producteurs where id=\""+ui->NumProducteur->text()+"\""))
    {
        qDebug() << "Erreur: recherche ce producteur. " <<query.lastError();
    }
    else
    {
        qDebug() << "Trouvé!";
    }
    while(query.next())
    {
        QString  livraisonsId= query.value(0).toString();
        QString  payment= query.value(1).toString();
        int count=0;
        qDebug()<<livraisonsId<<payment;

        ProducteurSousResponsable* pItemWidget = new ProducteurSousResponsable(this);
        pItemWidget->setData(payment,QString(ui->NumProducteur->text()));
        QListWidgetItem* pItem = new QListWidgetItem();
        pItem->setSizeHint(QSize(240,640 ));
        ui->SousList2->addItem(pItem);
        count++;
        ui->SousList2->setItemWidget(pItem,pItemWidget);

    }
}

void Widget::on_confirmer_clicked()
{
}
