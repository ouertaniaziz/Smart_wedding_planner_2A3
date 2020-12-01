#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include "client_marriage.h"
#include "invite.h"
#include "smtp.h"
#include <QtWidgets/QMessageBox>

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

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
