#include "Widgetp.h"

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
        //DialogueProducteurs dp = DialogueProducteurs();
        Producteur pr1 = Producteur(0);

        QApplication a(argc, argv);
        WidgetProducteur* w = new WidgetProducteur(nullptr, pr1);
        w->show();
        return a.exec();
        cout << "close Co" <<endl;
        sqlTool::closeConnexion();
    }
}
