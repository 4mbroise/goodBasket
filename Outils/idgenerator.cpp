#include "idgenerator.h"
#include <iostream>
using namespace std;

IdGenerator IdGenerator::m_instance=IdGenerator();

IdGenerator::IdGenerator()
{
    //cout<<"Creation IdProducteurGenerator"<<endl;
    lastIdProducteur = 1;
    lastIdProduit = 1;
}

IdGenerator::~IdGenerator()
{
    //cout<<"Destruction IdGenerator"<<endl;
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

IdGenerator& IdGenerator::Instance()
{
    return m_instance;
}
