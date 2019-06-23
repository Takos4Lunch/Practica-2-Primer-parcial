#ifndef ConsumoH
#define ConsumoH

class Consumo{
	char *unidadMedida;
	int cantidad;
	public:
		Consumo();//Constructor
		Consumo(char* a, int b);//Parametric constructor
		char getUnidadMedida();
		int getCantidad();
		virtual void mostrar();
};

#endif
