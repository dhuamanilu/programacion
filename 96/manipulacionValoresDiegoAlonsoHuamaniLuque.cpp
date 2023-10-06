//Autor : Diego Alonso Huamani Luque
#include <iostream>
#include <string>
#include "Carro.h"

int main() {
    /* Crear objetos de la clase Carro utilizando
    diferentes constructores*/
    Carro carro1; // Constructor por defecto
    Carro carro2("Juan", 1000.0); // Constructor parametrizado

    // Utilizar el constructor copia
    Carro carro3 = carro2;

    // Mostrar información de los carros
    std::cout << "Carro 1 - Duenio: "
    << carro1.GetNombreDueno() << ", Kilometros: "
    << carro1.GetKilometrosRecorridos() << std::endl;
    std::cout << "Carro 2 - Duenio: "
    << carro2.GetNombreDueno() << ", Kilometros: "
    << carro2.GetKilometrosRecorridos() << std::endl;
    std::cout << "Carro 3 - Duenio: "
    << carro3.GetNombreDueno() << ", Kilometros: "
    << carro3.GetKilometrosRecorridos() << std::endl;

    return 0;
}
