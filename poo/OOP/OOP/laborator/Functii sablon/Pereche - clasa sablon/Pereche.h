#pragma once
#include <iostream>

template <typename T, typename U>
class Pereche {
	T primul;
	U al_doilea;
public:
	Pereche() {};
	Pereche(T primul, U al_doilea) :primul(primul), al_doilea(al_doilea) {};

	void set_primul(T primul) {
		this->primul = primul;
	}
	void set_al_doilea(U al_doilea)
	{
		this->al_doilea = al_doilea;
	}

	T get_primul() {
		return primul;
	}

	U get_al_doilea()
	{
		return al_doilea;
	}

	bool operator == (Pereche<T, U> p)
	{
		return primul == p.primul && al_doilea == p.al_doilea;
	}

	friend std::ostream& operator << (std::ostream& os, Pereche<T, U> p)
	{
		os << "(" << p.primul << ", " << p.al_doilea << ") ";
		return os;
	}
};