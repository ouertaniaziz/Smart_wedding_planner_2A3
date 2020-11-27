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


bool invite::supprimer_invite(QString ID)
{
    QSqlQuery qry;
    qry.prepare("SELECT * FROM INVITE_MARRIAGE WHERE ID_INVITE =:id ");
    qry.bindValue(":id",ID);
    if (qry.exec())
    {
        int count(0);
        while(qry.next())
        {
            count++;
        }

        if (count == 1)
        {
            qry.prepare("Delete from INVITE_MARRIAGE WHERE ID_INVITE =:id ");
            qry.bindValue(":id",ID);
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
