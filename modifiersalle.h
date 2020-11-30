#ifndef MODIFIERSALLE_H
#define MODIFIERSALLE_H

#include <QWidget>

namespace Ui {
class ModifierSalle;
}

class ModifierSalle : public QWidget
{
    Q_OBJECT

public:
    explicit ModifierSalle(QWidget *parent = nullptr);
    ~ModifierSalle();

private slots:
    void on_RetourButton_clicked();

private:
    Ui::ModifierSalle *ui;
};

#endif // MODIFIERSALLE_H
