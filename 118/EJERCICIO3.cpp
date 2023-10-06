
#include <bits/stdc++.h>
#include "ExpresionTree.h"
#include "ListaEnlazada.h"
using namespace std;
// Clase que evalua toda la expresion
class EvaluadorExpresion{
public:
    int evaluar(string tokens){
        int i;
        //Usamos el stack como lista enlazada que implementamos
        ListaEnlazada<int> values;
        //Como lo hicimos generico podemos usarlo tambien para las operaciones
        ListaEnlazada<char> ops;
        for(i = 0; i < tokens.length(); i++){
            //Si es un espacio simplemente saltarlo
            if(tokens[i] == ' ')
                continue;

            //Hay un parentesis,la operacion inicia
            else if(tokens[i] == '('){
                ops.push(tokens[i]);
            }

            //Token actual es un numero ,ponerlo en el stack de numeros
            else if(isdigit(tokens[i])){
                int val = 0;

                //Puede haber mas de 1 digito en el numero
                while(i < tokens.length() &&
                            isdigit(tokens[i]))
                {
                    val = (val*10) + (tokens[i]-'0');
                    i++;
                }

                values.push(val);

                //el for se saltara el operador,tenemos que hacer i--
                  i--;
            }

            //Cierra parentesis,se tienen que hacer las operaciones de adentro
            else if(tokens[i] == ')'){
                while(!ops.empty() && ops.top() != '('){
                    int val2 = values.top();
                    values.pop();
                    int val1 = values.top();
                    values.pop();
                    char op = ops.top();
                    ops.pop();
                    //Usamos la clase que procesa en si la operacion
                    ProcesadorOperacion procesador;
                    values.push(procesador.aplicarOperacion(val1, val2, op));
                }
                // Borramos el parentesis del stack de operadores
                if(!ops.empty())
                   ops.pop();
            }

            // Token actual es un operador
            else{
                /* Mientras la precedencia del operador en el top
                sea mayor igual que la actual se debe de hacer la operacion*/
                ProcesadorOperacion procesador;
                while(!ops.empty() && procesador.precedencia(ops.top()) >=
                      procesador.precedencia(tokens[i])){
                    int val2 = values.top();
                    values.pop();
                    int val1 = values.top();
                    values.pop();
                    char op = ops.top();
                    ops.pop();
                    //Usamos la clase que procesa en si la operacion
                    values.push(procesador.aplicarOperacion(val1, val2, op));
                }

                /*Ponemos el token actual a las operaciones,este tiene mayor precedencia
                que el del top*/
                ops.push(tokens[i]);
            }
        }

        /* Toda la expresion fue analizada,todos los operadores y operandos que quedan se deben
        de procesar*/
        while(!ops.empty()){
            int val2 = values.top();
            values.pop();
            int val1 = values.top();
            values.pop();
            char op = ops.top();
            ops.pop();
            //Usamos la clase que procesa en si la operacion
            ProcesadorOperacion procesador;
            values.push(procesador.aplicarOperacion(val1, val2, op));
        }

        //El valor que este en el top del stack sera la respuesta
        return values.top();
    }
};
};
int main(){
    EvaluadorExpresion calc;
    cout<<"Ingrese operacion matematica (por ejemplo : \"100 *(19+26-17/1)/14\"):\n";
    string expresion;
    getline(cin,expresion);

    ListaEnlazada e;
    ExpresionTree a;
    Nodo *x, *y, *z;
    int l = s.length();
    for (int i = 0; i < l; i++) {
         si el carácter leído es el operador, entonces aparecerán dos
        otros elementos de la pila haciendo un árbol binario
        if (s[i] == '+' || s[i] == '-' || s[i] == '*'
            || s[i] == '/' || s[i] == '^') {
            z = new Nodo(s[i]);
            x = e.pop();
            y = e.pop();
            z->left = y;
            z->right = x;
            e.push(z);
        }
        else {
            z = new Nodo(s[i]);
            e.push(z);
        }
    }
    cout << "El Binary Expresion Tree es :\n";
    a.imprimir(z);
    int res=0;
    cout<<"El resultado es :"<<calc.evaluar(expresion)<<endl;
    return 0;
}
