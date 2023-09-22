#include <bits/stdc++.h>
using namespace std;
void oddEvenSort(vector<int> &arr){
    bool isSorted = false;
    int n=arr.size();
    while (!isSorted){
        isSorted = true;

        for (int i=1; i<=n-2; i+=2){
            if (arr[i] > arr[i+1]){
                swap(arr[i], arr[i+1]);
                isSorted = false;
              }
        }

        for (int i=0; i<=n-2; i+=2){
            if (arr[i] > arr[i+1]){
                swap(arr[i], arr[i+1]);
                isSorted = false;
            }
        }
    }
    return;
}
void imprimirArr(vector<int> &arr){
    for(auto & e : arr){
        cout<<e<<" ";
    }
    cout<<"\n";
}
int main(){
    int n;
    cout<<"Ingrese el numero de elementos del arreglo:";
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cout<<"Ingrese elemento:";
        cin>>a[i];
        cout<<"\n";
    }
    cout<<"Arreglo antes de ordenar:\n";
    imprimirArr(a);
    oddEvenSort(a);
    cout<<"Arreglo despues de ordenar:\n";
    imprimirArr(a);
    return 0;
}
