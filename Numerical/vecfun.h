#pragma once
#include <vector>
#include <functional>
#include <ostream>

namespace nric
{
	using vec = std::vector<double>;
	using vecfun = std::function<double(vec)>;

	vecfun convert1d(std::function<double(double)> fun);

	vecfun convert2d(std::function<double(double, double)> fun);

	vecfun convert3d(std::function<double(double, double, double)> fun);
}

std::ostream& operator<<(std::ostream& stream, const nric::vec& x );