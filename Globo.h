#ifndef GloboH
#define GloboH

#include "Consumo.h"

class Globo{
	char codigo[10];
	char propietario[25];
	int cantidadMediciones;
	Consumo **consumos;
	public:
		Globo();//Constructor
		Globo(char *cod, char *prop, int cant, Consumo ** cnsm);//Parametric Constructor
		char *getCodigo();
		char *getPropietario();
		int getMediciones();
		Consumo ** getConsumos();
		void mostrarepa();
};

#endif
