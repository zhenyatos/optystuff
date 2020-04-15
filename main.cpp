#include <iostream>
#include "UniOpt.h"
#include <math.h>
#include <vector>

int main()
{
	UniOpt* opt1 = UniOpt::get(UniOpt::Method::DICHOTOMY);
	UniOpt* opt2 = UniOpt::get(UniOpt::Method::FIBONACCI);

	std::vector<double> prec;
	prec.push_back(0.1);
	prec.push_back(0.01);
	prec.push_back(0.001);

	UniOpt::Result res;
	for each (double eps in prec)
	{
		res = opt1->optimize([](double x) { return abs(x - 3); }, eps);
		std::cout << "Fib " << eps << ":\n" << res << "\n\n";

		res = opt2->optimize([](double x) { return abs(x - 3); }, eps);
		std::cout << "Dih " << eps << ":\n" << res << "\n\n";
	}
	
	std::cin.get();

	delete opt1;
	delete opt2;
	return 0;
}
