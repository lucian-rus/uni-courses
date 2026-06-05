#pragma once
#include <iostream>
#include <string>
class Persoana
{
protected:
	std::string nume;
	int varsta;
public:
	Persoana(const std::string& nume, int varsta)
		: nume(nume), varsta(varsta)
	{
	}
	~Persoana()
	{
		std::cout << "Destructor Persoana" << std::endl;
	}
	void afisare() const
	{
		std::cout << "Nume: " << nume << std::endl;
		std::cout << "Varsta: " << varsta << std::endl;
	}
};
