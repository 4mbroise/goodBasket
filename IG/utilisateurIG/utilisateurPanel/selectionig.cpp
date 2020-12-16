#include "selectionig.h"
#include "connecterig.h"
#include "demanderpcig.h"
#include "ui_selectionig.h"
#include "../../../utilisateur.h"
#include "../../../consommateur.h"
#include "../../../producteur.h"
#include "../../../Outils/idgenerator.h"




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
    Consommateur*consommateur=new Consommateur(nom,prenom,adresse,phone,email);
    consommateur->ajouterConsommateurBDD();
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
    Prouducteur *producteur=Producteur(nom,prenom,adresse,phone,email);
    c->show();
    this->close();

}
