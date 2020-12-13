#ifndef DECORATOR_H
#define DECORATOR_H
#include <QString>
#include <QSqlQueryModel>


class Decorator
{

    QString id,name,type_decoration,price,number,nb_reservations,hall_id;

public:
    Decorator();
    Decorator(QString,QString,QString,QString,QString,QString,QString);

    bool addDecorator();
    bool deleteDecorator();
    bool updateDecorator();
    QSqlQueryModel* tableView();
    QSqlQuery statDecorator();





    QString getId(){ return id;}
    QString getNb_reservations() { return  nb_reservations; }
    QString getName() { return  name ; }
    QString getType_decoration() { return  type_decoration;}
    QString getHall_id() { return  hall_id ;}
    QString getNumber() {return  number  ;}
    QString getPrice() { return  price;}
};

#endif // DECORATOR_H
