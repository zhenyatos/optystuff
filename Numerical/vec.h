#pragma once
#include <functional>
#include <ostream>

namespace nric
{
	/*
		This class represents simple numerical computation
		vector (unresizeable)
	*/
	class vec 
	{
	private:
		double* vals_;
		int N_;

	public:
		explicit vec(int N);
		/*
			This constructor is used to initialize like:
			vec a = { 0, 1, 2 };
		*/
		vec(std::initializer_list<double> list);
		vec(const vec& other);
		vec& operator=(const vec& other);
		~vec();

		int dim() const;
		/*
			Part of nric::vec array-like behaviour 
			to set data
			a[0] = 1;
		*/
		double& operator[](size_t index);
		/*
			Part of nric::vec array-like behaviour
			to get data from const nric::vec
			double x = a[0];
		*/
		double operator[](size_t index) const;

		/*
			Part of nric::vec mathematical vector behaviour
		*/
		vec& operator+=(const vec& other);
		/*
			Part of nric::vec mathematical vector behaviour
		*/
		vec& operator-=(const vec& other);
		/*
			Part of nric::vec mathematical vector behaviour
		*/
		vec& operator*=(double scale);		

		/*
			Part of nric::vec mathematical vector behaviour
			[0 1 2] + [-1 -1 -1] = [-1 0 1] 
		*/
		friend vec operator+ (const vec& l, const vec& r);
		/*
			Part of nric::vec mathematical vector behaviour
			[0 2 1] - [1 3 1] = [-1 -1 0]
		*/
		friend vec operator- (const vec& l, const vec& r);
		/*
			Part of nric::vec mathematical vector behaviour
			2.5 * [0 1 -2] = [0 2.5 -5]
		*/
		friend vec operator* (double scale, const vec& x);
	};

	/*
		Calculates 2-norm (euclidean) of nric::vec
	*/
	double norm(nric::vec vec);

	using vecfun = std::function<double(vec)>;

	/*
		Syntactic sugar, can transform
		one variable function to nric::vecfun
	*/
	vecfun convert1d(std::function<double(double)> fun);
	/*
		Syntactic sugar, can transform
		two variable function to nric::vecfun
	*/
	vecfun convert2d(std::function<double(double, double)> fun);
	/*
		Syntactic sugar, can transform
		three variable function to nric::vecfun
	*/
	vecfun convert3d(std::function<double(double, double, double)> fun);
}

std::ostream& operator<<(std::ostream& stream, const nric::vec& x );