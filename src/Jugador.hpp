#ifndef JUGADOR_HPP
#define JUGADOR_HPP
#include <stdlib.h>
#include <string>
#include "Tanque.hpp"
/*****Datos administrativos************************ 
 * Nombre del archivo:  
 * Tipo de archivo: 
 * Proyecto: 
 * Autor: 
 * Empresa: 
 *****Descripción********************************** 
 *  
 *  
 *****Versión************************************** 
 * ## | Fecha y hora | Autor 
 *  
 **************************************************/ 
using namespace std;
class Jugador {
    private:
    string aNombre;
    Tanque *aTanque;
    int aTurnos;
    public:
    Jugador() {
        aTurnos = 0;
    }

    void SetTanque(Tanque *tanque) {
        aTanque = tanque;
    }

    void SetTurnos(int turnos) {
        aTurnos = turnos;
    }
    void SetNombre(string nombre) {
        aNombre = nombre;
    }

    Tanque *GetTanque() {
        return aTanque;
    }
    int GetTurnos() {
        return aTurnos;
    }
    string GetNombre() {
        return aNombre;
    }

};
#endif