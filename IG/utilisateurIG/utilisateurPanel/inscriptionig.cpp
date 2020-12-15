#include "inscriptionig.h"
#include "ui_inscriptionig.h"
#include "connecterig.h"
#include "selectionig.h"
#include <QLineEdit>
#include <QValidator>

Inscriptionig::Inscriptionig(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Inscriptionig)
{
    ui->setupUi(this);
    //title
    this->setWindowTitle("Inscription");
    //echo mode password
    this->ui->Pass->setEchoMode(QLineEdit::Password);
    //clearButton
    this->ui->Nom->setClearButtonEnabled(true);
    this->ui->Prenom->setClearButtonEnabled(true);
    this->ui->Pass->setEchoMode(QLineEdit::Password);
    this->ui->Email->setClearButtonEnabled(true);
    this->ui->Telephone->setClearButtonEnabled(true);
    this->ui->Ville->setClearButtonEnabled(true);
    this->ui->Numero->setClearButtonEnabled(true);
    this->ui->Postal->setClearButtonEnabled(true);
    this->ui->Rue->setClearButtonEnabled(true);

    ui->Nom->setPlaceholderText("que lettres");
    QRegExp no("[A-Za-z]+");
    ui->Nom->setValidator(new QRegExpValidator(no,this));

    ui->Prenom->setPlaceholderText("que lettres");
    QRegExp pn("[A-Za-z]+");
    ui->Prenom->setValidator(new QRegExpValidator(pn,this));

    ui->Telephone->setPlaceholderText("que chiffres");
    QRegExp te("[0-9]+");
    ui->Telephone->setValidator(new QRegExpValidator(te,this));

    ui->Pass->setPlaceholderText("que 8-12 lettres ou chiffres");
    QRegExp pass("[A-Za-z0-9]{8,12}");
    ui->Pass->setValidator(new QRegExpValidator(pass,this));


    QRegExp em("[A-Za-z0-9]+[@]{1}.$");
    ui->Email->setValidator(new QRegExpValidator(em,this));

    ui->Ville->setPlaceholderText("que lettres");
    QRegExp vi("[A-Za-z]+");
    ui->Ville->setValidator(new QRegExpValidator(vi,this));


    QRegExp nu("[0-9]+");
    ui->Numero->setValidator(new QRegExpValidator(nu,this));

    QRegExp po("[0-9]+");
    ui->Postal->setValidator(new QRegExpValidator(po,this));

    QRegExp ru("[A-Za-z]+");
    ui->Rue->setValidator(new QRegExpValidator(ru,this));
}

Inscriptionig::~Inscriptionig()
{
    delete ui;
}

bool Inscriptionig::verifier(){
    QString nom=this->ui->Nom->text();
    QString prenom=this->ui->Prenom->text();
    QString email=this->ui->Email->text();
    QString pass=this->ui->Pass->text();
    QString telephone=this->ui->Telephone->text();
    QString ville=this->ui->Ville->text();
    QString numero=this->ui->Numero->text();
    QString postal=this->ui->Postal->text();
    QString rue=this->ui->Rue->text();

    bool returned=true;
    if(nom.isEmpty()){
        ui->NomLabel->setText("Nom: il faut remplir");
        returned=false;
    }
    if(prenom.isEmpty()){
        ui->PrenomLabel->setText("Prenom: il faut remplir");
        returned=false;
    }
    if(email.isEmpty()){
        ui->EmailLabel->setText("Email: il faut remplir");
        returned=false;
    }
    if(pass.isEmpty()){
        ui->PassLabel->setText("Pass: il faut remplir");
        returned=false;
    }
    if(telephone.isEmpty()){
        ui->PhoneLable->setText("Telephone: il faut remplir");
        returned=false;
    }
    if(ville.isEmpty()){
        ui->VilleLabel->setText("Ville il faut remplir");
        returned=false;
    }
    if(numero.isEmpty()){
        ui->NumeroLabel->setText("Numero: il faut remplir");
        returned=false;
    }
    if(postal.isEmpty()){
        ui->PostaleLabel->setText("Postal: il faut remplir");
        returned=false;
    }if(rue.isEmpty()){
        ui->RueLabel->setText("Rue: il faut remplir");
        returned=false;
    }
    return returned;
}

void Inscriptionig::on_Inscrire_clicked(){
    if(verifier()){
        this->close();
        Selectionig* s=new Selectionig(nullptr);
        s->show();
    }
}

void Inscriptionig::on_Login_clicked(){
    Connecterig* c=new Connecterig(nullptr);
    c->show();
    this->close();
}

