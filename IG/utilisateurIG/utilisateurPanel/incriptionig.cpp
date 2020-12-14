#include "incriptionig.h"
#include "ui_incriptionig.h"

Incriptionig::Incriptionig(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Incriptionig)
{
    ui->setupUi(this);
}

Incriptionig::~Incriptionig()
{
    delete ui;
}

