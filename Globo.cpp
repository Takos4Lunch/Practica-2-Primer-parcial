#include "Globo.h"
#include <iostream>
#include <cstring>
#include <typeinfo>
#include "Freon12.h"
#include "Helio.h"
#include "Consumo.h"

using namespace std;

Globo::Globo(){
	strcpy(this->codigo,"");
	strcpy(this->propietario,"");
	this->cantidadMediciones = 0;
}

Globo::Globo(char *cod, char *prop, int cant, Consumo ** cnsm){
	strcpy(this->codigo,cod);
	strcpy(this->propietario,prop);
	this->cantidadMediciones = cant;
	//Ahora si se viene lo chido
	consumos = new Consumo*[cant];
	for(int x = 0; x<cant;x++){
		//Usar typeid para identificar el consumo
		if(typeid(*cnsm[x])==typeid(Freon12)){
			consumos[x] = new Freon12(cnsm[x]->getUnidadMedida(),cnsm[x]->getCantidad());
		}else if(typeid(*cnsm[x])==typeid(Helio)){
			consumos[x] = new Helio(cnsm[x]->getUnidadMedida(),cnsm[x]->getCantidad());
		}else{
			consumos[x] = new Consumo(cnsm[x]->getUnidadMedida(),cnsm[x]->getCantidad());
		}
	}
}
