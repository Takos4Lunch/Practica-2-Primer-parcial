#ifndef ConsumoH
#define ConsumoH

class Consumo{
	char unidadMedida[50];
	int cantidad;
	public:
		Consumo();//Constructor
		Consumo(char *a, int b);//Parametric constructor
		char *getUnidadMedida();
		int getCantidad();
		virtual void mostrar();
};

#endif
