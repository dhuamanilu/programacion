#include "StackComoListaEnlazada.h"
#include "ProcesadorOperacion.h"
#include "ExpresionTree.h"
#include <bits/stdc++.h>
using namespace std;

// Clase que evalua toda la expresion
class EvaluadorExpresion{
public:
    int evaluar(string tokens){
        int i;
        //Usamos el stack como lista enlazada que implementamos
        StackComoListaEnlazada<int> values;
        //Como lo hicimos generico podemos usarlo tambien para las operaciones
        StackComoListaEnlazada<char> ops;
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


int main() {
    EvaluadorExpresion calc;
    cout<<"Ingrese operacion matematica (por ejemplo : \"100 *(19+26-17/1)/14\"):\n";
    string expresion;
    getline(cin,expresion);
    cout<<"El resultado es :"<<calc.evaluar(expresion)<<endl;

    StackComoListaEnlazada<char> e;
    ExpresionTree<char> a;
    Node<char> *x, *y, *z;
    int l = expresion.length();
    for (int i = 0; i < l; i++) {
        if (expresion[i] == '+' || expresion[i] == '-' || expresion[i] == '*'
            || expresion[i] == '/' || expresion[i] == '^') {
            z = new Node<char>(expresion[i]);
            x = e.pop();
            y = e.pop();
            z->left = y;
            z->right = x;
            e.push(z);
        }
        else {
            z = new Node<char>(expresion[i]);
            e.push(z);
        }
    }
    cout << "El Binary Expresion Tree es :\n";
    a.imprimir(z);


    /*Ejemplos de evaluacion
    10+4* 5 - 2 +8/4*/
    return 0;
}




