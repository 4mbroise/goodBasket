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

const std::string Consommateur::getMessage()
{
    return this->message;
}

void Consommateur::setMessage(std::string mess)
{
    this->message=mess;
}


void Consommateur::consulterCatalogue(){

}



void Consommateur::ajouterProduitAuPanier(QString nom,int idConsommateur,int idProduit,int quantite,int prix,QString adressePC){
    QSqlQuery query;
    //recherche id max
    if(!query.exec("SELECT max(id) FROM Livraisons"))
       {
           qDebug() << "ERREUR recherche" << query.lastError();
       }
       else
       {
             qDebug() << "réussi"<<endl;
            query.next();
       }
        int actualMaxId = query.value(0).toInt();
    query.clear();
    //recherche dateLivraison
    query.prepare("SELECT dateLivraison FROM Cycle WHERE adressePC=:adresse");
    query.bindValue(":adresse",adressePC);
    if(!query.exec())
       {
           qDebug() << "ERREUR recherche" << query.lastError();
       }
       else
       {
            qDebug() << "réussi"<<endl;
            query.next();
       }
        QDate date = query.value(0).toDate();
         query.clear();
    //

    query.prepare("INSERT INTO Livraison(id,nom,idConsommatuer,idProduit,quantite,prix,dateDeLivraison,dateAchat,adressePC,prevue,annuler,payerResponsable)"
                  "VALUES(:id,:nom,:idConsommatuer,:idProduit,:quantite,:prix,:dateDeLivraison,:dateAchat,date('now'),false,false,false)");
    query.bindValue(":id",actualMaxId+1);
    query.bindValue(":nom",nom);
    query.bindValue(":idConsommateur",idConsommateur);
    query.bindValue(":idProduit",idProduit);
    query.bindValue(":quantite",quantite);
    query.bindValue(":prix",prix);
    query.bindValue(":dateDeLivraison",date);
    query.bindValue(":adressePC",adressePC);
    if(!query.exec())
    {
        qDebug() << "Erreur: " <<query.lastError();
    }
    else
    {
        qDebug() << "Réussi!";
    }
    query.clear();
    query.prepare("select quantite from Produit where idProduit=:idP");
    query.bindValue(":idP",idProduit);
    if(!query.exec())
    {
        qDebug() << "Erreur: " <<query.lastError();
    }
    else
    {
        qDebug() << "Réussi!";
    }
    query.next();
    int q=query.value(0).toInt();
    query.prepare("UPDATE Produit SET quantite=:quantite where idProduit=:idP");
    q=q-quantite;
    query.bindValue(":quantite",q);
    if(!query.exec())
    {
        qDebug() << "Erreur: " <<query.lastError();
    }
    else
    {
        qDebug() << "Réussi!";
    }
}
/*
void Consommateur::demanderExtraAjouter(Produit p,int extra){
    this->gestionnaireDialogue.extraAjouter(p,extra,this->id);
}

void Consommateur::ajouterExtraAuPanier(int position,Livraison l){
    this->Panier.insert(position,l);
}

void Consommateur::demanderSupprimerProduit(Produit p){
    this->gestionnaireDialogue.supprimerProduit(p,this->id);
}

void Consommateur::demanderSupprimerProduit(){
    for(Livraison l:this->Panier)
    {
        this->gestionnaireDialogue.supprimerProduit(l.getProduit(),this->id);
    }
}

void Consommateur::supprimerProduit(Livraison l){
    this->Panier.removeOne(l);
}*/
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
    insertion.prepare("INSERT INTO Utilisateurs(UtilisateurID,nom,prenom,adresse,telephone,email,pass,estConsommateur,estResponsable,estProducteur) VALUES(:id,:nom,:prenom,:adresse,:telephone,:email,:pass,true,false,false)");
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

QList<Livraison> Consommateur::getPanier(){
    return Panier;
}

int Consommateur::nbLivraison(){
    return Panier.count();
}

int Consommateur::nbLivraisonPrevues(){
    return LivraisonPrevues.count();
}

/*const std::string Consommateur::toString(){
    string resultat="Consommateur [ID-"+std::to_string(this->getId())+"]\n";
    resultat.append("Panier:\n");
    resultat.append("livraisons totales:"+to_string(nbLivraison()));
    for(int i=0;i<Panier.count();i++){
        Livraison l=Panier.at(i);
        resultat.append("No.:"+to_string(i)+l.toSring());
    }
    resultat.append("LivraisonPrevue:\n");
    resultat.append("livraisonPrevues totales:"+to_string(nbLivraisonPrevues()));
    for(int i=0;i<LivraisonPrevues.count();i++){
        Livraison lp=LivraisonPrevues.at(i);
        resultat.append("No.:"+to_string(i)+lp.toSring());
    }
    return resultat;
}*/
