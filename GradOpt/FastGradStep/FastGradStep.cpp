#include "FastGradStep.h"

FastGradStep::FastGradStep(UniOpt* opt)
	: opt_(opt)
{}

nric::vec FastGradStep::step(nric::vecfun fun, nric::vec x, nric::vec grad)
{
	std::function<double(double)> tempFun = [fun, x, grad](double alpha) {
		return fun(x - (alpha * grad));
	};

	double alpha = (opt_->optimize(tempFun, PREC, 0, MAX_ALPHA)).x;

	return x - alpha * grad;
}