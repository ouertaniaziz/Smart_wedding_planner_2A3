#ifndef CLIENT_MARRIAGE_H
#define CLIENT_MARRIAGE_H
#include <QString>
#include <iostream>
#include <sstream>
#include <QDebug>
#include <QtDebug>
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class client_marriage
{
private:
    QString nom_m,prenom_m,email,nom_f,prenom_f;
    QString budget,phone_m,phone_f,cin_m,cin_f,date;


public:
    client_marriage();
    client_marriage(QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString);

    // les accesseures

    QString get_nom_m(){return nom_m;}
    QString get_prenom_m(){return prenom_m;}
    QString get_cin_m(){return cin_m;}
    QString get_phone_m(){return phone_m;}

    QString get_nom_f(){return nom_f;}
    QString get_prenom_f(){return prenom_f;}
    QString get_cin_f(){return cin_f;}
    QString get_phone_f(){return phone_f;}

    QString get_email(){return email;}
    QString get_budget(){return budget;}

    QString get_date(){return date;}

    bool ajouter_client(int);
    bool supprimer_client(QString );
    bool update_client_info(QString);
    int unique_cin_search(QString );

    int count_id();
    int clear_table_marriage();
    QSqlQuery search_client_update(QString id);
    int check_id_client(QString id);
    void update_confirmation(QString id);
    QSqlQuery *order_by_name();
    QSqlQuery *order_by_email();
    QSqlQuery *order_by_confirmation();
};

#endif // CLIENT_MARRIAGE_H
