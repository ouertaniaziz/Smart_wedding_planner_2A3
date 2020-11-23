#ifndef MUSICIENS_H
#define MUSICIENS_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

class musiciens
{
    QString nom_mus,prenom_mus,id_mus,genre_mus,email_mus;
    float prix_mus;
public:
    musiciens(){};
    musiciens(float,QString,QString,QString,QString,QString);
    QString getNom_mus()
    {
        return nom_mus;
    }
    QString getPrenom_mus()
    {
        return prenom_mus;
    }
    QString getid_mus()
    {
        return id_mus;
    }
    QString getgenre_mus()
    {
        return genre_mus;
    }
    QString getemail_mus()
    {
        return email_mus;
    }
    float getprix_mus()
    {
        return prix_mus;
    }
};

#endif // MUSICIENS_H
