#include "StackComoListaEnlazada.h"

#include <bits/stdc++.h>

using namespace std;

// Encontrar la precedencia de los operadores
int precedence(char op){
    if(op=='+'||op=='-')
        return 1;
    if(op=='*'||op=='/')
        return 2;
    return 0;
}

// Clase que es el "core",la que hace las operaciones en si
class ProcesadorOperacion {
    public:
        int applyOp(int a, int b, char op){
            switch(op){
                case '+': return a + b;
                case '-': return a - b;
                case '*': return a * b;
                case '/': return a / b;
            }
        }
};


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
                    values.push(procesador.applyOp(val1, val2, op));
                }
                // Borramos el parentesis del stack de operadores
                if(!ops.empty())
                   ops.pop();
            }

            // Token actual es un operador
            else{
                /* Mientras la precedencia del operador en el top
                sea mayor igual que la actual se debe de hacer la operacion*/
                while(!ops.empty() && precedence(ops.top()) >= precedence(tokens[i])){
                    int val2 = values.top();
                    values.pop();
                    int val1 = values.top();
                    values.pop();
                    char op = ops.top();
                    ops.pop();
                    //Usamos la clase que procesa en si la operacion
                    ProcesadorOperacion procesador;
                    values.push(procesador.applyOp(val1, val2, op));
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
            values.push(procesador.applyOp(val1, val2, op));
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
    /*Ejemplos de evaluacion

    evaluar("10+4* 5 - 2 +8/4");
    evaluar("100 * ( 2 + 12 ) / 14");*/
    return 0;
}




