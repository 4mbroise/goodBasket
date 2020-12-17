#include "connecterig.h"
#include "ui_connecterig.h"
#include "inscriptionig.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include "../../consommateurIG/consommateurPanel/consommateurig.h"
#include "../../producteurIG/producteurPanel/producteurpanel.h"
#include "../../responsableIG/fusionResponsableIG/fusionresponsableig.h"
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
   QString id=ui->IDcode->text();
   QString pass=ui->Pass->text();
   QString choix=ui->choix->text();
   if(choix==QString("consommateur")){
       if(!login.exec("SELECT UtilisateurID \
                      from Utilisateurs where estConsommateur=\"true\" \
                      and UtilisateurID="+id+"  \
                      and passe= "+pass+""))
       {
           qDebug() << "Erreur:Pass pas correcte ou Email existe pas " <<login.lastError();
       }
       else
       {
           qDebug() << "réussi!";
           login.next();
           int id=login.value(0).toInt();
            qDebug() << id;

           Consommateurig* cig=new Consommateurig(nullptr,Consommateur(id));
           cig->show();
           this->close();
       }
   }

                      if(choix==QString("responsable")){
                          if(!login.exec("SELECT UtilisateurID \
                                         from Utilisateurs where estResponsable=\"true\" \
                                         and UtilisateurID="+id+"  \
                                         and passe= "+pass+""))
                          {
                              qDebug() << "Erreur:Pass pas correcte ou Email existe pas " <<login.lastError();
                          }
                          else
                          {
                              qDebug() << "réussi!";
                              login.next();
                              int id=login.value(0).toInt();
                               qDebug() << id;


                              Consommateurig* cig=new Consommateurig(nullptr,Consommateur(id));
                              cig->show();
                              this->close();
                          }
                      }


                                         if(choix==QString("producteur")){
                                             if(!login.exec("SELECT UtilisateurID \
                                                            from Utilisateurs where estProducteur=\"true\" \
                                                            and UtilisateurID="+id+"  \
                                                            and passe= "+pass+""))
                                             {
                                                 qDebug() << "Erreur:Pass pas correcte ou Email existe pas " <<login.lastError();
                                             }
                                             else
                                             {
                                                 qDebug() << "réussi!";
                                                 login.next();
                                                 int id=login.value(0).toInt();
                                                  qDebug() << id;

                                                 Consommateurig* cig=new Consommateurig(nullptr,Consommateur(id));
                                                 cig->show();
                                                 this->close();
                                             }
                                         }







}

void Connecterig::on_Inscrire_clicked(){
    Inscriptionig* iig=new Inscriptionig(nullptr);
    iig->show();
    this->close();
}
