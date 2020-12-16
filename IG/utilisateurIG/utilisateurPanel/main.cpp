#include "inscriptionig.h"
#include "../../../Outils/sqltool.h"
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
            Inscriptionig *c=new Inscriptionig(nullptr);
            c->show();
            return a.exec();
            sqlTool::closeConnexion();
        }
}
