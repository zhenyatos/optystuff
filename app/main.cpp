#include <iostream>
#include "opty/GradOpt.h"
#include "opty/AdaptGradStep.h"
#include "opty/FastGradStep.h"
#include "opty/UniOpt.h"
#include "opty/vec.h"
#include "opty/derivative.h"
#include "opty/Newton.h"
#include <math.h>
#include <vector>

int main()
{
	UniOpt* uniOpt = UniOpt::get(UniOpt::FIBONACCI);
	FastGradStep gradStep1(uniOpt);
	GradOpt opt(&gradStep1);
	
	nric::vecfun fun = [](nric::vec x) { return 2 * pow(x[0], 4) + pow(x[1], 4) - pow(x[0], 2) - 2 * pow(x[1], 2); };
	std::cout << opt.optimize(fun, { 10000, 900 }, 0.0000001) << "\n\n";

	AdaptGradStep gradStep2;
	opt.setGradStep(&gradStep2);
	std::cout << opt.optimize(fun, { 10000, 900 }, 0.0000001) << "\n\n";

	Newton newton;
	std::cout << newton.optimize(fun, { 10000, 900 }, 0.0000001) << "\n";

	std::cin.get();
	delete uniOpt;
	return 0;
}
