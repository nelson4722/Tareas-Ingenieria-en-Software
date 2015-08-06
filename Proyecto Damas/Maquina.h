#ifndef MAQUINA_H
#define	MAQUINA_H
#include <cstdlib>
#include <sstream>
#include <ostream>
#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
int cont=0;
int r=0;

char taux[10][10];

void copia(char W[10][10],char Z[10][10]){//Funcion que copia una matriz auxiliar
	
	for (int i=0;i<10;i++)
				{
				for(int j=0;j<10;j++)
				{
				W[i][j]=Z[i][j];
				
				}
				}
}

int comeCorona1(int i, int j, bool iz, int N, bool corona,bool ab,char taux[10][10])//Esta función busca retornar un número, el cual
{																					//entrega la distancia que debe recorrer la corona			
        if(iz==true && ab==false)                                                   //para capturar la primera pieza
         {
			   for(int w=1;w<N;w++)//entrega el valor de la dirección indicada
				   if(taux[i][j]=='N' && (taux[i-w][j-w]=='b'||taux[i-w][j-w]=='B') && taux[i-(w+1)][j-(w+1)]=='+')
				   return w+1;
          }    
        else if(iz==false && ab==false)
          {
				  for(int w=1;w<N;w++)//entrega el valor de la dirección indicada
					   if(taux[i][j]=='N' && (taux[i-w][j+w]=='b'||taux[i-w][j+w]=='B') && taux[i-(w+1)][j+(w+1)]=='+')
						   return w+1;
           }       
        else if(iz==true && ab==true)
	        {
	               for(int w=1;w<N;w++)//entrega el valor de la dirección indicada
						if(taux[i][j]=='N' && (taux[i+w][j-w]=='b'||taux[i+w][j-w]=='B') && taux[i+(w+1)][j-(w+1)]=='+')
					    return w+1;
             }  
        else if(iz==false && ab==true)
				{
					for(int w=1;w<N;w++)//entrega el valor de la dirección indicada
					    if(taux[i][j]=='N' && (taux[i+w][j+w]=='b'||taux[i+w][j+w]=='B') && taux[i+(w+1)][j+(w+1)]=='+')
						return w+1; 
					}             	
	
	return 0;			
}
int comeCorona(int i, int j, bool iz, int N, bool corona,bool ab,char taux[10][10])
{   									//Función que permite simular un movimiento de la corona, con el objetivo de encontrar
	cont++;								//un camino el cual capture el mayor numero de piezas contrarias, con ayuda de una matriz
    bool aux=false; 					//auxiliar previamente definida, esta función sirve tanto a la reina como al peón
    
         if(corona==false)
    {
        if(iz==false)//Peón que capturar hacia la izquierda, el cual se mueve por la matriz auxiliar
        {				
           if((taux[i+1][j+1]=='b'||taux[i+1][j+1]=='B') && taux[i+(2)][j+(2)]=='+' )
           {
			   taux[i][j]='+';
			   taux[i+1][j+1]='+';
			   taux[i+2][j+2]='n';
			   i=i+2;
			   j=j+2;
			   aux=true;
			   }
			   }
        else //Peón que capturar hacia la derecha, el cual se mueve por la matriz auxiliar
        {
            if((taux[i+1][j-1]=='b'||taux[i+1][j-1]=='B')&& taux[i+(2)][j-(2)]=='+')
            {
			   taux[i][j]='+';
			   taux[i+1][j-1]='+';
			   taux[i+2][j-2]='n';	
			   i=i+2;
			   j=j-2;
			   aux=true;
            }
           }
    }else
    {
   
		for(int m = 1; m<N; m++){
			
        if(iz==true && ab==false)//Corona que capturar hacia la izquierda y arriba, el cual se mueve por la matriz auxiliar
        {
           if((taux[i-m][j-m]=='b'||taux[i-m][j-m]=='B') && taux[i-(m+1)][j-(m+1)]=='+')
           {
			   if((taux[i-(m-1)][j-(m-1)]=='b'||taux[i-(m-1)][j-(m-1)]=='B')||taux[i-(N)][j-(N)]!='+')return 0;
			   
			   for(int w=1;w<N;w++)if(taux[i-w][j-w]=='n')return 0;
			   
			   for(int w=1;w<N;w++){
				   
                   if(taux[i][j]=='N' && (taux[i-w][j-w]=='b'||taux[i-w][j-w]=='B') && taux[i-(w+1)][j-(w+1)]=='+'){
				   taux[i-w][j-w]='+';
                }
				}
				
                taux[i-(N)][j-(N)]='N';
                taux[i][j]='+';
                i=i-(N);
                j=j-(N);
                aux=true;  
                m=N; 
           }
           
        }
        else if(iz==false && ab==false)//Corona que capturar hacia la derecha y arriba, el cual se mueve por la matriz auxiliar
        { 
			if((taux[i-m][j+m]=='b'||taux[i-m][j+m]=='B') && taux[i-(m+1)][j+(m+1)]=='+')
           { 
			   if((taux[i-(m-1)][j+(m-1)]=='b'||taux[i-(m-1)][j+(m-1)]=='B')||taux[i-(N)][j+(N)]!='+')return 0;
               
               for(int w=1;w<N;w++)if(taux[i-w][j+w]=='n')return 0;
               
               for(int w=1;w<N;w++){
				   
				   if(taux[i][j]=='N' && (taux[i-w][j+w]=='b'||taux[i-w][j+w]=='B') && taux[i-(w+1)][j+(w+1)]=='+'){
				   taux[i-w][j+w]='+';
                  }
			      }
			      
			    taux[i-(N)][j+(N)]='N';
                taux[i][j]='+';
                i=i-(N);
                j=j+(N);
                aux=true;
                m=N;
           }
	   }
        else if(iz==true && ab==true)//Corona que capturar hacia la izquierda y abajo, el cual se mueve por la matriz auxiliar
        {
            if((taux[i+m][j-m]=='b'||taux[+m][j-m]=='B') && taux[i+(m+1)][j-(m+1)]=='+')
           {
			  if((taux[i+(m-1)][j-(m-1)]=='b'||taux[i+(m-1)][j-(m-1)]=='B')||taux[i+(N)][j-(N)]!='+')return 0;
               
               for(int w=1;w<N;w++)if(taux[i+w][j-w]=='n')return 0;
               
               for(int w=1;w<N;w++){
				    
					if(taux[i][j]=='N' && (taux[i+w][j-w]=='b'||taux[i+w][j-w]=='B') && taux[i+(w+1)][j-(w+1)]=='+'){
				    taux[i+w][j-w]='+';
                }
                }
                taux[i+(N)][j-(N)]='N';
                taux[i][j]='+';
                i=i+(N);
                j=j-(N);
                aux=true;
                m=N;
                }
	   }
        else if(iz==false && ab==true)//Corona que capturar hacia la derecha y abajo, el cual se mueve por la matriz auxiliar
        {
			if((taux[i+m][j+m]=='b'||taux[+m][j+m]=='B') && taux[i+(m+1)][j+(m+1)]=='+')
           {
			  if((taux[i+(m-1)][j+(m-1)]=='b'||taux[i+(m-1)][j+(m-1)]=='B')||taux[i+(N)][j+(N)]!='+')return 0;
				
				for(int w=1;w<N;w++)if(taux[i+w][j+w]=='n')return 0;

               for(int w=1;w<N;w++){
				    
					if(taux[i][j]=='N' && (taux[i+w][j+w]=='b'||taux[i+w][j+w]=='B') && taux[i+(w+1)][j+(w+1)]=='+'){
					taux[i+w][j+w]='+';
                }
                }
                
                taux[i+(N)][j+(N)]='N';
                taux[i][j]='+';
                i=i+(N);
                j=j+(N);
                cout<<endl<<i<<j<<endl;
                aux=true;
                m=N;
           }
	   }
   }
}
           if(aux==true){                                   //Importante código que permite lograr la captura múltiple, 
			   if((puedeComerN(i,j,2,corona))==1){//+-      //por medio de un recurso recursivo donde se invoca a la misma función
				   iz=true;									//pero esta vez retornando un contador, para así obtener el camino
				   ab=true;								    //con mayor número de capturas
				   comeCorona(i,j,iz,Notr,corona,ab,taux);
				   return cont;
			   }
			   else{
				   if((puedeComerN(i,j,2,corona))==2){//--
					   iz=true;
					   ab=false;
					   comeCorona(i,j,iz,Notr,corona,ab,taux);
					   return cont;
				   }else{
					   if((puedeComerN(i,j,2,corona))==3){//++
					   iz=false;
					   ab=true;
					   comeCorona(i,j,iz,Notr,corona,ab,taux);
					   return cont;
				   }else{
					   if((puedeComerN(i,j,2,corona))==4){//-+
					   iz=false;
					   ab=false;
					   comeCorona(i,j,iz,Notr,corona,ab,taux);
					   return cont;
				   }else{
					   if ((puedeComerN(i,j,2,corona))==0)return cont;
			   }
		   }
	   }
   }
}
return cont;   
}    
    

int maquina(int B[]){

 
 bool ab=true, aux3=false;
 int  N=1;
 int aux=0, auxPeon=0, auxCorona=0;
 
    int valores[10][10] = {{5,0,5,0,5,0,5,0,5,0},//Matriz de costos o pesos, es el criterio del 
                           {0,1,0,1,0,1,0,1,0,2},//movimiento de los peones los cuales buscan el mayor valor
                           {5,0,3,0,3,0,3,0,4,0},//de esta matriz que refleja el tablero
                           {0,4,0,3,0,3,0,4,0,5},
                           {5,0,3,0,2,0,2,0,4,0},
                           {0,3,0,1,0,1,0,3,0,5},
                           {4,0,3,0,2,0,2,0,3,0},
                           {0,3,0,2,0,2,0,2,0,4},
                           {5,0,4,0,4,0,4,0,4,0},
                           {0,5,0,5,0,5,0,5,0,5}};
                           
for(int i=0;i<10;i++){//Busca alguna corona que tenga opción de captura, para luego usar funciones tales como
for(int j=0;j<10;j++){//comeCorona para retornar la mejor opcion de captura, tomando en cuenta que debe capturar       
                      //hacia el lado con mayor cantidad de opciones de captura
         if(tablero[i][j]=='N' && (puedeComerN(i,j,N,true)!=0))
         {
			
			 B[0]=i;
			 B[1]=j;
			 copia(taux,tablero);//copiando tablero en matriz auxiliar
			 cont=0;
			 
			 if(comeCorona(i,j,true,Notr,true,true,taux)>auxCorona){//si en tal dirección come, entonces devuelve
				 cont=0;                                            //guardando el valor en una variable 
				 auxCorona=comeCorona(i,j,true,Notr,true,true,taux);
				 copia(taux,tablero);
				 B[2]=true;
				 B[3]=true;
				 B[4]=comeCorona1(i,j,true,9,true,true,taux);
			 }
			 cont=0;
			 copia(taux,tablero);
			 if(comeCorona(i,j,true,Notr,true,false,taux)>auxCorona){//si en tal dirección come, entonces devuelve
				 cont=0;											 //guardando el valor en una variable 
				 auxCorona=comeCorona(i,j,true,Notr,true,false,taux);
				 copia(taux,tablero);
				 B[2]=true;
				 B[3]=false;
				 B[4]=comeCorona1(i,j,true,Notr,9,false,taux);
			 }
			 cont=0;
			 copia(taux,tablero);
			 if(comeCorona(i,j,false,Notr,true,true,taux)>auxCorona){//si en tal dirección come, entonces devuelve
				 cont=0;											//guardando el valor en una variable 
				 auxCorona=comeCorona(i,j,false,Notr,true,true,taux);
				 copia(taux,tablero);
				 B[2]=false;
				 B[3]=true;
				 B[4]=comeCorona1(i,j,false,9,true,true,taux);
			 }
			 cont=0;
			 copia(taux,tablero);
			 if(comeCorona(i,j,false,Notr,true,false,taux)>auxCorona){//si en tal dirección come, entonces devuelve
				 cont=0;											  //guardando el valor en una variable 
				 auxCorona=comeCorona(i,j,false,Notr,true,false,taux);
				 copia(taux,tablero);
				 B[2]=false;
				 B[3]=false;
				 B[4]=comeCorona1(i,j,false,9,true,false,taux);
			 }
		aux3=true;
		 } //al final se entregará la mejor opción de captura con la dirección donde capture mallor numero de piezas      
}                           
}
         if(aux3==true) return *B; //si come corona, retorna movimiento de corona
                                           
for(int i=0;i<10;i++){//Busca algún peón que tenga opción de captura, para luego usar funciones tales como
for(int j=0;j<10;j++){//comeCorona para retornar la mejor opcion de captura, tomando en cuenta que debe capturar   
	                  //hacia el lado con mayor cantidad de opciones de captura    
		if(tablero[i][j]=='n' && (puedeComerN(i,j,N,false)==3||puedeComerN(i,j,N,false)==1))
		{
				cont=0;
				copia(taux,tablero);
				
				if(comeCorona(i,j,true,Notr,false,true,taux)>auxPeon){//si en tal dirección come, entonces devuelve
				                                                      //posición a mover
				 cont=0;
				 copia(taux,tablero);
				 auxPeon=comeCorona(i,j,true,Notr,false,true,taux);
				 
				 B[2]=true;
				 B[0]=i;
				 B[1]=j;
				 
				 }
				 
				cout<<endl<<auxPeon<<endl;
			    cont=0;
			    copia(taux,tablero);
			    
			    if(comeCorona(i,j,false,Notr,false,true,taux)>auxPeon){//si en tal dirección come, entonces devuelve
				                                                      //posición a mover					
				 cont=0;
				 copia(taux,tablero);
				 auxPeon=comeCorona(i,j,false,Notr,false,true,taux);
				 
				 B[2]=false;
				 B[0]=i;
				 B[1]=j;
			 }
			aux3=true;	
	    }
	 }
}
if(aux3==true) return *B; //si puede comer peón, que coma la mejor opción

for(int i=0;i<10;i++){//Movimiento del peón, el cual sigue los costos o valores mas altos de la matriz
for(int j=0;j<10;j++){//de costos o valores
			  
		  if(tablero[i][j]=='n' &&(siMueveN(i,j,false,N,false,ab)==1 && valores[i+1][j+1]==5) && aux==0)//si puede mover hacia esa dirección y
		  {																							    //el valor es maximo, que mueva
			  B[0]=i;
			  B[1]=j;		 
			  B[2]=0;
			  return *B;
		  }
		  if(tablero[i][j]=='n' && (siMueveN(i,j,true,N,false,ab)==2 && valores[i+1][j-1]==5) && aux==0)//si puede mover hacia esa dirección y
		  {																								//el valor es maximo, que mueva
			  B[0]=i;
			  B[1]=j;
			  B[2]=1;
			  return *B;
		  }
		  if(tablero[i][j]=='n' && (siMueveN(i,j,false,N,false,ab)==1 && valores[i+1][j+1]==4)&& aux==1)//si puede mover hacia esa dirección y
		  {																								//el valor es maximo, que mueva
			  B[0]=i;
			  B[1]=j;
			  B[2]=0;
			  return *B;
		   }
		  if(tablero[i][j]=='n' && (siMueveN(i,j,true,N,false,ab)==2 && valores[i+1][j-1]==4)&& aux==1)//si puede mover hacia esa dirección y
		  {																								//el valor es maximo, que mueva
			  B[0]=i;
			  B[1]=j;
			  B[2]=1;
			  return *B;
		  }
		  if(tablero[i][j]=='n' && (siMueveN(i,j,false,N,false,ab)==1 && valores[i+1][j+1]==3)&& aux==2)//si puede mover hacia esa dirección y
		  {																							    //el valor es maximo, que mueva
			  B[0]=i;
			  B[1]=j;
			  B[2]=0;
			  return *B;
		  }
		  if(tablero[i][j]=='n' && (siMueveN(i,j,true,N,false,ab)==2 && valores[i+1][j-1]==3)&& aux==2)//si puede mover hacia esa dirección y
		  {																							   //el valor es maximo, que mueva
			  B[0]=i;
			  B[1]=j;
			  B[2]=1;
			  return *B;
		  }        
		  if(tablero[i][j]=='n' && (siMueveN(i,j,false,N,false,ab)==1 && valores[i+1][j+1]==2)&& aux==3)//si puede mover hacia esa dirección y
		  {																								//el valor es maximo, que mueva
			  B[0]=i;
			  B[1]=j;
			  B[2]=0;
			  return *B;
		  }
		  if(tablero[i][j]=='n' && (siMueveN(i,j,true,N,false,ab)==2 && valores[i+1][j-1]==2)&&aux==3)//si puede mover hacia esa dirección y
		  {																							  //el valor es maximo, que mueva
			  B[0]=i;
			  B[1]=j;
			  B[2]=1;
			  return *B;
		  }
		  
		  if(tablero[i][j]=='n' && (siMueveN(i,j,false,N,false,ab)==1 && valores[i+1][j+1]==1)&& aux==4)//si puede mover hacia esa dirección y
		  {																								//el valor es maximo, que mueva
			  B[0]=i;
			  B[1]=j;
			  B[2]=0;
			  return *B;
		   } 
		  if(tablero[i][j]=='n' && (siMueveN(i,j,true,N,false,ab)==2 && valores[i+1][j-1]==1)&&aux==4)//si puede mover hacia esa dirección y
		  {																							  //el valor es maximo, que mueva
			  B[0]=i;
			  B[1]=j;
			  B[2]=1;
			  return *B;
		  }
		  if(i==9 && j==9)
		  {
			  aux++;
			  if(aux==5){
				    B[0]=-1;
				    return *B;
				}
			  i=0; 
			  j=0;
		  }
	  
  }
  }
	  
}

#endif	/* MAQUINA_H */
