#ifndef SALLE_H
#define SALLE_H

#include <QWidget>

namespace Ui {
class Salle;
}

class Salle : public QWidget
{
    Q_OBJECT

public:
    explicit Salle(QWidget *parent = nullptr);
    ~Salle();

private slots:
    void on_pushButton_4_clicked();

    void on_ajouter_decorateurButton_clicked();

    void on_RetourButton_clicked();

private:
    Ui::Salle *ui;
};

#endif // SALLE_H
