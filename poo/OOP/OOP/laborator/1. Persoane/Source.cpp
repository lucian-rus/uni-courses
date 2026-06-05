#include <vector>
#include <fstream>
#include "Student.h"
#include "Angajat.h"

template<class T>
void citire(const std::string& fisier, std::vector<T>& persoane)
{
	std::ifstream fin(fisier);

	std::string nume;
	int varsta;
	std::string institutie;
	double venit;

	while (!fin.eof())
	{
		fin >> nume >> varsta >> institutie >> venit;
		T persoana(nume, varsta, institutie, venit);
		persoane.push_back(persoana);
	}

	fin.close();
}

template<class T>
double medie(const std::vector<T>& persoane)
{
	double suma = 0.0;

	for (auto& p : persoane)
		suma += p.getVenit();

	return suma / persoane.size();
}

int main()
{
	std::vector<Student> studenti;
	std::vector<Angajat> angajati;

	citire("studenti.txt", studenti);
	citire("angajati.txt", angajati);

	for (auto& s : studenti)
		s.afisare();

	std::cout << "+------------+\n";

	for (auto& a : angajati)
		a.afisare();

	std::cout << "+------------+\n";

	std::cout << "Media burselor: " << medie(studenti) << std::endl;
	std::cout << "Media salariilor: " << medie(angajati) << std::endl;

	return 0;
}
