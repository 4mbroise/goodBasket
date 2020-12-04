#include "erreur.h"
#include <QDebug>
#include <iostream>


/*
 * réfléchir que si on ajoute livraison plus tard
 * Erreur::Erreur(Livraison &l):livraison(l)
*/
Erreur::Erreur()
{
    this->quantiteErreur = 0;
};

bool Erreur::Verifier()
{
    if (this->quantiteErreur>0){
        return true;
    }else{
        return false;
    }
}


int Erreur::nbErreur()
{
    return this->quantiteErreur;
}

void Erreur::AjouterErreur(std::string erreur)
{

    this->erreurs.insert(this->quantiteErreur,erreur);
}

std::string Erreur::toString()
{
    std::string s = "Erreur recrutés :\n";
    QHashIterator<int,std::string> i(this->erreurs);
    while(i.hasNext())
    {
        i.next();
        s.append("  -(key = "+std::to_string(i.key())+")- ");
    }
    return s;
}
