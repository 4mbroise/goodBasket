#include "consommateur.h"
#include "utilisateur.h"
#include <QDebug>
#include <iostream>

using namespace std;

Consommateur::Consommateur(QString nom,QString prenom,QString adresse,QString phone,QString email):Utilisateur(nom,prenom,adresse,phone,email){
    //this->gestionnaireDialogue.ajouterConsommateur(this);
    estConsommateur=true;
    qDebug() << "Consommateur est créé" << endl;
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

/*void Consommateur::demanderAjouter(Produit p,int commande){
    this->gestionnaireDialogue.ajouterPanier(p,commande,this->id);
}

void Consommateur::ajouterProduitAuPanier(Livraison l){
    this->Panier.append(l);
}

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
    insertion.prepare("INSERT INTO Utilisateurs VALUES(:id,:nom,:prenom,:adresse,:telephone,:email,true,false,false)");
    insertion.bindValue(":id",id);
    insertion.bindValue(":nom",nom);
    insertion.bindValue(":prenom",prenom);
    insertion.bindValue(":adresse",adresse);
    insertion.bindValue(":telephone",phone);
    insertion.bindValue(":email",email);
    if(insertion.exec())
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
