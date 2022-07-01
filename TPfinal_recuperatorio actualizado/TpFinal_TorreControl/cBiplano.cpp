#include "cBiplano.h"

cBiplano::cBiplano(int _ID, int _cantcombustible, int _pasajerosmax, int _tamanio, int _aceleracion) :cAvion(_ID, _cantcombustible, _pasajerosmax, _tamanio)
{
	this->aceleracion = _aceleracion;
	this->helice = 2;
	this->pasajerosmax = 65;

}

cBiplano::~cBiplano()
{
}

void cBiplano::Despegar(cPista* pista)
{
	DespegarPadre(pista);
	cout << "--------Despegue del BIPLANO " << to_string(ID) << ":--------" << endl;
	this->aceleracion = 250;
	cout << "Se inclina un angulo de 25° del avion " << to_string(ID) << endl;
	pista->Desocupar();
	pistaAsiganda = NULL;
	//Cronometro(tiempomaxvuelo);
}

void cBiplano::Aterrizar(cPista* pista)
{
	AterrizarPadre(pista);
	cout << "--------Aterrizaje del BIPLANO " << to_string(ID) << ":--------" << endl;
	cout << "Volviendo a angulo default del avion " << to_string(ID) << endl;
	estado = eEstado::enEspera;
	this->aceleracion = 0;
	pista->Desocupar();
	pistaAsiganda = NULL;
}

float cBiplano::TiempoUsoPista()
{
	float tiempo = (float)velocidad / (float)aceleracion;
	return tiempo;
}


float cBiplano::Distancia()
{
	float tiempo = (float)velocidad / (float)aceleracion;
	float distancia = (1 / 2) * (float)aceleracion * (tiempo * tiempo);
	return distancia;
}

string cBiplano::BiplanoToString() const
{
	return "Biplano de ID: " + to_string(ID) + "\nCantidad de Combustible: " + to_string(cantcombustible) + "\nCantidad Pasajeros:" +
		to_string(pasajeros) + "\nVelocidad: " + to_string(velocidad) + "\nCantidad de Helices: "
		+ to_string(helice) + "\nAceleracion: " + to_string(aceleracion);
}

ostream& operator<<(ostream& os, const cBiplano* biplano)
{
	os << biplano->BiplanoToString();
	return os;
}
