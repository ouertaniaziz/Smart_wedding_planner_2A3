#include "deletedecorator.h"
#include "ui_deletedecorator.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>
#include <QSqlQueryModel>
#include "connection.h"
#include "decorator.h"


#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>


DeleteDecorator::DeleteDecorator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteDecorator)
{
    ui->setupUi(this);
}

DeleteDecorator::~DeleteDecorator()
{
    delete ui;
}

void DeleteDecorator::on_DeleteHallButton_clicked()
{
    if(ui->decorator_id_line->text()=="")
    {
        ui->decorator_id_line->setStyleSheet(QString("	border: 2px solid #e30000;"
                                                "  border-radius: 8px;"
                                                  "padding-left: 20px;"
                                                  "padding-right: 20px;"
                                                  "background-color: rgb(255,255,255);"));
        return;
   }


    Decorator D(ui->decorator_id_line->text(),
           "",
           "",
           "",
           "",
           "",
           ""
           );



            bool test=D.deleteDecorator();

            if(test)
            {
                accept();
            }


}

void DeleteDecorator::on_CancelButton_clicked()
{
    accept();
}
