#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#define T 10

using namespace std;
char tablero[T][T];
bool tab[T][T];

void inicio()
{
    cout<<"\t================\n";
    cout<<"\tTABLERO DE DAMAS\n";
    cout<<"\t================\n";
    cout<<endl;
}
bool puedeMover(int i, int j)
{
   if(tablero[i-1][j-1]=='+' ||tablero[i-1][j+1]=='+')
   {
       return true;
   }
   else 
   {
       if(tablero[i+1][j-1]=='+' ||tablero[i+1][j+1]=='+')
       {
           return true;
       }
       else
       {
           return false;
       }      
   }  
}
bool puedeComer(int i, int j)
{
   if((tablero[i-1][j-1]=='N'&& tablero[i-2][j-2]=='+') || (tablero[i-1][j+1]=='N' && tablero[i-1][j+1]=='+'))
   {
       return true;
   }
   else 
   {   
       if((tablero[i+1][j-1]=='B'&& tablero[i+2][j-2]=='+')||( tablero[i+1][j+1]=='B' && tablero[i+2][j+2]=='+'))
       {
           return true;
       }
       else
       {
           return false;
       }
   }
}

void crearlimite()
{
    for(int i=0;i<T;i++){
        for(int j=0;j<T;j++){
            tab[i][j]=true;}}
}
bool direc(char d)
{
  if(d=='i')return true;
  else if(d=='d')return false;
}

char cambioN (int i)
{
    char letras[] = {'A','B','C','D','E','F','G','H','I','J'};
    return letras[i-1];
}
int cambioL (char j)
{
    int numeros[] = {1,2,3,4,5,6,7,8,9,10};
    char letras[] = {'A','B','C','D','E','F','G','H','I','J'};
    for(int i=0;i<10;i++)
    {
        if(j==letras[i])
            return numeros[i];
    }
}

bool siMueveN(int i, int j,bool iz)
{
    if(iz==true)
    {
       if(tablero[i+1][j-1]=='+' && tab[i+1][j-1]==true)return true;
    }
    else if(iz==false)
    {
        if(tablero[i+1][j+1]=='+'&& tab[i+1][j+1]==true)return false;
    }
}

bool siComeN(int i, int j,bool iz)
{
    if(iz==true)
    {
       if(tablero[i+1][j-1]=='B' && tab[i+1][j-1]==true)
       {
           if(tablero[i+2][j-2]=='+' && tab[i+2][j-2]==true)return true;
           cout<<"puede comer por izquierda"<<endl;
       }
    }
    else if(iz==false)
    {
        if(tablero[i+1][j+1]=='B'&& tab[i+1][j+1]==true)
        {
             if(tablero[i+2][j+2]=='+'&& tab[i+2][j+2]==true)return false;
            cout<<"puede comer por derecha"<<endl;
        }
    }
}

bool siMueveB(int i, int j,bool iz)
{
    if(iz==true)
    {
       if(tablero[i-1][j-1]=='+' && tab[i-1][j-1]==true)return true;
       cout<<"puede mover por izquierda"<<endl;
    }
    else if(iz==false)
    {
        if(tablero[i-1][j+1]=='+'&& tab[i-1][j+1]==true)return false;
        cout<<"puede mover por derecha"<<endl;
    }
}

bool siComeB(int i, int j,bool iz)
{
    if(iz==true)
    {
       if(tablero[i-1][j-1]=='N' && tab[i-1][j-1]==true)
       {
           if(tablero[i-2][j-2]=='+' && tab[i-2][j-2]==true)return true;
           cout<<"puede comer por izquierda"<<endl;
       }    
    }
    else if(iz==false)
    {
        if(tablero[i-1][j+1]=='N'&& tab[i-1][j+1]==true)
        {
            if(tablero[i-2][j+2]=='+'&& tab[i-2][j+2]==true)return false;
            cout<<"puede comer por derecha"<<endl;
        }
            
    }
}

void moverNegra(int i, int j,bool iz)
{
    char aux;
    cout<<endl;
    cout<<endl;
    if(siMueveN(i,j,iz))
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
    else if(!siMueveN(i,j,iz))
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
void comerNegra(int i, int j,bool iz)
{
    char aux;
    cout<<endl;
    cout<<endl;
    if(siComeN(i,j,iz))
    {
        //moviemiento por izquierda
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
    else if(!siComeN(i,j,iz))
    {
        //moviemiento por derecha
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

void moverBlanca(int i, int j,bool iz)
{
    char aux;
    cout<<endl;
    cout<<endl;
    if(siMueveB(i,j,iz))
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
    else if(!siMueveB(i,j,iz))
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

void comerBlanca(int i, int j,bool iz)
{
    char aux;
    cout<<endl;
    cout<<endl;
    if(siComeB(i,j,iz))
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
    else if(!siComeB(i,j,iz))
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

void llenar(){

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

void imprimir(){
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
        int i,j; 
        char jota,direccion; 
        bool dir;
        crearlimite();
        llenar();
    	imprimir();
        while(true){
        cout<<"ingrese posicion que desea mover y direccion de Blancos"<<endl;
    	cin>>jota>>i>>direccion;
    	dir=direc(direccion);
        
        if(puedeComer(i-1,cambioL(jota)-1))
        {
            if(siComeB(i-1,cambioL(jota)-1,dir))
            {
               comerBlanca(i-1,cambioL(jota)-1,dir);
               imprimir();
            }
            else
            {
               comerBlanca(i-1,cambioL(jota)-1,dir);
               imprimir();
            }
        }
        else
        {
            if(puedeMover(i-1,cambioL(jota)-1))
            {
                if(siMueveB(i-1,cambioL(jota)-1,dir))
                {
                   moverBlanca(i-1,cambioL(jota)-1,dir);
                   imprimir();
                }
                else
                {
                   moverBlanca(i-1,cambioL(jota)-1,dir);
                   imprimir();
                }   
            }     
        }
        
        cout<<"ingrese posicion que desea mover y direccion de Negros"<<endl;
    	cin>>jota>>i>>direccion;
    	dir=direc(direccion);
        if(puedeComer(i-1,cambioL(jota)-1))
        {
            if(!siComeN(i-1,cambioL(jota)-1,dir))
            {
               comerNegra(i-1,cambioL(jota)-1,dir);
               imprimir();
            }
            else
            {
               comerNegra(i-1,cambioL(jota)-1,dir);
               imprimir();
            }
        }
        else
        {
            if(puedeMover(i-1,cambioL(jota)-1))
            {
                if(!siMueveN(i-1,cambioL(jota)-1,dir))
                {
                   moverNegra(i-1,cambioL(jota)-1,dir);
                   imprimir();
                }
                else
                {
                   moverNegra(i-1,cambioL(jota)-1,dir);
                   imprimir();
                }   
            }     
        } 
    } 
	return 0;
}
