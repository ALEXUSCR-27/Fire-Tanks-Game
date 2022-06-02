#include <iostream>
#include <string>
#include <windows.h>
#include "Impresion.hpp"
#include "Jugador.hpp"
using namespace std;

#define DEFAULT_BUFLEN 512

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
    int TanqueJ1 = VerificarNumero();
    //Verificar
    gImpresion->ImpresionTanques02(gJugador2);
    int TanqueJ2 = VerificarNumero();
    system("pause");

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