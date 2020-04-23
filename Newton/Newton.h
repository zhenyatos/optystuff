#pragma once
#include "vec.h"

/*
	This class represents Newtons method
	(gradient 2nd order algorithm)
	for multivariable function minimization
*/
class Newton
{
public:
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