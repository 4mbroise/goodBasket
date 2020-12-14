#include "pcsousig.h"
#include "ui_pcsousig.h"

PcSousConsommateur::PcSousConsommateur(QWidget *parent)
    : QWidget(parent), ui(new Ui::PcSousConsommateur)
{
    ui->setupUi(this);

}

PcSousConsommateur::~PcSousConsommateur()
{
    delete ui;
}


void PcSousConsommateur::setData(const QString& adresse)
{
  ui->Adresse->setText("adresse:"+adresse);
}

QString PcSousConsommateur::getAdresse(){
    return ui->Adresse->text();
}
