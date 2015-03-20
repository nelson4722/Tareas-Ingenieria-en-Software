#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<fstream>

FILE * fp;
using namespace std;

bool revisar(int v[], int x){
    for(int i=0;i<14;i++){
        if(v[i]==x){
        return true;
        }
        }
        return false;

}

int Implementacion(int V[],int B[],int i)
{
    int cont=0,aux,y;
    srand (GetTickCount());
    while(cont<14){
        y=1+(rand()%25);
        if(revisar(V,y)==false){
            V[cont]=y;
            cont++;
        }
        }
        for(int i=1;i<14;i++){
            for(int j=0;j<13;j++){
                if(V[j]>V[j+1]){
                        aux=V[j];
                        V[j]=V[j+1];
                        V[j+1]=aux;
                }
            }
        }
        return V[i];
}

void Fecha()
{
  time_t t;
  struct tm *tm;
  char fecha[100];
  fp = fopen ("kino.csv", "ab");
  t=time(NULL);
  tm=localtime(&t);
  strftime(fecha,100, "%Y-%m-%d", tm);
  fprintf(fp,"%s ",fecha);
  cout<<fecha<<" ";
  //printf ("%s ",fecha);
  fclose(fp);
}

void Hora()
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

int main(int argc, char *argv[]){
int entrada=0,i=0;
for (i=0;i<argc;i++)
{
   if(strcmp(argv[i],"-v")==0) entrada = 2;
   else if(strcmp(argv[i],"-g")==0) entrada = 1;
}
if(entrada == 0)
{
cout<<"\nOpcion no valida, ejecute nuevamente el programa\n";
// getch();
return 0;
}else if(entrada == 1)
{   int V[15],B[15];
    Implementacion(V,B,15);
    Fecha();
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
else if(entrada == 2)
{
    cout<<"\tIntegrantes"<<endl;
    cout<<"\tNelson Alegría"<<endl;
    cout<<"\tDavid Olivero"<<endl;
    cout<<"\tNicolas Vera"<<endl;
    time_t t;
    struct tm *tm;
    char fecha[100];
    t=time(NULL);
    tm=localtime(&t);
    strftime(fecha,100, "%Y-%m-%d", tm);
    cout<<"\t"<<fecha<<endl;
}
else
{
printf("\nOpcion no valida, ejecute nuevamente el programa\n");
//getch();
return 0;
}
  }
