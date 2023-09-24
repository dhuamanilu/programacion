#define NULL nullptr
#include <iostream>
using namespace std;
/*Creamos la clase nodo
que representa 1 dato,
se hizo generica porque necesitamos
representar los datos (int) y
tambien los operadores (char)*/
template <typename T>
class Node {
public:
    T data;
    Node<T>* link;
    // Constructor
    Node(T n){
        this->data = n;
        this->link = NULL;
    }
};
template <typename T>
class StackComoListaEnlazada {
    Node<T>* pico;

public:
    //Constructor por defecto
    StackComoListaEnlazada() {
        pico=NULL;
    }
    //Funcion para poner un nuevo dato
    void push(T data){
        //Creamos un nuevo nodo temporal en el heap
        Node <T> * temp = new Node<T>(data);

        // Inicializamos el dato
        temp->data = data;

        // Ponemos la referencia de su padre a temp
        temp->link =pico;

        // Hacemos que el top ahora sea temp
        pico= temp;
    }

    //Verificar si el stack esta vacio
    bool empty(){
        return pico==NULL;
    }

    //Obtener el "pico" del stack
    T top(){
        //Si la pila no está vacía, devuelve el elemento en el "top"
        if (!empty())
            return pico->data;
    }

    //Funcion para remover el elemtno
    void pop(){
        Node<T>* temp;

        //Si no hay elementos entonces no se puede hacer pop
        if (pico==NULL) {
            std::cout << "\nNo hay elementos en el stack" << std::endl;
        }
        else {
            // Guardamos la referencia de top para luego borrarla
            temp = pico;
            /*Hacemos que top ahora sea el hijo de top,es decir
            el ultimo elemento ya no esta apuntado por nadie*/
            pico=pico->link;

            /*Liberamos la memoria de la referencia del antiguo
            top que guardamos en temp*/
            free(temp);
        }
    }

    //Mostrar los elementos del stack
    void display()
    {
        Node<T>* temp;

        // Si no hay elementos
        if (pico== NULL) {
            cout << "\nNo hay elementos en el stack";
        }
        else {
            temp = pico;
            while (temp != NULL) {
                //Imprimir el dato
                cout << temp->data;
                //Recursivamente ir al sgte elemento
                temp = temp->link;
                if (temp != NULL)
                    cout << " -> ";
            }
        }
    }
};
