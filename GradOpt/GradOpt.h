#pragma once
#include "vecfun.h"

class GradStep
{
public:
	virtual nric::vec step(nric::vecfun fun, nric::vec x, nric::vec grad) = 0;
	virtual ~GradStep() { }
};

class GradOpt
{
private:
	GradStep* gradStep_;
public:
	GradOpt(GradStep* gradStep);
	nric::vec optimize(nric::vecfun fun, nric::vec init, double prec);
	nric::vec optimize(nric::vecfun fun, int dim, double prec);
};