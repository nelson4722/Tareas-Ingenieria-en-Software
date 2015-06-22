#include <cstdlib>
#include <sstream>
#include <ostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#define T 10 //tamaño maximo del tablero

using namespace std;
char tablero[T][T];//tablero de piezas
bool tab[T][T];//tablero de limites
int N;
int CN=0;
int CB=0;
FILE * fp;
int iaux=0;
int jaux=0;
bool puedeCoronarN(int i, int j)
{
    if(i==9)
    {
        if(tablero[i][j]=='n')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}
bool esCoronaN(int i, int j)
{
    if(tablero[i][j]=='N')
    {
        return true;
    }
    else
    {
        return false;
    }
}
void CoronarN(int i, int j)
{
    if(puedeCoronarN(i,j)==true)
    {
        tablero[i][j]='N';
    }
}

bool puedeCoronarB(int i, int j)
{
    if(i==0)
    {
        if(tablero[i][j]=='b')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}
bool esCoronaB(int i, int j)
{
    if(tablero[i][j]=='B')
    {
        return true;
    }
    else
    {
        return false;
    }
}
void CoronarB(int i, int j)
{
    if(puedeCoronarB(i,j)==true)
    {
        tablero[i][j]='B';
    }
}
void inicio()// encabezado visual del programa
{
    cout<<"\t================\n";
    cout<<"\tTABLERO DE DAMAS\n";
    cout<<"\t================\n";
    cout<<endl;
}
bool puedeMoverB(int i, int j,int N, bool corona) //comprueba que la ficha X,Y puede lograr desplazarse
{
   if(corona==false)
   {
       if(tablero[i-N][j-N]=='+'||tablero[i-N][j+N]=='+')//puede mover las Blancas
       {
           return true;
       }
       else //no puede mover Blancas
       {
           return false;
       }
   }
   else
   {
       if(tablero[i-N][j-N]=='+'||tablero[i-N][j+N]=='+'|| tablero[i+N][j-N]=='+'||tablero[i+N][j+N]=='+')//puede mover las Blancas
       {
           return true;
       }
       else //no puede mover Blancas
       {
           return false;
       }
   }
}
bool puedeMoverN(int i, int j,int N, bool corona) //comprueba que la ficha X,Y puede lograr desplazarse
{
   if(corona==false)
   {
       if(tablero[i+N][j-N]=='+' ||tablero[i+N][j+N]=='+')//puede mover las Negras
       {
           return true;
       }
       else//no puede mover Negras
       {
           return false;
       }
   }
   else
   {
       if(tablero[i+N][j-N]=='+'||tablero[i+N][j+N]=='+'|| tablero[i-N][j+N]=='+' ||tablero[i-N][j-N]=='+')//puede mover las Negras
       {
           return true;
       }
       else//no puede mover Negras
       {
           return false;
       }
   }

}
bool puedeComerN(int i, int j, int N, bool corona)//comprueba que la ficha X,Y puede capturar alguna ficha rival
{
    if(corona==false)
    {
       if(((tablero[i+N][j-N]=='b' || tablero[i+N][j-N]=='B') &&tablero[i+(N+1)][j-(N+1)]=='+')||((tablero[i+N][j+N]=='b' || tablero[i+N][j+N]=='B')&&tablero[i+(N+1)][j+(N+1)]=='+'))
       {//puede comer las Negras
           return true;
       }
       else//no puede comer ni Blancas ni Negras
       {
           return false;
       }
    }
    else
    {
       if((tablero[i+N][j-N]=='b'&&tablero[i+(N+1)][j-(N+1)]=='+')||(tablero[i+N][j+N]=='b'&&tablero[i+(N+1)][j+(N+1)]=='+')
        ||(tablero[i-N][j-N]=='b'&&tablero[i-(N+1)][j-(N+1)]=='+')||(tablero[i-N][j+N]=='b'&&tablero[i-(N+1)][j+(N+1)]=='+')
        ||(tablero[i+N][j-N]=='B'&&tablero[i+(N+1)][j-(N+1)]=='+')||(tablero[i+N][j+N]=='B'&&tablero[i+(N+1)][j+(N+1)]=='+')
        ||(tablero[i-N][j-N]=='B'&&tablero[i-(N+1)][j-(N+1)]=='+')||(tablero[i-N][j+N]=='B'&&tablero[i-(N+1)][j+(N+1)]=='+'))
       {//puede comer las Negras
           return true;
       }
       else//no puede comer ni Blancas ni Negras
       {
           return false;
       }
    }
}
bool puedeComerB(int i, int j, int N, bool corona)//comprueba que la ficha X,Y puede capturar alguna ficha rival
{
    if(corona==false)
    {
       if(((tablero[i-N][j-N]=='n'|| tablero[i-N][j-N]=='N')&& tablero[i-(N+1)][j-(N+1)]=='+') || ((tablero[i-N][j+N]=='n'|| tablero[i-N][j+N]=='N') && tablero[i-(N+1)][j+(N+1)]=='+'))
       {//puede comer las Blancas
           return true;
       }
       else//no puede comer ni Blancas ni Negras
       {
           return false;
       }
    }
    else
    {

       if(((tablero[i+N][j-N]=='n'&&tablero[i+(N+1)][j-(N+1)]=='+')||(tablero[i+N][j+N]=='n'&&tablero[i+(N+1)][j+(N+1)]=='+'))
        ||((tablero[i-N][j-N]=='n'&&tablero[i-(N+1)][j-(N+1)]=='+')||(tablero[i-N][j+N]=='n'&&tablero[i-(N+1)][j+(N+1)]=='+'))
        ||((tablero[i+N][j-N]=='N'&&tablero[i+(N+1)][j-(N+1)]=='+')||(tablero[i+N][j+N]=='N'&&tablero[i+(N+1)][j+(N+1)]=='+'))
        ||((tablero[i-N][j-N]=='N'&&tablero[i-(N+1)][j-(N+1)]=='+')||(tablero[i-N][j+N]=='N'&&tablero[i-(N+1)][j+(N+1)]=='+')))
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

int siMueveN(int i, int j,bool iz,int N,bool corona, bool ab)//determina direccion de movimiento de Negra
{
    cout<<"SI MUEVE NEGRA"<<endl;

    if(corona==true)cout<<"corona: si"<<endl;
    else cout<<"corona: no"<<endl;

    if(iz==true)cout<<"direccion horizontal: izquierda"<<endl;
    else cout<<"direccion: derecha"<<endl;

    if(ab==true)cout<<"direccion vertical: abajo"<<endl;
    else cout<<"direccion vertical: arriba"<<endl;

    cout<<"posiciones:"<<N<<endl;
    if(corona==false)
    {
        if(iz==true)//puede desplazar Negra hacia la izquierda
        {
           if(tablero[i+N][j-N]=='+' && tab[i+N][j-N]==true)return 1;
        }
        else if(iz==false)//puede desplazar Negra hacia la derecha
        {
            if(tablero[i+N][j+N]=='+'&& tab[i+N][j+N]==true)return 2;
        }
    }
    else
    {
        if(iz==true && ab== true)//puede desplazar Negra hacia la izquierda abajo
        {
           if(tablero[i+N][j-N]=='+' && tab[i+N][j-N]==true)return 3;
        }
        else if(iz==false)//puede desplazar Negra hacia la derecha abajo
        {
            if(tablero[i+N][j+N]=='+'&& tab[i+N][j+N]==true)return 4;
        }
        if(ab==true)//puede desplazar Negra hacia la izquierda arriba
        {
           if(tablero[i-N][j-N]=='+' && tab[i-N][j-N]==true)return 5;
        }
        else if(ab==false)//puede desplazar Negra hacia la derecha arriba
        {
            if(tablero[i-N][j+N]=='+'&& tab[i-N][j+N]==true)return 6;
        }
    }
}

int siComeN(int i, int j,bool iz, int N,bool corona,bool ab)//determina la dirección de captura de Negra
{
    cout<<"SI COME NEGRA"<<endl;

    if(corona==true)cout<<"corona: si"<<endl;
    else cout<<"corona: no"<<endl;

    if(iz==true)cout<<"direccion horizontal: izquierda"<<endl;
    else cout<<"direccion: derecha"<<endl;

    if(ab==true)cout<<"direccion vertical: abajo"<<endl;
    else cout<<"direccion vertical: arriba"<<endl;

    cout<<"posiciones:"<<N<<endl;
    if(corona==false)
    {
        if(iz==true)//puede capturar Negra hacia la izquierda
        {
           if((tablero[i+N][j-N]=='b'|| tablero[i+N][j-N]=='B') && tab[i+N][j-N]==true)
           {
               if(tablero[i+(N+1)][j-(N+1)]=='+' && tab[i+(N+1)][j-(N+1)]==true)return 1;
           }
        }
        else if(iz==false)//puede capturar Negra hacia la derecha
        {
            if((tablero[i+N][j+N]=='b'|| tablero[i+N][j+N]=='B')&& tab[i+N][j+N]==true)
            {
                 if(tablero[i+(N+1)][j+(N+1)]=='+'&& tab[i+(N+1)][j+(N+1)]==true)return 2;
            }
        }
    }
    else
    {
        if(iz==true)//puede capturar Negra hacia la izquierda abajo
        {
           if((tablero[i+N][j-N]=='b'|| tablero[i+N][j-N]=='B') && tab[i+N][j-N]==true)
           {
               if(tablero[i+(N+1)][j-(N+1)]=='+' && tab[i+(N+1)][j-(N+1)]==true)return 3;
           }
        }
        else if(iz==false)//puede capturar Negra hacia la derecha abajo
        {
            if((tablero[i+N][j+N]=='b' ||tablero[i+N][j+N]=='B')&& tab[i+N][j+N]==true)
            {
                 if(tablero[i+(N+1)][j+(N+1)]=='+'&& tab[i+(N+1)][j+(N+1)]==true)return 4;
            }
        }
        if(ab==true)//puede capturar Blanca hacia la izquierda arriba
        {
           if((tablero[i-N][j-N]=='b'||tablero[i-N][j-N]=='B') && tab[i-N][j-N]==true)
           {
               if(tablero[i-(N+1)][j-(N+1)]=='+' && tab[i-(N+1)][j-(N+1)]==true)return 5;
               cout<<"puede comer por izquierda"<<endl;
           }
        }
        else if(ab==false)//puede capturar Negra hacia la derecha arriba
        {
            if((tablero[i-N][j+N]=='b'||tablero[i-N][j+N]=='B')&& tab[i-N][j+N]==true)
            {
                if(tablero[i-(N+1)][j+(N+1)]=='+'&& tab[i-(N+1)][j+(N+1)]==true)return 6;
                cout<<"puede comer por derecha"<<endl;
            }
        }
    }
}

int siMueveB(int i, int j,bool iz, int N, bool corona,bool ab)//determina direccion de movimiento de Blanca
{
    cout<<"SI MUEVE BLANCA"<<endl;

    if(corona==true)cout<<"corona: si"<<endl;
    else cout<<"corona: no"<<endl;

    if(iz==true)cout<<"direccion horizontal: izquierda"<<endl;
    else cout<<"direccion: derecha"<<endl;

    if(ab==true)cout<<"direccion vertical: abajo"<<endl;
    else cout<<"direccion vertical: arriba"<<endl;

    cout<<"posiciones:"<<N<<endl;
    if(corona==false)
    {
        if(iz==true && ab==false)//puede desplazar Blanca hacia la izquierda
        {
           if(tablero[i-N][j-N]=='+' && tab[i-N][j-N]==true)return 1;
           cout<<"puede mover por izquierda"<<endl;
        }
        else if(iz==false && ab==false)//puede desplazar Blanca hacia la derecha
        {
            if(tablero[i-N][j+N]=='+'&& tab[i-N][j+N]==true)return 2;
            cout<<"puede mover por derecha"<<endl;
        }
    }
    else
    {
        if(iz==true && ab==false)//puede desplazar Blanca hacia la izquierda abajo
        {
           if(tablero[i-N][j-N]=='+' && tab[i-N][j-N]==true)return 3;
        }

        else if(iz==false && ab==false)//puede desplazar Blanca hacia la derecha abajo
        {
            if(tablero[i-N][j+N]=='+'&& tab[i-N][j+N]==true)return 4;
        }

        else if(iz==true && ab==true)//puede desplazar Blanca hacia la izquierda arriba
        {
           if(tablero[i+N][j-N]=='+' && tab[i+N][j-N]==true)return 5;
        }

        else if(iz==false && ab==true)//puede desplazar Blanca hacia la derecha arriba
        {
            if(tablero[i+N][j+N]=='+'&& tab[i+N][j+N]==true)return 6;
        }
    }
}

int siComeB(int i, int j,bool iz, int N,bool corona,bool ab)//determina la dirección de captura de Blanca
{
    cout<<"SI COME BLANCA"<<endl;

    if(corona==true)cout<<"corona: si"<<endl;
    else cout<<"corona: no"<<endl;

    if(iz==true)cout<<"direccion horizontal: izquierda"<<endl;
    else cout<<"direccion: derecha"<<endl;

    if(ab==true)cout<<"direccion vertical: abajo"<<endl;
    else cout<<"direccion vertical: arriba"<<endl;

    cout<<"posiciones:"<<N<<endl;
    if(corona==false)
    {
        if(iz==true)//puede capturar Blanca hacia la izquierda
        {
           if((tablero[i-N][j-N]=='n'||tablero[i-N][j-N]=='N') && tab[i-N][j-N]==true)
           {
               if(tablero[i-(N+1)][j-(N+1)]=='+' && tab[i-(N+1)][j-(N+1)]==true)return 1;
               cout<<"puede comer por izquierda"<<endl;
           }
        }
        else if(iz==false)//puede capturar Blanca hacia la derecha
        {
            if((tablero[i-N][j+N]=='n'||tablero[i-N][j+N]=='N')&& tab[i-N][j+N]==true)
            {
                if(tablero[i-(N+1)][j+(N+1)]=='+'&& tab[i-(N+1)][j+(N+1)]==true)return 2;
                cout<<"puede comer por derecha"<<endl;
            }
        }
    }
    else
    {
        if(iz==true && ab==false)//puede capturar Blanca hacia la izquierda
        {
           if((tablero[i-N][j-N]=='n'||tablero[i-N][j-N]=='N') && tab[i-N][j-N]==true)
           {
               if(tablero[i-(N+1)][j-(N+1)]=='+' && tab[i-(N+1)][j-(N+1)]==true)return 3;
               cout<<"puede comer por izquierda"<<endl;
           }
        }
        else if(iz==false && ab==false)//puede capturar Blanca hacia la derecha
        {
            if((tablero[i-N][j+N]=='n'||tablero[i-N][j+N]=='N')&& tab[i-N][j+N]==true)
            {
                if(tablero[i-(N+1)][j+(N+1)]=='+'&& tab[i-(N+1)][j+(N+1)]==true)return 4;
                cout<<"puede comer por derecha"<<endl;
            }
        }
        else if(iz==true && ab==true)//puede capturar Negra hacia la izquierda
        {
           if((tablero[i+N][j-N]=='n'||tablero[i+N][j-N]=='N') && tab[i+N][j-N]==true)
           {
               if(tablero[i+(N+1)][j-(N+1)]=='+' && tab[i+(N+1)][j-(N+1)]==true)return 5;
           }
        }
        else if(iz==false && ab==true)//puede capturar Negra hacia la derecha
        {
            if((tablero[i+N][j+N]=='n'||tablero[i+N][j+N]=='N')&& tab[i+N][j+N]==true)
            {
                 if(tablero[i+(N+1)][j+(N+1)]=='+'&& tab[i+(N+1)][j+(N+1)]==true)return 6;
            }
        }
    }
}

void moverNegra(int i, int j,bool iz, int N,bool corona,bool ab)//Accion de movimiento Negra
{
    char aux;
    cout<<endl;
    cout<<endl;
    if(corona==false)
    {
        if(siMueveN(i,j,iz,N,corona,ab)==1)//si puede mover Negra hacia la izquierda
        {
            //moviemiento por izquierda
            if((tablero[i][j]=='n') && tablero[i+N][j-N]=='+')
            {
                 aux=tablero[i][j];
                 tablero[i][j]='+';
                 tablero[i+N][j-N]=aux;
            }
            else
            {
                cout<<"No se puede cambiar tal ficha"<<endl;
            }
        }
        else if(siMueveN(i,j,iz,N,corona,ab)==2)//si puede mover Negra hacia la derecha
        {
            //moviemiento por derecha
            if((tablero[i][j]=='n') && tablero[i+N][j+N]=='+')
            {
                aux=tablero[i][j];
                tablero[i][j]='+';
                tablero[i+N][j+N]=aux;
            }
            else
            {
                cout<<"No se puede cambiar tal ficha"<<endl;
            }
        }
    }
    else
    {
        if(siMueveN(i,j,iz,N,corona,ab)==3)//si puede mover Negra hacia la izquierda
        {
            //moviemiento por izquierda
            if((tablero[i][j]=='N') && tablero[i+N][j-N]=='+')
            {
                 aux=tablero[i][j];
                 tablero[i][j]='+';
                 tablero[i+N][j-N]=aux;
            }
            else
            {
                cout<<"No se puede cambiar tal ficha"<<endl;
            }
        }
        else if(siMueveN(i,j,iz,N,corona,ab)==4)//si puede mover Negra hacia la derecha
        {
            //moviemiento por derecha
            if((tablero[i][j]=='N') && tablero[i+N][j+N]=='+')
            {
                aux=tablero[i][j];
                tablero[i][j]='+';
                tablero[i+N][j+N]=aux;
            }
            else
            {
                cout<<"No se puede cambiar tal ficha"<<endl;
            }
        }
        else if(siMueveN(i,j,iz,N,corona,ab)==5)//si puede mover Blanca hacia la izquierda
        {
            //moviemiento por izquierda
            if((tablero[i][j]=='N')  && tablero[i-N][j-N]=='+')
            {
                aux=tablero[i][j];
                tablero[i][j]='+';
                tablero[i-N][j-N]=aux;
            }
            else
            {
                cout<<"No se puede cambiar tal ficha"<<endl;
            }
        }
        else if(siMueveN(i,j,iz,N,corona,ab)==6)//si puede mover Blanca hacia la derecha
        {
            //moviemiento por derecha
             if((tablero[i][j]=='N') && tablero[i-N][j+N]=='+')
             {
                 aux=tablero[i][j];
                 tablero[i][j]='+';
                 tablero[i-N][j+N]=aux;
             }
             else
             {
                 cout<<"No se puede cambiar tal ficha"<<endl;
             }
        }
    }
}
void comerNegra(int i, int j,bool iz, int N,bool corona,bool ab)//Accion de captura Negra
{
    char aux;
    cout<<endl;
    cout<<endl;
    if(corona==false)
    {
        if(siComeN(i,j,iz,N,corona,ab)==1)//si puede capturar Negra hacia la izquierda
        {
            //captura por izquierda
            if((tablero[i][j]=='n') && (tablero[i+N][j-N]=='b'||tablero[i+N][j-N]=='B') && tablero[i+(N+1)][j-(N+1)]=='+')
            {
                 aux=tablero[i][j];
                 tablero[i][j]='+';
                 tablero[i+N][j-N]='+';
                 tablero[i+(N+1)][j-(N+1)]=aux;
                 CN++;
            }
            else
            {
                cout<<"No se puede comer tal ficha"<<endl;
            }
        }
        else if(siComeN(i,j,iz,N,corona,ab)==2)//si puede capturar Negra hacia la derecha
        {
            //captura por derecha
            if((tablero[i][j]=='n') && (tablero[i+1][j+1]=='b'||tablero[i+1][j+1]=='B') && tablero[i+2][j+2]=='+')
            {
                aux=tablero[i][j];
                tablero[i][j]='+';
                tablero[i+N][i+N]='+';
                tablero[i+(N+1)][i+(N+1)]=aux;
                CN++;
            }
            else
            {
                cout<<"No se puede comer tal ficha"<<endl;
            }
        }
    }
    else
    {
        if(siComeN(i,j,iz,N,corona,ab)==3)//si puede capturar Negra hacia la izquierda
        {
            if((tablero[i][j]=='N') && (tablero[i+N][j-N]=='b'||tablero[i+N][j-N]=='B') && tablero[i+(N+1)][j-(N+1)]=='+')
            {
                 aux=tablero[i][j];
                 tablero[i][j]='+';
                 tablero[i+N][j-N]='+';
                 tablero[i+(N+1)][j-(N+1)]=aux;
                 CN++;
            }
            else
            {
                cout<<"No se puede comer tal ficha"<<endl;
            }
        }
        else if(siComeN(i,j,iz,N,corona,ab)==4)//si puede capturar Negra hacia la derecha
        {
            //captura por derecha
            if((tablero[i][j]=='N') && (tablero[i+1][j+1]=='b'||tablero[i+1][j+1]=='B') && tablero[i+2][j+2]=='+')
            {
                aux=tablero[i][j];
                tablero[i][j]='+';
                tablero[i+N][i+N]='+';
                tablero[i+(N+1)][i+(N+1)]=aux;
                CN++;
            }
            else
            {
                cout<<"No se puede comer tal ficha"<<endl;
            }
        }
        else if(siComeN(i,j,iz,N,corona,ab)==5)//si puede capturar Blanca hacia la izquierda
        {
            //moviemiento por izquierda
            if((tablero[i][j]=='N')  && (tablero[i-N][j-N]=='b'||tablero[i-N][j-N]=='B')&& tablero[i-(N+1)][j-(N+1)]=='+')
            {
                aux=tablero[i][j];
                tablero[i][j]='+';
                tablero[i-N][j-N]='+';
                tablero[i-(N+1)][j-(N+1)]=aux;
                CB++;
            }
            else
            {
                cout<<"No se puede cambiar tal ficha"<<endl;
            }
        }
        else if(siComeN(i,j,iz,N,corona,ab)==6)//si puede capturar Blanca hacia la derecha
        {
            //moviemiento por derecha
             if((tablero[i][j]=='N') && (tablero[i-N][j+N]=='b'||tablero[i-N][j+N]=='B')&& tablero[i-(N+1)][j+(N+1)]=='+')
             {
                 aux=tablero[i][j];
                 tablero[i][j]='+';
                 tablero[i-N][j+N]='+';
                 tablero[i-(N+1)][j+(N+1)]=aux;
                 CB++;
             }
             else
             {
                 cout<<"No se puede cambiar tal ficha"<<endl;
             }
        }
    }
}

void moverBlanca(int i, int j,bool iz,int N,bool corona,bool ab)//Accion de movimiento Blanca
{
    char aux;
    cout<<endl;
    cout<<endl;
    if(corona==false)
    {
        if(siMueveB(i,j,iz,N,corona,ab)==1)//si puede mover Blanca hacia la izquierda
        {
            //moviemiento por izquierda
            if(tablero[i][j]=='b' && tablero[i-N][j-N]=='+')
            {
                aux=tablero[i][j];
                tablero[i][j]='+';
                tablero[i-N][j-N]=aux;
            }
            else
            {
                cout<<"No se puede cambiar tal ficha"<<endl;
            }
        }
        else if(siMueveB(i,j,iz,N,corona,ab)==2)//si puede mover Blanca hacia la derecha
        {
            //moviemiento por derecha
             if(tablero[i][j]=='b'&& tablero[i-N][j+N]=='+')
             {
                 aux=tablero[i][j];
                 tablero[i][j]='+';
                 tablero[i-N][j+N]=aux;
             }
             else
             {
                 cout<<"No se puede cambiar tal ficha"<<endl;
             }
        }
    }
    else
    {
        if(siMueveB(i,j,iz,N,corona,ab)==3)//si puede mover Blanca hacia la izquierda
        {
            //moviemiento por izquierda
            if(tablero[i][j]=='B' && tablero[i-N][j-N]=='+')
            {
                aux=tablero[i][j];
                tablero[i][j]='+';
                tablero[i-N][j-N]=aux;
            }
            else
            {
                cout<<"No se puede cambiar tal ficha"<<endl;
            }
        }
        else if(siMueveB(i,j,iz,N,corona,ab)==4)//si puede mover Blanca hacia la derecha
        {
            //moviemiento por derecha
             if(tablero[i][j]=='B'&& tablero[i-N][j+N]=='+')
             {
                 aux=tablero[i][j];
                 tablero[i][j]='+';
                 tablero[i-N][j+N]=aux;
             }
             else
             {
                 cout<<"No se puede cambiar tal ficha"<<endl;
             }
        }
        else if(siMueveB(i,j,iz,N,corona,ab)==5)//si puede mover Negra hacia la izquierda
        {
            //moviemiento por izquierda
            if((tablero[i][j]=='B') && tablero[i+N][j-N]=='+')
            {
                 aux=tablero[i][j];
                 tablero[i][j]='+';
                 tablero[i+N][j-N]=aux;
            }
            else
            {
                cout<<"No se puede cambiar tal ficha"<<endl;
            }
        }
        else if(siMueveB(i,j,iz,N,corona,ab)==6)//si puede mover Negra hacia la derecha
        {
            //moviemiento por derecha
            if((tablero[i][j]=='B') && tablero[i+N][j+N]=='+')
            {
                aux=tablero[i][j];
                tablero[i][j]='+';
                tablero[i+N][j+N]=aux;
            }
            else
            {
                cout<<"No se puede cambiar tal ficha"<<endl;
            }
        }
    }
}

void comerBlanca(int i, int j,bool iz,int N,bool corona,bool ab)//Accion de captura Blanca
{
    char aux;
    cout<<endl;
    cout<<endl;
    if(corona ==false)
    {
        if(siComeB(i,j,iz,N,corona,ab)==1)//si puede capturar Blanca hacia la izquierda
        {
            //moviemiento por izquierda
            if(tablero[i][j]=='b' && (tablero[i-N][j-N]=='n'||tablero[i-N][j-N]=='N')&& tablero[i-(N+1)][j-(N+1)]=='+')
            {
                aux=tablero[i][j];
                tablero[i][j]='+';
                tablero[i-N][j-N]='+';
                tablero[i-(N+1)][j-(N+1)]=aux;
                CB++;
            }
            else
            {
                cout<<"No se puede cambiar tal ficha"<<endl;
            }
        }
        else if(siComeB(i,j,iz,N,corona,ab)==2)//si puede capturar Blanca hacia la derecha
        {
            //moviemiento por derecha
             if(tablero[i][j]=='b'&& (tablero[i-N][j+N]=='n'||tablero[i-N][j+N]=='N')&& tablero[i-(N+1)][j+(N+1)]=='+')
             {
                 aux=tablero[i][j];
                 tablero[i][j]='+';
                 tablero[i-N][j+N]='+';
                 tablero[i-(N+1)][j+(N+1)]=aux;
                 CB++;
             }
             else
             {
                 cout<<"No se puede cambiar tal ficha"<<endl;
             }
        }
    }
    else
    {
        if(siComeB(i,j,iz,N,corona,ab)==3)//si puede capturar Blanca hacia la izquierda
        {
            //moviemiento por izquierda
            if(tablero[i][j]=='B' && (tablero[i-N][j-N]=='n'||tablero[i-N][j-N]=='N')&& tablero[i-(N+1)][j-(N+1)]=='+')
            {
                aux=tablero[i][j];
                tablero[i][j]='+';
                tablero[i-N][j-N]='+';
                tablero[i-(N+1)][j-(N+1)]=aux;
                CB++;
            }
            else
            {
                cout<<"No se puede cambiar tal ficha"<<endl;
            }
        }
        else if(siComeB(i,j,iz,N,corona,ab)==4)//si puede capturar Blanca hacia la derecha
        {
            //moviemiento por derecha
             if(tablero[i][j]=='B'&& tablero[i-N][j+N]=='n'&& tablero[i-(N+1)][j+(N+1)]=='+')
             {
                 aux=tablero[i][j];
                 tablero[i][j]='+';
                 tablero[i-N][j+N]='+';
                 tablero[i-(N+1)][j+(N+1)]=aux;
                 CB++;
             }
             else
             {
                 cout<<"No se puede cambiar tal ficha"<<endl;
             }
        }
        else if(siComeB(i,j,iz,N,corona,ab)==5)//si puede capturar Negra hacia la izquierda
        {
            //captura por izquierda
            if(tablero[i][j]=='B' && (tablero[i+N][j-N]=='n'||tablero[i+N][j-N]=='N') && tablero[i+(N+1)][j-(N+1)]=='+')
            {
                aux=tablero[i][j];
                for(int z=0;z<N;z++)
                {
                 tablero[i][j]='+';
                 tablero[i+z][j-z]='+';
                 tablero[i+(N+1)][j-(N+1)]=aux;
                 CB++;
                }
            }
            else
            {
                cout<<"No se puede comer tal ficha"<<endl;
            }
        }
        else if(siComeB(i,j,iz,N,corona,ab)==6)//si puede capturar Negra hacia la derecha
        {
            //captura por derecha
            if(tablero[i][j]=='B' && (tablero[i+N][j+N]=='n'||tablero[i+N][j+N]=='N') && tablero[i+(N+1)][j+(N+1)]=='+')
            {
                aux=tablero[i][j];
                //for(int z=0;z<N;z++)
                {
                    tablero[i][j]='+';
                    tablero[i+N][j+N]='+';
                }
                tablero[i+(N+1)][i+(N+1)]=aux;
                CB++;
            }
            else
            {
                cout<<endl<<"No se puede comer tal ficha"<<endl;
            }
        }
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
        int i; //direccion de filas por numeros
        char jota;//direccion de columnas por letras
        char direccion; //'i' o 'd'
        char diraux; //'a' o 'b'
        bool dir;//si 'i' retorna true y 'd' retorna false
        bool daux;//si 'a' retorna true y 'b' retorna false
        crearlimite();//determina el limite del tablero
        llenar();//llena las fichas y cuadros de desplazamiento
        tablero[1][1]='b';
        tablero[0][0]='+';
        tablero[8][8]='n';
        tablero[9][9]='+';
    	imprimir();//imprime el tablero
        while(true){//ciclo infinito, falta darle condicion de termino
            cout<<"El valor de N es "<<N<<endl;
        cout<<"ingrese posicion que desea mover y direccion de Blancos"<<endl;

    	cin>>jota>>i>>direccion;
    	dir=direc(direccion);//determina direccion con booleano

        if(esCoronaB(i-1,cambioL(jota)-1)==true)
        {
            cout<<"ingrese direccion y cantidad de posiciones a mover"<<endl;
            cin>>diraux>>N;
            daux=diaux(diraux);
        }
        else
        {
            N=1;
        }
        cout<<"el valor de puedeComerB es "<<puedeComerB(i-1,cambioL(jota)-1,N,esCoronaB(i-1,cambioL(jota)-1))<<endl;
        if(puedeComerB(i-1,cambioL(jota)-1,N,esCoronaB(i-1,cambioL(jota)-1)))//prioridad de capturar por sobre desplazar
        {
            cout<<"el valor de siComeB es "<<siComeB(i-1,cambioL(jota)-1,dir,N,esCoronaB(i-1,cambioL(jota)-1),daux)<<endl;
            if(siComeB(i-1,cambioL(jota)-1,dir,N,esCoronaB(i-1,cambioL(jota)-1),daux))//comprobar si puede capturar por izquierda
            {
               //cout<<"el valor de comerBlanca es "<<comerBlanca(i-1,cambioL(jota)-1,dir,N,esCoronaB(i-1,cambioL(jota)-1),daux)<<endl;
               comerBlanca(i-1,cambioL(jota)-1,dir,N,esCoronaB(i-1,cambioL(jota)-1),daux);//captura por izquierda
               imprimir();
            }
            else//determina captura por derecha
            {
               comerBlanca(i-1,cambioL(jota)-1,dir,N,esCoronaB(i-1,cambioL(jota)-1),daux);//captura por derecha
               imprimir();
            }
        }
        else//si no puede capturar, entonces debe moverse
        {
            cout<<"el valor de puedeMoverB es "<<puedeMoverB(i-1,cambioL(jota)-1,N,esCoronaB(i-1,cambioL(jota)-1))<<endl;
            if(puedeMoverB(i-1,cambioL(jota)-1,N,esCoronaB(i-1,cambioL(jota)-1)))//comprueba si puede mover
            {
                cout<<"el valor de siMueveB es "<<siMueveB(i-1,cambioL(jota)-1,dir,N,esCoronaB(i-1,cambioL(jota)-1),daux)<<endl;
                if(siMueveB(i-1,cambioL(jota)-1,dir,N,esCoronaB(i-1,cambioL(jota)-1),daux))//comprobar si puede mover por izquierda
                {
                   moverBlanca(i-1,cambioL(jota)-1,dir,N,esCoronaB(i-1,cambioL(jota)-1),daux);//mueve por izquierda
                   i=i-1;
                   int k=cambioL(jota)-1;
                   cout<<"el valor de puedeCoronarB es "<<puedeCoronarB(i-1,k-1)<<endl;
                   if(puedeCoronarB(i-1,k-1)==true)
                   {
                      CoronarB(i-1,k-1);
                   }
                    imprimir();
                }
                else//determina movida por derecha
                {
                   moverBlanca(i-1,cambioL(jota)-1,dir,N,esCoronaB(i-1,cambioL(jota)-1),daux);//mueve por derecha
                   i=i-1;
                   int k=cambioL(jota)-1;
                   cout<<"el valor de puedeCoronarB es "<<puedeCoronarB(i-1,k+1)<<endl;
                   if(puedeCoronarB(i-1,k+1)==true)
                   {
                      CoronarB(i-1,k+1);
                   }
                   imprimir();
                }
            }
        }
        N=1;

        cout<<"ingrese posicion que desea mover y direccion de Negros"<<endl;
    	cin>>jota>>i>>direccion;
        dir=direc(direccion);//determina direccion con booleano
         cout<<"el valor de puedeComerN es "<<puedeComerN(i-1,cambioL(jota)-1,N,esCoronaN(i-1,cambioL(jota)-1))<<endl;
        if(puedeComerN(i-1,cambioL(jota)-1,N,puedeCoronarN(i-1,cambioL(jota)-1)))//prioridad de capturar por sobre desplazar
        {
            cout<<"el valor de siComeN es "<<siComeN(i-1,cambioL(jota)-1,dir,N,esCoronaN(i-1,cambioL(jota)-1),daux)<<endl;
            if(siComeN(i-1,cambioL(jota)-1,dir,N,puedeCoronarN(i-1,cambioL(jota)-1),daux))//comprobar si puede capturar por izquierda
            {
               comerNegra(i-1,cambioL(jota)-1,dir,N,puedeCoronarN(i-1,cambioL(jota)-1),daux);//captura por izquierda
               imprimir();
            }
            else//determina captura por derecha
            {
               comerNegra(i-1,cambioL(jota)-1,dir,N,esCoronaB(i-1,cambioL(jota)-1),daux);//captura por derecha
               imprimir();
            }
        }
        else//si no puede capturar, entonces debe moverse
        {
            cout<<"el valor de puedeMoverN es "<<puedeMoverN(i-1,cambioL(jota)-1,N,esCoronaN(i-1,cambioL(jota)-1))<<endl;
            if(puedeMoverN(i-1,cambioL(jota)-1,N,esCoronaB(i-1,cambioL(jota)-1)))//comprueba si puede mover
            {
                cout<<"el valor de siMueveN es "<<siMueveN(i-1,cambioL(jota)-1,dir,N,esCoronaN(i-1,cambioL(jota)-1),daux)<<endl;
                if(siMueveN(i-1,cambioL(jota)-1,dir,N,esCoronaB(i-1,cambioL(jota)-1),daux))//comprobar si puede mover por izquierda
                {
                   moverNegra(i-1,cambioL(jota)-1,dir,N,esCoronaN(i-1,cambioL(jota)-1),daux);//mueve por izquierda
                   i=i-1;
                   int k=cambioL(jota)-1;
                   cout<<"el valor de puedeCoronarN es "<<puedeCoronarN(i+1,k+1)<<endl;
                   if(puedeCoronarN(i+1,k+1)==true)
                   {
                      CoronarN(i+1,k+1);
                   }
                    imprimir();
                }
                else//determina movida por derecha
                {
                   moverNegra(i-1,cambioL(jota)-1,dir,N,esCoronaN(i-1,cambioL(jota)-1),daux);//mueve por izquierda
                   i=i-1;
                   int k=cambioL(jota)-1;
                    cout<<"el valor de puedeCoronarN es "<<puedeCoronarN(i+1,k-1)<<endl;
                   if(puedeCoronarN(i+1,k-1)==true)
                   {
                      CoronarN(i+1,k-1);
                   }
                    imprimir();
                }
            }
        }
        N=1;
    }

	return 0;
}
