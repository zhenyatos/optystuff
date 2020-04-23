#pragma once
#include "vec.h"

class GradStep
{
public:
	virtual nric::vec step(nric::vecfun fun, nric::vec x, nric::vec grad) = 0;
};

class GradOpt
{
private:
	GradStep* gradStep_ = nullptr;
public:
	struct Result
	{
		nric::vec x;
		double y;
		double grad;
		int iter;

		friend std::ostream& operator<<(std::ostream& stream, const Result& res);
	};

	GradOpt(GradStep* gradStep);
	
	Result optimize(nric::vecfun fun, nric::vec init, double prec);

	void setGradStep(GradStep* gradStep);
};