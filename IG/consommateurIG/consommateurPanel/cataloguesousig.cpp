#include "cataloguesousig.h"
#include "ui_cataloguesousig.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QDebug>
#include <QListWidget>


CatalogueSousConsommateur::CatalogueSousConsommateur(QWidget *parent,QString adressePC,int idConsommateur)
    : QWidget(parent), ui(new Ui::CatalogueSousConsommateur),adressePC(adressePC),idConsommateur(idConsommateur)
{
    ui->setupUi(this);

}

CatalogueSousConsommateur::~CatalogueSousConsommateur()
{
    delete ui;
}

void CatalogueSousConsommateur::setData(){
    ui->PC->setText("PC:"+adressePC);
    ui->IdConsommateur->setText("IdConsommatuer:"+QString::number(idConsommateur));


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
