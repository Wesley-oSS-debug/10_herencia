#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

//clase base o madre de Persona----------------------------------------------
class Persona{
	protected:
		string nombres;
		string DNI;
		int edad;
	public:
		Persona(string, string, int); //prototipo  del constructor
		void mostrarDatos()	;
		
};

Persona :: Persona(string n, string d, int e){
	nombres=n;
	DNI=d;
	edad=e;
}

void Persona :: mostrarDatos(){
	cout<<nombres<<" Tiene el DNI# "<<DNI<<" y tiene "<<edad<<" años de edad\n"; 
}
//clase derivada Docente------------------------------------------------
class Docente : public Persona{
	private:
		int sueldo;
		string especialidad;
	public:
		Docente(string,string,int,int,string);
		void mostrarDocente();
		//void ingresarNotas();
		//void visualizarRegistro();
		
};

Docente :: Docente(string n, string d, int e, int s, string es): Persona(n,d,e){
	sueldo = s;
	especialidad=es;
}

void Docente :: mostrarDocente(){
	mostrarDatos();
	cout<<"\tEs un docente con un sueldo de S/ "<<sueldo<<endl;
	cout<<"\tSu especialida es : "<<especialidad<<endl;
}

//Clase derivadas Estudiante---------------------------------------
class Estudiante :public Persona{
	private:
		int notas[5];
		int numNotas;
		string codigo;
	public:
	Estudiante(string, string, int, int[], int, string);
	//void visualiazarNotas();
	void mostrarEstudiante();	
	
};

Estudiante :: Estudiante(string n, string d, int e, int no[], int nn, string c) : Persona(n,d,e){
	numNotas=nn;
	for(int i=0;i<nn;i++){
		notas[i]=no[i];
	}
		codigo=c;
}

void Estudiante :: mostrarEstudiante(){
	mostrarDatos();
	cout<<"\tEs un estudiante con código "<<codigo<<" y tiene "<<numNotas<<" notas : ";
	for(int i=0;i<numNotas;i++){
		cout<<notas[i]<<" ,";
	}
}

int main(){
	SetConsoleOutputCP(CP_UTF8);
	string nombre, nombre1;
	Persona p("Juan Perez","60172851",18);
	p.mostrarDatos(); cout<<"\n";
	cout<<"Ingrese nombre del Docente : "; fflush(stdin); getline(cin,nombre1);
	Docente d(nombre1, "89766598",54, 8000,"Analista de Datos");
	d.mostrarDocente(); cout<<"\n";
	int nota[]={20,15,17};
	cout<<"Ingrese nombre de estudiante : "; fflush(stdin);
	getline(cin,nombre);
	Estudiante e(nombre,"23249065", 19, nota, 3, "2024-119046");
	e.mostrarEstudiante(); cout<<"\n";
	return 0;
}