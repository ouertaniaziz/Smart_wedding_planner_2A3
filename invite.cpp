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
       ///////////////////// ajout du code d'invite
       /// INVITE_ARDUINO


    qry.prepare("SELECT * FROM INVITE_ARDUINO WHERE ID_MARRIAGE =:id AND ID_INVITE=(SELECT MAX(ID_INVITE) FROM INVITE_ARDUINO)");
    //qry.prepare("SELECT * FROM INVITE_ARDUINO WHERE ID_MARRIAGE =:id ORDER BY ID_INVITE DESC LIMIT 1");
    qry.bindValue(":id",id_marriage);
    int code_1 = 0;
    QString code_2,code = "1A";
    int change_lettre = 0;
    if ( qry.exec() )
    {
        while ( qry.next())
        {
            QString temp = qry.value(1).toString();
            qDebug() << "code aman : "<<temp << endl;
            if ( temp[0] == "1")
            {
                code_1 = 2;
            }
            else if ( temp[0] == "2")
            {
                code_1 = 3;
            }
            else if ( temp[0] == "3")
            {
                code_1 = 4;
            }
            else if ( temp[0] == "4")
            {
                code_1 = 5;
            }
            else if ( temp[0] == "5")
            {
                code_1 = 6;
            }
            else if ( temp[0] == "6")
            {
                code_1 = 7;
            }
            else if ( temp[0] == "7")
            {
                code_1 = 8;
            }
            else if ( temp[0] == "8")
            {
                code_1 = 9;
            }
            else if ( temp[0] == "9")
            {
                code_1 = 1;
                change_lettre = 1;
            }
            else
            {
            }


            if ( temp[1] == "A" && change_lettre == 1)
            {
                code_2 = "B";
                change_lettre = 0;
            }
            else if ( temp[1] == "B" && change_lettre == 1)
            {
                code_2 = "C";
                change_lettre = 0;
            }
            else if ( temp[1] == "C" && change_lettre == 1)
            {
                code_2 = "D";
                change_lettre = 0;
            }
            else if ( temp[1] == "D" && change_lettre == 1)
            {
                code_2 = "E";
                change_lettre = 0;
            }
            else if ( temp[1] == "E" && change_lettre == 1)
            {
                code_2 = "F";
                change_lettre = 0;
            }
            else if ( temp[1] == "F" && change_lettre == 1)
            {
                code_2 = "H";
                change_lettre = 0;
            }
            else if ( temp[1] == "H" && change_lettre == 1)
            {
                code_2 = "L";
                change_lettre = 0;
            }
            else if ( temp[1] == "L" && change_lettre == 1)
            {
                code_2 = "P";
                change_lettre = 0;
            }
            else if ( temp[1] == "P" && change_lettre == 1)
            {
                code_2 = "Q";
                change_lettre = 0;
            }
            else if ( temp[1] == "Q" && change_lettre == 1)
            {
                code_2 = "A";
                change_lettre = 0;
            }
            else
            {
            }

            QString tmp = QString::number(code_1);
            code = tmp + temp[1];
        }

    }


    qDebug() << "code initialise baseeee " << code << endl;


    qry.prepare("INSERT INTO INVITE_ARDUINO (ID_INVITE,CODE,ID_MARRIAGE) "
                "values ( :id_inv , :code , :id_marriage)");
    QString id_inv = id_invite;
    id_invite = id_marriage + id_invite;
    qDebug() << "hedha l id mtaa invite mkhalet " << id_invite << endl;
    //int id_inv_int = id_invite.toInt();
    qry.bindValue(":id_inv",id_invite);
    qry.bindValue(":code",code);
    qry.bindValue(":id_marriage",id_marriage);
    qry.exec();



    /////////////// ajout d'invite

    id_invite = id_inv;
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
