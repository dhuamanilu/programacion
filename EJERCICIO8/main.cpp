#include <bits/stdc++.h>
#include "funciones.h"

int main() {
    std::vector<Persona> personas;

    // Agregar personas hasta que se introduzca un nombre vacío
    agregarPersona(personas);

    // Mostrar el menú
    mostrarMenu(personas);

    return 0;
}
