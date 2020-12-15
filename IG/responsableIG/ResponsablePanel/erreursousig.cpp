#include "erreursousig.h"
#include "ui_erreursousig.h"
#include "../../../Outils/idgenerator.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QListWidget>

ErreurSousResponsable::ErreurSousResponsable(QWidget *parent)
    : QWidget(parent), ui(new Ui::ErreurSousResponsable)
{
    ui->setupUi(this);
}

ErreurSousResponsable::~ErreurSousResponsable()
{
    delete ui;
}


void ErreurSousResponsable::on_Confirmer_clicked()
{
    QSqlQuery query;

    if(ui->apercu->text()!=NULL)
    {
        if(!query.exec("INSERT INTO Erreurs VALUES("+QString::number(IdGenerator::Instance().getNewIdErreur())+", \""+ui->apercu->text()+"\")"))
        {
            qDebug() << "Erreur: Défaut de insertion d’une table. " << query.lastError();
        }
        else
        {
            qDebug() << "Insertion!";
        }
    }

    this->deleteLater();
}
