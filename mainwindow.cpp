#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"traiteur.h"
#include"produit.h"

#include <QApplication>
#include <QTableWidget>
//#include <QStandardItemModel>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStringList Titres;
    Titres <<"   Identifiant " <<"  Name  "<<" Phone "<<" Adresse   "<<" Email    "<<"delete";
    ui->aff_trait->setColumnCount(6);
    ui->aff_trait->setHorizontalHeaderLabels(Titres);
    ui->aff_trait->resizeColumnsToContents();

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
    p.setTYPEprod(ui->typeBox->currentText());
    p.setIDTRAITprod(ui->idencatprod->text());
p.addproduit();
    ui->identifier_edit->clear();
    ui->namePEdit->clear();
    ui->priceEdit->clear();
    ui->idencatprod->clear();
    ui->stackedWidget->setCurrentIndex(2);

}

void MainWindow::on_pushButton_2_clicked()
{ // back from from update caterer to caterer (crud)
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
{ // back from caterer (crud) to intial
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_pushButton_clicked()
{// back from product (crud) to intial
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_pushButton_4_clicked()
{ // back from from add caterer to caterer (crud)
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_pushButton_3_clicked()
{ // back from  add product to product (crud)
    ui->stackedWidget->setCurrentIndex(2);

}

void MainWindow::on_pushButton_6_clicked()
{// back from list caterer to caterer (crud)
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_modifier_traiter_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
   // initialiserUpdate();

    initialiserUpdatetrait();







}


void MainWindow::initialiserUpdatetrait( )
{

    traiteur t;

   ui->essai_table->setModel(t.afficher());


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
         QIcon MAJ("C:/Users/hp/Desktop/projet c++/traiteur/poubelle.png");

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
    ui->stackedWidget->setCurrentIndex(3);

}

void MainWindow::on_pushButton_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}


void MainWindow::on_aff_trait_cellClicked(int row, int column)
{ traiteur t;
    const QAbstractItemModel *model = ui->aff_trait->model();
  const QString identifiant = model->data(model->index(row, 0), Qt::DisplayRole).toString();
if(column==5)
{
    t.DELETE(identifiant);
    initialiserUpdatetrait();

}
}

void MainWindow::on_list_produit_clicked()
{
    Produit p;
            ui->stackedWidget->setCurrentIndex(7);
            ui->affiche_tablePR->setModel(p.afficher());
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

   ui->affiche_tablePR->setModel(p.afficher());


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
         QIcon MAJ("C:/Users/hp/Desktop/projet c++/traiteur/poubelle.png");

         QTableWidgetItem *MAJ_item = new QTableWidgetItem;

              MAJ_item->setIcon(MAJ);
              ui->update_tablePR->setItem(row,5, MAJ_item);
              ui->update_tablePR->resizeColumnsToContents();
            }
         }
}

void MainWindow::on_modifie_produit_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);

    initialiserUpdateprod();

}

void MainWindow::on_pushButton_9_clicked()
{// back from update prod to prod (crud)

    ui->stackedWidget->setCurrentIndex(2);

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
    p.DELETE(identifiant);
    initialiserUpdateprod();

}
}

void MainWindow::on_triTrait_currentIndexChanged(int index)
{qDebug()<< index;

    if (index==1){

    Produit p;
    ui->essai_table->setModel(p.afficher());
     ui->essai_table->resizeRowsToContents();
     ui->essai_table->resizeColumnsToContents();
     ui->essai_table->show();


    }
}
