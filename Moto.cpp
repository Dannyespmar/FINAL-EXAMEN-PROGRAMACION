#include <iostream>
#include <string>
#include "AgregarElemento.h"

class Moto : public AgregarElemento {
public:
    void agregarMoto() {
        std::string nombre, categoria, fechaRegistro;
        int stock;

        std::cout << "Ingrese el nombre de la moto: ";
        std::cin.ignore();
        std::getline(std::cin, nombre);
        std::cout << "Ingrese la categoría de la moto: ";
        std::getline(std::cin, categoria);
        std::cout << "Ingrese el stock de la moto: ";
        std::cin >> stock;
        std::cout << "Ingrese la fecha de registro de la moto: ";
        std::cin.ignore();
        std::getline(std::cin, fechaRegistro);

        archivo << "MOTO," << nombre << "," << stock << "," << categoria << "," << fechaRegistro << std::endl;

        std::cout << "Moto agregada correctamente." << std::endl;
    }
};
