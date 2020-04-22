#include <iostream>
#include "GradOpt.h"
#include "AdaptGradStep.h"
#include "FastGradStep.h"
#include "UniOpt.h"
#include "vec.h"
#include "derivative.h"
#include <math.h>
#include <vector>

int main()
{
	UniOpt* uniOpt = UniOpt::get(UniOpt::FIBONACCI);
	FastGradStep gradStep1(uniOpt);
	GradOpt opt(&gradStep1);
	
	nric::vecfun fun = [](nric::vec x) { return 2 * pow(x[0], 4) + pow(x[1], 4) - pow(x[0], 2) - 2 * pow(x[1], 2); };
	std::cout << opt.optimize(fun, { 10000, 900 }, 0.0000001) << "\n";

	AdaptGradStep gradStep2;
	opt.setGradStep(&gradStep2);
	std::cout << opt.optimize(fun, { 10000, 900 }, 0.0000001) << "\n";

	std::cout << nric::hessian(fun, { 1, 3 });

	std::cin.get();
	delete uniOpt;
	return 0;
}
