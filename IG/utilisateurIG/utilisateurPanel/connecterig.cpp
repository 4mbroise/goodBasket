#include "connecterig.h"
#include "ui_connecterig.h"
#include "inscriptionig.h"

Connecterig::Connecterig(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Connecterig)
{
    ui->setupUi(this);

    ui->Pass->setEchoMode(QLineEdit::Password);
}

Connecterig::~Connecterig(){
    delete ui;
}

void Connecterig::on_Login_clicked(){

}

void Connecterig::on_Inscrire_clicked(){
    Inscriptionig* iig=new Inscriptionig(nullptr);
    iig->show();
    this->close();
}
