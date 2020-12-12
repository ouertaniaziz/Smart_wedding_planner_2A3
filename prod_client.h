#ifndef PROD_CLIENT_H
#define PROD_CLIENT_H
#include<QString>
#include<QDate>
#include<QSqlQueryModel>

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
};

#endif // PROD_CLIENT_H
