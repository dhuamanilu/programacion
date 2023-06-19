#include "Persona.h"
#include <bits/stdc++.h>
using namespace std;
void modificarPersona(Persona& person){
    cout<<"Ingrese su nombre:";
    cin>>person.nombre;

    cout<<"Ingrese su apellido:";
    cin>>person.apellido;
    cout<<"Ingrese su edad:";
    cin>>person.edad;
}
void mostrarDatosPersona(Persona& person){
    cout<<"Tu nombre es : "<<person.nombre<<" "
    <<person.apellido<<", y tu edad es :"<<person.edad<<"\n";
}
