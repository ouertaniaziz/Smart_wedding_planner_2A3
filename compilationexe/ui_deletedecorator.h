/********************************************************************************
** Form generated from reading UI file 'deletedecorator.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETEDECORATOR_H
#define UI_DELETEDECORATOR_H

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

class Ui_DeleteDecorator
{
public:
    QLineEdit *decorator_id_line;
    QPushButton *DeleteHallButton;
    QLabel *decorator_number_label;
    QPushButton *CancelButton;

    void setupUi(QDialog *DeleteDecorator)
    {
        if (DeleteDecorator->objectName().isEmpty())
            DeleteDecorator->setObjectName(QStringLiteral("DeleteDecorator"));
        DeleteDecorator->resize(400, 159);
        decorator_id_line = new QLineEdit(DeleteDecorator);
        decorator_id_line->setObjectName(QStringLiteral("decorator_id_line"));
        decorator_id_line->setGeometry(QRect(180, 40, 101, 21));
        decorator_id_line->setStyleSheet(QLatin1String("QLineEdit{\n"
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
        DeleteHallButton = new QPushButton(DeleteDecorator);
        DeleteHallButton->setObjectName(QStringLiteral("DeleteHallButton"));
        DeleteHallButton->setGeometry(QRect(120, 110, 75, 23));
        DeleteHallButton->setStyleSheet(QLatin1String("background-color : transparent;\n"
"border-image: url(://Img/delete.png);\n"
"background: none;\n"
"border: none;\n"
"background-repeat : none;\n"
"\n"
""));
        decorator_number_label = new QLabel(DeleteDecorator);
        decorator_number_label->setObjectName(QStringLiteral("decorator_number_label"));
        decorator_number_label->setGeometry(QRect(60, 40, 101, 20));
        decorator_number_label->setStyleSheet(QLatin1String("color: rgb(85, 0, 127);\n"
""));
        CancelButton = new QPushButton(DeleteDecorator);
        CancelButton->setObjectName(QStringLiteral("CancelButton"));
        CancelButton->setGeometry(QRect(210, 110, 75, 23));
        CancelButton->setStyleSheet(QLatin1String("border-width : 1px;\n"
"border-style : outset;\n"
"border-color:rgb(60,170,153);"));

        retranslateUi(DeleteDecorator);

        QMetaObject::connectSlotsByName(DeleteDecorator);
    } // setupUi

    void retranslateUi(QDialog *DeleteDecorator)
    {
        DeleteDecorator->setWindowTitle(QApplication::translate("DeleteDecorator", "Dialog", Q_NULLPTR));
        DeleteHallButton->setText(QString());
        decorator_number_label->setText(QApplication::translate("DeleteDecorator", " Decorator number :", Q_NULLPTR));
        CancelButton->setText(QApplication::translate("DeleteDecorator", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DeleteDecorator: public Ui_DeleteDecorator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETEDECORATOR_H
