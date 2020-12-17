#include "musiciens.h"
#include <string>
#include <iostream>
musiciens::musiciens(int prix_mus, QString nom_mus, QString prenom_mus, int id_mus, QString genre_mus, QString email_mus)
{
    this->id_mus = id_mus;
    this->nom_mus = nom_mus;
    this->prenom_mus = prenom_mus;
    this->genre_mus = genre_mus;
    this->email_mus = email_mus;
    this->prix_mus = prix_mus;
}
bool musiciens::ajouter_mus()
{

    QSqlQuery query;
    QString res1 = QString::number(id_mus);
    QString res = QString::number(prix_mus);
    query.prepare("INSERT INTO MUSICIENS(PRIX_MUS,ID_MUS,NOM_MUS,PRENOM_MUS,GENRE_MUS,EMAIL_MUS) VALUES(:prix_mus,:id_mus,:nom_mus,:prenom_mus,:genre_mus,:email_mus);");

    query.bindValue(":prix_mus", res);
    query.bindValue(":id_mus", res1);
    query.bindValue(":nom_mus", nom_mus);
    query.bindValue(":prenom_mus", prenom_mus);
    query.bindValue(":genre_mus", genre_mus);
    query.bindValue(":email_mus", email_mus);

    return query.exec();
}
bool musiciens::supprimer_mus(int id_mus)
{
    QSqlQuery query;
    QString res1 = QString::number(id_mus);
    query.prepare("DELETE FROM MUSICIENS WHERE ID_MUS= :id_mus");
    query.bindValue(":id_mus", res1);
    return query.exec();
}
QSqlQueryModel *musiciens::afficher_mus(QString nom_mus,int id_mus, int index)
{
    QSqlQuery query;
    QString res1 = QString::number(id_mus);
   // query.prepare("SELECT * FROM MUSICIENS WHERE NOM_MUS= :nom_mus");
    //query.bindValue(":nom_mus",nom_mus);
    QSqlQueryModel *model = new QSqlQueryModel();
    if(index==-1)
     {
    if(nom_mus=="XYZ" && id_mus==-1)
    {
     model->setQuery("SELECT * FROM MUSICIENS");
    }
    else if(nom_mus!="XYZ" && id_mus==-1)
       {
        query.prepare("SELECT * FROM MUSICIENS WHERE NOM_MUS= :nom_mus");
        query.bindValue(":nom_mus",nom_mus);
        query.exec();
        model->setQuery(query);
       }
    else if(nom_mus=="XYZ" && id_mus !=-1)
    {
        query.prepare("SELECT * FROM MUSICIENS WHERE ID_MUS= :id_mus");
        query.bindValue(":id_mus",res1);
        query.exec();
        model->setQuery(query);
    }
    else if(nom_mus!="XYZ" && id_mus!=-1)
    {
        query.prepare("SELECT * FROM MUSICIENS WHERE ID_MUS= :id_mus AND NOM_MUS= :nom_mus");
        query.bindValue(":nom_mus",nom_mus);
        query.bindValue(":id_mus",res1);
        query.exec();
        model->setQuery(query);
    }
    }
    else
    {
        switch (index)
        {
        case 1:
            query.prepare("SELECT * FROM MUSICIENS ORDER BY ID_MUS");
            query.exec();
            model->setQuery(query);
            break;
         case 2:
            query.prepare("SELECT * FROM MUSICIENS ORDER BY PRIX_MUS");
            query.exec();
            model->setQuery(query);
            break;
          case 3:
            query.prepare("SELECT * FROM MUSICIENS ORDER BY GENRE_MUS");
            query.exec();
            model->setQuery(query);
        break;
        }
    }
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Last Name"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Genre"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Price"));
    return model;
}
int musiciens::affecter_mus(int id_mus)
{
    int id_mod = 0;
    QSqlQuery query;
    QString res1 = QString::number(id_mus);
    query.prepare("Select * from MUSICIENS where ID_MUS= :id_mus");
    query.bindValue(":id_mus", res1);
    if (query.exec())
    {
        while (query.next())
        {
            id_mod = query.value(0).toInt();
        }
    }
    return id_mod;
}
QString musiciens::affecter_mus2(int id_mus)
{
    QString fn_mod;
    QSqlQuery query;
    QString res1 = QString::number(id_mus);
    query.prepare("Select * from MUSICIENS where ID_MUS= :id_mus");
    query.bindValue(":id_mus", res1);
    if (query.exec())
    {
        while (query.next())
        {
            fn_mod = query.value(1).toString();
        }
    }
    return fn_mod;
}
QString musiciens::affecter_mus3(int id_mus)
{
    QString ln_mod;
    QSqlQuery query;
    QString res1 = QString::number(id_mus);
    query.prepare("Select * from MUSICIENS where ID_MUS= :id_mus");
    query.bindValue(":id_mus", res1);
    if (query.exec())
    {
        while (query.next())
        {
            ln_mod = query.value(2).toString();
        }
    }
    return ln_mod;
}

QString musiciens::affecter_mus4(int id_mus)
{
    QString gm_mod;
    QSqlQuery query;
    QString res1 = QString::number(id_mus);
    query.prepare("Select * from MUSICIENS where ID_MUS= :id_mus");
    query.bindValue(":id_mus", res1);
    if (query.exec())
    {
        while (query.next())
        {
            gm_mod = query.value(3).toString();
        }
    }
    return gm_mod;
}
QString musiciens::affecter_mus5(int id_mus)
{
    QString em_mod;
    QSqlQuery query;
    QString res1 = QString::number(id_mus);
    query.prepare("Select * from MUSICIENS where ID_MUS= :id_mus");
    query.bindValue(":id_mus", res1);
    if (query.exec())
    {
        while (query.next())
        {
            em_mod = query.value(4).toString();
        }
    }
    return em_mod;
}
int musiciens::affecter_mus6(int id_mus)
{
    int pr_mod = 0;
    QSqlQuery query;
    QString res1 = QString::number(id_mus);
    query.prepare("Select * from MUSICIENS where ID_MUS= :id_mus");
    query.bindValue(":id_mus", res1);
    if (query.exec())
    {
        while (query.next())
        {
            pr_mod = query.value(5).toInt();
        }
    }
    return pr_mod;
}
bool musiciens::modifier_mus(int id_mus1, int id_mus, QString nom_mus, QString prenom_mus, QString genre_mus, QString email_mus, int prix_mus)
{
    QSqlQuery query;
    QString res2 = QString::number(id_mus1);
    QString res1 = QString::number(id_mus);
    QString res = QString::number(prix_mus);
    query.prepare("UPDATE MUSICIENS SET ID_MUS= :id_mus, NOM_MUS= :nom_mus, PRENOM_MUS= :prenom_mus, GENRE_MUS= :genre_mus ,EMAIL_MUS= :email_mus, PRIX_MUS= :prix_mus WHERE ID_MUS= :id_mus1");
    query.bindValue(":prix_mus", res);
    query.bindValue(":id_mus", res1);
    query.bindValue(":id_mus1", res2);
    query.bindValue(":nom_mus", nom_mus);
    query.bindValue(":prenom_mus", prenom_mus);
    query.bindValue(":genre_mus", genre_mus);
    query.bindValue(":email_mus", email_mus);
    return query.exec();
}
