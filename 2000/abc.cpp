#include <iostream>
#include <vector>
#include <map>

using namespace std;

void incrementarCuadrados(vector<vector<int>>& matriz, int n, int m, int k) {
    for (int i = 0; i <= n - k; ++i) {
        for (int j = 0; j <= m - k; ++j) {
            // Incrementar todos los elementos dentro del cuadrado de longitud k
            for (int x = i; x < i + k; ++x) {
                for (int y = j; y < j + k; ++y) {
                    matriz[x][y]++;
                }
            }
        }
    }
}

int main() {
    int n, m, k;
    cout << "Ingrese los valores de n, m y k: ";
    cin >> n >> m >> k;

    // Inicializar la matriz de n x m con ceros
    vector<vector<int>> matriz(n, vector<int>(m, 0));

    // Incrementar los valores de la matriz según los cuadrados de longitud k
    incrementarCuadrados(matriz, n, m, k);

    // Contar las ocurrencias de cada número
    std::map<int, int> contador;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            contador[matriz[i][j]]++;
        }
    }

    // Mostrar el resultado
    cout << "Ocurrencias de cada número en la matriz:" << endl;
    for (const auto& par : contador) {
        cout << "Número " << par.first << ": " << par.second << " veces" << endl;
    }

    return 0;
}
