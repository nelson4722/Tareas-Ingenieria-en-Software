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
int Notr=0;
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
int puedeComerN(int i, int j, int N, bool corona)//comprueba que la ficha X,Y puede capturar alguna ficha rival
{
     if(corona==false)
    { cout<<endl<<"corona "<<corona<<endl<<tablero[i-(2)][j-(2)]<<endl<<tablero[i-(1)][j-(1)]<<endl;
       if(((tablero[i+1][j+1]=='b'|| tablero[i+1][j+1]=='B')&& tablero[i+(2)][j+(2)]=='+'))
       {//puede comer a las fichas Blancas
           h='i';
           return 2;
       }
       else
       {
           if((tablero[i+1][j-1]=='b'|| tablero[i+1][j-1]=='B') && tablero[i+(2)][j-(2)]=='+')
           {
               h='d';
               return 4;
           }
                   
       }
    }
    else
    {
		for(int m=1;m<7;m++){ 
            if(((tablero[i+m][j-m]=='b' || tablero[i+m][j-m]=='B')&&tablero[i+(m+1)][j-(m+1)]=='+')&&
               (tablero[i+(m-1)][j-(m-1)]=='+'))
            {
                Notr=m+1;
                h='i'; v='b';
                return 1;
             }
            else
            {
                if(((tablero[i-m][j-m]=='b'||tablero[i-m][j-m]=='B')&&tablero[i-(m+1)][j-(m+1)]=='+')&&
                   (tablero[i-(m-1)][j-(m-1)]=='+'))
                {
					Notr=m+1;
                    h='i'; v='a';
                    return 2;
                }
                else 
                {
                   if(((tablero[i+m][j+m]=='b'||tablero[i+m][j+m]=='B')&&tablero[i+(m+1)][j+(m+1)]=='+')&&
                       (tablero[i+(m-1)][j+(m-1)]=='+'))
                   {
					   Notr=m+1;
                       h='d'; v='b';
                       return 3;
                   }
                   else
                   {
                       if(((tablero[i-m][j+m]=='b'||tablero[i-m][j+m]=='B')&&tablero[i-(m+1)][j+(m+1)]=='+')&&
                       (tablero[i-(m-1)][j+(m-1)]=='+'))
                       {
						   Notr=m+1;
                           h='d'; v='a';
                           return 4;
                       }  
                   }
                }
            }
		}            
        
    }
    return 0;
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
           if(tablero[i+N][j-N]=='+' && tab[i+N][j-N]==true) return 2;
           return 7;
        }
        else if(iz==false)//puede desplazar Negra hacia la derecha
        {
            if(tablero[i+N][j+N]=='+'&& tab[i+N][j+N]==true) return 1;
            return 7;
        }
    } else
    {
        if(iz==true && ab==false)//puede desplazar Blanca hacia la izquierda abajo
        {
           if(tablero[i-N][j-N]=='+' && tab[i-N][j-N]==true) return 3;
           return 7;
        }

        else if(iz==false && ab==false)//puede desplazar Blanca hacia la derecha abajo
        {
            if(tablero[i-N][j+N]=='+'&& tab[i-N][j+N]==true)  return 4;
            return 7;
        }

        else if(iz==true && ab==true)//puede desplazar Blanca hacia la izquierda arriba
        {
           if(tablero[i+N][j-N]=='+' && tab[i+N][j-N]==true) return 5;
           return 7;
        }

        else if(iz==false && ab==true)//puede desplazar Blanca hacia la derecha arriba
        {
            if(tablero[i+N][j+N]=='+'&& tab[i+N][j+N]==true)  return 6;
            return 7;
        }
    }
}
int siComeN(int i, int j,bool iz, int N,bool corona,bool ab)//determina la dirección de captura de Negra
{
    cout<<"SI COME NEGRA"<<endl;
    bool aux=false;
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
        if(iz==true)//puede capturar Blanca hacia la izquierda
        {
           if((tablero[i+1][j+1]=='b'||tablero[i+1][j+1]=='B') && tablero[i+(2)][j+(2)]=='+' )
           {
			   tablero[i][j]='+';
			   tablero[i+1][j+1]='+';
			   tablero[i+2][j+2]='n';
			   i=i+2;
			   j=j+2;
			   aux=true;
			   
           }
          
        }
        else if(iz==false)//puede capturar Blanca hacia la derecha
        {
            if((tablero[i+1][j-1]=='b'||tablero[i+1][j-1]=='B')&& tablero[i+(2)][j-(2)]=='+')
            {
			   tablero[i][j]='+';
			   tablero[i+1][j-1]='+';
			   tablero[i+2][j-2]='b';	
			   i=i+2;
			   j=j-2;
			   aux=true;
            }
           
        }
    }
    else
    {
		for(int m = 1; m<N; m++){
			
        if(iz==true && ab==false)//puede capturar Blanca hacia la izquierda
        {
           if((tablero[i-m][j-m]=='b'||tablero[i-m][j-m]=='B') && tablero[i-(m+1)][j-(m+1)]=='+')
           {
			   cout<<endl<<"hola que tal soy sebastian--------------------------"<<endl;
			   if((tablero[i-(m-1)][j-(m-1)]=='b'||tablero[i-(m-1)][j-(m-1)]=='B')||tablero[i-(N)][j-(N)]!='+')return 0;
			   
			   for(int w=1;w<N;w++)if(tablero[i-w][j-w]=='n')return 0;
			   
			   for(int w=1;w<N;w++){
				   
                   if(tablero[i][j]=='N' && (tablero[i-w][j-w]=='b'||tablero[i-w][j-w]=='B') && tablero[i-(w+1)][j-(w+1)]=='+'){
				   tablero[i-w][j-w]='+';
                }
				}
				
                tablero[i-(N)][j-(N)]='N';
                tablero[i][j]='+';
                i=i-(N);
                j=j-(N);
                aux=true;  
                m=N; 
           }
           
        }
        else if(iz==false && ab==false)//puede capturar Blanca hacia la derecha
        { 
			if((tablero[i-m][j+m]=='b'||tablero[i-m][j+m]=='B') && tablero[i-(m+1)][j+(m+1)]=='+')
           {
			   cout<<endl<<"hola que tal soy sebastian - +   --------------------------"<<endl;
			   if((tablero[i-(m-1)][j+(m-1)]=='b'||tablero[i-(m-1)][j+(m-1)]=='B')||tablero[i-(N)][j+(N)]!='+')return 0;
               
               for(int w=1;w<N;w++)if(tablero[i-w][j+w]=='n')return 0;
               
               for(int w=1;w<N;w++){
				   
				   if(tablero[i][j]=='N' && (tablero[i-w][j+w]=='b'||tablero[i-w][j+w]=='B') && tablero[i-(w+1)][j+(w+1)]=='+'){
				   tablero[i-w][j+w]='+';
                  }
			      }
			      
			    tablero[i-(N)][j+(N)]='N';
                tablero[i][j]='+';
                i=i-(N);
                j=j+(N);
                aux=true;
                m=N;
           }
	   }
        else if(iz==true && ab==true)//puede capturar Negra hacia la izquierda
        {
            if((tablero[i+m][j-m]=='b'||tablero[+m][j-m]=='B') && tablero[i+(m+1)][j-(m+1)]=='+')
           {
			   cout<<endl<<"hola que tal soy sebastian----     +-     ----------------------"<<endl;
			   if((tablero[i+(m-1)][j-(m-1)]=='b'||tablero[i+(m-1)][j-(m-1)]=='B')||tablero[i+(N)][j-(N)]!='+')return 0;
               
               for(int w=1;w<N;w++)if(tablero[i+w][j-w]=='n')return 0;
               
               for(int w=1;w<N;w++){
				    
					if(tablero[i][j]=='N' && (tablero[i+w][j-w]=='b'||tablero[i+w][j-w]=='B') && tablero[i+(w+1)][j-(w+1)]=='+'){
				    tablero[i+w][j-w]='+';
                }
                }
                
                tablero[i+(N)][j-(N)]='N';
                tablero[i][j]='+';
                i=i+(N);
                j=j-(N);
                aux=true;
                m=N;
                }
	   }
        else if(iz==false && ab==true)//puede capturar Negra hacia la derecha
        {
			if((tablero[i+m][j+m]=='b'||tablero[+m][j+m]=='B') && tablero[i+(m+1)][j+(m+1)]=='+')
           {
			   cout<<endl<<"hola que ---------------------------------------------------"<<endl;
			   if((tablero[i+(m-1)][j+(m-1)]=='b'||tablero[i+(m-1)][j+(m-1)]=='B')||tablero[i+(N)][j+(N)]!='+')return 0;
				
				for(int w=1;w<N;w++)if(tablero[i+w][j+w]=='n')return 0;

               for(int w=1;w<N;w++){
				    
					if(tablero[i][j]=='N' && (tablero[i+w][j+w]=='b'||tablero[i+w][j+w]=='B') && tablero[i+(w+1)][j+(w+1)]=='+'){
					tablero[i+w][j+w]='+';
                }
                }
                
                tablero[i+(N)][j+(N)]='N';
                tablero[i][j]='+';
                i=i+(N);
                j=j+(N);
                cout<<endl<<i<<j<<endl;
                aux=true;
                m=N;
           }
	   }
   }
}
           if(aux==true){
			   cout<<endl<<"---------puedecomerNNNNNNNN"<<puedeComerN(i,j,2,corona)<<endl;
           if((puedeComerN(i,j,2,corona))==1){//+-
			   cout<<endl<<"mas menos-----"<<endl;
				   iz=true;
				   ab=true;
				   siComeN(i,j,iz,Notr,corona,ab);
				   return 1;
			   }
			   else{
				   if ((puedeComerN(i,j,2,corona))==2){//--
					   iz=true;
					   ab=false;
					   siComeN(i,j,iz,Notr,corona,ab);
					   return 1;
				   }else{
					   if ((puedeComerN(i,j,2,corona))==3){//++
						   cout<<endl<<"+++++++++++++++++++++++++++++++"<<endl;
					   iz=false;
					   ab=true;
					   cout<<endl<<"+-+-+-+-+-+"<<siComeN(i,j,iz,Notr,corona,ab)<<endl;
					   return 1;
				   }else{
					   if ((puedeComerN(i,j,2,corona))==4){//-+
						   cout<<endl<<"----------------++++++++++++++++++++++++"<<endl;
					   iz=false;
					   ab=false;
					   siComeN(i,j,iz,Notr,corona,ab);
					   return 1;
				   }else{
					   if ((puedeComerN(i,j,2,corona))==0)return 1;
			   }
		   }
	   }
   }
}
return 2;
    
}
void moverNegra(int q,int &i,int &j,int N,bool corona)//Accion de movimiento Negra
{
    
    cout<<endl;
    cout<<endl;
       if(corona==false)
    {
        if(q==1)//si puede mover Blanca hacia la izquierda
        {
            //moviemiento por izquierda
            if(tablero[i][j]=='n' && tablero[i+N][j+N]=='+')
            {
                tablero[i][j]='+';
                tablero[i+N][j+N]='n';
                if((i+N)==9)tablero[i+N][j+N]='N';
                i=i+N;
                j=j+N;
            }
         }
        else if(q==2)//si puede mover Blanca hacia la derecha
        {
            //moviemiento por derecha
             if(tablero[i][j]=='n'&& tablero[i+N][j-N]=='+')
             {
				 tablero[i][j]='+';
                 tablero[i+N][j-N]='n';
                 if((i+N)==9)tablero[i+N][j-N]='N';
                 i=i+N;
                 j=j-N;
             }
        }
    }
    else
    {
        if(q==3)//si puede mover Blanca hacia la izquierda
        {
            //moviemiento por izquierda
            if(tablero[i][j]=='N' && tablero[i-N][j-N]=='+')
            {
                tablero[i][j]='+';
                tablero[i-N][j-N]='N';
                i=i-N;
                j=j-N;
            }
        }
        else if(q==4)//si puede mover Blanca hacia la derecha
        {
            //moviemiento por derecha
             if(tablero[i][j]=='N'&& tablero[i-N][j+N]=='+')
             {
                 tablero[i][j]='+';
                 tablero[i-N][j+N]='N';
                 i=i-N;
                 j=j+N;
             }
        }
        else if(q==5)//si puede mover Negra hacia la izquierda
        {
            //moviemiento por izquierda
            if((tablero[i][j]=='N') && tablero[i+N][j-N]=='+')
            {
                 tablero[i][j]='+';
                 tablero[i+N][j-N]='N';
                 i=i+N;
                 j=j-N;
            }
        }
        else if(q==6)//si puede mover Negra hacia la derecha
        {
            //moviemiento por derecha
            if((tablero[i][j]=='N') && tablero[i+N][j+N]=='+')
            {
                tablero[i][j]='+';
                tablero[i+N][j+N]='N';
                i=i+N;
                j=j+N;
            }  
        }else{
		cout<<endl<<"otro numero"<<q<<endl;
		}
    }
}

void comerNegra(int i, int j,bool iz, int N,bool corona,bool ab)//Accion de captura Negra
{
    char aux;
    cout<<endl;
    cout<<endl;
     if(corona ==false)
    {
        if(siComeB(i,j,iz,N,corona,ab)==1)//si puede capturar Blanca hacia la izquierda
        {
            //moviemiento por izquierda
            if(tablero[i][j]=='n' && (tablero[i-N][j-N]=='b'||tablero[i-N][j-N]=='B')&& tablero[i-(N+1)][j-(N+1)]=='+')
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
             if(tablero[i][j]=='n'&& (tablero[i-N][j+N]=='b'||tablero[i-N][j+N]=='B')&& tablero[i-(N+1)][j+(N+1)]=='+')
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
            //captura por izquierda
            aux=tablero[i][j];
            for(int w=1;w<N;w++){
            if(tablero[i][j]=='N' && (tablero[i-w][j-w]=='b'||tablero[i-w][j-w]=='B') && tablero[i-(w+1)][j-(w+1)]=='+'){
				tablero[i-w][j-w]='+';
                }
            }
            tablero[i-N][j-N]=aux;
            tablero[i][j]='+';
			CB++;
		 }
        else if(siComeB(i,j,iz,N,corona,ab)==4)//si puede capturar Blanca hacia la derecha
        {
            //captura por izquierda
            aux=tablero[i][j];
            for(int w=1;w<N;w++){
            if(tablero[i][j]=='N' && (tablero[i-w][j+w]=='b'||tablero[i-w][j+w]=='B') && tablero[i-(w+1)][j+(w+1)]=='+'){
				tablero[i-w][j+w]='+';
                }
            }
            tablero[i-N][j+N]=aux;
            tablero[i][j]='+';
			CB++;
         } 
        else if(siComeB(i,j,iz,N,corona,ab)==5)//si puede capturar Negra hacia la izquierda
        {
            //captura por izquierda
            aux=tablero[i][j];
            for(int w=1;w<N;w++){
            if(tablero[i][j]=='N' && (tablero[i+w][j-w]=='b'||tablero[i+w][j-w]=='B') && tablero[i+(w+1)][j-(w+1)]=='+'){
				tablero[i+w][j-w]='+';
                }
            }
            tablero[i+N][j-N]=aux;
            tablero[i][j]='+';
			CB++;
            
        }
        else if(siComeB(i,j,iz,N,corona,ab)==6)//si puede capturar Negra hacia la derecha
        {
            //captura por derecha
            aux=tablero[i][j];
           for(int w=1;w<N;w++){
		   if(tablero[i][j]=='N' && (tablero[i+w][j+w]=='b'||tablero[i+w][j+w]=='B') && tablero[i+(w+1)][j+(w+1)]=='+'){
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
int siSopladitaN(int i,int j, int N)
{   
	for(int m=0;m<10;m++)
    {
        for(int n=0;n<10;n++)
        {
			 if((m!=i || n!=j) && (tablero[m][n]=='N')){
				 
                 if(puedeComerN(m,n,N,true)!=0)
                 {
					 tablero[m][n]='+';
					 return 0;
				 } 
              }
        }
    }
    for(int m=0;m<10;m++)
    {
        for(int n=0;n<10;n++)
        {
			 if((m!=i || n!=j) && (tablero[m][n]=='n')){
				 
				 if(puedeComerN(m,n,N,false)!=0)
				 {	
                 tablero[m][n]='+';
                 return 0;
                 }
              }
        }
    }
    return 0;
}

#endif	/* NEGRAS_H */

