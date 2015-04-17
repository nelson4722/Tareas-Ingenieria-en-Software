#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<fstream>
#include <vector>

using namespace std;

int Cuenta(string s, const char Separadorr, int &TotalChars) {

    for (int i = 0; i < s.size(); i++)
        if (s[i] == Separadorr) TotalChars++;
}
void split(string Linea, char Separador, vector<string> &TempBuff, int &TotalVector) {

    TempBuff.resize(0);
    TotalVector = 0;
    int Nums = -1;
    int NumPos = -1;
    int ValorNum = 0;
    int TotalChars = 0;
    int TotalEspacios = Linea.length();
    string Valor;
    Cuenta(Linea, Separador, TotalChars);

    if (TotalChars != 0) {
        while (Nums < TotalChars) {
            Nums++;
            ValorNum = Linea.find(Separador, NumPos + 1);
            Valor = Linea.substr(NumPos + 1,ValorNum);
            Valor = Valor.substr(0, Valor.find_first_of(Separador));
            TempBuff.push_back(Valor);
            NumPos = ValorNum;
            TotalEspacios++;
        }
        TotalVector = TempBuff.size();
    }
    else {

        TotalVector = 0;
    }
}

    int main(/*int argc, char *argv[]*/){

    char caracteres[20000];
    string fechain[20];
    string fechaout[20];
    ifstream fe("access.log");

    vector<string> estados; //vector con los estados sin repeticion
    vector<string> cant_estados; //vector con todos los estados repetidos incluidos

    while(!fe.eof()){
        fe.getline(caracteres, 20000); //lee la linea completa

         if(strstr(caracteres,"07/Apr/2015"))
 		  {
            vector<string> TempBuff(0);

            int TotalVector;
            split(caracteres, *" ",  TempBuff, TotalVector);

           cout << TempBuff[0] << endl;
            cout << TempBuff[8] << endl;

           cant_estados.push_back(TempBuff[8]); //mete todos los estados en el vector cant_estados

            if(estados.empty()){
                estados.push_back(TempBuff[8]);
            }

            for(int i=0;i<estados.size();i++){ //busca el estado en el vector estado

                if(estados[i]==TempBuff[8]){
                    i=estados.size();
                }
                else{
                    if(i==estados.size()-1){
                        estados.push_back(TempBuff[8]);
                    }
                }
            }

            split(TempBuff[3], *"[",  TempBuff, TotalVector);

            split(TempBuff[1], *":",  TempBuff, TotalVector);
            cout << TempBuff[0] << endl;
            cout << "-----" << endl;

 		  }
        }

        int ct=0;

        for(int i=0;i<estados.size();i++){ //imprime los estados

            for(int k=0;k<cant_estados.size();k++){

                if(estados[i]==cant_estados[k]){
                    ct++;
                }
            }
            cout << estados[i] << " : " << ct << endl;
            ct = 0;
        }

        cout <<  "total de estados: " << cant_estados.size() << endl; //borrar despues

        fe.close();
        system("PAUSE");

  }
