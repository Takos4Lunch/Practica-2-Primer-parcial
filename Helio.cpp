#include "Helio.h"
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

Helio::Helio():Consumo(){
	
}

Helio::Helio(char *a, int b):Consumo(a,b){
	
}

void Helio::mostrar(){
	int x = getCantidad();
	char y[50];
	strcpy(y,getUnidadMedida());
	cout<<x<<endl;
	cout<<y<<endl;
}
