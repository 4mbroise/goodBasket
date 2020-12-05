#include <QtDebug>
#include "dialogueconsommateurs.h"
#include "../consommateur.h"
#include "../Gestionnaire/gestionnaire.h"

#include <iostream>
using namespace std;

DialogueConsommateurs::DialogueConsommateurs(){
    qDebug()<<"Gestionnairedialogue du Consommateur est créé"<<endl;
}

DialogueConsommateurs::~DialogueConsommateurs(){
    qDebug()<<"Gestionnairedialogue du Consommateur est enlevé"<<endl;
}

Livraison DialogueConsommateurs::liv(Produit p,int quantite){
    Livraison l=Livraison(p,quantite);
    return l;
}

void DialogueConsommateurs::ajouterPanier(Produit p,int commande,int idConsommateur){
    if(!estDepasse(p,commande)){
        Consommateur *c=getConsommateur(idConsommateur);
        Livraison l=liv(p,commande);
        c->ajouterProduitAuPanier(l);
        qDebug()<<"l'ajoute est réussi"<<endl;
    } else {
        qDebug()<<"l'ajoute est échec car le commande dépasse le stock"<<endl;
    }
}

void DialogueConsommateurs::ajouterConsommateur(Consommateur* c){
    this->consommateurs.insert(c->getId(),c);
}

int DialogueConsommateurs::nbConsommateur(){
    return consommateurs.size();
}

void DialogueConsommateurs::extraAjouter(Produit p,int extra,int idConsommateur){
    Consommateur *c =getConsommateur(idConsommateur);
    QList<Livraison> panier=c->getPanier();
    for(int i=0;i<panier.count();i++){
        Livraison l=panier.at(i);
        Produit produit=l.getProduit();
        int id=produit.getId();
        int id2=p.getId();
        if(id==id2&&!estDepasse(p,l.getCommande()+extra)){
            l.ajouterCommande(extra);
            c->ajouterExtraAuPanier(i,l);
            continue;
        } else if(id==id2&&estDepasse(p,l.getCommande()+extra)){
            qDebug()<<"depasser le stock, interdit à ajouter"<<endl;
            continue;
        }
    }
}

bool estDepasse(Produit p,int commande){
    return p.getQuantite()<commande;
}

void DialogueProducteurs::notifierProducteurPayment(int Consommateurid,int montant)
{
    std::string s = "vous avez reçu le montant de remboursement ";
    s = s + to_string(montant);
    /*
    consommateurs.value(Consommateurid)->setMessage(s);
    à compléter plus tard
    */
    cout << s <<endl
}

std::string DialogueConsommateurs::toSring(){
    std::string returned = "Gestionnaire de Dialogue Consommateur(Nb producteur = ";
    returned.append(to_string(nbConsommateur())).append(")\n");
    QHashIterator<int,Consommateur*> i(this->consommateurs);
    while(i.hasNext())
    {
        i.next();
        returned.append("-(ID = "+std::to_string(i.key())+")- ");
        Consommateur* c=i.value();
        returned.append(c->toString()+"\n");
    }

    return returned;
}
