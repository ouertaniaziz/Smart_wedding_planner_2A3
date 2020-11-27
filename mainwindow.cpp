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


    ui->tableWidget->setColumnWidth(1,196);








}

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

        qry.prepare("SELECT * FROM CLIENT_MARRIAGE WHERE CIN_M =:cin");
        qry.bindValue(":cin",C.get_cin_m());

        if (qry.exec())
        {
            int count(0);
            while(qry.next())
            {
                count++;
            }
            if (count == 0)
            {
                if (qry.exec("SELECT * FROM CLIENT_MARRIAGE"))
                {
                    int count1=0;
                    while(qry.next())
                    {
                        count1++;
                    }
                    count1+=1;


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
            }
            else
            {
                QMessageBox::critical(nullptr, QObject::tr("add to data base"),
                                      QObject::tr("CIN of male or female already exists.\n"
                                                  "Click Cancel to try again."), QMessageBox::Cancel);
            }

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
            qDebug() << "succes" << endl;
            ui->mariage_id->setText("");
            ui->stackedWidget->setCurrentIndex(1);
        }


    }
}

void MainWindow::afficher_table_marriage()
{
    QSqlQuery qry;


    if (qry.exec("SELECT * FROM CLIENT_MARRIAGE"))
    {
        int rowCount = 0;
        while(qry.next())
        {
            rowCount++;
        }

        for (int i =rowCount ; i>=0 ; i--)
            ui->tableWidget->removeRow(i);

    }

    if (qry.exec("SELECT * FROM CLIENT_MARRIAGE"))
    {
        int rowCount = 0;
        while(qry.next())
        {
            ui->tableWidget->insertRow(rowCount);
            QTableWidgetItem *ID = new QTableWidgetItem;
            QTableWidgetItem *Marriage = new QTableWidgetItem;
            QTableWidgetItem *Phone_Number = new QTableWidgetItem;
            QTableWidgetItem *Email = new QTableWidgetItem;
            QTableWidgetItem *Confirmation = new QTableWidgetItem;

            ID->setText(qry.value(11).toString());
            Marriage->setText(qry.value(1).toString()+" "+qry.value(0).toString()+" / "+qry.value(5).toString()+" "+qry.value(4).toString());
            Phone_Number->setText(qry.value(3).toString()+" / "+qry.value(7).toString());
            Email->setText(qry.value(9).toString());


            if ( qry.value(14).toString() == "1" )
            {
                Confirmation->setCheckState(Qt::Checked);
            }
            else
            {
                Confirmation->setCheckState(Qt::Unchecked);
            }


            ui->tableWidget->setItem(rowCount,0,ID);
            ui->tableWidget->setItem(rowCount,1,Marriage);
            ui->tableWidget->setItem(rowCount,2,Phone_Number);
            ui->tableWidget->setItem(rowCount,3,Email);
            ui->tableWidget->setItem(rowCount,4,Confirmation);

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
        QSqlQuery qry;

        qry.prepare("SELECT * FROM CLIENT_MARRIAGE WHERE ID_CLIENT =:id ");
        qry.bindValue(":id",ID);

        if (qry.exec())
        {

            int count(0);
            while(qry.next())
            {
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


                count++;
            }

            if ( count == 0)
            {
                QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                                      QObject::tr("ID doesn't exists.\n"
                                                  "Click Cancel to try again."), QMessageBox::Cancel);
            }

        }

        if (!qry.exec())
        {
            qDebug("error updating to db");
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

void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
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
        qDebug() << C.get_cin_m() << endl;
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
    QSqlQuery qry;
    qry.prepare("SELECT * FROM INVITE_MARRIAGE");

    if (qry.exec())
    {
        int rowCount = 0;
        while(qry.next())
        {
            rowCount++;
        }

        for (int i =rowCount ; i>=0 ; i--)
            ui->tableWidget_3->removeRow(i);

    }

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

    QSqlQuery qry;

    qry.prepare("SELECT * FROM CLIENT_MARRIAGE WHERE ID_CLIENT = :id_marriage");
    qry.bindValue(":id_marriage",marriage_id);

    if (qry.exec())
    {
        int rowCount = 0;
        while(qry.next())
        {
            rowCount++;
        }

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

}

void MainWindow::on_add_guest_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
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
    bool test = e.supprimer_invite(ui->guest_id->text());

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
    QString filter = ui->search_bar->text();
    for( int i = 0; i < ui->tableWidget->rowCount(); ++i )
    {
        bool match = false;
        for( int j = 0; j < ui->tableWidget->columnCount(); ++j )
        {
            QTableWidgetItem *item = ui->tableWidget->item( i, j );
            if( item->text().contains(arg1) )
            {
                match = true;
                break;
            }
        }
        ui->tableWidget->setRowHidden( i, !match );
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

    QSqlQuery qry;
    qry.prepare("SELECT * FROM INVITE_MARRIAGE WHERE ID_MARRIAGE= :id_m");
    qry.bindValue(":id_m",id_marriage);

    if ( qry.exec())
    {
        int count(0);
        while(qry.next())
        {
            count++;
        }
        count++;
        id_inv = QString::number(count);
        E.set_id_inv(id_inv);
        qDebug() << E.get_id_inv() << "and " << E.get_id_marriage() << endl;

    }



    bool valid = false;

    if ( E.get_email().contains("@gmail.com") )
    {
        valid = true;
    }

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
    else
    {
        QSqlQuery qry;
        qry.prepare("SELECT * FROM INVITE_MARRIAGE WHERE PHONE_INVITE= :phone");
        qry.bindValue(":phone",E.get_phone());

        if ( qry.exec())
        {
            int count(0);
            while(qry.next())
            {
                count++;
            }

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
}


void MainWindow::on_cancel_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
    ui->name_guest->setText("");
    ui->last_name_guest->setText("");
    ui->Phone_number_guest->setText("");
    ui->Email_guest->setText("");

}
