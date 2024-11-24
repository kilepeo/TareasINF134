#ifndef STACK_HPP 
#define STACK_HPP
#include <limits>
#include <iostream>

#define INVALID_ELEMENT std::numeric_limits<int>::min()
#define MAXIMOSTACK 100

typedef int tElemPila;


class tPila {
    private:
        unsigned int maxSize; 
        unsigned int top; 
        tElemPila *stackArray; 

    public:
        /*****
        * Constructor tPila
        ******
        * Inicializa una pila vacía con un tamaño máximo predefinido.
        ******
        * Input:
        * Ninguno
        ******
        * Returns:
        * Ninguno
        *****/
        tPila (){
            maxSize = MAXIMOSTACK;
            top = 0;
            stackArray = new tElemPila[maxSize];
        }

        /*****
        * Destructor ~tPila
        ******
        * Libera la memoria asignada para el arreglo de la pila.
        ******
        * Input:
        * Ninguno
        ******
        * Returns:
        * Ninguno
        *****/
        ~tPila (){
            delete[] stackArray;
        }

        /*****
        * void clear
        ******
        * Vacía la pila, reiniciando el índice del elemento superior.
        ******
        * Input:
        * Ninguno
        ******
        * Returns:
        * Ninguno
        *****/
        void clear (){
            top = 0;
        }

        /*****
        * int push
        ******
        * Inserta un elemento en la parte superior de la pila.
        ******
        * Input:
        * tElemPila item : El elemento a insertar en la pila.
        ******
        * Returns:
        * int : 1 si la inserción es exitosa, 0 si la pila está llena.
        *****/
        int push (tElemPila item){
            if (top == maxSize) return 0;
            stackArray[top++] = item;
            return 1; // inserción exitosa
        }

        /*****
        * void pop
        ******
        * Elimina el elemento superior de la pila.
        ******
        * Input:
        * Ninguno
        ******
        * Returns:
        * Ninguno
        *****/
        void pop (){
            if( top > 0 ){
                top--;
            } 
        }

        /*****
        * tElemPila topValue
        ******
        * Devuelve el valor del elemento superior de la pila sin eliminarlo.
        ******
        * Input:
        * Ninguno
        ******
        * Returns:
        * tElemPila : El elemento superior de la pila. Si la pila está vacía, devuelve INVALID_ELEMENT.
        *****/
        tElemPila topValue (){
            if( top <= 0 ) return INVALID_ELEMENT;
            return stackArray[top-1];
        }

        /*****
        * int size
        ******
        * Devuelve el número de elementos en la pila.
        ******
        * Input:
        * Ninguno
        ******
        * Returns:
        * int : El número de elementos en la pila.
        *****/
        int size (){
            return top;
        }
};
#endif
