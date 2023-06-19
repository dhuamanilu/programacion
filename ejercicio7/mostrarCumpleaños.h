#include "Persona.h"
#include <bits/stdc++.h>
using namespace std;

void mostrarCumpleanieros(vector<Persona>& arr){
    do{
        int mes;
        cout<<"Ingrese numero de mes (0 para salir):";
        cin>>mes;
        if(mes==0) break;
        int cantidad=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i].mesNacimiento == mes){
                cantidad++;
                cout<<arr[i].nombre<<" cumple años en ese mes!\n";
            }
        }
        if(cantidad==0){
            cout<<"Nadie cumple años en ese mes!\n";
        }
    }while(true);
}
void ingresarPersonas(vector<Persona>& arr){
    for(int i=0;i<arr.size();i++){
        cout<<"Ingrese los datos de la persona " << i+1 << ":\n";
        cout<<"Nombre: ";
        cin>>arr[i].nombre;
        cout<<"Dia de nacimiento: ";
        cin>>arr[i].diaNacimiento;
        cout<<"Mes de nacimiento: ";
        cin>>arr[i].mesNacimiento;
        cout<<"Ano de nacimiento: ";
        cin>>arr[i].anioNacimiento;
    }
}
