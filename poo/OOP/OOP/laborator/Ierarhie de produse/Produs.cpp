#include <iostream>
#include "Produs.h"
#include "ProdusAlimentar.h"

Produs::Produs(const std::string& nume, double pret)
	: nume(nume), pret(pret)
{
	std::cout << "Constructor Produs\n";
}

Produs::Produs(const Produs& produs)
	: nume(produs.nume), pret(produs.pret)
{
	std::cout << "Constructor de copiere Produs\n";
}

Produs::~Produs()
{
	std::cout << "Destructor Produs\n";
}

void Produs::afisare()
{
	std::cout << "Nume: " << nume << std::endl;
	std::cout << "Pret: " << pret << std::endl;
}
