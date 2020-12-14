#include "cataloguesousig.h"
#include "ui_cataloguesousig.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QDebug>
#include <QListWidget>


CatalogueSousConsommateur::CatalogueSousConsommateur(QWidget *parent)
    : QWidget(parent), ui(new Ui::CatalogueSousConsommateur)
{
    ui->setupUi(this);

}

CatalogueSousConsommateur::~CatalogueSousConsommateur()
{
    delete ui;
}

void CatalogueSousConsommateur::setData(const QString& adressePC,const QString &idConsommateur){
    ui->PC->setText("PC:"+adressePC);
    ui->IdConsommateur->setText("IdConsommatuer:"+idConsommateur);
}

Ui::CatalogueSousConsommateur& CatalogueSousConsommateur::getUI(){
    return *this->ui;
}


void CatalogueSousConsommateur::on_Retourner_clicked(){
    emit sendsignal();
    this->close();
}
