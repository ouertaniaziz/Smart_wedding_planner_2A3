#ifndef AJOUTERDECORATEUR_H
#define AJOUTERDECORATEUR_H

#include <QWidget>

namespace Ui {
class AjouterDecorateur;
}

class AjouterDecorateur : public QWidget
{
    Q_OBJECT

public:
    explicit AjouterDecorateur(QWidget *parent = nullptr);
    ~AjouterDecorateur();

private slots:
    void on_RetourButton_clicked();

private:
    Ui::AjouterDecorateur *ui;
};

#endif // AJOUTERDECORATEUR_H
