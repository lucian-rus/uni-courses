#pragma once

template<class Type1 = int, class Type2 = int>
class Pereche
{
public:
	Pereche()
		: Pereche(Type1(), Type2())
	{
	}
	Pereche(Type1 item1, Type2 item2)
		: item1(item1), item2(item2)
	{
		counterInstante++;
	}
	Pereche(const Pereche& pereche)
		: Pereche(pereche.item1, pereche.item2)
	{
	}

	static int GetCounterInstante()
	{
		return counterInstante;
	}

private:
	Type1 item1;
	Type2 item2;

	static int counterInstante;
};