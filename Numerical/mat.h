#pragma once
#include <initializer_list>
#include <ostream>

namespace nric
{
	class mat
	{
	private:
		double** vals_;
		int M_;
		int N_;
		double** initVals(int M, int N);

	public:
		mat(int N, int M);
		mat(std::initializer_list<std::initializer_list<double>> list);
		mat(const mat& other);
		mat& operator=(const mat& other);
		~mat();

		double& operator()(int i, int j);
		double operator()(int i, int j) const;
		int M() const;
		int N() const;
	};
}

std::ostream& operator<<(std::ostream& stream, const nric::mat& A);