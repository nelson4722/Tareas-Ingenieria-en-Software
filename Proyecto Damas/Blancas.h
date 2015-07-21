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
bool direc(char o);
bool diaux(char p);
int iaux=0;
int jaux=0;
int Notro=0;
int CB=0;// contador de Blancas capturadas
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
int puedeComerB(int i, int j, int N, bool corona)//comprueba que la ficha X,Y puede capturar alguna ficha rival
{
    if(corona==false)
    { cout<<endl<<"corona "<<corona<<endl<<tablero[i-(2)][j-(2)]<<endl<<tablero[i-(1)][j-(1)]<<endl;
       if(((tablero[i-1][j-1]=='n'|| tablero[i-1][j-1]=='N')&& tablero[i-(2)][j-(2)]=='+'))
       {//puede comer a las fichas Negras
           h='i';
           return 2;
       }
       else
       {
           if((tablero[i-1][j+1]=='n'|| tablero[i-1][j+1]=='N') && tablero[i-(2)][j+(2)]=='+')
           {
               h='d';
               return 4;
           }
                   
       }
    }
    else
    {
		for(int m=1;m<7;m++){ 
            if(((tablero[i+m][j-m]=='n' || tablero[i+m][j-m]=='N')&&tablero[i+(m+1)][j-(m+1)]=='+')&&
            (tablero[i+(m-1)][j-(m-1)]=='+'))
            {
                Notro=m+1;
                h='i'; v='b';
                return 1;
             }
            else
            {
                if(((tablero[i-m][j-m]=='n'||tablero[i-m][j-m]=='N')&&tablero[i-(m+1)][j-(m+1)]=='+')&&
                (tablero[i-(m-1)][j-(m-1)]=='+'))
                {
					Notro=m+1;
                    h='i'; v='a';
                    return 2;
                }
                else 
                {
				  
                   if(((tablero[i+m][j+m]=='n'||tablero[i+m][j+m]=='N')&&tablero[i+(m+1)][j+(m+1)]=='+')&&
                   (tablero[i+(m-1)][j+(m-1)]=='+'))
                   {
					   Notro=m+1;
                       h='d'; v='b';
                       return 3;
                   }
                   else
                   {
                       if(((tablero[i-m][j+m]=='n'||tablero[i-m][j+m]=='N')&&tablero[i-(m+1)][j+(m+1)]=='+')&&
                       (tablero[i-(m-1)][j+(m-1)]=='+'))
                       {
						   Notro=m+1;
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
           return 7;
        }
        else if(iz==false && ab==false)//puede desplazar Blanca hacia la derecha
        {
            if(tablero[i-N][j+N]=='+'&& tab[i-N][j+N]==true)return 2;
            return 7;
        }
    }
    else
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

int siComeB(int i, int j,bool iz, int N,bool corona,bool ab)//determina la dirección de captura de Blanca
{
    cout<<"SI COME BLANCA"<<endl;
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
           if((tablero[i-1][j-1]=='n'||tablero[i-1][j-1]=='N') && tablero[i-(2)][j-(2)]=='+' )
           {
			   tablero[i][j]='+';
			   tablero[i-1][j-1]='+';
			   tablero[i-2][j-2]='b';
			   i=i-2;
			   j=j-2;
			   aux=true;
			   
           }
          
        }
        else if(iz==false)//puede capturar Blanca hacia la derecha
        {
            if((tablero[i-1][j+1]=='n'||tablero[i-1][j+1]=='N')&& tablero[i-(2)][j+(2)]=='+')
            {
			   tablero[i][j]='+';
			   tablero[i-1][j+1]='+';
			   tablero[i-2][j+2]='b';	
			   i=i-2;
			   j=j+2;
			   aux=true;
            }
           
        }
    }
    else
    {
		for(int m = 1; m<N; m++){
			
        if(iz==true && ab==false)//puede capturar Blanca hacia la izquierda
        {
           if((tablero[i-m][j-m]=='n'||tablero[i-m][j-m]=='N') && tablero[i-(m+1)][j-(m+1)]=='+')
           {
			   cout<<endl<<"hola que tal soy sebastian--------------------------"<<endl;
			   if((tablero[i-(m-1)][j-(m-1)]=='n'||tablero[i-(m-1)][j-(m-1)]=='N')||tablero[i-(N)][j-(N)]!='+')return 0;
               
               for(int w=1;w<N;w++)if(tablero[i-w][j-w]=='b')return 0;
               
               for(int w=1;w<N;w++){
				   
                   if(tablero[i][j]=='B' && (tablero[i-w][j-w]=='n'||tablero[i-w][j-w]=='N') && tablero[i-(w+1)][j-(w+1)]=='+'){
				   tablero[i-w][j-w]='+';
                }
			}
                tablero[i-(N)][j-(N)]='B';
                tablero[i][j]='+';
                i=i-(N);
                j=j-(N);
                aux=true;  
                m=N; 
           }
           
        }
        else if(iz==false && ab==false)//puede capturar Blanca hacia la derecha
        { 
			if((tablero[i-m][j+m]=='n'||tablero[i-m][j+m]=='N') && tablero[i-(m+1)][j+(m+1)]=='+')
           {
			   cout<<endl<<"hola que tal soy sebastian - +   --------------------------"<<endl;
			   if((tablero[i-(m-1)][j+(m-1)]=='n'||tablero[i-(m-1)][j+(m-1)]=='N')||tablero[i-(N)][j+(N)]!='+')return 0;
               
               for(int w=1;w<N;w++)if(tablero[i-w][j+w]=='b')return 0;
               
               for(int w=1;w<N;w++){
				   if(tablero[i-w][j+w]=='b')return 0;
				   if(tablero[i][j]=='B' && (tablero[i-w][j+w]=='n'||tablero[i-w][j+w]=='N') && tablero[i-(w+1)][j+(w+1)]=='+'){
				   tablero[i-w][j+w]='+';
                  }
			}
			 tablero[i-(N)][j+(N)]='B';
                tablero[i][j]='+';
                i=i-(N);
                j=j+(N);
                aux=true;
                m=N;
           }
	   }
        else if(iz==true && ab==true)//puede capturar Negra hacia la izquierda
        {
            if((tablero[i+m][j-m]=='n'||tablero[+m][j-m]=='N') && tablero[i+(m+1)][j-(m+1)]=='+')
           {
			   cout<<endl<<"hola que tal soy sebastian----     +-     ----------------------"<<endl;
			   if((tablero[i+(m-1)][j-(m-1)]=='n'||tablero[i+(m-1)][j-(m-1)]=='N')||tablero[i+(N)][j-(N)]!='+')return 0;
               
               for(int w=1;w<N;w++)if(tablero[i+w][j-w]=='b')return 0;
               
               for(int w=1;w<N;w++){
				    
					if(tablero[i][j]=='B' && (tablero[i+w][j-w]=='n'||tablero[i+w][j-w]=='N') && tablero[i+(w+1)][j-(w+1)]=='+'){
				    tablero[i+w][j-w]='+';
				    
                }
                }
                tablero[i+(N)][j-(N)]='B';
                tablero[i][j]='+';
                i=i+(N);
                j=j-(N);
                aux=true;
                m=N;
                }
	   }
        else if(iz==false && ab==true)//puede capturar Negra hacia la derecha
        {
			if((tablero[i+m][j+m]=='n'||tablero[+m][j+m]=='N') && tablero[i+(m+1)][j+(m+1)]=='+')
           {
			   cout<<endl<<"hola que ---------------------------------------------------"<<endl;
			   if((tablero[i+(m-1)][j+(m-1)]=='n'||tablero[i+(m-1)][j+(m-1)]=='N')||tablero[i+(N)][j+(N)]!='+')return 0;
			   
				for(int w=1;w<N;w++)if(tablero[i+w][j+w]=='b')return 0;
				
                for(int w=1;w<N;w++){
				  
					if(tablero[i][j]=='B' && (tablero[i+w][j+w]=='n'||tablero[i+w][j+w]=='N') && tablero[i+(w+1)][j+(w+1)]=='+')
					tablero[i+w][j+w]='+';
                }
                cout<<endl<<"que xuuuxa"<<endl;
                tablero[i+(N)][j+(N)]='B';
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
			   cout<<endl<<"---------puedecomerBBBBBBB"<<puedeComerB(i,j,2,corona)<<endl;
           if((puedeComerB(i,j,2,corona))==1){//+-
			   cout<<endl<<"mas menos-----"<<endl;
				   iz=true;
				   ab=true;
				   siComeB(i,j,iz,Notro,corona,ab);
				   return 1;
			   }
			   else{
				   if ((puedeComerB(i,j,2,corona))==2){//--
					   iz=true;
					   ab=false;
					   siComeB(i,j,iz,Notro,corona,ab);
					   return 1;
				   }else{
					   if ((puedeComerB(i,j,2,corona))==3){//++
						   cout<<endl<<"+++++++++++++++++++++++++++++++"<<endl;
					   iz=false;
					   ab=true;
					   cout<<endl<<"+-+-+-+-+-+"<<siComeB(i,j,iz,Notro,corona,ab)<<endl;
					   return 1;
				   }else{
					   if ((puedeComerB(i,j,2,corona))==4){//-+
						   cout<<endl<<"----------------++++++++++++++++++++++++"<<endl;
					   iz=false;
					   ab=false;
					   siComeB(i,j,iz,Notro,corona,ab);
					   return 1;
				   }else{
					   if ((puedeComerB(i,j,2,corona))==0)return 1;
			   }
		   }
	   }
   }
}
return 2;
}


void moverBlanca(int q,int &i,int &j,int N,bool corona)//Accion de movimiento Blanca
{
    cout<<endl;
    cout<<endl;
    if(corona==false)
    {
        if(q==1)//si puede mover Blanca hacia la izquierda
        {
            //moviemiento por izquierda
            if(tablero[i][j]=='b' && tablero[i-N][j-N]=='+')
            {
                tablero[i][j]='+';
                tablero[i-N][j-N]='b';
                if((i-N)==0)tablero[i-N][j-N]='B';
                i=i-N;
                j=j-N;
            }
         }
        else if(q==2)//si puede mover Blanca hacia la derecha
        {
            //moviemiento por derecha
             if(tablero[i][j]=='b'&& tablero[i-N][j+N]=='+')
             {
				 tablero[i][j]='+';
                 tablero[i-N][j+N]='b';
                 if((i-N)==0)tablero[i-N][j+N]='B';
                 i=i-N;
                 j=j+N;
             }
        }
    }
    else
    {
        if(q==3)//si puede mover Blanca hacia la izquierda
        {
            //moviemiento por izquierda
            if(tablero[i][j]=='B' && tablero[i-N][j-N]=='+')
            {
                tablero[i][j]='+';
                tablero[i-N][j-N]='B';
                i=i-N;
                j=j-N;
            }
        }
        else if(q==4)//si puede mover Blanca hacia la derecha
        {
            //moviemiento por derecha
             if(tablero[i][j]=='B'&& tablero[i-N][j+N]=='+')
             {
                 tablero[i][j]='+';
                 tablero[i-N][j+N]='B';
                 i=i-N;
                 j=j+N;
             }
        }
        else if(q==5)//si puede mover Negra hacia la izquierda
        {
            //moviemiento por izquierda
            if((tablero[i][j]=='B') && tablero[i+N][j-N]=='+')
            {
                 tablero[i][j]='+';
                 tablero[i+N][j-N]='B';
                 i=i+N;
                 j=j-N;
            }
        }
        else if(q==6)//si puede mover Negra hacia la derecha
        {
            //moviemiento por derecha
            if((tablero[i][j]=='B') && tablero[i+N][j+N]=='+')
            {
                tablero[i][j]='+';
                tablero[i+N][j+N]='B';
                i=i+N;
                j=j+N;
            }  
        }else{
		cout<<endl<<"otro numero"<<q<<endl;
		}
    }
}

int siSopladitaB(int i, int j, int N)
{   
	  for(int m=0;m<10;m++)
    {
        for(int n=0;n<10;n++)
        { 
			
			 if((m!=i || n!=j) && (tablero[m][n]=='B')){
				 
                 if(puedeComerB(m,n,N,true)!=0)
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
			
			 if((m!=i || n!=j) && (tablero[m][n]=='b')){
				 
				 if(puedeComerB(m,n,N,false)!=0)
				 {	
                 tablero[m][n]='+';
                 return 0;
                 }
            
			 }
         }
	}
	return 0;
}
    #endif	/* BLANCAS_H */
