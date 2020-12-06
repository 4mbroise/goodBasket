#include "pc.h"
#include <QDebug>
#include <iostream>

using namespace std;

PC::PC(std::string adressePC){
    this->adresse=adressePC.c_str();
    this->etat=false;
    qDebug()<<"PC est créé"<<endl;

}

PC::~PC(){
    qDebug()<<"PC est enlevé"<<endl;
}


const QString& PC::getAdressePC(){
    return adresse;
}

const Producteur* PC::getProducteur(int idProducteur){

        return producteurs.value(idProducteur);
}

int PC::nbProducteur(){
    return producteurs.size();
}

const bool& PC::getEtat(){
    return  etat;
}

void PC::setAdresse(std::string adressePC){
    this->adresse=adressePC.c_str();
}

void PC::ouvrirPC(){
    this->etat=true;
     qDebug()<<"PC est ouvert"<<endl;
}

void PC::fermerPC(){
    this->etat=false;
     qDebug()<<"PC est fermé"<<endl;
}

QHashIterator<int,Producteur*> PC::iterator(){
    QHashIterator<int,Producteur*> i(this->producteurs);
    return i;
}


QHash<Produit*,Producteur*> PC::getCatalogue(){
    QHash<Produit*,Producteur*> catalogue;
    QHashIterator<int,Producteur*> i=this->iterator();
    while(i.hasNext())
    {
       Producteur *p=i.next().value();
       QHashIterator<int,Produit*> it=p->iterator();
       while(it.hasNext()){
           Produit* produit=it.next().value();
           catalogue.insert(produit,p);
       }
    }
    return catalogue;
}



void PC::ajouterProducteur(Producteur pdct){
   this->producteurs.insert(pdct.getId(),&pdct);
}


const std::string PC::toString(){
    string resultat="PC [adress:"+this->adresse.toStdString()+"]\n";
    resultat.append("catalogue:\n");
    QHashIterator<Produit*,Producteur*>i =getCatalogue();
    int num=0;
    while(i.hasNext()){
        Producteur* pdct=i.next().value();
        Produit* pd=i.next().key();
        num++;
        resultat.append("No."+to_string(num)+":\n"+pd->toString()+"\n[Producteur<ID-"+to_string(pdct->getId())+">]\n");
    }
    return resultat;
}
