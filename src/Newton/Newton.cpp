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

Newton::Result Newton::optimize(nric::vecfun fun, nric::vec init, double prec)
{
	nric::vec& x0 = init;
	nric::vec x(x0.dim());

	nric::vec h = nric::solve(nric::hessian(fun, x0), nric::gradient(fun, x0));
	x = x0 - h;

	int iter = 1;
	while (nric::norm(x - x0) >= prec)
	{
		x0 = x;
		h = nric::solve(nric::hessian(fun, x0), nric::gradient(fun, x0));
		x = x0 - h;
		iter++;
	}

	double gradValue = nric::norm(nric::gradient(fun, x));
	return { x, fun(x), gradValue, iter };
}
