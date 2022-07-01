#pragma once
#include <string>
#include <iostream>
#include "cPista.h"
#include "cFecha.h"
#include "Enum.h"
using namespace std;
class cAvion
{
protected:
	int cantcombustible, pasajeros, pasajerosmax, velocidad, helice, tamanio;
	int ID;
	static int cont;
	float tiempomaxvuelo;
	eEstado estado;
	cPista* pistaAsiganda;
  
public:

	//tanto tamaño como distancia condicionan la pista a asignar
	
	cAvion(int _ID, int _cantcombustible, int _pasajerosmax, int _tamanio);
	virtual ~cAvion();
	virtual void Despegar(cPista* pista) {}
	virtual void Aterrizar(cPista* pista) {}
	void DespegarPadre(cPista* pista); 
	void AterrizarPadre(cPista* pista); 
	int getTam() { return tamanio; }
	void setTiempoVuelo(); 
	virtual float Distancia() = 0;
	void ImprimirDatos();
	string toString();
	eEstado getEstado() { return estado; }
	void operator++(); //sobrecarga del operador ++ para sumar pasajeros
	int getID() { return ID; }
	void Inicio();
};
