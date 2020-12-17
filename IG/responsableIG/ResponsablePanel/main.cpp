#include "widgetresponsable.h"

#include <QApplication>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WidgetResponsable w;
    w.show();
    return a.exec();
}
