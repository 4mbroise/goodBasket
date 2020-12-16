#include "producteur.h"
#include <QDebug>
#include <QString>
#include <iostream>
using namespace std;

/*
Producteur::Producteur(DialogueProducteurs &dp):gestionnaireDialogue(dp)
{
    IdGenerator& gen = IdGenerator::Instance();
    int newId = gen.getNewIdProducteur();
    this->id = newId;
    gestionnaireDialogue = dp;
    gestionnaireDialogue.ajouterProducteur(this);
};

Producteur::Producteur(int idUtilisateur, DialogueProducteurs &dp):gestionnaireDialogue(dp)
{
    this->id = idUtilisateur;
    gestionnaireDialogue = dp;
    gestionnaireDialogue.ajouterProducteur(this);

}
*/

Producteur::Producteur(QString nom,QString prenom,QString adresse,QString phone,QString email, QString pass):Utilisateur(nom,prenom,adresse,phone,email,pass){
    this->estResponsable=true;
    this->estConsommateur=false;
    this->estProducteur=false;
}

Producteur::Producteur(int idUtilisateur):Utilisateur(idUtilisateur)
{
    this->id = idUtilisateur;
}

/*Producteur::Producteur()
{
    this->id = -1;
}*/

/*
void Producteur::demanderAjoutProduit(int quantite, double prix, std::string nom, std::string imagePath)
{
    qDebug() << "DemanderAjoutProduit" << endl;
    gestionnaireDialogue.ajouterProduit(prix, quantite, nom, imagePath, this->id);
}
*/

void Producteur::ajouterProduit(int quantite, double prix, std::string nom, std::string imagePath)
{
    IdGenerator& gen = IdGenerator::Instance();
    int idProduit = gen.getNewIdProduit();
    Produit produitAjoute = Produit(idProduit, quantite, prix, nom, imagePath);

    boutique.insert(idProduit,produitAjoute);
}


void Producteur::ajouterProducteurBDD(){
    QSqlQuery insertion;
    insertion.prepare("INSERT INTO Utilisateurs VALUES(:id,:nom,:prenom,:adresse,:telephone,:email,:pass,false,false,true)");
    insertion.bindValue(":id",id);
    insertion.bindValue(":nom",nom);
    insertion.bindValue(":prenom",prenom);
    insertion.bindValue(":adresse",adresse);
    insertion.bindValue(":telephone",phone);
    insertion.bindValue(":email",email);
    insertion.bindValue(":pass",pass);

    if(!insertion.exec())
    {
        qDebug() << "Erreur: " <<insertion.lastError();
    }
    else
    {
        qDebug() << "réussi!";
    }
    insertion.clear();
    insertion.prepare("INSERT INTO Producteurs(id) VALUES(:id)");
    insertion.bindValue(":id",id);
    if(insertion.exec())
    {
        qDebug() << "Erreur: " <<insertion.lastError();
    }
    else
    {
        qDebug() << "réussi!";
    }

}

void Producteur::ajouterProduitBDD(int quantite, double prix, std::string nom)
{
    //On cherche l'idProduit max dans la table
    QSqlQuery sqlQuery;
    if(!sqlQuery.exec("SELECT max(idProduit) FROM Produit"))
    {
        qDebug() << "ERREUR requete SQL" << sqlQuery.lastError();
    }
    else
    {
        //On insere le nouveau produit avec comme id l'idProduitMax qu'on a trouvé +1
        sqlQuery.next();
        int actualMaxId = sqlQuery.value(0).toInt();

        QSqlQuery requeteInsertion;
        requeteInsertion.prepare("INSERT INTO Produit (idProduit, prix, nom, quantite, idProducteur)"
                                "VALUES(:idProduit, :prix, :nom, :quantite, :idProducteur)");



        requeteInsertion.bindValue(":idProduit", actualMaxId+1);
        requeteInsertion.bindValue(":prix", prix);
        requeteInsertion.bindValue(":nom", QString::fromStdString(nom));
        requeteInsertion.bindValue(":quantite", quantite);
        requeteInsertion.bindValue(":idProducteur", this->id);

        if(!requeteInsertion.exec())
        {
            qDebug() << "ERREUR insertion nouveau Produit" << sqlQuery.lastError();
        }
        else
        {
             qDebug() << "insertion réussies" << endl;
        }
    }

}

bool Producteur::produitExiste(int idProduit)
{
    return this->boutique.contains(idProduit);
}

/*
void Producteur::demanderRetirerProduit(int idProduit)
{
    this->gestionnaireDialogue.retirerProduit(idProduit, this->id);
}*/

const int& Producteur::getId()
{
    return this->id;
}

const std::string Producteur::getMessage()
{
    return this->message;
}

void Producteur::setMessage(std::string mess)
{
    this->message=mess;
}

void Producteur::retirerProduit(int idProduit)
{
    QSqlQuery sqlQuery;

    QString query= QString("DELETE FROM Produit WHERE idProduit = ");
    query.append(QString::number(idProduit));
    query.append(QString::fromStdString(" AND idProducteur = "));
    query.append(QString::number(this->id));
    sqlQuery.prepare(query);

    if(!sqlQuery.exec())
    {
        qDebug() << "ERREUR DELETE Produit SQL" << sqlQuery.lastError();
    }
    else
    {
        qDebug() << "SUCCES DELETE Produit SQL";
    }
}

/*
void Producteur::setGestionnaireDialogue(DialogueProducteurs &dp)
{
    this->gestionnaireDialogue = dp;

}
*/

void Producteur::annulerLivraisonByLivraison(int idlivraison)
{
    QSqlQuery sqlQuery;

    QString query= QString("UPDATE Livraisons SET prevue = 'false', annuler = 'true' WHERE id = ");
    query.append(QString::number(idlivraison));
    sqlQuery.prepare(query);

    if(!sqlQuery.exec())
    {
        qDebug() << "ERREUR UDPATE annulation par idLivraison" << sqlQuery.lastError();
    }
    else
    {
        qDebug() << "SUCCES UDPATE annulation par idLivraison";
    }
}

void Producteur::annulerLivraisonByProduit(int idProduit)
{
    QSqlQuery sqlQuery;

    QString query= QString("UPDATE Livraisons SET prevue = 'false', annuler = 'true' WHERE idProduit = ");
    query.append(QString::number(idProduit));
    sqlQuery.prepare(query);

    if(!sqlQuery.exec())
    {
        qDebug() << "ERREUR UDPATE annulation par idProduit" << sqlQuery.lastError();
    }
    else
    {
        qDebug() << "SUCCES UDPATE annulation par idProduit";
    }
}

/*
void Producteur::demanderRecrutement(int idResponsable,std::string demande){
    gestionnaireDialogue.recevoirDemande(this->id,idResponsable,demande);
}
*/

QHashIterator<int,Produit> Producteur::iterator(){
    QHashIterator<int,Produit> i(this->boutique);
    return i;
}

void Producteur::operator=(const Producteur& p ){
    this->id=p.id;
    this->boutique=p.boutique;
    this->message=p.message;
    //this->gestionnaireDialogue=p.gestionnaireDialogue;

}

const std::string  Producteur::toString()
{
    std::string returned = "Producteur [ID-"+std::to_string(this->getId())+"]\n";
    QHashIterator<int,Produit> i=this->iterator();
    while(i.hasNext())
    {
        i.next();
        returned.append("      -(key = "+std::to_string(i.key())+")- ");
        Produit pr= i.value();
        returned.append(pr.toString()+"\n");
    }

    return returned;
}


