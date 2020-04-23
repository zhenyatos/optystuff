#pragma once
#include "vec.h"
#include "mat.h"

namespace nric
{
	const double EPS = 0.000001;	// Default epsilon value

	/*
		ANALYSIS: derivative calculation
		@param	fun - function of 1 variable
		@param	x - point
		@param	eps - sort of precision
		@return derivative value
	*/
	double derivative(std::function<double(double)> fun, double x, double eps = EPS);

	/*
		ANALYSIS: gradient calculation
		@param	fun - multivariable function
		@param	x - point
		@param	eps - sort of precision
		@return	gradient vector
	*/
	vec gradient(vecfun fun, vec x, double eps = EPS);

	/*
		ANALYSIS: hessian calculation
		@param	fun - multivariable function
		@param	x - point
		@param	eps - sort of precision
		@return	hessian matrix
	*/
	mat hessian(vecfun fun, vec x, double eps = EPS);
}