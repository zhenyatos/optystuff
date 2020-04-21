#include "GradOpt.h"
#include "derivative.h"

GradOpt::GradOpt(GradStep* gradStep)
	: gradStep_(gradStep)
{}

nric::vec GradOpt::optimize(nric::vecfun fun, nric::vec init, double prec)
{
	nric::vec& x0 = init;
	nric::vec x(x0.dim());
	nric::vec grad = nric::gradient(fun, x0);

	x = gradStep_->step(fun, x0, grad);
	while (nric::norm(x - x0) >= prec)
	{
		x0 = x;
		grad = nric::gradient(fun, x0);
		x = gradStep_->step(fun, x0, grad);
	}

	return x;
}

nric::vec GradOpt::optimize(nric::vecfun fun, int dim, double prec)
{
	nric::vec zero(dim);
	for (int i = 0; i < dim; i++)
		zero[i] = 0;

	return optimize(fun, zero, prec);
}
