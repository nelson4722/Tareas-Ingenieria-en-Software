#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#define T 10 //tamaño maximo del tablero

using namespace std;
char tablero[T][T];//tablero de piezas
bool tab[T][T];//tablero de limites

void inicio()// encabezado visual del programa
{
    cout<<"\t================\n";
    cout<<"\tTABLERO DE DAMAS\n";
    cout<<"\t================\n";
    cout<<endl;
}
bool puedeMover(int i, int j) //comprueba que la ficha X,Y puede lograr desplazarse
{
   if(tablero[i-1][j-1]=='+' ||tablero[i-1][j+1]=='+')//puede mover las Blancas
   {
       return true;
   }
   else 
   {
       if(tablero[i+1][j-1]=='+' ||tablero[i+1][j+1]=='+')//puede mover las Negras
       {
           return true;
       }
       else//no puede mover ni Blancas ni Negras
       {
           return false;
       }      
   }  
}
bool puedeComer(int i, int j)//comprueba que la ficha X,Y puede capturar alguna ficha rival
{
   if((tablero[i-1][j-1]=='N'&& tablero[i-2][j-2]=='+') || (tablero[i-1][j+1]=='N' && tablero[i-1][j+1]=='+'))
   {//puede comer las Blancas
       return true;
   }
   else 
   {   
       if((tablero[i+1][j-1]=='B'&& tablero[i+2][j-2]=='+')||( tablero[i+1][j+1]=='B' && tablero[i+2][j+2]=='+'))
       {//puede comer las Negras
           return true;
       }
       else//no puede comer ni Blancas ni Negras
       {
           return false;
       }
   }
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

bool siMueveN(int i, int j,bool iz)//determina direccion de movimiento de Negra
{
    if(iz==true)//puede desplazar Negra hacia la izquierda
    {
       if(tablero[i+1][j-1]=='+' && tab[i+1][j-1]==true)return true;
    }
    else if(iz==false)//puede desplazar Negra hacia la derecha
    {
        if(tablero[i+1][j+1]=='+'&& tab[i+1][j+1]==true)return false;
    }
}

bool siComeN(int i, int j,bool iz)//determina la dirección de captura de Negra
{
    if(iz==true)//puede capturar Negra hacia la izquierda
    {
       if(tablero[i+1][j-1]=='B' && tab[i+1][j-1]==true)
       {
           if(tablero[i+2][j-2]=='+' && tab[i+2][j-2]==true)return true;
           cout<<"puede comer por izquierda"<<endl;
       }
    }
    else if(iz==false)//puede capturar Negra hacia la derecha
    {
        if(tablero[i+1][j+1]=='B'&& tab[i+1][j+1]==true)
        {
             if(tablero[i+2][j+2]=='+'&& tab[i+2][j+2]==true)return false;
            cout<<"puede comer por derecha"<<endl;
        }
    }
}

bool siMueveB(int i, int j,bool iz)//determina direccion de movimiento de Blanca
{
    if(iz==true)//puede desplazar Blanca hacia la izquierda
    {
       if(tablero[i-1][j-1]=='+' && tab[i-1][j-1]==true)return true;
       cout<<"puede mover por izquierda"<<endl;
    }
    else if(iz==false)//puede desplazar Blanca hacia la derecha
    {
        if(tablero[i-1][j+1]=='+'&& tab[i-1][j+1]==true)return false;
        cout<<"puede mover por derecha"<<endl;
    }
}

bool siComeB(int i, int j,bool iz)//determina la dirección de captura de Blanca
{
    if(iz==true)//puede capturar Blanca hacia la izquierda
    {
       if(tablero[i-1][j-1]=='N' && tab[i-1][j-1]==true)
       {
           if(tablero[i-2][j-2]=='+' && tab[i-2][j-2]==true)return true;
           cout<<"puede comer por izquierda"<<endl;
       }    
    }
    else if(iz==false)//puede capturar Blanca hacia la derecha
    {
        if(tablero[i-1][j+1]=='N'&& tab[i-1][j+1]==true)
        {
            if(tablero[i-2][j+2]=='+'&& tab[i-2][j+2]==true)return false;
            cout<<"puede comer por derecha"<<endl;
        }
            
    }
}

void moverNegra(int i, int j,bool iz)//Accion de movimiento Negra
{
    char aux;
    cout<<endl;
    cout<<endl;
    if(siMueveN(i,j,iz))//si puede mover Negra hacia la izquierda
    {
        //moviemiento por izquierda
        if(tablero[i][j]=='N' && tablero[i+1][j-1]=='+')
        {
             aux='N';
             tablero[i][j]='+';
             tablero[i+1][j-1]=aux; 
        }
        else
        {
            cout<<"No se puede cambiar tal ficha"<<endl;
        }     
    }
    else if(!siMueveN(i,j,iz))//si puede mover Negra hacia la derecha
    {
        //moviemiento por derecha
        if(tablero[i][j]=='N' && tablero[i+1][j+1]=='+')
        {
            aux='N';
            tablero[i][j]='+';
            tablero[i+1][i+1]=aux;
        }
        else
        {
            cout<<"No se puede cambiar tal ficha"<<endl;
        }
    }
}
void comerNegra(int i, int j,bool iz)//Accion de captura Negra
{
    char aux;
    cout<<endl;
    cout<<endl;
    if(siComeN(i,j,iz))//si puede capturar Negra hacia la izquierda
    {
        //captura por izquierda
        if(tablero[i][j]=='N' && tablero[i+1][j-1]=='B' && tablero[i+2][j-2]=='+')
        {
             aux='N';
             tablero[i][j]='+';
             tablero[i+1][j-1]='+';
             tablero[i+2][j-2]=aux; 
        }
        else
        {
            cout<<"No se puede comer tal ficha"<<endl;
        }
    }
    else if(!siComeN(i,j,iz))//si puede capturar Negra hacia la derecha
    {
        //captura por derecha
        if(tablero[i][j]=='N' && tablero[i+1][j+1]=='B' && tablero[i+2][j+2]=='+')
        {
            aux='N';
            tablero[i][j]='+';
            tablero[i+1][i+1]='+';
            tablero[i+2][i+2]=aux;
        }
        else
        {
            cout<<"No se puede comer tal ficha"<<endl;
        }     
    }
}

void moverBlanca(int i, int j,bool iz)//Accion de movimiento Blanca
{
    char aux;
    cout<<endl;
    cout<<endl;
    if(siMueveB(i,j,iz))//si puede mover Blanca hacia la izquierda
    {
        //moviemiento por izquierda
        if(tablero[i][j]=='B' && tablero[i-1][j-1]=='+')
        {
            aux='B';
            tablero[i][j]='+';
            tablero[i-1][j-1]=aux;
        }
        else
        {
            cout<<"No se puede cambiar tal ficha"<<endl;
        }
    }
    else if(!siMueveB(i,j,iz))//si puede mover Blanca hacia la derecha
    {
        //moviemiento por derecha
         if(tablero[i][j]=='B'&& tablero[i-1][j+1]=='+')
         {
             aux='B';
             tablero[i][j]='+';
             tablero[i-1][j+1]=aux;
         }
         else
         {
             cout<<"No se puede cambiar tal ficha"<<endl;
         }  
    }
}

void comerBlanca(int i, int j,bool iz)//Accion de captura Blanca
{
    char aux;
    cout<<endl;
    cout<<endl;
    if(siComeB(i,j,iz))//si puede capturar Blanca hacia la izquierda
    {
        //moviemiento por izquierda
        if(tablero[i][j]=='B' && tablero[i-1][j-1]=='N'&& tablero[i-2][j-2]=='+')
        {
            aux='B';
            tablero[i][j]='+';
            tablero[i-1][j-1]='+';
            tablero[i-2][j-2]=aux;
        }
        else
        {
            cout<<"No se puede cambiar tal ficha"<<endl;
        }     
    }
    else if(!siComeB(i,j,iz))//si puede capturar Blanca hacia la derecha
    {
        //moviemiento por derecha
         if(tablero[i][j]=='B'&& tablero[i-1][j+1]=='N'&& tablero[i-2][j+2]=='+')
         {
             aux='B';
             tablero[i][j]='+';
             tablero[i-1][j+1]='+';
             tablero[i-2][j+2]=aux;
         }
         else
         {
             cout<<"No se puede cambiar tal ficha"<<endl;
         }
    }
}

void llenar(){//Crear el tablero de Damas
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

void imprimir(){//Muestra el pantalla el Tablero de Damas
    system("clear");
    inicio();
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
}


int main(){
        int i; //direccion de filas por numeros
        char jota;//direccion de columnas por letras
        char direccion; //'i' o 'd'
        bool dir;//si 'i' retorna true y 'd' retorna false
        crearlimite();//determina el limite del tablero
        llenar();//llena las fichas y cuadros de desplazamiento
    	imprimir();//imprime el tablero
        while(true){//ciclo infinito, falta darle condicion de termino
        cout<<"ingrese posicion que desea mover y direccion de Blancos"<<endl;
    	cin>>jota>>i>>direccion;
    	dir=direc(direccion);//determina direccion con booleano
        if(puedeComer(i-1,cambioL(jota)-1))//prioridad de capturar por sobre desplazar
        {
            if(siComeB(i-1,cambioL(jota)-1,dir))//comprobar si puede capturar por izquierda
            {
               comerBlanca(i-1,cambioL(jota)-1,dir);//captura por izquierda
               imprimir();
            }
            else//determina captura por derecha
            {
               comerBlanca(i-1,cambioL(jota)-1,dir);//captura por derecha
               imprimir();
            }
        }
        else//si no puede capturar, entonces debe moverse
        {
            if(puedeMover(i-1,cambioL(jota)-1))//comprueba si puede mover
            {
                if(siMueveB(i-1,cambioL(jota)-1,dir))//comprobar si puede mover por izquierda
                {
                   moverBlanca(i-1,cambioL(jota)-1,dir);//mueve por izquierda
                   imprimir();
                }
                else//determina movida por derecha
                {
                   moverBlanca(i-1,cambioL(jota)-1,dir);//mueve por derecha
                   imprimir();
                }   
            }     
        }
        
        cout<<"ingrese posicion que desea mover y direccion de Negros"<<endl;
    	cin>>jota>>i>>direccion;
        dir=direc(direccion);//determina direccion con booleano
        if(puedeComer(i-1,cambioL(jota)-1))//prioridad de capturar por sobre desplazar
        {
            if(siComeN(i-1,cambioL(jota)-1,dir))//comprobar si puede capturar por izquierda
            {
               comerNegra(i-1,cambioL(jota)-1,dir);//captura por izquierda
               imprimir();
            }
            else//determina captura por derecha
            {
               comerNegra(i-1,cambioL(jota)-1,dir);//captura por derecha
               imprimir();
            }
        }
        else//si no puede capturar, entonces debe moverse
        {
            if(puedeMover(i-1,cambioL(jota)-1))//comprueba si puede mover
            {
                if(siMueveN(i-1,cambioL(jota)-1,dir))//comprobar si puede mover por izquierda
                {
                   moverNegra(i-1,cambioL(jota)-1,dir);//mueve por izquierda
                   imprimir();
                }
                else//determina movida por derecha
                {
                   moverNegra(i-1,cambioL(jota)-1,dir);//mueve por derecha
                   imprimir();
                }   
            }     
        }
    }        
	return 0;
}
