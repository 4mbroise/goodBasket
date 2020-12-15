#include "responsable.h"
#include "GestionnairesDeDialogue/dialogueproducteurs.h"
#include "Gestionnaire/gestionnaire.h"
#include <QDebug>
#include <iostream>
#include <QDate>
using namespace std;


Responsable::Responsable(QString nom,QString prenom,QString adresse,QString phone,QString email):Utilisateur(nom,prenom,adresse,phone,email)
{
    this->estResponsable=true;
    this->estConsommateur=false;
    this->confirmer=false;
}


Responsable::Responsable(int id):Utilisateur(id),pc(PC(id))
{
    this->id = id;
}

Responsable::Responsable():Utilisateur(),pc(PC())
{
    this->id = -1;
}

Responsable::~Responsable(){
    qDebug() << "Responsable est enlevé" << endl;
}

const int& Responsable::getId(){
    return this->id;
    qDebug()<<"get id du Responsable"<<endl;
}


const QString& Responsable::getNom(){
    return  this->nom;
    qDebug()<<"get nom du Responsable"<<endl;
}


const QString& Responsable::getPrenom(){
    return  this->prenom;
    qDebug()<<"get prenom du Responsable"<<endl;
}

const QString& Responsable::getAdresse(){
    return this->adresse;
    qDebug()<<"get adresse du Responsable"<<endl;
}

const QString& Responsable::getPhone(){
    return this->phone;
    qDebug()<<"get numéro de téléphon du Responsable"<<endl;
}

const QString& Responsable::getEmail(){
    return this->email;
    qDebug()<<"get email du Responsable"<<endl;
}


void Responsable::changeNom(std::string nom){
    this->nom=QString(nom.c_str());
    qDebug()<<"changer ou setter nom du Responsable"<<endl;
}


void Responsable::changePrenom(std::string prenom){
    this->prenom=QString(prenom.c_str());
    qDebug()<<"changer ou setter prenom du Responsable"<<endl;
}


void Responsable::changeAdresse(std::string adresse){
    this->adresse=QString(adresse.c_str());
    qDebug()<<"changer ou setter adresse du Responsable"<<endl;
}

void Responsable::changePhone(std::string phone){
    this->phone=QString(phone.c_str());
    qDebug()<<"changer ou setter numéro de téléphone du Responsable"<<endl;
}


void Responsable::changeEmail(std::string email){
    this->email=QString(email.c_str());
    qDebug()<<"changer ou setter email du Responsable"<<endl;
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
