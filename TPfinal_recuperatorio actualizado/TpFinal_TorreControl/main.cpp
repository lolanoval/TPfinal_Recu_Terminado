#include "cTorreControl.h"
#include "GeneradorRand.h"

using namespace std;

int main()
{
	//Pistas:
	cPista* pista1 = new cPista(100, 400, 1);//pista disponible
	cPista* pista2 = new cPista(300, 1000.0, 2); //pista disponible

	//Aviones:
	cAvion* cessna1 = new cCESSNA(1,1200, 10, 50, eModelo::A1);
	cAvion* cessna2 = new cCESSNA(2,2000, 20, 70, eModelo::B2);
	cAvion* biplano1 = new cBiplano(3,1500, 0, 100, 30);

	//Listas:
	cLista<cPista>* listaPistas = new cLista<cPista>();
	cLista<cAvion>* listaAviones = new cLista<cAvion>();

	try
	{
		(*listaPistas) + pista1;
		(*listaPistas) + pista2;
		(*listaAviones) + cessna1;
		(*listaAviones) + cessna2;
		(*listaAviones) + biplano1;
	}
	catch (exception* e)
	{
		cout << string(e->what()) << endl;
	}

	cessna1->Inicio();
	cessna2->Inicio();
	biplano1->Inicio();

	//Torre de Control:
	cTorreControl* torre = new cTorreControl(listaPistas, listaAviones);

	//Generador Random:
	GeneradorRand* random = new GeneradorRand();

	//uso de sobrecargas; VER COMO USARLAS
	cout << biplano1;
	//cin >> cessna1;

	try
	{
		cessna1++; //le agregamos un pasajero 
	}
	catch (exception* e)
	{
		cout << string(e->what()) << endl;
		delete e;
	}

	int numero = 0;
	while (numero == 0)
	{
		if ((torre->PistasOcupadas()))
		{
			cout << "Todas las pistas estan ocupadas en este momento" << endl;
			cout << "Ingrese un 0 para seguir: ";
			cin >> numero;
		}
		if (!(torre->PistasOcupadas()))
		{
			torre->LlamarComando(random->AvionRandom(torre->getListaAviones()));
			numero = 0;
		}
	}

	torre->ImprimirAvionesDespegando();
	torre->ImprimirAvionesAterrizando();
	torre->ImprimirAvionesEnVuelo();
	torre->ImprimirPistasLibres();

	delete pista1;
	delete pista2;
	delete cessna1;
	delete cessna2;
	delete biplano1;
	delete random;
	delete torre; 
	delete listaAviones;
	delete listaPistas;

	system("pause");
}