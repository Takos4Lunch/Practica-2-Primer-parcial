#ifndef ConsumoH
#define ConsumoH

class Consumo{
	char *unidadMedida;
	int cantidad;
	public:
		Consumo();//Constructor
		Consumo(char* a, int b);//Parametric constructor
		char getUnidadMedida(char * a);
		int getCantidad(int a);
		virtual void mostrar();
};

#endif
