#include "producteurpanel.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    DialogueProducteurs dp = DialogueProducteurs();
    Producteur pr1 = Producteur(dp);
    pr1.demanderAjoutProduit(10,5.5,"courgettes","courgettes.jpg");
    pr1.demanderAjoutProduit(25,2.285,"tomates","tomates.jpg");

    QApplication a(argc, argv);
    producteurPanel* w = new producteurPanel(nullptr, dp.getProducteurById(1));
    w->show();
    return a.exec();

}
