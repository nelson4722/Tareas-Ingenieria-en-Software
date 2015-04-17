#ifndef CAMBIOFECHA_H_INCLUDED
#define CAMBIOFECHA_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include "split.h"
using namespace std;

string cambioFecha(char Fecha[])
{
   vector<string> Temporal(0);
   int TotalVector;
   split(Fecha, *"-",  Temporal, TotalVector);
   char *Dia=strdup(Temporal[2].c_str());
   char *MesAux=strdup(Temporal[1].c_str());
   char *Anio=strdup(Temporal[0].c_str());
   char Mes[4];
   if (strcmp(MesAux,"01")==0) strcpy(Mes,"Jan");
       else if (strcmp(MesAux,"02")==0) strcpy(Mes,"Feb");
       else if (strcmp(MesAux,"03")==0) strcpy(Mes,"Mar");
       else if (strcmp(MesAux,"04")==0) strcpy(Mes,"Apr");
       else if (strcmp(MesAux,"05")==0) strcpy(Mes,"May");
       else if (strcmp(MesAux,"06")==0) strcpy(Mes,"Jun");
       else if (strcmp(MesAux,"07")==0) strcpy(Mes,"Jul");
       else if (strcmp(MesAux,"08")==0) strcpy(Mes,"Aug");
       else if (strcmp(MesAux,"09")==0) strcpy(Mes,"Sep");
       else if (strcmp(MesAux,"10")==0) strcpy(Mes,"Oct");
       else if (strcmp(MesAux,"11")==0) strcpy(Mes,"Nov");
       else if (strcmp(MesAux,"12")==0) strcpy(Mes,"Dec");
       char Fechaf[11];
    strcat(Fechaf,Dia);
    strcat(Fechaf,"/");
    strcat(Fechaf,Mes);
    strcat(Fechaf,"/");
    strcat(Fechaf,Anio);
    string Fechafinal=Fechaf;
    return Fechafinal;
}
#endif // CAMBIOFECHA_H_INCLUDED
