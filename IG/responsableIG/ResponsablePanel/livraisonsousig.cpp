#include "livraisonsousig.h"
#include "ui_livraisonsousig.h"


LivraisonSousResponsable::LivraisonSousResponsable(QWidget *parent)
    : QWidget(parent), ui(new Ui::LivraisonSousResponsable)
{
    ui->setupUi(this);
}

LivraisonSousResponsable::~LivraisonSousResponsable()
{
    delete ui;
}


void LivraisonSousResponsable::setData(const QString& livraisonId,const QString& nom,const QString& quantite,const QString& adresse,const QString& erreur,const QString& prix ,const QString& consommateurId)
{
    ui->NomProduit->setText("Nom : "+nom);
    ui->Quantite->setText("Quantite : "+quantite);
    ui->Prix->setText("Prix : "+prix);
    ui->Adresse->setText("Adresse : "+adresse);
    ui->Erreur->setText(erreur);

}



