#include "consommateur.h"
#include "utilisateur.h"
#include <QDebug>
#include <iostream>
#include <QDate>
using namespace std;

Consommateur::Consommateur(QString nom,QString prenom,QString adresse,QString phone,QString email, QString pass):Utilisateur(nom,prenom,adresse,phone,email,pass){
    estConsommateur=true;
    this->estResponsable=true;
    this->estProducteur=false;
    qDebug() << "Consommateur est créé" << endl;
}

Consommateur::Consommateur(int idConsommateur):Utilisateur(idConsommateur){
    this->id=idConsommateur;
}

void Consommateur::ajouterProduitAuPanier(QString nom,int idConsommateur,int idProduit,int quantite,double prix,QString adressePC){
    QSqlQuery query;
    //recherche id max
    if(!query.exec("SELECT max(id) FROM Livraisons"))
       {
           qDebug() << "ERREUR recherche" << query.lastError();
       }
       else
       {
             qDebug() << "1réussi"<<endl;
            query.next();
       }
        int actualMaxId = query.value(0).toInt();
    query.clear();
    //recherche dateLivraison
    query.prepare("SELECT distinct dateLivraison FROM Cycle,PointDeCollecte WHERE PointDeCollecte.adresse=:adresse AND PointDeCollecte.idPointDeCollecte=Cycle.idPC ");
    query.bindValue(":adresse",adressePC);
    if(!query.exec())
       {
           qDebug() << "ERREUR recherche" << query.lastError();
       }
       else
       {
            qDebug() << "2réussi"<<endl;
            query.next();
       }
        QString date = query.value(0).toString();
    //

    query.prepare("INSERT INTO Livraisons(id,nom,idConsommateur,idProduit,quantite,prix,dateDeLivraison,dateAchat,adressePC,prevue,annuler,payerResponsable) VALUES(:id,:nom,:idConsommateur,:idProduit,:quantite,:prix,:dateDeLivraison,date('now'),:adressePC,FALSE,FALSE,FALSE);");
    query.bindValue(":id",actualMaxId+1);
    query.bindValue(":nom",nom);
    query.bindValue(":idConsommateur",idConsommateur);
    query.bindValue(":idProduit",idProduit);
    query.bindValue(":quantite",quantite);
    query.bindValue(":prix",prix);
    query.bindValue(":dateDeLivraison",date);
    query.bindValue(":adressePC",adressePC);
     qDebug() <<actualMaxId+1<<nom<<idConsommateur<<idProduit<<quantite<<prix<<date<<adressePC<<endl;
    if(!query.exec())
    {
        qDebug() << "Erreur: " <<query.lastError();
    }
    else
    {
        qDebug() << "3Réussi!";
    }
}

void Consommateur::ajouterConsommateurBDD(){
    QSqlQuery insertion;
    if(!insertion.exec("SELECT max(UtilisateurID) FROM Utilisateurs"))
       {
           qDebug() << "ERREUR requete SQL" << insertion.lastError();
       }
       else
       {
            insertion.next();
       }
        int actualMaxId = insertion.value(0).toInt();

    qDebug()<<"++++++++++++++++++"+pass<<endl;
    insertion.clear();
    insertion.prepare("INSERT INTO Utilisateurs(UtilisateurID,nom,prenom,adresse,telephone,email,passe,estConsommateur,estResponsable,estProducteur) VALUES(:id,:nom,:prenom,:adresse,:telephone,:email,:pass,true,false,false)");
    insertion.bindValue(":id",actualMaxId+1);
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
    insertion.prepare("INSERT INTO Consommateur VALUES(:id)");
    insertion.bindValue(":id",actualMaxId+1);
    if(!insertion.exec())
    {
        qDebug() << "Erreur: " <<insertion.lastError();
    }
    else
    {
        qDebug() << "réussi!";
    }
}



void Consommateur::commanderPanier()
{
    QSqlQuery panier;
    QSqlQuery updateProduitStock;
    QSqlQuery updateLivraison;

    QString requetePanierString = QString::fromStdString("SELECT idProduit,quantite FROM Livraisons WHERE idConsommateur =");
    QString requeteUpdateStock;

    requetePanierString.append(QString::number(this->id));

    if(!panier.exec(requetePanierString))
    {
        qDebug() << "Erreur: " <<panier.lastError();
    }
    else
    {
        while(panier.next())
        {
            updateProduitStock.prepare( "UPDATE Produit\
                                        SET quantite = quantite - :quantity\
                                        WHERE idProduit = :idProduitAUpdtae;");

            updateProduitStock.bindValue(":quantity", panier.value(1).toString());
            updateProduitStock.bindValue(":idProduitAUpdtae", panier.value(0).toString());
            if(!updateProduitStock.exec())
            {
                qDebug() << "Erreur: " <<panier.lastError();
            }
            else
            {
                 qDebug() << "Réussi:" <<endl;
            }
        }
    }
    requetePanierString = QString::fromStdString("UPDATE Livraisons SET prevue = 1 WHERE idConsommateur =");
    requetePanierString.append(QString::number(this->id));
    if(!panier.exec(requetePanierString))
    {
        qDebug() << "Erreur: " <<panier.lastError();
    }

}


