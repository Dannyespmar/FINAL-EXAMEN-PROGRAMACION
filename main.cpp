#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class AgregarElemento {
protected:
    ofstream archivo;

public:
    AgregarElemento() {
        archivo.open("reporte.txt", ios::app);
    }

    ~AgregarElemento() {
        archivo.close();
    }
};

class Moto : public AgregarElemento {
public:
    void agregarMoto() {
        string nombre, categoria, fechaRegistro;
        int stock;

        cout << "Ingrese el nombre de la moto: ";
        cin.ignore();
        getline(cin, nombre);
        cout << "Ingrese la categoria de la moto: ";
        getline(cin, categoria);
        cout << "Ingrese el stock de la moto: ";
        cin >> stock;
        cout << "Ingrese la fecha de registro de la moto: ";
        cin.ignore();
        getline(cin, fechaRegistro);

        archivo << "MOTO," << nombre << "," << stock << "," << categoria << "," << fechaRegistro << endl;

        cout << "Moto agregada correctamente." << endl;
    }
};

class Repuesto : public AgregarElemento {
public:
    void agregarRepuesto() {
        string nombre, categoria, fechaRegistro;
        int stock;

        cout << "Ingrese el nombre del repuesto: ";
        cin.ignore();
        getline(cin, nombre);
        cout << "Ingrese la categoria del repuesto: ";
        getline(cin, categoria);
        cout << "Ingrese el stock del repuesto: ";
        cin >> stock;
        cout << "Ingrese la fecha de registro del repuesto: ";
        cin.ignore();
        getline(cin, fechaRegistro);

        archivo << "REPUESTO," << nombre << "," << stock << "," << categoria << "," << fechaRegistro << endl;

        cout << "Repuesto agregado correctamente." << endl;
    }
};

class Servicio : public AgregarElemento {
public:
    void agregarServicio() {
        string servicio, realizador, repuestos;
        int tiempo;

        cout << "Ingrese el servicio realizado: ";
        cin.ignore();
        getline(cin, servicio);
        cout << "Ingrese el nombre de quien lo realizo: ";
        getline(cin, realizador);
        cout << "Ingrese el tiempo en minutos que tomo realizar el servicio: ";
        cin >> tiempo;
        cout << "Ingrese los repuestos vendidos durante el servicio: ";
        cin.ignore();
        getline(cin, repuestos);

        archivo << "SERVICIO," << servicio << "," << realizador << "," << tiempo << "," << repuestos << endl;

        cout << "Servicio agregado correctamente." << endl;
    }
};

class Cliente : public AgregarElemento {
public:
    void agregarCliente() {
        string nombreCliente, compra, fecha;

        cout << "Ingrese el nombre del cliente: ";
        cin.ignore();
        getline(cin, nombreCliente);
        cout << "Ingrese el producto o servicio comprado por el cliente: ";
        getline(cin, compra);
        cout << "Ingrese la fecha de la compra: ";
        getline(cin, fecha);

        archivo << "CLIENTE," << nombreCliente << "," << compra << "," << fecha << endl;

        cout << "Cliente agregado correctamente." << endl;
    }
};

class Reporte {
public:
    void mostrarReporteProductos() {
        ifstream archivo("reporte.txt");
        string linea;

        cout << "Reporte de productos:" << endl;

        while (getline(archivo, linea)) {
            string tipo = linea.substr(0, linea.find(","));
            linea = linea.substr(linea.find(",") + 1);

            if (tipo == "MOTO" || tipo == "REPUESTO") {
                string nombre = linea.substr(0, linea.find(","));
                linea = linea.substr(linea.find(",") + 1);
                int stock = stoi(linea.substr(0, linea.find(",")));
                linea = linea.substr(linea.find(",") + 1);
                string categoria = linea.substr(0, linea.find(","));
                linea = linea.substr(linea.find(",") + 1);
                string fechaRegistro = linea;

                cout << "Tipo: " << tipo << endl;
                cout << "Nombre: " << nombre << endl;
                cout << "Stock: " << stock << endl;
                cout << "Categoria: " << categoria << endl;
                cout << "Fecha de Registro: " << fechaRegistro << endl;
                cout << "-------------------------" << endl;
            }
        }

        archivo.close();
    }

    void mostrarReporteServicios() {
        ifstream archivo("reporte.txt");
        string linea;

        cout << "Reporte de servicios:" << endl;

        while (getline(archivo, linea)) {
            string tipo = linea.substr(0, linea.find(","));
            linea = linea.substr(linea.find(",") + 1);

            if (tipo == "SERVICIO") {
                string servicio = linea.substr(0, linea.find(","));
                linea = linea.substr(linea.find(",") + 1);
                string realizador = linea.substr(0, linea.find(","));
                linea = linea.substr(linea.find(",") + 1);
                int tiempo = stoi(linea.substr(0, linea.find(",")));
                linea = linea.substr(linea.find(",") + 1);
                string repuestos = linea;

                cout << "Servicio: " << servicio << endl;
                cout << "Realizador: " << realizador << endl;
                cout << "Tiempo: " << tiempo << " minutos" << endl;
                cout << "Repuestos: " << repuestos << endl;
                cout << "-------------------------" << endl;
            }
        }

        archivo.close();
    }

    void mostrarReporteClientes() {
        ifstream archivo("reporte.txt");
        string linea;

        cout << "Reporte de clientes:" << endl;

        while (getline(archivo, linea)) {
            string tipo = linea.substr(0, linea.find(","));
            linea = linea.substr(linea.find(",") + 1);

            if (tipo == "CLIENTE") {
                string nombreCliente = linea.substr(0, linea.find(","));
                linea = linea.substr(linea.find(",") + 1);
                string compra = linea.substr(0, linea.find(","));
                linea = linea.substr(linea.find(",") + 1);
                string fecha = linea;

                cout << "Nombre del Cliente: " << nombreCliente << endl;
                cout << "Compra: " << compra << endl;
                cout << "Fecha: " << fecha << endl;
                cout << "-------------------------" << endl;
            }
        }

        archivo.close();
    }
};

class Motorin : public Moto, public Repuesto, public Servicio, public Cliente, public Reporte {
public:
    void mostrarMenu() {
        int opcion;

        do {
            cout << "----- MOTORIN -----" << endl;
            cout << "1. Aniadir moto" << endl;
            cout << "2. Aniadir repuesto de moto" << endl;
            cout << "3. Aniadir servicios del taller" << endl;
            cout << "4. Aniadir clientes mas comunes" << endl;
            cout << "5. Ver reporte de productos" << endl;
            cout << "6. Ver reporte de servicios" << endl;
            cout << "7. Ver reporte de clientes" << endl;
            cout << "8. Salir" << endl;
            cout << "Ingrese una opcion: ";
            cin >> opcion;

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
                    cout << "Saliendo del programa..." << endl;
                    break;
                default:
                    cout << "Opcion invalida. Intente nuevamente." << endl;
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
