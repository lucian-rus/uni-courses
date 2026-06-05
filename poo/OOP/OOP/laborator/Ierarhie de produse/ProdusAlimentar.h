#pragma once
#include <string>
#include "Produs.h"
#include "Data.h"

class ProdusAlimentar : public Produs
{
public:
	ProdusAlimentar(const std::string& nume, double pret, Data data, double cantitate);
	~ProdusAlimentar();
	void afisare();
private:
	Data termenValabilitate;
	double cantitate;
};