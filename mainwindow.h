#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_commandLinkButton_clicked();

    void on_commandLinkButton_2_clicked();

    void on_add_Musicians_clicked();



    void on_can_mus_clicked();

    void on_add_Emp_clicked();

    void on_can_emp_clicked();
void on_list_Musicians_clicked();

    void on_commandLinkButton_4_clicked();

    void on_sub_mus_clicked();

    void on_commandLinkButton_5_clicked();

    void on_del_Musicians_clicked();

    void on_commandLinkButton_6_clicked();

    void on_delmusid_clicked();

    void on_mod_Musicians_clicked();

    void on_commandLinkButton_7_clicked();

    void on_sub_mus_2_clicked();
private:
    Ui::MainWindow *ui;
        musiciens mscs;
};
#endif // MAINWINDOW_H
