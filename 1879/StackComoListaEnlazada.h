#ifndef LISTA_ENLAZADA_H
#define LISTA_ENLAZADA_H

template <typename T>
class Nodo{
public:
    //Representar el Expression Tree
    T valor;
    Nodo<T>* left;
    Nodo<T>* right;

    /*Simular una pila,pues el
    Expression Tree convierte una notacion */
    Nodo<T>* next=nullptr;

    Nodo<T>(T c){
        this->valor=c;
        left=nullptr;
        right=nullptr;
    }
    Nodo<T>(){
        left=nullptr;
        right=nullptr;
    }

};

template <typename T>
class ListaEnlazada {
    Nodo<T>* head =nullptr;
public:
    void push(Nodo<T>* x){
    if (head==nullptr) {
        head=x;
    }
    //Insertando nodos en el top de la lista enlazada (simulando un stack LIFO)
    else {
        x->next = head;
        head = x;
    }
}
Nodo<T>* pop(){
    //Sacar de la lista el elemento en el "top"
    Nodo<T>*p=head;
    head=head->next;
    return p;
}

};



#endif
