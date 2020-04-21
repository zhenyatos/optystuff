#include "derivative.h"

namespace nric
{
	double derivative(std::function<double(double)> fun, double x, double eps)
	{
		double h;
		if (x == 0)
			h = eps;
		else
			h = sqrt(eps) * x;
		volatile double front = x + h;
		volatile double back = x - h;
		double dx = front - back;
		return (fun(front) - fun(back)) / dx;
	}

	vec gradient(vecfun fun, vec x, double eps)
	{
		int N = x.dim();
		vec res(N);
		double h;
		double t;
		double dx;
		double y1, y2;
		volatile double front;
		volatile double back;

		for (int i = 0; i < N; i++)
		{
			t = x[i];
			if (t == 0)
				h = eps;
			else
				h = sqrt(eps) * t;

			front = t + h;
			back = t - h;
			dx = front - back;

			try {
				x[i] = front;
				y1 = fun(x);
				x[i] = back;
				y2 = fun(x);
			}
			catch (error error)
			{
				if (error == WRONG_DIMENSION)
					return vec(1);
			}
			res[i] = (y1 - y2) / dx;

			x[i] = t;
		}

		return res;
	}
}