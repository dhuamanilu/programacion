#include <iostream>
#include <stdexcept>

class ComputerException : public std::exception {
protected:
    std::string message;

public:
    ComputerException(const std::string& msg) : message(msg) {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};

class InputException : public ComputerException {
public:
    InputException(const std::string& msg) : ComputerException(msg) {}

    // Errores relacionados con la entrada
    static InputException FileNotFound(const std::string& filename) {
        return InputException("Error: Archivo no encontrado: " + filename);
    }

    static InputException ReadError(const std::string& filename) {
        return InputException("Error: No se pudo leer el archivo: " + filename);
    }

    static InputException InvalidInput(const std::string& input) {
        return InputException("Error: Entrada no valida " + input);
    }

    static InputException EndOfFile() {
        return InputException("Error: Fin del archivo encontrado");
    }

    // Otros errores relacionados con la entrada...
};

class ProcessorException : public ComputerException {
public:
    ProcessorException(const std::string& msg) : ComputerException(msg) {}

    // Errores relacionados con el procesador
    static ProcessorException Overheat() {
        return ProcessorException("Error: sobrecalentamiento del procesador");
    }

    static ProcessorException InvalidInstruction() {
        return ProcessorException("Error: Instruccion invalida");
    }

    static ProcessorException DivisionByZero() {
        return ProcessorException("Error: Division por cero");
    }

    static ProcessorException StackOverflow() {
        return ProcessorException("Error: Stack overflow");
    }

    // Otros errores relacionados con el procesador...
};

class OutputException : public ComputerException {
public:
    OutputException(const std::string& msg) : ComputerException(msg) {}

    // Errores relacionados con la salida
    static OutputException WriteError(const std::string& filename) {
        return OutputException("Error: No se pudo escribir en el archivo: " + filename);
    }

    static OutputException NetworkError() {
        return OutputException("Error: Conexion de red fallida");
    }

    static OutputException InsufficientSpace() {
        return OutputException("Error: Espacio Insuficiente");
    }

    static OutputException InvalidFormat() {
        return OutputException("Error: Invalid format");
    }

    // Otros errores relacionados con la salida...
};
