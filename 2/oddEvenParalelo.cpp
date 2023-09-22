#include <iostream>
#include <vector>
#include <thread>
#include <algorithm>

using namespace std;

// Función para comparar y cambiar elementos consecutivos del vector
void compare(vector<int> &a, int start, int step)
{
    for (int i = start; i < a.size() - 1; i += step)
    {
        if (a[i] > a[i + 1])
        {
            swap(a[i], a[i + 1]);
        }
    }
}

void oddEvenSort(vector<int> &a)
{
    vector<thread> threads;
    threads.reserve(a.size());

    for (int i = 0; i < a.size() / 2; i++)
    {
        threads.emplace_back(compare, ref(a), i * 2, 2);
    }

    for (auto &thread : threads)
    {
        thread.join();
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
