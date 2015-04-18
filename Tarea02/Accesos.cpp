#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<fstream>
#include "libreria/split.h"
#include "libreria/cambioFecha.h"
using namespace std;

void Implementacion(char *caracteres,char *inicio,char *fin,ifstream &fe, vector<string> cant_estados,vector<string> estados )
{
  bool marca=false;
  while(!fe.eof()){
fe.getline(caracteres, 20000); //lee la linea completa

if(strstr(caracteres,inicio)) marca=true;
if(strstr(caracteres,fin)) marca=false;

if(marca)
 		{
            vector<string> TempBuff(0);
            int TotalVector;
            split(caracteres, *" ",  TempBuff, TotalVector);

        if(!TempBuff.empty())
            {
                cout << TempBuff[0] << endl;
                //cout << TempBuff[3] << endl;
                //cout << TempBuff[4] << endl;
                //cout << TempBuff[5] <<" "<<TempBuff[6] <<" "<<TempBuff[7] << endl;
                cout << TempBuff[8] << endl;

                // cout <<TempBuff[9] << endl;
                //cout << TempBuff[10] << endl;
                //cout << TempBuff[11] << endl;
                cant_estados.push_back(TempBuff[8]); //mete todos los estados en el vector cant_estados

            if(estados.empty())
                {
                    estados.push_back(TempBuff[8]);
                }

            for(int i=0;i<estados.size();i++)//busca el estado en el vector estado
            {

                if(estados[i]==TempBuff[8]){
                    i=estados.size();
                 }
                else
                {
                    if(i==estados.size()-1)
                        {
                        estados.push_back(TempBuff[8]);
                        }
                }
            }

            split(TempBuff[3], *"[",  TempBuff, TotalVector);
            //cout << TempBuff[1] << endl;
            split(TempBuff[1], *":",  TempBuff, TotalVector);
            cout << TempBuff[0] << endl;
            cout << "-----" << endl;
            }
        }
    }

    int ct=0;

        for(int i=0;i<estados.size();i++)//imprime los estados
         {
            for(int k=0;k<cant_estados.size();k++)
               {
                if(estados[i]==cant_estados[k])
                  {
                    ct++;
                  }
              }
            cout << estados[i] << " : " << ct << endl;
            ct = 0;
        }

        cout <<  "total de estados: " << cant_estados.size() << endl; //borrar despues
}

int main(int argc, char *argv[])
{
    char caracteres[20000];
    int entrada=0,i=0;
    vector<string> estados; //vector con los estados sin repeticion
    vector<string> cant_estados; //vector con todos los estados repetidos incluidos
    ifstream fe("access.log");

    /*int argc=20;
    char *argv[20];
    argv[1]= "-so";
   argv[4]="access.log";
   argv[2]="2015-03-16";
   argv[3]="2015-03-16";*/
   cout<<"Abriendo archivo"<<argv[0]<<".exe"<<endl;
        char *inicio=strdup(cambioFecha(argv[2]).c_str());
        char *f= strdup(agregarDia(argv[3]).c_str());
        char *fin=strdup(cambioFecha(f).c_str());
    for(i=0;i<argc;i++)
    {
        if(strcmp(argv[1],"-so")==0 && strcmp(argv[4],"access.log")==0) entrada = 1;
        else if(strcmp(argv[1],"-geo")==0 && strcmp(argv[4],"access.log")==0) entrada = 2;
        else if(strcmp(argv[1],"-v")==0) entrada = 3;

    }

    if(entrada == 0)
    {
        cout<<"\nOpcion no valida, ejecute nuevamente el programa\n";
        // getch();
        return 0;
    }
    else if(entrada == 1) //OPCION -g
    {
        if(compara(argv[2],argv[3])>0) cout<<"la fecha de termino es mayor a la de inicio"<<endl;
        else Implementacion(caracteres,inicio,fin,fe,cant_estados,estados);

        //cout<<"OPCION -g: SORTEO"<<endl;
    }
    else if(entrada == 2) //OPCION -g
    {
        if(compara(argv[2],argv[3])>0) cout<<"la fecha de termino es mayor a la de inicio"<<endl;
        else Implementacion(caracteres,inicio,fin,fe,cant_estados,estados);
        //cout<<"OPCION -g: SORTEO"<<endl;
    }
    else if(entrada == 3) //OPCION -v
    {
        cout<<"OPCION -v: INTEGRANTES"<<endl;
        cout<<"Nelson Alegría"<<endl;
        cout<<"David Olivero"<<endl;
        cout<<"Nicolas Vera"<<endl;
        printf("Fecha de compilacion: %s - %s\n\n ", __DATE__, __TIME__);//Fecha de compilacion.
        EXIT_SUCCESS;
    }

    else
    {
        printf("\nOpcion no valida, ejecute nuevamente el programa\n");
        //getch();
        return EXIT_SUCCESS;
    }
}
