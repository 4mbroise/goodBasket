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
    QSqlQuery query2;

    int actualMaxId=IdGenerator::Instance().getNewIdErreur();

    if(!query2.exec("SELECT max(id) FROM Erreurs"))
    {
         qDebug() << "ERREUR requete SQL" << query2.lastError();
    }
    else
    {
         //On insere la nouvelle livraison  avec comme id l'id de livraison qu'on a trouvé +1
         query2.next();
         actualMaxId = query2.value(0).toInt()+1;

         qDebug() << actualMaxId;
    }

    if(ui->apercu->text()!=NULL)
    {
        if(!query.exec("INSERT INTO Erreurs VALUES("+QString::number(actualMaxId)+", \""+ui->apercu->text()+"\")"))
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
