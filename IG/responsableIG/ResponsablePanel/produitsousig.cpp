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


void ProduitSousResponsable::setData(const QString& a,const QString& id)
{
 //   ui->total->setText("Total : "+a+" euro");

}

void ProduitSousResponsable::on_Confirmer_clicked()
{

}
