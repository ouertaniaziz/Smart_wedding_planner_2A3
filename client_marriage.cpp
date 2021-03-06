#include "client_marriage.h"

client_marriage::client_marriage()
{
    nom_m = "";
    prenom_m = "";
    cin_m = "";
    phone_m = "";

    nom_f = "";
    prenom_f = "";
    cin_f = "";
    phone_f = "";

    budget = "";

    date="";

    email ="";
}

client_marriage::client_marriage(QString n_m,QString pr_m,QString c_m,QString ph_m,QString n_f,QString pr_f,QString c_f,QString ph_f,QString bg,QString d,QString em)
{
    nom_m = n_m;
    prenom_m = pr_m;
    cin_m = c_m;
    phone_m = ph_m;

    nom_f = n_f;
    prenom_f = pr_f;
    cin_f = c_f;
    phone_f = ph_f;

    budget = bg;

    date = d;
    email = em;
}

QSqlQuery* client_marriage::order_by_name()
{
    QSqlQuery* qry= new QSqlQuery();
    qry->prepare("SELECT * FROM CLIENT_MARRIAGE ORDER BY PRENOM_M ASC");
    qry->exec();
    return qry;
}

QSqlQuery* client_marriage::order_by_email()
{
    QSqlQuery* qry= new QSqlQuery();
    qry->prepare("SELECT * FROM CLIENT_MARRIAGE ORDER BY EMAIL ASC");
    qry->exec();
    return qry;
}

QSqlQuery* client_marriage::order_by_confirmation()
{
    QSqlQuery* qry= new QSqlQuery();
    qry->prepare("SELECT * FROM CLIENT_MARRIAGE ORDER BY CONFIRMATION DESC;");
    qry->exec();
    return qry;
}


bool client_marriage::ajouter_client(int ID_CLIENT)
{
    QString confirmation = "0";
    QString id_decorateur = "0";
    QString id_produit = "0";

    QSqlQuery qry;
    qry.prepare("INSERT INTO CLIENT_MARRIAGE (NOM_M,PRENOM_M,PHONE_M,CIN_M,NOM_F,PRENOM_F,PHONE_F,CIN_F,BUDGET,EMAIL,DATE_MARRIAGE,ID_CLIENT,CONFIRMATION,ID_DECORATEUR,ID_PRODUIT) "
                "values ( :nom_m, :prenom_m, :phone_m, :cin_m, :nom_f, :prenom_f, :phone_f, :cin_f, :budget, :email, :date, :id, :confirmation, :id_decorateur, :id_produit)");

    qry.bindValue(":nom_m",nom_m);
    qry.bindValue(":prenom_m",prenom_m);
    qry.bindValue(":phone_m",phone_m);
    qry.bindValue(":cin_m",cin_m);

    qry.bindValue(":nom_f",nom_f);
    qry.bindValue(":prenom_f",prenom_f);
    qry.bindValue(":phone_f",phone_f);
    qry.bindValue(":cin_f",cin_f);

    qry.bindValue(":budget",budget);
    qry.bindValue(":email",email);
    qry.bindValue(":date",date);


    qry.bindValue(":id",ID_CLIENT);
    qry.bindValue(":confirmation",confirmation);


    qry.bindValue(":id_decorateur",id_decorateur);
    qry.bindValue(":id_produit",id_produit);

    return qry.exec();
}

bool client_marriage::supprimer_client(QString ID)
{
    QSqlQuery qry;
    qry.prepare("SELECT * FROM CLIENT_MARRIAGE WHERE ID_CLIENT =:id ");
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
            qry.prepare("Delete from CLIENT_MARRIAGE WHERE ID_CLIENT =:id ");
            qry.bindValue(":id",ID);
            QMessageBox::information(nullptr, QObject::tr("SUCESS"),
                                     QObject::tr("Client Deleted.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
            return qry.exec();
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                                  QObject::tr("ID doesn't exists.\n"
                                              "Click Cancel to try again."), QMessageBox::Cancel);

        }

    }
    return qry.exec();

}

bool client_marriage::update_client_info(QString ID)
{
    QSqlQuery qry;



    qry.prepare("UPDATE CLIENT_MARRIAGE SET NOM_M=:nom_m ,PRENOM_M=:prenom_m,PHONE_M=:phone_m,CIN_M = :cin_m,NOM_F=:nom_f,PRENOM_F=:prenom_f,PHONE_F=:phone_f,CIN_F=:cin_f,BUDGET=:budget,EMAIL=:email, DATE_MARRIAGE=:date WHERE ID_CLIENT =:id");

    qry.bindValue(":nom_m",nom_m);
    qry.bindValue(":prenom_m",prenom_m);
    qry.bindValue(":phone_m",phone_m);
    qry.bindValue(":cin_m",cin_m);

    qry.bindValue(":nom_f",nom_f);
    qry.bindValue(":prenom_f",prenom_f);
    qry.bindValue(":phone_f",phone_f);
    qry.bindValue(":cin_f",cin_f);

    qry.bindValue(":budget",budget);
    qry.bindValue(":email",email);
    qry.bindValue(":date",date);

    qry.bindValue(":id",ID);

    return qry.exec();
}


int client_marriage::unique_cin_search(QString cinn)
{
    QSqlQuery qry;
    qry.prepare("SELECT * FROM CLIENT_MARRIAGE WHERE CIN_M =:cin");
    qry.bindValue(":cin",cinn);
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


int client_marriage::count_id()
{
    QSqlQuery qry;
    int count1=0;
    if (qry.exec("SELECT * FROM CLIENT_MARRIAGE"))
    {

        while(qry.next())
        {
            count1++;
        }

    }
    count1+=1;

    return count1;
}


int client_marriage::clear_table_marriage()
{
    QSqlQuery qry;
    int rowCount = 0;
    if (qry.exec("SELECT * FROM CLIENT_MARRIAGE"))
    {
        while(qry.next())
        {
            rowCount++;
        }
    }
    return rowCount;
}

QSqlQuery client_marriage::search_client_update(QString id)
{
    QSqlQuery qry;
    qry.prepare("SELECT * FROM CLIENT_MARRIAGE WHERE ID_CLIENT =:id ");
    qry.bindValue(":id",id);

    if (qry.exec())
    {


        while(qry.next())
        {
            return qry;
        }
    }
}


int client_marriage::check_id_client(QString id)
{
    QSqlQuery qry;
    qry.prepare("SELECT * FROM CLIENT_MARRIAGE WHERE ID_CLIENT =:id ");
    qry.bindValue(":id",id);
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

void client_marriage::update_confirmation(QString id)
{
    QSqlQuery qry;
    qry.prepare("UPDATE CLIENT_MARRIAGE SET CONFIRMATION=:conf WHERE ID_CLIENT =:id");
    qry.bindValue(":conf","1");
    qry.bindValue(":id",id);

    qry.exec();
}
