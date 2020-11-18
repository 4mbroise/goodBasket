#include "../../produit.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    cout << "DEBUT TEST"<<endl;

    Produit pr = Produit(13, 12, 12.3,"name" ,"test2" );

    bool constructeurOK = true;

    if(pr.getId() != 13)
    {
        cout << "Id probleme"<<endl;
        constructeurOK = false;
    }
    if(pr.getPrix()!=12.3)
    {
        cout << "prix probleme"<<endl;
        constructeurOK = false;
    }
    if(pr.getQuantite()!=12)
    {
        cout << "quantite probleme"<<endl;
        constructeurOK = false;
    }
    if(pr.getNom().toStdString().compare("name")!=0)
    {
        cout << "name probleme"<<endl;
        constructeurOK = false;
    }

    pr.setPrix(123.321);

    if(pr.getPrix()!=123.321)
    {
        cout << "setterPrix probleme"<<endl;
        constructeurOK = false;
    }

    //delete pr;

    cout << "FIN TEST"<<endl;

    return 0;
}
