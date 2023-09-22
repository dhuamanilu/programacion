#include <iostream>
#include <vector>
#include <algorithm>
#include <pthread.h>

using namespace std;

// Estructura para los argumentos de la función de comparación
struct CompareArgs
{
    vector<int> &a;
    int start;
    int step;
};

// Función para comparar y cambiar elementos consecutivos del vector
void *compare(void *arg)
{
    CompareArgs *args = (CompareArgs *)arg;
    vector<int> &a = args->a;
    int start = args->start;
    int step = args->step;

    for (int i = start; i < a.size() - 1; i += step)
    {
        if (a[i] > a[i + 1])
        {
            swap(a[i], a[i + 1]);
        }
    }

    return NULL;
}

void oddEvenSort(vector<int> &a)
{
    vector<pthread_t> threads(a.size());

    for (int i = 0; i < a.size() / 2; i++)
    {
        CompareArgs args = {a, i * 2, 2};
        pthread_create(&threads[i], NULL, compare, &args);
    }

    for (int i = 0; i < a.size() / 2; i++)
    {
        pthread_join(threads[i], NULL);
    }
}

// Función para imprimir el vector
void printVector(const vector<int> &a)
{
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Ingrese el tamaño del vector: ";
    cin >> n;

    vector<int> a(n);

    cout << "Ingrese los elementos del vector:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << "Vector original: ";
    printVector(a);

    oddEvenSort(a);

    cout << "Vector ordenado: ";
    printVector(a);

    return 0;
}



