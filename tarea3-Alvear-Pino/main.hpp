#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "funciones.hpp"
using namespace std;

void menu() {
    registro_cuentas registro;
    ifstream archivo("pruebas.txt");
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo." << endl;
        return;
    }

    string linea;
    while (getline(archivo, linea)) {
        istringstream auxiliar(linea);
        string comando;
        auxiliar >> comando;

        if (comando == "AGREGAR") {
            cuenta c;
            auxiliar >> c.rol >> c.nombre;
            getline(auxiliar, c.descripcion);
            if (!c.descripcion.empty() && c.descripcion[0] == ' ') {
                c.descripcion = c.descripcion.substr(1);
            }
            registro.agregar(c);
        } else if (comando == "OBTENER") {
            string rol;
            auxiliar >> rol;
            cuenta c = registro.obtener(rol);
            if (!c.rol.empty()) {
                cout << c.nombre << " " << c.descripcion << endl;
            }
        } else if (comando == "QUITAR") {
            string rol;
            auxiliar >> rol;
            registro.eliminar(rol);
        } else if (comando == "ESTADISTICAS") {
            registro.estadisticas();
        }
    }

    archivo.close();
}

#endif
