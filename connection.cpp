#include "connection.h"
#include "mainwindow.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Zied_Projet2A");
db.setUserName("system");//inserer nom de l'utilisateur
db.setPassword("0000");//inserer mot de passe de cet utilisateur

//db.setDatabaseName("projet_2A");
//db.setUserName("aziz");//inserer nom de l'utilisateur
//db.setPassword("esprit18");//inserer mot de passe de cet utilisateur


if (db.open())
test=true;




    return  test;
}
