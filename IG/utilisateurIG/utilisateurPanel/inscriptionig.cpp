#include "inscriptionig.h"
#include "ui_inscriptionig.h"

Inscriptionig::Inscriptionig(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Inscriptionig)
{
    ui->setupUi(this);
}

Inscriptionig::~Inscriptionig()
{
    delete ui;
}

