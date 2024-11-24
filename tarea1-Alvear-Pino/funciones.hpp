#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP
#include "structs.hpp"

using namespace std;
bool casillas_amenazadas[65];
bool *puntero_casillas_amenazadas = casillas_amenazadas;
bool posiciones_amenazadas_rey[65];
bool *puntero_posiciones = posiciones_amenazadas_rey;

/*****
* bool Limites
******
* La funcion bool Limites revisa que la posicion en la que va a atacar cada pieza exista dentro de los parametros del tablero. 
******
* Input:
* int x : El X representa el movimiento de la pieza respecto a las filas.
* int y : El Y representa el movimiento de la pieza respecto a las columnas.
******
* Returns:
* bool: Nos retornará verdadero o falso dependiendo si se encuentra dentro o fuera de los limites.
******
*****/
bool Limites(int x, int y){
    return (x>=0 && x<=7 && y>=0 && y<=7);
};

/*****
* void Torre
******
* La funcion Torre buscará todas las casillas amenazadas por la pieza torre, teniendo en cuenta de que se puede encontrar con otras piezas.
* Si es que encuntra una pieza, guardará hasta esa posicion en el arreglo bool casillas amenazadas. Utilizamos un ciclo while porque la accion se
* tiene que repetir hasta que encuentre una posicion fuera del limite o si se topa con una pieza.
******
* Input:
* int n : El n es el parametro con el cual entra, sabiendo en que casilla está cierta pieza, para poder acceder a su cordenada x e y.
* struct tablero : El tablero ingresa para poder ver la posicion de la pieza dentro del tablero.
******
* Returns:
* void : Tecnicamente no retorna nada, ya que el fin de esta funcion es añadir a un array todas las posciciones que amenaza la torre y guardarlas a 
*        travéz de un puntero.  
*****/
void Torre(Tablero tablero, int n){
    int x = tablero.piezas_tablero[n].x;
    int y = tablero.piezas_tablero[n].y;    
    bool r=true;
    int aux = 0;
    while (r){
        aux--;
        if (Limites(x+aux,y)){
            puntero_casillas_amenazadas[(x+aux)*8+y] = 1;
            if (tablero.piezas_tablero[(x+aux)*8+y].simbolo != '.'){
                if (tablero.piezas_tablero[(x+aux)*8+y].simbolo != 'X'){                   
                    r = false; 
                }
            }    
        }
        else{
            r=false;
        }    
    }  
    aux = 0; 
    r=true;
    while (r){
        aux += 1;
        if (Limites(x+aux,y)){
            puntero_casillas_amenazadas[(x+aux)*8+y] = 1;
            if (tablero.piezas_tablero[(x+aux)*8+y].simbolo != '.'){
                if (tablero.piezas_tablero[(x+aux)*8+y].simbolo != 'X'){
                    r = false;    
                }
            }    
        }
        else{
            r = false;
        }    
    } 
    aux = 0;  
    r=true;
    while (r){
        aux -= 1;
        if (Limites(x,y+aux)){
            puntero_casillas_amenazadas[x*8+(y+aux)] = 1;
            if (tablero.piezas_tablero[x*8+(y+aux)].simbolo != '.'){
                if (tablero.piezas_tablero[x*8+(y+aux)].simbolo != 'X'){
                    r = false;
                }
            }    
        }
        else{
            r = false;
        }    
    } 
    aux = 0;  
    r=true;
    while (r){
        aux += 1;
        if (Limites(x,y+aux)){
            puntero_casillas_amenazadas[x*8+(y+aux)] = 1;
            if (tablero.piezas_tablero[x*8+(y+aux)].simbolo != '.'){
                if (tablero.piezas_tablero[x*8+(y+aux)].simbolo != 'X'){
                    r = false;
                }
            }    
        }
        else{
            r = false;
        }    
    }    
}

/*****
* void Alfil
******
* La funcion Alfil buscará todas las casillas amenazadas por la pieza torre, teniendo en cuenta de que se puede encontrar con otras piezas.
* Si es que encuentra una pieza, guardará hasta esa posicion en el arreglo bool casillas amenazadas. Utilizamos un ciclo while porque la accion se
* tiene que repetir hasta que encuentre una posicion fuera del limite o si se topa con una pieza.
******
* Input:
* int n : El n es el parametro con el cual entra, sabiendo en que casilla está cierta pieza, para poder acceder a su cordenada x e y.
* struct tablero : El tablero ingresa para poder ver la posicion de la pieza dentro del tablero.
******
* Returns:
* void : Tecnicamente no retorna nada, ya que el fin de esta funcion es añadir a un array todas las posciciones que amenaza el alfil y guardarlas a 
*        travéz de un puntero.  
*****/
void Alfil(Tablero tablero, int n){
    int x = tablero.piezas_tablero[n].x;
    int y = tablero.piezas_tablero[n].y;    
    bool r=true;
    int aux = 0;
    int aux2 = 0;
    while (r){
        aux --;
        aux2 ++;
        if (Limites(x,y)){
            puntero_casillas_amenazadas[(x+aux)*8+(y+aux2)] = 1;
            if (tablero.piezas_tablero[(x+aux)*8+(y+aux2)].simbolo != '.'){
                r = false;
            }
        }
            else{
                r = false;
            }
    }    
    r=true;
    aux = 0;
    aux2 = 0;
    while (r){
        aux ++;
        if (Limites(x+aux,y+aux)){
            puntero_casillas_amenazadas[(x+aux)*8+(y+aux)] = 1;
            if (tablero.piezas_tablero[(x+aux)*8+(y+aux)].simbolo != '.'){
                r = false;                 
            }
        }
            else{
                r = false;
            }
    }   
    r=true;
    aux = 0;
    while (r){
        aux --;
        if (Limites(x+aux,y)){
            puntero_casillas_amenazadas[(x+aux)*8+(y+aux)] = 1;
            if (tablero.piezas_tablero[(x+aux)*8+(y+aux)].simbolo != '.'){
                r = false;
            }
        }
            else{
                r = false;
        }
    } 
    r=true;
    aux = 0;
    while (r){
        aux ++;
        aux2 --;
        if (Limites(x+aux,y+aux2)){
            puntero_casillas_amenazadas[(x+aux)*8+(y+aux2)] = 1;
            if (tablero.piezas_tablero[(x+aux)*8+(y+aux2)].simbolo != '.'){
                r = false;
            }
        }
            else{
                r = false;
        }
    }                  
}

/*****
* void Reina
******
* La funcion Reina buscará todas las casillas amenazadas por la pieza reina, teniendo en cuenta de que se puede encontrar con otras piezas.
* Si es que encuntra una pieza, guardará hasta esa posicion en el arreglo bool casillas amenazadas.Ya que la reina se mueve de la misma forma que el alfil 
* y la torre combinados, utilizamos las dos funciones posteriormente creadas.
******
* Input:
* int n : El n es el parametro con el cual entra, sabiendo en que casilla está cierta pieza, para poder acceder a su cordenada x e y.
* struct tablero : El tablero ingresa para poder ver la posicion de la pieza dentro del tablero.
******
* Returns:
* void : Tecnicamente no retorna nada, ya que el fin de esta funcion es añadir a un array todas las posciciones que amenaza la reina y guardarlas a 
*        travéz de un puntero. 
*****/
void Reina(Tablero tablero, int n){
    Alfil(tablero, n);
    Torre(tablero, n);
}
/*****
* void Peon
******
* La funcion Peon buscará todas las casillas amenazadas por la pieza peón, teniendo en cuenta de que se puede encontrar con otras piezas.
* Si es que encuntra una pieza, guardará hasta esa posicion en el arreglo bool casillas amenazadas. Como solo puede atacar dos lugares no utilizamos
* un ciclo while y calculamos las posiciones, si es que estan dentro del limite, directamente. 
******
* Input:
* int n : El n es el parametro con el cual entra, sabiendo en que casilla está cierta pieza, para poder acceder a su cordenada x e y.
* struct tablero : El tablero ingresa para poder ver la posicion de la pieza dentro del tablero.
******
* Returns:
* void : Tecnicamente no retorna nada, ya que el fin de esta funcion es añadir a un array todas las posciciones que amenaza el peon y guardarlas a 
*        travéz de un puntero.
*****/
void Peon(Tablero tablero, int n){
    int x = tablero.piezas_tablero[n].x;
    int y = tablero.piezas_tablero[n].y;
    int aux = 0;
    int aux2 = 0;
    aux = -1;
    aux2 = 1;
    if (Limites(x,y)){
        puntero_casillas_amenazadas[(x+aux)*8+(y+aux2)] = 1;
        if (tablero.piezas_tablero[(x+aux)*8+(y+aux2)].simbolo != '.'){
        }
    }
    aux = 1;
    if (Limites(x+aux,y+aux)){
        puntero_casillas_amenazadas[(x+aux)*8+(y+aux)] = 1;
        if (tablero.piezas_tablero[(x+aux)*8+(y+aux)].simbolo != '.'){                   
        }
    }
}

/*****
* void Caballo
******
* La funcion Caballo buscará todas las casillas amenazadas por la pieza caballo, teniendo en cuenta de que se puede encontrar con otras piezas.
* Si es que encuntra una pieza, guardará hasta esa posicion en el arreglo bool casillas amenazadas. 
******
* Input:
* int n : El n es el parametro con el cual entra, sabiendo en que casilla está cierta pieza, para poder acceder a su cordenada x e y.
* struct tablero : El tablero ingresa para poder ver la posicion de la pieza dentro del tablero.
******
* Returns:
* void : Tecnicamente no retorna nada, ya que el fin de esta funcion es añadir a un array todas las posciciones que amenaza el caballo y guardarlas a 
*        travéz de un puntero.
*****/
void Caballo(Tablero tablero, int n){
    int x = tablero.piezas_tablero[n].x;
    int y = tablero.piezas_tablero[n].y;  
    int aux = 0;
    int aux2 = 0; 
    aux = 2;
    aux2 = 1;
    if (Limites(x+aux,y+aux2)){
        puntero_casillas_amenazadas[(x+aux)*8+(y+aux2)] = 1;
        if (tablero.piezas_tablero[(x+aux)*8+(y+aux2)].simbolo != '.'){
        }
    }
    aux = 1;
    aux2 = 2;
    if (Limites(x+aux,y+aux2)){
        puntero_casillas_amenazadas[(x+aux)*8+(y+aux2)] = 1;
        if (tablero.piezas_tablero[(x+aux)*8+(y+aux2)].simbolo != '.'){
        }
    }
    aux = 2;
    aux2 = -1;
    if (Limites(x+aux,y+aux2)){
        puntero_casillas_amenazadas[(x+aux)*8+(y+aux2)] = 1;
        if (tablero.piezas_tablero[(x+aux)*8+(y+aux2)].simbolo != '.'){
        }
    }   
    aux = 1;
    aux2 = -2;
    if (Limites(x+aux,y+aux2)){
        puntero_casillas_amenazadas[(x+aux)*8+(y+aux2)] = 1;
        if (tablero.piezas_tablero[(x+aux)*8+(y+aux2)].simbolo != '.'){
        }
    }  
    aux = -2;
    aux2 = 1;
    if (Limites(x+aux,y+aux2)){
        puntero_casillas_amenazadas[(x+aux)*8+(y+aux2)] = 1;
        if (tablero.piezas_tablero[(x+aux)*8+(y+aux2)].simbolo != '.'){
        }
    }      
    aux = -1;
    aux2 = 2;
    if (Limites(x+aux,y+aux2)){
        puntero_casillas_amenazadas[(x+aux)*8+(y+aux2)] = 1;
        if (tablero.piezas_tablero[(x+aux)*8+(y+aux2)].simbolo != '.'){
        }
    }  
    aux = -2;
    aux2 = -1;
    if (Limites(x+aux,y+aux2)){
        puntero_casillas_amenazadas[(x+aux)*8+(y+aux2)] = 1;
        if (tablero.piezas_tablero[(x+aux)*8+(y+aux2)].simbolo != '.'){
        }
    }  
    aux = 1;
    aux = -2;
    if (Limites(x+aux,y+aux2)){
        puntero_casillas_amenazadas[(x+aux)*8+(y+aux2)] = 1;
        if (tablero.piezas_tablero[(x+aux)*8+(y+aux2)].simbolo != '.'){
        }
    }     
}

/*****
* int PosicionRey
******
* La funcion PosiciónRey tiene dos funciones. La primera es guardar las casillas que tienen que estar amenazadas para que 
* el rey este en jaquemate, estas posiciones las guardará en un arreglo bool de 65 llamado posiciones_amenazadas_rey. La segunda funcion es 
* que retorne un valor entero llamado contador, este va a ir aumentando de uno en uno cada vez que se guardue una nueva casilla al arreglo de 
* posiciones_amenazadas_rey. Con este contador sabemos cuantas casillas en total tienen que estar amenazadas para el jaque mate.
******
* Input:
* struct tablero : El tablero ingresa para poder recorrer el tablero.
******
* Returns:
* int : En este caso, distinto de los otros, nos retornará un contador, en el cual, sabremos cuantas de las posiciones del rey son las que están
*       disponibles para que el rey pueda moverse, considerando si está en los limites o no.  
*****/
int PosicionRey(Tablero tablero){
    int contador = 1;
    int aux = 0;
    int aux2 = 0;
    for (int n = 0; n < 65; n++){
        if (tablero.piezas_tablero[n].simbolo == 'X'){
            int x = tablero.piezas_tablero[n].x;
            int y = tablero.piezas_tablero[n].y;    
            puntero_posiciones[x*8+y]= 1;
            aux += 1;
            if (Limites(x+aux,y)){
                puntero_posiciones[(x+aux)*8+y] =1;
                contador++;
            }
            aux = 1;
            aux2 = 1;
            if (Limites(x+aux,y+aux2)){
                puntero_posiciones[(x+aux)*8+(y+aux2)] = 1; 
                contador++;
            }
            aux = 1;
            aux = -1;
            if (Limites(x+aux,y+aux2)){
                puntero_posiciones[(x+aux)*8+(y+aux2)] = 1; 
                contador++;                
            }
            aux2 = 1;
            if (Limites(x,y+aux2)){
                puntero_posiciones[x*8+(y+aux2)] =1;
                contador++;                
            }
            aux2 = -1;
            if (Limites(x,y+aux2)){
                puntero_posiciones[x*8+(y+aux2)] =1; 
                contador++;
            }
            aux = -1;
            if (Limites(x+aux,y)){
                puntero_posiciones[(x+aux)*8+y] =1;
                contador++;               
            }
            aux = -1;
            aux2 = 1;
            if (Limites(x+aux,y+aux2)){
                puntero_posiciones[(x+aux)*8+(y+aux2)] =1; 
                contador++;           
            }
            aux = -1;
            aux2 = -1;
            if (Limites(x+aux,y+aux2)){
                puntero_posiciones[(x+aux)*8+(y+aux2)] =1;
                contador++;               
            } 
        }

    }
    return contador;
    
}

/*****
* void CasillasAmenazadas
******
* La funcion CasillasAmenazadas va recorriendo todos los simbolos del tablero, si es que encuntra una pieza llamará a su respectiva función para
* guardar en el arreglo bool casillas_amenazadas de 65 todas las posiciones que estan siendo amenazadas. 
******
* Input:
* struct tablero : El tablero ingresa para poder recorrer el tablero.
******
* Returns:
* Void : Tecnicamente no retorna nada, ya que el fin de esta funcion es llamar a las piezas y añadir a un array todas las posiciones que amenazan 
         las piezas y guardarlas a travéz del llamado de la pieza.   
*****/
void CasillasAmenazadas(Tablero tablero) { 
    for (int n=0; n < 65;){         
        switch(tablero.piezas_tablero[n].simbolo){
            case 'T':
                Torre(tablero,n);
                n++;
                break;
            case 'R':
                Reina(tablero,n);
                n++;
                break;
            case 'K':
                n++;
                break;
            case 'A':
                Alfil(tablero,n);
                n++;
                break;
            case 'P':
                Peon(tablero,n);
                n++;
                break;
            case 'C':
                Caballo(tablero,n);
                n++;
                break;           
            default:
                n++;
        }
    }    
}

/*****
* bool tableroEnJaqueMate
******
* Utilizamos un ciclo for para que vaya 
* sumando n. Entrará en el primer if solo si esa posicion n en el arreglo posiciones_amenazadas_rey es true, luego si la misma posicion es true en el 
* arreglo casillas amenazadas, es decir la casilla que necesitamos que este amenazada para el jaquemate lo está, el contador final sumará 1.
******
* Input:
* struct tablero : El tablero ingresa para poder recorrer el tablero.
******
* Returns:
* bool : Retornará que el booleano es true siempre y cuando numero_casillas == contador_final, en otras palabras, retornará verdadero si encuentra que 
*        TODAS las  posiciones del rey en las que se puede mover el rey Y la posicion del rey estan siendo amenazadas, esto se traduce a que el rey
*        está en jaque mate.  
* bool : Retornará que el booleano es false si la condición de arriba no se cumple, o explicado en nuestras funciones, si encuentra que UNA casilla de 
*        todas las posiciones que se puede mover al rey no está en el array de casiilas amenazadas, esto se traduce a que el rey si
*        puede moverse para evitar el jaque mate y por lo tanto, no es considerado jaque mate el tablero.
*****/
bool tableroEnJaqueMate(Tablero &tablero){
    CasillasAmenazadas(tablero);
    int numero_casillas = PosicionRey(tablero);
    int contador_final = 0 ;
    for(int n=0; n<=65; n++){
        if(posiciones_amenazadas_rey[n]){
            if (casillas_amenazadas[n]){
                contador_final++;
            }
        }
    }
    if (numero_casillas == contador_final ){
        return true;
    }
    else{
        return false;
    }    
}
#endif