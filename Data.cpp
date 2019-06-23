#include <iostream>
#include <string.h>
#include "Data.h"

using namespace std;

Data::Data(){
   strcpy(datosGlobo[0],"12345-UNET");	
   strcpy(datosGlobo[1],"67890-PELLIZARI");
   strcpy(datosGlobo[2],"21369-GARZON");
   strcpy(datosGlobo[3],"93647-CIRO SANCHEZ");
   strcpy(datosGlobo[4],"77722-BETEL");    
   
   strcpy(datosAltimetro[0],"93647/4/654637289");  //0010011100000100-1111-1000-1110-1001   15-8-14-9
   strcpy(datosAltimetro[1],"67890/2/427384939");  //0001100101111001-0110-0000-0110-1011       6-11
   strcpy(datosAltimetro[2],"77722/2/637929853");  //0010011000000110-0000-1001-0111-1101       7-13  
   strcpy(datosAltimetro[3],"12345/3/647939873");  //0010011010011110-1100-0111-0010-0001     7-2-1
   strcpy(datosAltimetro[4],"21369/5/736936402");  //001010111110-1100-1100-0001-1101-0010  12-12-1-13-2
}

char * Data::getDatosGlobo(int i){
	if (i>=0 && i <this->getLongitud()) 
	   return datosGlobo[i];
	else return 0;
}

char * Data::getDatosAltimetro(int i){
	if (i>=0 && i <this->getLongitud()) 
	   return datosAltimetro[i];
	else return 0;
}

int Data::getLongitud(){
	int longitud = sizeof(datosGlobo)/sizeof(*datosGlobo);
    return longitud;
}

Data::~Data(){
	//destructor para objetos dinamicos
}

