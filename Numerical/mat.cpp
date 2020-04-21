#include "mat.h"
#include "error.h"

namespace nric
{
	double** mat::initVals(int M, int N)
	{
		double** vals;
		vals = new double*[M];
		for (int i = 0; i < M; i++)
			vals[i] = new double[N];

		return vals;
	}

	nric::mat::mat(int M, int N)
		: M_(M), N_(N)
	{
		vals_ = initVals(M_, N_);
	}

	mat::mat(std::initializer_list<std::initializer_list<double>> list)
	{
		int rowNum = list.size();
		int colNum = (list.begin())->size();
		for (auto row : list)
			if (row.size() > colNum)
				colNum = row.size();

		M_ = rowNum;
		N_ = colNum;
		vals_ = initVals(M_, N_);

		int i = 0;
		for (auto row : list)
		{
			int j = 0;
			for (auto col : row)
			{
				vals_[i][j] = col;
				j++;
			}
			i++;
		}
	}

	mat::mat(const mat& other)
		: M_(other.M_), N_(other.N_)
	{
		vals_ = initVals(M_, N_);

		for (int i = 0; i < M_; i++)
			for (int j = 0; j < N_; j++)
				vals_[i][j] = other.vals_[i][j];
	}

	mat& mat::operator=(const mat& other)
	{
		if (M_ != other.M_)
			throw DIFFERENT_ROWNUM;
		if (N_ != other.N_)
			throw DIFFERENT_COLNUM;

		for (int i = 0; i < M_; i++)
			for (int j = 0; j < N_; j++)
				vals_[i][j] = other.vals_[i][j];
	}

	nric::mat::~mat()
	{
		for (int i = 0; i < M_; i++)
			delete[] vals_[i];
		delete[] vals_;
	}

	double& mat::operator()(int i, int j)
	{
		return vals_[i][j];
	}

	double mat::operator()(int i, int j) const
	{
		return vals_[i][j];
	}
}