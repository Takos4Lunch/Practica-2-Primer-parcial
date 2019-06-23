#include <iostream>
#include "Data.h"
#include "Consumo.h"
#include "Freon12.h"
#include "Helio.h"
#include "Globo.h"
#include <cstring>
#include <stdlib.h>
#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

class Principal{
	Globo ** vGlobos;
	Data data;
	public:
		
		void cargarDatos(){
			Consumo **conshelp;
			vGlobos = new Globo*[data.getLongitud()];
			int mask = 15;
			int result, helper, vectlenght;
			
			char fdat[50],testdat[50],codetest[50],codetest2[50],name[50],plsnext[50],plsnext2[50];
			
			for(int x=0;x<data.getLongitud();x++){
				 
				strcpy(fdat,data.getDatosGlobo(x));
				strcpy(codetest,strtok(fdat,"-"));
				strcpy(name,strtok(NULL,""));
				
				//This for loop checks the code
				for(int y=0;y<data.getLongitud();y++){
					strcpy(testdat,data.getDatosAltimetro(y));
					strcpy(codetest2,strtok(testdat,"/"));
					if(strcmp(codetest2,codetest)==0){
						strcpy(plsnext,strtok(NULL,"/"));
						strcpy(plsnext2,strtok(NULL,""));
						break;
					}
				}
				
				helper = atoi(plsnext2);
				
				//cout<<"cantidad de mediciones : "<<plsnext<<endl;
				vectlenght = atoi(plsnext);
				conshelp = new Consumo * [vectlenght];
				
				for(int z = 0;z<vectlenght;z++){
					//Aqui desenmascaro y guardo
					//Aqui corro bits y lleno el vector de consumos
					result = helper & mask;
					result = result*100;
					
					if(result>1196.58){
						conshelp[z] = new Freon12("Gramos",350);
					}else if(result<740.41){
						conshelp[z] = new Helio("Litros",0.5);
					}else{
						conshelp[z] = new Consumo();
					}
					
					//cout<<result<<endl;
					helper = helper>>4;
				}
				vGlobos[x] = new Globo(codetest,name,atoi(plsnext),conshelp);
				delete [] conshelp;
			}
		}
		
		void mostrarDatos(){
			char ayudante1[50], ayudante2[50];
			int ayudante3;
			int fr, hel, cantfr, canthel, cantrang;
			Consumo **cnsm;
			
			for(int x =0;x<data.getLongitud();x++){
				strcpy(ayudante1,vGlobos[x]->getCodigo());
				strcpy(ayudante2,vGlobos[x]->getPropietario());
				ayudante3 = vGlobos[x]->getMediciones();
				cout<<"Globo Nro :"<<x+1<<endl;
				cout<<"Codigo: "<<ayudante1<<endl;
				cout<<"Propietario: "<<ayudante2<<endl;
				cout<<"Nro de mediciones: "<<ayudante3<<endl;
				
				cnsm = new Consumo*[ayudante3];
				cnsm = vGlobos[x]->getConsumos();
				for(int y=0;y<ayudante3;y++){
					cnsm[y]->mostrar();
				}
				
				cout<<""<<endl;
			}
		}
};

int main(int argc, char** argv) {
	Principal x;
	x.cargarDatos();
	x.mostrarDatos();
	return 0;
}


