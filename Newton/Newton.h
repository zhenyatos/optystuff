#pragma once
#include "vec.h"

class Newton
{
public:
	struct Result
	{
		nric::vec x;
		double y;
		double grad;
		int iter;

		friend std::ostream& operator<<(std::ostream& stream, const Result& res);
	};

	Result optimize(nric::vecfun fun, nric::vec init, double prec);
};