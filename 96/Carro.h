//Autor : Diego Alonso Huamani Luque
class Carro {
public:
    // Constructor por defecto
    Carro() {
        nombreDueno = "Sin duenio";
        kilometrosRecorridos = 0;
    }

    // Constructor parametrizado
    Carro(std::string nombre, double km) {
        nombreDueno = nombre;
        kilometrosRecorridos = km;
    }

    // Constructor copia
    Carro(const Carro& otroCarro) {
        nombreDueno = otroCarro.nombreDueno;
        kilometrosRecorridos = otroCarro.kilometrosRecorridos;
    }

    // Setter para el nombre del dueño
    void SetNombreDueno(std::string nombre) {
        nombreDueno = nombre;
    }

    // Getter para el nombre del dueño
    std::string GetNombreDueno() {
        return nombreDueno;
    }

    // Setter para los kilómetros recorridos
    void SetKilometrosRecorridos(double km) {
        kilometrosRecorridos = km;
    }

    // Getter para los kilómetros recorridos
    double GetKilometrosRecorridos() {
        return kilometrosRecorridos;
    }
//Atributos privados por la encapsulacion
private:
    std::string nombreDueno;
    double kilometrosRecorridos;
};
