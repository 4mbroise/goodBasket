#include "idtgenerator.h"
#include <iostream>
using namespace std;

IdProduitGenerator IdProduitGenerator::m_instance=IdProduitGenerator();

IdProduitGenerator::IdProduitGenerator()
{
    //cout<<"Creation IdProduitGenerator"<<endl;
    lastIdProduit = 1;
}

IdProduitGenerator::~IdProduitGenerator()
{
    //cout<<"Destruction IdProduitGenerato"<<endl;
}

int IdProduitGenerator::getNewIdProduit()
{
    int idAReturn = this-> lastIdProduit;       //Sauvegarde de l'id à retourner avant incrémentation
    this -> lastIdProduit ++;                   //Incrémentation
    return idAReturn;
}

int idProducteurGenerator::getNewIdProducteur()
{
    int idAReturn = this-> lastIdProducteur;       //Sauvegarde de l'id à retourner avant incrémentation
    this -> lastIdProducteur ++;                   //Incrémentation
    return idAReturn;
}

IdProduitGenerator& IdProduitGenerator::Instance()
{
    return m_instance;
}
