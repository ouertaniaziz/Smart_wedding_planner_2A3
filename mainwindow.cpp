#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"traiteur.h"
#include"produit.h"

#include <QApplication>
#include <QTableWidget>
#include <QStandardItemModel>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStringList Titres;
    Titres <<"   Identifiant " <<"  Name  "<<" Phone "<<" Adresse   "<<" Email    "<<"delete";
    ui->aff_trait->setColumnCount(6);
    ui->aff_trait->setHorizontalHeaderLabels(Titres);
    ui->aff_trait->resizeColumnsToContents();
    initialiserUpdate();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_traiteur_edit_clicked()
{

ui->stackedWidget->setCurrentIndex(1);


}

void MainWindow::on_fermer_clicked()
{
    close();
}


void MainWindow::on_ajouter_traiteur_clicked()
{

    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_cancel_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_produit_edit_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}

void MainWindow::on_cancel_P_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}


void MainWindow::on_ajoute_produit_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);

}


//ajouter un traiteur
void MainWindow::on_green_add_clicked()
{

    traiteur t;
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
ui->stackedWidget->setCurrentIndex(1);

}
void MainWindow::on_green_addP_clicked()
{
    Produit p;
    p.setIDprod(ui->identifier_edit->text());
    p.setNOMprod(ui->namePEdit->text());
    p.setPRIXprod(ui->priceEdit->text());
   // p.setTYPEprod(ui->typeBox->findText());
    p.setIDTRAITprod(ui->idencatprod->text());
p.addproduit();
    ui->identifier_edit->clear();
    ui->namePEdit->clear();
    ui->priceEdit->clear();
    ui->idencatprod->clear();
    ui->stackedWidget->setCurrentIndex(2);

}

void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_list_traiteurs_clicked()
{

traiteur t;
        ui->stackedWidget->setCurrentIndex(6);
        ui->essai_table->setModel(t.afficher());
         ui->essai_table->resizeRowsToContents();
         ui->essai_table->resizeColumnsToContents();
         ui->essai_table->show();


}

void MainWindow::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}

void MainWindow::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_modifier_traiter_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
   // initialiserUpdate();








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
void MainWindow::initialiserUpdate(  )
{
/*  traiteur t;



QSqlQuery query;
ui->aff_trait->setRowCount(0);
       query.exec( "SELECT ID_TRAIT,NOM_TRAIT,NUM_TRAIT,EMAIL_TRAIT,ADRESSE_TRAIT FROM TRAITEUR " );

           while((query.next()))
           {

               ui->aff_trait->insertRow(ui->aff_trait->rowCount());
               qDebug()<<(ui->aff_trait->rowCount());
               int ligne=ui->aff_trait->rowCount()-1;
                 QString identifiant = query.value(0).toString();
                 QString Name = query.value(1).toString();
                 QString Numero = query.value(2).toString();
                 QString email = query.value(3).toString();
                 QString adresse = query.value(4).toString();
                 ui->aff_trait->setItem(ligne,0,new QTableWidgetItem(identifiant));
                 ui->aff_trait->setItem(ligne,1,new QTableWidgetItem(Name));
                 ui->aff_trait->setItem(ligne,2,new QTableWidgetItem(Numero));
                 ui->aff_trait->setItem(ligne,3,new QTableWidgetItem(email));
                 ui->aff_trait->setItem(ligne,4,new QTableWidgetItem(adresse));
                 QIcon MAJ("C:/Users/hp/Desktop/projet c++/traiteur/poubelle.png");

                 QTableWidgetItem *MAJ_item = new QTableWidgetItem;

                      MAJ_item->setIcon(MAJ);
                     ui->aff_trait->setIconSize(QSize(100, 30));
                      ui->aff_trait->setItem(ligne,5, MAJ_item);
                      ui->aff_trait->resizeColumnsToContents();
              }
*/

}
void MainWindow::essaiaff()
{


}

void MainWindow::on_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);

}

void MainWindow::on_pushButton_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);

}

