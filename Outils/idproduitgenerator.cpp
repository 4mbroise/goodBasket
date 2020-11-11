#include "idproduitgenerator.h"
#include <iostream>
using namespace std;

IdProduitGenerator IdProduitGenerator::m_instance=IdProduitGenerator();

IdProduitGenerator::IdProduitGenerator()
{
    cout<<"Creation"<<endl;
    lastIdProduit = 1;
}

IdProduitGenerator::~IdProduitGenerator()
{
    cout<<"Destruction"<<endl;
}

int IdProduitGenerator::getNewIdProduit()
{
    int idAReturn = this-> lastIdProduit;       //Sauvegarde de l'id à retourner avant incrémentation
    this -> lastIdProduit ++;                   //Incrémentation
    return idAReturn;
}

IdProduitGenerator& IdProduitGenerator::Instance()
{
    return m_instance;
}

int main(void)
{
    //1er appel de Instance: on alloue le pointeur SoundManager::m_instance
    IdProduitGenerator& ptr1=IdProduitGenerator::Instance();
    cout <<ptr1.getNewIdProduit()<< endl;
    cout <<ptr1.getNewIdProduit()<< endl;
    cout <<ptr1.getNewIdProduit()<< endl;
    cout <<ptr1.getNewIdProduit()<< endl;
    IdProduitGenerator& ptr2=IdProduitGenerator::Instance();
    cout <<ptr2.getNewIdProduit()<< endl;
    cout <<ptr2.getNewIdProduit()<< endl;
    cout <<ptr2.getNewIdProduit()<< endl;
    cout <<ptr2.getNewIdProduit()<< endl;



    return 0;
}
