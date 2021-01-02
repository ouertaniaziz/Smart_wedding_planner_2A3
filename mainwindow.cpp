#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <sstream>
#include <QString>
#include "client_marriage.h"
#include <QDebug>
#include <QtDebug>
#include <QMessageBox>
#include <QSqlQueryModel>
#include "connection.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include "invite.h"
#include <QPrinter>
#include <QPrintDialog>
#include<QPdfWriter>
#include <QPdfWriter>
#include <QPainter>
#include <QTextEdit>
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ajoutersalle.h"
#include "deletedecorator.h"
#include "hall.h"
#include "decorator.h"
#include "smtp.h"
#include "smtp_yassine.h"
#include "deletehall.h"

#include"traiteur.h"
#include"produit.h"



#include <QApplication>
#include <QTableWidget>
#include <QDateTime>
#include<QBarSet>
#include <QtMultimedia/QMediaPlayer>

#include <QChartView>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //icon

    QIcon search_bar("C:/Users/Yassine/Documents/validation QT/Module-yassine/search_icon.png");
    QIcon user_icon("C:/Users/Yassine/Documents/validation QT/Module-yassine/user_icon.png");
    QIcon phone_number_icon("C:/Users/Yassine/Documents/validation QT/Module-yassine/phone_icon.png");
    QIcon cin_icon("C:/Users/Yassine/Documents/validation QT/Module-yassine/cin_icon.png");
    QIcon budget_icon("C:/Users/Yassine/Documents/validation QT/Module-yassine/budget_icon.png");
    QIcon email_icon("C:/Users/Yassine/Documents/validation QT/Module-yassine/email_icon.png");




    //fill the search bar with the icon
    ui->search_bar->addAction(search_bar,QLineEdit::LeadingPosition);
    ui->search_bar->setPlaceholderText("Search");
    ui->search_bar_2->setPlaceholderText("Search");
    ui->search_bar_2->addAction(search_bar,QLineEdit::LeadingPosition);

    //filling the bars with the icons

    ui->male_name->addAction(user_icon,QLineEdit::LeadingPosition);
    ui->female_name->addAction(user_icon,QLineEdit::LeadingPosition);
    ui->male_last_name->addAction(user_icon,QLineEdit::LeadingPosition);
    ui->female_last_name->addAction(user_icon,QLineEdit::LeadingPosition);

    ui->phone_male->addAction(phone_number_icon,QLineEdit::LeadingPosition);
    ui->phone_female->addAction(phone_number_icon,QLineEdit::LeadingPosition);
    ui->male_cin->addAction(cin_icon,QLineEdit::LeadingPosition);
    ui->female_cin->addAction(cin_icon,QLineEdit::LeadingPosition);
    ui->budget->addAction(budget_icon,QLineEdit::LeadingPosition);

    ui->email->addAction(email_icon,QLineEdit::LeadingPosition);

    ui->name_guest->addAction(user_icon,QLineEdit::LeadingPosition);
    ui->last_name_guest->addAction(user_icon,QLineEdit::LeadingPosition);
    ui->Phone_number_guest->addAction(phone_number_icon,QLineEdit::LeadingPosition);
    ui->Email_guest->addAction(email_icon,QLineEdit::LeadingPosition);


    ui->mariage_id->setPlaceholderText("Marriage ID");
    ui->mariage_id_2->setPlaceholderText("Marriage ID");
    ui->mariage_id_3->setPlaceholderText("Marriage ID");
    ui->guest_id->setPlaceholderText("Guest ID");
    ui->guest_id_2->setPlaceholderText("Guest ID");


    ui->tableWidget_client->setColumnWidth(1,196);



    connect(ui->send_invite, SIGNAL(clicked()),this, SLOT(sendMail()));

    ui->tableWidget_client->setSortingEnabled(false);
    ui->tableWidget_3->setSortingEnabled(false);
    ///////////////////////////////////////////


    QIcon search_bar_("C:/Users/Deadly/Desktop/Fac/2A/Projet/Qt/ProjetFac/Img/searchicon");


        //fill the search bar with the icon

        //ui->search_line->addAction(search_bar,QLineEdit::LeadingPosition);
        ui->search_line->setPlaceholderText("Search");


        //ui->search_2->addAction(search_bar,QLineEdit::LeadingPosition);
        ui->search_2->setPlaceholderText("Search");

        //ui->hall_id_line_2->setPlaceholderText("  Hall number");

        animation = new QPropertyAnimation (ui->HallsTitle,"geometry");
            animation->setDuration(10000);
            animation->setStartValue(ui->HallsTitle->geometry());
            animation->setEndValue(QRect(160,10,171,30));
            animation->start();

            QStringList Titres;
            Titres <<"   Identifiant " <<"  Name  "<<" Phone "<<"         Adresse       "<<"         Email        "<<"delete";
            ui->aff_trait->setColumnCount(6);
            ui->aff_trait->setHorizontalHeaderLabels(Titres);
            ui->aff_trait->resizeColumnsToContents();
            ui->stackedWidget->setCurrentIndex(10);

            prod_client p_c;

            QSqlQuery* qry = p_c.afficher_client_pour_poduit();

            while ( qry->next() )
            {
                ui->comboBox_client_produit->addItem(qry->value(11).toString());
            }
Arduino A;

int ret=A.connect_arduino();
switch(ret){
     case 0 :
         qDebug()<<"arduino is available on connected to "<<A.getArduino_port_name();
         break;
     case 1 :
         qDebug()<<"arduino is available but not connected to : "<<A.getArduino_port_name();
         break;
     case -1 :
         qDebug()<<"arduino is not available";
         break;
     }
     QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_btn()));
}

void MainWindow::sendMail()
{
    QSqlQuery qry;
    qry.prepare("SELECT * FROM INVITE_MARRIAGE WHERE ID_MARRIAGE=:id");
    qry.bindValue(":id",ui->mariage_id_3->text());
    if(qry.exec())
    {
        while(qry.next())
        {
            QString code = qry.value(0).toString() + ui->mariage_id_3->text();
            qDebug() << code << endl;

            Smtp* smtp = new Smtp("yassine.bs125@gmail.com", "Salwaghozzi10", "smtp.gmail.com", 465);
            connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


            smtp->sendMail("yassine.bs125@gmail.com", qry.value(4).toString() , "Wedding Invitation",code);
        }

    }



}

/*void MainWindow::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}*/

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::convert_string_to_number(QString s)
{
    quint64 number = s.toULongLong();
    return number;
}

int MainWindow::check_string_without_number(QString s)
{
    int count(0);
    int length = s.length();

    for (int i=0; i<length; i++)
        if ( s[i] >= 0 || s[i] <= 9)
            count++;

    return count;
}


void MainWindow::clear_info_add_marriage()
{
    ui->male_name->setText("");
    ui->male_last_name->setText("");
    ui->phone_male->setText("");
    ui->male_cin->setText("");

    ui->female_name->setText("");
    ui->female_last_name->setText("");
    ui->phone_female->setText("");
    ui->female_cin->setText("");


    QString s="12-02-2020";
    QDate Date = QDate::fromString(s,"dd-MM-yyyy");
    ui->marriage_date->setDate(Date);

    ui->budget->setText("");
    ui->email->setText("");
}

void MainWindow::add_to_database_Marriage()
{
    qDebug("bouton : <<ajouter personne>> appuye");

    QString df = ui->marriage_date->date().toString("dd-MM-yyyy");


    client_marriage C(ui->male_last_name->text(),ui->male_name->text(),ui->male_cin->text(),ui->phone_male->text(),ui->female_last_name->text(),ui->female_name->text(),ui->female_cin->text(),ui->phone_female->text(),ui->budget->text(),df,ui->email->text());

    ////////////////////////
    int cin_m = convert_string_to_number(C.get_cin_m());
    int cin_f = convert_string_to_number(C.get_cin_f());
    int phone_m = convert_string_to_number(C.get_phone_m());
    int phone_f = convert_string_to_number(C.get_phone_f());
    int budget = convert_string_to_number(C.get_budget());

    /////////////////////////



    bool valid = false;

    if ( C.get_email().contains("@gmail.com") )
    {
        valid = true;
    }



    if ((C.get_nom_m()=="")||(C.get_prenom_m()=="")||(C.get_nom_f()=="")||(C.get_prenom_f()=="")||(C.get_cin_m()=="")||(C.get_cin_f()=="")||(C.get_phone_f()=="")||(C.get_phone_m()=="")||(C.get_email()=="")||(C.get_budget()==""))
    {
        QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                              QObject::tr("PLEASE FILL IN THE INFORMATIONS.\n"
                                          "Click Cancel to try again."), QMessageBox::Cancel);
    }
    else if (  cin_m == 0 || cin_f == 0 )
    {
        QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                              QObject::tr("CIN must only contain numbers.\n"
                                          "Click Cancel to try again."), QMessageBox::Cancel);

    }
    else if ( phone_m == 0 || phone_f == 0)
    {
        QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                              QObject::tr("Phone Numbers must only contain numbers.\n"
                                          "Click Cancel to try again."), QMessageBox::Cancel);

    }
    else if ( C.get_cin_m().length() != 8 || C.get_cin_f().length() != 8)
    {
        QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                              QObject::tr("CIN MUST BE 8 NUMBERS ONLY.\n"
                                          "Click Cancel to try again."), QMessageBox::Cancel);

    }
    else if (C.get_phone_m().length() != 8 || C.get_phone_f().length() != 8)
    {
        QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                              QObject::tr("PHONE MUST BE 8 NUMBERS ONLY.\n"
                                          "Click Cancel to try again."), QMessageBox::Cancel);
    }
    else if (C.get_cin_m()==C.get_cin_f())
    {
        ui->male_cin->setStyleSheet(QString("	border: 2px solid #e30000;"
                                            "  border-radius: 8px;"
                                            "background-color: rgb(255,255,255);"));
        ui->female_cin->setStyleSheet(QString("	border: 2px solid #e30000;"
                                              "  border-radius: 8px;"
                                              "background-color: rgb(255,255,255);"));
        QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                              QObject::tr("CIN of both Clients can not be the same.\n"
                                          "Click Cancel to try again."), QMessageBox::Cancel);
    }
    else if ( budget <= 10000 || budget >= 40000 )
    {
        QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                              QObject::tr("Please enter a valid budget between 10000DT and 40000DT.\n"
                                          "Click Cancel to try again."), QMessageBox::Cancel);
    }
    else if ( valid == false)
    {
        QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                              QObject::tr("Please use an email of a Gmail domain.\n"
                                          "Click Cancel to try again."), QMessageBox::Cancel);
    }
    else
    {
        QSqlQuery qry;

        int count = C.unique_cin_search(C.get_cin_m());
        if (count == 0)
        {
            int count1 = C.count_id();


            bool test = C.ajouter_client(count1);
            if ( test)
            {
                QMessageBox::information(nullptr, QObject::tr("add to data base"),
                                         QObject::tr("done .\n"
                                                     "Click Cancel to try again."), QMessageBox::Cancel);
                ui->stackedWidget->setCurrentIndex(1);

            }



            clear_info_add_marriage();


        }

        else
        {
            QMessageBox::critical(nullptr, QObject::tr("add to data base"),
                                  QObject::tr("CIN of male or female already exists.\n"
                                              "Click Cancel to try again."), QMessageBox::Cancel);
        }




    }
}


void MainWindow::Delete_Marriage()
{
    client_marriage C;
    QString ID;
    ID = ui->mariage_id->text();
    if (ID == "")
    {
        QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                              QObject::tr("PLEASE PROVIDE AN ID.\n"
                                          "Click Cancel to try again."), QMessageBox::Cancel);
    }
    else
    {
        bool test = C.supprimer_client(ID);

        if (test)
        {
            ui->mariage_id->setText("");
            ui->stackedWidget->setCurrentIndex(1);
        }


    }
}

void MainWindow::afficher_table_marriage()
{
    client_marriage c;
    int rowCount = c.clear_table_marriage();
    for (int i =rowCount ; i>=0 ; i--)
        ui->tableWidget_client->removeRow(i);

    QSqlQuery qry;
    if (qry.exec("SELECT * FROM CLIENT_MARRIAGE"))
    {
        int rowCount = 0;
        while(qry.next())
        {
            ui->tableWidget_client->insertRow(rowCount);
            QTableWidgetItem *ID = new QTableWidgetItem;
            QTableWidgetItem *Marriage = new QTableWidgetItem;
            QTableWidgetItem *Phone_Number = new QTableWidgetItem;
            QTableWidgetItem *Email = new QTableWidgetItem;
            QTableWidgetItem *Confirmation = new QTableWidgetItem;

            ID->setText(qry.value(11).toString());
            Marriage->setText(qry.value(1).toString()+" "+qry.value(0).toString()+" / "+qry.value(5).toString()+" "+qry.value(4).toString());
            Phone_Number->setText(qry.value(3).toString()+" / "+qry.value(7).toString());
            Email->setText(qry.value(9).toString());


            if ( qry.value(12).toString() == "1" )
            {
                Confirmation->setCheckState(Qt::Checked);
            }
            else
            {
                Confirmation->setCheckState(Qt::Unchecked);
            }


            ui->tableWidget_client->setItem(rowCount,0,ID);
            ui->tableWidget_client->setItem(rowCount,1,Marriage);
            ui->tableWidget_client->setItem(rowCount,2,Phone_Number);
            ui->tableWidget_client->setItem(rowCount,3,Email);
            ui->tableWidget_client->setItem(rowCount,4,Confirmation);

            rowCount++;



        }

    }

}

void MainWindow::search_client_to_update()
{
    QString ID;
    ID = ui->mariage_id_2->text();
    if (ID == "")
    {
        QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                              QObject::tr("PLEASE PROVIDE AN ID.\n"
                                          "Click Cancel to try again."), QMessageBox::Cancel);
    }
    else
    {
        client_marriage c;
        int count = c.check_id_client(ID);



        if ( count == 0)
        {
            QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                                  QObject::tr("ID doesn't exists.\n"
                                              "Click Cancel to try again."), QMessageBox::Cancel);
        }
        else
        {

            QSqlQuery qry= c.search_client_update(ID);


            int i=0;
            QTableWidgetItem *m_name = new QTableWidgetItem;
            QTableWidgetItem *m_last_name = new QTableWidgetItem;
            QTableWidgetItem *m_phone_number = new QTableWidgetItem;
            QTableWidgetItem *m_cin = new QTableWidgetItem;
            QTableWidgetItem *f_name = new QTableWidgetItem;
            QTableWidgetItem *f_last_name = new QTableWidgetItem;
            QTableWidgetItem *f_phone_number = new QTableWidgetItem;
            QTableWidgetItem *f_cin = new QTableWidgetItem;
            QTableWidgetItem *email = new QTableWidgetItem;
            QTableWidgetItem *budget = new QTableWidgetItem;
            QTableWidgetItem *Date = new QTableWidgetItem;

            m_name->setText(qry.value(0).toString());
            m_last_name->setText(qry.value(1).toString());
            m_phone_number->setText(qry.value(2).toString());
            m_cin->setText(qry.value(3).toString());
            f_name->setText(qry.value(4).toString());
            f_last_name->setText(qry.value(5).toString());
            f_phone_number->setText(qry.value(6).toString());
            f_cin->setText(qry.value(7).toString());
            email->setText(qry.value(9).toString());
            budget->setText(qry.value(8).toString());
            Date->setText(qry.value(10).toString());

            ui->tableWidget_2->setItem(0,i,m_name);
            ui->tableWidget_2->setItem(1,i,m_last_name);
            ui->tableWidget_2->setItem(2,i,m_phone_number);
            ui->tableWidget_2->setItem(3,i,m_cin);
            ui->tableWidget_2->setItem(4,i,f_name);
            ui->tableWidget_2->setItem(5,i,f_last_name);
            ui->tableWidget_2->setItem(6,i,f_phone_number);
            ui->tableWidget_2->setItem(7,i,f_cin);
            ui->tableWidget_2->setItem(8,i,email);
            ui->tableWidget_2->setItem(9,i,budget);
            ui->tableWidget_2->setItem(10,i,Date);
        }


    }

}





void MainWindow::on_clientlist_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    afficher_table_marriage();
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_add_client_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_delete_client_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_update_client_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_cancel_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_add_2_clicked()
{
    // pour ajouter le client a la base de données
    add_to_database_Marriage();
    afficher_table_marriage();
}

void MainWindow::on_delete_2_clicked()
{
    // effacer le client desiré
    Delete_Marriage();
    afficher_table_marriage();

}

void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_delete_3_clicked()
{
    //search and show case the client
    search_client_to_update();

}

void MainWindow::update_client_info()
{


    QString ID;
    ID = ui->mariage_id_2->text();

    QSqlQuery qry;

    QTableWidgetItem *nom_m= new QTableWidgetItem,*prenom_m= new QTableWidgetItem,*phone_m= new QTableWidgetItem,*nom_f= new QTableWidgetItem,*prenom_f= new QTableWidgetItem,*phone_f= new QTableWidgetItem,*cin_m= new QTableWidgetItem,*cin_f= new QTableWidgetItem,*budget= new QTableWidgetItem,*email= new QTableWidgetItem,*date= new QTableWidgetItem;
    QString nom_male="",prenom_male="",phone_male="",cin_male="",nom_fe="",prenom_fe="",phone_fe="",cin_fe="",bget="",mail="",Date="";

    for ( int i = 0;i< 11;i++)
    {
        for (int j=0 ; j<1 ; j++)
        {
            if ( i == 0)
            {
                nom_m = ui->tableWidget_2->item(i,j);
                nom_male = nom_m->text();
            }

            if ( i == 1)
            {
                prenom_m = ui->tableWidget_2->item(i,j);
                prenom_male = prenom_m->text();

            }

            if ( i == 2)
            {
                phone_m = ui->tableWidget_2->item(i,j);
                phone_male = phone_m->text();

            }

            if ( i == 3)
            {
                cin_m = ui->tableWidget_2->item(i,j);
                cin_male = cin_m->text();
            }
            if ( i == 4)
            {
                nom_f = ui->tableWidget_2->item(i,j);
                nom_fe = nom_f->text();
            }

            if ( i == 5)
            {
                prenom_f = ui->tableWidget_2->item(i,j);
                prenom_fe = prenom_f->text();
            }
            if ( i == 6)
            {
                phone_f = ui->tableWidget_2->item(i,j);
                phone_fe = phone_f->text();
            }
            if ( i == 7)
            {
                cin_f = ui->tableWidget_2->item(i,j);
                cin_fe = cin_f->text();
            }

            if ( i == 9)
            {
                budget = ui->tableWidget_2->item(i,j);
                bget = budget->text();
            }
            if ( i == 8)
            {
                email = ui->tableWidget_2->item(i,j);
                mail = email->text();
            }
            if ( i == 10)
            {
                date = ui->tableWidget_2->item(i,j);
                Date = date->text();
            }
        }

    }
    client_marriage C(nom_male,prenom_male,cin_male,phone_male,nom_fe,prenom_fe,cin_fe,phone_fe,bget,Date,mail);


    int m_cin = check_string_without_number(C.get_cin_m());
    int f_cin = check_string_without_number(C.get_cin_f());
    int m_phone = check_string_without_number(C.get_phone_m());
    int f_phone = check_string_without_number(C.get_phone_f());
    int b = check_string_without_number(C.get_budget());



    if ((C.get_nom_m()=="")||(C.get_prenom_m()=="")||(C.get_nom_f()=="")||(C.get_prenom_f()=="")||(C.get_cin_m()=="")||(C.get_cin_f()=="")||(C.get_phone_f()=="")||(C.get_phone_m()=="")||(C.get_email()=="")||(C.get_budget()==""))
    {
        QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                              QObject::tr("PLEASE FILL IN THE INFORMATIONS.\n"
                                          "Click Cancel to try again."), QMessageBox::Cancel);
    }
    else if (  C.get_cin_m() == 0 || C.get_cin_f() == 0 )
    {
        QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                              QObject::tr("CIN must only contain numbers.\n"
                                          "Click Cancel to try again."), QMessageBox::Cancel);

    }
    else if ( C.get_phone_m() == 0 || C.get_phone_f() == 0)
    {
        QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                              QObject::tr("Phone Numbers must only contain numbers.\n"
                                          "Click Cancel to try again."), QMessageBox::Cancel);

    }
    else if ( C.get_cin_m().length() != 8 || C.get_cin_f().length() != 8)
    {
        QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                              QObject::tr("CIN MUST BE 8 NUMBERS ONLY.\n"
                                          "Click Cancel to try again."), QMessageBox::Cancel);

    }
    else if (C.get_phone_m().length() != 8 || C.get_phone_f().length() != 8)
    {
        QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                              QObject::tr("PHONE MUST BE 8 NUMBERS ONLY.\n"
                                          "Click Cancel to try again."), QMessageBox::Cancel);
    }
    else if (C.get_cin_m()==C.get_cin_f())
    {
        ui->male_cin->setStyleSheet(QString("	border: 2px solid #e30000;"
                                            "  border-radius: 8px;"
                                            "background-color: rgb(255,255,255);"));
        ui->female_cin->setStyleSheet(QString("	border: 2px solid #e30000;"
                                              "  border-radius: 8px;"
                                              "background-color: rgb(255,255,255);"));
        QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                              QObject::tr("CIN of both Clients can not be the same.\n"
                                          "Click Cancel to try again."), QMessageBox::Cancel);
    }
    else if ( m_cin < 8 || f_cin < 8 )
    {
        QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                              QObject::tr("CIN MUST CONTAIN ONLY NUMBERS.\n"
                                          "Click Cancel to try again."), QMessageBox::Cancel);
    }
    else if (m_phone < 8 || f_phone <8 )
    {
        QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                              QObject::tr("PHONE NUMBER MUST CONTAIN ONLY NUMBERS.\n"
                                          "Click Cancel to try again."), QMessageBox::Cancel);
    }
    else
    {
        int count = C.check_id_client(ID);

        if (count == 1)
        {

            bool test = C.update_client_info(ID);
            if ( test)
            {
                QMessageBox::information(nullptr, QObject::tr("edit to data base"),
                                         QObject::tr("Client Updated.\n"
                                                     "Click Cancel to exit."), QMessageBox::Cancel);
                ui->stackedWidget->setCurrentIndex(1);
                for (int i =0 ; i<1 ; i++)
                    for (int j =0 ; j< 11 ; j++)
                        ui->tableWidget_2->item(j,i)->setText("");

                ui->mariage_id_2->setText("");


            }


        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("edit to data base"),
                                  QObject::tr("CIN doesn't exist.\n"
                                              "Click Cancel to try again."), QMessageBox::Cancel);
        }

    }

}





void MainWindow::on_update_client_info_clicked()
{
    //confirm update and update client's info

    update_client_info();
    afficher_table_marriage();
}

void MainWindow::on_guestlist_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_marriage_list_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    afficher_table_marriage();
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->mariage_id_3->setText("");
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::afficher_liste_invite(QString marriage_id)
{
    invite inv;
    int rowCount = inv.clear_table_inv();

    for (int i =rowCount ; i>=0 ; i--)
        ui->tableWidget_3->removeRow(i);


    QSqlQuery qry;

    qry.prepare("SELECT * FROM INVITE_MARRIAGE WHERE ID_MARRIAGE = :id_marriage");
    qry.bindValue(":id_marriage",marriage_id);

    if (qry.exec())
    {
        int rowCount = 0;
        while(qry.next())
        {
            ui->tableWidget_3->insertRow(rowCount);
            QTableWidgetItem *ID_invite = new QTableWidgetItem;
            QTableWidgetItem *full_name = new QTableWidgetItem;
            QTableWidgetItem *phone_invite = new QTableWidgetItem;
            QTableWidgetItem *email_invite = new QTableWidgetItem;

            ID_invite->setText(qry.value(0).toString());
            full_name->setText(qry.value(1).toString()+" "+qry.value(2).toString());
            phone_invite->setText(qry.value(3).toString());
            email_invite->setText(qry.value(4).toString());



            ui->tableWidget_3->setItem(rowCount,0,ID_invite);
            ui->tableWidget_3->setItem(rowCount,1,full_name);
            ui->tableWidget_3->setItem(rowCount,2,phone_invite);
            ui->tableWidget_3->setItem(rowCount,3,email_invite);
            rowCount++;



        }

    }

    ui->stackedWidget->setCurrentIndex(6);
}


void MainWindow::on_search_guest_list_clicked()
{
    // recher d'un client id pour afficher les invitées
    QString marriage_id = ui->mariage_id_3->text();

    client_marriage c;
    int rowCount = c.check_id_client(marriage_id);
    if ( rowCount == 0)
    {
        QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                              QObject::tr("ENTER A VALID MARRIAGE ID.\n"
                                          "Click Cancel to try again."), QMessageBox::Cancel);
    }
    else
    {
        afficher_liste_invite(marriage_id);
    }

}



void MainWindow::on_add_guest_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_back_guest_from_add()
{
    ui->stackedWidget->setCurrentIndex(6);
    ui->name_guest->setText("");
    ui->last_name_guest->setText("");
    ui->Phone_number_guest->setText("");
    ui->Email_guest->setText("");


}

void MainWindow::on_delete_guest_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
}

void MainWindow::on_pushButton_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_delete_guest_3_clicked()
{
    //delete the guest through ID then go back to guest list
    invite e;
    QString ID = ui->guest_id->text();
    QString id_client = ui->mariage_id_3->text();
    bool test = e.supprimer_invite(ID,id_client);

    QSqlQuery qry;



    int id = ui->guest_id->text().toInt();

    e.fix_id_after_delete(id,id_client);

    if (  test )
    {
        afficher_liste_invite(ui->mariage_id_3->text());
    }

}

void MainWindow::on_pushButton_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_update_guest_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}

void MainWindow::on_search_bar_textChanged(const QString &arg1)
{
    if ( ui->ID->isChecked())
    {
        QString filter = ui->search_bar->text();
        for( int i = 0; i < ui->tableWidget_client->rowCount(); ++i )
        {
            bool match = false;
            for( int j = 0; j < 1; ++j )
            {
                QTableWidgetItem *item = ui->tableWidget_client->item(i,j);
                if( item->text().contains(arg1) )
                {
                    match = true;
                    break;
                }
            }
            ui->tableWidget_client->setRowHidden( i, !match );
        }
    }
    else if ( ui->MARRIAGE->isChecked())
    {
        QString filter = ui->search_bar->text();
        for( int i = 0; i < ui->tableWidget_client->rowCount(); ++i )
        {
            bool match = false;
            for( int j = 1; j < 2; ++j )
            {
                QTableWidgetItem *item = ui->tableWidget_client->item(i,j);
                if( item->text().contains(arg1) )
                {
                    match = true;
                    break;
                }
            }
            ui->tableWidget_client->setRowHidden( i, !match );
        }
    }
    else if ( ui->PHONE_NUMBER->isChecked())
    {
        QString filter = ui->search_bar->text();
        for( int i = 0; i < ui->tableWidget_client->rowCount(); ++i )
        {
            bool match = false;
            for( int j = 2; j < 3; ++j )
            {
                QTableWidgetItem *item = ui->tableWidget_client->item(i,j);
                if( item->text().contains(arg1) )
                {
                    match = true;
                    break;
                }
            }
            ui->tableWidget_client->setRowHidden( i, !match );
        }
    }
    else
    {
        QString filter = ui->search_bar->text();
        for( int i = 0; i < ui->tableWidget_client->rowCount(); ++i )
        {
            bool match = false;
            for( int j = 0; j < ui->tableWidget_client->columnCount(); ++j )
            {
                QTableWidgetItem *item = ui->tableWidget_client->item(i,j);
                if( item->text().contains(arg1) )
                {
                    match = true;
                    break;
                }
            }
            ui->tableWidget_client->setRowHidden( i, !match );
        }
    }

}



void MainWindow::on_add_guest_3_clicked()
{
    QString id_inv  ="";
    QString nom_inv = ui->name_guest->text();
    QString prenom_inv = ui->last_name_guest->text();
    QString phone_inv = ui->Phone_number_guest->text();
    QString email_inv = ui->Email_guest->text();
    QString id_marriage = ui->mariage_id_3->text();

    invite E(id_inv,nom_inv,prenom_inv,phone_inv,email_inv,id_marriage);
    ///////////////////////////////////

    int count = E.count_id_inv(id_marriage);
    id_inv = QString::number(count);
    E.set_id_inv(id_inv);



    bool valid = false;

    if ( E.get_email().contains("@gmail.com") )
    {
        valid = true;
    }
    int length_email = E.get_email().length();

    int phone = convert_string_to_number(E.get_phone());
    int l_phone = E.get_phone().length();

    if ( E.get_nom() == "" || E.get_phone() == "" || E.get_prenom()=="" || E.get_email() == "")
    {
        QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                              QObject::tr("PLEASE FILL IN THE INFORMATIONS.\n"
                                          "Click Cancel to try again."), QMessageBox::Cancel);
    }
    else if ( phone == 0)
    {
        QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                              QObject::tr("PHONE NUMBER MUST ONLY CONTAIN NUMBERS AND NOT 0 OR EMPTY.\n"
                                          "Click Cancel to try again."), QMessageBox::Cancel);
    }
    else if ( l_phone < 8)
    {
        QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                              QObject::tr("ENTER A VALID 8 DIGIT PHONE NUMBER.\n"
                                          "Click Cancel to try again."), QMessageBox::Cancel);
    }
    else if ( valid == false)
    {
        QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                              QObject::tr("Please use an email of a Gmail domain.\n"
                                          "Click Cancel to try again."), QMessageBox::Cancel);
    }
    else if ( length_email < 14)
    {
        QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                              QObject::tr("Email must contian at least 4 letters before the gmail domaine.\n"
                                          "Click Cancel to try again."), QMessageBox::Cancel);
    }
    else
    {

        int count = E.invite_check_unique_phone(E.get_phone());
        if ( count == 0)
        {
            bool test = E.add_guest();
            if ( test )
            {
                QMessageBox::information(nullptr, QObject::tr("SUCCESS"),
                                         QObject::tr("done .\n"
                                                     "Click Cancel to try again."), QMessageBox::Cancel);
            }
            ui->stackedWidget->setCurrentIndex(6);
            afficher_liste_invite(E.get_id_marriage());

            ui->name_guest->setText("");
            ui->last_name_guest->setText("");
            ui->Phone_number_guest->setText("");
            ui->Email_guest->setText("");
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                                  QObject::tr("PHONE NUMBER ALREADY EXISTS.\n"
                                              "Click Cancel to try again."), QMessageBox::Cancel);
        }
    }



}



void MainWindow::on_cancel_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
    ui->name_guest->setText("");
    ui->last_name_guest->setText("");
    ui->Phone_number_guest->setText("");
    ui->Email_guest->setText("");

}

void MainWindow::on_search_gues_info_clicked()
{
    invite inv;
    QString ID,id_client;
    id_client = ui->mariage_id_3->text();
    ID = ui->guest_id_2->text();
    if (ID == "")
    {
        QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                              QObject::tr("PLEASE PROVIDE AN ID.\n"
                                          "Click Cancel to try again."), QMessageBox::Cancel);
    }
    else
    {



        int count = inv.search_inv_exist_to_update(ID,id_client);
        if ( count == 0)
        {
            QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                                  QObject::tr("ID doesn't exists.\n"
                                              "Click Cancel to try again."), QMessageBox::Cancel);
        }
        else
        {
            QSqlQuery qry = inv.search_inv_to_update(ID,id_client);
            int i=0;
            QTableWidgetItem *name = new QTableWidgetItem;
            QTableWidgetItem *last_name = new QTableWidgetItem;
            QTableWidgetItem *phone_number = new QTableWidgetItem;
            QTableWidgetItem *email = new QTableWidgetItem;

            name->setText(qry.value(1).toString());
            last_name->setText(qry.value(2).toString());
            phone_number->setText(qry.value(3).toString());
            email->setText(qry.value(4).toString());


            ui->tableWidget_5->setItem(0,i,name);
            ui->tableWidget_5->setItem(1,i,last_name);
            ui->tableWidget_5->setItem(2,i,phone_number);
            ui->tableWidget_5->setItem(3,i,email);


        }

    }
}

void MainWindow::on_update_guest_info_clicked()
{
    QString ID,id_client;
    ID = ui->guest_id_2->text();
    id_client = ui->mariage_id_3->text();

    QSqlQuery qry;

    QTableWidgetItem *nom= new QTableWidgetItem,*prenom= new QTableWidgetItem,*phone= new QTableWidgetItem,*email= new QTableWidgetItem;
    QString n_inv="",p_inv="",ph_inv="",email_inv="";

    for ( int i = 0;i< 4;i++)
    {
        for (int j=0 ; j<1 ; j++)
        {
            if ( i == 0)
            {
                nom = ui->tableWidget_5->item(i,j);
                n_inv = nom->text();
            }
            if ( i == 1)
            {
                prenom = ui->tableWidget_5->item(i,j);
                p_inv = prenom->text();

            }
            if ( i == 2)
            {
                phone = ui->tableWidget_5->item(i,j);
                ph_inv = phone->text();

            }
            if ( i == 3)
            {
                email = ui->tableWidget_5->item(i,j);
                email_inv = email->text();
            }
        }

    }
    invite inv(ID,n_inv,p_inv,ph_inv,email_inv,id_client);


    bool valid = false;

    if ( inv.get_email().contains("@gmail.com") )
    {
        valid = true;
    }
    int length_email = inv.get_email().length();

    int phone_inv = convert_string_to_number(inv.get_phone());
    int l_phone = inv.get_phone().length();


    if ( inv.get_nom()== "" || inv.get_prenom()== "" || inv.get_email()== "" || inv.get_phone() == "")
    {
        QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                              QObject::tr("PLEASE FILL IN THE INFORMATIONS.\n"
                                          "Click Cancel to try again."), QMessageBox::Cancel);
    }
    else if ( phone_inv == 0)
    {
        QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                              QObject::tr("PHONE NUMBER MUST ONLY CONTAIN NUMBERS AND NOT 0 OR EMPTY.\n"
                                          "Click Cancel to try again."), QMessageBox::Cancel);
    }
    else if ( l_phone < 8)
    {
        QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                              QObject::tr("ENTER A VALID 8 DIGIT PHONE NUMBER.\n"
                                          "Click Cancel to try again."), QMessageBox::Cancel);
    }
    else if ( valid == false)
    {
        QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                              QObject::tr("Please use an email of a Gmail domain.\n"
                                          "Click Cancel to try again."), QMessageBox::Cancel);
    }
    else if ( length_email < 14)
    {
        QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                              QObject::tr("Email must contian at least 4 letters before the gmail domaine.\n"
                                          "Click Cancel to try again."), QMessageBox::Cancel);
    }
    else
    {
        int count = inv.search_inv_exist_to_update(ID,id_client);

        if (count == 1)
        {

            bool test = inv.update_invite_info( ID, id_client);
            if ( test)
            {
                QMessageBox::information(nullptr, QObject::tr("edit to data base"),
                                         QObject::tr("invite Updated.\n"
                                                     "Click Cancel to exit."), QMessageBox::Cancel);
                afficher_liste_invite(inv.get_id_marriage());
                ui->stackedWidget->setCurrentIndex(6);
                for (int i =0 ; i<1 ; i++)
                    for (int j =0 ; j< 4 ; j++)
                        ui->tableWidget_5->item(j,i)->setText("");

                ui->guest_id_2->setText("");


            }


        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("edit to data base"),
                                  QObject::tr("ID doesn't exist.\n"
                                              "Click Cancel to try again."), QMessageBox::Cancel);
        }

    }

}


void MainWindow::on_search_bar_2_textChanged(const QString &arg1)
{
    QString filter = ui->search_bar->text();
    for( int i = 0; i < ui->tableWidget_3->rowCount(); ++i )
    {
        bool match = false;
        for( int j = 0; j < ui->tableWidget_3->columnCount(); ++j )
        {
            QTableWidgetItem *item = ui->tableWidget_3->item( i, j );
            if( item->text().contains(arg1) )
            {
                match = true;
                break;
            }
        }
        ui->tableWidget_3->setRowHidden( i, !match );
    }
}

void MainWindow::on_imprimer_clicked()
{
    QPrinter printer;
    invite inv;
    printer.setPrinterName("my_printer_machine");
    QPrintDialog dialog(&printer,this);
    if ( dialog.exec()== QDialog::Rejected) return ;

    QString nom,phone,email,cin,budget,date;

    QString ID = ui->mariage_id_2->text();

    QSqlQuery qry = inv.search_inv_to_print(ID);

    nom = qry.value(0).toString() + " " + qry.value(1).toString() + " ET " + qry.value(4).toString() + " " + qry.value(5).toString();
    phone = qry.value(2).toString() + " / " + qry.value(6).toString();
    cin = qry.value(3).toString() + " / " + qry.value(7).toString();
    email = qry.value(9).toString();
    budget = qry.value(8).toString();
    date = qry.value(10).toString();






    QString text = "Le Nom Complet des Marries est  : " + nom + "\n"
            + " Les numeros de telephone associes sont : " + phone + "\n"
            + " Les CIN associes sont : " + cin + "\n"
            + " Leur Email est : " + email + "\n"
            + " Leur Budget est : " + budget + "\n"
            + " Leur Date de Marriage est : " + date ;


    QTextEdit y;
    y.setPlainText(text);

    y.print(&printer);


}

void MainWindow::on_send_invite_clicked()
{
    QString ID = ui->mariage_id_3->text();
    client_marriage c;
    c.update_confirmation(ID);
}

void MainWindow::on_pushButton_10_clicked()
{

}

void MainWindow::on_client_back_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_yassine_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_back_tomneu_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
}


void MainWindow::on_zied_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
}


////////////////////////////////////////////////////////////////////////////////////////////////////////




void MainWindow::on_SelectHallButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);

    animation = new QPropertyAnimation (ui->DecoratorsTitle,"geometry");
        animation->setDuration(10000);
        animation->setStartValue(ui->DecoratorsTitle->geometry());
        animation->setEndValue(QRect(160,10,171,30));
        animation->start();

}

void MainWindow::on_AddHallButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);

}

void MainWindow::on_UpdateHallButton_clicked()
{
    ui->UpdateButton->setVisible(false);



    ui->stackedWidget->setCurrentIndex(14);
}

void MainWindow::on_AddDecButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(16);

}

void MainWindow::on_UpdateDecButton_clicked()
{
    ui->UpdateButton_2->setVisible(false);

    ui->stackedWidget->setCurrentIndex(15);

}

void MainWindow::on_BackButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);

}

void MainWindow::on_BackButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);

}

void MainWindow::on_BackButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);

}

void MainWindow::on_BackButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);

}

void MainWindow::on_BackButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);

}

void MainWindow::on_AddButton_clicked()
{
    bool _empty=false;


    if(ui->hall_name_line->text()=="")
    {
        ui->hall_name_line->setStyleSheet(QString("	border: 2px solid #e30000;"
                                                "  border-radius: 8px;"
                                                  "padding-left: 20px;"
                                                  "padding-right: 20px;"
                                                  "background-color: rgb(255,255,255);"));
        _empty=true;

   }

    if(ui->address_line->text()=="")
    {
        ui->address_line->setStyleSheet(QString("	border: 2px solid #e30000;"
                                                "  border-radius: 8px;"
                                                  "padding-left: 20px;"
                                                  "padding-right: 20px;"
                                                  "background-color: rgb(255,255,255);"));

        _empty=true;

   }

    if(ui->price_line->text()=="")
    {
        ui->price_line->setStyleSheet(QString("	border: 2px solid #e30000;"
                                                "  border-radius: 8px;"
                                                  "padding-left: 20px;"
                                                  "padding-right: 20px;"
                                                  "background-color: rgb(255,255,255);"));

        _empty=true;

   }

    if(ui->nb_places_line->text()=="")
    {
        ui->nb_places_line->setStyleSheet(QString("	border: 2px solid #e30000;"
                                                "  border-radius: 8px;"
                                                  "padding-left: 20px;"
                                                  "padding-right: 20px;"
                                                  "background-color: rgb(255,255,255);"));

        _empty=true;

   }

    if(ui->number_line->text()=="")
    {
        ui->number_line->setStyleSheet(QString("	border: 2px solid #e30000;"
                                                "  border-radius: 8px;"
                                                  "padding-left: 20px;"
                                                  "padding-right: 20px;"
                                                  "background-color: rgb(255,255,255);"));

        _empty=true;

   }

    if(ui->email_line->text()=="")
    {
        ui->email_line->setStyleSheet(QString("	border: 2px solid #e30000;"
                                                "  border-radius: 8px;"
                                                  "padding-left: 20px;"
                                                  "padding-right: 20px;"
                                                  "background-color: rgb(255,255,255);"));
        _empty=true;

   }

    if(ui->number_line->text().length()!=8)
    {
        ui->number_line->setStyleSheet(QString("	border: 2px solid #e30000;"
                                                "  border-radius: 8px;"
                                                  "padding-left: 20px;"
                                                  "padding-right: 20px;"
                                                  "background-color: rgb(255,255,255);"));

        _empty=true;

   }

    if(!ui->email_line->text().contains("@")||!ui->email_line->text().contains("."))
    {
        ui->email_line->setStyleSheet(QString("	border: 2px solid #e30000;"
                                                "  border-radius: 8px;"
                                                  "padding-left: 20px;"
                                                  "padding-right: 20px;"
                                                  "background-color: rgb(255,255,255);"));
        _empty=true;

   }



    if(_empty) return ;

    Hall H(ui->number_line->text(),
           "0",
           ui->hall_name_line->text(),
           ui->address_line->text(),
           ui->email_line->text(),
           ui->number_line->text(),
           ui->price_line->text(),
           ui->nb_places_line->text()
           );

    bool fn=H.addHall();
    if(fn)  {
        ui->stackedWidget->setCurrentIndex(11);

        Hall H(ui->search_line->text(),
               "",
               "",
               "",
               "",
               "",
               "",
               ""
               );

        ui->tableView->setModel(H.tableView());
        ui->tableView->resizeRowsToContents();
        ui->tableView->resizeColumnsToContents();

    }


}



void MainWindow::on_AddButton_2_clicked()
{

       bool _empty2=false;


       if(ui->decorator_name_line_2->text()=="")
       {
           ui->decorator_name_line_2->setStyleSheet(QString("	border: 2px solid #e30000;"
                                                   "  border-radius: 8px;"
                                                     "padding-left: 20px;"
                                                     "padding-right: 20px;"
                                                     "background-color: rgb(255,255,255);"));
           _empty2=true;

      }

       if(ui->number_line_4->text()=="")
       {
           ui->number_line_4->setStyleSheet(QString("	border: 2px solid #e30000;"
                                                   "  border-radius: 8px;"
                                                     "padding-left: 20px;"
                                                     "padding-right: 20px;"
                                                     "background-color: rgb(255,255,255);"));

           _empty2=true;

      }

       if(ui->price_line_4->text()=="")
       {
           ui->price_line_4->setStyleSheet(QString("	border: 2px solid #e30000;"
                                                   "  border-radius: 8px;"
                                                     "padding-left: 20px;"
                                                     "padding-right: 20px;"
                                                     "background-color: rgb(255,255,255);"));

           _empty2=true;

      }

       if(ui->type_decoration_line_2->text()=="")
       {
           ui->type_decoration_line_2->setStyleSheet(QString("	border: 2px solid #e30000;"
                                                   "  border-radius: 8px;"
                                                     "padding-left: 20px;"
                                                     "padding-right: 20px;"
                                                     "background-color: rgb(255,255,255);"));

           _empty2=true;

      }

       if(ui->hall_id_line->text()=="")

       {
           ui->hall_id_line->setStyleSheet(QString("	border: 2px solid #e30000;"
                                                   "  border-radius: 8px;"
                                                     "padding-left: 20px;"
                                                     "padding-right: 20px;"
                                                     "background-color: rgb(255,255,255);"));

           _empty2=true;

      }

       if(ui->number_line_4->text().length()!=8)
       {
           ui->number_line_4->setStyleSheet(QString("	border: 2px solid #e30000;"
                                                   "  border-radius: 8px;"
                                                     "padding-left: 20px;"
                                                     "padding-right: 20px;"
                                                     "background-color: rgb(255,255,255);"));

           _empty2=true;

      }



       if(_empty2) return ;

       Decorator D(ui->number_line_4->text(),
                   ui->decorator_name_line_2->text(),
                   ui->type_decoration_line_2->text(),
                   ui->price_line_4->text(),
                   ui->number_line_4->text(),
                   "0",
                   ui->hall_id_line->text()
                   );


       bool fn=D.addDecorator();
       if(fn)
       {

           ui->stackedWidget->setCurrentIndex(12);
           Decorator D(ui->search_2->text(),
                       "",
                       "",
                       "",
                       "",
                       "",
                       ""
                       );

               ui->tableView_2->setModel(D.tableView());
               ui->tableView_2->resizeRowsToContents();
               ui->tableView_2->resizeColumnsToContents();
       }


}

void MainWindow::on_DeleteHallButton_clicked()
{

    DeleteHall *dialog =new DeleteHall(this);
    dialog->show();
;

}

void MainWindow::on_DisplayButton_clicked()
{

        Hall H(ui->search_line->text(),
               "",
               "",
               "",
               "",
               "",
               "",
               ""
               );

        ui->tableView->setModel(H.tableView());
        ui->tableView->resizeRowsToContents();
        ui->tableView->resizeColumnsToContents();




}

void MainWindow::on_AddDecButton_2_clicked()
{

    Decorator D(ui->search_2->text(),
                "",
                "",
                "",
                "",
                "",
                ""
                );

        ui->tableView_2->setModel(D.tableView());
        ui->tableView_2->resizeRowsToContents();
        ui->tableView_2->resizeColumnsToContents();


}

void MainWindow::on_DeleteDecButton_clicked()
{
    DeleteDecorator *dialog =new DeleteDecorator(this);
    dialog->show();
}

void MainWindow::on_UpdateButton_clicked()
{
    bool _empty3=false;

    if(ui->hall_name_line_2->text()=="")
    {
        ui->hall_name_line_2->setStyleSheet(QString("	border: 2px solid #e30000;"
                                                "  border-radius: 8px;"
                                                  "padding-left: 20px;"
                                                  "padding-right: 20px;"
                                                  "background-color: rgb(255,255,255);"));
        _empty3=true;

   }

    if(ui->address_line_2->text()=="")
    {
        ui->address_line_2->setStyleSheet(QString("	border: 2px solid #e30000;"
                                                "  border-radius: 8px;"
                                                  "padding-left: 20px;"
                                                  "padding-right: 20px;"
                                                  "background-color: rgb(255,255,255);"));
        _empty3=true;

   }

    if(ui->price_line_2->text()=="")
    {
        ui->price_line_2->setStyleSheet(QString("	border: 2px solid #e30000;"
                                                "  border-radius: 8px;"
                                                  "padding-left: 20px;"
                                                  "padding-right: 20px;"
                                                  "background-color: rgb(255,255,255);"));
        _empty3=true;

   }

    if(ui->nb_places_line_2->text()=="")
    {
        ui->nb_places_line_2->setStyleSheet(QString("	border: 2px solid #e30000;"
                                                "  border-radius: 8px;"
                                                  "padding-left: 20px;"
                                                  "padding-right: 20px;"
                                                  "background-color: rgb(255,255,255);"));
        _empty3=true;

   }

    if(ui->number_line_2->text()=="")
    {

        ui->number_line_2->setStyleSheet(QString("	border: 2px solid #e30000;"
                                                "  border-radius: 8px;"
                                                  "padding-left: 20px;"
                                                  "padding-right: 20px;"
                                                  "background-color: rgb(255,255,255);"));
        _empty3=true;
   }

    if(ui->email_line_2->text()=="")
    {

        ui->email_line_2->setStyleSheet(QString("	border: 2px solid #e30000;"
                                                "  border-radius: 8px;"
                                                  "padding-left: 20px;"
                                                  "padding-right: 20px;"
                                                  "background-color: rgb(255,255,255);"));
        _empty3=true;
   }

    if(ui->number_line_2->text().length()!=8)
    {

        ui->number_line_2->setStyleSheet(QString("	border: 2px solid #e30000;"
                                                "  border-radius: 8px;"
                                                  "padding-left: 20px;"
                                                  "padding-right: 20px;"
                                                  "background-color: rgb(255,255,255);"));
        _empty3=true;
   }

    if(!ui->email_line_2->text().contains("@")||!ui->email_line_2->text().contains("."))
    {
        ui->email_line->setStyleSheet(QString("	border: 2px solid #e30000;"
                                                "  border-radius: 8px;"
                                                  "padding-left: 20px;"
                                                  "padding-right: 20px;"
                                                  "background-color: rgb(255,255,255);"));
        _empty3=true;

   }

    if(_empty3) return ;

    Hall H(ui->number_line_2->text(),
           "0",
           ui->hall_name_line_2->text(),
           ui->address_line_2->text(),
           ui->email_line_2->text(),
           ui->number_line_2->text(),
           ui->price_line_2->text(),
           ui->nb_places_line_2->text()
           );

    bool test=H.updateHall();
    if(test)
    {
           ui->stackedWidget->setCurrentIndex(11);

    }


}



void MainWindow::on_UpdateButton_2_clicked()
{
    bool _empty2=false;


    if(ui->decorator_name_line->text()=="")
    {
        ui->decorator_name_line->setStyleSheet(QString("	border: 2px solid #e30000;"
                                                "  border-radius: 8px;"
                                                  "padding-left: 20px;"
                                                  "padding-right: 20px;"
                                                  "background-color: rgb(255,255,255);"));
        _empty2=true;

   }

    if(ui->number_line_3->text()=="")
    {
        ui->number_line_3->setStyleSheet(QString("	border: 2px solid #e30000;"
                                                "  border-radius: 8px;"
                                                  "padding-left: 20px;"
                                                  "padding-right: 20px;"
                                                  "background-color: rgb(255,255,255);"));

        _empty2=true;

   }

    if(ui->price_line_3->text()=="")
    {
        ui->price_line_3->setStyleSheet(QString("	border: 2px solid #e30000;"
                                                "  border-radius: 8px;"
                                                  "padding-left: 20px;"
                                                  "padding-right: 20px;"
                                                  "background-color: rgb(255,255,255);"));

        _empty2=true;

   }

    if(ui->type_decoration_line->text()=="")
    {
        ui->type_decoration_line->setStyleSheet(QString("	border: 2px solid #e30000;"
                                                "  border-radius: 8px;"
                                                  "padding-left: 20px;"
                                                  "padding-right: 20px;"
                                                  "background-color: rgb(255,255,255);"));

        _empty2=true;

   }

    if(ui->hall_id_line_3->text()=="")
    {
        ui->hall_id_line_3->setStyleSheet(QString("	border: 2px solid #e30000;"
                                                "  border-radius: 8px;"
                                                  "padding-left: 20px;"
                                                  "padding-right: 20px;"
                                                  "background-color: rgb(255,255,255);"));

        _empty2=true;

   }


    if(ui->number_line_3->text().length()!=8)
    {
        ui->number_line_3->setStyleSheet(QString("	border: 2px solid #e30000;"
                                                "  border-radius: 8px;"
                                                  "padding-left: 20px;"
                                                  "padding-right: 20px;"
                                                  "background-color: rgb(255,255,255);"));

        _empty2=true;

   }

    if(ui->hall_id_line_3->text().length()!=8)
    {
        ui->hall_id_line_3->setStyleSheet(QString("	border: 2px solid #e30000;"
                                                "  border-radius: 8px;"
                                                  "padding-left: 20px;"
                                                  "padding-right: 20px;"
                                                  "background-color: rgb(255,255,255);"));

        _empty2=true;

   }


    if(_empty2) return ;


    Decorator D(ui->number_line_3->text(),
                       ui->decorator_name_line->text(),
                       ui->type_decoration_line->text(),
                       ui->price_line_3->text(),
                       ui->number_line_3->text(),
                       "0",
                       ui->hall_id_line_3->text()
                       );



        bool test =D.updateDecorator();

          if(test)
        {
            ui->stackedWidget->setCurrentIndex(12);

        }


}

void MainWindow::on_UpdateFindButton_clicked()
{


    if(ui->number_line_2->text()=="")
    {

        ui->number_line_2->setStyleSheet(QString("	border: 2px solid #e30000;"
                                                "  border-radius: 8px;"
                                                  "padding-left: 20px;"
                                                  "padding-right: 20px;"
                                                  "background-color: rgb(255,255,255);"));
        return ;
    }


    QSqlQuery qry;
//    Hall H(ui->number_line_2->text(),
//           "",
//           "",
//           "",
//           "",
//           "",
//           "",
//           ""
//           );
//     qry =H.findHall();

            if (qry.exec("SELECT * FROM SALLE WHERE ID ='"+ ui->number_line_2->text() +"' "))
            {
                int count(0);
                while(qry.next())
                {
                    count++;

                    ui->number_line_2->setText(qry.value(0).toString());
                    ui->hall_name_line_2->setText(qry.value(2).toString());
                    ui->address_line_2->setText(qry.value(3).toString());
                    ui->email_line_2->setText(qry.value(4).toString());
                    ui->price_line_2->setText(qry.value(6).toString());
                    ui->nb_places_line_2->setText(qry.value(7).toString());

                    ui->UpdateButton->setVisible(true);



                }
                if (count == 0)
                {


                    ui->number_line_2->setStyleSheet(QString("	border: 2px solid #e30000;"
                                                            "  border-radius: 8px;"
                                                              "padding-left: 20px;"
                                                              "padding-right: 20px;"
                                                              "background-color: rgb(255,255,255);"));

                    QMessageBox::critical(nullptr, QObject::tr("edit to data base"),
                                          QObject::tr("HALL NUMBER doesn't exist.\n"
                                                      "Click Cancel to try again."), QMessageBox::Cancel);

                }

            }



}

void MainWindow::on_UpdateFindButton_2_clicked()
{
       bool _empty=false;


    if(ui->number_line_3->text()=="")
    {
        ui->number_line_3->setStyleSheet(QString("	border: 2px solid #e30000;"
                                                "  border-radius: 8px;"
                                                  "padding-left: 20px;"
                                                  "padding-right: 20px;"
                                                  "background-color: rgb(255,255,255);"));

        _empty=true;
   }

    if(_empty) return ;

//    Decorator D(ui->number_line_3->text(),
//                "",
//                "",
//                "",
//                "",
//                "",
//                ""
//                );


    QSqlQuery qry3;

    //qry3 =D.findDecorator();



        if (qry3.exec("SELECT * FROM DECORATEUR WHERE ID =  '"+ ui->number_line_3->text() +"' "))
                {
                    int count(0);
                    while(qry3.next())
                    {
                        count++;

                        ui->decorator_name_line->setText(qry3.value(0).toString());
                        ui->type_decoration_line->setText(qry3.value(1).toString());
                        ui->price_line_3->setText(qry3.value(2).toString());
                        ui->number_line_3->setText(qry3.value(3).toString());
                        ui->hall_id_line_3->setText(qry3.value(5).toString());
                        ui->number_line_3->setText(qry3.value(6).toString());


                        ui->UpdateButton_2->setVisible(true);



                    }
                    if (count == 0)
                    {
                        QMessageBox::critical(nullptr, QObject::tr("add to data base"),
                                              QObject::tr("DECORATOR  doesn't exist.\n"
                                                          "Click Cancel to try again."), QMessageBox::Cancel);
                    }

                }

                if (!qry3.exec())
                {
                    qDebug("error adding to db");
                }







}

void MainWindow::on_StatHallButton_clicked()
{
    Hall H;

    QPieSeries *series = new QPieSeries();
            QSqlQuery query;
                    query=H.statHall();
            while(query.next())
            {
                series->append(query.value(0).toString(),query.value(1).toInt());
            }

            QChart * chart=new  QChart();
            chart->addSeries(series);
            chart->setTitle("Halls stats");

            QChartView * chartView=new QChartView(chart);
            chartView ->setParent(ui->horizontalFrame);
            chartView->setFixedSize(ui->horizontalFrame->size());
            ui->stackedWidget->setCurrentIndex(17);


}

void MainWindow::on_HallStatBackButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);

}

void MainWindow::on_StatDecoratorButton_clicked()
{
    Decorator D;

    QPieSeries *series = new QPieSeries();
            QSqlQuery query;
                    query=D.statDecorator();
            while(query.next())
            {
                series->append(query.value(5).toString(),query.value(4).toInt());
            }

            QChart * chart=new  QChart();
            chart->addSeries(series);
            chart->setTitle("Decorators stats");

            QChartView * chartView=new QChartView(chart);
            chartView ->setParent(ui->horizontalFrame_2);
            chartView->setFixedSize(ui->horizontalFrame_2->size());
            ui->stackedWidget->setCurrentIndex(18);
}

void MainWindow::on_DecoratorStatBackButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);

}



void MainWindow::on_MailHallButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(19);
}

void MainWindow::on_hall_mail_send_button_clicked()
{
    if (!ui->hall_mail_to_line->text().contains("@") || !ui->hall_mail_to_line->text().contains("."))
    {
        QMessageBox::critical(nullptr, QObject::tr("Mail"),
                              QObject::tr("Email  doesn't exist.\n"
                                          "Click Cancel to try again."), QMessageBox::Cancel);

        return ;
    }

    msg=ui->hall_mail_plainText->toPlainText();

    if(msg.isEmpty())
    {
        QMessageBox::critical(nullptr, QObject::tr("Mail"),
                              QObject::tr("Empty mail.\n"
                                          "Click Cancel to try again."), QMessageBox::Cancel);

        return ;

    }

    smtp = new Smtp("smartwedding.esprit@gmail.com" , "esprit20", "smtp.gmail.com",465);
        connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


        smtp->sendMail("smartwedding.esprit@gmail.com",ui->hall_mail_to_line->text(),ui->hall_mail_subject_line->text(),msg);

        on_MailHallPrint_clicked();



        //ui->stackedWidget->setCurrentIndex(11);
}


void MainWindow::on_DecoratorStatBackButton_2_clicked()
{
    // HallMailBackButton

    ui->stackedWidget->setCurrentIndex(11);

}


void MainWindow::on_MailDecoratorBackButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);

}

void MainWindow::on_MailDecoratorButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(20);

}




void MainWindow::on_decorator_mail_send_button_clicked()
{
    if (!ui->decorator_mail_to_line->text().contains("@") || !ui->decorator_mail_to_line->text().contains("."))
        {
            QMessageBox::critical(nullptr, QObject::tr("Mail"),
                                  QObject::tr("Email  doesn't exist.\n"
                                              "Click Cancel to try again."), QMessageBox::Cancel);

            return ;
        }

        msg=ui->decorator_mail_plainText->toPlainText();


        if(msg.isEmpty())
        {
            QMessageBox::critical(nullptr, QObject::tr("Mail"),
                                  QObject::tr("Empty mail.\n"
                                              "Click Cancel to try again."), QMessageBox::Cancel);

            return ;

        }

        smtp = new Smtp("smartwedding.esprit@gmail.com" , "esprit20", "smtp.gmail.com",465);
            connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


            smtp->sendMail("smartwedding.esprit@gmail.com",ui->decorator_mail_to_line->text(),ui->decorator_mail_subject_line->text(),msg);



}

void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
}


void MainWindow::on_back_from_delete_client_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_back_from_yassine_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////aziz ############################################################


void MainWindow::on_traiteur_edit_clicked()
{

ui->stackedWidget->setCurrentIndex(22);


}

void MainWindow::on_fermer_clicked()
{
    close();
}


void MainWindow::on_ajouter_traiteur_clicked()
{

    ui->stackedWidget->setCurrentIndex(24);
}

void MainWindow::on_cancel_clicked()
{
    ui->stackedWidget->setCurrentIndex(22);

}

void MainWindow::on_produit_edit_clicked()
{
    ui->stackedWidget->setCurrentIndex(23);

}

void MainWindow::on_cancel_P_clicked()
{
    ui->stackedWidget->setCurrentIndex(23);

}


void MainWindow::on_ajoute_produit_clicked()
{
    ui->stackedWidget->setCurrentIndex(25);

}
bool MainWindow::verif_trait(QString id,QString nom,QString num,QString email,QString adresse)
{ bool verification=true;
    int k,N;
    k=id.toInt();
    N=num.toInt();
    if(k==0)
    {
        ui->IDEdit->clear();
        ui->IDEdit->setText("l'identifiant contien que des chiffres");
        verification=false;
    }
    if(nom=="")
    {
        ui->nameEdit->clear();

          ui->nameEdit->setText("il faut remplire le nom5");
          verification=false;

    }
    QString ch;
            ch=ui->nameEdit->text();
            bool test=true;
            int i=0;
            while(i<ch.size() && test==true)
            {
                if(ch[i].isLetter())
                  {  i++;
                    test=true;

                }
                else {
                    test=false;
                  verification=false;
                  ui->nameEdit->setText("verifier le nom");
                }
            }
   if(N==0)
   {
       ui->phoneEdit->clear();
       ui->phoneEdit->setText("verifier le numero");
       verification=false;
   }
   int x=0;
   for(int i=0;i<email.size();i++)
   {
if(email.at(i)=='@')
{

x++;
    }
   }
   if((x<1)||(x>1))
   {
       ui->emailEdit->clear();

         ui->emailEdit->setText("verifier l'email");
         verification=false;
   }
   if(adresse=="")
   {
       ui->adresseEdit->clear();

         ui->adresseEdit->setText("il faut remplire l'adresse");
         verification=false;

   }

    return verification;

}
bool MainWindow::verif_prod(QString id ,QString nom ,QString prix,QString id_t)
{
bool verification=true;
   int k,N;
   k=id.toInt();
   N=prix.toInt();
   if(k==0)
   {
       ui->identifier_edit->clear();
       ui->identifier_edit->setText("l'identifiant contien que des chiffres");
       verification=false;
   }
   if(nom=="")
   {
       ui->namePEdit->clear();

         ui->namePEdit->setText("il faut remplire le nom");
         verification=false;

   }
   QString ch;
           ch=ui->namePEdit->text();
           bool test=true;
           int i=0;
           while(i<ch.size() && test==true)
           {
               if(ch[i].isLetter())
                 {  i++;
                   test=true;

               }
               else {
                   test=false;
                 verification=false;
                 ui->namePEdit->setText("verifier le nom");
               }
           }
   if(N==0)
   {
       ui->priceEdit->clear();
       ui->priceEdit->setText("verifier le prix");
       verification=false;
   }

   if(id_t=="")
   {
       ui->idencatprod->clear();

         ui->idencatprod->setText("il faut remplire l'id");
         verification=false;

   }

    return verification;
}
//ajouter un traiteur
void MainWindow::on_green_add_clicked()
{

    traiteur t;
   if(verif_trait(ui->IDEdit->text(),ui->nameEdit->text(),ui->phoneEdit->text(),ui->emailEdit->text(),ui->adresseEdit->text())==true)
   {
t.setIDTrait(ui->IDEdit->text());
t.setNomTrait(ui->nameEdit->text());
t.setNumTrait(ui->phoneEdit->text());
t.setEmailTrait(ui->emailEdit->text());
t.setAdressTrait(ui->adresseEdit->text());

t.addtraiteur();
ui->IDEdit->clear();
ui->nameEdit->clear();
ui->phoneEdit->clear();
ui->emailEdit->clear();
ui->adresseEdit->clear();
ui->stackedWidget->setCurrentIndex(22);
   }


}
void MainWindow::on_green_addP_clicked()
{
    Produit p;
    if(verif_prod(ui->identifier_edit->text(),ui->namePEdit->text(),ui->priceEdit->text(),ui->idencatprod->text()))
   { p.setIDprod(ui->identifier_edit->text());
    p.setNOMprod(ui->namePEdit->text());
    p.setPRIXprod(ui->priceEdit->text());
    p.setTYPEprod(ui->typeBox->currentText());
    p.setIDTRAITprod(ui->idencatprod->text());
p.addproduit();
    }
    ui->identifier_edit->clear();
    ui->namePEdit->clear();
    ui->priceEdit->clear();
    ui->idencatprod->clear();
    ui->stackedWidget->setCurrentIndex(23);

}

void MainWindow::on_BACK5_clicked()
{ // back from from update caterer to caterer (crud)
    ui->stackedWidget->setCurrentIndex(22);

}

void MainWindow::on_list_traiteurs_clicked()
{

traiteur t;
        ui->stackedWidget->setCurrentIndex(27);
        ui->essai_table->setModel(t.afficher(0,"null"));
         ui->essai_table->resizeRowsToContents();
         ui->essai_table->resizeColumnsToContents();
         ui->essai_table->show();


}

void MainWindow::on_BACK1_clicked()
{ // back from caterer (crud) to intial
    ui->stackedWidget->setCurrentIndex(21);

}

void MainWindow::on_BACK2_clicked()
{// back from product (crud) to intial
    ui->stackedWidget->setCurrentIndex(21);

}

void MainWindow::on_BACK3_clicked()
{ // back from from add caterer to caterer (crud)
    ui->stackedWidget->setCurrentIndex(22);

}

void MainWindow::on_BACK4_clicked()
{ // back from  add product to product (crud)
    ui->stackedWidget->setCurrentIndex(23);

}

void MainWindow::on_BACK6_clicked()
{// back from list caterer to caterer (crud)
    ui->stackedWidget->setCurrentIndex(22);

}

void MainWindow::on_modifier_traiter_clicked()
{
    ui->stackedWidget->setCurrentIndex(26);
   // initialiserUpdate();

    initialiserUpdatetrait();


}


void MainWindow::initialiserUpdatetrait( )
{

    traiteur t;

   ui->essai_table->setModel(t.afficher(0,"null"));


            ui->aff_trait->setRowCount(0);

         for( int row = 0; row < ui->essai_table->model()->rowCount(); ++row )
          {ui->aff_trait->insertRow(ui->aff_trait->rowCount());
    for( int col = 0; col < ui->essai_table->model()->columnCount(); ++col )
            {
             QModelIndex index =ui->essai_table->model()->index(row,col);
         ui->aff_trait->setItem(row,col,new QTableWidgetItem(index.data().toString()));
         ui->aff_trait->setItem(row,col,new QTableWidgetItem(index.data().toString()));
         ui->aff_trait->setItem(row,col,new QTableWidgetItem(index.data().toString()));
         ui->aff_trait->setItem(row,col,new QTableWidgetItem(index.data().toString()));
         ui->aff_trait->setItem(row,col,new QTableWidgetItem(index.data().toString()));
         QIcon MAJ("C:/Users/hp/Desktop/projet c++/traiteur/poubelle.jpg");

         QTableWidgetItem *MAJ_item = new QTableWidgetItem;

              MAJ_item->setIcon(MAJ);
              ui->aff_trait->setItem(row,5, MAJ_item);

              ui->aff_trait->resizeColumnsToContents();
            }
         }
}
void MainWindow::on_aff_trait_cellChanged(int row, int column)
{ traiteur t;
qDebug()<< "entrer";


                    const QAbstractItemModel *model = ui->aff_trait->model();
                  const QString identifiant = model->data(model->index(row, 0), Qt::DisplayRole).toString();

                  const QString nom = model->data(model->index(row, 1), Qt::DisplayRole).toString();
                    const QString numero = model->data(model->index(row, 2), Qt::DisplayRole).toString();
                    const QString email = model->data(model->index(row, 3), Qt::DisplayRole).toString();
                    const QString adresse = model->data(model->index(row, 4), Qt::DisplayRole).toString();
                    t.update_T(identifiant,nom,numero,email,adresse,column);

}

void MainWindow::essaiaff()
{}
void MainWindow::on_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(24);

}

void MainWindow::on_BACK7_clicked()
{
    ui->stackedWidget->setCurrentIndex(23);

}


void MainWindow::on_aff_trait_cellClicked(int row, int column)
{ traiteur t;
    const QAbstractItemModel *model = ui->aff_trait->model();
  const QString identifiant = model->data(model->index(row, 0), Qt::DisplayRole).toString();
if(column==5)
{
    QMediaPlayer *player = new QMediaPlayer;
        player->setMedia(QUrl::fromLocalFile("C:/Users/hp/Desktop/projet c++/traiteur/sound.mp3"));
        player->setVolume(50);
        player->play();
    t.effacer(identifiant);
    initialiserUpdatetrait();

}
}

void MainWindow::on_list_produit_clicked()
{
    Produit p;
            ui->stackedWidget->setCurrentIndex(28);
            ui->affiche_tablePR->setModel(p.afficher(0,"null"));
           // ui->affiche_tablePR->setModel(p.stat("123456",1));

            ui->affiche_tablePR->resizeRowsToContents();
             ui->affiche_tablePR->resizeColumnsToContents();
             ui->affiche_tablePR->show();
}
void MainWindow::initialiserUpdateprod()
{

   Produit p;
   QStringList entet;
   entet <<"   Identifiant " <<"  Name  "<<" Type "<<" price "<<" Id_traiteur    "<<"delete";
   ui->update_tablePR->setColumnCount(6);
   ui->update_tablePR->setHorizontalHeaderLabels(entet);
   ui->update_tablePR->resizeColumnsToContents();

  ui->affiche_tablePR->setModel(p.afficher(0,"null"));


            ui->update_tablePR->setRowCount(0);

         for( int row = 0; row < ui->affiche_tablePR->model()->rowCount(); ++row )
          {ui->update_tablePR->insertRow(ui->update_tablePR->rowCount());
    for( int col = 0; col < ui->affiche_tablePR->model()->columnCount(); ++col )
            {
             QModelIndex index =ui->affiche_tablePR->model()->index(row,col);
         ui->update_tablePR->setItem(row,col,new QTableWidgetItem(index.data().toString()));
         ui->update_tablePR->setItem(row,col,new QTableWidgetItem(index.data().toString()));
         ui->update_tablePR->setItem(row,col,new QTableWidgetItem(index.data().toString()));
         ui->update_tablePR->setItem(row,col,new QTableWidgetItem(index.data().toString()));
         ui->update_tablePR->setItem(row,col,new QTableWidgetItem(index.data().toString()));
         QIcon MAJ("C:/Users/hp/Desktop/projet c++/traiteur/poubelle.jpg");

         QTableWidgetItem *MAJ_item = new QTableWidgetItem;

              MAJ_item->setIcon(MAJ);
              ui->update_tablePR->setItem(row,5, MAJ_item);
              ui->update_tablePR->resizeColumnsToContents();
            }
         }
}

void MainWindow::on_modifie_produit_clicked()
{
    ui->stackedWidget->setCurrentIndex(29);

    initialiserUpdateprod();

}

void MainWindow::on_BACK8_clicked()
{// back from update prod to prod (crud)

    ui->stackedWidget->setCurrentIndex(23);

}

void MainWindow::on_update_tablePR_cellChanged(int row, int column)
{ Produit p;
    const QAbstractItemModel *model = ui->update_tablePR->model();
  const QString identifiant = model->data(model->index(row, 0), Qt::DisplayRole).toString();

  const QString nom = model->data(model->index(row, 1), Qt::DisplayRole).toString();
    const QString type = model->data(model->index(row, 2), Qt::DisplayRole).toString();
    const QString prix = model->data(model->index(row, 3), Qt::DisplayRole).toString();
    const QString idtrait = model->data(model->index(row, 4), Qt::DisplayRole).toString();
   p.update_P(identifiant ,nom , type, prix, idtrait , column);
}

void MainWindow::on_update_tablePR_cellClicked(int row, int column)
{ Produit p;
    const QAbstractItemModel *model = ui->update_tablePR->model();
  const QString identifiant = model->data(model->index(row, 0), Qt::DisplayRole).toString();
if(column==5)
{
    QMediaPlayer *player = new QMediaPlayer;
        player->setMedia(QUrl::fromLocalFile("C:/Users/hp/Desktop/projet c++/traiteur/sound.mp3"));
        player->setVolume(50);
        player->play();
    p.effacer(identifiant);
    initialiserUpdateprod();

}
}

void MainWindow::on_triTrait_currentIndexChanged(int index)
{qDebug()<< index;
    traiteur t;
    ui->essai_table->setModel(t.afficher(index,"null"));
         ui->essai_table->resizeRowsToContents();
         ui->essai_table->resizeColumnsToContents();
         ui->essai_table->show();


}






void MainWindow::on_rechercheLine_textChanged(const QString &arg1)
{
    traiteur t;

    ui->essai_table->setModel(t.afficher(5,arg1));

    qDebug()<< ui->rechercheLine->text();
         ui->essai_table->resizeRowsToContents();
         ui->essai_table->resizeColumnsToContents();
         ui->essai_table->show();
}

void MainWindow::on_triProd_currentIndexChanged(int index)
{
    Produit p;
            ui->affiche_tablePR->setModel(p.afficher(index,"null"));
             ui->affiche_tablePR->resizeRowsToContents();
             ui->affiche_tablePR->resizeColumnsToContents();
             ui->affiche_tablePR->show();
}

void MainWindow::on_rechercheLine_2_textChanged(const QString &arg1)
{
    Produit p;
            ui->affiche_tablePR->setModel(p.afficher(5,arg1));
             ui->affiche_tablePR->resizeRowsToContents();
             ui->affiche_tablePR->resizeColumnsToContents();
             ui->affiche_tablePR->show();
}

void MainWindow::on_statisticP_clicked()
{
    ui->stackedWidget->setCurrentIndex(30);

}

void MainWindow::on_imprimer_TRAIT_clicked()
{
    QPrinter printer(QPrinter::HighResolution);


    printer.setOrientation(QPrinter::Landscape);
            QPrintDialog *dialog = new QPrintDialog(&printer, this);
            dialog->setWindowTitle(tr("Print Document"));
             dialog->addEnabledOption(QAbstractPrintDialog::PrintSelection);

                printer.setOutputFileName("print.ps");
                QPainter painter;

     painter.begin(&printer);


        int    numberOfPages=1;
                for (int page = 0; page < numberOfPages; ++page) {

                    // Utilisez l'imprimante pour dessiner sur la page.

                    if (page != numberOfPages)
                      {painter.setFont(QFont("Arial",20));

                        painter.drawText(width()/2,height()/2, (""));
                       // painter.drawImage()
                              double xscale = printer.pageRect().width()/double(  ui->stackedWidget->width());
                                double yscale = printer.pageRect().height()/double( ui->stackedWidget->height());
                                double scale = qMin(xscale, yscale);
                                painter.translate(printer.paperRect().x() + printer.pageRect().width()/2,
                                                   printer.paperRect().y() + printer.pageRect().height()/2);
                                painter.scale(scale, scale);
                                painter.translate(-width()/2, -height()/2);

                                 ui->stackedWidget->render(&painter);


                    }


                }

                painter.end();
}

void MainWindow::on_stat_clicked()
{       ui->stackedWidget->setCurrentIndex(31);

      QLineEdit text1;

     Produit p;

            QBarSet *set0 = new QBarSet("chaud");
            QBarSet *set1 = new QBarSet("froid");
            QBarSet *set2 = new QBarSet("sucrée");
            QBarSet *set3 = new QBarSet("salee");
    QString identifiant_1=ui->identifiant_1->text();
    QString identifiant_2=ui->identifiant_2->text();
    QString identifiant_3=ui->identifiant_3->text();
    QString identifiant_4=ui->identifiant_4->text();
    QString identifiant_5=ui->identifiant_5->text();

                            for(int i=1;i<5;i++)
                            {

                                    text1.setText(p.stat(identifiant_1,i)->index(0 , 0).data().toString());
                                   int k1=text1.text().toInt();
                                     text1.setText(p.stat(identifiant_2,i)->index(0 , 0).data().toString());
                                      int k2=text1.text().toInt();
                                          text1.setText(p.stat(identifiant_3,i)->index(0 , 0).data().toString());
                                         int k3=text1.text().toInt();
                                             text1.setText(p.stat(identifiant_4,i)->index(0 , 0).data().toString());
                                            int k4=text1.text().toInt();
                                            text1.setText(p.stat(identifiant_5,i)->index(0 , 0).data().toString());
                                           int k5=text1.text().toInt();
                                            if(i==1)
                                            {
                                              *set0 << k1 << k2 << k3 << k4 << k5 ;
                                            }
                                            else if (i==2)
                                            {
                                                *set1 << k1 << k2 << k3 << k4 << k5 ;

                                            }
                                            else if( i==3)
                                            {
                                                *set2 << k1 << k2 << k3 << k4 << k5 ;

                                            }
                                            else if(i==4)
                                            {
                                                *set3 << k1 << k2 << k3 << k4 << k5 ;
                                            }


                            }



            QBarSeries *series = new QBarSeries();
            series->append(set0);
            series->append(set1);
            series->append(set2);
            series->append(set3);


            QChart *chart = new QChart();
            chart->addSeries(series);
            chart->setTitle("statistique des poroduits préparés par chaque traiteur");
            chart->setAnimationOptions(QChart::SeriesAnimations);

            QStringList categories;

            categories << ui->identifiant_1->text() << ui->identifiant_2->text() << ui->identifiant_3->text() << ui->identifiant_4->text() << ui->identifiant_5->text() ;
            QBarCategoryAxis *axis = new QBarCategoryAxis();
            axis->append(categories);
            chart->createDefaultAxes();
            chart->setAxisX(axis, series);

            chart->legend()->setVisible(true);
            chart->legend()->setAlignment(Qt::AlignBottom);

            QChartView *chartView = new QChartView(chart);
            chartView->setRenderHint(QPainter::Antialiasing);

    ui->graphicsView->setChart(chart);
            ui->graphicsView->setMinimumSize(420,300);
            ui->graphicsView->show();


}

void MainWindow::on_BACK10_clicked()
{
    ui->stackedWidget->setCurrentIndex(30);
    ui->identifiant_1->clear();
    ui->identifiant_2->clear();
    ui->identifiant_3->clear();
    ui->identifiant_4->clear();
    ui->identifiant_5->clear();
}

void MainWindow::on_BACK9_clicked()
{
    ui->stackedWidget->setCurrentIndex(23);

}

void MainWindow::on_imprimerPROD_clicked()
{

    QPrinter printer(QPrinter::HighResolution);


    printer.setOrientation(QPrinter::Landscape);
            QPrintDialog *dialog = new QPrintDialog(&printer, this);
            dialog->setWindowTitle(tr("Print Document"));
             dialog->addEnabledOption(QAbstractPrintDialog::PrintSelection);

                printer.setOutputFileName("print.ps");
                QPainter painter;

     painter.begin(&printer);


        int    numberOfPages=1;
                for (int page = 0; page < numberOfPages; ++page) {

                    // Utilisez l'imprimante pour dessiner sur la page.

                    if (page != numberOfPages)
                      {painter.setFont(QFont("Arial",20));

                        painter.drawText(width()/2,height()/2, (""));
                       // painter.drawImage()
                              double xscale = printer.pageRect().width()/double(  ui->stackedWidget->width());
                                double yscale = printer.pageRect().height()/double( ui->stackedWidget->height());
                                double scale = qMin(xscale, yscale);
                                painter.translate(printer.paperRect().x() + printer.pageRect().width()/2,
                                                   printer.paperRect().y() + printer.pageRect().height()/2);
                                painter.scale(scale, scale);
                                painter.translate(-width()/2, -height()/2);

                                 ui->stackedWidget->render(&painter);


                    }


                }

                painter.end();
}
void MainWindow::initialiserclientproduit()
{
   prod_client pc;
   ui->clientproduittable->setModel(pc.afficherpc(ui->comboBox_client_produit->currentText(),ui->nbr->text().toInt()));
   ui->clientproduittable->resizeRowsToContents();
   ui->clientproduittable->resizeColumnsToContents();
ui->nbr->setText("1");
calcule_de_facture();

}
void MainWindow::on_temporaire_clicked()
{

    Produit p;

    prod_client p_c;

    QSqlQuery* qry = p_c.afficher_client_pour_poduit();

    while ( qry->next() )
    {
        ui->comboBox_client_produit->addItem(qry->value(11).toString());
    }
     initialiserclientproduit();
        QStringList entet;
        entet <<"   Identifiant " <<"  Name  "<<" Type "<<" price "<<" Id_traiteur    "<<"ajouter";
        ui->acheter_prod->setColumnCount(6);
        ui->acheter_prod->setHorizontalHeaderLabels(entet);
        ui->acheter_prod->resizeColumnsToContents();

        ui->affiche_tablePR->setModel(p.afficher(0,"null"));

                 ui->acheter_prod->setRowCount(0);


              for( int row = 0; row < ui->affiche_tablePR->model()->rowCount(); ++row )
               {ui->acheter_prod->insertRow(ui->acheter_prod->rowCount());
         for( int col = 0; col < ui->affiche_tablePR->model()->columnCount(); ++col )
                 {
                  QModelIndex index =ui->affiche_tablePR->model()->index(row,col);
              ui->acheter_prod->setItem(row,col,new QTableWidgetItem(index.data().toString()));
              ui->acheter_prod->setItem(row,col,new QTableWidgetItem(index.data().toString()));
              ui->acheter_prod->setItem(row,col,new QTableWidgetItem(index.data().toString()));
              ui->acheter_prod->setItem(row,col,new QTableWidgetItem(index.data().toString()));
              ui->acheter_prod->setItem(row,col,new QTableWidgetItem(index.data().toString()));
              QIcon MAJ(":/add.png");

              QTableWidgetItem *MAJ_item = new QTableWidgetItem;

                   MAJ_item->setIcon(MAJ);
                   ui->acheter_prod->setItem(row,5, MAJ_item);
                   ui->acheter_prod->resizeColumnsToContents();
                 }
              }
              ui->stackedWidget->setCurrentIndex(32);

}

void MainWindow::on_acheter_prod_cellClicked(int row, int column)
{
    prod_client pc;
        const QAbstractItemModel *model = ui->affiche_tablePR->model();
        const QString idprod = model->data(model->index(row, 0), Qt::DisplayRole).toString();
    qDebug()<<idprod;
    if(column==5)
    {
        pc.setIDclient(ui->comboBox_client_produit->currentText());

    pc.setIDprod(idprod);
    pc.addprod_client();
    initialiserclientproduit();
    calcule_de_facture();

    }
}

void MainWindow::on_BACK12_clicked()
{
    ui->stackedWidget->setCurrentIndex(21);
    ui->comboBox_client_produit->clear();
    ui->clientproduittable->clearSpans();
}







void MainWindow::on_aziz_clicked()
{
    ui->stackedWidget->setCurrentIndex(21);


}

void MainWindow::on_back_to_aziz_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
}


void MainWindow::on_MailHallPrint_clicked()
{
    QPrinter printer;
        printer.setPrinterName("Mail");
        QPrintDialog dialog(&printer,this);
        if ( dialog.exec()== QDialog::Rejected) return ;

        QString to,subject,mail;


        to= ui->hall_mail_to_line->text();
        subject=ui->hall_mail_subject_line->text();
        mail = ui->hall_mail_plainText->toPlainText();



        QPainter painter(this);
        painter.begin(&printer);


        QFont font = painter.font();
        font.setPointSize(font.pointSize() * 2);
        painter.setFont(font);
        QImage image(":/email_icon.png");
        painter.setPen(Qt::cyan);
        painter.drawImage(380,30,image);

        painter.drawText(230,90,"Mail");
        painter.setPen(Qt::darkBlue);

        painter.drawText(130,160,"To: ");
        painter.drawText(130,185,"Subject: ");
        painter.drawText(130,210,"Mail: ");



        painter.setPen(Qt::black);

        painter.drawText(300,160,to);
        painter.drawText(300,185,subject);
        painter.drawText(300,210,mail);






        painter.end();


         ui->stackedWidget->setCurrentIndex(11);
}
void MainWindow::calcule_de_facture()
{ prod_client cp;
  QString id=ui->comboBox_client_produit->currentText() ;
  QSqlQuery  query=cp.imprimeretcalcule(id);
int somme=0;
  while (query.next())
            {

             int prix = query.value(2).toInt();
             somme=somme+prix;
              qDebug() <<prix<<somme<< endl;


  }
int k=ui->nbr->text().toInt();
somme=somme*k;
QString resulta=QString::number(somme);

ui->prix_finale->setText(resulta);
}


void MainWindow::on_nbr_editingFinished()
{
    calcule_de_facture();

}

void MainWindow::on_imprimerFACTURE_clicked()
{
    prod_client cp;
     QString id=ui->comboBox_client_produit->currentText() ;
     QSqlQuery  query=cp.imprimeretcalcule(id);
   int somme=0;
   QPdfWriter pdf1("C:/Users/hp/Desktop/projet/Smart_wedding_planner_2A3/Exportation.pdf");
   QPainter painter (&pdf1);
int x=2000;
painter.setPen(Qt::blue);
painter.drawText(4500,500,"facture ");
painter.drawText(500,2000,"IDENTIFIANT ");
painter.drawText(1500,2000,"NOM DE PRODUIT");
painter.drawText(2500,2000,"PRIX DE PRODUIT");

     while (query.next())
               {
x=x+500;
painter.setPen(Qt::darkGreen);

                int prix = query.value(2).toInt();
                somme=somme+prix;
                 qDebug() <<prix<<somme<< endl;
                 QString identifiant = query.value(0).toString();
                               QString nom = query.value(1).toString();
                               QString prix1 = query.value(2).toString();
                 painter.drawText(500,x,identifiant);
                 painter.drawText(1500,x,nom);
                 painter.drawText(2500,x,prix1);


     }
   int k=ui->nbr->text().toInt();
   somme=somme*k;
   QString resulta=QString::number(somme);
   painter.drawText(500,x+2000,"la somme de votre facture est ");
   painter.drawText(3500,x+2000,resulta);
   painter.drawText(500,x+1000,"la quantitée a achetée est  ");
   painter.drawText(3500,x+1000,ui->nbr->text());

}
void MainWindow::reclamation()
{
Arduino a;
QByteArray rec = a.read_from_arduino();
qDebug() << rec;

//ui->reclame->setText(rec);

}
