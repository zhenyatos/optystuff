#include "GradOpt.h"

GradOpt::GradOpt(GradStep* gradStep)
	: gradStep_(gradStep)
{}

nric::vec GradOpt::optimize(nric::vecfun fun, nric::vec init, double prec)
{
	nric::vec& x0 = init;
	nric::vec x(x0.dim());

	

	return x;
}

nric::vec GradOpt::optimize(nric::vecfun fun, int dim, double prec)
{
	nric::vec zero(dim);
	for (int i = 0; i < dim; i++)
		zero[i] = 0;

	return optimize(fun, dim, prec);
}
