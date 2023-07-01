#include <iostream>
#include <string>

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

    void addAdditionalInfo(const std::string& info) {
        message += " Additional Info: " + info;
    }
};

class ProcessorException : public ComputerException {
public:
    ProcessorException(const std::string& msg) : ComputerException(msg) {}

    void addErrorCode(int code) {
        message += " Error Code: " + std::to_string(code);
    }
};

class OutputException : public ComputerException {
public:
    OutputException(const std::string& msg) : ComputerException(msg) {}

    void addReason(const std::string& reason) {
        message += " Reason: " + reason;
    }
};

// Ejemplo de uso

void processInputFile(const std::string& filePath) {
    try {
        // Intenta abrir y procesar el archivo de entrada
        if (filePath.empty()) {
            // No se proporcion� una ruta de archivo v�lida
            throw InputException("No se proporcion� una ruta de archivo v�lida");
        }

        // Realizar alguna operaci�n de entrada
    } catch (const std::ifstream::failure& e) {
        // Error de entrada/salida al procesar el archivo
        InputException ex("Error de entrada/salida al procesar el archivo: " + filePath);
        ex.addAdditionalInfo(e.what());
        throw ex;
    }
}

void processData() {
    try {
        // Realizar alg�n procesamiento de datos
        int result = 5 / 0;  // Simulaci�n de un error de divisi�n por cero
    } catch (const std::exception& e) {
        // Error espec�fico de procesamiento
        ProcessorException ex("Error de procesamiento de datos");
        ex.addErrorCode(123);
        ex.addAdditionalInfo(e.what());
        throw ex;
    }
}

void outputResult() {
    try {
        // Realizar alguna operaci�n de salida
        if (true) {
            // Simulaci�n de un error de salida
            throw std::runtime_error("Error en la operaci�n de salida");
        }
    } catch (const std::exception& e) {
        // Error espec�fico de salida
        OutputException ex("Error al realizar la operaci�n de salida");
        ex.addReason("Error en el dispositivo de salida");
        ex.addAdditionalInfo(e.what());
        throw ex;
    }
}

// Uso de las excepciones en el programa principal

int main() {
    try {
        std::string filePath;
        std::cout << "Introduce la ruta del archivo: ";
        std::cin >> filePath;

        processInputFile(filePath);
        processData();
        outputResult();
    } catch (const InputException& e) {
        std::cout << "Error en la entrada: " << e.what() << std::endl;
    } catch (const ProcessorException& e) {
        std::cout << "Error en el procesamiento: " << e.what() << std::endl;
    } catch (const OutputException& e) {
        std::cout << "Error en la salida: " << e.what() << std::endl;
    }

    return 0;
}
