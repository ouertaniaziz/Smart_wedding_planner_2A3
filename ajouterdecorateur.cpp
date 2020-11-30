#include "ajouterdecorateur.h"
#include "ui_ajouterdecorateur.h"
#include "salle.h"

AjouterDecorateur::AjouterDecorateur(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AjouterDecorateur)
{
    ui->setupUi(this);
}

AjouterDecorateur::~AjouterDecorateur()
{
    delete ui;
}

void AjouterDecorateur::on_RetourButton_clicked()
{
    Salle w;
    w.show();
}
