#include "producteursousig.h"
#include "ui_producteursousig.h"
#include "produitsousig.h"
#include "ui_produitsousig.h"
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


void ProducteurSousResponsable::setData(const QString& a,const QString& id)
{
    QSqlQuery query;

    qDebug() << "erreur---------------------" << id;

    if(query.exec("select * from ProducteursLivaison where producteurId=\""+id+"\""))
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
        QString  quantite= query.value(2).toString();
        QString  adreese= query.value(3).toString();
        QString  date= query.value(4).toString();
        QString  nomProducteur= query.value(5).toString();
        qDebug()<<livraisonsId<<nom<<quantite<<adreese<<date<<nomProducteur<<a;

        ui->total->setText(a);

        ProduitSousResponsable* pItemWidget = new ProduitSousResponsable(this);
        pItemWidget->setData(livraisonsId,nom,quantite,adreese,date,nomProducteur);
        QListWidgetItem* pItem = new QListWidgetItem();
        pItem->setSizeHint(QSize(240,640 ));
        ui->listWidget->addItem(pItem);
        ui->listWidget->setItemWidget(pItem,pItemWidget);

    }

}

void ProducteurSousResponsable::on_Confirmer_clicked()
{

}
