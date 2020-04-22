#include <iostream>
#include "linalg.h"
#include <math.h>
#include <vector>

int main()
{
	nric::mat A = { {1, 1, 1}, {1, 0, 0}, {0, 0, 1} };
	std::cout << A << "\n";
	auto[L, D, R] = nric::LDR(A);
	std::cout << L * D * R << "\n";
	std::cout << D;

	std::cin.get();
	return 0;
}
