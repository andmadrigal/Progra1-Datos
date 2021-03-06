#include "vagregaequipaje.h"
#include "ui_vagregaequipaje.h"
#include "vagregapasajero.h"
#include "equipaje.h"
#include "principal.h"
#include <QDebug>

vagregaequipaje::vagregaequipaje(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::vagregaequipaje)
{
    ui->setupUi(this);
}

vagregaequipaje::~vagregaequipaje()
{
    delete ui;
}

void vagregaequipaje::on_btnVolver_clicked()
{
    vagregapasajero *v = new vagregapasajero();
    v->colaEspera = this->colaEspera;
    v->colaTicket = this->colaTicket;
    v->colaTrenes = this->colaTrenes;

    v->setVisible(true);
    this->close();
    v->exec();
}

void vagregaequipaje::on_btnAgregar_clicked()
{
    int peso = ui->txfPeso->text().toInt();
    bool isMano = ui->chxMano->checkState() == 1;

    Equipaje *nuevo = new Equipaje(peso, this->amo, isMano);
    this->amo->equipaje->insertar(nuevo);
    this->colaTicket->insertar(this->amo);

    Principal *p = new Principal();
    p->colaEspera = this->colaEspera;
    p->colaTicket = this->colaTicket;
    p->colaTrenes = this->colaTrenes;
    p->show();
    this->close();
}
