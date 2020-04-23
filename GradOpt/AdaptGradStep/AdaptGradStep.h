#pragma once
#include "GradOpt.h"

/*
	This class represents adaptive
	step strategy for gradient method
*/
class AdaptGradStep : public GradStep
{
private:
	double delta_;		// Step coefficient multiplies by this value
	double epsilon_;	// Use in exit condition to make it stronger or weaker
public:
	AdaptGradStep(double delta = 0.5, double epsilon = 0.5);

	/*
		Calculates next step
		@param fun - function
		@param x - current step point
		@return next step point
	*/
	nric::vec step(nric::vecfun fun, nric::vec x) override;
};