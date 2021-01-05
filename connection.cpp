#include "connection.h"
#include "mainwindow.h"
#include <QtDebug>

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Projet_2A");
      db.setUserName("aziz");//inserer nom de l'utilisateur
      db.setPassword("esprit18");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;




    return  test;
}
