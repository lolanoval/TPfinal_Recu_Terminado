#include "cTorreControl.h"

cTorreControl::cTorreControl(cLista<cPista>* _Pistas, cLista<cAvion>* _ListaAviones)
{
	this->ListaAviones = _ListaAviones;
	this->Pistas = _Pistas;
}

cTorreControl::~cTorreControl()
{
	ListaAviones = NULL;
	Pistas = NULL;
}

void cTorreControl::AsignarPista(cAvion* avion) //try catch
{
	if (avion == NULL)
		throw new exception("Puntero nulo");
	int pos = ListaAviones->getItemPos(avion);
	if (pos == -1)
	{
		throw new exception("El avion no se encuentra en el sistema");
	}
		int tamanio = avion->getTam();
		float distancia = avion->Distancia();
		int ca = Pistas->getCA();
		int i = 0;
		for (i = 0; i < ca ; i++)
		{
			if ((*Pistas)[i]->getDistancia() >= distancia && (*Pistas)[i]->getTamanio() >= tamanio && (*Pistas)[i]->getOcupada() == false && (*Pistas)[i] != NULL)
			{
				if (avion->getEstado() == eEstado::Volando)
				{
					avion->Aterrizar(((*Pistas)[i]));
					break;
				}
					
				if (avion->getEstado() == eEstado::enEspera)
				{
					avion->Despegar(((*Pistas)[i]));
					break;
				}
			}
		}
		if (i == ca)
		{
			throw new exception("No hay pistas libres");
		}

}

void cTorreControl::ImprimirAvionesEnVuelo()
{
	cout << "-----------Aviones en vuelo:-----------" << endl;
	for (int i = 0; i < ListaAviones->getCA(); i++)
	{
		if (EstadoToString((*ListaAviones)[i]->getEstado()) == "Volando")
			(*ListaAviones)[i]->ImprimirDatos();
	}
}

void cTorreControl::ImprimirAvionesAterrizando()
{
	cout << "-----------Aviones en Aterrizando:-----------" << endl;
	for (int i = 0; i < ListaAviones->getCA(); i++)
	{
		if (EstadoToString((*ListaAviones)[i]->getEstado()) == "Aterrizando")
			(*ListaAviones)[i]->ImprimirDatos();
	}
}

void cTorreControl::ImprimirAvionesDespegando()
{
	cout << "-----------Aviones Despegando:-----------" << endl;
	for (int i = 0; i < ListaAviones->getCA(); i++)
	{
		if (EstadoToString((*ListaAviones)[i]->getEstado()) == "Despegando")
			(*ListaAviones)[i]->ImprimirDatos();
	}
}

void cTorreControl::ImprimirPistasLibres()
{
	cout << "-----------Pistas Libres:-----------" << endl;
	int j = Pistas->getCA();
	for (int i = 0; i < j; i++)
	{
		if ((*Pistas)[i]->getOcupada() == false)
		(*Pistas)[i]->ImprimirDatos();
	}
}

void cTorreControl::DespegarAvion(cAvion* avion)
{
	try
	{
		AsignarPista(avion);
	}
	catch (exception* e)
	{
		cout << string(e->what()) << endl;
		delete e;
	}
}

void cTorreControl::AterrizarAvion(cAvion* avion)
{
	try
	{
		AsignarPista(avion);
	}
	catch (exception* e)//chequear esto si era asi
	{
		cout << e->what() << endl;
		delete e;
	}
	//avion->Aterrizar(AsignarPista(avion)); 
}

bool cTorreControl::PistasOcupadas() const
{
	int j = 0;
	int i = 0;
	int ca = Pistas->getCA();
	for (i = 0; i < ca; i++)
	{
		if (!((*Pistas)[i]->getOcupada())) //si no esta ocupada, j++
			j++;
	}
	if (j != 0)
		return false;
	return true;
}

void cTorreControl::LlamarComando(cAvion* avion)
{
	switch (avion->getEstado())
	{
	case eEstado::Aterrizando:
		cout << "Avion "<<to_string(avion->getID())<<"aterrizando";
		break;
	case eEstado::Despegando:
		cout << "Avion " << to_string(avion->getID()) << "despegando";
		break;
	case eEstado::enEspera:
		DespegarAvion(avion);
		break;
	case eEstado::Volando:
		AterrizarAvion(avion);
		break;
	}

}

void cTorreControl::AgregarPista(cPista* pista)
{
	try
	{
		(*Pistas) + pista;
	}
	catch (exception* e)
	{
		cout << string(e->what()) << endl;
		delete e;
	}
	cout << "Pista agregada exitosamente" << endl;
}

void cTorreControl::AgregarAvion(cAvion* avion)
{
	try
	{
		(*ListaAviones) + avion;
	}
	catch (exception* e)
	{
		cout << string(e->what()) << endl;
		delete e;
	}
	cout << "Avion agregado exitosamente" << endl;
}

