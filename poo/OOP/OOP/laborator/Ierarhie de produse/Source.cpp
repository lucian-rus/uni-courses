#include "Produs.h"
#include "ProdusAlimentar.h"

int main1()
{
	Produs produs("Umbrela", 35.99);
	produs.afisare();

	ProdusAlimentar produsAlimentar("Iaurt de baut", 7.99, Data(25, 05, 2026), 750);
	produsAlimentar.afisare();
	return 0;
}

int main()
{
	double real = 5.6;
	int intreg = real; // elimina zecimalele

	ProdusAlimentar produsAlimentar("Iaurt de baut", 7.99, Data(25, 05, 2026), 750);

	Produs produs = produsAlimentar; // elimina comportamentul specific
	produs.afisare();
}
