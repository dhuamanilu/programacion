#include <iostream>
#include <fstream>
#include <string>
using namespace std;


void pausa() {
    cout << "Presiona Enter para continuar...";
    cin.ignore();
}


int main() {
    string nombreArchivo;
    cout << "Ingrese el nombre del archivo: ";
    getline(cin, nombreArchivo);


    ifstream archivo(nombreArchivo);


    if (!archivo) {
        cout << "No se pudo abrir el archivo." << endl;
        return 1;
    }


    const int lineasPorPausa = 25;
    int contadorLineas = 0;
    string linea;


    while (getline(archivo, linea)) {
        cout << linea << endl;
        contadorLineas++;


        if (contadorLineas % lineasPorPausa == 0) {
            pausa();
        }
    }


    archivo.close();


    return 0;
}
