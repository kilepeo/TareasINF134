#ifndef FUNCIONES2_HPP
#define FUNCIONES2_HPP

#include <iostream>
#include <fstream>
#include <string>
#include "stack.hpp"
#include "comentarios.hpp"

using namespace std;

class super_string {
private:
    struct nodo {
        nodo *left = nullptr, *right = nullptr;
        int index;
        char c;
        nodo(int index, char c) : index(index), c(c) {}
        nodo() : index(0), c('\0') {}
    };

    int height = 0;
    int length = 0; 
    nodo *root = nullptr; 
    nodo *root_aux = nullptr;

    void insertar(nodo *&root, char c, int index) {
        if (root == nullptr) {
            root = new nodo(index, c);
            return;
        }
        if (index > root->index){
            insertar(root->right, c, index);
        }
        else{
            insertar(root->left, c, index);
        }
    }

    nodo *juntarStr(nodo *a, nodo *b) {
        if (a == nullptr) return b;
        if (b == nullptr) return a;
        a->right = juntarStr(a->right, b);
        return a;
    }

    nodo *SacarInfoRt(nodo *root) {
        if (root == nullptr) return nullptr;
        nodo *nuevo = new nodo(root->index, root->c);
        nuevo->right = SacarInfoRt(root->right);
        nuevo->left = SacarInfoRt(root->left);
        return nuevo;
    }

    int SacarAlturaDer(nodo *root) {
        if (root == nullptr) return 0;
        int h = SacarAlturaDer(root->right);
        return 1 + h;
    }

    void limpiar_2(nodo *root) {
        if (!root) return;
        limpiar_2(root->left);
        limpiar_2(root->right);
        delete root;
    }

    int alturaArbol(nodo* root) {
    if (root == nullptr) {
        return 0;
    } 
    else {
        int alturaIzquierda = alturaArbol(root->left);
        int alturaDerecha = alturaArbol(root->right);
        return max(alturaIzquierda, alturaDerecha) + 1;
        }
    }

    void stringizar_con_parametros(nodo *root, string &stringizado) {
        if (!root) return;
        stringizar_con_parametros(root->left, stringizado);
        stringizado += root->c;
        stringizar_con_parametros(root->right, stringizado);
    }

    void voltear(nodo *root, tPila &pila) {
        if (!root) return;
        voltear(root->left, pila);
        pila.push(root->c);
        voltear(root->right, pila);
    }

    void insertarEnOrden(nodo *&root, int index, char c) {
        if (root == nullptr) {
            root = new nodo(index, c);
            return;
        }
        nodo *nuevaRaiz = root;
        while (true) {
            if (index < nuevaRaiz->index) {
                if (nuevaRaiz->left == nullptr) {
                    nuevaRaiz->left = new nodo(index, c);
                    break;
                }
                nuevaRaiz = nuevaRaiz->left;
            } else {
                if (nuevaRaiz->right == nullptr) {
                    nuevaRaiz->right = new nodo(index, c);
                    break;
                }
                nuevaRaiz = nuevaRaiz->right;
            }
        }
    }

    void construirArbolBalanceado(nodo *&root, const string &arbol_string, int inicio, int fin) {
        if (inicio > fin) return;
        int mid = (inicio + fin) / 2;
        insertarEnOrden(root, mid, arbol_string[mid]);
        construirArbolBalanceado(root, arbol_string, inicio, mid - 1);
        construirArbolBalanceado(root, arbol_string, mid + 1, fin);
    }

public:
    super_string() {}

    ~super_string() { limpiar(); }

    void juntar(super_string &s) { 
        root = juntarStr(root, SacarInfoRt(s.root));
        length += s.length;
        height += SacarAlturaDer(s.root);
    }

    void agregar(char c) { 
        insertar(root, c, length++);
    }

    void separar(int i, super_string &a, super_string &b) {
        string arbol_string = stringizar();
        if (i < 0 || i > length) return;
        string a_string = arbol_string.substr(0, i);
        string b_string = arbol_string.substr(i+1);////
        a.limpiar();
        b.limpiar();

        for (char c : a_string) {
            a.agregar(c);
        }
        for (char c : b_string) {
            b.agregar(c);
        }
    }

    void reverso() {
        if (!root) return;
        tPila pila;
        voltear(root, pila);
        root = nullptr;
        while (pila.size() > 0) {
            char aux = pila.topValue();
            agregar(aux);
            pila.pop();
        }
    }

    int recortar() {
        string arbol_string = stringizar();
        limpiar_2(root);
        root_aux = nullptr;
        construirArbolBalanceado(root_aux, arbol_string, 0, arbol_string.length() - 1);
        height = alturaArbol(root_aux);
        return height;
    }

    void limpiar() {
        limpiar_2(root);
        root = nullptr;
        length = 0;
        height = 0;
    }

    string stringizar() {
        string stringizado;
        stringizar_con_parametros(root, stringizado);
        return stringizado;
    }
};

#endif
