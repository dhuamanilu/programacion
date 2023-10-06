class Persona {
public:
    Persona(const std::string& nombre, const std::string& genero, int edad)
        : nombre_(nombre), genero_(genero), edad_(edad) {}

    std::string getNombre() const { return nombre_; }
    std::string getGenero() const { return genero_; }
    int getEdad() const { return edad_; }

private:
    std::string nombre_;
    std::string genero_;
    int edad_;
};
