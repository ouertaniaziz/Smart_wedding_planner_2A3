#include "invite.h"

invite::invite()
{
    id_invite ="";
    nom_invite ="";
    prenom_invite ="";
    phone_invite ="";
    email_invite ="";
    id_marriage ="";
}

invite::invite(QString id_inv,QString nom,QString prenom ,QString phone ,QString email ,QString id_client)
{
    this->id_invite = id_inv;
    this->nom_invite = nom;
    this->prenom_invite = prenom;
    this->phone_invite = phone;
    this->email_invite = email;
    this->id_marriage = id_client;

}


bool invite::add_guest()
{
    QSqlQuery qry;
    qry.prepare("INSERT INTO INVITE_MARRIAGE (ID_INVITE,NOM_INVITE,PRENOM_INVITE,PHONE_INVITE,EMAIL_INVITE,ID_MARRIAGE) "
                "values ( :id_inv , :nom_inv , :prenom_inv , :phone_inv , :email_inv , :id_marriage)");

    qry.bindValue(":id_inv",id_invite);
    qry.bindValue(":nom_inv",nom_invite);
    qry.bindValue(":prenom_inv",prenom_invite);
    qry.bindValue(":phone_inv",phone_invite);

    qry.bindValue(":email_inv",email_invite);
    qry.bindValue(":id_marriage",id_marriage);


    return qry.exec();
}


bool invite::supprimer_invite(QString ID,QString id_client)
{
    QSqlQuery qry;
    qry.prepare("SELECT * FROM INVITE_MARRIAGE WHERE ID_INVITE =:id AND ID_MARRIAGE = :id_client ");
    qry.bindValue(":id",ID);
    qry.bindValue(":id_client",id_client);
    if (qry.exec())
    {
        int count=0;
        while(qry.next())
        {
            count++;
        }

        if (count == 1)
        {
            qry.prepare("Delete from INVITE_MARRIAGE WHERE ID_INVITE =:id AND ID_MARRIAGE = :id_client ");
            qry.bindValue(":id",ID);
            qry.bindValue(":id_client",id_client);
            QMessageBox::information(nullptr, QObject::tr("SUCESS"),
                                     QObject::tr("INVITE SUPPRIMER.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
            return qry.exec();
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                                  QObject::tr("INVITE doesn't exists.\n"
                                              "Click Cancel to try again."), QMessageBox::Cancel);

        }

    }
    return qry.exec();
}


bool invite::update_invite_info(QString ID,QString id_client)
{
    QSqlQuery qry;



    qry.prepare("UPDATE INVITE_MARRIAGE SET NOM_INVITE=:nom ,PRENOM_INVITE=:prenom,PHONE_INVITE=:phone ,EMAIL_INVITE = :email  WHERE ID_INVITE =:id AND ID_MARRIAGE = :id_client ");

    qry.bindValue(":nom",nom_invite);
    qry.bindValue(":prenom",prenom_invite);
    qry.bindValue(":phone",phone_invite);
    qry.bindValue(":email",email_invite);



    qry.bindValue(":id",ID);
    qry.bindValue(":id_client",id_client);


    return qry.exec();
}

int invite::clear_table_inv()
{
    QSqlQuery qry;
    qry.prepare("SELECT * FROM INVITE_MARRIAGE");
    int rowCount = 0;
    if (qry.exec())
    {

        while(qry.next())
        {
            rowCount++;
        }



    }
    return rowCount;
}

void invite::fix_id_after_delete(int id,QString id_client)
{
    QSqlQuery qry;

    qry.prepare("UPDATE INVITE_MARRIAGE SET ID_INVITE= :id_inv  WHERE ID_MARRIAGE = :id_client AND ID_INVITE > :id_inv");
    qry.bindValue(":id_inv",id);
    qry.bindValue(":id_client",id_client);
    if (qry.exec() )
    {
        while (qry.next())
        {
            id++;
        }
    }
}

int invite::count_id_inv(QString id_marriage)
{
    QSqlQuery qry;
    qry.prepare("SELECT * FROM INVITE_MARRIAGE WHERE ID_MARRIAGE= :id_m");
    qry.bindValue(":id_m",id_marriage);
    int count(0);
    if ( qry.exec())
    {

        while(qry.next())
        {
            count++;
        }
        count++;


    }
    return count;
}

int invite::invite_check_unique_phone(QString phone)
{

    QSqlQuery qry;
    qry.prepare("SELECT * FROM INVITE_MARRIAGE WHERE PHONE_INVITE= :phone");
    qry.bindValue(":phone",phone);
    int count(0);

    if ( qry.exec())
    {
        while(qry.next())
        {
            count++;
        }
    }
    return count;
}


QSqlQuery invite::search_inv_to_update(QString ID,QString id_client)
{
    QSqlQuery qry;

    qry.prepare("SELECT * FROM INVITE_MARRIAGE WHERE ID_INVITE =:id AND ID_MARRIAGE = :id_client");
    qry.bindValue(":id",ID);
    qry.bindValue(":id_client",id_client);

    if (qry.exec())
    {

        while(qry.next())
        {
            return qry;
        }

    }
}

int invite::search_inv_exist_to_update(QString ID,QString id_client)
{
    QSqlQuery qry;

    qry.prepare("SELECT * FROM INVITE_MARRIAGE WHERE ID_INVITE =:id AND ID_MARRIAGE = :id_client");
    qry.bindValue(":id",ID);
    qry.bindValue(":id_client",id_client);
    int count(0);
    if (qry.exec())
    {

        while(qry.next())
        {
            count++;
        }

    }
    return count;
}


QSqlQuery invite::search_inv_to_print(QString ID)
{
    QSqlQuery qry;
    qry.prepare("SELECT * FROM CLIENT_MARRIAGE WHERE ID_CLIENT=:id");
    qry.bindValue(":id",ID);

    if ( qry.exec())
    {
        while(qry.next())
        {
            return qry;
        }
    }
}
