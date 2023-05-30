#include <iostream>
#include <string>
#include "AgregarElemento.h"

class Servicio : public AgregarElemento {
public:
    void agregarServicio() {
        std::string servicio, realizador, repuestos;
        int tiempo;

        std::cout << "Ingrese el servicio realizado: ";
        std::cin.ignore();
        std::getline(std::cin, servicio);
        std::cout << "Ingrese el nombre de quien lo realizó: ";
        std::getline(std::cin, realizador);
        std::cout << "Ingrese el tiempo en minutos que tomó realizar el servicio: ";
        std::cin >> tiempo;
        std::cout << "Ingrese los repuestos vendidos durante el servicio: ";
        std::cin.ignore();
        std::getline(std::cin, repuestos);

        archivo << "SERVICIO," << servicio << "," << realizador << "," << tiempo << "," << repuestos << std::endl;

        std::cout << "Servicio agregado correctamente." << std::endl;
    }
};
