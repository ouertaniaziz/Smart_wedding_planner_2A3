#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include "client_marriage.h"
#include "invite.h"
#include "smtp.h"
#include <QtWidgets/QMessageBox>
#include <QPropertyAnimation>
#include "arduino_yassine.h"
#include "arduino.h"
#include "musiciens.h"
#include "employes.h"
#include <QMainWindow>
#include "traiteur.h"
#include"prod_client.h"
#include<QSqlQueryModel>
#include"produit.h"
#include <stdlib.h>
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
    void on_clientlist_clicked();

    void on_pushButton_4_clicked();

    void on_add_client_clicked();

    void on_delete_client_clicked();

    void on_update_client_clicked();

    void on_pushButton_clicked();

    void on_cancel_2_clicked();

    void on_add_2_clicked();

    void on_delete_2_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_delete_3_clicked();

    void on_update_client_info_clicked();

    void on_guestlist_clicked();

    void on_marriage_list_2_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_search_guest_list_clicked();

    void on_add_guest_clicked();

    void on_back_guest_from_add();

    void on_delete_guest_clicked();

    void on_pushButton_8_clicked();

    void on_delete_guest_3_clicked();

    void on_pushButton_9_clicked();

    void on_update_guest_clicked();

    void add_to_database_Marriage();

    void afficher_table_marriage();

    void Delete_Marriage();

    void search_client_to_update();

    void update_client_info();

    int convert_string_to_number(QString s);

    int check_string_without_number(QString s);

    void clear_info_add_marriage();

    void on_search_bar_textChanged(const QString &arg1);

    //void on_add_3_clicked();

    void on_add_guest_3_clicked();

    void afficher_liste_invite(QString);

    void on_cancel_3_clicked();

    void on_search_gues_info_clicked();

    void on_update_guest_info_clicked();

    void on_search_bar_2_textChanged(const QString &arg1);

    void sendMail();
  //  void mailSent(QString);

    void on_imprimer_clicked();

    void on_send_invite_clicked();

    void on_pushButton_10_clicked();

    void on_client_back_button_clicked();

    void on_yassine_clicked();

    void on_back_tomneu_clicked();

    void on_zied_clicked();

    void on_UpdateHallButton_clicked();

    void on_SelectHallButton_clicked();

    void on_AddHallButton_clicked();

    void on_AddDecButton_clicked();

    void on_UpdateDecButton_clicked();

    void on_BackButton_clicked();

    void on_BackButton_2_clicked();

    void on_BackButton_3_clicked();

    void on_BackButton_4_clicked();

    void on_BackButton_5_clicked();

 //   void on_search_2_windowIconChanged(const QIcon &icon);

    void on_AddButton_clicked();

    void on_AddButton_2_clicked();

    void on_DeleteHallButton_clicked();

    void on_DisplayButton_clicked();

  //  void on_hall_id_line_2_textChanged(const QString &arg1);

    void on_AddDecButton_2_clicked();

    void on_DeleteDecButton_clicked();

    void on_UpdateButton_clicked();

    void on_UpdateButton_2_clicked();

    void on_UpdateFindButton_clicked();

    void on_UpdateFindButton_2_clicked();

    void on_StatHallButton_clicked();

    void on_HallStatBackButton_clicked();

    void on_StatDecoratorButton_clicked();

    void on_DecoratorStatBackButton_clicked();

    //void on_mail_send_button_clicked();

    void on_MailHallButton_clicked();

    void on_DecoratorStatBackButton_2_clicked();

    //void on_HallMailBackButton_clicked();

    void on_hall_mail_send_button_clicked();

    void on_MailDecoratorBackButton_clicked();

    void on_MailDecoratorButton_clicked();

   // void on_decorator_mail_send_button_2_clicked();

    void on_decorator_mail_send_button_clicked();

    //void on_pushButton_2_clicked();

    void on_back_from_delete_client_clicked();

    void on_back_from_yassine_clicked();

    //////////////////////////////////////////////////////////////////////// aziz
    ///
    ///
    void on_traiteur_edit_clicked();

    void on_fermer_clicked();

    void on_ajouter_traiteur_clicked();

    void on_cancel_clicked();

    void on_produit_edit_clicked();

    void on_cancel_P_clicked();


    void on_ajoute_produit_clicked();

    void on_green_add_clicked();

    void on_BACK5_clicked();

    void on_list_traiteurs_clicked();
    void essaiaff();

    void on_BACK1_clicked();

    void on_BACK2_clicked();

    void on_BACK3_clicked();

    void on_BACK4_clicked();

    void on_BACK6_clicked();

    void on_modifier_traiter_clicked();


    void on_aff_trait_cellChanged(int row, int column );
    void on_pushButton_7_clicked();
    void on_BACK7_clicked();
    void on_green_addP_clicked();


    void on_aff_trait_cellClicked(int row, int column);

    void on_list_produit_clicked();

    void on_modifie_produit_clicked();

    void on_BACK8_clicked();

    void on_update_tablePR_cellChanged(int row, int column);

    void on_update_tablePR_cellClicked(int row, int column);

    void on_triTrait_currentIndexChanged(int index);
void reclamatio();



    void on_rechercheLine_textChanged(const QString &arg1);

    void on_triProd_currentIndexChanged(int index);

    void on_rechercheLine_2_textChanged(const QString &arg1);

    bool verif_trait(QString,QString,QString,QString,QString);
    bool verif_prod(QString,QString,QString,QString);

    void on_statisticP_clicked();

    void on_imprimer_TRAIT_clicked();

    void on_stat_clicked();

    void on_BACK10_clicked();

    void on_BACK9_clicked();

    void on_imprimerPROD_clicked();

    void on_temporaire_clicked();

    void on_acheter_prod_cellClicked(int row, int column);

    void on_BACK12_clicked();

    void on_aziz_clicked();

    void on_back_to_aziz_clicked();

    //void on_PrintHallsButton_clicked();

    void on_MailHallPrint_clicked();
    void initialiserclientproduit();
void calcule_de_facture();

void on_nbr_editingFinished();

void on_imprimerFACTURE_clicked();

void on_sami_clicked();

void on_search_clicked();

void on_reset_clicked();

void on_Sort_mus_activated(int index);

void on_mus_man_main_2_clicked();

void on_mus_man_main_clicked();

void on_Submit_mus_clicked();

void on_mus_man_main_5_clicked();

void on_mus_man_main_3_clicked();

void on_returnsami_clicked();

void on_cancelsami_clicked();

void on_returnsami_5_clicked();

void on_returnsami_4_clicked();

void on_returnsami_3_clicked();

void on_returnsami_2_clicked();

void on_Submit_mus_2_clicked();

void on_search_3_clicked();

void on_returnsami_6_clicked();

void on_mus_man_main_6_clicked();

void on_search_7_clicked();

void on_returnsami_13_clicked();

void on_mus_man_main_7_clicked();

void on_emp_man_main_clicked();

void on_search_8_clicked();

void on_reset_3_clicked();

void on_Gen_PDF_clicked();

void on_returnsami_14_clicked();

void on_returnsami_15_clicked();

void on_sub_emp_2_clicked();

void on_cancelsami_5_clicked();

void on_returnsami_16_clicked();

void on_search_9_clicked();

void on_Submit_mus_5_clicked();

void on_returnsami_17_clicked();

void on_search_10_clicked();

void on_returnsami_18_clicked();

void on_emp_man_main_3_clicked();

void on_mus_man_main_15_clicked();

void on_mus_man_main_16_clicked();

void on_mus_man_main_17_clicked();

void on_mus_man_main_18_clicked();

void on_returnsami_19_clicked();

void on_comboBox_2_activated(int index);

void activate_arduino();

void on_name_marriage_clicked();

void on_none_clicked();

void on_confirmation_clicked();

void on_email_marriage_clicked();

void sendMail_yassine();
void on_Aman_clicked();

private:
    Ui::MainWindow *ui;
    Smtp* smtp ;
    QString msg;
    musiciens mscs;
    employes empy;
    QString mail;
    QPropertyAnimation *animation;
    arduino_yassine Arduino_yassine;
    QByteArray data;

};
#endif // MAINWINDOW_H
