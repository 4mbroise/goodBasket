#include "idgenerator.h"
#include <iostream>
#include <QDebug>
using namespace std;

IdGenerator IdGenerator::m_instance=IdGenerator();

IdGenerator::IdGenerator()
{
    qDebug()<<"Creation IdProducteurGenerator"<<endl;
    lastIdProducteur = 1;
    lastIdProduit = 1;
    lastIdErreur =1;
}

IdGenerator::~IdGenerator()
{
    qDebug()<<"Destruction IdGenerator"<<endl;
}

int IdGenerator::getNewIdProducteur()
{
    int idAReturn = this-> lastIdProducteur;       //Sauvegarde de l'id à retourner avant incrémentation
    this -> lastIdProducteur ++;                   //Incrémentation
    return idAReturn;
}

int IdGenerator::getNewIdProduit()
{
    int idAReturn = this-> lastIdProduit;       //Sauvegarde de l'id à retourner avant incrémentation
    this -> lastIdProduit ++;                   //Incrémentation
    return idAReturn;
}

int IdGenerator::getNewIdUtilisateur()
{
    int idAReturn = this-> lastIdUtilisateur;       //Sauvegarde de l'id à retourner avant incrémentation
    this -> lastIdUtilisateur++;               //Incrémentation
    return idAReturn;
}

int IdGenerator::getNewIdLivraison(){
    int idAReturn = this-> lastIdLivraison;       //Sauvegarde de l'id à retourner avant incrémentation
    this -> lastIdLivraison ++;                   //Incrémentation
    return idAReturn;
}

int IdGenerator::getNewIdErreur(){
    int idAReturn = this-> lastIdErreur;       //Sauvegarde de l'id à retourner avant incrémentation
    this -> lastIdErreur ++;                   //Incrémentation
    return idAReturn;
}

IdGenerator& IdGenerator::Instance()
{
    return m_instance;
}
