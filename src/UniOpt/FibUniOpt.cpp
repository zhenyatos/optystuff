#include "opty/FibUniOpt.h"
#include <vector>

UniOpt::Result FibUniOpt::optimize(std::function<double(double)> fun, double prec, double a, double b)
{
	double a_ = a;
	double b_ = b;
	double x1, x2, x3;
	double y1, y2, y3;
	int funCalls = 0;
	fun = [&funCalls, fun](double x) { funCalls++; return fun(x); };
	std::vector<int> F;
	
	F.push_back(1);
	F.push_back(1);
	int N = 1;
	while ((b - a) / F[N] >= prec)
	{
		F.push_back(F[N] + F[N - 1]);
		N++;
	}
	
	x1 = a + (double(F[N-2]) / F[N]) * (b - a);
	x2 = a + (double(F[N-1]) / F[N]) * (b - a);
	y1 = fun(x1);
	y2 = fun(x2);

	for (int i = 2; i < N; i++)
	{ 
		if (y1 <= y2)
		{
			b = x2;
			x3 = a + (double(F[N-i-1]) / F[N]) * (b_ - a_);
			y3 = fun(x3);
			x2 = x1;
			y2 = y1;
			x1 = x3;
			y1 = y3;
		}
		else
		{
			a = x1;
			x3 = a + (double(F[N-i]) / F[N]) * (b_ - a_);
			y3 = fun(x3);
			x1 = x2;
			y1 = y2;
			x2 = x3;
			y2 = y3;
		}
	}
	
	return { funCalls, x3, y3, a_, b_ };
}