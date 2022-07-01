#pragma once
#include "cLista.h" //ver si conviene que el include de lista este aca
#include "cCESSNA.h"
#include "cBiplano.h"
#include <stdio.h>
using namespace std;
class cTorreControl
{
private:
	cLista<cAvion>* ListaAviones;
	cLista<cPista>* Pistas;

public:
	cTorreControl(cLista<cPista>* _Pistas, cLista<cAvion>* _ListaAviones);
	~cTorreControl();
	void AsignarPista(cAvion* avion);

	void AgregarPista(cPista* pista);
	void AgregarAvion(cAvion* avion);

	void ImprimirAvionesEnVuelo();
	void ImprimirAvionesAterrizando();
	void ImprimirAvionesDespegando();
	void ImprimirPistasLibres();

	void DespegarAvion(cAvion* avion);
	void AterrizarAvion(cAvion* avion);

	bool PistasOcupadas()const;

	void LlamarComando(cAvion* avion);
	cLista<cAvion>* getListaAviones() { return ListaAviones; }
};

