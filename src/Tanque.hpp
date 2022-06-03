#ifndef TANQUE_HPP
#define TANQUE_HPP
#include <stdlib.h>
#include <string>
using namespace std;

class Tanque {
    private:
        string aNombre;
        int aVida;
        int aDaño;
        int aPosicion;
    public:
        Tanque (string nombre,int vida, int daño) {
            aNombre = nombre;
            aVida = vida;
            aDaño = daño;
        }

        void SetVida(int vida) {
            aVida = vida;
        }

        void SetDaño(int daño) {
            aDaño = daño;
        }

        void SetPosicion(int posicion) {
            aPosicion = posicion;
        }

        string GetNombre() {
            return aNombre;
        }

        int GetVida() {
            return aVida;
        }

        int GetDaño() {
            return aDaño;
        }

        int GetPosicion() {
            return aPosicion;
        }
    
};


#endif