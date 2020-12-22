/********************************************************************************
** Form generated from reading UI file 'deletehall.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETEHALL_H
#define UI_DELETEHALL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DeleteHall
{
public:
    QLineEdit *hall_id_line;
    QLabel *hall_number_label;
    QPushButton *CancelButton;
    QPushButton *DeleteHallButton;

    void setupUi(QDialog *DeleteHall)
    {
        if (DeleteHall->objectName().isEmpty())
            DeleteHall->setObjectName(QStringLiteral("DeleteHall"));
        DeleteHall->resize(374, 153);
        hall_id_line = new QLineEdit(DeleteHall);
        hall_id_line->setObjectName(QStringLiteral("hall_id_line"));
        hall_id_line->setGeometry(QRect(160, 40, 101, 21));
        hall_id_line->setStyleSheet(QLatin1String("QLineEdit{\n"
"	border: 2px solid rgb(138,87,163);\n"
"	border-radius: 8px;\n"
"	background-color: rgb(255,255,255);\n"
"}\n"
"\n"
"QLineEdit:hover{\n"
"	border: 2px solid rgb(138,87,163);\n"
"}\n"
"\n"
"QLineEdit:focused{\n"
"	border: 2px solid rgb(138,87,163);\n"
"	color: #A0A0A0;\n"
"}"));
        hall_number_label = new QLabel(DeleteHall);
        hall_number_label->setObjectName(QStringLiteral("hall_number_label"));
        hall_number_label->setGeometry(QRect(50, 40, 81, 16));
        hall_number_label->setStyleSheet(QLatin1String("color: rgb(85, 0, 127);\n"
""));
        CancelButton = new QPushButton(DeleteHall);
        CancelButton->setObjectName(QStringLiteral("CancelButton"));
        CancelButton->setGeometry(QRect(190, 110, 75, 23));
        CancelButton->setStyleSheet(QLatin1String("border-width : 1px;\n"
"border-style : outset;\n"
"border-color:rgb(60,170,153);"));
        DeleteHallButton = new QPushButton(DeleteHall);
        DeleteHallButton->setObjectName(QStringLiteral("DeleteHallButton"));
        DeleteHallButton->setGeometry(QRect(100, 110, 75, 23));
        DeleteHallButton->setStyleSheet(QLatin1String("background-color : transparent;\n"
"border-image: url(://Img/delete.png);\n"
"background: none;\n"
"border: none;\n"
"background-repeat : none;\n"
"\n"
""));

        retranslateUi(DeleteHall);

        QMetaObject::connectSlotsByName(DeleteHall);
    } // setupUi

    void retranslateUi(QDialog *DeleteHall)
    {
        DeleteHall->setWindowTitle(QApplication::translate("DeleteHall", "Dialog", Q_NULLPTR));
        hall_number_label->setText(QApplication::translate("DeleteHall", " Hall number :", Q_NULLPTR));
        CancelButton->setText(QApplication::translate("DeleteHall", "Cancel", Q_NULLPTR));
        DeleteHallButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DeleteHall: public Ui_DeleteHall {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETEHALL_H
