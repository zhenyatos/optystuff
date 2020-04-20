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
		int N = x.size();
		vec res(N);
		double h;
		double t;
		double dx;
		double y1, y2;
		vec tempX = x;
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

			tempX[i] = front;
			y1 = fun(tempX);
			tempX[i] = back;
			y2 = fun(tempX);
			res[i] = (y2 - y1) / dx;

			tempX[i] = x[i];
		}

		return res;
	}
}