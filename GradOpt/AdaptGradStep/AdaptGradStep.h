#pragma once
#include "GradOpt.h"

class AdaptGradStep : public GradStep
{
private:
	double delta_;
	double epsilon_;
public:
	AdaptGradStep(double delta = 0.5, double epsilon = 0.5);
	nric::vec step(nric::vecfun fun, nric::vec x, nric::vec grad) override;
};