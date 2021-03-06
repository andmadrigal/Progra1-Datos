#ifndef VAGREGAPASAJERO_H
#define VAGREGAPASAJERO_H

#include <QDialog>
#include "pasajero.h"
#include "tren.h"

namespace Ui {
class vagregapasajero;
}

class vagregapasajero : public QDialog
{
    Q_OBJECT

public:
    explicit vagregapasajero(QWidget *parent = 0);
    ~vagregapasajero();
    listaPasajero *colaEspera = new listaPasajero();
    listaPasajero *colaTicket = new listaPasajero();
    listaTrenes *colaTrenes = new listaTrenes();
private slots:
    void on_btnVolver_clicked();

    void on_btnAgregar_clicked();

private:
    Ui::vagregapasajero *ui;
};

#endif // VAGREGAPASAJERO_H
