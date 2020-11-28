#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsDropShadowEffect>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     ui->tableView->setModel(mscs.afficher_mus());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_pushButton_2_clicked()
{
ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_commandLinkButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_commandLinkButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_add_Musicians_clicked()
{
   ui->stackedWidget->setCurrentIndex(3);
}



void MainWindow::on_can_mus_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_add_Emp_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);

}

void MainWindow::on_can_emp_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);

}
void MainWindow::on_list_Musicians_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_commandLinkButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_sub_mus_clicked()
{
    int prix_mus = ui->PRMedit->text().toInt();
    QString nom_mus = ui->FNedit->text();
    QString prenom_mus = ui->LNedit->text();
    int id_mus = ui->IDMedit->text().toInt();
    QString genre_mus = ui->MGedit->text();
    QString email_mus = ui->EMedit->text();
    musiciens m(prix_mus, nom_mus, prenom_mus, id_mus, genre_mus, email_mus);
    bool test = m.ajouter_mus();
    if (test)
    {
        ui->PRMedit->clear();
        ui->FNedit->clear();
        ui->LNedit->clear();
        ui->IDMedit->clear();
        ui->MGedit->clear();
        ui->EMedit->clear();
        ui->tableView->setModel(mscs.afficher_mus());

        QMessageBox::information(nullptr, QObject::tr("Success"), QObject::tr("Musician Successfully Added!\n"), QMessageBox::Ok);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Failed"), QObject::tr("Failed to add musician\n"
                                                                          "Click cancel."),
                              QMessageBox::Cancel);
    }
}

void MainWindow::on_commandLinkButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_del_Musicians_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}
void MainWindow::on_commandLinkButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
void MainWindow::on_delmusid_clicked()
{
    int id_mus = ui->musdeledit->text().toInt();
    bool test = mscs.supprimer_mus(id_mus);
    if (test)
    {
        ui->tableView->setModel(mscs.afficher_mus());

        QMessageBox::information(nullptr, QObject::tr("Success"), QObject::tr("Musician Successfully Deleted!\n"), QMessageBox::Ok);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Failed"), QObject::tr("Failed to delete musician\n"
                                                                          "Click cancel."),
                              QMessageBox::Cancel);
    }
}

void MainWindow::on_mod_Musicians_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_commandLinkButton_7_clicked()
{
    QString aaa;
    int id_mus = ui->MIDedit->text().toInt();
    int cmon = mscs.affecter_mus(id_mus);
    aaa.setNum(cmon);
    ui->IDMedit_2->setText(aaa);
    ui->FNedit_2->setText(mscs.affecter_mus2(id_mus));
    ui->LNedit_2->setText(mscs.affecter_mus3(id_mus));
    ui->MGedit_2->setText(mscs.affecter_mus4(id_mus));
    ui->EMedit_2->setText(mscs.affecter_mus5(id_mus));
    cmon = mscs.affecter_mus6(id_mus);
    aaa.setNum(cmon);
    ui->PRMedit_2->setText(aaa);
}
