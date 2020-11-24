#include "produit.h"
#include<QDebug>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QModelIndex>
#include <QVector>
Produit::Produit()
{

}
bool Produit::addproduit( )
{


QSqlQuery query;

query.prepare("insert into PRODUIT (ID_PRODUIT,NOM_PRODUIT,TYPE_PRODUIT,PRIX_PRODUIT,ID_TRAITEUR) "
              "values ( :id,:nom,:type,:prix,:idT)");

query.bindValue(":id",getIdprod());
query.bindValue(":nom",getNOMprod());
query.bindValue(":type",getTYPEprod());

query.bindValue(":prix",getPRIXprod());
query.bindValue(":idT",getIDTRAITPROD());
return query.exec();
}
bool Produit::update_P(QString identifiant ,QString nom ,QString type,QString prix,QString idtrait , int column)
{ QSqlQuery query;
    if (column==1)
              {

      query.prepare( "update PRODUIT set  NOM_PRODUIT= :nom where ID_PRODUIT=:id " );

              }
    else if (column==2)
    {
        query.prepare( "update PRODUIT set  TYPE_PRODUIT= :type where ID_PRODUIT=:id " );

    }
    else if (column==3)
    {
        query.prepare( "update PRODUIT set  PRIX_PRODUIT= :prix where ID_PRODUIT=:id " );

    }
    else if (column==4)
    {
        query.prepare( "update PRODUIT set  ID_TRAITEUR= :id_trait where ID_PRODUIT=:id" );

    }

    query.bindValue(":id",identifiant);
    query.bindValue(":nom",nom);
    query.bindValue(":type",type);
    query.bindValue(":prix",prix);
    query.bindValue(":id_trait",idtrait);
    query.exec();


    return query.exec();
}
QSqlQueryModel * Produit::afficher()
{
    QSqlQueryModel *model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM PRODUIT ");

return model;
}
bool Produit::DELETE(QString identifiant)
{ QSqlQuery query;
     query.prepare("Delete from PRODUIT where ID_PRODUIT=:id ");
     qDebug()<<"suprimer";
     query.bindValue(":id",identifiant);

     return query.exec();
}
