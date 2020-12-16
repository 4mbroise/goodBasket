#include "responsable.h"
#include "GestionnairesDeDialogue/dialogueproducteurs.h"
#include "Gestionnaire/gestionnaire.h"
#include <QDebug>
#include <iostream>
#include <QDate>
using namespace std;


Responsable::Responsable(QString nom,QString prenom,QString adresse,QString phone,QString email, QString pass):Utilisateur(nom,prenom,adresse,phone,email,pass)
{
    this->estResponsable=true;
    this->estConsommateur=false;
    this->estProducteur=false;
    this->confirmer=false;
}


Responsable::Responsable(int id):Utilisateur(id)
{
    this->id = id;
}



/*Responsable::~Responsable(){
    qDebug() << "Responsable est enlevé" << endl;
}
*/

void Responsable::ajouterResponsableBDD(){
    QSqlQuery insertion;
    insertion.prepare("INSERT INTO Utilisateurs VALUES(:id,:nom,:prenom,:adresse,:telephone,:email,:pass,false,true,false)");
    insertion.bindValue(":id",id);
    insertion.bindValue(":nom",nom);
    insertion.bindValue(":prenom",prenom);
    insertion.bindValue(":adresse",adresse);
    insertion.bindValue(":telephone",phone);
    insertion.bindValue(":email",email);
    insertion.bindValue(":pass",pass);

    if(insertion.exec())
    {
        qDebug() << "Erreur: " <<insertion.lastError();
    }
    else
    {
        qDebug() << "réussi!";
    }
    insertion.clear();
    insertion.prepare("INSERT INTO Responsable VALUES(:id)");
    insertion.bindValue(":id",id);
    if(!insertion.exec())
    {
        qDebug() << "Erreur: " <<insertion.lastError();
    }
    else
    {
        qDebug() << "réussi!";
    }

}


void Responsable::PayerProducteurs(int producteurid)
{
    //------ATTENTION-----------this->gestionnaire.CalculerMontantPayement(this->id, producteurid);

    /* procedure que gestionnaire retourner montant confirmer ou non*/
    if(this->confirmer){

        //------ATTENTION-----------this->gestionnaire.Payer(this->id, producteurid);

    }
    this->confirmer=false;  // reinitialiser
}

void Responsable::Confirmer()
{
    this->confirmer=true;
}

std::string Responsable::GetMessage()
{
    return this->message;
}

void Responsable::RecevoirMessage(std::string mess)
{
    this->message=mess;
}

void Responsable::ConsulterReports()
{
    //------ATTENTION-----------this->gestionnaire.NotifierErreur(this->id);
}


PC& Responsable::getPC(){
    return  this->pc;
}

void Responsable::DemanderRembourser(int consommateurId)
{
    //------ATTENTION-----------

    /*    if(this->gestionnaire.VerifeirRemboursement(consommateurId,this->id))
    {
         qDebug()<<"attente confirmer"<<endl;
    }
    if(this->confirmer)
    {
        this->gestionnaire.Rembourser(consommateurId,this->id);
    }
    */
}


void Responsable::demanderPC(int id,std::string villes, int codePostal, int numero, std::string nomRue){
    //------ATTENTION-----------gestionnaire.demanderPC(id,villes,codePostal,numero,nomRue);
}

void Responsable::setPC(PC pc){
    this->pc=pc;
}

void Responsable::recruterProducteur(std::string recrutement){
   //------ATTENTION-----------gestionnaire.getDialogueProducteurs().recruteProducteur(this->id,recrutement);
}

//------ATTENTION-----------
/*
QHash<int,std::string>& Responsable::consulterDemande(){
    return  gestionnaire.getDialogueProducteurs().getDemande();
}
*/

bool Responsable::reponseRecrutement(int idProducteur,std::string demande){
    return true;
}

/*
void Responsable::ajouterProducteur(int idProducteur,std::string demande){
    if(reponseRecrutement(id,demande)){
        Producteur *p=gestionnaire.getDialogueProducteurs().getProducteurById(idProducteur);
        pc.ajouterProducteur(*p);
    }
}
*/

bool Responsable::isCycleValide(QDate dateDebutCycle, QDate dateVente, QDate dateFinVente, QDate dateLivraison)
{
    return (dateDebutCycle < dateVente && dateVente < dateFinVente && dateFinVente < dateLivraison);
}

void Responsable::ajouterCycle(QDate dateDebutCycle, QDate dateVente, QDate dateFinVente, QDate dateLivraison)
{
    QSqlQuery sqlQuery;

    //Recherche de l'idPC
    QString requeteRechercheIdPc = QString::fromStdString("SELECT idPointDeCollecte FROM PointDeCollecte WHERE idResponsablePC = ");
    requeteRechercheIdPc.append(QString::number(this->id));

    if(!sqlQuery.exec(requeteRechercheIdPc))
    {
        qDebug() << "ERREUR recherche Id PC " << sqlQuery.lastError();
    }
    else
    {
        sqlQuery.next();
        int idPC = sqlQuery.value(0).toInt();

        //Insertion du cycle dans la table Cycle de la BDD
        QSqlQuery requeteInsertion;
        requeteInsertion.prepare("INSERT INTO Cycle (dateDebut,dateVente,dateFinVente,dateLivraison,idPC)"
                                 " VALUES(:dateDebut,:dateVente,:dateFinVente,:dateLivraison,:idPC);");

        requeteInsertion.bindValue(":dateDebut", dateDebutCycle.toString(Qt::ISODate));
        requeteInsertion.bindValue(":dateVente", dateVente.toString(Qt::ISODate));
        requeteInsertion.bindValue(":dateFinVente", dateFinVente.toString(Qt::ISODate));
        requeteInsertion.bindValue(":dateLivraison", dateLivraison.toString(Qt::ISODate));
        requeteInsertion.bindValue(":idPC", idPC);

        if(!requeteInsertion.exec())
        {
            qDebug() << "ERREUR insertion Cycle" << requeteInsertion.lastError();
        }
        else
        {
             qDebug() << "insertion Cycle réussies" << endl;
        }
    }
}

void Responsable::retirerCycle(QDate dateDebutCycle, QDate dateVente, QDate dateFinVente, QDate dateLivraison)
{
    QSqlQuery sqlQuery;

    //Recherche de l'idPC
    QString requeteRechercheIdPc = QString::fromStdString("SELECT idPointDeCollecte FROM PointDeCollecte WHERE idResponsablePC = ");
    requeteRechercheIdPc.append(QString::number(this->id));

    if(!sqlQuery.exec(requeteRechercheIdPc))
    {
        qDebug() << "ERREUR recherche Id PC " << sqlQuery.lastError();
    }
    else
    {
        sqlQuery.next();
        int idPC = sqlQuery.value(0).toInt();

        //Insertion du cycle dans la table Cycle de la BDD
        QSqlQuery requeteInsertion;
        requeteInsertion.prepare("DELETE FROM Cycle WHERE dateDebut = :dateDebut AND dateVente = :dateVente "
                                 "AND dateFinVente = :dateFinVente AND dateLivraison = :dateLivraison AND idPC = :idPC");

        requeteInsertion.bindValue(":dateDebut", dateDebutCycle.toString(Qt::ISODate));
        requeteInsertion.bindValue(":dateVente", dateVente.toString(Qt::ISODate));
        requeteInsertion.bindValue(":dateFinVente", dateFinVente.toString(Qt::ISODate));
        requeteInsertion.bindValue(":dateLivraison", dateLivraison.toString(Qt::ISODate));
        requeteInsertion.bindValue(":idPC", idPC);

        if(!requeteInsertion.exec())
        {
            qDebug() << "ERREUR insertion Cycle" << requeteInsertion.lastError();
        }
        else
        {
             qDebug() << "insertion Cycle réussies" << endl;
        }
    }
}

void Responsable::fermerPointDeCollecte()
{
    QSqlQuery sqlQuery;

    //Recherche de l'idPC
    QString requeteRechercheIdPc = QString::fromStdString("SELECT idPointDeCollecte FROM PointDeCollecte WHERE idResponsablePC = ");
    requeteRechercheIdPc.append(QString::number(this->id));

    if(!sqlQuery.exec(requeteRechercheIdPc))
    {
        qDebug() << "ERREUR recherche Id PC " << sqlQuery.lastError();
    }
    else
    {
        sqlQuery.next();
        int idPC = sqlQuery.value(0).toInt();

        //Insertion du cycle dans la table Cycle de la BDD
        QSqlQuery requeteInsertion;
        requeteInsertion.prepare("DELETE FROM Cycle WHERE idPC = :id");

        requeteInsertion.bindValue(":id", idPC);

        if(!requeteInsertion.exec())
        {
            qDebug() << "ERREUR insertion Cycle" << requeteInsertion.lastError();
        }
        else
        {
             qDebug() << "insertion Cycle réussies" << endl;
        }
    }

}
