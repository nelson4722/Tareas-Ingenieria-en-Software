#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
#include<sstream>
using namespace std;


int main(){
float x1=0,x2=0,x3=0,x4=0,x5=0,x6=0,x7=0,x8=0,x9=0,x10=0,x11=0,x12=0;
float x13=0,x14=0,x15=0,x16=0,x17=0,x18=0,x19=0,x20=0,x21=0,x22=0,x23=0,x24=0,x25=0,x26;
string out[20];
char* valores;
int i=0;
int c[20];
ifstream salida;

salida.open("kino.csv",ios::in);

if(salida.fail()){
	cout<<"fallo al abrir el archivo";
	
}else{
	char fecha[20],hora[40];
	
	while(!salida.eof()){
		salida>>fecha>>hora;
		valores=strtok(hora,";");
	while(valores){
		out[i]=valores;
		valores=strtok(NULL,";");
		i++;

	}
	i=0;
		for(int i=0;i<15;i++){
	       stringstream ss(out[i]);
	       ss>>c[i];
	       }
          
         for(int i=1;i<16;i++){
	       if(c[i]==1){x1++;
		}else{if(c[i]==2){x2++;}
			   else{if(c[i]==3){x3++;}
	                 else{if(c[i]==4){x4++;}
						 else{if(c[i]==5){x5++;}
	                         else{if(c[i]==6){x6++;}
								 else{if(c[i]==7){x7++;}
	                                 else{if(c[i]==8){x8++;}
										 else{if(c[i]==9){x9++;}
	                                         else{if(c[i]==10){x10++;}
												 else{if(c[i]==11){x11++;}
	                                                 else{if(c[i]==12){x12++;}
														 else{if(c[i]==13){x13++;}
	                                                         else{if(c[i]==14){x14++;}
																 else{if(c[i]==15){x15++;}
	                                                                  else{if(c[i]==16){x16++;}
																		  else{if(c[i]==17){x17++;}
	                                                                       else{if(c[i]==18){x18++;}
			                                                               else{if(c[i]==19){x19++;}
	                                                                       else{if(c[i]==20){x20++;}
						                                                   else{if(c[i]==21){x21++;}
	                                                                       else{if(c[i]==22){x22++;}
								                                           else{if(c[i]==23){x23++;}
	                                                                       else{if(c[i]==24){x24++;}
									                                    	 else{if(c[i]==25){x25++;}
																			 }}}}}}}}}}}}}}}}}}}}}}}}
	                                                                       
          }  
          
	}	
}

x26=x1+x2+x3+x4+x5+x6+x7+x8+x9+x10+x11+x12+x13+x14+x15+x16+x17+x18+x19+x20+x21+x22+x23+x24+x25;
cout<<"-----------------Porcentaje de repeticion de numeros------------------------"<<endl<<endl;
cout<<" el numero 1 se repite "<<x1/x26*100<<"%"<<endl;
cout<<" el numero 2 se repite "<<x2/x26*100<<"%"<<endl;
cout<<" el numero 3 se repite "<<x3/x26*100<<"%"<<endl;
cout<<" el numero 4 se repite "<<x4/x26*100<<"%"<<endl;
cout<<" el numero 5 se repite "<<x5/x26*100<<"%"<<endl;
cout<<" el numero 6 se repite "<<x6/x26*100<<"%"<<endl;
cout<<" el numero 7 se repite "<<x7/x26*100<<"%"<<endl;
cout<<" el numero 8 se repite "<<x8/x26*100<<"%"<<endl;
cout<<" el numero 9 se repite "<<x9/x26*100<<"%"<<endl;
cout<<" el numero 10 se repite  "<<x10/x26*100<<"%"<<endl;
cout<<" el numero 11 se repite "<<x11/x26*100<<"%"<<endl;
cout<<" el numero 12 se repite "<<x12/x26*100<<"%"<<endl;
cout<<" el numero 13 se repite "<<x13/x26*100<<"%"<<endl;
cout<<" el numero 14 se repite "<<x14/x26*100<<"%"<<endl;
cout<<" el numero 15 se repite "<<x15/x26*100<<"%"<<endl;
cout<<" el numero 16 se repite "<<x16/x26*100<<"%"<<endl;
cout<<" el numero 17 se repite "<<x17/x26*100<<"%"<<endl;
cout<<" el numero 18 se repite "<<x18/x26*100<<"%"<<endl;
cout<<" el numero 19 se repite "<<x19/x26*100<<"%"<<endl;
cout<<" el numero 20 se repite "<<x20/x26*100<<"%"<<endl;
cout<<" el numero 21 se repite "<<x21/x26*100<<"%"<<endl;
cout<<" el numero 22 se repite "<<x22/x26*100<<"%"<<endl;
cout<<" el numero 23 se repite "<<x23/x26*100<<"%"<<endl;
cout<<" el numero 24 se repite "<<x24/x26*100<<"%"<<endl;
cout<<" el numero 25 se repite "<<x25/x26*100<<"%"<<endl;
return(0);
}
