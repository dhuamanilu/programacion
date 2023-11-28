#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
    // Semilla para generar n�meros aleatorios
    srand(time(0));

    // Funci�n lambda para verificar si un n�mero es primo
    auto esPrimo = [](int n) {
        //si es mayor a 1000 no lo contamos
        if (n <= 1 || n>1000) {
            return false;
        }
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    };

    // Generar un vector de n�meros enteros aleatorios
    vector<int> numeros;
    for (int i = 0; i < 100; ++i) {
        numeros.push_back(rand()%10000);
    }
    cout<<"Los elementos del vector son :\n";
    for(auto & e: numeros){
        cout<<e<<" ";
    }
    cout<<endl;
    // Contar los n�meros primos utilizando std::count_if y la funci�n lambda
    int primosMenoresDe1000 = count_if(numeros.begin(), numeros.end(), esPrimo);

    // Mostrar el resultado
    cout << "Numero de primos menores de 1000 en el vector: " << primosMenoresDe1000 <<endl;

    return 0;
}
