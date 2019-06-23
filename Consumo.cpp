#include "Consumo.h"
#include <iostream>
#include <cstring>

Consumo::Consumo(){
	this->cantidad = 0;
	strcpy(this->unidadMedida,"");
}

Consumo::Consumo(char * a, int b){
	this->cantidad = b;
	strcpy(this->unidadMedida,a);
}

char Consumo::getUnidadMedida(char * a){
	
}

int Consumo::getCantidad(int a){
	
}

void Consumo::mostrar(){
	
}
