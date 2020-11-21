#ifndef TRAITEUR_H
#define TRAITEUR_H
#include<QString>
#include<QDate>
#include<QSqlQueryModel>

class traiteur
{
   QString ID_traiteur;
   QString Nom_traiteur;
   QString Numeror_traiteur;
   QString Email_traiteur;
   QString Adresse_traiteur;
   QString Description_traiteur;
public:
   QString getIDTrait(){return ID_traiteur;}
   QString getNomTrait(){return Nom_traiteur;}
   QString getNumTrait(){return Numeror_traiteur;}
   QString getEmailTrait(){return Email_traiteur;}
   QString getAdressTrait(){return Adresse_traiteur;}
   QString getDescrpTrait(){return Description_traiteur;}
   void setDescrpTrait(QString desc){Description_traiteur=desc;}
   void setAdressTrait(QString adress){Adresse_traiteur=adress;}
   void setEmailTrait(QString email){Email_traiteur=email;}
   void setNumTrait(QString num){Numeror_traiteur=num;}
   void setNomTrait(QString nom){Nom_traiteur=nom;}
   void setIDTrait(QString id){ID_traiteur=id;}
   bool addtraiteur( );
   bool update_T(QString identifiant ,QString nom ,QString numero,QString email,QString adresse , int columun);
   QSqlQueryModel* afficher();

};


#endif // TRAITEUR_H
