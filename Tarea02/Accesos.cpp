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
                //cout << TempBuff[0] << endl; //ip
                //cout << TempBuff[8] << endl; //estado


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
            split(TempBuff[1], *":",  TempBuff, TotalVector);
           // cout << TempBuff[0] << endl; //fecha
            //cout << "-----" << endl;
            }
        }
    }

    int ct=0;

    cout << "ESTADO" << "\t#\t" << "CANTIDAD" << endl;
    cout << "------------------------" << endl;

        for(int i=0;i<estados.size();i++)//imprime los estados y su cantidad
         {
            for(int k=0;k<cant_estados.size();k++)
               {
                if(estados[i]==cant_estados[k])
                  {
                    ct++; //lleva la cuenta de los estados
                  }
              }
            cout << estados[i] << " : " << ct << endl;
            ct = 0;
        }

         cout << "------------------------" << endl;

        cout <<  "total de estados: " << cant_estados.size() << endl; //borrar despues
}


void csv(string ipp){ //void de prueba no terminado

char asdf[1000];
char asdf2[1000];
ifstream archivo ("GeoLite2-City-Blocks-IPv4.csv"); //abre el archivo csv
vector<string> ip;
ip.push_back("216"); //a modo de prueba
ip.push_back("107");
ip.push_back("155");
ip.push_back("114");

    while(!archivo.eof()){
        archivo.getline(asdf,1000);

          vector<string> TempBuffo(0);
          vector<string> TempBuff2(0);
           int TotalVector2;
            int TotalVector;
            split(asdf, *"/",  TempBuffo, TotalVector); //quito la mascara de la ip

            if(!TempBuffo.empty()){

                split(TempBuffo[0], *".", TempBuff2, TotalVector2);
                int Octeto3 = atoi(TempBuff2[2].c_str()); //pasa de string a entero el octeto 3 y 4
                int Octeto4 = atoi(TempBuff2[3].c_str());

                if(TempBuff2[0]== ip[0] && TempBuff2[1]== ip[1]) //compara los octetos con la ip recibida
                    {
                        if(Octeto3 == 155)
                            {
                                if(Octeto4 <= 114)
                                {
                                cout << TempBuffo[0] << endl;
                                }
                            }
                        else
                        {
                                if(151 <= Octeto3 && Octeto3 <= 155) //-3
                            {
                                if( 111 <= Octeto4 && Octeto4 <= 114)
                                cout << TempBuffo[0] << endl;
                            }

                        }
                    }

            }
    }
    archivo.close();

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

        return 0;
    }
    else if(entrada == 1) //OPCION -g
    {
        if(compara(argv[2],argv[3])>0) cout<<"la fecha de termino es mayor a la de inicio"<<endl;
        else Implementacion(caracteres,inicio,fin,fe,cant_estados,estados);


    }
    else if(entrada == 2) //OPCION -g
    {
        if(compara(argv[2],argv[3])>0) cout<<"la fecha de termino es mayor a la de inicio"<<endl;
        else Implementacion(caracteres,inicio,fin,fe,cant_estados,estados);

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

        return EXIT_SUCCESS;
    }
}
