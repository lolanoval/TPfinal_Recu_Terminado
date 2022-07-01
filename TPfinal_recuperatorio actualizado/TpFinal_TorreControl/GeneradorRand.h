#pragma once
#include "cBiplano.h"
#include "cCESSNA.h"
#include "cLista.h"
class GeneradorRand
{


public:
	GeneradorRand();
	~GeneradorRand();
	cAvion* AvionRandom(cLista<cAvion>* listaAviones);

};

