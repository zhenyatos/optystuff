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
	/*
		Strategy constructor
		@param delta - step coefficient multiplies by this value, between 0 and 1
		@param epsilon - used in adaptive step exit condition, between 0 and 1
	*/
	explicit AdaptGradStep(double delta = 0.5, double epsilon = 0.5);
	
	/*
		Calculates next step with ADAPTIVE STRATEGY
		@param fun - function
		@param x - current step point
		@return next step point
	*/
	nric::vec step(nric::vecfun fun, nric::vec x) override;
};