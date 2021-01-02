#ifndef PROD_CLIENT_H
#define PROD_CLIENT_H
#include<QString>
#include<QDate>
#include<QSqlQueryModel>
#include "connection.h"

class prod_client
{
    QString Id_Prod;
    QString Id_client;

public:
    QString getIdprod(){return Id_Prod;}
    QString getIdclient(){return Id_client;}
    void setIDprod(QString id){Id_Prod=id;}
    void setIDclient(QString idC){Id_client=idC;}

    bool addprod_client();
    QSqlQuery *afficher_client_pour_poduit();
    QSqlQueryModel * afficherpc(QString,int);
   QSqlQuery imprimeretcalcule(QString id);
};

#endif // PROD_CLIENT_H
