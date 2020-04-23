#include "FastGradStep.h"
#include "derivative.h"

FastGradStep::FastGradStep(UniOpt* opt)
	: opt_(opt)
{}

nric::vec FastGradStep::step(nric::vecfun fun, nric::vec x)
{
	if (opt_ == nullptr)
		throw NO_UNIMODAL_OPT;
	nric::vec grad = nric::gradient(fun, x);
	std::function<double(double)> tempFun = [fun, x, grad](double alpha) {
		return fun(x - (alpha * grad));
	};

	double max;
	double norm = nric::norm(grad);
	if (norm <= MAX_STEP)
		max = 1;
	else
		max = MAX_STEP / norm;

	double alpha = (opt_->optimize(tempFun, max / MAX_STEP, 0, max)).x;
	return x - alpha * grad;
}