#include "gestionnaireig.h"
#include "ui_gestionnaireig.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QListWidget>
#include "erreursousgestionnaire.h"
#include "ui_erreursousgestionnaire.h"
#include "pcsousig.h"
#include "ui_pcsousig.h"


GestionnaireIG::GestionnaireIG(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GestionnaireIG)
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
}

GestionnaireIG::~GestionnaireIG()
{
    delete ui;
}


void GestionnaireIG::on_ConsulterReports_clicked()
{
    QSqlQuery query;

    ui->SousList->clear();

    //verifier id de producteur
    if(!query.exec("select * from Erreurs"))
    {
        qDebug() << "Erreur: recherche Erreurs. " <<query.lastError();
    }
    else
    {
        qDebug() << "Trouvé!";
    }
    while(query.next())
    {
        QString apercu= query.value(1).toString();

        qDebug()<<apercu;

        ErreurSousGestionnaire* pItemWidget = new ErreurSousGestionnaire(this);
        QListWidgetItem* pItem = new QListWidgetItem();
        pItemWidget->setData(apercu);
        pItem->setSizeHint(QSize(240, 120));
        ui->SousList->addItem(pItem);
        ui->SousList->setItemWidget(pItem,pItemWidget);
    }
}

void GestionnaireIG::on_ValiderPC_clicked()
{
    QSqlQuery query;

    ui->SousList->clear();

    //verifier id de producteur
    if(!query.exec("select * from PointDeCollecte where valider = \"false\""))
    {
        qDebug() << "Erreur: recherche PC. " <<query.lastError();
    }
    else
    {
        qDebug() << "Trouvé!";
    }
    while(query.next())
    {
        QString id= query.value(1).toString();
        QString adresse= query.value(2).toString();
        QString nom= QString(" ");

        if(!query.exec("select * from Utilisateurs where UtilisateurID = \""+id+"\""))
        {
            qDebug() << "Erreur: recherche PC. " <<query.lastError();
        }
        else
        {
            qDebug() << "Trouvé!";
        }
        while(query.next())
        {
            nom= query.value(1).toString();
        }

        qDebug()<<adresse<<nom;

        PcSousGestionnaire* pItemWidget = new PcSousGestionnaire(this);
        QListWidgetItem* pItem = new QListWidgetItem();
        pItemWidget->setData(id,nom,adresse);
        pItem->setSizeHint(QSize(240, 120));
        ui->SousList->addItem(pItem);
        ui->SousList->setItemWidget(pItem,pItemWidget);
    }
}
