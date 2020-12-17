#include "fusionresponsableig.h"
#include "ui_fusionresponsableig.h"

#include "../ResponsablePanel/widgetresponsable.h"

fusionResponsableIg::fusionResponsableIg(QWidget *parent, Responsable r)
    : QWidget(parent), responsable(r)
    , ui(new Ui::fusionResponsableIg)
{
    ui->setupUi(this);

    this->responsable = r;

    this->gestionOuvertureWidget = new GestionOuverturePCPanel(nullptr, r);
    this->responsablePanel = new WidgetResponsable(ui->tabWidget);

    ui->tabWidget->removeTab(0);
    ui->tabWidget->removeTab(0);
    ui->tabWidget->addTab(this->responsablePanel, "responsable");
    ui->tabWidget->addTab(this->gestionOuvertureWidget, "Cycles");

}

fusionResponsableIg::~fusionResponsableIg()
{
    delete responsablePanel;
    delete gestionOuvertureWidget;
    delete ui;

}
