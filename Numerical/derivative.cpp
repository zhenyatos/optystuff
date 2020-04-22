#include "derivative.h"
#include "error.h"

namespace nric
{
	double delta(double x, double eps) 
	{
		double h;
		if (x == 0)
			h = eps;
		else
			h = sqrt(eps) * x;
		return h;
	}

	double derivative(std::function<double(double)> fun, double x, double eps)
	{
		double h;
		h = delta(x, eps);
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
			h = delta(t, eps);

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

	mat hessian(vecfun fun, vec x, double eps)
	{
		int N = x.dim();
		mat H(N, N);
		double h1, h2;
		vec temp(N);
		double y1, y2, y3, y4;

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
			{
				if (i == j)
				{
					h1 = h2 = delta(x[i], eps);

					temp = x;
					temp[i] += 2 * h1;
					y1 = fun(temp);

					y2 = y3 = fun(x);

					temp[i] = x[i];
					temp[i] -= 2 * h1;
					y4 = fun(temp);
				}
				else
				{
					h1 = delta(x[i], eps);
					h2 = delta(x[j], eps);

					temp = x;
					temp[i] += h1;
					temp[j] += h2;
					y1 = fun(temp);

					temp[i] = x[i];
					temp[j] = x[j];
					temp[i] += h1;
					temp[j] -= h2;
					y2 = fun(temp);

					temp[i] = x[i];
					temp[j] = x[j];
					temp[i] -= h1;
					temp[j] += h2;
					y3 = fun(temp);

					temp[i] = x[i];
					temp[j] = x[j];
					temp[i] -= h1;
					temp[j] -= h2;
					y4 = fun(temp);
				}

				H(i, j) = (y1 - y2 - y3 + y4) / (4 * h1 * h2);
			}

		return H;
	}
}