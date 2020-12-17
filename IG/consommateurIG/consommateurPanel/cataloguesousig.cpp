#include "cataloguesousig.h"
#include "ui_cataloguesousig.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QDebug>
#include <QListWidget>


CatalogueSousConsommateur::CatalogueSousConsommateur(QWidget *parent,QString adressePC,Consommateur consommateur)
    : QWidget(parent), ui(new Ui::CatalogueSousConsommateur),adressePC(adressePC),consommateur(consommateur)
{
    ui->setupUi(this);
    this->idConsommateur=consommateur.getId();
    this->setData();
    //title
    this->setWindowTitle("catalogue");
}

CatalogueSousConsommateur::~CatalogueSousConsommateur()
{
    delete ui;
}

void CatalogueSousConsommateur::setData(){
    ui->PC->setText("PC:"+adressePC);
    ui->IdConsommateur->setText("IdConsommatuer:"+QString::number(idConsommateur));


}

Consommateur& CatalogueSousConsommateur::getConsommateur(){
    return consommateur;
}

void CatalogueSousConsommateur::on_Retourner_clicked(){
    emit sendsignal();
    this->close();
}

void CatalogueSousConsommateur::mettreAJour(){
    setData();
}

Ui::CatalogueSousConsommateur& CatalogueSousConsommateur::getUI(){
    return *this->ui;
}
