#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<fstream>
#include "libreria/split.h"
using namespace std;

int main(/*int argc, char *argv[]*/){
char caracteres[20000];
string fechain[20];
string fechaout[20];
ifstream fe("access.log");

while(!fe.eof()){
fe.getline(caracteres, 20000); //lee la linea completa
if(strstr(caracteres,"16/Mar/2015"))
 		{
    vector<string> TempBuff(0);
    int TotalVector;
    split(caracteres, *" ",  TempBuff, TotalVector);
    cout << TempBuff[0] << endl;
    //cout << TempBuff[3] << endl;
    //cout << TempBuff[4] << endl;
    //cout << TempBuff[5] <<" "<<TempBuff[6] <<" "<<TempBuff[7] << endl;
    cout << TempBuff[8] << endl;
   // cout <<TempBuff[9] << endl;
    //cout << TempBuff[10] << endl;
    //cout << TempBuff[11] << endl;

    split(TempBuff[3], *"[",  TempBuff, TotalVector);
    //cout << TempBuff[1] << endl;
    split(TempBuff[1], *":",  TempBuff, TotalVector);
    cout << TempBuff[0] << endl;
    cout << "-----" << endl;
 		}

//cout<< "----------" << endl;
}
/*
while (!feof(fp))
 	{
 		fscanf(fp,"%s",caracteres);




 	}
 	*/
 	fe.close();
        system("PAUSE");
        //fclose(fp);
  }
