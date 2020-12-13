#include "modifierdecorateur.h"
#include "ui_modifierdecorateur.h"
#include "salle.h"

ModifierDecorateur::ModifierDecorateur(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ModifierDecorateur)
{
    ui->setupUi(this);
}

ModifierDecorateur::~ModifierDecorateur()
{
    delete ui;
}

void ModifierDecorateur::on_RetourButton_clicked()
{
    Salle w;
    w.show();
}
