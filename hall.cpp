#include "hall.h"

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>
#include <QMessageBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlQuery>

Hall::Hall()
{


}

Hall::Hall(QString id,QString nb_reservations,QString name ,QString address ,QString email,QString number ,QString price,QString nb_places)
{

    this->id=id;
    this->nb_reservations=nb_reservations;
    this->name=name;
    this->address=address;
    this->email=email;
    this->number=number;
    this->price=price;
    this->nb_places=nb_places;

}


bool Hall::addHall()
{
 QSqlQuery query;

 QSqlQuery qry;

         if (qry.exec("SELECT * FROM SALLE WHERE ID =  '"+ id +"' "))
         {
             int count(0);
             while(qry.next())
             {
                 count++;
             }
             if (count == 0)
             {

                 query.prepare("INSERT INTO SALLE (ID,NB_RESERVATIONS,NOM,ADRESSE,EMAIL,NUMERO,PRIX,NB_PLACES) values (:ID,:NB_RESERVATIONS,:NOM,:ADRESSE,:EMAIL,:NUMERO,:PRIX,:NB_PLACES)");
                 query.bindValue(":ID",id);
                 query.bindValue(":NB_RESERVATIONS",nb_reservations);
                 query.bindValue(":NOM",name);
                 query.bindValue(":ADRESSE",address);
                 query.bindValue(":EMAIL",email);
                 query.bindValue(":NUMERO",number);
                 query.bindValue(":PRIX",price);
                 query.bindValue(":NB_PLACES",nb_places);

                 QMessageBox::information(nullptr, QObject::tr("add to data base"),
                                       QObject::tr("Hall added \n"
                                                   "Click Cancel to try again."), QMessageBox::Cancel);

                 return  query.exec() ;

             }
             else
             {
                 QMessageBox::critical(nullptr, QObject::tr("add to data base"),
                                       QObject::tr("Phone number already exists.\n"
                                                   "Click Cancel to try again."), QMessageBox::Cancel);
             }

         }

         if (!qry.exec())
         {
             qDebug("error adding to db");
         }



         return  false ;
}


bool Hall::deleteHall()
{
    QSqlQuery qry;

           if (qry.exec("SELECT * FROM SALLE WHERE ID ='"+ id +"' "))
           {
               int count(0);
               while(qry.next())
               {
                   count++;
               }
               if (count == 1)
               {
                   qry.prepare("Delete from SALLE WHERE ID ='"+ id +"' ");
                   QMessageBox::information(nullptr, QObject::tr("edit to data base"),
                                            QObject::tr("HALL Deleted.\n"
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
               qDebug("error  db");
           }


           return  false ;


}

bool Hall::updateHall()
{

    QSqlQuery qry;

            if (qry.exec("SELECT * FROM SALLE WHERE ID ='"+ id +"' "))
            {
                int count(0);
                while(qry.next())
                {
                    count++;
                }
                if (count == 1)
                {

                    qry.prepare("UPDATE SALLE SET ADRESSE='"+ address +"',NOM = '"+ name +"',EMAIL='"+ email +"',NUMERO='"+ number +"',PRIX='"+ price +"',NB_PLACES='"+ nb_places +"' WHERE ID ='"+ id +"' ");
                    qry.bindValue(":ADRESSE",address);
                    qry.bindValue(":NOM",name);
                    qry.bindValue(":EMAIL",email);
                    qry.bindValue(":NUMERO",number);
                    qry.bindValue(":PRIX",price);
                    qry.bindValue(":NB_PLACES",nb_places);


                    QMessageBox::information(nullptr, QObject::tr("edit to data base"),
                                          QObject::tr("HALL Updated.\n"
                                                      "Click Cancel to exit."), QMessageBox::Cancel);

                    return  qry.exec() ;
                }
                else
                {
                    QMessageBox::critical(nullptr, QObject::tr("edit to data base"),
                                          QObject::tr("HALL NUMBER doesn't exist.\n"
                                                      "Click Cancel to try again."), QMessageBox::Cancel);
                }

            }

            if (!qry.exec())
            {
                qDebug("error updating to db");
            }


            return false;
}

QSqlQueryModel* Hall::tableView()
{
    QSqlQueryModel* modal=new QSqlQueryModel();
       QSqlQuery* qry=new QSqlQuery();

    if(id=="")
    {
        qry->prepare("SELECT * FROM SALLE");
        qry->exec();
    }
    else
    {
        qry->prepare("SELECT * FROM SALLE WHERE ID='"+ id +"' OR PRIX ='"+ id +"' OR NB_PLACES='"+ id +"'");
        qry->exec();
    }


    modal->setQuery(*qry);

       return  modal;
}

QSqlQuery Hall::statHall()
{
    QSqlQuery query;
    query.prepare("select * from SALLE");
    query.exec();
    return query;

}
