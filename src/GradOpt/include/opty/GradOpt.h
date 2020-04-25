#pragma once
#include "opty/vec.h"

/*
	This class represents next-step strategy
	for gradient descent method,
	to get concrete strategy create it and add
	AdaptGradStep gradStep;
	GradOpt opt(&gradStep);
*/
class GradStep
{
public:
	/*
		Calculates next step
		@param fun - function
		@param x - current step point
		@return next step point
	*/
	virtual nric::vec step(nric::vecfun fun, nric::vec x) = 0;
};

/*
	This class represents gradient descent method
	(gradient 1nd order algorithm)
	for multivariable function minimization
*/
class GradOpt
{
private:
	GradStep* gradStep_ = nullptr;
public:
	/*
		Solution of the multivariable 
		function minimization problem
	*/
	struct Result
	{
		nric::vec x;	// Solution point
		double y;		// Function minimum
		double grad;	// Gradient value (2-norm)
		int iter;		// Number of iterations, check perfomance with these

		friend std::ostream& operator<<(std::ostream& stream, const Result& res);
	};

	enum error
	{
		NO_GRADSTEP		// You should specify GradStep
	};

	/*
		Basic constructor
	*/
	GradOpt(GradStep* gradStep = nullptr);
	
	/*
		Solves minimization problem for multivariable function
		@param fun - function
		@param init - starting point
		@param prec - sort of precision
		@return solution
	*/
	Result optimize(nric::vecfun fun, nric::vec init, double prec);

	void setGradStep(GradStep* gradStep);
};