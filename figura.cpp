/* cre una clase Padre figura y clases hijas, circulo, rectangulo y triangulo. se pide implementar 
el diagrama de clases con los constructores  y funciones miembro necesarios  para  cada clase e implementar un
programa*/
#include <iostream>
#include <windows.h>
#include <cmath> // para usar P_MI
using namespace std;

class Figura{
	protected:
		string color;
	public:
		Figura(string);	//constructor
};

Figura::Figura(string _color){
	color=_color;
	cout<<" El color de figura es: "<<color<<endl;
}

class Circulo : public Figura{
	private:
		float radio;
	public:
		Circulo(float _radio, string _color);	//constuctor
		void calcularArea();
		void calcularPerimetro();
};

//constructor
Circulo::Circulo(float _radio, string _color) : Figura(_color){
	radio=_radio;
	cout << "el radio digitado es: "<<radio<<" y el color es "<<color<<endl;
}


void Circulo::calcularArea(){
	float area;
		area=M_PI*pow(radio,2);
		cout<<" LA ÁREA DEL CÍRCULO ES: "<<area<<endl;
	
}

void Circulo::calcularPerimetro(){
	float perimetro;
	perimetro=2*M_PI*radio;
	cout<<"EL PERÍMETRO DEL CÍRCULO ES : "<<perimetro<<endl;
	
}
class Rectangulo : public Figura{
	private:
		float base;
		float altura;
	public:
		Rectangulo(float _base, float _altura,string _color); //constructor
		void calcularArea();
		void calcularPerimetro();	
};

Rectangulo::Rectangulo(float _base, float _altura,string _color): Figura(_color){
	base=_base;
	altura=_altura;
	cout << "los datos digitados son: "<<base<<" "<<altura<<""<<color<<endl;
}

void Rectangulo::calcularArea(){
	float area;
	area=(base*altura);
	cout<<" LA ÁREA DEL RECTÁNGULO ES : "<<area<<endl;
}

void Rectangulo::calcularPerimetro(){
	
	float perimetro;
	perimetro=2*base + 2*altura;
	cout<<"EL PERÍMETRO DEL RECTÁNGULO ES : "<<perimetro<<endl;
}

class Triangulo: public Figura{
	private:
		float base;
		float altura;
		string tipo;
	public:
		Triangulo(float _base, float _altura, string _tipo,string _color); // constructor
		void calcularArea();
			
};

Triangulo::Triangulo(float _base, float _altura, string _tipo,string _color):Figura(_color){
	base=_base;
	altura=_altura;
	tipo=_tipo;
	cout << "Los datos digitados son: "<<base<<" "<<altura<<" "<<tipo<<" "<<color<<endl;
}

void Triangulo::calcularArea(){
	float area;
	area=(base*altura)/2;
	cout<<"EL ÁREA DEL TRIÁNGULO ES: "<<area<<endl;
}


int main(){
	SetConsoleOutputCP(CP_UTF8);
	Figura f1("ROSADO");
	Circulo p1(3,"azul");
	Rectangulo p2(2,3," rojo");
	Triangulo p3(2,8,"  rectangulo   ","  verde  ");
	p1.calcularArea();
	p1.calcularPerimetro();
	p2.calcularArea();
	p2.calcularPerimetro();
	p3.calcularArea();
	
	
	return 0;
}