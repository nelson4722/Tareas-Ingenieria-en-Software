#include <cstdlib>
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

bool CoronaN(int i, int j)
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
void CoronarN(int i, int j)
{
    if(CoronaN(i,j)==true)
    {
        tablero[i][j]='N';
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
bool CoronaB(int i, int j)
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
    if(CoronaB(i,j)==true)
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
       if((tablero[i+N][j-N]=='b'&&tablero[i+(N+1)][j-(N+1)]=='+')||(tablero[i+N][j+N]=='b'&&tablero[i+(N+1)][j+(N+1)]=='+'))
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
       if((tablero[i-N][j-N]=='n'&& tablero[i-(N+1)][j-(N+1)]=='+') || (tablero[i-N][j+N]=='n' && tablero[i-(N+1)][j+(N+1)]=='+'))
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
       if((tablero[i+N][j-N]=='n'&&tablero[i+(N+1)][j-(N+1)]=='+')||(tablero[i+N][j+N]=='n'&&tablero[i+(N+1)][j+(N+1)]=='+')
        ||(tablero[i-N][j-N]=='n'&&tablero[i-(N+1)][j-(N+1)]=='+')||(tablero[i-N][j+N]=='n'&&tablero[i-(N+1)][j+(N+1)]=='+')
        ||(tablero[i+N][j-N]=='N'&&tablero[i+(N+1)][j-(N+1)]=='+')||(tablero[i+N][j+N]=='N'&&tablero[i+(N+1)][j+(N+1)]=='+')
        ||(tablero[i-N][j-N]=='N'&&tablero[i-(N+1)][j-(N+1)]=='+')||(tablero[i-N][j+N]=='N'&&tablero[i-(N+1)][j+(N+1)]=='+'))
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
  if(d=='a')return true;
  else if(d=='b')return false;
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

int siMueveN(int i, int j,bool iz,int N,bool corona, bool vr)//determina direccion de movimiento de Negra
{
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
        if(iz==true)//puede desplazar Negra hacia la izquierda abajo
        {
           if(tablero[i+N][j-N]=='+' && tab[i+N][j-N]==true)return 3;
        }
        else if(iz==false)//puede desplazar Negra hacia la derecha abajo
        {
            if(tablero[i+N][j+N]=='+'&& tab[i+N][j+N]==true)return 4;
        }
        if(vr==true)//puede desplazar Negra hacia la izquierda arriba
        {
           if(tablero[i-N][j-N]=='+' && tab[i-N][j-N]==true)return 5;
        }
        else if(vr==false)//puede desplazar Negra hacia la derecha arriba
        {
            if(tablero[i-N][j+N]=='+'&& tab[i-N][j+N]==true)return 6;
        }
    }
}

int siComeN(int i, int j,bool iz, int N,bool corona,bool vr)//determina la dirección de captura de Negra
{
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
        if(vr==true)//puede capturar Blanca hacia la izquierda arriba
        {
           if((tablero[i-N][j-N]=='b'||tablero[i-N][j-N]=='B') && tab[i-N][j-N]==true)
           {
               if(tablero[i-(N+1)][j-(N+1)]=='+' && tab[i-(N+1)][j-(N+1)]==true)return 5;
               cout<<"puede comer por izquierda"<<endl;
           }    
        }
        else if(vr==false)//puede capturar Negra hacia la derecha arriba
        {
            if((tablero[i-N][j+N]=='b'||tablero[i-N][j+N]=='B')&& tab[i-N][j+N]==true)
            {
                if(tablero[i-(N+1)][j+(N+1)]=='+'&& tab[i-(N+1)][j+(N+1)]==true)return 6;
                cout<<"puede comer por derecha"<<endl;
            }      
        }
    }
}

int siMueveB(int i, int j,bool iz, int N, bool corona,bool vr)//determina direccion de movimiento de Blanca
{
    if(corona==false)
    {    
        if(iz==true)//puede desplazar Blanca hacia la izquierda
        {
           if(tablero[i-N][j-N]=='+' && tab[i-N][j-N]==true)return 1;
           cout<<"puede mover por izquierda"<<endl;
        }
        else if(iz==false)//puede desplazar Blanca hacia la derecha
        {
            if(tablero[i-N][j+N]=='+'&& tab[i-N][j+N]==true)return 2;
            cout<<"puede mover por derecha"<<endl;
        }
    }
    else
    {
        if(iz==true)//puede desplazar Blanca hacia la izquierda
        {
           if(tablero[i-N][j-N]=='+' && tab[i-N][j-N]==true)return 3;
           cout<<"puede mover por izquierda"<<endl;
        }
        else if(iz==false)//puede desplazar Blanca hacia la derecha
        {
            if(tablero[i-N][j+N]=='+'&& tab[i-N][j+N]==true)return 4;
            cout<<"puede mover por derecha"<<endl;
        }
        else if(vr==true)//puede desplazar Negra hacia la izquierda
        {
           if(tablero[i+N][j-N]=='+' && tab[i+N][j-N]==true)return 5;
        }
        else if(vr==false)//puede desplazar Negra hacia la derecha
        {
            if(tablero[i+N][j+N]=='+'&& tab[i+N][j+N]==true)return 6;
        }
    }
}

int siComeB(int i, int j,bool iz, int N,bool corona,bool vr)//determina la dirección de captura de Blanca
{
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
        if(iz==true)//puede capturar Blanca hacia la izquierda
        {
           if((tablero[i-N][j-N]=='n'||tablero[i-N][j-N]=='N') && tab[i-N][j-N]==true)
           {
               if(tablero[i-(N+1)][j-(N+1)]=='+' && tab[i-(N+1)][j-(N+1)]==true)return 3;
               cout<<"puede comer por izquierda"<<endl;
           }    
        }
        else if(iz==false)//puede capturar Blanca hacia la derecha
        {
            if((tablero[i-N][j+N]=='n'||tablero[i-N][j+N]=='N')&& tab[i-N][j+N]==true)
            {
                if(tablero[i-(N+1)][j+(N+1)]=='+'&& tab[i-(N+1)][j+(N+1)]==true)return 4;
                cout<<"puede comer por derecha"<<endl;
            }      
        }
        else if(vr==true)//puede capturar Negra hacia la izquierda
        {
           if((tablero[i+N][j-N]=='n'||tablero[i+N][j-N]=='N') && tab[i+N][j-N]==true)
           {
               if(tablero[i+(N+1)][j-(N+1)]=='+' && tab[i+(N+1)][j-(N+1)]==true)return 5;
           }
        }
        else if(vr==false)//puede capturar Negra hacia la derecha
        {
            if((tablero[i+N][j+N]=='n'||tablero[i+N][j+N]=='N')&& tab[i+N][j+N]==true)
            {
                 if(tablero[i+(N+1)][j+(N+1)]=='+'&& tab[i+(N+1)][j+(N+1)]==true)return 6;
            }
        }
    }
}

void moverNegra(int i, int j,bool iz, int N,bool corona,bool vr)//Accion de movimiento Negra
{
    char aux;
    cout<<endl;
    cout<<endl;
    if(corona==false)
    {
        if(siMueveN(i,j,iz,N,corona,vr)==1)//si puede mover Negra hacia la izquierda
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
        else if(siMueveN(i,j,iz,N,corona,vr)==2)//si puede mover Negra hacia la derecha
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
        if(siMueveN(i,j,iz,N,corona,vr)==3)//si puede mover Negra hacia la izquierda
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
        else if(siMueveN(i,j,iz,N,corona,vr)==4)//si puede mover Negra hacia la derecha
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
        else if(siMueveN(i,j,iz,N,corona,vr)==5)//si puede mover Blanca hacia la izquierda
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
        else if(siMueveN(i,j,iz,N,corona,vr)==6)//si puede mover Blanca hacia la derecha
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
void comerNegra(int i, int j,bool iz, int N,bool corona,bool vr)//Accion de captura Negra
{
    char aux;
    cout<<endl;
    cout<<endl;
    if(corona==false)
    {
        if(siComeN(i,j,iz,N,corona,vr)==1)//si puede capturar Negra hacia la izquierda
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
        else if(siComeN(i,j,iz,N,corona,vr)==2)//si puede capturar Negra hacia la derecha
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
        if(siComeN(i,j,iz,N,corona,vr)==3)//si puede capturar Negra hacia la izquierda
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
        else if(siComeN(i,j,iz,N,corona,vr)==4)//si puede capturar Negra hacia la derecha
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
        else if(siComeN(i,j,iz,N,corona,vr)==5)//si puede capturar Blanca hacia la izquierda
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
        else if(siComeN(i,j,iz,N,corona,vr)==6)//si puede capturar Blanca hacia la derecha
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

void moverBlanca(int i, int j,bool iz,int N,bool corona,bool vr)//Accion de movimiento Blanca
{
    char aux;
    cout<<endl;
    cout<<endl;
    if(corona==false)
    {
        if(siMueveB(i,j,iz,N,corona,vr)==1)//si puede mover Blanca hacia la izquierda
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
        else if(siMueveB(i,j,iz,N,corona,vr)==2)//si puede mover Blanca hacia la derecha
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
        if(siMueveB(i,j,iz,N,corona,vr)==3)//si puede mover Blanca hacia la izquierda
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
        else if(siMueveB(i,j,iz,N,corona,vr)==4)//si puede mover Blanca hacia la derecha
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
        else if(siMueveB(i,j,iz,N,corona,vr)==5)//si puede mover Negra hacia la izquierda
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
        else if(siMueveN(i,j,iz,N,corona,vr)==6)//si puede mover Negra hacia la derecha
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

void comerBlanca(int i, int j,bool iz,int N,bool corona,bool vr)//Accion de captura Blanca
{
    char aux;
    cout<<endl;
    cout<<endl;
    if(corona ==false)
    {
        if(siComeB(i,j,iz,N,corona,vr)==1)//si puede capturar Blanca hacia la izquierda
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
        else if(siComeB(i,j,iz,N,corona,vr)==2)//si puede capturar Blanca hacia la derecha
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
        if(siComeB(i,j,iz,N,corona,vr)==3)//si puede capturar Blanca hacia la izquierda
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
        else if(siComeB(i,j,iz,N,corona,vr)==4)//si puede capturar Blanca hacia la derecha
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
        else if(siComeB(i,j,iz,N,corona,vr)==5)//si puede capturar Negra hacia la izquierda
        {
            //captura por izquierda
            if(tablero[i][j]=='B' && (tablero[i+N][j-N]=='n'||tablero[i+N][j-N]=='N') && tablero[i+(N+1)][j-(N+1)]=='+')
            {
                 aux=tablero[i][j];
                 tablero[i][j]='+';
                 tablero[i+N][j-N]='+';
                 tablero[i+(N+1)][j-(N+1)]=aux; 
                 CB++;
            }
            else
            {
                cout<<"No se puede comer tal ficha"<<endl;
            }
        }
        else if(siComeB(i,j,iz,N,corona,vr)==6)//si puede capturar Negra hacia la derecha
        {
            //captura por derecha
            if(tablero[i][j]=='B' && (tablero[i+N][j+N]=='n'||tablero[i+N][j+N]=='N') && tablero[i+(N+1)][j+(N+1)]=='+')
            {
                aux=tablero[i][j];
                tablero[i][j]='+';
                tablero[i+N][i+N]='+';
                tablero[i+(N+1)][i+(N+1)]=aux;
                CB++;
            }
            else
            {
                cout<<"No se puede comer tal ficha"<<endl;
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
    system("clear");
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
        bool daux;//si 'b' retorna true y 'a' retorna false
        crearlimite();//determina el limite del tablero
        llenar();//llena las fichas y cuadros de desplazamiento
        tablero[1][1]='b';
        tablero[0][0]='+';
    	imprimir();//imprime el tablero
        while(true){//ciclo infinito, falta darle condicion de termino
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
        
        if(puedeComerB(i-1,cambioL(jota)-1,N,esCoronaB(i-1,cambioL(jota)-1)))//prioridad de capturar por sobre desplazar
        {
            if(siComeB(i-1,cambioL(jota)-1,dir,N,esCoronaB(i-1,cambioL(jota)-1),daux))//comprobar si puede capturar por izquierda
            {
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
            if(puedeMoverB(i-1,cambioL(jota)-1,N,esCoronaB(i-1,cambioL(jota)-1)))//comprueba si puede mover
            {
                if(siMueveB(i-1,cambioL(jota)-1,dir,N,esCoronaB(i-1,cambioL(jota)-1),daux))//comprobar si puede mover por izquierda
                {
                   moverBlanca(i-1,cambioL(jota)-1,dir,N,esCoronaB(i-1,cambioL(jota)-1),daux);//mueve por izquierda
                   i=i-1;
                   int k=cambioL(jota)-1;
                   if(CoronaB(i-1,k-1)==true)
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
                   if(CoronaB(i-1,k+1))
                   {
                      CoronarB(i-1,k+1);
                   }
                   imprimir(); 
                }   
            }     
        }
        
        cout<<"ingrese posicion que desea mover y direccion de Negros"<<endl;
    	cin>>jota>>i>>direccion;
        dir=direc(direccion);//determina direccion con booleano
        if(puedeComerN(i-1,cambioL(jota)-1,N,CoronaN(i-1,cambioL(jota)-1)))//prioridad de capturar por sobre desplazar
        {
            if(siComeN(i-1,cambioL(jota)-1,dir,N,CoronaN(i-1,cambioL(jota)-1),daux))//comprobar si puede capturar por izquierda
            {
               comerNegra(i-1,cambioL(jota)-1,dir,N,CoronaN(i-1,cambioL(jota)-1),daux);//captura por izquierda
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
            if(puedeMoverN(i-1,cambioL(jota)-1,N,esCoronaB(i-1,cambioL(jota)-1)))//comprueba si puede mover
            {
                if(siMueveN(i-1,cambioL(jota)-1,dir,N,esCoronaB(i-1,cambioL(jota)-1),daux))//comprobar si puede mover por izquierda
                {
                   moverNegra(i-1,cambioL(jota)-1,dir,N,esCoronaB(i-1,cambioL(jota)-1),daux);//mueve por izquierda
                   imprimir();
                }
                else//determina movida por derecha
                {
                   moverNegra(i-1,cambioL(jota)-1,dir,N,esCoronaB(i-1,cambioL(jota)-1),daux);//mueve por derecha
                   imprimir();
                }   
            }     
        }
    }
        
	return 0;
}
