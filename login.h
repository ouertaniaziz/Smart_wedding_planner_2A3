#ifndef LOGIN_H
#define LOGIN_H
#include<QtSql>
#include<QDebug>
#include<QFileInfo>
class login
{
public:
    QSqlDatabase db;
    login();
    bool creatLogin();
private:

};

#endif // LOGIN_H
