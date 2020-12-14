#include "consommateurig.h"
#include "cataloguesousig.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Consommateurig w;
    w.show();
    CatalogueSousConsommateur c;

    return a.exec();
}
