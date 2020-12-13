#include "Widget.h"
#include "ui_Widget.h"
using namespace std;

Widget::Widget(QWidget *parent, Producteur p)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->model = p;
}

Widget::~Widget()
{
    cout << "Destruction widget" <<endl;
    delete ui;
}

void Widget::on_buttonAjouterProduit_released()
{
    double prix = ui->spinPrix->value();
    int quantity = ui->spinQuantity->value();
    std::string nom = ui->lineEditNom->text().toStdString();

    if(isFormulaireOK())
    {
        this->model.ajouterProduitBDD(quantity,prix,nom);
    }
    else
    {
        cout << "forumlaire pas ok " << endl;
    }

    emit miseAjourBoutique();
}



bool Widget::isFormulaireOK()
{
    double prix = ui->spinPrix->value();
    int quantity = ui->spinQuantity->value();
    std::string nom = ui->lineEditNom->text().toStdString();

    return (prix>=0 && quantity >0 && !nom.empty());
}

