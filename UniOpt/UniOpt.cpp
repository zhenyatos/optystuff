#include "UniOpt.h"

std::ostream& operator<<(std::ostream& stream, const UniOpt::Result& res)
{
	stream << "X = [" << res.a << ", " << res.b << "]" <<
		"\nx: " << res.x <<
		"\ny: " << res.y <<
		"\nfunction called: " << res.functionCalls;
		
	return stream;
}

UniOpt::Result UniOpt::optimize(std::function<double(double)> fun, double prec)
{
	auto[a, b] = findBorders(fun);
	return optimize(fun, prec, a, b);
}

std::pair<double, double> UniOpt::findBorders(std::function<double (double)> fun)
{
	double x1 = 0;
	double x2 = 1;
	double x3;
	double h = 1;
	double temp;

	if (fun(x1) == fun(x2))
		return { x1, x2 };

	if (fun(x1) > fun(x2))
	{
		x3 = x2 + h;
		while (!(fun(x3) >= fun(x2)))
		{
			x1 = x2;
			x2 = x3;
			x3 = x3 + h;
			h *= 2;
		}
		return { x1, x3 };
	}

	if (fun(x1) < fun(x2))
	{
		temp = x1;
		x1 = x2;
		x2 = temp;
		x3 = x2 - h;
		while (!(fun(x2) <= fun(x3)))
		{
			x1 = x2;
			x2 = x3;
			x3 = x3 - h;
			h *= 2;
		}
		return { x3, x1 };
	}
}
