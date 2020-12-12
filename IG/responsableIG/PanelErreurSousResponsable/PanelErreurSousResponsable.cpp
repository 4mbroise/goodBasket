#include "PanelErreurSousResponsable.h"
#include "ui_PanelErreurSousResponsable.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_Confirmer_clicked()
{

}
