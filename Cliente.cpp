#include <iostream>
#include <string>
#include "AgregarElemento.h"

class Cliente : public AgregarElemento {
public:
    void agregarCliente() {
        std::string nombreCliente, compra, fecha;

        std::cout << "Ingrese el nombre del cliente: ";
        std::cin.ignore();
        std::getline(std::cin, nombreCliente);
        std::cout << "Ingrese el producto o servicio comprado por el cliente: ";
        std::getline(std::cin, compra);
        std::cout << "Ingrese la fecha de la compra: ";
        std::getline(std::cin, fecha);

        archivo << "CLIENTE," << nombreCliente << "," << compra << "," << fecha << std::endl;

        std::cout << "Cliente agregado correctamente." << std::endl;
    }
};
