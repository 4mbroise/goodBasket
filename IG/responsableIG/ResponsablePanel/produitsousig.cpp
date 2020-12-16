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


void ProduitSousResponsable::setData(const QString& id,const QString& nom,const QString& quantite,const QString& prix,const QString& adresse,const QString& date,const QString& nomProducteur)
{
    ui->NomProduit->setText("Nom : "+nom);
    ui->Quantite->setText("Quantite : "+quantite);
    ui->Prix->setText("Prix : "+prix);
    ui->Adresse->setText("Adresse : "+adresse);
    ui->Date->setText("Date : "+date);
    ui->NomProducteur->setText("IdProducteur : "+nomProducteur);
}



