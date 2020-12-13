#include "decorator.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>

#include <QMessageBox>


Decorator::Decorator()
{

}
Decorator::Decorator(QString id,QString name ,QString type_decoration ,QString price ,QString number, QString nb_reservations,QString hall_id )
{

    this->id=id;
    this->nb_reservations=nb_reservations;
    this->name=name;
    this->type_decoration=type_decoration;
    this->number=number;
    this->price=price;
    this->hall_id=hall_id;

}

bool Decorator::addDecorator()
{
    QSqlQuery query;
    QSqlQuery qry2;
    QSqlQuery qry3;
    int countS(0);


    if (qry2.exec("SELECT * FROM SALLE WHERE ID =  '"+ hall_id +"' "))
    {
        while(qry2.next())
        {
            countS++;
        }

    }

    if (!qry2.exec())
    {
        qDebug("error reading from db");
    }


    if(countS==1)
    {



        if (qry3.exec("SELECT * FROM DECORATEUR WHERE ID =  '"+ id +"' "))
                {

                    int count(0);
                    while(qry3.next())
                    {
                        count++;
                    }
                    if (count == 0)
                    {

                        query.prepare("INSERT INTO DECORATEUR (ID,NB_RESERVATIONS,NOM,NUMERO,PRIX,TYPE_DECORATION,ID_SALLE) values (:ID,:NB_RESERVATIONS,:NOM,:NUMERO,:PRIX,:TYPE_DECORATION,:ID_SALLE)");
                        query.bindValue(":ID",id);
                        query.bindValue(":NB_RESERVATIONS",nb_reservations);
                        query.bindValue(":NOM",name);
                        query.bindValue(":NUMERO",number);
                        query.bindValue(":PRIX",price);
                        query.bindValue(":TYPE_DECORATION",type_decoration);
                        query.bindValue(":ID_SALLE",hall_id);

                        return  query.exec() ;

                     }
                    else
                    {
                        QMessageBox::critical(nullptr, QObject::tr("add to data base"),
                                              QObject::tr("Phone number already exists.\n"
                                                          "Click Cancel to try again."), QMessageBox::Cancel);
                    }

                }

                if (!qry3.exec())
                {
                    qDebug("error adding to db");
                }



    }

    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Data base"),
                              QObject::tr("This hall doesn't exist.\n"
                                          "Click Cancel to try again."), QMessageBox::Cancel);

    }


    return  false ;

}

bool Decorator::deleteDecorator()
{

    QSqlQuery qry;

           if (qry.exec("SELECT * FROM DECORATEUR WHERE ID ='"+ id +"' "))
           {


               int count(0);
               while(qry.next())
               {
                   count++;
               }
               if (count == 1)
               {
                   qry.prepare("Delete from DECORATEUR WHERE ID ='"+ id +"' ");
                   QMessageBox::information(nullptr, QObject::tr("edit to data base"),
                                            QObject::tr("DECORATOR Deleted.\n"
                                                        "Click Cancel to exit."), QMessageBox::Cancel);

                   return  qry.exec() ;


               }
               else
               {
                   QMessageBox::critical(nullptr, QObject::tr("edit to data base"),
                                         QObject::tr("PHONE NUMBER doesn't exist.\n"
                                                     "Click Cancel to try again."), QMessageBox::Cancel);
               }

           }

           if (!qry.exec())
           {
               qDebug("error reading to db");
           }

           return  false ;

}

bool Decorator::updateDecorator()
{
    QSqlQuery qry2;
    QSqlQuery qry3;
    int countS(0);


    if (qry2.exec("SELECT * FROM SALLE WHERE ID =  '"+ hall_id +"' "))
    {
        while(qry2.next())
        {
            countS++;
        }

    }

    if (!qry2.exec())
    {
        qDebug("error reading from db");
    }


    if(countS==1)
    {

        if (qry3.exec("SELECT * FROM DECORATEUR WHERE ID =  '"+ id +"' "))
                {
                    int count(0);
                    while(qry3.next())
                    {
                        count++;
                    }
                    if (count == 1)
                    {
                        qry3.prepare("UPDATE DECORATEUR SET NOM='"+ name+"',NUMERO = '"+ number +"',PRIX='"+ price +"',TYPE_DECORATION='"+ type_decoration +"',ID_SALLE='"+ hall_id +"' WHERE ID ='"+ id +"' ");
                        qry3.bindValue(":NOM",name);
                        qry3.bindValue(":NUMERO",number);
                        qry3.bindValue(":PRIX",price);
                        qry3.bindValue(":TYPE_DECORATION",type_decoration);
                        qry3.bindValue(":ID_SALLE",hall_id);


                        QMessageBox::information(nullptr, QObject::tr("edit to data base"),
                                              QObject::tr("DECORATOR Updated.\n"
                                                          "Click Cancel to exit."), QMessageBox::Cancel);

                        return qry3.exec();
                    }
                    else
                    {
                        QMessageBox::critical(nullptr, QObject::tr("add to data base"),
                                              QObject::tr("DECORATOR  doesn't exist.\n"
                                                          "Click Cancel to try again."), QMessageBox::Cancel);
                    }

                }

                if (!qry3.exec())
                {
                    qDebug("error adding to db");
                }



    }

    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Data base"),
                              QObject::tr("This hall doesn't exist.\n"
                                          "Click Cancel to try again."), QMessageBox::Cancel);

    }


    return false ;

}


QSqlQueryModel* Decorator::tableView()
{


    QSqlQueryModel* modal2=new QSqlQueryModel();
       QSqlQuery* qry2=new QSqlQuery();

       if(id=="")
       {
           qry2->prepare("SELECT * FROM DECORATEUR ");
           qry2->exec();
       }
       else
       {
           qry2->prepare("SELECT * FROM DECORATEUR WHERE ID = '"+ id +"' OR ID_SALLE = '"+ id +"' OR PRIX = '"+ id +"' ");
           qry2->exec();
       }



       modal2->setQuery(*qry2);

       return  modal2;

}

QSqlQuery Decorator::statDecorator()
{
    QSqlQuery query;
    query.prepare("select * from DECORATEUR");
    query.exec();
    return query;

}
