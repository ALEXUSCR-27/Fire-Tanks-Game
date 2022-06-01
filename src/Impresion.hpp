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
        char MsgBienvenida[] = "[BIENVENIDOS A FIRE TANKS]";
        ImprimirCentral(MsgBienvenida);
        //ImprimirTanque();
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

    void ImprimirCentral(char *s) {
		system("cls");
		Sleep(10);
		for (int i=0;i<24;i++) cout<<"\n";
		int msg=strlen(s);
		int pos=(int)(((aSBSize.X)-msg)/2);
		for(int i=0;i<pos;i++) cout<<" ";
		SetConsoleTextAttribute(aHConsole,2);
		for (int i=0;i!=msg;i++) {
			cout<<s[i];
			Sleep(50);
		}
        cout<<endl;
	}

    void ImprimirTanque() {
        int x = 255;
        char parte1[] = "██████**********************";
        char parte2[] = "          ";
        char parte3[] = "  ■■ ■■■■■■■■ ■■■      ";
        char parte4[] = "              ";
        CentrarCursor(parte1);
        SetConsoleTextAttribute(aHConsole,240);
        cout<<parte1<<endl;
        SetConsoleTextAttribute(aHConsole,2);
        CentrarCursor(parte2);
        SetConsoleTextAttribute(aHConsole,240);
        cout<<parte2<<endl;
        SetConsoleTextAttribute(aHConsole,2);
        CentrarCursor(parte3);
        SetConsoleTextAttribute(aHConsole,240);
        cout<<parte3<<endl;
        SetConsoleTextAttribute(aHConsole,2);
        CentrarCursor(parte4);
        SetConsoleTextAttribute(aHConsole,240);
        cout<<parte4<<endl;
        SetConsoleTextAttribute(aHConsole,2);

    }

    void ImprimirContinuar() {
        for (int i=0;i<9;i++) cout<<"\n";
        int pos=(int)(((aSBSize.X)-37)/2);
		for(int i=0;i<pos;i++) cout<<" ";
        system("pause");
    }

    void ImpresionObtenerNombres() {
        for (int i=0;i<24;i++) cout<<"\n";
        char MsgTitulo1[] = "[INGRESE EL NOMBRE DE LOS JUGADORES]";
        CentrarCursor(MsgTitulo1);
        cout<<MsgTitulo1<<endl;
        for (int i=0;i<10;i++) cout<<"\n";
        char MsgJugador1[] = "[JUGADOR 1] = > ";
        CursorIzquierda(MsgJugador1);
        cout<<MsgJugador1;
    }

};

#endif
