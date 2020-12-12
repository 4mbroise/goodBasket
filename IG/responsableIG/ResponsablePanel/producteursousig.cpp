#include "producteursousig.h"
#include "ui_producteursousig.h"


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
    ui->total->setText("Total : "+a+" euro");

}

void ProducteurSousResponsable::on_Confirmer_clicked()
{

}
