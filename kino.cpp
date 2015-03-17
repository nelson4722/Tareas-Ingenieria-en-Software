#include<iostream>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

bool revisar(int v[], int x){
    for(int i=0;i<14;i++){
        if(v[i]==x){
        return true;
        }
        }
        return false;
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
  for(int i=0;i<14;i++){
  cout<<V[i]<<endl;
  }
  return 0;
  }


