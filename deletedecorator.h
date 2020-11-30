#ifndef DELETEDECORATOR_H
#define DELETEDECORATOR_H

#include <QDialog>

namespace Ui {
class DeleteDecorator;
}

class DeleteDecorator : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteDecorator(QWidget *parent = nullptr);
    ~DeleteDecorator();

private slots:
    void on_DeleteHallButton_clicked();

    void on_CancelButton_clicked();

private:
    Ui::DeleteDecorator *ui;
};

#endif // DELETEDECORATOR_H
