#include "opty/DihUniOpt.h"

UniOpt::Result DihUniOpt::optimize(std::function<double(double)> fun, double prec, double a, double b)
{
	double a_ = a;
	double b_ = b;
	double delta = prec / 10;
	double x, x1, x2;
	double y;
	int funCalls = 0;
	fun = [&funCalls, fun](double x) { funCalls++;  return fun(x); };

	while ((b - a) >= prec)
	{
		x = (a + b) / 2;
		x1 = x - delta;
		x2 = x + delta;
		if (fun(x1) <= fun(x2))
			b = x2;
		else
			a = x1;
	}

	x = (a + b) / 2;
	y = fun(x);
	return { funCalls, x, y, a_, b_ };
}