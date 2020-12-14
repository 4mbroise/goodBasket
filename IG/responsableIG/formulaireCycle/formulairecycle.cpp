#include "formulairecycle.h"
#include "ui_formulairecycle.h"

formulaireCycle::formulaireCycle(QWidget *parent, Responsable r)
    : QWidget(parent)
    , ui(new Ui::formulaireCycle)
{
    ui->setupUi(this);
    this->responsable = r;
}

formulaireCycle::~formulaireCycle()
{
    delete ui;
}


void formulaireCycle::on_pushButton_released()
{
    QDate dateDebutCycle = ui->dateDC->date() ;
    QDate dateDebutVente = ui->dateDV->date() ;
    QDate dateFincVente = ui->dateFV->date() ;
    QDate dateLivraison = ui->dateL->date() ;

    if(this->responsable.isCycleValide(dateDebutCycle, dateDebutVente, dateFincVente, dateLivraison))
    {
        this->responsable.ajouterCycle(dateDebutCycle, dateDebutVente, dateFincVente, dateLivraison);

        emit miseAJourTableCycle();
    }

}
