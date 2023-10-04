#include <iostream>
#include <map>
#include <cmath>

using namespace std;

// Definición de la estructura Nodo para la lista enlazada
struct Nodo {
    int coeficiente;
    int exponente;
    Nodo* siguiente;
};

// Clase para representar un polinomio mediante una lista enlazada
class Polinomio {
public:
    Polinomio() {
        cabeza = nullptr;
    }

    // Método para agregar un término al polinomio
    void agregarTermino(int coeficiente, int exponente) {
        Nodo* nuevoNodo = new Nodo;
        nuevoNodo->coeficiente = coeficiente;
        nuevoNodo->exponente = exponente;
        nuevoNodo->siguiente = cabeza;
        cabeza = nuevoNodo;
    }

    // Método para evaluar el polinomio en un rango [L, R] y guardar los resultados en un mapa
    void evaluarEnRango(int L, int R, map<int, int>& resultados) {
        for (int x = L; x <= R; x++) {
            int resultado = 0;
            Nodo* actual = cabeza;
            while (actual != nullptr) {
                resultado += actual->coeficiente * pow(x, actual->exponente);
                actual = actual->siguiente;
            }
            resultados[x] = resultado;
        }
    }

private:
    Nodo* cabeza;
};

int main() {
    Polinomio polinomio;
    // Agrega términos al polinomio (coeficiente, exponente)
    polinomio.agregarTermino(2, 3);
    polinomio.agregarTermino(1, 2);
    polinomio.agregarTermino(3, 1);
    polinomio.agregarTermino(4, 0);

    int L, R;
    cout << "Ingrese el valor de L (rango inferior): ";
    cin >> L;
    cout << "Ingrese el valor de R (rango superior): ";
    cin >> R;

    map<int, int> resultados;
    polinomio.evaluarEnRango(L, R, resultados);

    // Imprime los resultados
    for (const auto& par : resultados) {
        cout << "P(" << par.first << ") = " << par.second << endl;
    }

    return 0;
}
