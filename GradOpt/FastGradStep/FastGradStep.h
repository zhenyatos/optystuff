#pragma once
#include "GradOpt.h"
#include "UniOpt.h"

class FastGradStep : public GradStep
{
private:
	const double MAX_STEP = 1000;
	UniOpt* opt_ = nullptr;
public:
	FastGradStep(UniOpt* opt);
	nric::vec step(nric::vecfun fun, nric::vec x, nric::vec grad) override;
};