#ifndef MUSICIENS_H
#define MUSICIENS_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class musiciens
{
    QString nom_mus, prenom_mus, genre_mus, email_mus;
    int prix_mus, id_mus;
public:
    musiciens(){};
    musiciens(int, QString, QString, int, QString, QString);
    QString getNom_mus()
    {
        return nom_mus;
    }
    QString getPrenom_mus()
    {
        return prenom_mus;
    }
    int getid_mus()
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
    int getprix_mus()
    {
        return prix_mus;
    }

    void setNom_mus(QString nm)
    {
        nom_mus = nm;
    }
    void setPrenom_mus(QString prm)
    {
        prenom_mus = prm;
    }
    void setid_mus(int idm)
    {
        this->id_mus = idm;
    }
    void setgenre_mus(QString gnm)
    {
        genre_mus = gnm;
    }
    void setemail_mus(QString emm)
    {
        email_mus = emm;
    }
    void setprix_mus(int prixm)
    {
        this->prix_mus = prixm;
    }
    bool ajouter_mus();
    QSqlQueryModel *afficher_mus(QString nom_mus,int id_mus, int index);
    bool supprimer_mus(int);
    bool modifier_mus(int, int, QString, QString, QString, QString, int);
    int affecter_mus(int);
    QString affecter_mus2(int);
    QString affecter_mus3(int);
    QString affecter_mus4(int);
    QString affecter_mus5(int);
    int affecter_mus6(int);
};

#endif // MUSICIENS_H
