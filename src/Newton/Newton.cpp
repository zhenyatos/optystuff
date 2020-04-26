#include "opty/Newton.h"
#include "opty/linalg.h"
#include "opty/derivative.h"

std::ostream& operator<<(std::ostream& stream, const Newton::Result& res)
{
	stream << "x: " << res.x <<
		"\ny: " << res.y <<
		"\ngradient value: " << res.grad <<
		"\niterations: " << res.iter;
	return stream;
}

Newton::Newton(double delta, double epsilon)
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

Newton::Result Newton::optimize(nric::vecfun fun, nric::vec init, double prec)
{
	nric::vec& x0 = init;
	nric::vec x(x0.dim());

	nric::vec grad = nric::gradient(fun, x0);
	nric::vec h = nric::solve(nric::hessian(fun, x0), nric::gradient(fun, x0));
	
	double alpha = 1;
	while (fun(x0 - alpha * h) - fun(x0) > -epsilon_ * alpha * (grad * h))
		alpha *= delta_;
	x = x0 - alpha * h;

	int iter = 1;
	while (nric::norm(x - x0) >= prec)
	{
		x0 = x;
		grad = nric::gradient(fun, x0);
		h = nric::solve(nric::hessian(fun, x0), grad);
	
		alpha = 1;
		while (fun(x0 - alpha * h) - fun(x0) > -epsilon_ * alpha * (grad * h))
			alpha *= delta_;
		x = x0 - alpha * h;
		iter++;
	}

	double gradValue = nric::norm(nric::gradient(fun, x));
	return { x, fun(x), gradValue, iter };
}
