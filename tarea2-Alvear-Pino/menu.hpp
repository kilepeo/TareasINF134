#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <fstream>
#include <string>
#include "funciones2.hpp"


void menu() {
    ifstream archivo("prueba.txt");
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo." << endl;
        return;
    }
    
    string linea;
    super_string arbol;

    while (getline(archivo, linea)) {
        if (linea.find("REVERSO") != string::npos) {
            int pos1 = -1;
            int pos2 = -1;
            for (int n = 0; n < linea.length(); n++) {
                if (linea[n] == ' ') {
                    if (pos1 == -1) {
                        pos1 = n;
                    } 
                    else if (pos2 == -1) {
                        pos2 = n;
                        break; 
                    }
                }
            }
            int num1 = stoi(linea.substr(pos1 + 1 , pos2 - pos1 - 1));
            int num2 = stoi(linea.substr(pos2 + 1));
            super_string a,b,c;
            int n = 0;
            string stringArbol = arbol.stringizar();
            for (int i = 0; i < num1; i++){
                a.agregar(stringArbol[i]);
                n++;
            }
            int k = n;
            for (int i = n; i <= num2 ; i++){
                b.agregar(stringArbol[i]);
                k++;
            }
            for(int i = k; i <=stringArbol.size(); i++ ){
                c.agregar(stringArbol[i]);
            }
            string primer_str = a.stringizar();
            string segundo_str = b.stringizar();
            string tercer_str = c.stringizar();
            string final = primer_str + segundo_str + tercer_str;
            arbol.limpiar();
            for (char c : final){
                arbol.agregar(c);
            }
            arbol.reverso();
        }
        else if (linea.find("ELIMINAR") != string::npos) {
            int pos1 = -1;
            int pos2 = -1;
            for (int n = 0; n < linea.length(); n++) {
                if (linea[n] == ' ') {
                    if (pos1 == -1) {
                        pos1 = n;
                    } else if (pos2 == -1) {
                        pos2 = n;
                        break; 
                    }
                }
            }
            int num1 = stoi(linea.substr(pos1 + 1 , pos2 - pos1 -1));
            int num2 = stoi(linea.substr(pos2 + 1));
            super_string a,b,c;
            arbol.separar(num2, a, b);
            a.separar(num1, a, c);
            c.limpiar();
            a.juntar(b);
            arbol = a;
        }
        else if (linea.find("INSERTAR") != string::npos) {
            int pos1 = -1;
            int pos2 = -1;
            for (int n = 0; n < linea.length(); n++) {
                if (linea[n] == ' ') {
                    if (pos1 == -1) {
                        pos1 = n;
                    } else if (pos2 == -1) {
                        pos2 = n;
                        break; 
                    }
                }
            }
            int num1 = stoi(linea.substr(pos1 + 1 , pos2 - pos1 -1));
            string linea_nueva = linea.substr(pos2 + 1);
            for (char c : linea_nueva){
                arbol.agregar(c);
            }    
        }   
        else if (linea.find("RECORTAR") != string::npos) {
            int i = arbol.recortar();
            cout<<i<<endl;
        }
        else if (linea.find("MOSTRAR") != string::npos) {
            string string_arbol = arbol.stringizar();
            cout << string_arbol <<endl;       
        }
        else if (linea == "FIN"){
            arbol.limpiar();
            arbol.~super_string();
            break;
        }
    }

    archivo.close();
}

#endif
