#ifndef STRUCTS_HPP
#define STRUCTS_HPP

struct Pieza {
    char simbolo; // Define qu� tipo de pieza es y su caracter
    int x, y;     // Su posici�n dentro del tablero [0, 7] x [0, 7]
};

struct Tablero {
    int cantidad_piezas; // Cantidad de piezas en el tablero
    Pieza* piezas_tablero; // Lista de piezas que tiene el tablero
};


#endif