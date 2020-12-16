#include "producteursousig.h"
#include "ui_producteursousig.h"
#include "produitsousig.h"
#include "ui_produitsousig.h"
#include "producteuritemsousig.h"
#include "ui_producteuritemsousig.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QListWidget>


ProducteurSousResponsable::ProducteurSousResponsable(QWidget *parent)
    : QWidget(parent), ui(new Ui::ProducteurSousResponsable)
{
    ui->setupUi(this);


}

ProducteurSousResponsable::~ProducteurSousResponsable()
{
    delete ui;
}


void ProducteurSousResponsable::setData(const QString& id)
{
    QSqlQuery query;

    qDebug() << "erreur---------------------" << id;

    if(!query.exec("select * from Livraisons where idProduit= \
                   (select idProduit from Produit where idProducteur=\""+id+"\") \
                   and payerResponsable = \"false\" \
                   and annuler = \"false\" "))
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
        QString  nom= query.value(1).toString();
        QString  quantite= query.value(4).toString();
        QString  prix = query.value(5).toString();
        QString  adreese= query.value(8).toString();
        QString  date= query.value(6).toString();

        qDebug()<<livraisonsId<<nom<<quantite<<adreese<<date<<id;

            int somme=ui->total->text().toInt();

            qDebug()<<somme;

            somme+=prix.toInt()*quantite.toInt();

            qDebug()<<somme;

            ui->total->setText(QString::number(somme));

        ProduitSousResponsable* pItemWidget = new ProduitSousResponsable(this);
        pItemWidget->setData(livraisonsId,nom,quantite,prix,adreese,date,id);
        QListWidgetItem* pItem = new QListWidgetItem();
        pItem->setSizeHint(QSize(240,120 ));
        ui->listWidget->addItem(pItem);
        ui->listWidget->setItemWidget(pItem,pItemWidget);
    }
    idProducteur=id.toInt();
    etatPayer=true;
}

void ProducteurSousResponsable::on_Confirmer_clicked()
{
    QSqlQuery query;
    if(etatPayer){

            if(!query.exec("UPDATE Livraisons \
                           SET  payerResponsable = \"true\" \
                           WHERE payerResponsable = \"false\" \
                           and  idProduit = \
                           (select idProduit from Produit where idProducteur=\""+QString::number(idProducteur)+"\") \
                           and annuler = \"false\" "))
            {
                qDebug() << "Erreur: Défaut de Modification d’une table. " << query.lastError();
            }
            else
            {
                qDebug() << "Modification!";
            }

    etatPayer=false;
    }
    this->deleteLater();
}

void ProducteurSousResponsable::setProducteurItem(const QString& idPc)
{
    QSqlQuery query;
    QSqlQuery query2;

    qDebug() << "erreur---------------------" << idPc;


    if(!query.exec("select * from Utilisateurs where UtilisateurID IN \
                    (select id from Producteurs) "))
    {
        qDebug() << "Erreur: recherche ce producteur. " <<query.lastError();
    }
    else
    {
        qDebug() << "Trouvé!";
    }
    while(query.next())
    {
        QString  nom= query.value(1).toString();
        QString  tele= query.value(4).toString();
        QString  adreese= query.value(3).toString();
        QString  idproducteur= query.value(0).toString();
        QString  accord = QString("pas encore");

        if(!query2.exec("select * from AppartenanceProducteur where idPC = "+idPc+" and idProducteur = "+idproducteur+"  "))
        {
            qDebug() << "Erreur: recherche ce appartenance. " <<query2.lastError();
        }
        else
        {
            qDebug() << "Trouvé!";
        }
        while(query2.next())
        {
            accord=QString(query2.value(2).toString());
        }
        qDebug()<<nom<<tele<<adreese<<idproducteur<<accord;

        ProducteurItemSousResponsable* pItemWidget = new ProducteurItemSousResponsable(this);
        pItemWidget->setData(idproducteur,nom,tele,adreese,accord,idPc);
        QListWidgetItem* pItem = new QListWidgetItem();
        pItem->setSizeHint(QSize(240,120 ));
        ui->listWidget->addItem(pItem);
        ui->listWidget->setItemWidget(pItem,pItemWidget);
    }
}
