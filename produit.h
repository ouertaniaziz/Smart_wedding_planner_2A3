#ifndef PRODUIT_H
#define PRODUIT_H

#include<QString>
#include<QDate>
#include<QSqlQueryModel>
class Produit
{ QString Id_Prod;
    QString Nom_Prod;
    QString Type_Prod;
    QString Prix_Prod;
    QString Id_TraitProd;

public:
    QString getIdprod(){return Id_Prod;}
    QString getNOMprod(){return Nom_Prod;}
    QString getTYPEprod(){return Type_Prod;}
    QString getPRIXprod(){return Prix_Prod;}
    QString getIDTRAITPROD(){return Id_TraitProd;}
    void setIDprod(QString id){Id_Prod=id;}
    void setNOMprod(QString nomP){Nom_Prod=nomP;}
    void setTYPEprod(QString typeP){Type_Prod=typeP;}
    void setPRIXprod(QString prixP){Prix_Prod=prixP;}
    void setIDTRAITprod(QString idTP){Id_TraitProd=idTP;}
 bool addproduit();
 bool update_P(QString identifiant ,QString nom ,QString type,QString prix,QString idtrait , int columun);
 QSqlQueryModel* afficher(int c,QString cherche);
 bool effacer(QString identifiant);
 QSqlQueryModel * stat(QString id,int k);

    Produit();
};

#endif // PRODUIT_H
