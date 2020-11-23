#include "connection.h"

Connection::Connection()
{

}
bool Connection::createconnect()
{
    bool test=false;
    QSqlDatabase db =QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_Projet2A");
    db.setUserName("Sami");
    db.setPassword("0000");
    if (db.open())
        test=true;
    return test;
}
