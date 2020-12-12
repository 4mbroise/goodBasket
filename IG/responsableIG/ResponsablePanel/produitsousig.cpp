#include "produitsousig.h"
#include "ui_produitsousig.h"


ProduitSousResponsable::ProduitSousResponsable(QWidget *parent)
    : QWidget(parent), ui(new Ui::ProduitSousResponsable)
{
    ui->setupUi(this);
}

ProduitSousResponsable::~ProduitSousResponsable()
{
    delete ui;
}


void ProduitSousResponsable::setData(const QString& id,const QString& nom,const QString& quantite,const QString& adresse,const QString& date,const QString& nomProducteur)
{
    ui->NomProduit->setText(nom);
    ui->Quantite->setText(quantite);
    ui->Adresse->setText(adresse);
    ui->Date->setText(date);
    ui->NomProducteur->setText(nomProducteur);
}



