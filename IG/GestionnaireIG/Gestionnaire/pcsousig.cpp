#include "pcsousig.h"
#include "ui_pcsousig.h"
#include "../../../Outils/idgenerator.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QListWidget>

PcSousGestionnaire::PcSousGestionnaire(QWidget *parent)
    : QWidget(parent), ui(new Ui::PcSousGestionnaire)
{
    ui->setupUi(this);
}

PcSousGestionnaire::~PcSousGestionnaire()
{
    delete ui;
}


void PcSousGestionnaire::on_Confirmer_clicked()
{
    QSqlQuery query;


    if(!query.exec("UPDATE PointDeCollecte \
                   SET  valider = \"true\" \
                   WHERE valider = \"false\" \
                   and  idResponsablePC ="+QString::number(idPC)+" "))
    {
        qDebug() << "Erreur: Défaut de Modification d’une table. " << query.lastError();
    }
    else
    {
        qDebug() << "Modification!";
    }


    this->deleteLater();
}

void PcSousGestionnaire::setData(const QString& idPc,const QString& nom,const QString& adresse){
    ui->NomDemandeur->setText(nom);
    ui->Adresse->setText(adresse);
    idPC=idPc.toInt();
}

void PcSousGestionnaire::on_Supprimer_clicked()
{
    this->deleteLater();
}
