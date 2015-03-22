#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<fstream>

FILE * fp;
using namespace std;
bool revisar(int v[], int x){ //verifica si algun numero aleatorio fue escogido anticipadamente
    for(int i=0;i<14;i++){
        if(v[i]==x){
        return true;
        }
        }
        return false;
}

int Implementacion(int V[]) // elige de forma aleatorio 14 numeros y los ordena de menor a mayor en un vector
{
    int cont=0,aux,y,i,j;
    srand (time(NULL));
    while(cont<14){
        y=1+(rand()%25);
        if(revisar(V,y)==false){
            V[cont]=y;
            cont++;
        }
        }
        for(i=1;i<14;i++){
            for(j=0;j<13;j++){
                if(V[j]>V[j+1]){
                        aux=V[j];
                        V[j]=V[j+1];
                        V[j+1]=aux;
                }
            }
        }
        return V[i];
}

void Fecha(int opcion) //funcion que nos permite obtener la fecha del sorteo del kino
{
  time_t t;
  struct tm *tm;
  char fecha[100];
  t=time(NULL);
  tm=localtime(&t);
  strftime(fecha,100, "%Y-%m-%d", tm);
  if(opcion==1) //verifica la opcion del menu, si es 1 imprime la fecha en el archivo, si es 2 solo la muestra
  {
  fp = fopen ("kino.csv", "ab");
  fprintf(fp,"%s ",fecha);
  cout<<fecha<<" ";
  fclose(fp);
  }
  else if(opcion==2)
  {
     cout<<fecha<<endl;
  }
}

void Hora() //funcion que nos permite obtener la fecha del sorteo del kino
{
time_t tiempo = time(0);
struct tm *h = localtime(&tiempo);
char hora[50];
strftime(hora,50,"%H:%M",h);
  fp = fopen ("kino.csv", "ab");
  fprintf(fp,"%s",hora);
  cout<<hora<<";";
  //printf("%s;",hora);
  fclose(fp);
}

int main(int argc, char *argv[]){ // función principal con argumentos a traves de linea de comando
cout<<"\n\t\tSORTEO DEL QNO"<<endl;
int entrada=0,i=0;
for (i=0;i<argc;i++)
{
   if(strcmp(argv[i],"-v")==0) entrada = 2; //vefica que se ingresó la opción -v de los datos de integrantes
   else if(strcmp(argv[i],"-g")==0) entrada = 1; //vefica que se ingresó la opción -g del sorteo
}
if(entrada == 0)
{
cout<<"\nOpcion no valida, ejecute nuevamente el programa\n";
// getch();
return 0;
}else if(entrada == 1) //OPCION -g
{
    cout<<"OPCION -g: SORTEO"<<endl;
    int V[15];
    Implementacion(V);
    Fecha(entrada);
    Hora();
    fp = fopen ("kino.csv", "ab");
    for(int i=0;i<14;i++)
    {
        fprintf(fp, ";%d", V[i]);
        cout<<V[i]<<";";
    }
    cout<<endl;
    fprintf(fp, "\n");
    fclose(fp);
}
else if(entrada == 2) //OPCION -v
{
    cout<<"OPCION -v: INTEGRANTES"<<endl;
    cout<<"Nelson Alegría"<<endl;
    cout<<"David Olivero"<<endl;
    cout<<"Nicolas Vera"<<endl;
    Fecha(entrada);
    system("exit");
}
else
{
printf("\nOpcion no valida, ejecute nuevamente el programa\n");
//getch();
return 0;
}
  }
