#include "selectionig.h"
#include "connecterig.h"
#include "demanderpcig.h"
#include "ui_selectionig.h"


Selectionig::Selectionig(QWidget *parent,QString nom,QString prenom,QString adresse,QString phone,QString email)
    : QWidget(parent)
    , ui(new Ui::Selectionig)
    , nom(nom),prenom(prenom),adresse(adresse),phone(phone),email(email)
{
    ui->setupUi(this);

}

Selectionig::~Selectionig(){
    delete ui;
}

void Selectionig::on_Consommateur_clicked(){
    Connecterig* c=new Connecterig(nullptr);
    c->show();
    this->close();
}

void Selectionig::on_Responsable_clicked(){
    Demanderpcig *d=new Demanderpcig(nullptr,nom,prenom,adresse,phone,email);
    d->show();
    this->close();
}

void Selectionig::on_Producteur_clicked(){
    Connecterig* c=new Connecterig(nullptr);
    c->show();
    this->close();

}
