#include "livraisonsousig.h"
#include "ui_livraisonsousig.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QDebug>
#include <QListWidget>


LivraisonSousConsommateur::LivraisonSousConsommateur(QWidget *parent)
    : QWidget(parent), ui(new Ui::LivraisonSousConsommateur)
{
    ui->setupUi(this);

}

LivraisonSousConsommateur::~LivraisonSousConsommateur()
{
    delete ui;
}


void LivraisonSousConsommateur::setData(const QString& idProduit ,const QString &idProducteur,const QString& quantite)
{
    QSqlQuery query;

    qDebug() << "erreur---------------------" << idProduit;

    if(query.exec("select * from catalogue where produitId=\""+idProduit+"\",and producteurID=\""+idProducteur"\""))
    {
        qDebug() << "Erreur: recherche ce producteur. " <<query.lastError();
    }
    else
    {
        qDebug() << "Trouvé!";
    }
    while(query.next())
    {
        id INT PRIMARY KEY NOT NULL,\
        produitId INT NOT NULL,\
        quantite INT NOT NULL, \
        dateLivraison DATE NOT NULL,\
        dateAchat DATE NOT NULL)"
        QString  indice= ;
        QString  produitId= query.value(0).toString();
        QString  quantite= query.value(2).toString();
        QString  adreese= query.value(3).toString();
        QString  date= query.value(4).toString();
        QString  nomProducteur= query.value(5).toString();
        qDebug()<<livraisonsId<<nom<<quantite<<adreese<<date<<nomProducteur<<a;

        ui->total->setText(a);

        LivraisonSousConsommateur* pItemWidget = new LivraisonSousConsommateur(this);
        pItemWidget->setData(indice,nom,quantite,adreese,date,nomProducteur);
        QListWidgetItem* pItem = new QListWidgetItem();
        pItem->setSizeHint(QSize(240,640 ));
        ui->listWidget->addItem(pItem);
        ui->listWidget->setItemWidget(pItem,pItemWidget);

    }

}
