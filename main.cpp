#include <iostream>
#include "UniOpt.h"
#include "GradOpt.h"
#include "FastGradStep.h"
#include <math.h>
#include <vector>

int main()
{
	nric::vecfun fun = nric::convert2d(
		[](double x, double y) { return 2 * pow(x, 4) + pow(y, 4) - pow(x, 2) - 2 * pow(y, 2); });
	
	UniOpt* uni = UniOpt::get(UniOpt::FIBONACCI);
	GradStep* step = new FastGradStep(uni);
	GradOpt opt(step);
	nric::vec test = opt.optimize(fun, { 0.4, 0.2 }, 0.0000001);
	std::cout << test;
	std::cin.get();

	delete uni;
	delete step;
	return 0;
}
