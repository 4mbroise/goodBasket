#ifndef SQLTOOL_H
#define SQLTOOL_H

#include <QSqlError>
#include <QSqlDatabase>
#include <iostream>
#include <QDebug>

using namespace std;

class sqlTool
{
public :
    sqlTool();
    static QSqlDatabase initBDD();
    static bool openConnexion();
    static void closeConnexion();
};

#endif // SQLTOOL_H
