#include "produit.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    Produit* pr = new Produit(13, 12, 12.3,"test" ,"test2" );
    delete pr;
    cout << "aeaze"<<endl;
    return 0;
}
