#include "producteurpanel.h"
#include "ui_producteurpanel.h"

producteurPanel::producteurPanel(QWidget *parent , Producteur p)
    : QWidget(parent), prod(p)
    , ui(new Ui::producteurPanel)
{
    ui->setupUi(this);
    this->prod = Producteur(-1);
    this->prod = p;

        this->setWindowTitle("panelProducteur");

        //init table
        this->modelProduits = new QSqlQueryModel;
        this->modelLivraisons = new QSqlQueryModel;

        mettreAJourTable();


        //ui->tableView->update();

        this->formulaire = new WidgetProducteur(this, p);

        this->layout()->addWidget(formulaire);

        connect(this->formulaire,SIGNAL(miseAjourBoutique()),this,SLOT(mettreAJourTable()));




}

void producteurPanel::mettreAJourTable()
{

    //Table des Produits
    QString requeteListeProduits = QString::fromStdString("SELECT nom, quantite, prix, idProduit FROM Produit WHERE idProducteur = ");
    requeteListeProduits.append(QString::number(this->prod.getId()));

    modelProduits->setQuery(requeteListeProduits);

    modelProduits->setHeaderData(0, Qt::Horizontal ,tr("Nom"));
    modelProduits->setHeaderData(1, Qt::Horizontal ,tr("Quantité"));
    modelProduits->setHeaderData(2, Qt::Horizontal ,tr("Prix"));
    modelProduits->setHeaderData(3, Qt::Horizontal ,tr("ID"));

    ui->tableView->setModel(modelProduits);


    //Table des Livraisons prévues
    QString requeteLivraisonPrevue = QString::fromStdString("SELECT Livraisons.id, Produit.nom,Livraisons.quantite, Produit.prix,Livraisons.quantite*Produit.prix,adresse,dateDeLivraison, Utilisateurs.nom FROM Livraisons JOIN Produit Join Utilisateurs WHERE Livraisons.idProduit = Produit.idProduit AND Livraisons.annuler = 'false' AND idConsommateur = Utilisateurs.UtilisateurID ");

    //requeteLivraisonPrevue.append(QString::number(this->prod.getId()));

    cout << requeteLivraisonPrevue.toStdString() << endl;

    modelLivraisons->setQuery(requeteLivraisonPrevue);

    modelLivraisons->setHeaderData(0, Qt::Horizontal ,tr("ID"));
    modelLivraisons->setHeaderData(1, Qt::Horizontal ,tr("Nom"));
    modelLivraisons->setHeaderData(2, Qt::Horizontal ,tr("Quantité"));
    modelLivraisons->setHeaderData(3, Qt::Horizontal ,tr("Prix"));
    modelLivraisons->setHeaderData(4, Qt::Horizontal ,tr("recette"));
    modelLivraisons->setHeaderData(5, Qt::Horizontal ,tr("Adresse"));
    modelLivraisons->setHeaderData(6, Qt::Horizontal ,tr("Date de Livraison"));
    modelLivraisons->setHeaderData(7, Qt::Horizontal ,tr("Client"));

    ui->tableView_2->setModel(modelLivraisons);

}




producteurPanel::~producteurPanel()
{
    delete ui;
    delete formulaire;
    delete modelProduits;
    delete modelLivraisons;

}

void producteurPanel::on_pushButton_clicked()
{
    int idLigne;

    //ui->tableView->

    if(ui->tableView->selectionModel()->selectedRows().count())
    {
        idLigne = ui->tableView->selectionModel()->currentIndex().row();
        int idProduitARetirer = this->modelProduits->index(idLigne,3).data().toInt();

        cout << "id produit = " << this->modelProduits->index(idLigne,3).data().toInt() << endl;

        this->prod.retirerProduit(idProduitARetirer);
        this->prod.annulerLivraisonByProduit(idProduitARetirer);


    }

    mettreAJourTable();

}

void producteurPanel::on_pushButton_2_released()
{
    int idLigne;


    if(ui->tableView_2->selectionModel()->selectedRows().count())
    {
        idLigne = ui->tableView_2->selectionModel()->currentIndex().row();
        int idLivraisonARetirer = this->modelLivraisons->index(idLigne,0).data().toInt();

        //cout << "id produit = " << this->modelProduits->index(idLigne,3).data().toInt() << endl;

        this->prod.annulerLivraisonByLivraison(idLivraisonARetirer);


    }

    mettreAJourTable();
}
