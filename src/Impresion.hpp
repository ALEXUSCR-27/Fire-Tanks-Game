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
#ifndef IMPRESION_HPP
#define IMPRESION_HPP
#include <iostream>
#include <stdio.h>
#include <string>
#include "Jugador.hpp"
using namespace std;

/*****Nombre*************************************** 
 *  
 *****Descripción********************************** 
 *  
 *****Atributos************************************ 
 *  
 *****Métodos************************************** 
 *  
 **************************************************/ 
class Impresion {
    private:
        HANDLE aHConsole;
		COORD aSBSize;
    public:
        Impresion() {
            aHConsole=GetStdHandle(STD_OUTPUT_HANDLE);
			aSBSize=GetLargestConsoleWindowSize(aHConsole);
        }
    void ImpresionPantalla1() {
        system("cls");
        char MsgBienvenida[] = "[BIENVENIDOS A FIRE TANKS]";
		Sleep(10);
		for (int i=0;i<24;i++) cout<<"\n";
		int msg=strlen(MsgBienvenida);
		int pos=(int)(((aSBSize.X)-msg)/2);
		for(int i=0;i<pos;i++) cout<<" ";
		SetConsoleTextAttribute(aHConsole,2);
		for (int i=0;i!=msg;i++) {
			cout<<MsgBienvenida[i];
			Sleep(50);
		}
        cout<<endl<<endl<<endl;
        ImprimirTanque();
        cout<<endl;
        ImprimirContinuar();

    }

/*****Nombre***************************************
* CentrarCursor
*****Descripción**********************************
* Metodo para centrar el texto en la consola
*****Retorno**************************************
* Sin retorno
*****Entradas*************************************
* Un puntero al texto que se desea centrar
**************************************************/
	void CentrarCursor(char *a) {
		int msg=strlen(a);
		int pos=(int)(((aSBSize.X)-msg)/2);
		for(int i=0;i<pos;i++) cout<<" ";
	}

    void CursorIzquierda(char *a) {
		int msg=strlen(a);
		int pos=(int)(((aSBSize.X)-msg)/4);
		for(int i=0;i<pos;i++) cout<<" ";
	}


    void ImprimirTanque() {
        char parte1[] = "    ________       ";
        char parte2[] = "        __/        \\_____________";
        char parte3[] = "              |___         _____________|=====|>";
        char parte4[] = "______|       |_________";
        char parte5[] = "|________________________|";
        char parte6[] = "\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/";
        CentrarCursor(parte1);
        cout<<parte1<<endl;
        CentrarCursor(parte2);
        cout<<parte2<<endl;
        CentrarCursor(parte3);
        cout<<parte3<<endl;
        CentrarCursor(parte4);
        cout<<parte4<<endl;
        CentrarCursor(parte5);
        cout<<parte5<<endl;
        CentrarCursor(parte6);
        cout<<parte6<<endl;

    }

    void ImprimirContinuar() {
        for (int i=0;i<9;i++) cout<<"\n";
        int pos=(int)(((aSBSize.X)-37)/2);
		for(int i=0;i<pos;i++) cout<<" ";
        system("pause");
    }

    void ImpresionObtenerNombres() {
        for (int i=0;i<20;i++) cout<<"\n";
        char MsgTitulo1[] = "[INGRESE EL NOMBRE DE LOS JUGADORES]";
        CentrarCursor(MsgTitulo1);
        cout<<MsgTitulo1<<endl;
        cout<<"\n\n\n";
        char MsgJugador1[] = "[JUGADOR 1] = > ";
        CursorIzquierda(MsgJugador1);
        cout<<MsgJugador1;
    }
    void ImpresionObtenerNombres2() {
        cout<<"\n\n\n";
        char MsgJugador2[] = "[JUGADOR 2] = > ";
        CursorIzquierda(MsgJugador2);
        cout<<MsgJugador2;
    }
    void ImpresionDificultad() {
        cout<<endl;
        char MsgDificultad[] = "[MODO DE JUEGO]";
        CentrarCursor(MsgDificultad);
        cout<<MsgDificultad<<"\n\n";
        char MsgDificultad2[] ="[FACIL]==>1         [DIFICIL]==>2";
        CentrarCursor(MsgDificultad2);
        cout<<MsgDificultad2<<"\n\n";
        char MsgDificultad3[] = "[SELECCIONE EL MODO DE JUEGO]==>";
        CentrarCursor(MsgDificultad3);
        cout<<MsgDificultad3;
    }

    void ImpresionError01() {
        char MsgError01[] = "[POR FAVOR DIGITE CORRECTAMENTE UNO DE LOS MODOS DISPONIBLES]==>";
        CentrarCursor(MsgError01);
        cout<<MsgError01;
    }

    void ImpresionTanques(Jugador *J1) {
        char MsgTanques[] = "[SELECCIONE EL TANQUE QUE DESEA UTILIZAR]";
        for (int i=0;i<20;i++) cout<<"\n";
        CentrarCursor(MsgTanques);
        cout<<MsgTanques<<endl;
        char Tanque1[] = " [1].[T-28 SUPER TANK]===>[100 VIDA - 30 DAÑO]";
        char Tanque2[] = "[2].[T-14 ARMATA]===>[100 VIDA - 60 DAÑO]";
        char Tanque3[] = "[3].[LEOPARDO II]===>[150 VIDA - 15 DAÑO]";
        char Tanque4[] = "[4].[BLACK NIGHT]===>[100 VIDA - 25 DAÑO]";
        char InputTanque[] = "==>";
        string nombreJ1 = J1->GetNombre();
        cout<<"\n\n";
        CursorIzquierda(Tanque1);
        printf(" [1].[T-28 SUPER TANK]===>[100 VIDA - 30 DA%cO]\n",165);
        CursorIzquierda(Tanque2);
        printf("[2].[T-14 ARMATA]===>[100 VIDA - 60 DA%cO]\n",165);
        CursorIzquierda(Tanque3);
        printf("[3].[LEOPARDO II]===>[150 VIDA - 15 DA%cO]\n",165);
        CursorIzquierda(Tanque4);
        printf("[4].[BLACK NIGHT]===>[100 VIDA - 25 DA%cO]\n",165);
        CursorIzquierda(Tanque4);
        cout<<"["<<nombreJ1<<"] "<<InputTanque;
    }

    void ImpresionTanques02(Jugador *J2) {
        char Tanque4[] = "[4].[BLACK NIGHT]===>[100 VIDA - 25 DAÑO]";
        string nombreJ2 = J2->GetNombre();
        char InputTanque[] = "==>";
        CursorIzquierda(Tanque4);
        cout<<"["<<nombreJ2<<"] "<<InputTanque;
    }

};

#endif
