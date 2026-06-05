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

int main()
{
	/*std::vector<Student> studenti;
	std::vector<Angajat> angajati;

	citire("studenti.txt", studenti);
	citire("angajati.txt", angajati);

	std::vector<Persoana*> colectieMixta1;
	colectieMixta1.push_back(&studenti[0]);
	colectieMixta1.push_back(&angajati[0]);

	for (auto& p : colectieMixta1)
		p->afisare();*/

	std::vector<Persoana*> colectieMixta2;
	colectieMixta2.push_back(new Student("Ion", 18, "INFO", 700.0));
	colectieMixta2.push_back(new Angajat("Alexa", 28, "Oracle", 6000.0));

	for (auto& p : colectieMixta2)
		p->afisare();	// Apeleaza functia de afisare din clasa Persoana

	for (auto& p : colectieMixta2)
		delete p;		// Apeleaza DOAR destructorul din clasa Persoana !!!!!!

	return 0;
}
