#include "erreursousig.h"
#include "ui_erreursousig.h"

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

}

void ErreurSousResponsable::setData(const QString& a)
{
    ui->apercu->setText(a);
}
