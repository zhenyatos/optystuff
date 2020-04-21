#include <iostream>
#include "UniOpt.h"
#include "GradOpt.h"
#include "FastGradStep.h"
#include <math.h>
#include <vector>

int main()
{
	UniOpt* uni = UniOpt::get(UniOpt::FIBONACCI);
	GradStep* step = new FastGradStep(uni);
	GradOpt opt(step);

	nric::vecfun fun1 = nric::convert2d(
		[](double x, double y) { return 2 * pow(x, 4) + pow(y, 4) - pow(x, 2) - 2 * pow(y, 2); });
	GradOpt::Result test1 = opt.optimize(fun1, { 0.4, 0.2 }, 0.000001);
	std::cout << test1 << "\n";

	nric::vecfun fun2 = [](nric::vec x) { return pow(x[0], 4) + pow(x[1], 4) + pow(x[2], 4) - 3 * x[0] * x[1] * x[2]; };
	GradOpt::Result test2 = opt.optimize(fun2, { 0.1, 0.2, 0.3 }, 0.000001);
	std::cout << test2;

	std::cin.get();

	delete uni;
	delete step;
	return 0;
}
