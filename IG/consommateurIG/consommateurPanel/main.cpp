#include "consommateurig.h"
#include "cataloguesousig.h"
#include "../../../consommateur.h"
#include "../../../Outils/sqltool.h"
#include "../../../Outils/sqltool.cpp"
#include <QApplication>



int main(int argc, char *argv[])
{

    if(!sqlTool::openConnexion())
        {
            cout << "Erreur Connexion BDD dans IG ConsommateurPanel" <<endl;
            return EXIT_FAILURE;
        }
        else
        {
            cout<<"BDD est connexion"<<endl;
            QApplication a(argc, argv);
            Consommateur consommateur=Consommateur(0);
            Consommateurig *c=new Consommateurig(nullptr,1);
            c->show();
            return a.exec();
            sqlTool::closeConnexion();
        }
}
