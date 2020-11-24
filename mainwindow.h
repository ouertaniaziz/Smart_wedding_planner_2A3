#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "traiteur.h"
#include"login.h"
#include<QSqlQueryModel>
#include"produit.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void initialiserUpdatetrait();
    void initialiserUpdateprod();

private slots:
    void on_traiteur_edit_clicked();

    void on_fermer_clicked();

    void on_ajouter_traiteur_clicked();

    void on_cancel_clicked();

    void on_produit_edit_clicked();

    void on_cancel_P_clicked();


    void on_ajoute_produit_clicked();

    void on_green_add_clicked();

    void on_pushButton_2_clicked();

    void on_list_traiteurs_clicked();
    void essaiaff();

    void on_pushButton_5_clicked();

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_6_clicked();

    void on_modifier_traiter_clicked();


    void on_aff_trait_cellChanged(int row, int column );
void on_pushButton_7_clicked();
void on_pushButton_8_clicked();
void on_green_addP_clicked();


void on_aff_trait_cellClicked(int row, int column);

void on_list_produit_clicked();

void on_modifie_produit_clicked();

void on_pushButton_9_clicked();

void on_update_tablePR_cellChanged(int row, int column);

void on_update_tablePR_cellClicked(int row, int column);

void on_triTrait_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
