#include "formulairecycle.h"
#include "../../../Outils/sqltool.h"
#include <QApplication>
#include "../../../utilisateur.cpp"
int main(int argc, char *argv[])
{
    if(!sqlTool::openConnexion())
    {
        cout << "Erreur Connexion BDD dans IG producteurPanel" <<endl;
        return EXIT_FAILURE;
    }
    else
    {
        Responsable resp = Responsable(7);
        QApplication a(argc, argv);
        formulaireCycle* w = new formulaireCycle(nullptr, resp);
        w->show();
        return a.exec();
        sqlTool::closeConnexion();
    }
}
