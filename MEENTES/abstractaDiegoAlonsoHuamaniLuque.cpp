//Autor :Diego Alonso Huamani Luque
#include <iostream>
#include "Vehiculo.h"

int main() {
    // Crear objetos de clases derivadas
    Coche miCoche;
    Moto miMoto;

    // Llamar a métodos
    miCoche.Arrancar();
    miCoche.Parar();

    miMoto.Arrancar();
    miMoto.Parar();

    return 0;
}
