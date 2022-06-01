#include <iostream>
#include <string>
#include <windows.h>
#include "Impresion.hpp"
#include "Jugador.hpp"
using namespace std;

#define DEFAULT_BUFLEN 512

Impresion *gImpresion = new Impresion();
Jugador *gJugador1 = new Jugador();
Jugador *gJugador2 = new Jugador();
//Variables globales para impresion
HANDLE gHOut=GetStdHandle(STD_OUTPUT_HANDLE);
COORD gSBSize=GetLargestConsoleWindowSize(gHOut);

void Inicio();
void Menu();

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
    gImpresion->ImpresionObtenerNombres();
    string nombre1;
    cin>>nombre1;
    gJugador1->SetNombre(nombre1);
    cout<<gJugador1->GetNombre();
    system("pause");
}