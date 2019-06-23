#ifndef DataH
#define DataH

//#include <iostream>
//#include <string.h>

//using namespace std;

class Data{
	
	private:
	    //Atributos
		char datosGlobo[5][25];
		char datosAltimetro[5][25];
	public:
		//Métodos
		Data();
		char * getDatosGlobo(int i);
		char * getDatosAltimetro(int i);
		int getLongitud();
		~Data();
};
#endif


