#include "demanderpcig.h"
#include "ui_demanderpcig.h"
#include "connecterig.h"
#include <QValidator>
#include "../../../responsable.h"
#include "../../../utilisateur.h"
#include "../../../Outils/idgenerator.h"
#include "../../../pc.h"



Demanderpcig::Demanderpcig(QWidget *parent,QString nom,QString prenom,QString adresse,QString phone,QString email)
    : QWidget(parent)
    , ui(new Ui::Demanderpcig)
     , nom(nom),prenom(prenom),adresse(adresse),phone(phone),email(email)
{
    ui->setupUi(this);

    this->ui->Ville->setClearButtonEnabled(true);
    this->ui->Numero->setClearButtonEnabled(true);
    this->ui->Postal->setClearButtonEnabled(true);
    this->ui->Rue->setClearButtonEnabled(true);

    ui->Ville->setPlaceholderText("que lettres");
    QRegExp vi("[A-Za-z]+");
    ui->Ville->setValidator(new QRegExpValidator(vi,this));

    ui->Numero->setPlaceholderText("que chiffres");
    QRegExp nu("[0-9]+");
    ui->Numero->setValidator(new QRegExpValidator(nu,this));

    ui->Postal->setPlaceholderText("que chiffres");
    QRegExp po("[0-9]+");
    ui->Postal->setValidator(new QRegExpValidator(po,this));

    ui->Rue->setPlaceholderText("que lettres");
    QRegExp ru("[A-Za-z]+");
    ui->Rue->setValidator(new QRegExpValidator(ru,this));
}

Demanderpcig::~Demanderpcig(){
    delete  ui;
}

void Demanderpcig::on_Requete_clicked(){
    QString requete=ui->Ville->text()+ui->Postal->text()+ui->Numero->text()+ui->Rue->text();
    Responsable *r=new Responsable(nom,prenom,adresse,phone,email);
    Connecterig *cig=new Connecterig(nullptr);
    cig->show();
    delete this;
}
