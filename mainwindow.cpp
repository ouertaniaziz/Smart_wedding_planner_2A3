#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"traiteur.h"
#include"produit.h"

#include <QApplication>
#include <QTableWidget>
#include <QtCharts>
#include <QDateTime>
#include<QBarSet>
#include <QChartView>
QT_CHARTS_USE_NAMESPACE


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
bool MainWindow::verif_trait(QString id,QString nom,QString num,QString email,QString adresse)
{ bool verification=true;
    int k,N;
    k=id.toInt();
    N=num.toInt();
    if(k==0)
    {
        ui->IDEdit->clear();
        ui->IDEdit->setText("l'identifiant contien que des chiffres");
        verification=false;
    }
    if(nom=="")
    {
        ui->nameEdit->clear();

          ui->nameEdit->setText("il faut remplire le nom5");
          verification=false;

    }
   for(int i=0;i<ui->nameEdit->text().size();i++)
   {
if((ui->nameEdit->text().at(i)>'a')&&((ui->nameEdit->text().at(i))<'z'))
{
    ui->nameEdit->clear();

      ui->nameEdit->setText("verifier le nom !!");
      //verification=false;

    }
   }
   if(N==0)
   {
       ui->phoneEdit->clear();
       ui->phoneEdit->setText("verifier le numero");
       verification=false;
   }
   int x=0;
   for(int i=0;i<ui->emailEdit->text().size();i++)
   {
if(ui->emailEdit->text().at(i)=='@')
{

x++;
    }
   }
   if((x<1)||(x>1))
   {
       ui->emailEdit->clear();

         ui->emailEdit->setText("verifier l'email");
         verification=false;
   }
   if(adresse=="")
   {
       ui->adresseEdit->clear();

         ui->adresseEdit->setText("il faut remplire l'adresse");
         verification=false;

   }

    return verification;

}
bool MainWindow::verif_prod(QString id ,QString nom ,QString prix,QString type,QString id_t)
{
bool verification=true;
   int k,N;
   k=id.toInt();
   N=prix.toInt();
   if(k==0)
   {
       ui->identifier_edit->clear();
       ui->identifier_edit->setText("l'identifiant contien que des chiffres");
       verification=false;
   }
   if(nom=="")
   {
       ui->namePEdit->clear();

         ui->namePEdit->setText("il faut remplire le nom");
         verification=false;

   }
   for(int i=0;i<ui->namePEdit->text().size();i++)
   {
if((ui->namePEdit->text().at(i)>'a')&&((ui->namePEdit->text().at(i))<'z'))
{
    ui->namePEdit->clear();

      ui->namePEdit->setText("verifier le nom ");
      //verification=false;

    }
   }
   if(N==0)
   {
       ui->priceEdit->clear();
       ui->priceEdit->setText("verifier le prix");
       verification=false;
   }

   if(id_t=="")
   {
       ui->idencatprod->clear();

         ui->idencatprod->setText("il faut remplire l'id");
         verification=false;

   }

    return verification;
}
//ajouter un traiteur
void MainWindow::on_green_add_clicked()
{

    traiteur t;
   if(verif_trait(ui->IDEdit->text(),ui->nameEdit->text(),ui->phoneEdit->text(),ui->emailEdit->text(),ui->adresseEdit->text())==true)
   {
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


}
void MainWindow::on_green_addP_clicked()
{
    Produit p;
    if(verif_prod(ui->identifier_edit->text(),ui->namePEdit->text(),ui->priceEdit->text(),ui->typeBox->currentText(),ui->idencatprod->text()))
   { p.setIDprod(ui->identifier_edit->text());
    p.setNOMprod(ui->namePEdit->text());
    p.setPRIXprod(ui->priceEdit->text());
    p.setTYPEprod(ui->typeBox->currentText());
    p.setIDTRAITprod(ui->idencatprod->text());
p.addproduit();
    }
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
        ui->essai_table->setModel(t.afficher(0,"null"));
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

   ui->essai_table->setModel(t.afficher(0,"null"));


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
    t.effacer(identifiant);
    initialiserUpdatetrait();

}
}

void MainWindow::on_list_produit_clicked()
{
    Produit p;
            ui->stackedWidget->setCurrentIndex(7);
           // ui->affiche_tablePR->setModel(p.afficher(0,"null"));
            ui->affiche_tablePR->setModel(p.stat());

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

  ui->affiche_tablePR->setModel(p.afficher(0,"null"));


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
    p.effacer(identifiant);
    initialiserUpdateprod();

}
}

void MainWindow::on_triTrait_currentIndexChanged(int index)
{qDebug()<< index;
    traiteur t;
    ui->essai_table->setModel(t.afficher(index,"null"));
         ui->essai_table->resizeRowsToContents();
         ui->essai_table->resizeColumnsToContents();
         ui->essai_table->show();


}






void MainWindow::on_rechercheLine_textChanged(const QString &arg1)
{
    traiteur t;

    ui->essai_table->setModel(t.afficher(5,arg1));

    qDebug()<< ui->rechercheLine->text();
         ui->essai_table->resizeRowsToContents();
         ui->essai_table->resizeColumnsToContents();
         ui->essai_table->show();
}

void MainWindow::on_triProd_currentIndexChanged(int index)
{
    Produit p;
            ui->affiche_tablePR->setModel(p.afficher(index,"null"));
             ui->affiche_tablePR->resizeRowsToContents();
             ui->affiche_tablePR->resizeColumnsToContents();
             ui->affiche_tablePR->show();
}

void MainWindow::on_rechercheLine_2_textChanged(const QString &arg1)
{
    Produit p;
            ui->affiche_tablePR->setModel(p.afficher(5,arg1));
             ui->affiche_tablePR->resizeRowsToContents();
             ui->affiche_tablePR->resizeColumnsToContents();
             ui->affiche_tablePR->show();
}

void MainWindow::on_statisticP_clicked()
{ QStringList list;

  ui->stackedWidget->setCurrentIndex(9);
    //![1]
        QBarSet *set0 = new QBarSet("chaud");
        QBarSet *set1 = new QBarSet("froid");
        QBarSet *set2 = new QBarSet("sucrée");
        QBarSet *set3 = new QBarSet("salée");


        *set0 << 1 << 2 << 3 << 4 << 5 << 6;
        *set1 << 5 << 0 << 0 << 4 << 0 << 7;
        *set2 << 3 << 5 << 8 << 13 << 8 << 5;
        *set3 << 5 << 6 << 7 << 3 << 4 << 5;
    //![1]

    //![2]
        QBarSeries *series = new QBarSeries();
        series->append(set0);
        series->append(set1);
        series->append(set2);
        series->append(set3);
     //   series->append(set4);

    //![2]

    //![3]
        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Simple barchart example");
        chart->setAnimationOptions(QChart::SeriesAnimations);
    //![3]

    //![4]
        QStringList categories;

        categories << "Jan" << "Feb" << "Mar" << "Apr" << "May" << "Jun";
        QBarCategoryAxis *axis = new QBarCategoryAxis();
        axis->append(categories);
        chart->createDefaultAxes();
        chart->setAxisX(axis, series);
    //![4]

    //![5]
        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);
    //![5]

    //![6]
        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);
    //![6]

    //![7]
    //!
ui->graphicsView->setChart(chart);
        ui->graphicsView->setMinimumSize(420,300);
        ui->graphicsView->show();
    //![7]

}
