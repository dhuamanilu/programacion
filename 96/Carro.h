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

    // Setter para el nombre del due�o
    void SetNombreDueno(std::string nombre) {
        nombreDueno = nombre;
    }

    // Getter para el nombre del due�o
    std::string GetNombreDueno() {
        return nombreDueno;
    }

    // Setter para los kil�metros recorridos
    void SetKilometrosRecorridos(double km) {
        kilometrosRecorridos = km;
    }

    // Getter para los kil�metros recorridos
    double GetKilometrosRecorridos() {
        return kilometrosRecorridos;
    }
//Atributos privados por la encapsulacion
private:
    std::string nombreDueno;
    double kilometrosRecorridos;
};
