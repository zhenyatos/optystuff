#pragma once
#include <functional>
#include <ostream>

namespace nric
{
	class vec 
	{
	private:
		double* vals_;
		int N_;

	public:
		vec(int N);
		vec(std::initializer_list<double> list);
		vec(const vec& other);
		vec& operator=(const vec& other);
		~vec();

		int dim() const;
		double& operator[](size_t index);
		double operator[](size_t index) const;

		vec& operator+=(const vec& other);
		vec& operator-=(const vec& other);
		vec& operator*=(double scale);

		friend vec operator+ (const vec& l, const vec& r);
		friend vec operator- (const vec& l, const vec& r);
		friend vec operator* (double scale, const vec& x);
	};

	double norm(nric::vec vec);

	using vecfun = std::function<double(vec)>;

	vecfun convert1d(std::function<double(double)> fun);

	vecfun convert2d(std::function<double(double, double)> fun);

	vecfun convert3d(std::function<double(double, double, double)> fun);
}

std::ostream& operator<<(std::ostream& stream, const nric::vec& x );