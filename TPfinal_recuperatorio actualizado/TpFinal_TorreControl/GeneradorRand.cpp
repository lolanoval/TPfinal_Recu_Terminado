#include "GeneradorRand.h"

GeneradorRand::GeneradorRand()
{
}

GeneradorRand::~GeneradorRand()
{
}

cAvion* GeneradorRand::AvionRandom(cLista<cAvion>* listaAviones)
{
	if (listaAviones != NULL)
	{
		srand(time(NULL)); //semilla random 
		int limite = listaAviones->getCA() - 1;
		int random = rand() % limite; //numero random del 0 al ca de la lista menos 1
		return (*listaAviones)[random];
	}
	return NULL;
}

