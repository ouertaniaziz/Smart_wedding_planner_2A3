#ifndef AJOUTERSALLE_H
#define AJOUTERSALLE_H

#include <QWidget>

namespace Ui {
class AjouterSalle;
}

class AjouterSalle : public QWidget
{
    Q_OBJECT

public:
    explicit AjouterSalle(QWidget *parent = nullptr);
    ~AjouterSalle();

private slots:
    void on_RetourButton_clicked();

private:
    Ui::AjouterSalle *ui;
};

#endif // AJOUTERSALLE_H
