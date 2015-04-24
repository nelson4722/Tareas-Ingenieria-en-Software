#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define T 8

using namespace std;
char tablero[T][T];
char cambio (int i)
{
    char letras[] = {'A','B','C','D','E','F','G','H','I','J'};
    return letras[i];
}
void moverFichaRival(bool izq)
{
    int i=2;
    char aux;
    cout<<endl;
     cout<<endl;
    aux=tablero[i][i];
    if(izq==true)
    {
        //moviemiento por izquierda
        tablero[i][i]=tablero[i+1][i-1];
        tablero[i+1][i-1]=aux;

    }
    else
    {
        //moviemiento por derecha
        tablero[i][i]=tablero[i+1][i+1];
        tablero[i+1][i+1]=aux;
    }


}
void moverFicha(bool izq)
{
    int i=5;
    char aux;
    cout<<endl;
     cout<<endl;
    aux=tablero[i][i];
    if(izq==true)
    {
        //moviemiento por izquierda
        tablero[i][i]=tablero[i-1][i-1];
        tablero[i-1][i-1]=aux;
    }
    else
    {
        //moviemiento por derecha
        tablero[i][i]=tablero[i-1][i+1];
        tablero[i-1][i+1]=aux;
    }

}

void llenarTablero(){
	for(int i = 0; i < T; i++)
	        for(int j = 0; j < T; j++)
		{
			if (i < 3 && ((i + j) % 2 == 0))
				tablero[i][j] = 'O';
			else
                if(i == 3 && ((i + j) % 2 == 0))
                   tablero[i][j] = '+';
                   else
                    if(i == 4 && ((i + j) % 2 == 0))
                   tablero[i][j] = '+';
            else
				if ((i > 4) && ((i + j) % 2 == 0))
					tablero[i][j] = 'P';
				else
					tablero[i][j] = '-' ;
		}
}

void imprimirTablero(){
	for(int i = 0; i < T; i++)
    {
		if (i == 0)
		{
		    cout<<"  ";
			for (int k = 0; k < T; k++)
				cout<<" "<<cambio(k)<<"  ";
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
}

int main(){
        bool izq=false;
        cout<<"\t================\n";
        cout<<"\tTABLERO DE DAMAS\n";
        cout<<"\t================\n";
        cout<<endl;

    	llenarTablero();
    	imprimirTablero();
    	moverFichaRival(izq);
    	imprimirTablero();
    	moverFicha(!izq);
    	imprimirTablero();
	return 0;
}
