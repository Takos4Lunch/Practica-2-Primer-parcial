#ifndef Freon12H
#define Freon12H

#include "Consumo.h"

class Freon12 : public Consumo{
	public:
		Freon12();//Constructor
		Freon12(char *a, int b);//Parametric Constructor
		void mostrar();
};

#endif
