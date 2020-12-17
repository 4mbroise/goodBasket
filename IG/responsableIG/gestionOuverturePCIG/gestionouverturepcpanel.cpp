#include "gestionouverturepcpanel.h"
#include "ui_gestionouverturepcpanel.h"
#include "QDate"

GestionOuverturePCPanel::GestionOuverturePCPanel(QWidget *parent, Responsable r)
    : QWidget(parent), responsable(r)
    , ui(new Ui::GestionOuverturePCPanel)
{

    this->setWindowTitle("gestion Ouverture du PC");

    ui->setupUi(this);
    this->responsable= r;

    ui->tableView->horizontalHeader()->setStretchLastSection(true);

    //init table
    this->model = new QSqlQueryModel;
    mettreAJourTable();


    this->formulaire = new formulaireCycle(this, r);
    this->layout()->addWidget(formulaire);

    connect(this->formulaire,SIGNAL(miseAJourTableCycle()),this,SLOT(mettreAJourTable()));

}

void GestionOuverturePCPanel::mettreAJourTable()
{
    QString requete = QString::fromStdString("SELECT dateDebut, dateVente, dateFinVente, dateLivraison "
                                             "FROM PointDeCollecte LEFT JOIN Cycle ON PointDeCollecte.idPointDeCollecte = Cycle.idPC "
                                             "WHERE idResponsablePC = ");
    requete.append(QString::number(this->responsable.getId()));

    cout << requete.toStdString() <<endl;

    model->setQuery(requete);
    model->setHeaderData(0, Qt::Horizontal ,tr("Date Début Cycle"));
    model->setHeaderData(1, Qt::Horizontal ,tr("Ouverture des ventes"));
    model->setHeaderData(2, Qt::Horizontal ,tr("Fermeture des ventes"));
    model->setHeaderData(3, Qt::Horizontal ,tr("Date de Livraison"));

    ui->tableView->setModel(model);

}

GestionOuverturePCPanel::~GestionOuverturePCPanel()
{
    delete model;
    delete formulaire;
    delete ui;
}


void GestionOuverturePCPanel::on_pushButton_released()
{
    int idLigne;

    //ui->tableView->
    cout << "selection count = " << ui->tableView->selectionModel()->selection().count() << endl;

    if(ui->tableView->selectionModel()->selectedRows().count())
    {
        idLigne = ui->tableView->selectionModel()->currentIndex().row();

        QDate dateDebutCycle = this->model->index(idLigne,0).data().toDate();
        QDate dateVente = this->model->index(idLigne,1).data().toDate();
        QDate dateFinVente = this->model->index(idLigne,2).data().toDate();
        QDate dateLivraison = this->model->index(idLigne,3).data().toDate();

        this->responsable.retirerCycle(dateDebutCycle, dateVente, dateFinVente, dateLivraison);

        //this->prod.retirerProduit(idProduitARetirer);
        mettreAJourTable();
    }

}

void GestionOuverturePCPanel::on_pushButton_2_released()
{
    this->responsable.fermerPointDeCollecte();
    mettreAJourTable();
}
