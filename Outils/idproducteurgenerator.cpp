#include "zaezaezae.h"
#include <iostream>
using namespace std;

idProducteurGenerator idProducteurGenerator::m_instance=idProducteurGenerator();

idProducteurGenerator::idProducteurGenerator()
{
    //cout<<"Creation IdProducteurGenerator"<<endl;
    lastIdProducteur = 1;
}

idProducteurGenerator::~idProducteurGenerator()
{
    //cout<<"Destruction IdProducteurGenerator"<<endl;
}

int idProducteurGenerator::getNewIdProducteur()
{
    int idAReturn = this-> lastIdProducteur;       //Sauvegarde de l'id à retourner avant incrémentation
    this -> lastIdProducteur ++;                   //Incrémentation
    return idAReturn;
}

idProducteurGenerator& idProducteurGenerator::Instance()
{
    return m_instance;
}
