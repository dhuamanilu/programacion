#include <iostream>
#include <fstream>
#include "exceptions.h"

// Funcion de ejemplo para leer un archivo de texto
void readFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw InputException::FileNotFound(filename);
    }

    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }

    file.close();
}

// Funcion de ejemplo para escribir datos en un archivo
void writeFile(const std::string& filename, const std::string& data) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw OutputException::WriteError(filename);
    }

    file << data;

    file.close();
}

// Funcion de ejemplo para realizar una operacion matematica
int performOperation(int a, int b) {
    if (b == 0) {
        throw ProcessorException::DivisionByZero();
    }

    return a / b;
}

int main() {
    std::string filename;
    bool fileFound = false;

    do {
        std::cout << "Ingrese el nombre del archivo: ";
        std::cin >> filename;

        try {
            readFile(filename);
            fileFound = true;
        } catch (const InputException& e) {
            std::cout << "Error de entrada: " << e.what() << std::endl;
            // Volver a pedir el nombre del archivo si no se encuentra
        } catch (const ComputerException& e) {
            std::cout << "Error general del computador: " << e.what() << std::endl;
            // Manejar cualquier otro error general del computador
            break;
        } catch (const std::exception& e) {
            std::cout << "Error desconocido: " << e.what() << std::endl;
            // Manejar cualquier otro error desconocido
            break;
        }
    } while (!fileFound);

    if (fileFound) {
        try {
            int dividendo,divisor;
            std::cout << "Ingrese dividendo :";
            std::cin >> dividendo;
            std::cout << "Ingrese divisor :";
            std::cin >> divisor;
            int result = performOperation(dividendo, divisor);
            std::cout << "Escribiendo resultado en archivo..." << std::endl;
            writeFile("resultado.txt", std::to_string(result));
            std::cout << "Operacion completada." << std::endl;

        } catch (const ProcessorException& e) {
            std::cout << "Error de procesador: " << e.what() << std::endl;
            // Manejar el error especifico de procesador, si es posible
        } catch (const OutputException& e) {
            std::cout << "Error de salida: " << e.what() << std::endl;
            // Manejar el error especifico de salida, si es posible
        } catch (const ComputerException& e) {
            std::cout << "Error general del computador: " << e.what() << std::endl;
            // Manejar cualquier otro error general del computador
        } catch (const std::exception& e) {
            std::cout << "Error desconocido: " << e.what() << std::endl;
            // Manejar cualquier otro error desconocido
        }
    }
    return 0;
}
