#include "principal.h"
#include <QApplication>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include "pasajero.h"
#include "tren.h"

listaPasajero *pasajeros = new listaPasajero();
trenes listTrenes = new listaTrenes();

void cargarPasajeros(){
    QFile file("/home/shiki/Documentos/Datos/I Proyecto/I_Proyecto/Datos/Pasajeros.xlsx");
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        qDebug() << "No se pudo cargar el archivo de pasajeros";
        return;
    }
    pasajero nuevo;

    QTextStream in(&file);
    QString nombre;
    QString apellido;
    int id;
    int telf;
    QString nacio;
    int peso;
    int estatura;
    QString destino;
    QStringList data;
    while(!in.atEnd()){
        QString line = in.readLine();
        data = line.split(",");
        nombre = data.at(0);
        apellido = data.at(1);
        id = data.at(2).toInt();
        telf = data.at(3).toInt();
        nacio = data.at(4);
        peso = data.at(5).toInt();
        estatura = data.at(6).toInt();
        destino = "";

        nuevo = new Pasajero(nombre, apellido, id, telf, nacio, peso, estatura, destino);
        pasajeros->insertar(nuevo);
    }
    file.flush();
    file.close();

}

void cargarTrenes(){
    QFile file("/home/shiki/Documentos/Datos/I Proyecto/I_Proyecto/Datos/Trenes.xlsx");
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        qDebug() << "No se pudo cargar el archivo de trenes";
        return;
    }
    tren nuevo;
    QTextStream in(&file);
    QString destino;
    QString capitan;
    int placa;
    QStringList data;
    while(!in.atEnd()){
        QString line = in.readLine();
        data = line.split(",");
        destino = "";
        capitan = data.at(0);
        placa = data.at(1).toInt();

        nuevo = new Tren(destino, capitan, placa);
        listTrenes->insertar(nuevo);
    }
    file.flush();
    file.close();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    cargarPasajeros();
    cargarTrenes();


    Principal w;
    w.show();

    return a.exec();
}