#include "gestionnaireig.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GestionnaireIG w;
    w.show();
    return a.exec();
}
