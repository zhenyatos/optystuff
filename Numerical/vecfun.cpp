#include "vecfun.h"

namespace nric
{
	vecfun convert1d(std::function<double(double)> fun)
	{
		return [fun](vec x) { return fun(x[0]); };
	}

	vecfun convert2d(std::function<double(double, double)> fun)
	{
		return [fun](vec x) { return fun(x[0], x[1]); };
	}

	vecfun convert3d(std::function<double(double, double, double)> fun)
	{
		return [fun](vec x) { return fun(x[0], x[1], x[2]); };
	}
}

std::ostream& operator<<(std::ostream& stream, const nric::vec& x)
{
	size_t N = x.size();
	if (N == 0)
		return stream;
	stream << "[";
	for (size_t i = 0; i < (N - 1); i++)
		stream << x[i] << " ";
	stream << x[N - 1] << "]";
	return stream;
}