#pragma once
#include <functional>
#include <ostream>

/*
	This class represents unimodal function
	minimization on [a, b] interval problem solver, 
	to get concrete algorithm use form:
	UniOpt* opt = UniOpt::get(...)
	*/
class UniOpt
{
public:
	/* 
		Concrete unimodal optimization
		algorithm name to get with
		UniOpt::get(...)
	*/
	enum Method 
	{
		DICHOTOMY,	// Dichotomy method - less memory but more iterations need
		FIBONACCI	// Fibonnaci method - more memory but less iterations need
	};

	/*
		Result - solution of the optimization problem
	*/
	struct Result
	{
		int functionCalls;	// You can check performance with these
		double x;			// Solution point
		double y;			// Function minimum
		double a;			// Left border of [a, b]
		double b;			// Right border of [a, b]

		friend std::ostream& operator<<(std::ostream& stream, const Result& res);
	};

	/*
		Get concrete algorithm
		@param method - algorithm (or method) name
		@return pointer to UniOpt with this algorithm
	*/
	static UniOpt* get(Method method);

	/*
		Solves minimization problem
		@param fun - one variable function
		@param prec - precision
		@param a - left border of [a, b]
		@param b - left border of [a, b]
		@return solution
	*/
	virtual Result optimize(std::function<double(double)> fun, double prec, double a, double b) = 0;
	/*
		Solves minimization problem, but if borders are unknown
		@param fun - one variable function
		@param prec - precision
		@return solution
	*/
	Result optimize(std::function<double(double)> fun, double prec);
protected:
	/*
		Finding borders of an unimodal function
		@param fun - one variable function
		@return [a, b] - borders
	*/
	std::pair<double, double> findBorders(std::function<double(double)> fun);
};