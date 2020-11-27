#ifndef INVITE_H
#define INVITE_H

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


class invite
{
private:
    QString id_invite,nom_invite,prenom_invite,phone_invite,email_invite,id_marriage;
public:
    invite();
    invite(QString,QString,QString,QString,QString,QString);


    QString get_id_inv(){return id_invite;}
    QString get_nom(){return nom_invite;}
    QString get_prenom(){return prenom_invite;}
    QString get_phone(){return phone_invite;}
    QString get_email(){return email_invite;}
    QString get_id_marriage(){return id_marriage;}

    void set_id_inv(QString nv_id){id_invite=nv_id;}


    bool add_guest();
    bool supprimer_invite(QString );
};

#endif // INVITE_H
