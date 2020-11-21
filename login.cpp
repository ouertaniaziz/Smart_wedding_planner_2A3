#include "login.h"

login::login()
{

}
bool login::creatLogin()
{
    bool test=false;
    db =QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("projet_2A");
    db.setUserName("aziz");
    db.setPassword("esprit18");
    if (db.open())
    test=true;
    return test;

}
