#include "producteurpanel.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    DialogueProducteurs dp = DialogueProducteurs();
    Producteur pr1 = Producteur(dp);

    QApplication a(argc, argv);
    producteurPanel* w = new producteurPanel(nullptr, dp.getProducteurById(1));
    w->show();
    return a.exec();
}
