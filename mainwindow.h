#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include "client_marriage.h"
#include "invite.h"
#include "smtp.h"
#include <QtWidgets/QMessageBox>
#include <QPropertyAnimation>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


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

    void on_pushButton_7_clicked();

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

    void on_add_3_clicked();

    void on_add_guest_3_clicked();

    void afficher_liste_invite(QString);

    void on_cancel_3_clicked();

    void on_search_gues_info_clicked();

    void on_update_guest_info_clicked();

    void on_search_bar_2_textChanged(const QString &arg1);

    void sendMail();
    void mailSent(QString);

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

    void on_search_2_windowIconChanged(const QIcon &icon);

    void on_AddButton_clicked();

    void on_AddButton_2_clicked();

    void on_DeleteHallButton_clicked();

    void on_DisplayButton_clicked();

    void on_hall_id_line_2_textChanged(const QString &arg1);

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

    void on_mail_send_button_clicked();

    void on_MailHallButton_clicked();

    void on_DecoratorStatBackButton_2_clicked();

    void on_HallMailBackButton_clicked();

    void on_hall_mail_send_button_clicked();

    void on_MailDecoratorBackButton_clicked();

    void on_MailDecoratorButton_clicked();

    void on_decorator_mail_send_button_2_clicked();

    void on_decorator_mail_send_button_clicked();

    //void on_pushButton_2_clicked();

    void on_back_from_delete_client_clicked();

    void on_back_from_yassine_clicked();

private:
    Ui::MainWindow *ui;
    Smtp* smtp ;
    QString msg;
    QString mail;
    QPropertyAnimation *animation;
};
#endif // MAINWINDOW_H
