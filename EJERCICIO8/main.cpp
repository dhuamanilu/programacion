#include <bits/stdc++.h>
#include "funciones.h"

int main() {
    std::vector<Persona> personas;

    // Agregar personas hasta que se introduzca un nombre vac�o
    agregarPersona(personas);

    // Mostrar el men�
    mostrarMenu(personas);

    return 0;
}
