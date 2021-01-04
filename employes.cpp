#include "employes.h"
#include <QPdfWriter>
#include <QPainter>
#include <QDesktopServices>
#include <QUrl>
#include <QMessageBox>
#include <QPageSize>
#include <QFont>
employes::employes(int id_emp, QString nom_emp,QString prenom_emp, int salaire_emp,QString num_emp,QString type_emp )
{
    this->id_emp = id_emp;
    this->nom_emp = nom_emp;
    this->prenom_emp = prenom_emp;
    this->salaire_emp = salaire_emp;
    this->num_emp = num_emp;
    this->type_emp = type_emp;
}
bool employes::ajouter_emp()
{
    QSqlQuery query;
    QString res1 = QString::number(id_emp);
    QString res = QString::number(salaire_emp);
    query.prepare("INSERT INTO EMPLOYES(ID_EMP,NOM_EMP,PRENOM_EMP,SALAIRE_EMP,NUM_EMP,TYPE_EMP) VALUES(:id_emp,:nom_emp,:prenom_emp,:salaire_emp,:num_emp,:type_emp);");

    query.bindValue(":salaire_emp", res);
    query.bindValue(":id_emp", res1);
    query.bindValue(":nom_emp", nom_emp);
    query.bindValue(":prenom_emp", prenom_emp);
    query.bindValue(":num_emp", num_emp);
    query.bindValue(":type_emp", type_emp);

    return query.exec();
}
QSqlQueryModel *employes::afficher_emp(QString nom_emp,int id_emp, int index)
{
    QSqlQuery query;
    QString res1 = QString::number(id_emp);
    QString res = QString::number(salaire_emp);
    QSqlQueryModel *model1 = new QSqlQueryModel();
    if(index==-1)
         {
        if(nom_emp=="XYZ" && id_emp==-1)
        {
         model1->setQuery("SELECT * FROM EMPLOYES");
        }
        else if(nom_emp!="XYZ" && id_emp==-1)
           {
            query.prepare("SELECT * FROM EMPLOYES WHERE NOM_EMP= :nom_emp");
            query.bindValue(":nom_emp",nom_emp);
            query.exec();
            model1->setQuery(query);
           }
        else if(nom_emp=="XYZ" && id_emp !=-1)
        {
            query.prepare("SELECT * FROM EMPLOYES WHERE ID_EMP= :id_emp");
            query.bindValue(":id_emp",res1);
            query.exec();
            model1->setQuery(query);
        }
        else if(nom_emp!="XYZ" && id_emp!=-1)
        {
            query.prepare("SELECT * FROM EMPLOYES WHERE ID_EMP= :id_emp AND NOM_EMP= :nom_emp");
            query.bindValue(":nom_emp",nom_emp);
            query.bindValue(":id_emp",res1);
            query.exec();
            model1->setQuery(query);
        }
        }
        else
        {
            switch (index)
            {
            case 1:
                query.prepare("SELECT * FROM EMPLOYES ORDER BY ID_EMP");
                query.exec();
                model1->setQuery(query);
                break;
             case 2:
                query.prepare("SELECT * FROM EMPLOYES ORDER BY SALAIRE_EMP");
                query.exec();
                model1->setQuery(query);
                break;
              case 3:
                query.prepare("SELECT * FROM EMPLOYES ORDER BY NOM_EMP");
                query.exec();
                model1->setQuery(query);
            break;
            }
        }
        model1->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model1->setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));
        model1->setHeaderData(2, Qt::Horizontal, QObject::tr("Last Name"));
        model1->setHeaderData(3, Qt::Horizontal, QObject::tr("SALARY"));
        model1->setHeaderData(4, Qt::Horizontal, QObject::tr("NUMBER"));
        model1->setHeaderData(5, Qt::Horizontal, QObject::tr("TYPE"));
        return model1;
    }
int employes::affecter_emp(int id_emp)
{
    int id_mod = 0;
    QSqlQuery query;
    QString res1 = QString::number(id_emp);
    query.prepare("Select * from EMPLOYES where ID_EMP= :id_emp");
    query.bindValue(":id_emp", res1);
    if (query.exec())
    {
        while (query.next())
        {
            id_mod = query.value(0).toInt();
        }
    }
    return id_mod;
}
QString employes::affecter_emp2(int id_emp)
{
    QString fn_mod;
    QSqlQuery query;
    QString res1 = QString::number(id_emp);
    query.prepare("Select * from EMPLOYES where ID_EMP= :id_emp");
    query.bindValue(":id_emp", res1);
    if (query.exec())
    {
        while (query.next())
        {
            fn_mod = query.value(1).toString();
        }
    }
    return fn_mod;
}
QString employes::affecter_emp3(int id_emp)
{
    QString ln_mod;
    QSqlQuery query;
    QString res1 = QString::number(id_emp);
    query.prepare("Select * from EMPLOYES where ID_EMP= :id_emp");
    query.bindValue(":id_emp", res1);
    if (query.exec())
    {
        while (query.next())
        {
            ln_mod = query.value(2).toString();
        }
    }
    return ln_mod;
}
int employes::affecter_emp6(int id_emp)
{
    int sal_mod = 0;
    QSqlQuery query;
    QString res1 = QString::number(id_emp);
    query.prepare("Select * from EMPLOYES where ID_EMP= :id_emp");
    query.bindValue(":id_emp", res1);
    if (query.exec())
    {
        while (query.next())
        {
            sal_mod = query.value(3).toInt();
        }
    }
    return sal_mod;
}
QString employes::affecter_emp4(int id_emp)
{
    QString num_mod;
    QSqlQuery query;
    QString res1 = QString::number(id_emp);
    query.prepare("Select * from EMPLOYES where ID_EMP= :id_emp");
    query.bindValue(":id_emp", res1);
    if (query.exec())
    {
        while (query.next())
        {
            num_mod = query.value(4).toString();
        }
    }
    return num_mod;
}
QString employes::affecter_emp5(int id_emp)
{
    QString type_mod;
    QSqlQuery query;
    QString res1 = QString::number(id_emp);
    query.prepare("Select * from EMPLOYES where ID_EMP= :id_emp");
    query.bindValue(":id_emp", res1);
    if (query.exec())
    {
        while (query.next())
        {
            type_mod = query.value(5).toString();
        }
    }
    return type_mod;
}
bool employes::modifier_emp(int id_emp1, int id_emp, QString nom_emp, QString prenom_emp, QString num_emp, QString type_emp, int salaire_emp)
{
    QSqlQuery query;
    QString res2 = QString::number(id_emp1);
    QString res1 = QString::number(id_emp);
    QString res = QString::number(salaire_emp);
    query.prepare("UPDATE EMPLOYES SET ID_EMP= :id_emp, NOM_EMP= :nom_emp, PRENOM_EMP= :prenom_emp, SALAIRE_EMP= :salaire_emp ,NUM_EMP= :num_emp, TYPE_EMP= :type_emp WHERE ID_EMP= :id_emp1");
    query.bindValue(":salaire_emp", res);
    query.bindValue(":id_emp", res1);
    query.bindValue(":id_emp1", res2);
    query.bindValue(":nom_emp", nom_emp);
    query.bindValue(":prenom_emp", prenom_emp);
    query.bindValue(":type_emp", type_emp);
    query.bindValue(":num_emp", num_emp);
    return query.exec();
}
bool employes::supprimer_emp(int id_emp)
{
    QSqlQuery query;
        QString res1 = QString::number(id_emp);
        query.prepare("DELETE FROM EMPLOYES WHERE ID_EMP= :id_emp");
        query.bindValue(":id_emp", res1);
        return query.exec();
}
void employes::gen_pdf()
{
QPdfWriter pdf("ficherend.pdf");
QFont font;
QFont font1;
font.setPointSize(14);
font1.setPointSize(14);
font1.setWeight(QFont::Bold);
QPainter painter (&pdf);
int i=0;
int j=0;

painter.setFont(font1);
QString linepdf;
QSqlQuery query;

painter.setPen(Qt::black);
painter.drawText(2800,600,"FICHE DE RENDEMENT DES EMPLOYES");

query.prepare("Select * from EMPLOYES");
painter.setFont(font);
if (query.exec())
{
    j=2000;
    while (query.next())
    {
        linepdf = query.value(0).toString();
        painter.setPen(Qt::black);
        painter.drawText(750,j,linepdf);
        i++;
  j+=800;
    }
}
if (query.exec())
{
    j=2000;
    while (query.next())
    {
        linepdf = query.value(1).toString();
        painter.setPen(Qt::black);
        painter.drawText(1050,j,linepdf);
        i++;
  j+=800;
    }
}
if (query.exec())
{
    j=2000;
    while (query.next())
    {
        linepdf = query.value(2).toString();
        painter.setPen(Qt::black);
        painter.drawText(2650,j,linepdf);
        i++;
 j+=800;
    }
}
if (query.exec())
{
    j=2000;
    while (query.next())
    {
        linepdf = query.value(3).toString();
        painter.setPen(Qt::black);
        painter.drawText(5000,j,linepdf);
        i++;
 j+=800;
    }
}
if (query.exec())
{
    j=2000;
    while (query.next())
    {
        linepdf = query.value(4).toString();
        painter.setPen(Qt::black);
        painter.drawText(6500,j,linepdf);
        i++;
 j+=800;
    }
}
if (query.exec())
{
    j=2000;
    while (query.next())
    {
        linepdf = query.value(5).toString();
        painter.setPen(Qt::black);
        painter.drawText(8000,j,linepdf);
        i++;
 j+=800;
    }
}
painter.drawPixmap(QRect(10000,5000,100,100),QPixmap("appico.png"));
painter.end();
}
