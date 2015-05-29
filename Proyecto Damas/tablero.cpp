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
/*void MoverCoronaN(int i,int j,int N)
{
    if(tablero[i][j]=="(N)")
    {
        
    }
        
}*/
bool esCoronaN(int i, int j)
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
    if(esCoronaN(i,j)==true)
    {
        tablero[i][j]='N';
    }    
}
bool esCoronaB(int i, int j)
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
void CoronarB(int i, int j)
{
    if(esCoronaB(i,j)==true)
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
bool puedeMoverB(int i, int j,int N) //comprueba que la ficha X,Y puede lograr desplazarse
{
   if(tablero[i-N][j-N]=='+' ||tablero[i-N][j+N]=='+')//puede mover las Blancas
   {
       return true;
   }
   else //no puede mover Blancas
   {
       return false;
   }      
}
bool puedeMoverN(int i, int j,int N) //comprueba que la ficha X,Y puede lograr desplazarse
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
bool puedeComerN(int i, int j, int N)//comprueba que la ficha X,Y puede capturar alguna ficha rival
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
bool puedeComerB(int i, int j, int N)//comprueba que la ficha X,Y puede capturar alguna ficha rival
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

bool siMueveN(int i, int j,bool iz,int N)//determina direccion de movimiento de Negra
{
    if(iz==true)//puede desplazar Negra hacia la izquierda
    {
       if(tablero[i+N][j-N]=='+' && tab[i+N][j-N]==true)return true;
    }
    else if(iz==false)//puede desplazar Negra hacia la derecha
    {
        if(tablero[i+N][j+N]=='+'&& tab[i+N][j+N]==true)return false;
    }
}

bool siComeN(int i, int j,bool iz, int N)//determina la dirección de captura de Negra
{
    if(iz==true)//puede capturar Negra hacia la izquierda
    {
       if(tablero[i+N][j-N]=='b' && tab[i+N][j-N]==true)
       {
           if(tablero[i+(N+1)][j-(N+1)]=='+' && tab[i+(N+1)][j-(N+1)]==true)return true;
           cout<<"puede comer por izquierda"<<endl;
       }
    }
    else if(iz==false)//puede capturar Negra hacia la derecha
    {
        if(tablero[i+N][j+N]=='b'&& tab[i+N][j+N]==true)
        {
             if(tablero[i+(N+1)][j+(N+1)]=='+'&& tab[i+(N+1)][j+(N+1)]==true)return false;
            cout<<"puede comer por derecha"<<endl;
        }
    }
}

bool siMueveB(int i, int j,bool iz, int N)//determina direccion de movimiento de Blanca
{
    if(iz==true)//puede desplazar Blanca hacia la izquierda
    {
       if(tablero[i-N][j-N]=='+' && tab[i-N][j-N]==true)return true;
       cout<<"puede mover por izquierda"<<endl;
    }
    else if(iz==false)//puede desplazar Blanca hacia la derecha
    {
        if(tablero[i-N][j+N]=='+'&& tab[i-N][j+N]==true)return false;
        cout<<"puede mover por derecha"<<endl;
    }
}

bool siComeB(int i, int j,bool iz, int N)//determina la dirección de captura de Blanca
{
    if(iz==true)//puede capturar Blanca hacia la izquierda
    {
       if(tablero[i-N][j-N]=='n' && tab[i-N][j-N]==true)
       {
           if(tablero[i-(N+1)][j-(N+1)]=='+' && tab[i-(N+1)][j-(N+1)]==true)return true;
           cout<<"puede comer por izquierda"<<endl;
       }    
    }
    else if(iz==false)//puede capturar Blanca hacia la derecha
    {
        if(tablero[i-N][j+N]=='n'&& tab[i-N][j+N]==true)
        {
            if(tablero[i-(N+1)][j+(N+1)]=='+'&& tab[i-(N+1)][j+(N+1)]==true)return false;
            cout<<"puede comer por derecha"<<endl;
        }      
    }
}

void moverNegra(int i, int j,bool iz, int N)//Accion de movimiento Negra
{
    char aux;
    cout<<endl;
    cout<<endl;
    if(siMueveN(i,j,iz,N))//si puede mover Negra hacia la izquierda
    {
        //moviemiento por izquierda
        if(tablero[i][j]=='n' && tablero[i+N][j-N]=='+')
        {
             aux='n';
             tablero[i][j]='+';
             tablero[i+N][j-N]=aux; 
        }
        else
        {
            cout<<"No se puede cambiar tal ficha"<<endl;
        }     
    }
    else if(!siMueveN(i,j,iz,N))//si puede mover Negra hacia la derecha
    {
        //moviemiento por derecha
        if(tablero[i][j]=='n' && tablero[i+N][j+N]=='+')
        {
            aux='n';
            tablero[i][j]='+';
            tablero[i+N][i+N]=aux;
        }
        else
        {
            cout<<"No se puede cambiar tal ficha"<<endl;
        }
    }
}
void comerNegra(int i, int j,bool iz, int N)//Accion de captura Negra
{
    char aux;
    cout<<endl;
    cout<<endl;
    if(siComeN(i,j,iz,N))//si puede capturar Negra hacia la izquierda
    {
        //captura por izquierda
        if(tablero[i][j]=='n' && tablero[i+N][j-N]=='b' && tablero[i+(N+1)][j-(N+1)]=='+')
        {
             aux='n';
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
    else if(!siComeN(i,j,iz,N))//si puede capturar Negra hacia la derecha
    {
        //captura por derecha
        if(tablero[i][j]=='n' && tablero[i+1][j+1]=='b' && tablero[i+2][j+2]=='+')
        {
            aux='n';
            tablero[i][j]='+';
            tablero[i+1][i+1]='+';
            tablero[i+2][i+2]=aux;
            CN++;
        }
        else
        {
            cout<<"No se puede comer tal ficha"<<endl;
        }     
    }
}

void moverBlanca(int i, int j,bool iz,int N)//Accion de movimiento Blanca
{
    char aux;
    cout<<endl;
    cout<<endl;
    if(siMueveB(i,j,iz,N))//si puede mover Blanca hacia la izquierda
    {
        //moviemiento por izquierda
        if(tablero[i][j]=='b' && tablero[i-N][j-N]=='+')
        {
            aux='b';
            tablero[i][j]='+';
            tablero[i-N][j-N]=aux;
        }
        else
        {
            cout<<"No se puede cambiar tal ficha"<<endl;
        }
    }
    else if(!siMueveB(i,j,iz,N))//si puede mover Blanca hacia la derecha
    {
        //moviemiento por derecha
         if(tablero[i][j]=='b'&& tablero[i-N][j+N]=='+')
         {
             aux='b';
             tablero[i][j]='+';
             tablero[i-N][j+N]=aux;
         }
         else
         {
             cout<<"No se puede cambiar tal ficha"<<endl;
         }  
    }
}

void comerBlanca(int i, int j,bool iz,int N)//Accion de captura Blanca
{
    char aux;
    cout<<endl;
    cout<<endl;
    if(siComeB(i,j,iz,N))//si puede capturar Blanca hacia la izquierda
    {
        //moviemiento por izquierda
        if(tablero[i][j]=='b' && tablero[i-N][j-N]=='n'&& tablero[i-(N+1)][j-(N+1)]=='+')
        {
            aux='b';
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
    else if(!siComeB(i,j,iz,N))//si puede capturar Blanca hacia la derecha
    {
        //moviemiento por derecha
         if(tablero[i][j]=='b'&& tablero[i-N][j+N]=='n'&& tablero[i-(N+1)][j+(N+1)]=='+')
         {
             aux='b';
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
        bool dir;//si 'i' retorna true y 'd' retorna false
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
            cout<<"ingrese cantidad de posiciones a mover"<<endl;
            cin>>N;
        }
        else
        {
            N=1;
        }
        
        if(puedeComerB(i-1,cambioL(jota)-1,N))//prioridad de capturar por sobre desplazar
        {
            if(siComeB(i-1,cambioL(jota)-1,dir,N))//comprobar si puede capturar por izquierda
            {
               comerBlanca(i-1,cambioL(jota)-1,dir,N);//captura por izquierda
               imprimir();
            }
            else//determina captura por derecha
            {
               comerBlanca(i-1,cambioL(jota)-1,dir,N);//captura por derecha
               imprimir();
            }
        }
        else//si no puede capturar, entonces debe moverse
        {
            if(puedeMoverB(i-1,cambioL(jota)-1,N))//comprueba si puede mover
            {
                if(siMueveB(i-1,cambioL(jota)-1,dir,N))//comprobar si puede mover por izquierda
                {
                   moverBlanca(i-1,cambioL(jota)-1,dir,N);//mueve por izquierda
                   i=i-1;
                   int k=cambioL(jota)-1;
                   if(esCoronaB(i-1,k-1)==true)
                   {
                      CoronarB(i-1,k-1); 
                   }
                    imprimir();
                }
                else//determina movida por derecha
                {
                   moverBlanca(i-1,cambioL(jota)-1,dir,N);//mueve por derecha
                   i=i-1;
                   int k=cambioL(jota)-1;
                   if(esCoronaB(i-1,k+1))
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
        if(puedeComerN(i-1,cambioL(jota)-1,N))//prioridad de capturar por sobre desplazar
        {
            if(siComeN(i-1,cambioL(jota)-1,dir,N))//comprobar si puede capturar por izquierda
            {
               comerNegra(i-1,cambioL(jota)-1,dir,N);//captura por izquierda
               imprimir();
            }
            else//determina captura por derecha
            {
               comerNegra(i-1,cambioL(jota)-1,dir,N);//captura por derecha
               imprimir();
            }
        }
        else//si no puede capturar, entonces debe moverse
        {
            if(puedeMoverN(i-1,cambioL(jota)-1,N))//comprueba si puede mover
            {
                if(siMueveN(i-1,cambioL(jota)-1,dir,N))//comprobar si puede mover por izquierda
                {
                   moverNegra(i-1,cambioL(jota)-1,dir,N);//mueve por izquierda
                   imprimir();
                }
                else//determina movida por derecha
                {
                   moverNegra(i-1,cambioL(jota)-1,dir,N);//mueve por derecha
                   imprimir();
                }   
            }     
        }
    }
        
	return 0;
}
