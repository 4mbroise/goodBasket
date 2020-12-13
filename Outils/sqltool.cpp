#include "sqltool.h"

#include <iostream>
using namespace std;

sqlTool::sqlTool()
{

}

QSqlDatabase sqlTool::initBDD()
{
    QSqlDatabase  db =QSqlDatabase::addDatabase("QSQLITE");    // type
                  db.setDatabaseName("maze");                     //nom de database
                  db.setHostName("127.0.0.1");                    //Host
                  db.setPort(3306);                               //Porte
                  db.setUserName("root");                         //login
                  db.setPassword("root");
                  db.setDatabaseName("../../../db.sqlite");
    return db;
}

bool sqlTool::openConnexion()
{

    QSqlDatabase db = initBDD();

    if(!db.open())
    {
        qDebug() << "ERREUR requete SQL" << db.lastError();        return false;
        return false;
    }
    else
    {
        return true;
    }

}

void sqlTool::closeConnexion()
{
    QSqlDatabase db = initBDD();
    db.close();
    QSqlDatabase::removeDatabase("../../../db.sqlite");
}
