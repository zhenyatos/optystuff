﻿#include <iostream>
#include "linalg.h"
#include <math.h>
#include <vector>

int main()
{
	nric::mat A = { {1, -1, 3, 1},
					{4, -1, 5, 4},
					{2, -2, 4, 1},
					{1, -4, 5, -1} };
	nric::vec b = { {5, 4, 6, 3} };
	std::cout << nric::solve(A, b);

	std::cin.get();
	return 0;
}
