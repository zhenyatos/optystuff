#pragma once
#include <functional>
#include <ostream>

class UniOpt
{
public:
	enum Method 
	{
		DICHOTOMY, FIBONACCI
	};

	struct Result
	{
		int functionCalls;
		double x;
		double y;
		double a;
		double b;

		friend std::ostream& operator<<(std::ostream& stream, const Result& res);
	};

	static UniOpt* get(Method method);

	virtual Result optimize(std::function<double(double)> fun, double prec, double a, double b) = 0;
	Result optimize(std::function<double(double)> fun, double prec);
protected:
	std::pair<double, double> findBorders(std::function<double(double)> fun);
};