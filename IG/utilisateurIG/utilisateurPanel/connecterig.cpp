#include "connecterig.h"
#include "ui_connecterig.h"
#include "inscriptionig.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include "../../consommateurIG/consommateurPanel/consommateurig.h"
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
   QSqlQuery login;
   QString email=ui->Email->text();
   QString pass=ui->Pass->text();
   login.prepare("SELECT Utilisateurs.UtilisateurID"
                 "from Utilisateurs where Utilisateurs.estConsommateur"
                 "and Utilisateurs.email=:email"
                 "and Utilisateurs.pass=:pass");
   qDebug()<<email<<endl;
   qDebug()<<pass<<endl;
   login.bindValue(":email",email);
   login.bindValue(":pass",pass);
   if(!login.exec())
   {
       qDebug() << "Erreur:Pass pas correcte ou Email existe pas " <<login.lastError();
   }
   else
   {
       qDebug() << "réussi!";
       login.next();
       int id=login.value(0).toInt();
       Consommateurig* cig=new Consommateurig(nullptr,Consommateur(id));
       cig->show();
       this->close();
   }

}

void Connecterig::on_Inscrire_clicked(){
    Inscriptionig* iig=new Inscriptionig(nullptr);
    iig->show();
    this->close();
}
