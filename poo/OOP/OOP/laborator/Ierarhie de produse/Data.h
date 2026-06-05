#pragma once
#include <iostream>

class Data
{
public:
	Data(int zi, int luna, int an)
		: zi(zi), luna(luna), an(an)
	{
	}

	friend std::ostream& operator<<(std::ostream& out, const Data& d)
	{
		out << d.zi << "/" << d.luna << "/" << d.an;
		return out;
	}

private:
	int zi, luna, an;
};
