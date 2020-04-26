#pragma once
#include "opty/vec.h"

/*
	This class represents Newtons method
	(gradient 2nd order algorithm) with adaptive step
	for multivariable function minimization
*/
class Newton
{
private:
	double delta_;		// Step coefficient multiplies by this value
	double epsilon_;	// Use in exit condition to make it stronger or weaker
public:
	/*
		Method constructor
		@param delta - step coefficient multiplies by this value, between 0 and 1
		@param epsilon - used in adaptive step exit condition, between 0 and 1
	*/
	explicit Newton(double delta = 0.5, double epsilon = 0.5);

	/*
		Solution of the multivariable 
		function minimization problem
	*/
	struct Result
	{
		nric::vec x;		// Solution point
		double y;			// Function minimum
		double grad;		// Gradient value (2-norm)
		int iter;			// Number of iterations, check perfomance with these

		friend std::ostream& operator<<(std::ostream& stream, const Result& res);
	};

	/*
		Solves minimization problem for multivariable function
		@param fun - function
		@param init - starting point
		@param prec - sort of precision
		@return solution
	*/
	Result optimize(nric::vecfun fun, nric::vec init, double prec);
};