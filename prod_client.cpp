#include "prod_client.h"
#include<QDebug>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QSqlQueryModel>
bool prod_client::addprod_client()
{
    QSqlQuery query;

    query.prepare("insert into CLIENT_PRODUIT (ID_CLIENT,ID_PRODUIT) "
                  "values ( :idc,:idp)");

    query.bindValue(":idp",getIdprod());
    query.bindValue(":idc",getIdclient());
    return  query.exec();
}


QSqlQuery* prod_client::afficher_client_pour_poduit()
{
    QSqlQuery* qry = new QSqlQuery();
    qry->prepare("SELECT * FROM CLIENT_MARRIAGE");
    qry->exec();
    return qry;
}
