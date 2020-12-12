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


void ProducteurSousResponsable::setData(const QString& a)
{

}
