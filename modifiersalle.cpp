#include "modifiersalle.h"
#include "ui_modifiersalle.h"
#include "salle.h"

ModifierSalle::ModifierSalle(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ModifierSalle)
{
    ui->setupUi(this);
}

ModifierSalle::~ModifierSalle()
{
    delete ui;
}

void ModifierSalle::on_RetourButton_clicked()
{
    Salle  w;
    w.show();
}
