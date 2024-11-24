#ifndef COMENTARIOS_HPP
#define COMENTARIOS_HPP

/*****
* void menu
******
* La función menu es la principal, ya que es la que se encarga de leer el archivo y procesar
* la lectura para la utilización de las funciones del TDA.
******
* Input:  
*       No recibe inputs, solo abre el archivo y se ejecuta.
******
* Returns:
* void:   No retorna nada, ya que es una función tipo void.
*****/

/*****
* int hash
******
* La función busca obtener un número de hashing respecto a distintas operaciones y asi
* obtener un valor aleatorizado para ser mas eficiente. las operaciones realizadas son
* Obtener el número ASCII del primer numero del rol, multiplicarlo por n! y luego sumarlo
* a un total, este proceso se repetirá para todo el rol, es decir, para el numero en posicion
* 1, tomara el valor ASCII del número en posición 1 y lo multiplicará por (n-1)!
******
* Input:
* string rol: La función recibe como parámetro el rol para poder recorrerlo.
******
* Returns:
* total: La función retornará el número de hash obtenido.
*****/

/*****
* int factorial
******
* La función factorial nos sirve como una función auxiliar al momento de calcular el hashing.
* Esta función, como su nombre lo dice, calcula el factorial de un número n.
******
* Input:
* int n : Es el número al cual se le desea calcular el factorial.
******
* Returns:
* resultado: La función retornará el resultado total del factorial.
*****/

/*****
* int p
******
* La función p busca una segunda opcion en caso de colisiones. Esta funciona de forma cuadratica
* y se mantiene firme a través de números primos que (Idealmente) no dividen a las ranuras.
******
* Input:
* string rol: Recibe el rol para poder obtener el hash del rol
* int i: Recibe un parámetro i para obtener la ranura a revisar.
******
* Returns:
* return p_final: Es el resultado de la ejecución de P
*****/

/*****
* cuenta obtener
******
* La función obtiene la cuenta del rol buscado
******
* Input:
* string rol: Se ingresa el rol a buscar.
******
* Returns:
* tabla[pos]: La función retornará la poscicion del rol buscado en la tabla
* cuenta(): La función no retornará nada si no encuentra el rol buscado.
*****/

/*****
* void agregar
******
* La función agregar busca si la poscicion de la tabla está ocupadam si está ocupada, entregará
* rol ya existente, sino, la agregará. Si la cantidad de ranuras ocupadas es demasiada, llamará
* a la función auxiliar redimensionar y esta creará nuevas ranuras.
******
* Input:
* cuenta c: La función recibe como parámetro C de tipo cuenta para poder operar sobre
*           la poscicion de la tabla en la tabla y con el rol.
******
* Returns:
* void: No retorna nada, ya que es una función tipo Void.
*****/

/*****
* void eliminar
******
* La función eliminar busca eliminar el rol, busca su posición y la devuelve como vacia.
******
* Input:
* string rol: La función recibe como parametro el rol de interés a eliminar.
******
* Returns:
* void: No retornará nada, pues es una función tipo void.
*****/

/*****
* void modificar
******
* La función busca modificar la descripción del rol de interés.
******
* Input:
* string rol: Recibe el rol de interés a modificar.
* string descripción: Recibé la nueva descripción para el rol.
******
* Returns:
* void: No retornará nada, pues es una función tipo void.
*****/

/*****
* void redimensionar
******
* La función redimensionar crea una nueva tabla con la nueva cantidad de ranuras, guarda la 
* antigua tabla en otra variable, para luego asi, ir recorriendola e ir agregandola a la nueva
* tabla, manteniendo los roles en sus ranuras originales y aumentando la cantidad de ranuras
* por n veces.
******
* Input:
* int n: Será el número de interes por el cual queremos amplificar nuestras ranuras.
******
* Returns:
* void: No retornará nada, pues es una función tipo void.
*****/

/*****
* void estadisticas
******
* La función imprimirá la cantidad de ranuras ocupadas, ranuras totales y el factor de carga
* que calcula las ranuras ocupadas partido en la cantidad de ranuras totales.
******
* Input:
*      : No recibe ningun input, solo imprime.
******
* Returns:
* void: No retornará nada, pues es una función tipo void.
*****/
#endif
