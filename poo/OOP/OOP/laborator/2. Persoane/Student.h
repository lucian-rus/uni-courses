#pragma once
#include "Persoana.h"
class Student : public Persoana
{
private:
	std::string profil;
	double bursa;
public:
	Student(const std::string& nume, int varsta, const std::string& profil, double bursa)
		: Persoana(nume, varsta), profil(profil), bursa(bursa)
	{
	}
	~Student()
	{
		std::cout << "Destructor Student" << std::endl;
	}
	void afisare() const
	{
		Persoana::afisare();

		std::cout << "Profil: " << profil << std::endl;
		std::cout << "Bursa: " << bursa << std::endl;
	}
	double getVenit() const
	{
		return bursa;
	}
};
