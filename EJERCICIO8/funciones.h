#include <bits/stdc++.h>
#include "Persona.h"
using namespace std;
void agregarPersona(std::vector<Persona>& personas) {
    Persona nuevaPersona;

    while (true) {
        if(personas.size() == 50){
            break;
        }

        std::cout << "Ingrese nombre (deje vacio para salir): ";
        getline(cin, nuevaPersona.nombre);
        if(nuevaPersona.nombre.length() == 0){
            break;
        }


        std::cout << "Ingrese direccion: ";
        std::getline(std::cin >> std::ws, nuevaPersona.direccion);

        std::cout << "Ingrese telefono: ";
        std::getline(std::cin >> std::ws, nuevaPersona.telefono);

        std::cout << "Ingrese edad: ";
        std::cin >> nuevaPersona.edad;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        personas.push_back(nuevaPersona);
    }
}



void mostrarNombres(const std::vector<Persona>& personas) {
    std::cout << "Lista de nombres:\n";
    for (const auto& persona : personas) {
        std::cout << persona.nombre << std::endl;
    }
    std::cout << std::endl;
}

void mostrarPersonasPorEdad(const std::vector<Persona>& personas) {
    int edad;
    std::cout << "Ingrese la edad: ";
    std::cin >> edad;

    std::cout << "Personas de " << edad << " anios:\n";
    for (auto & persona : personas) {
        if (persona.edad == edad) {
            std::cout << "Nombre: " << persona.nombre << std::endl;
            std::cout << "Direccion: " << persona.direccion << std::endl;
            std::cout << "Telefono: " << persona.telefono << std::endl;
            std::cout << "Edad: " << persona.edad << std::endl;
            std::cout << std::endl;
        }
    }
}

void mostrarPersonasPorInicial(const std::vector<Persona>& personas) {
    char inicial;
    std::cout << "Ingrese la inicial: ";
    std::cin >> inicial;

    std::cout << "Personas cuya inicial es " << inicial << ":\n";
    for (const auto& persona : personas) {
        if (persona.nombre[0] == inicial) {
            std::cout << "Nombre: " << persona.nombre << std::endl;
            std::cout << "Direccion: " << persona.direccion << std::endl;
            std::cout << "Telefono: " << persona.telefono << std::endl;
            std::cout << "Edad: " << persona.edad << std::endl;
            std::cout << std::endl;
        }
    }
}
void mostrarMenu(std::vector<Persona>& personas) {
    int opcion;

    while (true) {
        std::cout << "----- Menu -----\n";
        std::cout << "1. Mostrar lista de nombres\n";
        std::cout << "2. Mostrar personas por edad\n";
        std::cout << "3. Mostrar personas por inicial\n";
        std::cout << "4. Salir\n";
        std::cout << "Ingrese una opcion: ";
        std::cin >> opcion;

        // Limpiar el buffer de entrada
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (opcion) {
            case 1:
                mostrarNombres(personas);
                break;
            case 2:
                mostrarPersonasPorEdad(personas);
                break;
            case 3:
                mostrarPersonasPorInicial(personas);
                break;
            case 4:
                return;  // Salir del programa
            default:
                std::cout << "Opcion invalida. Por favor, intente nuevamente.\n";
                break;
        }

        std::cout << std::endl;
    }
}
