#ifndef PROCESADOR_OPERACION_H
#define PROCESADOR_OPERACION_H
// Clase que es el "core",la que hace las operaciones en si
class ProcesadorOperacion {
    public:
        int aplicarOperacion(int a, int b, char op){
            switch(op){
                case '+': return a + b;
                case '-': return a - b;
                case '*': return a * b;
                case '/': return a / b;
            }
        }
        // Encontrar la precedencia de los operadores
        int precedencia(char op){
            if(op=='+'||op=='-')
                return 1;
            if(op=='*'||op=='/')
                return 2;
            return 0;
        }
};
#endif
