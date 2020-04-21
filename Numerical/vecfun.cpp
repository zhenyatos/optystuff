#include "vecfun.h"

namespace nric
{
	vecfun convert1d(std::function<double(double)> fun)
	{
		return [fun](vec x) { 
			if (x.dim() != 1) 
				throw WRONG_DIMENSION; 
			return fun(x[0]); };
	}

	vecfun convert2d(std::function<double(double, double)> fun)
	{
		return [fun](vec x) { 
			if (x.dim() != 2) 
				throw WRONG_DIMENSION;
			return fun(x[0], x[1]); };
	}

	vecfun convert3d(std::function<double(double, double, double)> fun)
	{
		return [fun](vec x) { 
			if (x.dim() != 3) 
				throw WRONG_DIMENSION; 
			return fun(x[0], x[1], x[2]); };
	}

	vec::vec(int N)
		: N_(N)
	{
		vals_ = new double[N_];
	}

	vec::vec(std::initializer_list<double> list)
		: N_(list.size())
	{
		vals_ = new double[N_];
		int i = 0;
		for (double t : list)
		{
			vals_[i] = t;
			i++;
		}
	}

	vec::vec(const vec& other)
		: N_(other.N_)
	{
		vals_ = new double[N_];
		for (int i = 0; i < N_; i++)
			vals_[i] = other.vals_[i];
	}

	vec& vec::operator=(const vec& other)
	{
		if (this->N_ != other.N_)
			throw WRONG_DIMENSION;

		for (int i = 0; i < N_; i++)
			vals_[i] = other.vals_[i];
		
		return *this;
	}

	vec::~vec()
	{
		delete[] vals_;
	}

	int vec::dim() const
	{
		return N_;
	}

	double& vec::operator[](size_t index)
	{
		return vals_[index];
	}

	double vec::operator[](size_t index) const
	{
		return vals_[index];
	}
}

std::ostream& operator<<(std::ostream& stream, const nric::vec& x)
{
	size_t N = x.dim();
	if (N == 0)
		return stream;
	stream << "[";
	for (size_t i = 0; i < (N - 1); i++)
		stream << x[i] << " ";
	stream << x[N - 1] << "]";
	return stream;
}