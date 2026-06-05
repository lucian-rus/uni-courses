#include <iostream>

static void counter()
{
	static int count = 0;
	count++;
	std::cout << count << "\n";
}