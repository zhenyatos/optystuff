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
	AdaptGradStep gradStep;
	GradOpt opt(&gradStep);
	
	nric::vecfun fun = [](nric::vec x) { return 2 * pow(x[0], 4) + pow(x[1], 4) - pow(x[0], 2) - 2 * pow(x[1], 2); };
	std::cout << opt.optimize(fun, { 10, 900 }, 0.00001);

	std::cin.get();
	return 0;
}
