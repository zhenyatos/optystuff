#include "UniOpt.h"

class FibUniOpt : public UniOpt
{
public:
	/*
		Solves minimization problem with FIBBONACCI METHOD
		@param fun - one variable function
		@param prec - precision
		@param a - left border of [a, b]
		@param b - left border of [a, b]
		@return solution
	*/
	Result optimize(std::function<double(double)> fun, double prec, double a, double b) override;
};