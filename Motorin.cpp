#include <iostream>

class Motorin : public Moto, public Repuesto, public Servicio, public Cliente, public Reporte {
public:
    void mostrarMenu() {
        int opcion;

        do {
            std::cout << "----- MOTORIN -----" << std::endl;
            std::cout << "1. Añadir moto" << std::endl;
            std::cout << "2. Añadir repuesto de moto" << std::endl;
            std::cout << "3. Añadir servicios del taller" << std::endl;
            std::cout << "4. Añadir clientes más comunes" << std::endl;
            std::cout << "5. Ver reporte de productos" << std::endl;
            std::cout << "6. Ver reporte de servicios" << std::endl;
            std::cout << "7. Ver reporte de clientes" << std::endl;
            std::cout << "8. Salir" << std::endl;
            std::cout << "Ingrese una opción: ";
            std::cin >> opcion;

            switch (opcion) {
                case 1:
                    agregarMoto();
                    break;
                case 2:
                    agregarRepuesto();
                    break;
                case 3:
                    agregarServicio();
                    break;
                case 4:
                    agregarCliente();
                    break;
                case 5:
                    mostrarReporteProductos();
                    break;
                case 6:
                    mostrarReporteServicios();
                    break;
                case 7:
                    mostrarReporteClientes();
                    break;
                case 8:
                    std::cout << "Saliendo del programa..." << std::endl;
                    break;
                default:
                    std::cout << "Opción inválida. Intente nuevamente." << std::endl;
                    break;
            }
        } while (opcion != 8);
    }
};

int main() {
    Motorin motorin;
    motorin.mostrarMenu();
    return 0;
}
