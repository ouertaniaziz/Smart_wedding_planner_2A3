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

query.prepare("insert into PRODUIT (ID_PRODUIT,NOM_PRODUIT,PRIX_PRODUIT,ID_TRAITEUR) "
              "values ( :id,:nom,:prix,:idT)");

query.bindValue(":id",getIdprod());
query.bindValue(":nom",getNOMprod());
query.bindValue(":prix",getPRIXprod());
query.bindValue(":idT",getIDTRAITPROD());
return query.exec();
}
