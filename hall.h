#ifndef HALL_H
#define HALL_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>




class Hall
{
    //int id,nb_reservations,number,nb_places;
    QString name,address,email,id,nb_reservations,number,nb_places,price;


public:
    Hall();
    Hall(QString,QString,QString,QString,QString,QString,QString,QString);

    bool addHall();
    bool deleteHall();
    bool updateHall();
    QSqlQueryModel* tableView();
    QSqlQuery statHall();

    QString getId(){ return id;}
    QString getNb_reservations() { return  nb_reservations; }
    QString getName() { return  name ; }
    QString getAddress() { return  address;}
    QString getEmail() { return  email ;}
    QString getNumber() {return  number  ;}
    QString getPrice() { return  price;}
    QString getNb_places() { return  nb_places ;}

};

#endif // HALL_H
