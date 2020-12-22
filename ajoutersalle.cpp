#include "ajoutersalle.h"
#include "ui_ajoutersalle.h"
#include "mainwindow.h"

AjouterSalle::AjouterSalle(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AjouterSalle)
{
    ui->setupUi(this);
}

AjouterSalle::~AjouterSalle()
{
    delete ui;
}

void AjouterSalle::on_RetourButton_clicked()
{
    MainWindow w;
    w.show();
}
