#include "deletehall.h"
#include "ui_deletehall.h"


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>
#include <QSqlQueryModel>
#include "connection.h"
#include "hall.h"

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

DeleteHall::DeleteHall(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteHall)
{
    ui->setupUi(this);
}

DeleteHall::~DeleteHall()
{
    delete ui;
}

void DeleteHall::on_DeleteHallButton_clicked()
{


    if(ui->hall_id_line->text()=="")
    {
        ui->hall_id_line->setStyleSheet(QString("	border: 2px solid #e30000;"
                                                "  border-radius: 8px;"
                                                  "padding-left: 20px;"
                                                  "padding-right: 20px;"
                                                  "background-color: rgb(255,255,255);"));
        return;
   }


    Hall H(ui->hall_id_line->text(),
           "",
           "",
           "",
           "",
           "",
           "",
           ""

           );



            bool test=H.deleteHall();

            if(test)
            {
                accept();
            }



}

void DeleteHall::on_CancelButton_clicked()
{
    accept();
}
