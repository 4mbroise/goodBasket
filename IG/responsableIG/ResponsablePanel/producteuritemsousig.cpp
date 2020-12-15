#include "producteuritemsousig.h"
#include "ui_producteuritemsousig.h"


ProducteurItemSousResponsable::ProducteurItemSousResponsable(QWidget *parent)
    : QWidget(parent), ui(new Ui::ProducteurItemSousResponsable)
{
    ui->setupUi(this);
}

ProducteurItemSousResponsable::~ProducteurItemSousResponsable()
{
    delete ui;
}


void ProducteurItemSousResponsable::setData(const QString& id,const QString& nom,const QString& tele,const QString& adresse,const QString& accord)
{
    ui->NomProducteur->setText("Nom : "+nom);
    ui->Adresse->setText("Adresse : "+adresse);
    ui->Tele->setText(tele);
    ui->Etat->setText("Etat : \n"+accord);
}



