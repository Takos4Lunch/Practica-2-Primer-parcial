#include <iostream>
#include "Data.h"
#include "Consumo.h"
#include "Freon12.h"
#include "Helio.h"
#include "Globo.h"
#include <cstring>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

class Principal{
	Globo ** vGlobos;
	Data data;
	public:
		void cargarDatos(){
			
			char fdat[50],testdat[50],codetest[50],codetest2[50],name[50],plsnext[50],plsnext2[50];
			//fdat contains the first string
			//testdat contains the second string
			//codetest contains the code
			//codetest2 contains the code from the other one
			//plsnext is the one im searching for in times of need
			
			//This for loop opens pandora's box
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
				
				cout<<fdat<<endl;
				cout<<codetest<<endl;
				cout<<name<<endl;
				cout<<testdat<<endl;
				cout<<codetest2<<endl;
				cout<<plsnext<<endl;
				cout<<plsnext2<<endl;
				
				//Now, it's time to save
				//pls don't explode
			}
		}
		void mostrarDatos(){
			
		}
};

int main(int argc, char** argv) {
	Principal x;
	x.cargarDatos();
	return 0;
}


