#pragma once
#include "vec.h"

namespace nric
{
	const double EPS = 0.000001;

	double derivative(std::function<double(double)> fun, double x, double eps = EPS);

	vec gradient(vecfun fun, vec x, double eps = EPS);
}