#ifndef CAMBIOFECHA_H_INCLUDED
#define CAMBIOFECHA_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include "split.h"
using namespace std;
string agregarDia(char Fecha[])
{
   int d=1,TotalVector;
   vector<string> Temporal(0);
   split(Fecha, *"-", Temporal, TotalVector);
   char *Dia=strdup(Temporal[2].c_str());
   char *Mes=strdup(Temporal[1].c_str());
   char *Anio=strdup(Temporal[0].c_str());
   int diasMeses[]={31,28,31,30,31,30,31,31,30,31,30,31};
    int di,m,a;
    di = atoi(Dia);
    m = atoi(Mes);
    a = atoi(Anio);
    di=di+d;
    char da[3],me[3],an[3];
    while(di>diasMeses[m-1])
       {
            di=di-diasMeses[m-1];
            m=m+1;
            if(m>12)
            {
                a=a+1;
                m=1;
            }
       }
       if(di<10) sprintf(da, "0%d", di);
       else sprintf(da, "%d", di);
       if(m<10) sprintf(me, "0%d",m);
       else sprintf(me, "%d", m);
       sprintf(an, "%d", a);
     Temporal.empty();
   string Fechafinal=(string)an+"-"+(string)me+"-"+(string)da;
    return Fechafinal;
   }

int getDia(char Fecha[])
{
    vector<string> Temporal(0);
   int TotalVector;
   split(Fecha, *"-",  Temporal, TotalVector);
   char *Dia=strdup(Temporal[2].c_str());
   int d=atoi(Dia);
   Temporal.empty();
    return d;
}

int getMes(char Fecha[])
{
    vector<string> Temporal(0);
   int TotalVector;
   split(Fecha, *"-",  Temporal, TotalVector);
   char *Mes=strdup(Temporal[1].c_str());
   int m=atoi(Mes);
   Temporal.empty();
    return m;
}

int getAnio(char Fecha[])
{
    vector<string> Temporal(0);
   int TotalVector;
   split(Fecha, *"-",  Temporal, TotalVector);
   char *Anio=strdup(Temporal[0].c_str());
   int a=atoi(Anio);
    return a;
}


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
       Temporal.empty();
    string Fechafinal=(string)Dia+"/"+(string)Mes+"/"+(string)Anio;
    return Fechafinal;
}
 int compara(char Fechai[],char Fechaf[])
   {
   int TotalVector;
   vector<string> Temporali(0);
   vector<string> Temporalf(0);
   split(Fechai, *"-", Temporali, TotalVector);
   split(Fechaf, *"-", Temporalf, TotalVector);
   char *Diai=strdup(Temporali[2].c_str());
   char *Mesi=strdup(Temporali[1].c_str());
   char *Anioi=strdup(Temporali[0].c_str());
   char *Diaf=strdup(Temporalf[2].c_str());
   char *Mesf=strdup(Temporalf[1].c_str());
   char *Aniof=strdup(Temporalf[0].c_str());
   int diasMeses[]={31,28,31,30,31,30,31,31,30,31,30,31};
    int di,mi,ai,df,mf,af;
    di = atoi(Diai);
    mi = atoi(Mesi);
    ai = atoi(Anioi);
    df = atoi(Diaf);
    mf = atoi(Mesf);
    af = atoi(Aniof);
       if (ai<af)
           return  -1;
       else
          if (ai>af)
             return 1;
          else
            if (mi<mf)
                return -1;
            else
                if (mi>mf)
                    return 1;
                else
                    if (di<df)
                        return -1;
                    else
                        if (di>df)
                            return 1;
                        else
                            return 0;
   }

#endif // CAMBIOFECHA_H_INCLUDED
