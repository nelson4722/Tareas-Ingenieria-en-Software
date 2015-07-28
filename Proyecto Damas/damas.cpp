#include <cstdlib>
#include <sstream>
#include <ostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "Blancas.h"
#include "Negras.h"
#define T 10 //tamaño maximo del tablero
using namespace std;
int N=0;// cantidad de piezas a mover la coronada
FILE * fp;//puntero del archivo de texto del historial

void inicio()// encabezado visual del programa
{
    cout<<"\t================\n";
    cout<<"\tTABLERO DE DAMAS\n";
    cout<<"\t================\n";
    cout<<endl;
}

void crearlimite()//comprueba que no salga del tablero establecido
{
    for(int i=0;i<T;i++){
        for(int j=0;j<T;j++){
            tab[i][j]=true;}}
}
bool direc(char d)//determina la dirección de movimiento de ficha
{
  if(d=='i')return true;
  else if(d=='d')return false;
}
bool diaux(char d)//determina la dirección de movimiento de ficha
{
  if(d=='b')return true;
  else if(d=='a')return false;
}

char cambioN (int i)//cambia el numero de la posición por una letra
{//ubicacion grafica del tablero
    char letras[] = {'A','B','C','D','E','F','G','H','I','J'};
    return letras[i-1];
}
int cambioL (char j)//cambia letra de posición por un numero
{//utilización de letras para trabajar
    int numeros[] = {1,2,3,4,5,6,7,8,9,10};
    char letras[] = {'A','B','C','D','E','F','G','H','I','J'};
    for(int i=0;i<10;i++)
    {
        if(j==letras[i])
            return numeros[i];
    }
}

void llenar(){//Crear el tablero de Damas
    for(int i = 0; i < T; i++)
            for(int j = 0; j < T; j++)
            {
                if (i < 3 && ((i + j) % 2 == 0))
                        tablero[i][j] = 'n';
                else
                if((i==3||i==4||i==5||i==6) && ((i + j) % 2 == 0))
                   tablero[i][j] = '+';
                else
                if ((i > 6) && ((i + j) % 2 == 0))
                        tablero[i][j] = 'b';
                else
                        tablero[i][j] = '-' ;
            }
}


void imprimir(){//Muestra el pantalla el Tablero de Damas
    //system("clear");
    fp = fopen ("historial.txt", "a");
    inicio();
    for(int i = 0; i < T; i++)
    {
        if (i == 0)
        {
            fprintf(fp,"  ");
            cout<<"  ";
                for (int k = 0; k < T; k++)
                {
                fprintf(fp," %c ",cambioN(k+1));
                cout<<" "<<cambioN(k+1)<<"  ";
                }
                fprintf(fp,"\n");
                fprintf(fp,"\n");
                cout<<endl;
                cout<<endl;
        }
        fprintf(fp," %d ",i+1);
        cout<<i+1;
        for(int j = 0; j < T; j++)
        {
                fprintf(fp," %c ",tablero[i][j]);
                cout<<"  "<<tablero[i][j]<<" ";
        }
        fprintf(fp,"\n");
        fprintf(fp,"\n");
        cout<<endl;
        cout<<endl;
    }
    fprintf(fp,"\n");
    fprintf(fp,"\n");
    fclose(fp);
}

int main(){
        //int iaux; //direccion de filas por numeros
        char jota;//direccion de columnas por letras
        char direccion; //'i' o 'd'
        char diraux; //'a' o 'b'
        bool dir;//si 'i' retorna true y 'd' retorna false
        bool daux;//si 'a' retorna true y 'b' retorna false
        
        int i=0,j=0;
        crearlimite();//determina el limite del tablero
        llenar();//llena las fichas y cuadros de desplazamiento
    	imprimir();//imprime el tablero
        while(true){//ciclo infinito, falta darle condicion de termino
            B:
        cout<<"ingrese posicion que desea mover y direccion de Blancos"<<endl;
    	cin>>jota>>i>>direccion;
    	if(direccion!='i' && direccion!='d'){cout<<endl<<"--Direccion invalida, intente nuevamente"<<endl;
			goto B;
		}
        //i=iaux;
        j=cambioL(jota);
    	dir=direc(direccion);//determina direccion con booleano
    	
        if(esCoronaB(i-1,j-1)==true)
        {
			C:
            cout<<"ingrese direccion y cantidad de posiciones a mover"<<endl;
            cin>>diraux>>N;
            if(diraux!='a'&& diraux!='b'){
				cout<<endl<<"Direccion invalida, intente nuevamente"<<endl;
				goto C;
		}
            daux=diaux(diraux);
        }else N=1;
       
                if(siComeB(i-1,j-1,dir,N,esCoronaB(i-1,j-1),daux)==1)//comprobar si puede capturar por izquierda
                {
                   siSopladitaB(i-1,j-1,N);
                   imprimir();
                }
                else if(siComeB(i-1,j-1,dir,N,esCoronaB(i-1,j-1),daux)==2)//determina captura por derecha
                {
                    if(siMueveB(i-1,j-1,dir,N,esCoronaB(i-1,j-1),daux)!=7)//comprobar si puede mover por izquierda
                    {
						i=i-1;
                        j=j-1;
                        if(puedeComerB(i,j,N,esCoronaB(i,j))!=0)tablero[i][j]='+';
						else{
                            moverBlanca(siMueveB(i,j,dir,N,esCoronaB(i,j),daux),i,j,N);//mueve por izquierda
							siSopladitaB(i,j,N);
							}
				    imprimir();
                    }
                    else{
						system("cls");
						imprimir();
					    cout<<endl<<"Movimiento invalido, intente nuevamente"<<endl;
						goto B;
					}
                }else
                    {
						system("cls");
						imprimir();
					    cout<<endl<<"Movimiento invalido, intente nuevamente"<<endl;
						goto B;
                     }
                     
                                    
        L:
        cout<<"ingrese posicion que desea mover y direccion de Negros"<<endl;
    	cin>>jota>>i>>direccion;
    	if(direccion!='i'&& direccion!='d'){cout<<endl<<"Direccion invalida, intente nuevamente"<<endl;
			goto L;
		}
        j=cambioL(jota);
        dir=direc(direccion);//determina direccion con booleano
        
        cout<<"el i es "<<i<<" y j es "<<j<<endl;
        if(esCoronaN(i-1,j-1)==true)
        {
			K:
            cout<<"ingrese direccion y cantidad de posiciones a mover"<<endl;
            cin>>diraux>>N;
            if(diraux!='a'&&diraux!='b'){
				cout<<endl<<"Direccion invalida, intente nuevamente"<<endl;
				goto K;
		}
            daux=diaux(diraux);
        }
        else N=1;
        
                
                if(siComeN(i-1,j-1,dir,N,esCoronaN(i-1,j-1),daux)==1)//comprobar si puede capturar por izquierda
                {
                   siSopladitaN(i-1,j-1,N);
                   imprimir();
                }
                else if(siComeN(i-1,j-1,dir,N,esCoronaN(i-1,j-1),daux)==2)//determina captura por derecha
                {
                    if(siMueveN(i-1,j-1,dir,N,esCoronaN(i-1,j-1),daux)!=7)//comprobar si puede mover por izquierda
                    {
						i=i-1;
						j=j-1;
						 if(puedeComerN(i,j,N,esCoronaN(i,j))!=0)tablero[i][j]='+';
						 else{
                       moverNegra(siMueveN(i,j,dir,N,esCoronaN(i,j),daux),i,j,N);//mueve por izquierda
                       siSopladitaN(i,j,N);
				   }
                       imprimir();
                    }
                    else{
						system("cls");
						imprimir();
					    cout<<endl<<"Movimiento invalido, intente nuevamente"<<endl;
						goto L;
					}
                }else
                      {
						system("cls");
						imprimir();
					    cout<<endl<<"Movimiento invalido, intente nuevamente"<<endl;
						goto L;
                       }
            
              goto B;
            }
        return 0;
}

