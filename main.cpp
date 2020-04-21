#include <iostream>
#include "mat.h"
#include <math.h>
#include <vector>

int main()
{
	nric::mat A = { {1, 1, 1}, {1, 0, 0}, {0, 0, 1} };
	std::cout << A(0, 1) << "\n";

	double t;
	std::cin >> t;
	A(0, 2) = t;
	std::cout << A(0, 2);

	std::cin.get();
	return 0;
}
