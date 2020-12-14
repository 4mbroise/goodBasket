#include "producteurpanel.h"
#include "ui_producteurpanel.h"

producteurPanel::producteurPanel(QWidget *parent , Producteur p)
    : QWidget(parent)
    , ui(new Ui::producteurPanel)
{
    ui->setupUi(this);
    this->prod = Producteur(-1);
    this->prod = p;


        //init table
        this->model = new QSqlQueryModel;

        mettreAJourTable();


        //ui->tableView->update();

        this->formulaire = new Widget(this, p);

        this->layout()->addWidget(formulaire);

        connect(this->formulaire,SIGNAL(miseAjourBoutique()),this,SLOT(mettreAJourTable()));




}

void producteurPanel::mettreAJourTable()
{
    QString requete = QString::fromStdString("SELECT nom, quantite, prix, idProduit FROM Produit WHERE idProducteur = ");
    requete.append(QString::number(this->prod.getId()));

    model->setQuery(requete);
    model->setHeaderData(0, Qt::Horizontal ,tr("Nom"));
    model->setHeaderData(1, Qt::Horizontal ,tr("Quantité"));
    model->setHeaderData(2, Qt::Horizontal ,tr("Prix"));
    model->setHeaderData(3, Qt::Horizontal ,tr("ID"));


    ui->tableView->setModel(model);

}




producteurPanel::~producteurPanel()
{
    delete ui;
    delete formulaire;
    delete model;
}

void producteurPanel::on_pushButton_clicked()
{
    int idLigne;

    //ui->tableView->
    cout << "selection count = " << ui->tableView->selectionModel()->selection().count() << endl;

    if(ui->tableView->selectionModel()->selectedRows().count())
    {
        idLigne = ui->tableView->selectionModel()->currentIndex().row();
        int idProduitARetirer = this->model->index(idLigne,3).data().toInt();

        cout << "id produit = " << this->model->index(idLigne,3).data().toInt() << endl;

        this->prod.retirerProduit(idProduitARetirer);

    }

    mettreAJourTable();

}
