#include "../../Outils/idgenerator.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    IdGenerator& gen = IdGenerator::Instance();

    bool singletonOK = true;

    for(int i=1;i<=100000;i++)
    {
        if(i!=gen.getNewIdProduit())
        {
            singletonOK = false;
        }
        if(i!=gen.getNewIdProducteur())
        {
            singletonOK = false;
        }
    }

    if(singletonOK)
    {
        cout<<"Test Concluant"<<endl;
    }
    else
    {
        cout<<"Test Erreur"<<endl;
    }
    
    return 0;
}
