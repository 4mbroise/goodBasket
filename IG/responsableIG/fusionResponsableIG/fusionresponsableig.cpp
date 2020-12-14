#include "fusionresponsableig.h"
#include "ui_fusionresponsableig.h"

fusionResponsableIg::fusionResponsableIg(QWidget *parent, Responsable r)
    : QWidget(parent)
    , ui(new Ui::fusionResponsableIg)
{
    ui->setupUi(this);

    this->responsable = r;

    this->gestionOuvertureWidget = new GestionOuverturePCPanel(nullptr, r);
    this->responsablePanel = new Widget(ui->tabWidget);

    ui->tabWidget->removeTab(0);
    ui->tabWidget->removeTab(0);
    ui->tabWidget->addTab(this->responsablePanel, "responsable");
    ui->tabWidget->addTab(this->gestionOuvertureWidget, "Cycles");

}

fusionResponsableIg::~fusionResponsableIg()
{
    delete ui;
}

