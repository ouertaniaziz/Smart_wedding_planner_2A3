#include "salle.h"
#include "ui_salle.h"
#include <QPixmap>
#include <QMessageBox>
#include <QtCore>
#include <QtGui>
#include "ajouterdecorateur.h"
#include "ui_ajouterdecorateur.h"
#include "mainwindow.h"





Salle::Salle(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Salle)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/Deadly/Desktop/Fac/2A/Projet/Qt/ProjetFac/Img/phone");
    ui->label_8->setPixmap(pix);


    QPixmap pix2("C:/Users/Deadly/Desktop/Fac/2A/Projet/Qt/ProjetFac/Img/nofav");
}

Salle::~Salle()
{
    delete ui;
}





void Salle::on_RetourButton_clicked()
{
    MainWindow w;
    w.show();
}
