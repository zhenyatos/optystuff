#include <iostream>
#include "UniOpt.h"
#include "derivative.h"
#include "vecfun.h"
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

	nric::vecfun fun = nric::convert2d(
		[](double x, double y) { return 5 * pow(x, 2) + 5 * pow(y, 2) - 6 * x * y; });
	nric::vec grad = nric::gradient(fun, { 1, 2 });
	std::cout << grad;
	std::cin.get();

	delete opt1;
	delete opt2;
	return 0;
}
