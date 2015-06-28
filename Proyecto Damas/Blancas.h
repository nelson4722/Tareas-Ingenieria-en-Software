#ifndef BLANCAS_H
#define	BLANCAS_H
#include <cstdlib>
#include <sstream>
#include <ostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;
#define T 10 //tamaño maximo del tablero
char tablero[10][10];//tablero de piezas
bool tab[10][10];//tablero de limites
char h,v;
int iaux=0;
int jaux=0;
int Notro=0;
int CB=0;// contador de Blancas capturadas
bool puedeCoronarB(int i, int j)//determina si la pieza Blanca se puede coronar
{
    if(i==0)// determina si cruzó al otro extremo la pieza Blanca
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
bool esCoronaB(int i, int j)//determina si la pieza Blanca es corona
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
void CoronarB(int i, int j)// cambia la pieza Blanca por una corona a traves de una mayuscula
{
    if(puedeCoronarB(i,j)==true)
    {
        tablero[i][j]='B';
    }
}
bool puedeMoverB(int i, int j,int N, bool corona) //comprueba que la ficha X,Y puede lograr desplazarse
{
   if(corona==false)//si no es corona, N=1
   {
       if(tablero[i-N][j-N]=='+'||tablero[i-N][j+N]=='+')//puede mover las fichas Blancas
       {
           return true;
       }
       else //no puede mover fichas Blancas
       {
           return false;
       }
   }
   else
   {
       if(tablero[i-N][j-N]=='+'||tablero[i-N][j+N]=='+'|| tablero[i+N][j-N]=='+'||tablero[i+N][j+N]=='+')//puede mover las coronas Blancas
       {
           return true;
       }
       else //no puede mover coronas Blancas
       {
           return false;
       }
   }
}
bool puedeComerB(int i, int j, int N, bool corona)//comprueba que la ficha X,Y puede capturar alguna ficha rival
{
    if(corona==false)
    {
       if(((tablero[i-N][j-N]=='n'|| tablero[i-N][j-N]=='N')&& tablero[i-(N+1)][j-(N+1)]=='+'))
       {//puede comer a las fichas Negras
           h='i';
           return true;
       }
       else
       {
           if((tablero[i-N][j+N]=='n'|| tablero[i-N][j+N]=='N') && tablero[i-(N+1)][j+(N+1)]=='+')
           {
               h='d';
               return true;
           }
           else
           {
               return false;
           }         
       }
    }
    else
    {
        bool si=false;
        for (int m=0;m<N;m++)
        {
            if(((tablero[i+m][j-m]=='n' || tablero[i+m][j-m]=='N')&&tablero[i+(m+1)][j-(m+1)]=='+'))
            {
                Notro=m;
                h='i'; v='b';
                si= true;
                return true;
             }
            else
            {
                if(((tablero[i-m][j-m]=='n'||tablero[i-m][j-m]=='N')&&tablero[i-(m+1)][j-(m+1)]=='+'))
                {
                    h='i'; v='a';
                    Notro=m;
                    si= true;
                    return true;
                }
                else 
                {
                   if(((tablero[i+m][j+m]=='n'||tablero[i+m][j+m]=='N')&&tablero[i+(m+1)][j+(m+1)]=='+'))
                   {
                       h='d'; v='b';
                       Notro=m;
                       si= true;
                       return true;
                   }
                   else
                   {
                       if(((tablero[i-m][j+m]=='n'||tablero[i-m][j+m]=='N')&&tablero[i-(m+1)][j+(m+1)]=='+'))
                       {
                           h='d'; v='a';
                           Notro=m;
                           si= true;
                           return true;
                       }  
                        else
                        {
                             si= false;
                         }
                   }
                }
            }            
        }
        return si;
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
           if(tablero[i-N][j-N]=='+' && tab[i-N][j-N]==true) return 3;
        }

        else if(iz==false && ab==false)//puede desplazar Blanca hacia la derecha abajo
        {
            if(tablero[i-N][j+N]=='+'&& tab[i-N][j+N]==true)  return 4;
        }

        else if(iz==true && ab==true)//puede desplazar Blanca hacia la izquierda arriba
        {
           if(tablero[i+N][j-N]=='+' && tab[i+N][j-N]==true) return 5;
        }

        else if(iz==false && ab==true)//puede desplazar Blanca hacia la derecha arriba
        {
            if(tablero[i+N][j+N]=='+'&& tab[i+N][j+N]==true)  return 6;
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
    cout<<"i:"<<i<<endl;
    cout<<"j:"<<j<<endl;
    if(corona==false)
    {
        Notro=1;
        if(iz==true)//puede capturar Blanca hacia la izquierda
        {
           if((tablero[i-Notro][j-Notro]=='n'||tablero[i-Notro][j-Notro]=='N') && tab[i-Notro][j-Notro]==true)
           {
               if(tablero[i-(N+1)][j-(N+1)]=='+' && tab[i-(N+1)][j-(N+1)]==true)return 1;
               cout<<"puede comer por izquierda"<<endl;
           }
        }
        else if(iz==false)//puede capturar Blanca hacia la derecha
        {
            if((tablero[i-Notro][j+Notro]=='n'||tablero[i-Notro][j+Notro]=='N')&& tab[i-Notro][j+Notro]==true)
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
           if((tablero[i-Notro][j-Notro]=='n'||tablero[i-Notro][j-Notro]=='N') && tab[i-Notro][j-Notro]==true)
           {
               if(tablero[i-(N+1)][j-(N+1)]=='+' && tab[i-(N+1)][j-(N+1)]==true) return 3;
               cout<<"puede comer por izquierda"<<endl;
           }
        }
        else if(iz==false && ab==false)//puede capturar Blanca hacia la derecha
        {
            if((tablero[i-Notro][j+Notro]=='n'||tablero[i-Notro][j+Notro]=='N')&& tab[i-Notro][j+Notro]==true)
            {
                if(tablero[i-(N+1)][j+(N+1)]=='+'&& tab[i-(N+1)][j+(N+1)]==true) return 4;
                cout<<"puede comer por derecha"<<endl;
            }
        }
        else if(iz==true && ab==true)//puede capturar Negra hacia la izquierda
        {
           if((tablero[i+Notro][j-Notro]=='n'||tablero[i+Notro][j-N]=='N') && tab[i+N][j-N]==true)
           {
               if(tablero[i+(N+1)][j-(N+1)]=='+' && tab[i+(N+1)][j-(N+1)]==true) return 5;
           }
        }
        else if(iz==false && ab==true)//puede capturar Negra hacia la derecha
        {
            if((tablero[i+Notro][j+Notro]=='n'||tablero[i+Notro][j+Notro]=='N')&& tab[i+Notro][j+Notro]==true)
            {
                 if(tablero[i+(N+1)][j+(N+1)]=='+'&& tab[i+(N+1)][j+(N+1)]==true)  return 6;
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
                iaux=i-(N+1);
                jaux=j-(N+1);
                cout<<"el valor de i es:"<<iaux<<endl;
                cout<<"el valor de j es:"<<jaux<<endl;
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
                 iaux=i-(N+1);
                 jaux=j+(N+1);
                 cout<<"el valor de i es:"<<iaux<<endl;
                 cout<<"el valor de j es:"<<jaux<<endl;
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
        else 
            if(siComeB(i,j,iz,N,corona,ab)==6)//si puede capturar Negra hacia la derecha
        {
            //captura por derecha
            aux=tablero[i][j];
           for(int w=1;w<N;w++)
           {
	      if(tablero[i][j]=='B' && (tablero[i+w][j+w]=='n'||tablero[i+w][j+w]=='N') && tablero[i+(w+1)][j+(w+1)]=='+')
              { 
                //for(int z=0;z<N;z++) 
                    tablero[i+w][j+w]='+'; 
              } 
           }
            tablero[i+(N)][j+(N)]=aux;
	    tablero[i][j]='+';		 
            CB++;
            }
            else
            {
                cout<<endl<<"No se puede comer tal ficha"<<endl;
            }
        }
    }

#endif	/* BLANCAS_H */
