#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(mscs.afficher_mus("XYZ",-1,-1));
    ui->tableView_2->setModel(empy.afficher_emp("XYZ",-1,-1));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Mus_management_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_backtosono_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_Consult_Musicians_clicked()
{
    ui->tableView->setModel(mscs.afficher_mus("XYZ",-1,-1));
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_backtomusman_clicked()
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
    if (id_mus==0 || prix_mus==0)
       {
        ui->IDERROR->setText("");
        ui->PRERROR->setText("");
            if(id_mus==0)
            ui->IDERROR->setText("Please enter a number");
            if(prix_mus==0)
            ui->PRERROR->setText("Please enter a number");

       }
    else
    {
        musiciens m(prix_mus, nom_mus, prenom_mus, id_mus, genre_mus, email_mus);
        bool test = m.ajouter_mus();
        if (test)
        {
            ui->IDERROR->setText("");
            ui->PRERROR->setText("");
            ui->PRMedit->clear();
            ui->FNedit->clear();
            ui->LNedit->clear();
            ui->IDMedit->clear();
            ui->MGedit->clear();
            ui->EMedit->clear();
            ui->tableView->setModel(mscs.afficher_mus("XYZ",-1,-1));

            QMessageBox::information(nullptr, QObject::tr("Success"), QObject::tr("Musician Successfully Added!\n"), QMessageBox::Ok);
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Failed"), QObject::tr("Failed to add musician\n"
                                                                              "Click cancel."),
                                  QMessageBox::Cancel);
        }
    }
}

void MainWindow::on_Manage_Musicians_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_backtosono_2_clicked()
{
  ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_Add_mus_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_gobacktomanmus_clicked()
{
    ui->IDERROR->setText("");
    ui->PRERROR->setText("");
    ui->PRMedit->clear();
    ui->FNedit->clear();
    ui->LNedit->clear();
    ui->IDMedit->clear();
    ui->MGedit->clear();
    ui->EMedit->clear();
     ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_can_mus_clicked()
{
    ui->IDERROR->setText("");
    ui->PRERROR->setText("");
    ui->PRMedit->clear();
    ui->FNedit->clear();
    ui->LNedit->clear();
    ui->IDMedit->clear();
    ui->MGedit->clear();
    ui->EMedit->clear();
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_searchtomod_clicked()
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

void MainWindow::on_Modify_mus_button_clicked()
{
  ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_sub_mus_2_clicked()
{
    int id_mus1 = ui->MIDedit->text().toInt();
    int prix_mus = ui->PRMedit_2->text().toInt();
    QString nom_mus = ui->FNedit_2->text();
    QString prenom_mus = ui->LNedit_2->text();
    int id_mus = ui->IDMedit_2->text().toInt();
    QString genre_mus = ui->MGedit_2->text();
    QString email_mus = ui->EMedit_2->text();
    bool test = mscs.modifier_mus(id_mus1, id_mus, nom_mus, prenom_mus, genre_mus, email_mus, prix_mus);
    if (test)
    {
        ui->PRMedit_2->clear();
        ui->FNedit_2->clear();
        ui->LNedit_2->clear();
        ui->IDMedit_2->clear();
        ui->MGedit_2->clear();
        ui->EMedit_2->clear();
        ui->tableView->setModel(mscs.afficher_mus("XYZ",-1,-1));

        QMessageBox::information(nullptr, QObject::tr("Success"), QObject::tr("Musician Successfully Modified!\n"), QMessageBox::Ok);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Failed"), QObject::tr("Failed to Modify musician\n"
                                                                          "Click cancel."),
                              QMessageBox::Cancel);
    }
}

void MainWindow::on_backtomusman_2_clicked()
{
    ui->PRMedit_2->clear();
    ui->FNedit_2->clear();
    ui->LNedit_2->clear();
    ui->IDMedit_2->clear();
    ui->MGedit_2->clear();
    ui->EMedit_2->clear();
     ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_commandLinkButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_delmusid_clicked()
{
    int id_mus = ui->musdeledit->text().toInt();
    bool test = mscs.supprimer_mus(id_mus);
    if (test)
    {
        QString nom_mus;
        ui->tableView->setModel(mscs.afficher_mus("XYZ",-1,-1));

        QMessageBox::information(nullptr, QObject::tr("Success"), QObject::tr("Musician Successfully Deleted!\n"), QMessageBox::Ok);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Failed"), QObject::tr("Failed to delete musician\n"
                                                                          "Click cancel."),
                              QMessageBox::Cancel);
    }
}

void MainWindow::on_Delete_mus_button_clicked()
{
  ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_search_clicked()
{
    int id_mus=0;
    QString nom_mus =ui->musname->text().trimmed();
    id_mus = ui->musid->text().toInt();
    if (ui->musid->text()=="" && nom_mus!="")
    {
      ui->tableView->setModel(mscs.afficher_mus(nom_mus,-1,-1));
    }
    if (ui->musid->text()!="" && nom_mus=="")
    {
      ui->tableView->setModel(mscs.afficher_mus("XYZ",id_mus,-1));
    }
    if(ui->musid->text()!="" && nom_mus!="")
    {
        ui->tableView->setModel(mscs.afficher_mus(nom_mus,id_mus,-1));
    }
}

void MainWindow::on_reset_clicked()
{
    ui->musname->clear();
    ui->musid->clear();
    ui->tableView->setModel(mscs.afficher_mus("XYZ",-1,-1));
}

void MainWindow::on_Sort_mus_activated(int index)
{
    switch (index)
    {
        case 0:
        ui->tableView->setModel(mscs.afficher_mus("XYZ",-1,-1));
        break;

        case 1:
        ui->tableView->setModel(mscs.afficher_mus("XYZ",-1,1));
        break;
    case 2:
        ui->tableView->setModel(mscs.afficher_mus("XYZ",-1,2));
        break;
    case 3:
         ui->tableView->setModel(mscs.afficher_mus("XYZ",-1,3));
        break;
    }
}

void MainWindow::on_Consult_Employees_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
}

void MainWindow::on_Emp_management_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);

}

void MainWindow::on_searchname_2_clicked()
{
    int id_emp=0;
    QString nom_emp= ui->emp_n->text().trimmed();
    id_emp = ui->empid->text().toInt();
    if (ui->empid->text()=="" && nom_emp!="")
    {
      ui->tableView_2->setModel(empy.afficher_emp(nom_emp,-1,-1));
    }
    if (ui->empid->text()!="" && nom_emp=="")
    {
      ui->tableView_2->setModel(empy.afficher_emp("XYZ",id_emp,-1));
    }
    if(ui->empid->text()!="" && nom_emp!="")
    {
        ui->tableView_2->setModel(empy.afficher_emp(nom_emp,id_emp,-1));
    }
}

void MainWindow::on_comboBox_2_activated(int index)
{
    switch (index)
    {
        case 0:
        ui->tableView_2->setModel(empy.afficher_emp("XYZ",-1,-1));
        break;

        case 1:
        ui->tableView_2->setModel(empy.afficher_emp("XYZ",-1,1));
        break;
    case 2:
        ui->tableView_2->setModel(empy.afficher_emp("XYZ",-1,2));
        break;
    case 3:
         ui->tableView_2->setModel(empy.afficher_emp("XYZ",-1,3));
        break;
    }
}

void MainWindow::on_searchid_3_clicked()
{
    ui->emp_n->clear();
    ui->empid->clear();
    ui->tableView_2->setModel(empy.afficher_emp("XYZ",-1,-1));
}

void MainWindow::on_sub_emp_2_clicked()
{
    int numlen=0;
    int id_emp=ui->IDe_2->text().toInt();
    QString nom_emp=ui->FNe_2->text();
    QString prenom_emp=ui->LNe_2->text();
    int salaire_emp=ui->SALm_2->text().toInt();
    QString num_emp=ui->Nemp_2->text();
    QString type_emp=ui->comboBox_4->currentText();
    employes em ( id_emp,  nom_emp, prenom_emp,  salaire_emp, num_emp, type_emp );
    numlen=num_emp.length();
    if(id_emp==0 || salaire_emp==0 || numlen>8 || numlen <8)
    {
        ui->IDERROR_3->clear();
        ui->PRERROR_3->clear();
        ui->phonenumerr->clear();
        if(id_emp==0)
        {
            ui->IDERROR_3->setText("Please Enter a number");

        }
        if(salaire_emp==0)
        {
            ui->PRERROR_3->setText("Please Enter a number");
        }
        if(numlen< 8)
         ui->phonenumerr->setText("Phone number is only 8 digits");
        if(numlen > 8)
         ui->phonenumerr->setText("Phone number is only 8 digits");

    }
    else
       {
 bool test=em.ajouter_emp();
 if (test)
 {
     ui->IDERROR_3->setText("");
     ui->PRERROR_3->setText("");
     ui->IDe_2->clear();
     ui->FNe_2->clear();
     ui->LNe_2->clear();
     ui->SALm_2->clear();
     ui->Nemp_2->clear();
     ui->tableView_2->setModel(empy.afficher_emp("XYZ",-1,-1));

     QMessageBox::information(nullptr, QObject::tr("Success"), QObject::tr("Employee Successfully Added!\n"), QMessageBox::Ok);
 }
 else
 {
     QMessageBox::critical(nullptr, QObject::tr("Failed"), QObject::tr("Failed to add Employee\n"
                                                                       "Click cancel."),
                           QMessageBox::Cancel);
 }
}
    }



void MainWindow::on_Add_emp_button_clicked()
{
   ui->stackedWidget->setCurrentIndex(10);
}

void MainWindow::on_Manage_Employees_clicked()
{
   ui->stackedWidget->setCurrentIndex(9);
}

void MainWindow::on_commandLinkButton_10_clicked()
{
    QString aaa;
        int id_emp = ui->Eidedit->text().toInt();
        int cmon = empy.affecter_emp(id_emp);
        aaa.setNum(cmon);
        ui->IDEedit->setText(aaa);
        ui->FNEedit->setText(empy.affecter_emp2(id_emp));
        ui->LNEedit->setText(empy.affecter_emp3(id_emp));
        ui->SALedit->setText(empy.affecter_emp4(id_emp));
        ui->NEmedit->setText(empy.affecter_emp5(id_emp));
        cmon = empy.affecter_emp6(id_emp);
        aaa.setNum(cmon);
        ui->TYEedit->setText(aaa);
}

void MainWindow::on_sub_mus_3_clicked()
{
    int id_emp1 = ui->Eidedit->text().toInt();
       int salaire_emp = ui->TYEedit->text().toInt();
       QString nom_emp = ui->FNEedit->text();
       QString prenom_emp = ui->LNEedit->text();
       int id_emp = ui->IDEedit->text().toInt();
       QString type_emp = ui->NEmedit->text();
       QString num_emp = ui->SALedit->text();
       bool test = empy.modifier_emp(id_emp1, id_emp, nom_emp, prenom_emp, num_emp, type_emp, salaire_emp);
       if (test)
       {
           ui->Eidedit->clear();
           ui->TYEedit->clear();
           ui->FNEedit->clear();
           ui->LNEedit->clear();
           ui->IDEedit->clear();
           ui->NEmedit->clear();
           ui->SALedit->clear();
           ui->tableView_2->setModel(empy.afficher_emp("XYZ",-1,-1));

           QMessageBox::information(nullptr, QObject::tr("Success"), QObject::tr("Employee Successfully Modified!\n"), QMessageBox::Ok);
       }
       else
       {
           QMessageBox::critical(nullptr, QObject::tr("Failed"), QObject::tr("Failed to Modify Employee\n"
                                                                             "Click cancel."),
                                 QMessageBox::Cancel);
       }
}

void MainWindow::on_commandLinkButton_11_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}

void MainWindow::on_Modify_mus_button_2_clicked()
{
     ui->stackedWidget->setCurrentIndex(11);
}

void MainWindow::on_commandLinkButton_12_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_commandLinkButton_8_clicked()
{
  ui->stackedWidget->setCurrentIndex(9);
}

void MainWindow::on_commandLinkButton_9_clicked()
{
   ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_commandLinkButton_13_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_delemp_2_clicked()
{
    int id_emp = ui->musdeledit_2->text().toInt();
     bool test =empy.supprimer_emp(id_emp);
     if (test)
     {
         QString nom_mus;
         ui->tableView_2->setModel(empy.afficher_emp("XYZ",-1,-1));

         QMessageBox::information(nullptr, QObject::tr("Success"), QObject::tr("Employee Successfully Deleted!\n"), QMessageBox::Ok);
     }
     else
     {
         QMessageBox::critical(nullptr, QObject::tr("Failed"), QObject::tr("Failed to delete Employee\n"
                                                                           "Click cancel."),
                               QMessageBox::Cancel);
     }
}

void MainWindow::on_commandLinkButton_14_clicked()
{
  ui->stackedWidget->setCurrentIndex(9);
}

void MainWindow::on_Delete_emp_button_clicked()
{
     ui->stackedWidget->setCurrentIndex(12);
}

void MainWindow::on_Gen_PDF_clicked()
{
    empy.gen_pdf();
}
