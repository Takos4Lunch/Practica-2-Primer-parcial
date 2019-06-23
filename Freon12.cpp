#include "Freon12.h"
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

Freon12::Freon12():Consumo(){
	
}

Freon12::Freon12(char * a, int b):Consumo(a,b){

}

void Freon12::mostrar(){
	int x = getCantidad();
	char *y;
	strcpy(y,getUnidadMedida());
	cout<<x<<endl;
	cout<<y<<endl;
}
