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
ui->stackedWidget->setCurrentIndex(4);
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
   ui->stackedWidget->setCurrentIndex(2);
}



void MainWindow::on_can_mus_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_add_Emp_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);

}

void MainWindow::on_can_emp_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);

}
