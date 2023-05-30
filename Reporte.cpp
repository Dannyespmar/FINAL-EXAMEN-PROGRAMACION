#include <iostream>
#include <fstream>
#include <string>

class Reporte {
public:
    void mostrarReporteProductos() {
        std::ifstream archivo("reporte.txt");
        std::string linea;

        std::cout << "Reporte de productos:" << std::endl;

        while (std::getline(archivo, linea)) {
            std::string tipo = linea.substr(0, linea.find(","));
            linea = linea.substr(linea.find(",") + 1);

            if (tipo == "MOTO" || tipo == "REPUESTO") {
                std::string nombre = linea.substr(0, linea.find(","));
                linea = linea.substr(linea.find(",") + 1);
                int stock = std::stoi(linea.substr(0, linea.find(",")));
                linea = linea.substr(linea.find(",") + 1);
                std::string categoria = linea.substr(0, linea.find(","));
                linea = linea.substr(linea.find(",") + 1);
                std::string fechaRegistro = linea;

                std::cout << "Tipo: " << tipo << std::endl;
                std::cout << "Nombre: " << nombre << std::endl;
                std::cout << "Stock: " << stock << std::endl;
                std::cout << "Categoría: " << categoria << std::endl;
                std::cout << "Fecha de Registro: " << fechaRegistro << std::endl;
                std::cout << "-------------------------" << std::endl;
            }
        }

        archivo.close();
    }

    void mostrarReporteServicios() {
        std::ifstream archivo("reporte.txt");
        std::string linea;

        std::cout << "Reporte de servicios:" << std::endl;

        while (std::getline(archivo, linea)) {
            std::string tipo = linea.substr(0, linea.find(","));
            linea = linea.substr(linea.find(",") + 1);

            if (tipo == "SERVICIO") {
                std::string servicio = linea.substr(0, linea.find(","));
                linea = linea.substr(linea.find(",") + 1);
                std::string realizador = linea.substr(0, linea.find(","));
                linea = linea.substr(linea.find(",") + 1);
                int tiempo = std::stoi(linea.substr(0, linea.find(",")));
                linea = linea.substr(linea.find(",") + 1);
                std::string repuestos = linea;

                std::cout << "Servicio: " << servicio << std::endl;
                std::cout << "Realizador: " << realizador << std::endl;
                std::cout << "Tiempo: " << tiempo << " minutos" << std::endl;
                std::cout << "Repuestos: " << repuestos << std::endl;
                std::cout << "-------------------------" << std::endl;
            }
        }

        archivo.close();
    }

    void mostrarReporteClientes() {
        std::ifstream archivo("reporte.txt");
        std::string linea;

        std::cout << "Reporte de clientes:" << std::endl;

        while (std::getline(archivo, linea)) {
            std::string tipo = linea.substr(0, linea.find(","));
            linea = linea.substr(linea.find(",") + 1);

            if (tipo == "CLIENTE") {
                std::string nombreCliente = linea.substr(0, linea.find(","));
                linea = linea.substr(linea.find(",") + 1);
                std::string compra = linea.substr(0, linea.find(","));
                linea = linea.substr(linea.find(",") + 1);
                std::string fecha = linea;

                std::cout << "Nombre del Cliente: " << nombreCliente << std::endl;
                std::cout << "Compra: " << compra << std::endl;
                std::cout << "Fecha: " << fecha << std::endl;
                std::cout << "-------------------------" << std::endl;
            }
        }

        archivo.close();
    }
};
