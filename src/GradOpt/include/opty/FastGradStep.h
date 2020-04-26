#pragma once
#include "GradOpt.h"
#include "opty/UniOpt.h"

/*
	This class represents fastest descent
	step strategy for gradient method
*/
class FastGradStep : public GradStep
{
private:
	const double MAX_STEP = 1000;
	UniOpt* opt_ = nullptr;

public:
	enum error
	{
		NO_UNIMODAL_OPT		// You should specify unimodal optimizator
	};

	/*
		Strategy constructor
		@param opt - unimodal optimizer is used to find step coefficient
	*/
	explicit FastGradStep(UniOpt* opt = nullptr);

	/*
		Calculates next step with FASTEST DESCENT STRATEGY
		@param fun - function
		@param x - current step point
		@return next step point
	*/
	nric::vec step(nric::vecfun fun, nric::vec x) override;
};