#include <iostream>
#include <string>
#include "AgregarElemento.h"

class Repuesto : public AgregarElemento {
public:
    void agregarRepuesto() {
        std::string nombre, categoria, fechaRegistro;
        int stock;

        std::cout << "Ingrese el nombre del repuesto: ";
        std::cin.ignore();
        std::getline(std::cin, nombre);
        std::cout << "Ingrese la categoría del repuesto: ";
        std::getline(std::cin, categoria);
        std::cout << "Ingrese el stock del repuesto: ";
        std::cin >> stock;
        std::cout << "Ingrese la fecha de registro del repuesto: ";
        std::cin.ignore();
        std::getline(std::cin, fechaRegistro);

        archivo << "REPUESTO," << nombre << "," << stock << "," << categoria << "," << fechaRegistro << std::endl;

        std::cout << "Repuesto agregado correctamente." << std::endl;
    }
};
