#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct cuenta {
    string rol, nombre, descripcion;
};
class registro_cuentas {
    private:
        float factor_de_carga = 0.0;
        cuenta *tabla; 
        int ranuras = 15; 
        int ranuras_ocupadas = 0;
        int hash(string rol){
            int total = 0;
            int n = 11;
            for (char c : rol) {
                int aux = static_cast<int>(c) * factorial(n);
                n--;
                total += aux;
            }
            total = total % ranuras;
            return total;
        }
        int factorial(int n){
            int resultado = 1;
            for (int i = 1; i<= n; i++){
                resultado *= i;
            }
            return resultado;
        }

        int p(string rol, int i){ 
            if (i == 0) return 0;
            int p_final = (hash(rol) + 29*i*i + 73*i + 97)%ranuras;
            return p_final;
        }            

    public:
        registro_cuentas() {
            tabla = new cuenta[ranuras];
        }

        ~registro_cuentas() {
            delete[] tabla;
        }

        cuenta obtener(string rol){
            for (int i = 0; i < ranuras; ++i){
                int pos = p(rol, i);
                if (tabla[pos].rol == rol) {
                    return tabla[pos];
                }
                if (tabla[pos].rol == "") {
                    break;
                }
            }
            cout << "Rol no existente" << endl;
            return cuenta();
        }

        void agregar(cuenta c) {
            for (int i = 0; i < ranuras; i++) {
                int pos = p(c.rol, i);
                if (tabla[pos].rol == "" || tabla[pos].rol == c.rol) {
                    if (tabla[pos].rol == c.rol) {
                        cout << "Rol ya existente" << endl;
                        return;
                    }
                    tabla[pos] = c;
                    ++ranuras_ocupadas;
                    factor_de_carga = static_cast<float>(ranuras_ocupadas) / ranuras;
                    if (factor_de_carga > 0.8) {
                        redimensionar(ranuras * 2);
                    }
                    return;
                }
            }
        }


        void eliminar(string rol){
            for (int i = 0; i < ranuras; i++){
                int pos = p(rol, i);
                if (tabla[pos].rol == rol){
                    tabla[pos].rol = "";
                    --ranuras_ocupadas;
                    return;
                }
                if (tabla[pos].rol == ""){
                    break;
                }
            }
            cout << "Rol no existente" << endl;
        }


        void modificar(string rol, string descripcion){
            for (int i = 0; i < ranuras; i++){
                int pos = p(rol, i);
                if (tabla[pos].rol == rol){
                    tabla[pos].descripcion = descripcion;
                    return;
                }
                if (tabla[pos].rol == ""){
                    break;
                }
            }
        }

        void redimensionar(int n) {
            cuenta *nueva_tabla = new cuenta[n];
            int antiguas_ranuras = ranuras;
            ranuras = n;
            ranuras_ocupadas = 0;
            factor_de_carga = 0.0;
            for (int i = 0; i < n; ++i) {
                nueva_tabla[i].rol = "";
            }

            for (int i = 0; i < antiguas_ranuras; ++i) {
                if (tabla[i].rol != "") {
                    for (int j = 0; j < ranuras; ++j) {
                        int pos = (hash(tabla[i].rol) + j) % ranuras;
                        if (nueva_tabla[pos].rol == "") {
                            nueva_tabla[pos] = tabla[i];
                            ++ranuras_ocupadas;
                            break;
                        }
                    }
                }
            }

            delete[] tabla;
            tabla = nueva_tabla;
        }
        void estadisticas() {
            cout << "RANURAS OCUPADAS: " << ranuras_ocupadas << endl;
            cout << "RANURAS TOTALES: " << ranuras << endl;
            factor_de_carga = static_cast<float>(ranuras_ocupadas) / ranuras;
            cout << "FACTOR DE CARGA: " << float(factor_de_carga) << endl;
        }
};

#endif