#ifndef DELETEHALL_H
#define DELETEHALL_H

#include <QDialog>

namespace Ui {
class DeleteHall;
}

class DeleteHall : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteHall(QWidget *parent = nullptr);
    ~DeleteHall();

private slots:
    void on_DeleteHallButton_clicked();

    void on_CancelButton_clicked();

private:
    Ui::DeleteHall *ui;
};

#endif // DELETEHALL_H
