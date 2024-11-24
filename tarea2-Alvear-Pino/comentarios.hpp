#ifndef COMENTARIOS_HPP
#define COMENTARIOS_HPP

/*****
* void insertar
******
* La función insertar es una función recursiva, en la cual pregunta si la raíz es nula, si lo es, crea una raíz con el carácter
* de interés, y si no lo es, revisa el nodo derecho y repite los pasos.
******
* Input:
* nodo*& root: Accede a la raíz a través del parámetro del puntero tipo nodo.
* char c: Es el carácter de interés que buscamos insertar.
* int index: Es el número el cual acompañará a nuestro carácter de interés. 
******
* Returns:
* void: La función no retorna nada pues es recursiva.
*****/

/*****
* nodo* juntarStr
******
* La función juntarStr es una función recursiva, la cual junta 2 árboles, siempre siguiendo la regla de que el árbol b se inserta
* a la derecha total del a.
******
* Input:
* nodo* a: Es el árbol al cual buscamos hacerle la inserción.
* nodo* b: Es el árbol el cual vamos a insertar al árbol a.
******
* Returns:
* a: La función retornará el árbol a con el árbol b ya insertado al extremo derecho.
*****/

/*****
* nodo* SacarInfoRt
******
* La función busca sacar la información desde la raíz a todo el árbol analizado.
******
* Input:
* nodo* root: Ingresa un puntero tipo nodo apuntando a la raíz.
******
* Returns:
* nuevo: Este retornará el nuevo árbol el cual nos permitirá acceder a él de forma más fácil.
*****/

/*****
* int SacarAlturaDer
******
* La función busca sacar la altura del árbol derecho. Esta función es recursiva, pues busca hasta el último nodo derecho.
******
* Input:
* nodo* root: La función accede a la raíz a través de un puntero tipo nodo.
******
* Returns:
* return 1 + h: Nos entregará la altura de todo el árbol derecho contando la raíz.
*****/

/*****
* void limpiar_2
******
* La función es recursiva, limpiará el nodo derecho y el nodo izquierdo.
******
* Input:
* nodo* root: Este input accede a la raíz a través de un puntero tipo nodo.
******
* Returns:
* void: No retorna nada, ya que es una función tipo void.
*****/

/*****
* void stringizar_con_parametros
******
* La función recorre el árbol y guarda el carácter que la raíz está apuntando en un string. Esta función es recursiva.
******
* Input:
* nodo* root: Esta función accede a la raíz a través de un puntero tipo nodo.
* string &stringizado: Ingresa un parámetro por referencia en el cual guardaremos todos los caracteres del árbol.
* .......
******
* Returns:
* TipoRetorno, Descripción retorno
*****/

/*****
* void voltear
******
* La función voltear ingresará el árbol en una pila. Esta función es más que nada un auxiliar.
******
* Input:
* nodo* root: Esta función accede a la raíz a través de un puntero tipo nodo.
* tPila& pila: Accedemos a la pila a través de un parámetro por referencia.
******
* Returns:
* void: No retornará nada, pues es una función tipo void.
*****/

/*****
* void insertarEnOrden
******
* La función recibe un nodo, si no hay raíz, será la nueva raíz, y luego irá asignando el nodo dependiendo si es mayor o menor.
******
* Input:
* nodo*& root: Accede al árbol a través de un puntero tipo nodo que apunta a su dirección.
* int index: Es el número del nodo correspondiente.
* char c: Es el carácter del nodo correspondiente.
******
* Returns:
* void: No retornará nada, pues es una función tipo void.
*****/

/*****
* void construirArbolBalanceado
******
* La función recibe un nodo, si no hay raíz, será la nueva raíz, y luego irá asignando el nodo dependiendo si es mayor o menor.
******
* Input:
* nodo *&root: La función accede al árbol a través de un nodo tipo puntero apuntando a la dirección del árbol.
* const string &arbol_string: Mantiene el arbol_string como una constante.
* int inicio: Es el método para calcular las mitades.
* int fin: Es utilizado en el método para calcular las mitades de las mitades y así sucesivamente.
******
* Returns:
* void: No retornará nada, pues es una función tipo void.
*****/

/*****
* void juntar
******
* La función recibe por parámetros un árbol s al cual llama las 2 funciones auxiliares definidas y aumenta el largo y alto
* del árbol.
******
* Input:
* super_string &s: Recibe por parámetros el árbol S para poder juntarlo con otro árbol de interés.
******
* Returns:
* void: No retornará nada, pues es una función tipo void.
*****/

/*****
* int recortar
******
* La función recortar busca optimizar el árbol, haciendo su búsqueda logn(2).
******
* Input:
*      : No recibe inputs.
******
* Returns:
* height = Retorna la altura del árbol recortado.
*****/

/*****
* void agregar
******
* La función se apoya en una función auxiliar para realizar la inserción del carácter en el último nodo.
******
* Input:
* char c: Es el carácter el cual queremos ingresar.
******
* Returns:
* void: No retorna nada, pues es un void.
*****/

/*****
* void separar
******
* La función separar llama a stringizar para dejar el árbol como string, para luego recortar el substring desde 0 al número
* ingresado, y desde el número ingresado hasta el final, limpia ambos árboles y luego con la función agregar, inserta cada 
* carácter del string a ambos árboles de forma respectiva para que queden separados.
******
* Input:
* int i: El i ingresado corresponde a la posición en la cual queremos realizar la separación.
* super_string &a: Recibimos por parámetro el árbol que tenemos.
* super_string &b: Este es un árbol auxiliar que ocupamos para apoyarnos con la función separar.
******
* Returns:
* void: La función no retorna nada, pues es tipo void.
*****/

/*****
* void reverso
******
* La función reverso se apoya con una pila, 2 funciones auxiliares y una función ya existente para la inserción de caracteres, con
* estas 3 funciones, recreamos el árbol de forma inversa.
******
* Input:
*      : La función no recibe inputs, pues no se pueden modificar los inputs que reciben las funciones proporcionadas por
*        el struct de la guía, por lo cual nos ayudamos de las 3 funciones mencionadas anteriormente.
******
* Returns:
* void: La función no retorna nada, pues es tipo void.
*****/

/*****
* void limpiar
******
* La función llama a otra función auxiliar, y luego de su ejecución hace a la raíz, la altura y el largo 0.
******
* Input:
*      :La función no recibe inputs, pues no se puede modificar lo que se nos da el struct de la guía, por lo cual creamos
*       la función auxiliar.
******
* Returns:
* void: La función no retorna nada, pues es tipo void, y la función auxiliar que creamos se encarga del proceso.
*****/

/*****
* string stringizar
******
* La función define un string, llama a una función auxiliar llamada "stringizar_con_parametros" y retornará el árbol como string.
******
* Input:
*      : La función no recibe inputs, pues no se pueden modificar los inputs que reciben las funciones proporcionadas por
*        el struct de la guía, por lo cual creamos nuestra función auxiliar mencionada antes.
******
* Returns:
* Stringizado: El return Stringizado retornará el árbol como string.
*****/

/*****
* int alturaArbol
******
* La función recorre el árbol en in orden y luego preguntará entre la altura derecha e izquierda, quién es el mayor, el mayor será
* la altura máxima del árbol recortado.
******
* Input:
* nodo* root: La función recibe como input un puntero tipo nodo de la raíz o del árbol analizado.
******
* Returns:
* return 0: La función retornará 0 si el árbol está vacío.
* return max(alturaIzquierda, alturaDerecha) + 1: La función retornará el valor máximo entre la altura izquierda y derecha, luego
*                                                 le sumará el nodo raíz con un +1.
*****/

#endif
