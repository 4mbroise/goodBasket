#include "gestionouverturepcpanel.h"

#include <QApplication>

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
        GestionOuverturePCPanel* w = new GestionOuverturePCPanel(nullptr, resp);
        w->show();
        return a.exec();
        sqlTool::closeConnexion();
    }
}
