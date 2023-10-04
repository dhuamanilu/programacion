//Autor : Diego Alonso Huamani Luque
#include <iostream>
#include <string>
#include <vector>
#include "Persona.h"

class Abuelo : public Persona {
public:
    Abuelo(const std::string& nombre, const std::string& genero, int edad, const std::string& apellido)
        : Persona(nombre, genero, edad), apellido_(apellido) {}

    std::string getApellido() const { return apellido_; }

private:
    std::string apellido_;
};
class Hijo;
class Padre : public Persona {
public:
    Padre(const std::string& nombre, const std::string& genero, int edad, const std::string& apellido)
        : Persona(nombre, genero, edad), apellido_(apellido) {}

    void agregarHijo(const Hijo& hijo) {
        hijos_.push_back(hijo);
    }

    std::vector<Hijo> getHijos() const { return hijos_; }

private:
    std::string apellido_;
    std::vector<Hijo> hijos_;
};
class Hijo : public Persona {
public:
    Hijo(const std::string& nombre, const std::string& genero, int edad, const Padre& madre, const Padre& padre)
        : Persona(nombre, genero, edad), madre_(madre), padre_(padre) {}

    Padre getMadre() const { return madre_; }
    Padre getPadre() const { return padre_; }

private:
    Padre madre_;
    Padre padre_;
};


int main() {
    Abuelo abuelo("Diego", "Masculino", 70, "Vidal");
    Padre padre("Pedro", "Masculino", 45, "Gomez");
    Padre madre("Juana","Femenino",26,"Perez");
    Hijo hijo("Eduardo", "Masculino", 20, padre, madre);

    padre.agregarHijo(hijo);

    std::cout << "Arbol genealogico creado." << std::endl;

    return 0;
}
