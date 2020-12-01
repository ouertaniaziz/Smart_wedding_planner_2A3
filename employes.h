#ifndef EMPLOYES_H
#define EMPLOYES_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class employes
{
    QString nom_emp, prenom_emp, num_emp, type_emp;
    int salaire_emp, id_emp;
public:
    employes(){};
    employes(int,QString, QString,int, QString,QString);
    QString getNom_emp()
    {
        return nom_emp;
    }
    QString getPrenom_emp()
    {
        return prenom_emp;
    }
    int getid_emp()
    {
        return id_emp;
    }
    QString getnum_emp()
    {
        return num_emp;
    }
    QString gettype_emp()
    {
        return type_emp;
    }
    int getsalaire_emp()
    {
        return salaire_emp;
    }

    void setNom_emp(QString nemp)
    {
        nom_emp = nemp;
    }
    void setPrenom_emp(QString premp)
    {
        prenom_emp = premp;
    }
    void settype_emp(QString typem)
    {
        type_emp = typem;
    }
    void setid_emp(int idemp)
    {
        this->id_emp = idemp;
    }
    void setnum_emp(QString numemp)
    {
        num_emp = numemp;
    }
    void setsalaire_emp(int salm)
    {
       this->salaire_emp = salm;
    }
    bool ajouter_emp();
    QSqlQueryModel *afficher_emp(QString nom_emp,int id_emp, int index);
    int affecter_emp(int);
    QString affecter_emp2(int);
    QString affecter_emp3(int);
    QString affecter_emp4(int);
    QString affecter_emp5(int);
    int affecter_emp6(int);
    bool modifier_emp(int, int, QString, QString, QString, QString, int);
    bool supprimer_emp(int);
    void gen_pdf();
};

#endif // EMPLOYES_H
