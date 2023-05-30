#include <fstream>
#include <string>

class AgregarElemento {
protected:
    std::ofstream archivo;

public:
    AgregarElemento() {
        archivo.open("reporte.txt", std::ios::app);
    }

    ~AgregarElemento() {
        archivo.close();
    }
};
