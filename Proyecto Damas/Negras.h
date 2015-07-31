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
int puedeComerN(int i, int j, int N, bool corona)//comprueba que la ficha X,Y puede capturar alguna ficha rival
{
     if(corona==false)
    { 
       if(((tablero[i+1][j+1]=='b'|| tablero[i+1][j+1]=='B')&& tablero[i+(2)][j+(2)]=='+'))
       {//puede comer a las fichas Blancas
           return 2;
       }
       else
       {
           if((tablero[i+1][j-1]=='b'|| tablero[i+1][j-1]=='B') && tablero[i+(2)][j-(2)]=='+')
           {
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
                return 1;
             }
            else
            {
                if(((tablero[i-m][j-m]=='b'||tablero[i-m][j-m]=='B')&&tablero[i-(m+1)][j-(m+1)]=='+')&&
                   (tablero[i-(m-1)][j-(m-1)]=='+'))
                {
					Notr=m+1;
                    return 2;
                }
                else 
                {
                   if(((tablero[i+m][j+m]=='b'||tablero[i+m][j+m]=='B')&&tablero[i+(m+1)][j+(m+1)]=='+')&&
                       (tablero[i+(m-1)][j+(m-1)]=='+'))
                   {
					   Notr=m+1;
                       return 3;
                   }
                   else
                   {
                       if(((tablero[i-m][j+m]=='b'||tablero[i-m][j+m]=='B')&&tablero[i-(m+1)][j+(m+1)]=='+')&&
                       (tablero[i-(m-1)][j+(m-1)]=='+'))
                       {
						   Notr=m+1;
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
    bool aux=false; 
     if(corona==false)
    {
        if(iz==false)//puede capturar Blanca hacia la izquierda
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
        else //puede capturar Blanca hacia la derecha
        {
            if((tablero[i+1][j-1]=='b'||tablero[i+1][j-1]=='B')&& tablero[i+(2)][j-(2)]=='+')
            {
			   tablero[i][j]='+';
			   tablero[i+1][j-1]='+';
			   tablero[i+2][j-2]='n';	
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
			   if((puedeComerN(i,j,2,corona))==1){//+-
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
					   iz=false;
					   ab=true;
					   siComeN(i,j,iz,Notr,corona,ab);
					   return 1;
				   }else{
					   if ((puedeComerN(i,j,2,corona))==4){//-+
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
void moverNegra(int q,int &i,int &j,int N)//Accion de movimiento Negra
{
    cout<<endl;
    cout<<endl;
      
        if(q==1)//si puede mover Blanca hacia la izquierda
        {
                tablero[i][j]='+';
                tablero[i+N][j+N]='n';
                if((i+N)==9)tablero[i+N][j+N]='N';
                i=i+N;
                j=j+N;
         }
        else if(q==2)//si puede mover Blanca hacia la derecha
        {
				 tablero[i][j]='+';
                 tablero[i+N][j-N]='n';
                 if((i+N)==9)tablero[i+N][j-N]='N';
                 i=i+N;
                 j=j-N;
        }
        else if(q==3)//si puede mover Blanca hacia la izquierda
        {
                tablero[i][j]='+';
                tablero[i-N][j-N]='N';
                i=i-N;
                j=j-N;
        }
        else if(q==4)//si puede mover Blanca hacia la derecha
        {
                 tablero[i][j]='+';
                 tablero[i-N][j+N]='N';
                 i=i-N;
                 j=j+N;
        }
        else if(q==5)//si puede mover Negra hacia la izquierda
        {
                 tablero[i][j]='+';
                 tablero[i+N][j-N]='N';
                 i=i+N;
                 j=j-N;
        }
        else if(q==6)//si puede mover Negra hacia la derecha
        {
                tablero[i][j]='+';
                tablero[i+N][j+N]='N';
                i=i+N;
                j=j+N;  
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
					 cout<<endl<<"sopladita en posicion: "<<m<<", "<<n<<endl;
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
					 cout<<endl<<"sopladita en posicion: "<<m<<", "<<n<<endl;
					 tablero[m][n]='+';
					 return 0;
                 }
              }
        }
    }
    return 0;
}
int maquina(int B[]){


 
 bool ab=true;
 int N=1;
 int aux=0;
    int valores[10][10] = {{5,0,5,0,5,0,5,0,5,0},
                           {0,4,0,4,0,4,0,4,0,5},
                           {5,0,3,0,3,0,3,0,4,0},
                           {0,4,0,2,0,2,0,3,0,5},
                           {5,0,3,0,1,0,2,0,4,0},
                           {0,4,0,2,0,1,0,3,0,5},
                           {5,0,3,0,2,0,2,0,4,0},
                           {0,4,0,3,0,3,0,3,0,5},
                           {5,0,4,0,4,0,4,0,4,0},
                           {0,5,0,5,0,5,0,5,0,5}};
                           
                           B[0]=0;
                           B[1]=0;
                          
                           
for(int i=0;i<10;i++){
for(int j=0;j<10;j++){
		if(tablero[i][j]=='n' && (puedeComerN(i,j,N,false)==2||puedeComerN(i,j,N,false)==4))
		{
			B[0]=i;
			B[1]=j;
			if(puedeComerN(i,j,N,false)==2)B[2]=false;
			else B[2]=true;
			return *B;  
	    }
	 }
}

for(int i=0;i<10;i++){
for(int j=0;j<10;j++){
	if(i!=0){
			  
		  if(tablero[i][j]=='n' &&(siMueveN(i,j,false,N,false,ab)==1 && valores[i+1][j+1]==5) && aux==0)
		  {
			  B[0]=i;
			  B[1]=j;		 
			  B[2]=0;
			  return *B;
		  }
		  if(tablero[i][j]=='n' && (siMueveN(i,j,true,N,false,ab)==2 && valores[i+1][j-1]==5) && aux==0)
		  {
			  B[0]=i;
			  B[1]=j;
			  B[2]=1;
			  return *B;
		  }
		  if(tablero[i][j]=='n' && (siMueveN(i,j,false,N,false,ab)==1 && valores[i+1][j+1]==4)&& aux==1)
		  {
			  B[0]=i;
			  B[1]=j;
			  B[2]=0;
			  return *B;
		   }
		  if(tablero[i][j]=='n' && (siMueveN(i,j,true,N,false,ab)==2 && valores[i+1][j-1]==4)&& aux==1)
		  {
			  B[0]=i;
			  B[1]=j;
			  B[2]=1;
			  return *B;
		  }
		  if(tablero[i][j]=='n' && (siMueveN(i,j,false,N,false,ab)==1 && valores[i+1][j+1]==3)&& aux==2)
		  {
			  B[0]=i;
			  B[1]=j;
			  B[2]=0;
			  return *B;
		  }
		  if(tablero[i][j]=='n' && (siMueveN(i,j,true,N,false,ab)==2 && valores[i+1][j-1]==3)&& aux==2)
		  {
			  B[0]=i;
			  B[1]=j;
			  B[2]=1;
			  return *B;
		  }        
		  if(tablero[i][j]=='n' && (siMueveN(i,j,false,N,false,ab)==1 && valores[i+1][j+1]==2)&& aux==3)
		  {
			  B[0]=i;
			  B[1]=j;
			  B[2]=0;
			  return *B;
		  }
		  if(tablero[i][j]=='n' && (siMueveN(i,j,true,N,false,ab)==2 && valores[i+1][j-1]==2)&&aux==3)
		  {
			  B[0]=i;
			  B[1]=j;
			  B[2]=1;
			  return *B;
		  }
		  
		  if(tablero[i][j]=='n' && (siMueveN(i,j,false,N,false,ab)==1 && valores[i+1][j+1]==1)&& aux==4)
		  {
			  B[0]=i;
			  B[1]=j;
			  B[2]=0;
			  return *B;
		   } 
		  if(tablero[i][j]=='n' && (siMueveN(i,j,true,N,false,ab)==2 && valores[i+1][j-1]==1)&&aux==4)
		  {
			  B[0]=i;
			  B[1]=j;
			  B[2]=1;
			  return *B;
		  }
		  if(i==9 && j==9)
		  {
			  aux++;
			  cout<<endl<<aux<<endl;
			  i=0; 
			  j=0;
		  }
	  }
  }
  }
		  
}



#endif	/* NEGRAS_H */

