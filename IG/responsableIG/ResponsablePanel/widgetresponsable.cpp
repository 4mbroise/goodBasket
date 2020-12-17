#include "widgetresponsable.h"
#include "ui_widgetresponsable.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QListWidget>
#include "erreursousig.h"
#include "producteursousig.h"
#include "consommateursousig.h"
#include "../../GestionnaireIG/Gestionnaire/gestionnaireig.h"

WidgetResponsable::WidgetResponsable(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::WidgetResponsable)
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
    if(!sqlQuery.exec("INSERT INTO Producteurs VALUES(0)"))
    {
        qDebug() << "Erreur: Défaut de insertion d’une table. " << sqlQuery.lastError();
    }
    else
    {
        qDebug() << "InsertionProducteur!";
    }


    //inserer
    if(!sqlQuery.exec("INSERT INTO Livraisons VALUES(3, \"pomme de terre\",1 ,0 ,20 ,1, \" 2005-03-29\" , \" UL\", \" 2005-03-27\" , \"true\",\"false\",\"false\")"))
    {
        qDebug() << "Erreur: Défaut de insertion d’une table. " << sqlQuery.lastError();
    }
    else
    {
        qDebug() << "Insertion!";
    }

    //inserer
    if(!sqlQuery.exec("INSERT INTO Livraisons VALUES(1, \"pomme\",1 ,0 ,10, 1,\" 2010-10-23\", \" UL\", \"2010-10-21\",  \"false\",\"true\",\"false\")"))
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

    //inserer
    if(!sqlQuery.exec("INSERT INTO Consommateur VALUES(0)"))
    {
        qDebug() << "Erreur: Défaut de insertion d’une table. " << sqlQuery.lastError();
    }
    else
    {
        qDebug() << "Insertion!";
    }

    //inserer
    if(!sqlQuery.exec("INSERT INTO Consommateur VALUES(1)"))
    {
        qDebug() << "Erreur: Défaut de insertion d’une table. " << sqlQuery.lastError();
    }
    else
    {
        qDebug() << "Insertion!";
    }

}

WidgetResponsable::~WidgetResponsable()
{
    delete ui;
}


void WidgetResponsable::on_PayerProducteur_clicked()
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

        ProducteurSousResponsable* pItemWidget = new ProducteurSousResponsable(this);
        pItemWidget->setData(QString(ui->NumProducteur->text()));
        QListWidgetItem* pItem = new QListWidgetItem();
        pItem->setSizeHint(QSize(240,640));
        ui->SousList2->addItem(pItem);
        ui->SousList2->setItemWidget(pItem,pItemWidget);

    }
}


void WidgetResponsable::on_Rembourser_clicked()
{
    QSqlQuery query;


    ui->SousList2->clear();


    //verifier id de producteur
    if(!query.exec("select * from Consommateur where id=\""+ui->NumConsommateur->text()+"\""))
    {
        qDebug() << "Erreur: recherche ce consommateur. " <<query.lastError();
    }
    else
    {
        qDebug() << "Trouvé!";
    }
    while(query.next())
    {

        ConsommateurSousResponsable* pItemWidget = new ConsommateurSousResponsable(this);
        pItemWidget->setData(QString(ui->NumConsommateur->text()));
        qDebug() << "Trouvé!";
        QListWidgetItem* pItem = new QListWidgetItem();
        pItem->setSizeHint(QSize(240,640 ));
        ui->SousList2->addItem(pItem);
        ui->SousList2->setItemWidget(pItem,pItemWidget);

    }
}


void WidgetResponsable::on_RecruterProducteur_clicked()
{
    QSqlQuery query;


    ui->SousList2->clear();



    ProducteurSousResponsable* pItemWidget = new ProducteurSousResponsable(this);
    pItemWidget->setProducteurItem(QString(ui->NumPC->text()));
    QListWidgetItem* pItem = new QListWidgetItem();
    pItem->setSizeHint(QSize(240,640 ));
    ui->SousList2->addItem(pItem);
    ui->SousList2->setItemWidget(pItem,pItemWidget);

}

void WidgetResponsable::on_ReporterReports_clicked()
{
    QSqlQuery query;

    ui->SousList->clear();

    ErreurSousResponsable* pItemWidget = new ErreurSousResponsable(this);
    QListWidgetItem* pItem = new QListWidgetItem();
    pItem->setSizeHint(QSize(240, 120));
    ui->SousList->addItem(pItem);
    ui->SousList->setItemWidget(pItem,pItemWidget);
}

void WidgetResponsable::on_Gestionnaire_clicked()
{
    GestionnaireIG* ges=new GestionnaireIG();
    ges->show();
    this->close();
}
