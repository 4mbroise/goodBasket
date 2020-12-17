#include "Widgetp.h"
#include "ui_Widgetp.h"
#include "../../../producteur.h"
using namespace std;

WidgetProducteur::WidgetProducteur(QWidget *parent, Producteur p)
    : QWidget(parent) ,model(p)
    , ui(new Ui::WidgetProducteur)
{
    this->setWindowTitle("ajouter produit formulaire");
    ui->setupUi(this);
    this->model = p;
}

WidgetProducteur::~WidgetProducteur()
{
    cout << "Destruction widget" <<endl;
    delete ui;
}

void WidgetProducteur::on_buttonAjouterProduit_released()
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



bool WidgetProducteur::isFormulaireOK()
{
    double prix = ui->spinPrix->value();
    int quantity = ui->spinQuantity->value();
    std::string nom = ui->lineEditNom->text().toStdString();

    return (prix>=0 && quantity >0 && !nom.empty());
}

