#include "producteurpanel.h"
#include "ui_producteurpanel.h"

producteurPanel::producteurPanel(QWidget *parent , Producteur *p)
    : QWidget(parent)
    , ui(new Ui::producteurPanel)
{
    ui->setupUi(this);

    this->layout()->addWidget(new Widget(this, p));

}

producteurPanel::~producteurPanel()
{
    delete ui;
}

