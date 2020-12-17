#include "selectionig.h"
#include "connecterig.h"
#include "demanderpcig.h"
#include "ui_selectionig.h"
#include "../../../utilisateur.h"
#include "../../../consommateur.h"
#include "../../../producteur.h"
#include "../../../Outils/idgenerator.h"




Selectionig::Selectionig(QWidget *parent,QString nom,QString prenom,QString adresse,QString phone,QString email,QString pass)
    : QWidget(parent)
    , ui(new Ui::Selectionig)
    , nom(nom),prenom(prenom),adresse(adresse),phone(phone),email(email),pass(pass)
{
    ui->setupUi(this);
    //title
    this->setWindowTitle("selection");

}

Selectionig::~Selectionig(){
    delete ui;
}

void Selectionig::on_Consommateur_clicked(){
    Connecterig* c=new Connecterig(nullptr);
    Consommateur*consommateur=new Consommateur(nom,prenom,adresse,phone,email,pass);
    consommateur->ajouterConsommateurBDD();
    c->show();
    this->close();
}

void Selectionig::on_Responsable_clicked(){
    Demanderpcig *d=new Demanderpcig(nullptr,nom,prenom,adresse,phone,email,pass);
    d->show();
    this->close();
}

void Selectionig::on_Producteur_clicked(){
    Connecterig* c=new Connecterig(nullptr);
    Producteur *producteur=new Producteur(nom,prenom,adresse,phone,email,pass);
    producteur->ajouterProducteurBDD();
    c->show();
    this->close();

}
