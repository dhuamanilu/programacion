#include <bits/stdc++.h>
//Usar linux
#include <pthread.h>
using namespace std;
int n;
int max_threads;
const int MX=100000;
int a[MX];
int tmp;
void* compare(void* arg){
    int index = tmp;
    tmp = tmp + 2;
    if ((index + 1 < n) && (a[index] > a[index + 1])) {
        swap(a[index], a[index + 1]);
    }
}


void oddEven(pthread_t threads[])
{
    int i, j;
    for (i = 1; i <= n; i++) {
        if (i % 2 == 1) {
            tmp = 0;
            for (j = 0; j < max_threads; j++)
                pthread_create(&threads[j], NULL, compare, NULL);

            for (j = 0; j < max_threads; j++)
                pthread_join(threads[j], NULL);
        }

        else {
            tmp = 1;

            for (j = 0; j < max_threads - 1; j++)
                pthread_create(&threads[j], NULL, compare, NULL);

            for (j = 0; j < max_threads - 1; j++)
                pthread_join(threads[j], NULL);
        }
    }
}

void printArray(){
    int i;
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main()
{
    cout<<"Ingrese n :";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Ingrese numero:";
        cin>>a[i];
        cout<<endl;
    }
    max_threads=(n+1)/2;
    pthread_t threads[max_threads];

    cout << "El arreglo es: ";
    printArray();

    oddEven(threads);

    cout << "\nArreglo ordenado es es: ";
    printArray();

    return 0;
}
