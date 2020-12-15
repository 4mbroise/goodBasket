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
            //DialogueConsommateurs dc;
            Consommateur consommateur=Consommateur("jack","pont","Nancy","0785168954","jp12345868@gmail.com");
            Consommateurig *cig=new Consommateurig(nullptr,consommateur);
            cig->show();
            return a.exec();
            sqlTool::closeConnexion();
        }

}
