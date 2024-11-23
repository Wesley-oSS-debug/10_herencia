#include <iostream>
#include <windows.h>
using namespace std;

// clase base o madre Vehiculo
class Vehiculo{
	protected:
		string numPlaca;
		string color;
		string marca;
		int velocimetro;
	public:
		Vehiculo(string, string, string, int); // prototipo del constructor 
	//	~Vehiculo(); destructor
		void mostrarDatos();
		void cambiarVelocimetro(int);
};

Vehiculo :: Vehiculo (string _numPlaca, string _color, string _marca, int _velocimetro){
	numPlaca=_numPlaca;
	color=_color;
	marca=_marca;
	velocimetro=_velocimetro;
}

void Vehiculo :: mostrarDatos(){
	cout<<"\n-----DATOS DEL VEHÍCULO------\n\n";
	cout<<" NÚMERO DE PLACA: "<<numPlaca<<endl
		<<" COLOR: "<<color<<endl
		<<" MARCA: "<<marca<<endl
		<<" VELOCÍMETRO: "<<velocimetro<<" Km/h"<<endl;
}

void Vehiculo :: cambiarVelocimetro(int nuevoVelocimetro){
		velocimetro=nuevoVelocimetro;
	
}

//clase derivada de Vehiculo
class Automovil: public Vehiculo{
		private:
			int cantPuertas;
			int cantPasajeros;
		public:
			Automovil(string, string, string, int, int, int);	// constructor
			void mostrarAutomovil();
			void subirPasajeros(int);
			void bajarPasajeros(int);
			
};

Automovil :: Automovil(string _numPlaca, string _color, string _marca, int _velocimetro,int _cantPuertas, int _cantPasajeros) : Vehiculo (_numPlaca,  _color,  _marca,  _velocimetro){
	cantPuertas=_cantPuertas;
	cantPasajeros=_cantPasajeros;
}

void Automovil :: mostrarAutomovil(){
	mostrarDatos();
	cout<<"CANTIDAD DE PUERTAS: "<<cantPuertas<<endl;
	cout<<"CANTIDAD DE PASAJEROS: "<<cantPasajeros<<endl;
}

 void Automovil :: subirPasajeros(int subePasajeros){
	cantPasajeros+=subePasajeros;	
}

void Automovil :: bajarPasajeros(int menosPasajeros){
	cantPasajeros-=menosPasajeros;
}

//clase derivada de Vehiculo
class Camion: public Vehiculo{
		private:
			string carga;
		public:
			Camion(string, string, string, int, int, int, string); //constructor
			void mostrarCamion();
			void cambiarCarga(string);	
};

Camion :: Camion(string _numPlaca, string _color, string _marca, int _velocimetro,int _cantPuertas, int _cantPasajeros, string _carga): Vehiculo (_numPlaca,  _color,  _marca,  _velocimetro) {
	carga=_carga;
}

void Camion :: mostrarCamion(){
	mostrarDatos();
	cout<<" LA CARGA ES: "<<carga<<endl;
	
}

void Camion :: cambiarCarga(string nuevaCarga){
	carga=nuevaCarga;
}
int main(){
SetConsoleOutputCP(CP_UTF8);
	Vehiculo v1("RFA-452","Plomo","TOYOTA",180);
	v1.mostrarDatos();
	v1.cambiarVelocimetro(150);
	v1.mostrarDatos();
	cout<<"-------------------------------------------------------------------";
	Automovil a1("RFA-452","Plomo","TOYOTA",180,6,10);
	a1.mostrarAutomovil();
	a1.subirPasajeros(4);
	a1.mostrarAutomovil();
	a1.bajarPasajeros(4);
	a1.mostrarAutomovil();
	cout<<"---------------------------------------------------------------------";
	Camion c1("RFA-452","Plomo","TOYOTA",180,6,10,"Caja de manzanas");
	c1.mostrarCamion();
	c1.cambiarCarga("Caja de uvas");
	c1.mostrarCamion();
	return 0;
}