#include "Pereche.h"
#include <iostream>
int main()
{
	Pereche<int, int> p;
	p.set_primul(5);
	p.set_al_doilea(10);
	std::cout << p;

	Pereche<std::string, int> p2("Ana", 3);
	std::cout << p2.get_al_doilea() << " " << p2;
}