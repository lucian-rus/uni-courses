// metode template
#include <vector>
#include <iostream>

class Pereche {
	double x, y;
public:
	Pereche(double x = 0, double y = 0) :x(x), y(y) {};

	bool operator == (Pereche& p)
	{
		return (x == p.x && y == p.y);
	}

	friend std::ostream& operator <<(std::ostream& os, Pereche p)
	{
		os << "(" << p.x << ", " << p.y << ") ";
		return os;
	}
};

template <typename T> 
int cautare(std::vector<T> v, T elem)
{
	for (int i = 0; i < v.size(); i++)
		{
			if (v[i] == elem)
				return i;
		}
		return -1;
}

template<typename U>
void afisare(std::vector<U> vect)
{
	for (int i = 0; i < vect.size(); i++)
		std::cout << vect[i] << " ";
	std::cout << "\n";
}

//int cautare(std::vector<int> v, int elem)
//{
//	for (int i = 0; i < v.size(); i++)
//	{
//		if (v[i] == elem)
//			return i;
//	}
//	return -1;
//}
//
//int cautare(std::vector<std::string> v, std::string elem)
//{
//	for (int i = 0; i < v.size(); i++)
//	{
//		if (v[i] == elem)
//			return i;
//	}
//
//	return -1;
//}


int main()
{
	std::vector<int> v = { 2,10,-1,4,7, -5, 6 };
	std::cout << cautare(v, 25) << "\n";
	afisare(v);

	std::vector<std::string> siruri = { "Ana", "are", "mere", "rosii" };
	std::string sir = "mere";
	std::cout << cautare(siruri, sir) << "\n";
	afisare(siruri);

	std::vector<Pereche> perechi = { {1,0}, {-1,6}, {2,3}, {-4,5} };
	Pereche p(2, 3);
	std::cout << cautare(perechi, p) << "\n";
	afisare(perechi);
}