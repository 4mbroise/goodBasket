#include "consommateursousig.h"
#include "ui_consommateursousig.h"
#include "livraisonsousig.h"
#include "ui_livraisonsousig.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QListWidget>


ConsommateurSousResponsable::ConsommateurSousResponsable(QWidget *parent)
    : QWidget(parent), ui(new Ui::ConsommateurSousResponsable)
{
    ui->setupUi(this);


}

ConsommateurSousResponsable::~ConsommateurSousResponsable()
{
    delete ui;
}


void ConsommateurSousResponsable::setData(const QString& consommateurid)
{
    QSqlQuery query;

    qDebug() << "erreur---------------------" << consommateurid;

    if(!query.exec("select * from Livraisons where idConsommateur= \""+consommateurid+"\" and annuler=\"true\""))
    {
        qDebug() << "Erreur: recherche ce consommateur. " <<query.lastError();
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
        QString  erreur= "producteur annule\ncette livraison";

        qDebug()<<livraisonsId<<nom<<quantite<<adreese<<consommateurid;

        int somme=ui->total->text().toInt();

        qDebug()<<somme;

        somme+=prix.toInt()*quantite.toInt();

        qDebug()<<somme;

        ui->total->setText(QString::number(somme));

        LivraisonSousResponsable* pItemWidget = new LivraisonSousResponsable(this);
        pItemWidget->setData(livraisonsId,nom,quantite,adreese,erreur,prix,consommateurid);
        QListWidgetItem* pItem = new QListWidgetItem();
        pItem->setSizeHint(QSize(240,640 ));
        ui->listWidget->addItem(pItem);
        ui->listWidget->setItemWidget(pItem,pItemWidget);
    }
    consommateurId=consommateurid.toInt();
}

void ConsommateurSousResponsable::on_Confirmer_clicked()
{
    QSqlQuery query;

    if(!query.exec("DELETE from Livraisons \
                   WHERE  annuler = \"true\" \
                   AND idConsommateur ="+QString::number(consommateurId)+""))
    {
        qDebug() << "Erreur: Défaut de Modification d’une table. " << query.lastError();
    }
    else
    {
        qDebug() << "Modification!";
    }

    this->deleteLater();
}
