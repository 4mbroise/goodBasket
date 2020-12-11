#include "Widget.h"
#include "ui_Widget.h"
using namespace std;

Widget::Widget(QWidget *parent, Producteur *p)
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
    cout << "nom "<< nom << endl;
    cout << "quantite "<< quantity << endl;
    cout << "prix "<< prix << endl;

    this->model->demanderAjoutProduit(quantity,prix,nom,"imagePath");

    cout << "Emission MAJ table boutique" << endl;
    emit miseAjourBoutique();
}
