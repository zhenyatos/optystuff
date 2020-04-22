#include "AdaptGradStep.h"

AdaptGradStep::AdaptGradStep(double delta, double epsilon)
{
	if (delta <= 0 || delta >= 1)
		delta_ = 0.5;
	else
		delta_ = delta;

	if (epsilon <= 0 || epsilon >= 1)
		epsilon_ = 0.5;
	else
		epsilon_ = epsilon;
}

nric::vec AdaptGradStep::step(nric::vecfun fun, nric::vec x, nric::vec grad)
{
	double a = 1;
	double temp = fun(x - a * grad) - fun(x);
	while (temp > -epsilon_ * a * nric::norm(grad) * nric::norm(grad))
	{
		a *= delta_;
		temp = fun(x - a * grad) - fun(x);
	}

	return x - a * grad;
}
