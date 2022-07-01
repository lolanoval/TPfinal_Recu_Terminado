#pragma once
//#include <string>
#include <iostream>
using namespace std;
#define TMAX 100
template <class T>
class cLista
{
protected:
	T** lista;
	int ca;
	int ct;

public:
	cLista(int tam = TMAX);
	~cLista();

	bool operator+(T* puntero); //P= puntero que recibe, método agregar
	//void ImprimirPacientes(); //imprime el listado de receptores y donantes
	T* operator-(T* P); //sobrecarga del operator - para quitar elementos
	T* operator[](int i); //se le pasa la posición y devuelve el puntero
	int getItemPos(T* P);
	unsigned int getCA()const;
	bool Agregar(T* P);
	T* Quitar(T* P);
	bool Eliminar(T* P);
	T* BuscarenPos(int i);
	//void igualar(cLista<T>* nuevaLista);
};

template<class T>
inline cLista<T>::cLista(int tam)
{
	this->ca = 0;
	this->ct = tam; //cantidad total es igual al tamaño
	lista = new T * [ct];
	for (int i = 0; i < ct; i++)
	{
		lista[i] = NULL;
	}
}

template<class T>
inline cLista<T>::~cLista()
{
	if (lista != NULL) {

		for (int i = 0; i < ca; i++)
		{
			lista[i] = NULL;
		}
		delete this->lista;
	}
}

template<class T>
inline bool cLista<T>::operator+(T* puntero) // al agregar se asegura que el elemento no exista en la lista
{
	int i = 0;
	int pos = getItemPos(puntero);
	if (ca == ct)
		throw new exception("No hay mas espacio en la lista");
	if (pos != -1)
		throw new exception("El elemento ya se encuentra en la lista");

	this->lista[ca] = puntero;
	ca++;
	return true;
}

template<class T>
inline bool cLista<T>::Agregar(T* P)
{
	if (P != NULL && ca < ct)
	{
		lista[ca] = P;
		ca++;
		return true;
	}
	return false;
}

template<class T>
inline T* cLista<T>::operator-(T* P)
{
	T* aux = NULL;
	aux = P;
	int pos = getItemPos(P);
	if (pos != -1)
	{
		ca--;
		for (unsigned int j = pos; j < ca; j++)
		{
			lista[j] = lista[j + 1];
		}

		lista[ca] = NULL;
		return aux;
	}
	return NULL;
}

template<class T>
inline T* cLista<T>::Quitar(T* P)
{
	if (P == NULL)
		return NULL;
	int pos = getItemPos(P);
	if (pos != -1)
	{
		ca--; //disminuimos la cantidad actual
		T* aux = P; //igualamos el aux al puntero en la posición para despues devolverlo
		for (int i = pos; i < ca; i++)
		{
			lista[i] = lista[i + 1];
		}
		lista[pos] = NULL; //quitamos el puntero
		return aux; //devolvemos el auxiliar creado
	}
	return NULL;
}

template<class T>
inline bool cLista<T>::Eliminar(T* P)
{
	T* aux = Quitar(P);
	if (aux != NULL)
	{
		aux = NULL;
		return true;
	}
	return false;
}

template<class T>
inline T* cLista<T>::operator[](int i)
{
	T* retnode = NULL;
	retnode = this->lista[i];
	return retnode;
	/*if (i <= ca)
	{
		return lista[i];
	}
	return NULL;*/
}

template<class T>
inline int cLista<T>::getItemPos(T* P)
{
	int i = 0;
	for (i = 0; i < ca + 1; i++)
	{
		if (lista[i] == P)
			return i;
	}
	return -1;
}

template<class T>
inline unsigned int cLista<T>::getCA() const
{
	return ca;
}

template<class T>
inline T* cLista<T>::BuscarenPos(int i)
{
	if (i <= ca)
	{
		return lista[i];
	}
}

//template<class T>
//inline void cLista<T>::igualar(cLista<T>* nuevaLista)
//{
//	if (nuevaLista == NULL)
//		throw new exception("Lista vacia");
//	if (nuevaLista->getCA() > ct)
//		throw new exception("Nueva lista supera el tamaño posible para almacenar");
//
//	int i = 0;
//	int j = 0;
//	j = nuevaLista->getCA();
//	for (i = 0; i < j; i++)
//	{
//		lista[ca] = (*nuevaLista)[i];
//		ca++;
//	}
//}