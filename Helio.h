#ifndef HelioH
#define HelioH

#include "Consumo.h"

class Helio : public Consumo{
	public:
		Helio();//Constructor
		Helio(char * a, int b);//Parametric constructor
		void mostrar();
};

#endif
