/*Autor :Diego Alonso Huamani Luque
 Clase abstracta base para vehículos*/
class Vehiculo {
public:
    /*Al menos un método debe de ser virtual puro para que
    una clase sea abstracta,este sera
    implementado en clases derivadas,

    "= 0" indica que la función es virtual pura
    y no tiene implementación en la clase base*/

    virtual void Arrancar() = 0;

    // Método concreto
    void Parar() {
        std::cout << "El vehiculo se ha detenido." << std::endl;
    }
};

// Clase abstracta derivada de Vehiculo
class Coche : public Vehiculo {
public:
    /* Implementación del método virtual puro.
    La palabra clave override en C++ se utiliza
    para indicar explícitamente que una función
    en una clase derivada está destinada a ser
    una implementación de una función virtual
    que ya ha sido declarada en la clase base*/
    void Arrancar() override {
        std::cout << "El coche ha arrancado." << std::endl;
    }
};

// Clase abstracta derivada de Vehiculo
class Moto : public Vehiculo {
public:
    // Implementación del método virtual puro
    void Arrancar() override {
        std::cout << "La moto ha arrancado." << std::endl;
    }
};
