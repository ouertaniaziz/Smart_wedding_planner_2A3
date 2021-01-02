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


QSqlQueryModel * prod_client::afficherpc(QString id,int nbr)
{
    QSqlQueryModel *model= new QSqlQueryModel();

//NOM_PRODUIT,PRIX_PRODUIT,PRIX_PRODUIT*37
        model->setQuery("SELECT CP.ID_PRODUIT,P.NOM_PRODUIT,P.PRIX_PRODUIT FROM CLIENT_PRODUIT CP , PRODUIT P WHERE  CP.ID_CLIENT= '"+id+"' AND P.ID_PRODUIT=CP.ID_PRODUIT    ");



return model;
}
QSqlQuery prod_client::imprimeretcalcule(QString id)

{
    QSqlQuery query;

       query.prepare("SELECT CP.ID_PRODUIT,P.NOM_PRODUIT,P.PRIX_PRODUIT FROM CLIENT_PRODUIT CP , PRODUIT P WHERE  CP.ID_CLIENT= '"+id+"' AND P.ID_PRODUIT=CP.ID_PRODUIT    ");
       query.exec();

       return query;
}
