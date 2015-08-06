#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "Blancas.h"
#include "Negras.h"
#include "Funciones.h"
#ifdef __linux__
#define LIMPIAR "clear"
#endif // __linux__
#ifdef __MINGW32__
#define LIMPIAR "cls"
#endif // __MINGW32__
#define T 10 //tamaño maximo del tablero
using namespace std;
int main(){
        crearlimite();//determina el limite del tablero
        llenar();//llena las fichas y cuadros de desplazamiento
        string op;
        int opcion;
        
        inicio();
        menu();
        cout<<"\nOPCION: ";
        cin>>op;
        do
        {
	    interruptor=true;
        if(validacion1(op))
    	opcion=atoi(op.c_str());
    	else opcion=0;
    	
    	if(opcion>4)opcion=0;
    	
        switch(opcion)
        {
            case 1:{
                system(LIMPIAR);
                inicio();
                imprimir();//imprime el tablero
                while(true){//ciclo infinito, falta darle condicion de termino
                  juegoBlanca();
                  if(interruptor)
                  juegoNegra();
                }
                break;
            }
            case 2:{
                system(LIMPIAR);
                inicio();
                imprimir();//imprime el tablero
                cout<<endl<<"Usted jugara con las fichas o piezas blancas (b) y la corona sera (B)" <<endl;
                cout<<"               ----------¡¡suerte!!----------"<<endl<<endl;
                while(interruptor){//ciclo infinito, falta darle condicion de termino
                  juegoBlanca();
                  if(interruptor)
                  juegoMaquina();
                }
                break;
            }
            case 3:
            {
                system(LIMPIAR);
                inicio();
                cout<<"\n";
                    cout<<"\t\t*INSTRUCCIONES DEL JUEGO*\n\n";
                    cout<<"* Instrucción 1: \nLas fichas avanzan en forma diagonal por el tablero sólo hacia adelante, \nno pueden capturar hacia atrás.\n\n";
                    cout<<"* Instrucción 2: \nSe corona cuando se llega a la linea final, en donde la dama tiene la \nparticularidad de moverse libremente sobre las diagonales de las casillas.\n\n";
                    cout<<"* Instrucción 3: \nSe coronará con letras mayusculas las piezas\n\n";
                    cout<<"* Instrucción 4: \nLas coordenadas verticales del tablero van desde las letras A-J.\n\n";
                    cout<<"* Instrucción 5: \nLas coordenadas horizontales del tablero van desde el numero 1-10.\n\n";
                    cout<<"* Instrucción 6: \nAl momento de mover una ficha se debe poner primero la coordenada vertical \nluego la horizontal.\n\n";
                    cout<<"* Instrucción 7: \nAl momento de seleccionar la ficha existen dos opciones:\n\n";
                    cout<<"\t 1)Mover Izquierda (i).\n\n";
                    cout<<"\t 2)Mover Derecha (d).\n\n";
                    cout<<"* Instrucción 8: \nSi una dama llega a ser coronada tendrá la opcion de moverse libremente hacia \ncualquier diagonal\n\n";
                    cout<<"* Instrucción 9: \nExiste la regla llamada “Sopladita” (obligación de captura), si no se cumple el \noponente tiene el derecho de pedir que se capture o se retire del juego la ficha \nque no se capturó anteriormete.\n\n";
                    getchar();
                    getchar();
                    break;
            }
            case 4:
            {
                system(LIMPIAR);
                inicio();
                cout<<"\n\n";
                    cout<<"Proyecto realizado por:\n";
                    cout<<"\t- Nelson Alegría Bello.\n";
                    cout<<"\t- David Olivero Medina.\n";
                    cout<<"\t- Nicolás Vera Palominos.\n";
                    cout<<"Estudiantes de Ingeniería en Informática, UTEM.\n\n\n";
                    getchar();
                    getchar();
                    
                    break;
            }
            case 5:
            {
                system(LIMPIAR);
                inicio();
                cout<<"\tGRACIAS POR PREFERIRNOS!!!";
                delay();
                exit(0);
                break;
            }

            default:
                system(LIMPIAR);
                inicio();
                menu();
                cout<<"\nOPCION "<<opcion<<" NO ES VALIDA EN EL MENU, INTENTE NUEVAMENTE"<<endl;
                delay();
                break;
        }
        system("/usr/bin/clear");
        inicio();
        menu();
        cout<<"\nOPCION: ";
        cin>>op;
        }while(opcion>=0);
        return 0;
}
