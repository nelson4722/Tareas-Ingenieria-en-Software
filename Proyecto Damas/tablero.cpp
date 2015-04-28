#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#define T 10

using namespace std;
char tablero[T][T];
void inicio()
{
    cout<<"\t================\n";
    cout<<"\tTABLERO DE DAMAS\n";
    cout<<"\t================\n";
    cout<<endl;
}

bool direc(char d)
{
  if(d=='i')return true;
  else if(d=='d')return false;
}

char cambioN (int i)
{
    char letras[] = {'A','B','C','D','E','F','G','H','I','J'};
    if(i==1) return letras[0];
    else if(i==2) return letras[1];
    else if(i==3) return letras[2];
    else if(i==4) return letras[3];
    else if(i==5) return letras[4];
    else if(i==6) return letras[5];
    else if(i==7) return letras[6];
    else if(i==8) return letras[7];
    else if(i==9) return letras[8];
    else if(i==10) return letras[9];
}
int cambioL (char i)
{
    int numeros[] = {1,2,3,4,5,6,7,8,9,10};
    if(i=='A') return numeros[0];
    else if(i=='B') return numeros[1];
    else if(i=='C') return numeros[2];
    else if(i=='D') return numeros[3];
    else if(i=='E') return numeros[4];
    else if(i=='F') return numeros[5];
    else if(i=='G') return numeros[6];
    else if(i=='H') return numeros[7];
    else if(i=='I') return numeros[8];
    else if(i=='J') return numeros[9];
}
void moverFichaRival(int i, int j,bool iz)
{
    char aux;
    cout<<endl;
    cout<<endl;
    aux=tablero[i][j];
    if(iz==true)
    {
        //moviemiento por izquierda
        tablero[i][j]=tablero[i+1][j-1];
        tablero[i+1][j-1]=aux;
    }
    else if(iz==false)
    {
        //moviemiento por derecha
        tablero[i][j]=tablero[i+1][i+1];
        tablero[i+1][i+1]=aux;
    }
}
void moverFicha(int i, int j,bool iz)
{
    char aux;
    cout<<endl;
    cout<<endl;
    aux=tablero[i][j];
    if(iz==true)
    {
        //moviemiento por izquierda
        tablero[i][j]=tablero[i-1][j-1];
        tablero[i-1][j-1]=aux;
    }
    else if(iz==false)
    {
        //moviemiento por derecha
        tablero[i][j]=tablero[i-1][j+1];
        tablero[i-1][j+1]=aux;
    }

}

void llenarTablero(){

	for(int i = 0; i < T; i++)
	        for(int j = 0; j < T; j++)
		{
			if (i < 3 && ((i + j) % 2 == 0))
				tablero[i][j] = 'N';
			else
                if((i==3||i==4||i==5||i==6) && ((i + j) % 2 == 0))
                   tablero[i][j] = '+';
            else
				if ((i > 6) && ((i + j) % 2 == 0))
					tablero[i][j] = 'B';
				else
					tablero[i][j] = '-' ;
		}
}

void imprimirTablero(){
    system("/usr/bin/clear");

	for(int i = 0; i < T; i++)
    {
		if (i == 0)
		{
		    cout<<"  ";
			for (int k = 0; k < T; k++)
				cout<<" "<<cambioN(k+1)<<"  ";
			cout<<endl;
			cout<<endl;
		}

        cout<<i+1;
        	for(int j = 0; j < T; j++)
        	{
                	cout<<"  "<<tablero[i][j]<<" ";
          	}
          	cout<<endl;
          	cout<<endl;
    	}
    	inicio();
}

int main(){
        int i,j;
        char jota,direccion;
        bool dir;
    	llenarTablero();
    	imprimirTablero();
        cout<<"ingrese posicion que desea mover y direccion de Blancos"<<endl;
    	cin>>jota>>i>>direccion;
    	dir=direc(direccion);
    	moverFicha(i-1,cambioL(jota)-1,dir);
    	imprimirTablero();
        cout<<"ingrese posicion que desea mover y direccion de Negros"<<endl;
    	cin>>jota>>i>>direccion;
    	dir=direc(direccion);
    	moverFichaRival(i-1,cambioL(jota)-1,dir);
    	imprimirTablero();

	return 0;
}
