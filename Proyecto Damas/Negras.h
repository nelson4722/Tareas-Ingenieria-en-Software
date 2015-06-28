/* 
 * File:   Negras.h
 * Author: nelson
 *
 * Created on 27 de junio de 2015, 18:45
 */

#ifndef NEGRAS_H
#define	NEGRAS_H
#include <cstdlib>
#include <sstream>
#include <ostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;
#define T 10 //tamaño maximo del tablero
int CN=0;// contador de Negras capturadas
bool puedeCoronarN(int i, int j)//determina si la pieza Negra se puede coronar
{
    if(i==9)// determina si cruzó al otro extremo la pieza Negra
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
bool esCoronaN(int i, int j)//determina si la pieza Negra es corona
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
void CoronarN(int i, int j)// cambia la pieza Negra por una corona a traves de una mayuscula
{
    if(puedeCoronarN(i,j)==true)
    {
        tablero[i][j]='N';
    }
}
bool puedeMoverN(int i, int j,int N, bool corona) //comprueba que la ficha X,Y puede lograr desplazarse
{
   if(corona==false)// si no es corona N=1
   {
       if(tablero[i+N][j-N]=='+' ||tablero[i+N][j+N]=='+')//puede mover las fichas Negras
       {
           return true;
       }
       else//no puede mover fichas Negras
       {
           return false;
       }
   }
   else
   {
       if(tablero[i+N][j-N]=='+'||tablero[i+N][j+N]=='+'|| tablero[i-N][j+N]=='+' ||tablero[i-N][j-N]=='+')//puede mover las coronas Negras
       {
           return true;
       }
       else//no puede mover coronas Negras
       {
           return false;
       }
   }
}
bool puedeComerN(int i, int j, int N, bool corona)//comprueba que la ficha X,Y puede capturar alguna ficha rival
{
    if(corona==false)
    {
       if((tablero[i+N][j-N]=='b' || tablero[i+N][j-N]=='B') &&tablero[i+(N+1)][j-(N+1)]=='+')
       {//puede comer a las fichas Blancas
           h='i';
           return true;
       }
       else
       {
           if((tablero[i+N][j+N]=='b' || tablero[i+N][j+N]=='B')&&tablero[i+(N+1)][j+(N+1)]=='+')
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
            if(((tablero[i+m][j-m]=='b' || tablero[i+m][j-m]=='B')&&tablero[i+(m+1)][j-(m+1)]=='+'))
            {
                Notro=m;
                h='i'; v='b';
                si= true;
                return true;
             }
            else
            {
                if(((tablero[i-m][j-m]=='b'||tablero[i-m][j-m]=='B')&&tablero[i-(m+1)][j-(m+1)]=='+'))
                {
                    h='i'; v='a';
                    Notro=m;
                    si= true;
                    return true;
                }
                else 
                {
                   if(((tablero[i+m][j+m]=='b'||tablero[i+m][j+m]=='B')&&tablero[i+(m+1)][j+(m+1)]=='+'))
                   {
                       h='d'; v='b';
                       Notro=m;
                       si= true;
                       return true;
                   }
                   else
                   {
                       if(((tablero[i-m][j+m]=='b'||tablero[i-m][j+m]=='B')&&tablero[i-(m+1)][j+(m+1)]=='+'))
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
           if(tablero[i+N][j-N]=='+' && tab[i+N][j-N]==true) return 1;
        }
        else if(iz==false)//puede desplazar Negra hacia la derecha
        {
            if(tablero[i+N][j+N]=='+'&& tab[i+N][j+N]==true) return 2;
        }
    }else{
        if(iz==true && ab== true)//puede desplazar Negra hacia la izquierda abajo
        {
           if(tablero[i+N][j-N]=='+' && tab[i+N][j-N]==true) return 3;
        }
        else if(iz==false && ab==true)//puede desplazar Negra hacia la derecha abajo
        {
            if(tablero[i+N][j+N]=='+'&& tab[i+N][j+N]==true) return 4;
        }
        else if(iz==true && ab==false)//puede desplazar Negra hacia la izquierda arriba
        {
           if(tablero[i-N][j-N]=='+' && tab[i-N][j-N]==true) return 5;
        }
        else if(iz== false && ab==false)//puede desplazar Negra hacia la derecha arriba
        {
            if(tablero[i-N][j+N]=='+'&& tab[i-N][j+N]==true) return 6;
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
    cout<<"i:"<<i<<endl;
    cout<<"j:"<<j<<endl;
    if(corona==false)
    {
        Notro=1;
        if(iz==true)//puede capturar Negra hacia la izquierda
        {
           if((tablero[i+Notro][j-Notro]=='b'|| tablero[i+Notro][j-Notro]=='B') && tab[i+Notro][j-Notro]==true)
           {
               if(tablero[i+(N+1)][j-(N+1)]=='+' && tab[i+(N+1)][j-(N+1)]==true)return 1;
           }
        }
        else if(iz==false)//puede capturar Negra hacia la derecha
        {
            if((tablero[i+Notro][j+Notro]=='b'|| tablero[i+Notro][j+Notro]=='B')&& tab[i+Notro][j+Notro]==true)
            {
                 if(tablero[i+(N+1)][j+(N+1)]=='+'&& tab[i+(N+1)][j+(N+1)]==true)return 2;
            }
        }
    }
    else
    {
        if(iz==true && ab== true)//puede capturar Negra hacia la izquierda abajo
        {
           if((tablero[i+Notro][j-Notro]=='b'|| tablero[i+Notro][j-Notro]=='B') && tab[i+Notro][j-Notro]==true)
           {
               if(tablero[i+(N+1)][j-(N+1)]=='+' && tab[i+(N+1)][j-(N+1)]==true)return 3;
           }
        }
        else if(iz==false && ab== true)//puede capturar Negra hacia la derecha abajo
        {
            if((tablero[i+Notro][j+Notro]=='b' ||tablero[i+Notro][j+Notro]=='B')&& tab[i+Notro][j+Notro]==true)
            {
                 if(tablero[i+(N+1)][j+(N+1)]=='+'&& tab[i+(N+1)][j+(N+1)]==true)return 4;
            }
        }
        else if(iz==true && ab==false)//puede capturar Blanca hacia la izquierda arriba
        {
           if((tablero[i-Notro][j-Notro]=='b'||tablero[i-Notro][j-Notro]=='B') && tab[i-Notro][j-Notro]==true)
           {
               if(tablero[i-(N+1)][j-(N+1)]=='+' && tab[i-(N+1)][j-(N+1)]==true)return 5;
               cout<<"puede comer por izquierda"<<endl;
           }
        }
        else if(iz==false && ab==false)//puede capturar Negra hacia la derecha arriba
        {
            if((tablero[i-Notro][j+Notro]=='b'||tablero[i-Notro][j+Notro]=='B')&& tab[i-Notro][j+Notro]==true)
            {
                if(tablero[i-(N+1)][j+(N+1)]=='+'&& tab[i-(N+1)][j+(N+1)]==true)return 6;
                cout<<"puede comer por derecha"<<endl;
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
                 iaux=i+(N+1);
                 jaux=j-(N+1);
                 cout<<"el valor de i es:"<<iaux<<endl;
                 cout<<"el valor de j es:"<<jaux<<endl;
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
            if((tablero[i][j]=='n') && (tablero[i+N][j+N]=='b'||tablero[i+N][j+N]=='B') && tablero[i+(N+1)][j+(N+1)]=='+')
            {
                aux=tablero[i][j];
                tablero[i][j]='+';
                tablero[i+N][j+N]='+';
                tablero[i+(N+1)][j+(N+1)]=aux;
                iaux=i+(N+1);
                jaux=j+(N+1);
                cout<<"el valor de i es:"<<iaux<<endl;
                cout<<"el valor de j es:"<<jaux<<endl;
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
                tablero[i+N][j+N]='+';
                tablero[i+(N+1)][j+(N+1)]=aux;
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
#endif	/* NEGRAS_H */

