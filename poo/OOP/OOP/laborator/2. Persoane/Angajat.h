#pragma once
#include "Persoana.h"
class Angajat : public Persoana
{
private:
	std::string firma;
	double salariu;
public:
	Angajat(const std::string& nume, int varsta, const std::string& firma, double salariu)
		: Persoana(nume, varsta), firma(firma), salariu(salariu)
	{
	}
	~Angajat()
	{
		std::cout << "Destructor Angajat" << std::endl;
	}
	void afisare() const
	{
		Persoana::afisare();

		std::cout << "Firma: " << firma << std::endl;
		std::cout << "Salariul: " << salariu << std::endl;
	}
	double getVenit() const
	{
		return salariu;
	}
};
