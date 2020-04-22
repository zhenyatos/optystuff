#include <iostream>
#include "GradOpt.h"
#include "AdaptGradStep.h"
#include "FastGradStep.h"
#include "UniOpt.h"
#include "vec.h"
#include <math.h>
#include <vector>

int main()
{
	UniOpt* uniOpt = UniOpt::get(UniOpt::DICHOTOMY);
	FastGradStep gradStep1(uniOpt);
	GradOpt opt(&gradStep1);
	
	nric::vecfun fun = [](nric::vec x) { return 2 * pow(x[0], 4) + pow(x[1], 4) - pow(x[0], 2) - 2 * pow(x[1], 2); };
	std::cout << opt.optimize(fun, { 10000, 900 }, 0.00001) << "\n";

	AdaptGradStep gradStep2;
	opt.setGradStep(&gradStep2);
	std::cout << opt.optimize(fun, { 10000, 900 }, 0.00001);

	std::cin.get();
	delete uniOpt;
	return 0;
}
