#include <iostream>
#include "Data.h"
#include "Consumo.h"
#include "Freon12.h"
#include "Helio.h"
#include "Globo.h"
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include <typeinfo>
#include <iomanip>

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
			int helpfr, cantfr, canthel, cantrang;
			float hel, fr, globalhel=0, globalfr=0;
			int contfr, conthel;
			Consumo **cnsm;
			
			for(int x =0;x<data.getLongitud();x++){
				strcpy(ayudante1,vGlobos[x]->getCodigo());
				strcpy(ayudante2,vGlobos[x]->getPropietario());
				ayudante3 = vGlobos[x]->getMediciones();
				cout<<"Globo Nro :"<<x+1<<endl;
				cout<<"Codigo: "<<ayudante1<<endl;
				cout<<"Propietario: "<<ayudante2<<endl;
				cout<<"Nro de mediciones: "<<ayudante3<<endl;
				fr = 0;
				hel = 0;
				cantrang = 0;
				helpfr=0;
				cnsm = new Consumo*[ayudante3];
				cnsm = vGlobos[x]->getConsumos();
				for(int y=0;y<ayudante3;y++){
					if(typeid(*cnsm[y])==typeid(Freon12)){
						fr = fr + 0.350;
						globalfr = globalfr + 0.350;
						contfr++;
					}else if(typeid(*cnsm[y])==typeid(Helio)){
						hel = hel + 0.5;
						globalhel = globalhel + 0.5;
						conthel++;
					}else{
						cantrang++;
					}
				}
				cout<<"Helio usado: "<<hel<<" litros"<<endl;
				cout<<"Freon12 usado: "<<fr<<" kilogramos"<<endl;
				cout<<cantrang<<" veces se mantuvo dentro del rango de seguridad"<<endl;
				cout<<""<<endl;
				if(fr>=5){
					cout<<"Se han usado mas de 5 lts de Helio"<<endl;
				}
				if(hel>=5){
					cout<<"Se han usado mas de 5 kgs de Freon12"<<endl;
				}
			}
			
			if(contfr>=7){
				cout<<"En este viaje, se usaron "<<globalfr<<" Kilogramos de Freon en total."<<endl<<"Para el proximo viaje, se debe llevar el doble de gas Freon12, exactamente "<<globalfr*2<<" kilogramos"<<endl;
				cout<<""<<endl;
			}
			
			if(conthel>=3){
				cout<<"En este viaje, se usaron "<<globalhel<<" Kilogramos de Freon en total."<<endl<<"Para el proximo viaje, se debe llevar el doble de gas Helio, exactamente "<<globalhel*2<<" litros"<<endl;
			}
		}
};

int main(int argc, char** argv) {
	Principal x;
	x.cargarDatos();
	x.mostrarDatos();
	//Realizado por Rafael Ramírez y Luis Acosta
	return 0;
}


