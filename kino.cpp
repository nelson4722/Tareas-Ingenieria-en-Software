#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include <time.h>
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

void Fecha()
{
  time_t t;
  struct tm *tm;
  char fecha[100];
  fp = fopen ("kino.txt", "w+");
  t=time(NULL);
  tm=localtime(&t);
  strftime(fecha,100, "%Y-%m-%d", tm);
  fprintf(fp,"%s ",fecha);
  printf ("%s ",fecha);
  fclose(fp);
}

void Hora()
{

time_t tiempo = time(0);
struct tm *h = localtime(&tiempo);
char hora[50];
strftime(hora,50,"%H:%M",h);
  fp = fopen ("kino.txt", "a");
  fprintf(fp,"%s",hora);
  printf("%s;",hora);
  fclose(fp);
}


int main(){

    int V[15],B[15];
    int cont=0,aux,y;
    srand (time(NULL));


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
        Fecha();
        Hora();
        fp = fopen ("kino.txt", "a");

  for(int i=0;i<14;i++){
  fprintf(fp, ";%d", V[i]);
  cout<<V[i]<<";";
  }
  fclose(fp);
  return 0;
  }


