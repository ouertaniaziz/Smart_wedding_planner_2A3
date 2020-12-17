#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "musiciens.h"
#include "employes.h"
#include <QMainWindow>

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
    void on_Mus_management_clicked();

    void on_backtosono_clicked();

    void on_Consult_Musicians_clicked();

    void on_backtomusman_clicked();

    void on_sub_mus_clicked();

    void on_Manage_Musicians_clicked();

    void on_backtosono_2_clicked();

    void on_Add_mus_button_clicked();

    void on_gobacktomanmus_clicked();

    void on_can_mus_clicked();

    void on_searchtomod_clicked();

    void on_Modify_mus_button_clicked();

    void on_sub_mus_2_clicked();

    void on_backtomusman_2_clicked();

    void on_commandLinkButton_6_clicked();

    void on_delmusid_clicked();

    void on_Delete_mus_button_clicked();

    void on_search_clicked();

    void on_reset_clicked();

    void on_Sort_mus_activated(int index);

    void on_Consult_Employees_clicked();

    void on_Emp_management_clicked();

    void on_searchname_2_clicked();

    void on_comboBox_2_activated(int index);

    void on_searchid_3_clicked();

    void on_sub_emp_2_clicked();

    void on_Add_emp_button_clicked();

    void on_Manage_Employees_clicked();

    void on_commandLinkButton_10_clicked();

    void on_sub_mus_3_clicked();

    void on_commandLinkButton_11_clicked();

    void on_Modify_mus_button_2_clicked();

    void on_commandLinkButton_12_clicked();

    void on_commandLinkButton_8_clicked();

    void on_commandLinkButton_9_clicked();

    void on_commandLinkButton_13_clicked();

    void on_delemp_2_clicked();

    void on_commandLinkButton_14_clicked();

    void on_Delete_emp_button_clicked();

    void on_Gen_PDF_clicked();

private:
    Ui::MainWindow *ui;
    musiciens mscs;
    employes empy;
};
#endif // MAINWINDOW_H
