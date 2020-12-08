#include "producteurpanel.h"
#include "ui_producteurpanel.h"

producteurPanel::producteurPanel(QWidget *parent , Producteur *p)
    : QWidget(parent)
    , ui(new Ui::producteurPanel)
{
    ui->setupUi(this);
    ui->widget = new Widget(this, p);
    //ui->widget = new Widget(this, p);

    //ui->tableWidget = new QTableWidget(3,3,this);
    //ui->tableWidget.set
}

producteurPanel::~producteurPanel()
{
    delete ui;
}

