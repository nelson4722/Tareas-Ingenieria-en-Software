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
        tablero[1][1]='b';
        tablero[0][0]='+';
        tablero[8][8]='n';
        tablero[9][9]='+';
        tablero[6][4]='n';
        tablero[4][4]='n';
        tablero[3][7]='b';
        tablero[5][7]='b';
    	imprimir();//imprime el tablero
        while(true){//ciclo infinito, falta darle condicion de termino
            cout<<"El valor de N es "<<N<<endl;
        cout<<"ingrese posicion que desea mover y direccion de Blancos"<<endl;
    	cin>>jota>>i>>direccion;
        //i=iaux;
        j=cambioL(jota);
    	dir=direc(direccion);//determina direccion con booleano
        
       L: 
        cout<<"el i es "<<i<<" y j es "<<j<<endl;
        if(esCoronaB(i-1,j-1)==true)
        {
            cout<<"ingrese direccion y cantidad de posiciones a mover"<<endl;
            cin>>diraux>>N;
            daux=diaux(diraux);
        }
        else
        {
            N=1;
        }

        cout<<"el valor de puedeComerB es "<<puedeComerB(i-1,j-1,N,esCoronaB(i-1,j-1))<<endl;
        if(puedeComerB(i-1,j-1,N,esCoronaB(i-1,j-1)))//prioridad de capturar por sobre desplazar
        {
            cout<<"el valor de siComeB es "<<siComeB(i-1,j-1,dir,N,esCoronaB(i-1,j-1),daux)<<endl;
            if(siComeB(i-1,j-1,dir,N,esCoronaB(i-1,j-1),daux))//comprobar si puede capturar por izquierda
            {
                
               //cout<<"el valor de comerBlanca es "<<comerBlanca(i-1,j-1,dir,N,esCoronaB(i-1,j-1),daux)<<endl;
               comerBlanca(i-1,j-1,dir,N,esCoronaB(i-1,j-1),daux);//captura por izquierda
               imprimir();
            }
            else//determina captura por derecha
            {
               comerBlanca(i-1,j-1,dir,N,esCoronaB(i-1,j-1),daux);//captura por derecha
               imprimir();
            }
        }
        else//si no puede capturar, entonces debe moverse
        {
            cout<<"el valor de puedeMoverB es "<<puedeMoverB(i-1,j-1,N,esCoronaB(i-1,j-1))<<endl;
            if(puedeMoverB(i-1,j-1,N,esCoronaB(i-1,j-1)))//comprueba si puede mover
            {
                cout<<"el valor de siMueveB es "<<siMueveB(i-1,j-1,dir,N,esCoronaB(i-1,j-1),daux)<<endl;
                if(siMueveB(i-1,j-1,dir,N,esCoronaB(i-1,j-1),daux))//comprobar si puede mover por izquierda
                {
                   moverBlanca(i-1,j-1,dir,N,esCoronaB(i-1,j-1),daux);//mueve por izquierda
                   i=i-1;
                   int k=j-1;
                   cout<<"el valor de puedeCoronarB es "<<puedeCoronarB(i-1,k-1)<<endl;
                   if(puedeCoronarB(i-1,k-1)==true)
                   {
                      CoronarB(i-1,k-1);
                   }
                    imprimir();
                }
                else//determina movida por derecha
                {
                   moverBlanca(i-1,j-1,dir,N,esCoronaB(i-1,j-1),daux);//mueve por derecha
                   i=i-1;
                   int k=j-1;
                   cout<<"el valor de puedeCoronarB es "<<puedeCoronarB(i-1,k+1)<<endl;
                   if(puedeCoronarB(i-1,k+1)==true)
                   {
                      CoronarB(i-1,k+1);
                   }
                   imprimir();
                }
                
            } 
            goto H;
        }       
        N=1;
        i=iaux+1;
        j=jaux+1;
        dir=direc(h);
        diraux=diaux(v);
        goto L;
        cout<<"el valor de i es "<<i<<" y j es "<<j<<endl;
        H: 
        iaux=0;jaux=0;
        cout<<"ingrese posicion que desea mover y direccion de Negros"<<endl;
    	cin>>jota>>i>>direccion;
        //i=iaux;
        j=cambioL(jota);
        dir=direc(direccion);//determina direccion con booleano
        M: 
        cout<<"el i es "<<i<<" y j es "<<j<<endl;
        if(esCoronaN(i-1,j-1)==true)
        {
            cout<<"ingrese direccion y cantidad de posiciones a mover"<<endl;
            cin>>diraux>>N;
            daux=diaux(diraux);
        }
        else
        {
            N=1;
        }
         cout<<"el valor de puedeComerN es "<<puedeComerN(i-1,j-1,N,esCoronaN(i-1,j-1))<<endl;
        if(puedeComerN(i-1,j-1,N,esCoronaN(i-1,j-1)))//prioridad de capturar por sobre desplazar
        {
            cout<<"el valor de siComeN es "<<siComeN(i-1,j-1,dir,N,esCoronaN(i-1,j-1),daux)<<endl;
            if(siComeN(i-1,j-1,dir,N,esCoronaN(i-1,j-1),daux))//comprobar si puede capturar por izquierda
            {
               comerNegra(i-1,j-1,dir,N,esCoronaN(i-1,j-1),daux);//captura por izquierda
               imprimir();
            }
            else//determina captura por derecha
            {
               comerNegra(i-1,j-1,dir,N,esCoronaB(i-1,j-1),daux);//captura por derecha
               imprimir();
            }
        }
        else//si no puede capturar, entonces debe moverse
        {
            cout<<"el valor de puedeMoverN es "<<puedeMoverN(i-1,j-1,N,esCoronaN(i-1,j-1))<<endl;
            if(puedeMoverN(i-1,j-1,N,esCoronaB(i-1,j-1)))//comprueba si puede mover
            {
                cout<<"el valor de siMueveN es "<<siMueveN(i-1,j-1,dir,N,esCoronaN(i-1,j-1),daux)<<endl;
                if(siMueveN(i-1,j-1,dir,N,esCoronaB(i-1,j-1),daux))//comprobar si puede mover por izquierda
                {
                   moverNegra(i-1,j-1,dir,N,esCoronaN(i-1,j-1),daux);//mueve por izquierda
                   i=i-1;
                   int k=j-1;
                   cout<<"el valor de puedeCoronarN es "<<puedeCoronarN(i+1,k+1)<<endl;
                   if(puedeCoronarN(i+1,k+1)==true)
                   {
                      CoronarN(i+1,k+1);
                   }
                    imprimir();
                }
                else//determina movida por derecha
                {
                   moverNegra(i-1,j-1,dir,N,esCoronaN(i-1,j-1),daux);//mueve por izquierda
                   i=i-1;
                   int k=j-1;
                    cout<<"el valor de puedeCoronarN es "<<puedeCoronarN(i+1,k-1)<<endl;
                   if(puedeCoronarN(i+1,k-1)==true)
                   {
                      CoronarN(i+1,k-1);
                   }
                    imprimir();
                }
            }
            goto N;
        }
        N=1;
        i=iaux+1;
        j=jaux+1;
        dir=direc(h);
        diraux=diaux(v);
        goto M;
        cout<<"el valor de i es "<<i<<" y j es "<<j<<endl;
        N:
        cout<<"";  
    }
	return 0;
}