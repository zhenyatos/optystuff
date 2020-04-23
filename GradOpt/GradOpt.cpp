#include "GradOpt.h"
#include "derivative.h"

std::ostream& operator<<(std::ostream& stream, const GradOpt::Result& res)
{
	stream << "x: " << res.x <<
		"\ny: " << res.y <<
		"\ngradient value: " << res.grad << 
		"\niterations: " << res.iter;
	return stream;
}

GradOpt::GradOpt(GradStep* gradStep)
	: gradStep_(gradStep)
{}

GradOpt::Result GradOpt::optimize(nric::vecfun fun, nric::vec init, double prec)
{
	nric::vec& x0 = init;
	nric::vec x(x0.dim());
	nric::vec grad = nric::gradient(fun, x0);

	x = gradStep_->step(fun, x0, grad);
	int iter = 1;

	while (nric::norm(x - x0) >= prec)
	{
		x0 = x;
		grad = nric::gradient(fun, x0);
		x = gradStep_->step(fun, x0, grad);
		iter++;
	}

	double gradValue = nric::norm(nric::gradient(fun, x));

	return { x, fun(x), gradValue, iter };
}

void GradOpt::setGradStep(GradStep* gradStep)
{
	if (gradStep == nullptr)
		return;
	gradStep_ = gradStep;
}
