#pragma once
#include <string>

class Produs
{
public:
	Produs(const std::string& nume, double pret);
	Produs(const Produs& produs);
	~Produs();
	void afisare();
protected:
	std::string nume;
	double pret;
};
