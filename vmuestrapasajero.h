#ifndef VMUESTRAPASAJERO_H
#define VMUESTRAPASAJERO_H

#include <QDialog>
#include "pasajero.h"
#include "tren.h"

namespace Ui {
class vmuestrapasajero;
}

class vmuestrapasajero : public QDialog
{
    Q_OBJECT

public:
    explicit vmuestrapasajero(QWidget *parent = 0);
    ~vmuestrapasajero();
    listaPasajero *colaEspera = new listaPasajero();
    listaPasajero *colaTicket = new listaPasajero();
    listaTrenes *colaTrenes = new listaTrenes();
    Pasajero *amo;

private slots:
    void on_btnVolver_clicked();

    void on_btnActualizar_clicked();

private:
    Ui::vmuestrapasajero *ui;
};

#endif // VMUESTRAPASAJERO_H
