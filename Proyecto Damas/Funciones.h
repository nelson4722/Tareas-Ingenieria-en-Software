#ifndef FUNCIONES_H
#define	FUNCIONES_H
#include "Maquina.h"
//"/usr/bin/clear"
#ifdef __linux__
#define LIMPIAR "clear"
#endif // __linux__
#ifdef __MINGW32__
#define LIMPIAR "cls"
#endif // __MINGW32__
#include <cstdlib>
#include <sstream>
#include <ostream>
#include <cstdio>
#include <string>
#include <iostream>
#define length(x) (sizeof(x)/sizeof(x[0]))//obtiene el tamaño de un arreglo
using namespace std;
using namespace std;
char ENE[2];
int N=0;// cantidad de piezas a mover la coronada
int numeros[] = {1,2,3,4,5,6,7,8,9,10};
char letras[] = {'A','B','C','D','E','F','G','H','I','J'};
bool interruptor;
void delay()
{
       for ( int c = 1 ; c <= 15000 ; c++ )
       for ( int d = 1 ; d <= 15000 ; d++ )
       {}
}
void delay1()
{
       for ( int c = 1 ; c <= 23000 ; c++ )
       for ( int d = 1 ; d <= 23000 ; d++ )
       {}
}
char cambioP (int j)
{

    for(int i=0;i<10;i++)
    {
        if(j==numeros[i])
            return letras[i];
    }
}
int existeCorona(int x, int y,char tabla[10][10],char a,char b)
{

	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
		if(tabla[x][y]==a)
		if(tabla[i][j]==b)
		 if(puedeComerB(i,j,1,true)!=0){
			tablero[i][j]='+';
			cout<<endl<<"sopladita en posicion: "<<cambioP(j+1)<<", "<<i+1<<endl;
			return 0;
		}
		return 0;
}
bool columnaValida(char j)
{
   int t=0;
   bool e=false;
		while(t<length(letras)){
            if(j==letras[t])return true;
            else e=false;
           t++;
        }
        return e;
}
bool filaValida(int i)
{
   int t=0;
   bool e=false;

		while(t<length(numeros)){
            if(i==numeros[t])return true;
            else e=false;
           t++;
        }
        return e;
}

void inicio()// encabezado visual del programa
{
    printf("%c[%d;%d;%dm", 0x1B, 0,1,15);
    cout<<endl;
    cout<<"                  ================\n";
    cout<<"                  TABLERO DE DAMAS\n";
    cout<<"                  ================\n";
    cout<<endl;
}
void menu()
{
    cout<<"BIENVENIDO AL JUEGO DE DAMAS!!"<<endl;
    cout<<"SELECCIONE UNA OPCION DEL MENU:"<<endl;
    cout<<"1.- JUGAR 1 VS 1"<<endl;
    cout<<"2.- JUGAR 1 VS CPU"<<endl;
    cout<<"3.- INSTRUCCIONES DE JUEGO"<<endl;
    cout<<"4.- VER MAS..."<<endl;
    cout<<"5.- SALIR"<<endl;
}
bool verificarTermino(char Tabla[10][10], char x,char y)
{
	bool aux=true;
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			if(Tabla[i][j]==x||Tabla[i][j]==y)aux=false;

	return aux;
}
void prueba(char Tabla[10][10], char x)
{

	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			if(Tabla[i][j]==x)Tabla[i][j]='+';

}
bool termino(char tabla[10][10])
{
	bool aux=true;
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			if((puedeComerB(i,j,1,false)!=0 || puedeComerB(i,j,1,true)!=0)
			||(siMueveB(i,j,true,1,false,false)!=7 || siMueveB(i,j,false,1,false,false)!=7)
			||(siMueveB(i,j,true,1,true,true)!=7 || siMueveB(i,j,true,1,true,false)!=7)
			||(siMueveB(i,j,false,1,true,true)!=7 || siMueveB(i,j,false,1,true,false)!=7))
			aux=false;
		}
	}
return aux;
}
void crearlimite()//comprueba que no salga del tablero establecido
{
    for(int i=0;i<T;i++){
        for(int j=0;j<T;j++){
            tab[i][j]=true;}}
}
bool direc(string d)//determina la dirección de movimiento de ficha
{
  if(d=="i")return true;
  else if(d=="d")return false;
}
bool diaux(string d)//determina la dirección de movimiento de ficha
{
  if(d=="b")return true;
  else if(d=="a")return false;
}


//~ int cambioL (string j)//cambia letra de posición por un numero
//~ {//utilización de letras para trabajar
	//~
    //~ for(int i=0;i<10;i++)
    //~ {
        //~ if(j==letras[i])
            //~ return numeros[i];
    //~ }
//~ }
int cambio1 (string j)//cambia letra de posición por un numero
{//utilización de letras para trabajar
	int numeros[] = {1,2,3,4,5,6,7,8,9,10};
    string letras[] = {"A","B","C","D","E","F","G","H","I","J"};
    for(int i=0;i<10;i++)
    {
        if(j==letras[i])
            return numeros[i];
    }
}
int cambio2(string w)
{
	int numeros[] = {1,2,3,4,5,6,7,8,9,10};
	string letras[] = {"1","2","3","4","5","6","7","8","9","10"};
	for(int i=0;i<10;i++)
    {
        if(w==letras[i])
            return numeros[i];
    }
    return -1;
}

bool validacion(string letra)
{
	if(letra!="A"&&letra!="B"&&letra!="C"&&letra!="D"&&letra!="E"&&letra!="F"&&letra!="G"&&letra!="H"&&letra!="I"&&letra!="J")
	return false;
	else return true;
}
bool validacion1(string numero)
{
	if(numero!="1"&&numero!="2"&&numero!="3"&&numero!="4"&&numero!="5"&&numero!="6"&&numero!="7"&&numero!="8"&&numero!="9"&&numero!="10")
	return false;
	else return true;
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
    //system(LIMPIAR);
    printf("%c[%d;%d;%dm", 0x1B, 0,1,15);
    //inicio();
    for(int i = 0; i < T; i++)
    {
        if (i == 0)
        {
            cout<<"   ";
                for (int k = 0; k < T; k++)
                {
                cout<<"    "<<cambioN(k+1);
                }
                //cout<<endl;
                cout<<endl;
        }
        if(i>8)cout<<" "<<i+1<<"  ";
        else cout<<"  "<<i+1<<"  ";

       // cout<<i+1<<" ";
        for(int j = 0; j < T; j++)
        {
                if(tablero[i][j]=='n'||tablero[i][j]=='b')printf("%c[%d;%d;%dm  %c  ", 0x1B, 7,1,1,tablero[i][j]);
                else  if(tablero[i][j]=='N'||tablero[i][j]=='B')printf("%c[%d;%d;%dm  %c  ", 0x1B, 7,1,1,tablero[i][j]);
                else if(tablero[i][j]=='+')printf("%c[%d;%d;%dm     ", 0x1B, 7,1,1);
                else if(tablero[i][j]=='-')printf("%c[%d;%d;%dm     ", 0x1B, 1,41,41);

               // else if(tablero[i][j]=='-')printf("%c[%d;%d;%dm - ", 0x1B, 0,1,15);
                printf("%c[%d;%d;%dm", 0x1B, 0,1,1);
                //cout<<"  "<<tablero[i][j]<<" ";
        }
        //cout<<endl;
        cout<<endl;
    }
    cout<<endl;
}
void juegoBlanca()
{
        string direccion,columna,fila,num,lado,lado1,diraux;
        bool dir,daux;
        char d;
        int i=0,j=0;

    B:
    N=1;



		if(verificarTermino(tablero,'b','B')){
			cout<<endl<<"¡¡¡ ENHORAMALA !!!"<<endl<<" Usted ha perdido la partida, le han capturado todas las fichas"<<endl;
			delay();
			getchar();
			getchar();
			interruptor=false;
        }
        if(termino(tablero)){
			cout<<endl<<"¡¡¡ ENHORAMALA !!!"<<endl<<" Usted ha perdido la partida, ya no puede realizar movimientos"<<endl;
			delay();
			getchar();
			getchar();
			interruptor=false;
        }
        if(interruptor){
        cout<<"FORMATO DE DATOS: Columna(A-J) Fila(1-10) Direccion(i-d)"<<endl<<endl;
        cout<<"Ingrese coordenada de la Columna(A-J) de la pieza que desea mover: ";
    	cin>>columna;

    	if(validacion(columna)){
			j=cambio1(columna);
			d=cambioP(j);
		}
    	else {
			system(LIMPIAR);
			imprimir();
			cout<<endl<<"---¡Coordenada no valida, intente nuevamente!---"<<endl;
			goto B;
		}

    	cout<<"Ingrese coordenada de la Fila(1-10) de la pieza que desea mover: ";
    	cin>>fila;

    	if(validacion1(fila))
    	i=atoi(fila.c_str());
    	else {
			cout<<endl<<"---¡Coordenada no valida, intente nuevamente!---"<<endl;
			goto B;
		}

		cout<<"Ingrese direccion(i-d) de la pieza: ";
		cin>>direccion;

		if(direccion!="i" && direccion!="d")
                {
                    cout<<endl<<"---¡Direccion invalida, intente nuevamente!---"<<endl;
                    goto B;
                }

        dir=direc(direccion);//determina direccion con booleano

		if(dir)lado="izquierda";
		else lado="derecha";

        if(esCoronaB(i-1,j-1))
        {
			C:
            cout<<"FORMATO DE DATOS: Dirección(arriba (a)-abajo (b) Posiciones(1 o 2 o 3....) "<<endl;
            cout<<"Ingrese direccion(arriba (a)-abajo (b)): ";
            cin>>diraux;
            if(diraux!="a"&& diraux!="b")
            {
                cout<<endl<<"---¡Coordenada invalida, intente nuevamente!---"<<endl;
                goto C;
            }
            daux=diaux(diraux);
            cout<<"Ingrese cantidad de posiciones a mover: ";
            cin>>num;
            if(cambio2(num)!=-1)N=cambio2(num);
            else{
				cout<<endl<<"---¡Coordenada invalida, intente nuevamente!---"<<endl;
                goto C;
			}
			if(daux)lado1="abajo";
            else lado1="arriba";

			cout<<endl<<"La pieza ["<<d<<", "<<i<<"] se esta moviendo hacia su "<<lado<<" y a "<<lado1<<" "<<N<<" posiciones"<<endl<<endl;
        }else cout<<endl<<"La pieza ["<<d<<","<<i<<"] se esta moviendo hacia su "<<lado<<endl;
        delay();

        copia(taux,tablero);
                if(siComeB(i-1,j-1,dir,N,esCoronaB(i-1,j-1),daux)==1)//comprobar si puede capturar por izquierda
                {
					existeCorona(i-1,j-1,taux,'b','B');
                    system(LIMPIAR);
                            inicio();
                            imprimir();
                }
                else if(siComeB(i-1,j-1,dir,N,esCoronaB(i-1,j-1),daux)==2)//determina captura por derecha
                {
                    if(siMueveB(i-1,j-1,dir,N,esCoronaB(i-1,j-1),daux)!=7)//comprobar si puede mover por izquierda
                    {
						i=i-1;
                        j=j-1;
                        if(puedeComerB(i,j,N,esCoronaB(i,j))!=0){
							tablero[i][j]='+';
							cout<<endl<<"sopladita en posicion: "<<cambioP(j)<<", "<<i<<endl;
						}
						else{
                            moverBlanca(siMueveB(i,j,dir,N,esCoronaB(i,j),daux),i,j,N);//mueve por izquierda
							siSopladitaB(i,j,N);
							}
                        system(LIMPIAR);
                        inicio();
				        imprimir();
                    }
                    else{
                            system(LIMPIAR);
                            inicio();
                            imprimir();
                        cout<<endl<<"---Movimiento invalido, intente nuevamente"<<endl;
                            goto B;
                    }
                }else
                    {
                            system(LIMPIAR);
                            inicio();
                            imprimir();
                        cout<<endl<<"---Movimiento invalido, intente nuevamente"<<endl;
                            goto B;
                     }
}
}
void juegoNegra()
{
        string direccion,columna,fila,num,lado,lado1,diraux;
        bool dir,daux;
        char d;
        int i=0,j=0;

    B:
    N=1;

		if(verificarTermino(tablero,'n','N')){
			cout<<endl<<"¡¡¡ ENHORAMALA !!!"<<endl<<" Usted ha perdido la partida, le han capturado todas las fichas"<<endl;
			delay();
			getchar();
			getchar();
			interruptor=false;
        }
        if(termino(tablero)){
			cout<<endl<<"¡¡¡ ENHORAMALA !!!"<<endl<<" Usted ha perdido la partida, ya no puede realizar movimientos"<<endl;
			delay();
			getchar();
			getchar();
			interruptor=false;
        }
		if(interruptor){
        cout<<"FORMATO DE DATOS: Columna(A-J) Fila(1-10) Direccion(i-d)"<<endl<<endl;
        cout<<"Ingrese coordenada de la Columna(A-J) de la pieza que desea mover: ";
    	cin>>columna;

    	if(validacion(columna)){
			j=cambio1(columna);
			d=cambioP(j+1);
		}
    	else {
			system(LIMPIAR);
			imprimir();
			cout<<endl<<"---¡Coordenada no valida, intente nuevamente!---"<<endl;
			goto B;
		}

    	cout<<"Ingrese coordenada de la Fila(1-10) de la pieza que desea mover: ";
    	cin>>fila;

    	if(validacion1(fila))
    	i=atoi(fila.c_str());
    	else {
			cout<<endl<<"---¡Coordenada no valida, intente nuevamente!---"<<endl;
			goto B;
		}

		cout<<"Ingrese direccion(i-d) de la pieza: ";
		cin>>direccion;

		if(direccion!="i" && direccion!="d")
                {
                    cout<<endl<<"---¡Direccion invalida, intente nuevamente!---"<<endl;
                    goto B;
                }

        dir=direc(direccion);//determina direccion con booleano

		if(dir)lado="izquierda";
		else lado="derecha";

        if(esCoronaN(i-1,j-1))
        {
			C:
            cout<<"FORMATO DE DATOS: Dirección(arriba (a)-abajo (b) Posiciones(1 o 2 o 3....) "<<endl;
            cout<<"Ingrese direccion(arriba (a)-abajo (b)): ";
            cin>>diraux;
            if(diraux!="a"&& diraux!="b")
            {
                cout<<endl<<"---¡Coordenada invalida, intente nuevamente!---"<<endl;
                goto C;
            }
            daux=diaux(diraux);
            cout<<"Ingrese cantidad de posiciones a mover: ";
            cin>>num;
            if(cambio2(num)!=-1)N=cambio2(num);
            else{
				cout<<endl<<"---¡Coordenada invalida, intente nuevamente!---"<<endl;
                goto C;
			}
			if(daux)lado1="abajo";
            else lado1="arriba";

			cout<<endl<<"La pieza ["<<d<<", "<<i+1<<"] se esta moviendo hacia su "<<lado<<" y a "<<lado1<<" "<<N<<" posiciones"<<endl<<endl;
        }else cout<<endl<<"La pieza ["<<d<<","<<i+1<<"] se esta moviendo hacia su "<<lado<<endl;;
        delay();
		copia(taux,tablero);
                if(siComeN(i-1,j-1,dir,N,esCoronaN(i-1,j-1),daux)==1)//comprobar si puede capturar por izquierda
                {
					existeCorona(i-1,j-1,taux,'n','N');
                   system(LIMPIAR);
                            inicio();
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
                        system(LIMPIAR);
                        inicio();
				    imprimir();
                    }
                    else{
                            system(LIMPIAR);
                            inicio();
                            imprimir();
                        cout<<endl<<"---¡Movimiento invalido, intente nuevamente!---"<<endl;
                            goto B;
                    }
                }else
                    {
                            system(LIMPIAR);
                            inicio();
                            imprimir();
                        cout<<endl<<"---¡Movimiento invalido, intente nuevamente!---"<<endl;
                            goto B;
                     }
		}
}

void juegoMaquina()
{
    L:
        int B[5];
        string lado,lado1;

        maquina(B);
        int i=B[0],j=B[1],daux=B[3];
        bool dir=B[2];


        N=1;
        if(verificarTermino(tablero,'n','N')){
			cout<<endl<<"¡¡¡ ENHORABUENA !!!"<<endl<<" Usted ha ganado la partida"<<endl;
			delay();
			getchar();
			getchar();
			interruptor=false;
        }
        if(B[0]==-1){
			cout<<endl<<"¡¡¡ ENHORABUENA !!!"<<endl<<" Usted ha ganado la partida, "<<endl;
			delay();
			getchar();
			getchar();
			interruptor=false;
		}
		if(interruptor){
        if(dir)lado="izquierda";
		else lado="derecha";

		char d=cambioP(j+1);

		if(esCoronaN(i,j))
		{
			N=B[4];

            if(daux)lado1="abajo";
            else lado1="arriba";
            cout<<endl<<"La pieza ["<<d<<", "<<i+1<<"] se esta moviendo hacia su "<<lado<<" y a "<<lado1<<" "<<N<<" posiciones"<<endl<<endl;
		}
		else cout<<endl<<"La pieza ["<<d<<","<<i+1<<"] se esta moviendo hacia su "<<lado<<endl;
              delay1();

		if(siComeN(i,j,dir,N,esCoronaN(i,j),daux)==1)//comprobar si puede capturar por izquierda
		{
		   imprimir();
		}
		else if(siComeN(i,j,dir,N,esCoronaN(i,j),daux)==2)//determina captura por derecha
		{
			if(siMueveN(i,j,dir,N,esCoronaN(i,j),daux)!=7)//comprobar si puede mover por izquierda
			{

			 if(puedeComerN(i,j,N,esCoronaN(i,j))!=0)tablero[i][j]='+';
			 else{
					   moverNegra(siMueveN(i,j,dir,N,esCoronaN(i,j),daux),i,j,N);//mueve por izquierda
					   siSopladitaN(i,j,N);
		         }
			   system(LIMPIAR);
			   imprimir();
             }
                    else{
							system(LIMPIAR);
							imprimir();
						    cout<<endl<<"---Movimiento invalido, intente nuevamente"<<endl;
							goto L;
					    }
                }
                else
                 {
						system(LIMPIAR);
						imprimir();
					    cout<<endl<<"---Movimiento invalido, intente nuevamente"<<endl;
						goto L;
                  }
}
}
#endif	/* FUNCIONES_H */


