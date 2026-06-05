#include <iostream>
#include <vector>
#include "Pereche.h"

template<class Type1, class Type2>
int Pereche<Type1, Type2>::counterInstante = 0;

int main()
{
	Pereche<int, float> A;		// apel constructor fara parametri
	Pereche<int, float> B = A;	// apel constructor de copiere
	
	Pereche C;		// apel constructor fara parametri

	std::cout << Pereche<int, float>::GetCounterInstante() << "\n";
	std::cout << Pereche<int, int>::GetCounterInstante() << "\n";
}