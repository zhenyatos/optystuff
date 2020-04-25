#pragma once
#include <initializer_list>
#include <ostream>

namespace nric
{
	/*
		This class represents simple numerical computation
		matrix (unresizeable)
	*/
	class mat
	{
	private:
		double** vals_;
		int M_;
		int N_;
		double** initVals(int M, int N);

	public:
		/*
			Basic constructor
			@param	M - number of rows
			@param	N - number of columns
		*/
		explicit mat(int N, int M);
		/*
			This constructor is used to initialize like:
			mat E = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
		*/
		mat(std::initializer_list<std::initializer_list<double>> list);
		mat(const mat& other);
		mat& operator=(const mat& other);
		~mat();

		/*
			Part of nric::mat matrix-like behaviour
			to set data
		*/
		double& operator()(int i, int j);
		/*
			Part of nric::mat matrix-like behaviour
			to get data from const nric::mat
			double x = E(0, 1);
		*/
		double operator()(int i, int j) const;
		int M() const;
		int N() const;
	};
}

std::ostream& operator<<(std::ostream& stream, const nric::mat& A);