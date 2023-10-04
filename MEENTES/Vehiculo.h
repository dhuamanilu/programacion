/*Autor :Diego Alonso Huamani Luque
 Clase abstracta base para veh�culos*/
class Vehiculo {
public:
    /*Al menos un m�todo debe de ser virtual puro para que
    una clase sea abstracta,este sera
    implementado en clases derivadas,

    "= 0" indica que la funci�n es virtual pura
    y no tiene implementaci�n en la clase base*/

    virtual void Arrancar() = 0;

    // M�todo concreto
    void Parar() {
        std::cout << "El vehiculo se ha detenido." << std::endl;
    }
};

// Clase abstracta derivada de Vehiculo
class Coche : public Vehiculo {
public:
    /* Implementaci�n del m�todo virtual puro.
    La palabra clave override en C++ se utiliza
    para indicar expl�citamente que una funci�n
    en una clase derivada est� destinada a ser
    una implementaci�n de una funci�n virtual
    que ya ha sido declarada en la clase base*/
    void Arrancar() override {
        std::cout << "El coche ha arrancado." << std::endl;
    }
};

// Clase abstracta derivada de Vehiculo
class Moto : public Vehiculo {
public:
    // Implementaci�n del m�todo virtual puro
    void Arrancar() override {
        std::cout << "La moto ha arrancado." << std::endl;
    }
};
