#include "producteurpanel.h"
#include "ui_producteurpanel.h"

producteurPanel::producteurPanel(QWidget *parent , Producteur *p)
    : QWidget(parent)
    , ui(new Ui::producteurPanel)
{
    ui->setupUi(this);
    this->prod = p;

    //init table
    this->model = new QStandardItemModel ();


    model->setItem(0,0,new QStandardItem(QString("test")));

    QHashIterator<int,Produit> ite = prod->iterator();
    int i=0;
    while(ite.hasNext())
    {
        ite.next();
        Produit produit = ite.value();
        model->setItem(i,0,new QStandardItem(produit.getNom()));
        model->setItem(i,1,new QStandardItem(QString::number(produit.getQuantite())));
        model->setItem(i,2,new QStandardItem(QString::number(produit.getPrix())));
        model->setItem(i,3,new QStandardItem(QString::number(produit.getId())));
        i++;
    }



    ui->tableView->setModel(model);

    model->setHeaderData(0, Qt::Horizontal ,tr("Nom"));
    model->setHeaderData(1, Qt::Horizontal ,tr("Quantité"));
    model->setHeaderData(2, Qt::Horizontal ,tr("Prix"));
    model->setHeaderData(3, Qt::Horizontal ,tr("ID"));

    //ui->tableView->update();

    this->formulaire = new Widget(this, p);

    this->layout()->addWidget(formulaire);

    connect(this->formulaire,SIGNAL(miseAjourBoutique()),this,SLOT(mettreAJourTable()));
}

void producteurPanel::mettreAJourTable()
{
    cout << "SLOT mettreAJour Table" << endl;
    this->model->clear();

    QHashIterator<int,Produit> ite = prod->iterator();
    int i=0;
    while(ite.hasNext())
    {
        ite.next();
        Produit produit = ite.value();
        model->setItem(i,0,new QStandardItem(produit.getNom()));
        model->setItem(i,1,new QStandardItem(QString::number(produit.getQuantite())));
        model->setItem(i,2,new QStandardItem(QString::number(produit.getPrix())));
        model->setItem(i,3,new QStandardItem(QString::number(produit.getId())));
        i++;
    }

    this->model->setHeaderData(0, Qt::Horizontal ,tr("Nom"));
    this->model->setHeaderData(1, Qt::Horizontal ,tr("Quantité"));
    this->model->setHeaderData(2, Qt::Horizontal ,tr("Prix"));
    this->model->setHeaderData(3, Qt::Horizontal ,tr("ID"));

    cout << this->prod->toString() << endl;
}




producteurPanel::~producteurPanel()
{
    delete ui;
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

        this->prod->demanderRetirerProduit(idProduitARetirer);
        mettreAJourTable();

    }

}
