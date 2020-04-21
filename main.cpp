#include <iostream>
#include "linalg.h"
#include <math.h>
#include <vector>

int main()
{
	nric::mat A = { {1, 1, 1}, {1, 0, 0}, {0, 0, 1} };
	nric::vec b = { 2, 1, -1 };
	std::cout << b;
	b = A * b;
	std::cout << b;

	std::cin.get();
	return 0;
}
