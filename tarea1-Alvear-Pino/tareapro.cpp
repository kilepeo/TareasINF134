#include <iostream>
#include <fstream>
#include <string>
#include "structs.hpp"
#include "funciones.hpp"
using namespace std;

int main() {
    ifstream archivo("tablero.txt");
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo." << endl;
        return 1;
    }
    Tablero tablero;
    archivo >> tablero.cantidad_piezas;
    tablero.piezas_tablero = new Pieza[64];
    string linea;
    int n = 0;
    for (int i = 0; i < 8; ++i) {
        archivo >> linea;
        for (int j = 0; j < 8; ++j) {
            char simbolo = linea[j];
            tablero.piezas_tablero[n].simbolo = simbolo;
            tablero.piezas_tablero[n].x = i;
            tablero.piezas_tablero[n].y = j;
            n++;
        }
    }
    if (tableroEnJaqueMate(tablero)){
        cout<<"Si\n";
    }
    else {
        cout<<"No\n";
    }
    archivo.close();
    delete[] tablero.piezas_tablero; 
    return 0;
}