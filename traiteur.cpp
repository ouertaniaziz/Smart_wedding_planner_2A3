#include "traiteur.h"
#include "ui_traiteur.h"

#include<QDebug>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QModelIndex>
#include <QVector>
bool traiteur::addtraiteur( )
{


QSqlQuery query;

query.prepare("insert into TRAITEUR (ID_TRAIT,NOM_TRAIT,NUM_TRAIT,EMAIL_TRAIT,ADRESSE_TRAIT) "
              "values ( :id,:nom,:num,:email,:adresse)");

query.bindValue(":id",getIDTrait());
query.bindValue(":nom",getNomTrait());
query.bindValue(":num",getNumTrait());
query.bindValue(":email",getEmailTrait());
query.bindValue(":adresse",getAdressTrait());
return query.exec();
}
//update traiteur
bool traiteur::update_T(QString identifiant ,QString nom ,QString numero,QString email,QString adresse ,int column)
{ QSqlQuery query;
    if (column==1)
              {

      query.prepare( "update TRAITEUR set  NOM_TRAIT= :nom where ID_TRAIT=:id " );

              }
    else if (column==2)
    {
        query.prepare( "update TRAITEUR set  NUM_TRAIT= :num where ID_TRAIT=:id " );

    }
    else if (column==3)
    {
        query.prepare( "update TRAITEUR set  EMAIL_TRAIT= :email where ID_TRAIT=:id " );

    }
    else if (column==4)
    {
        query.prepare( "update TRAITEUR set  ADRESSE_TRAIT= :addres where ID_TRAIT=:id " );

    }
    query.bindValue(":id",identifiant);
    query.bindValue(":nom",nom);
    query.bindValue(":num",numero);
    query.bindValue(":email",email);
    query.bindValue(":addres",adresse);
    query.exec();


    return query.exec();
}
//afficher traiteur
QSqlQueryModel * traiteur ::afficher()
{
    QSqlQueryModel *model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM TRAITEUR ");

return model;
}
