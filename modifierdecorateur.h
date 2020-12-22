#ifndef MODIFIERDECORATEUR_H
#define MODIFIERDECORATEUR_H

#include <QWidget>

namespace Ui {
class ModifierDecorateur;
}

class ModifierDecorateur : public QWidget
{
    Q_OBJECT

public:
    explicit ModifierDecorateur(QWidget *parent = nullptr);
    ~ModifierDecorateur();

private slots:
    void on_RetourButton_clicked();

private:
    Ui::ModifierDecorateur *ui;
};

#endif // MODIFIERDECORATEUR_H
