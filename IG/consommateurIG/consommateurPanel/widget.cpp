#include "widget.h"
#include "ui_widget.h"
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
    // preparer exec
    QString createSqlLivraison = QString("CREATE TABLE Livraison (\
                              id INT PRIMARY KEY NOT NULL,\
                              produitId INT NOT NULL,\
                              quantite INT NOT NULL, \
                              dateLivraison DATE NOT NULL,\
                              dateAchat DATE NOT NULL)");
    sqlQuery.prepare(createSqlLivraison);
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

    //creer tableau ProducteursLivaison
    // preparer exec
    QString createSqlLivraisonPrevue = QString("CREATE TABLE LivraisonPrevue (\
                                               id INT PRIMARY KEY NOT NULL,\
                                               produitId INT NOT NULL,\
                                               quantite INT NOT NULL, \
                                               dateLivraison TEXT NOT NULL,\
                                               dateAchat TEXT NOT NULL)");
    sqlQuery.prepare(createSqlLivraisonPrevue);
    // creer tableau
    if(!sqlQuery.exec())
    {
        qDebug() << "Défaut de création d’une table. " << sqlQuery.lastError();
    }
    else
    {     qDebug() << "Tableau créé!";  }

    //inserer
    if(!sqlQuery.exec("INSERT INTO LivraisonPrevue VALUES(1, 1, 1, '2020-12-12','2020-12-30')"))
    {
        qDebug() << "Erreur: Défaut de insertion d’une table. " << sqlQuery.lastError();
    }
    else
    {
        qDebug() << "Insertion!";
    }

    //creer tableau ProducteursLivaison
    // preparer exec
    QString createSqlProduit = QString("CREATE TABLE Produits (\
                                               id INT PRIMARY KEY NOT NULL,\
                                               produitId INT NOT NULL,\
                                               quantite INT NOT NULL, \
                                               dateLivraison TEXT NOT NULL,\
                                               dateAchat TEXT NOT NULL)");
    sqlQuery.prepare(createSqlLivraisonPrevue);
    // creer tableau
    if(!sqlQuery.exec())
    {
        qDebug() << "Défaut de création d’une table. " << sqlQuery.lastError();
    }
    else
    {     qDebug() << "Tableau créé!";  }

    //inserer
    if(!sqlQuery.exec("INSERT INTO LivraisonPrevue VALUES(1, 1, 1, '2020-12-12','2020-12-30')"))
    {
        qDebug() << "Erreur: Défaut de insertion d’une table. " << sqlQuery.lastError();
    }
    else
    {
        qDebug() << "Insertion!";
    }
}

void Widget::on_ajouter_panier_clicked()
{
    QSqlQuery query;


}

Widget::~Widget()
{
    delete ui;
}

