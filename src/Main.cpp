#include <iostream>
#include <string>
#include <windows.h>
#include "Impresion.hpp"
#include "Jugador.hpp"
using namespace std;


Impresion *gImpresion = new Impresion();
Jugador *gJugador1 = nullptr;
Jugador *gJugador2 = nullptr;
int gDificultad = 0;
//Variables globales para impresion
HANDLE gHOut=GetStdHandle(STD_OUTPUT_HANDLE);
COORD gSBSize=GetLargestConsoleWindowSize(gHOut);

void Inicio();
void Menu();
void Menu02();
void Menu03();
void Menu03_2();
void Menu03_3();
int VerificarNumero();


int main() {
    system("cls");
    SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE),CONSOLE_FULLSCREEN_MODE,0);
    Inicio();
    return 0;
}

void Inicio() {
    gImpresion->ImpresionPantalla1();
    system("cls");
    Menu();
}

void Menu() {
    gJugador1 = new Jugador();
    gJugador2 = new Jugador();
    gImpresion->ImpresionObtenerNombres();
    string nombre1;
    cin>>nombre1;
    gJugador1->SetNombre(nombre1);
    gImpresion->ImpresionObtenerNombres2();
    string nombre2;
    cin>>nombre2;
    gJugador2->SetNombre(nombre2);
    gImpresion->ImpresionDificultad();
    Menu02();
    
}

void Menu02() {
    gDificultad = VerificarNumero();
    switch(gDificultad) {
        case 1:
            gDificultad = 1;
            break;
        case 2:
            gDificultad = 2;
            break;
        default:
            gImpresion->ImpresionError01();
            Menu02();
    }
    Menu03();
}

void Menu03() {
    system("cls");
    gImpresion->ImpresionTanques(gJugador1);
    Menu03_2();
    int TanqueJ1 = VerificarNumero();
}

void Menu03_2() {
    int TJ1 = VerificarNumero();
    Tanque *TanqueJ1 = nullptr;
    switch (TJ1) {
        case 1:
            TanqueJ1 = new Tanque("T-28 Super Tank",100,30);
            gJugador1->SetTanque(TanqueJ1);
            break;
        case 2:
            TanqueJ1 = new Tanque("T-14 Armata",100,60);
            gJugador1->SetTanque(TanqueJ1);
            break;
        case 3:
            TanqueJ1 = new Tanque("Leopardo II",150,15);
            gJugador1->SetTanque(TanqueJ1);
            break;
        case 4:
            TanqueJ1 = new Tanque("Black Night",100,25);
            gJugador1->SetTanque(TanqueJ1);
            break;
        default:
            gImpresion->ImpresionError01();
            Menu03_2();
    }

    gImpresion->ImpresionTanques02(gJugador2);
    Menu03_3();

}

void Menu03_3() {
    int TJ2 = VerificarNumero();
    Tanque *TanqueJ2 = nullptr;
    switch (TJ2) {
        case 1:
            TanqueJ2 = new Tanque("T-28 Super Tank",100,30);
            gJugador2->SetTanque(TanqueJ2);
            break;
        case 2:
            TanqueJ2 = new Tanque("T-14 Armata",100,60);
            gJugador2->SetTanque(TanqueJ2);
            break;
        case 3:
            TanqueJ2 = new Tanque("Leopardo II",150,15);
            gJugador2->SetTanque(TanqueJ2);
            break;
        case 4:
            TanqueJ2 = new Tanque("Black Night",100,25);
            gJugador2->SetTanque(TanqueJ2);
            break;
        default:
            gImpresion->ImpresionError01();
            Menu03_3();
    }
    system("pause");
    //saltar al siguiente metodo de inicio de partida
    //gJugador1 variable del j1
    //gJugador2 variable del j2
}



/*****Nombre***************************************
* VerificarNumero
*****Descripción**********************************
* Metodo para verificar si el usuario ingresa un numero
*****Retorno**************************************
* Un numero entero
*****Entradas*************************************
* Sin entradas
**************************************************/
int VerificarNumero() {
	int numero;
	while (!(cin>>numero)) {
		cin.clear();
		cin.ignore(10000,'\n');
        gImpresion->ImpresionError01();
	}
	return numero;
}