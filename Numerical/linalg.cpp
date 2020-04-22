#include "linalg.h"
#include "error.h"

namespace nric
{
	vec operator*(const mat& A, const vec& b)
	{
		if (A.N() != b.dim())
			throw INVALID_MATRIX_MULT;

		int M = A.M();
		int N = A.N();
		vec res(M);

		for (int i = 0; i < M; i++)
		{
			res[i] = 0;
			for (int k = 0; k < N; k++)
				res[i] += (A(i, k) * b[k]);
		}

		return res;
	}

	mat operator*(const mat& A, const mat& B)
	{
		if (A.N() != B.M())
			throw INVALID_MATRIX_MULT;

		int M = A.M();
		int K = A.N();
		int N = B.N();
		mat C(M, N);

		for (int i = 0; i < M; i++)
			for (int j = 0; j < N; j++)
			{
				C(i, j) = 0;
				for (int k = 0; k < K; k++)
					C(i, j) += A(i, k) * B(k, j);
			}

		return C;
	}

	std::tuple<mat, mat, mat> LDR(const mat& A) 
	{
		if (A.M() != A.N())
			throw NOT_SQUARE_MATRIX;

		int N = A.N();
		double temp;
		mat L(N,N), D(N,N), R(N,N);

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
			{
				D(i, j) = 0;
				if (i == j)
				{
					L(i, j) = 1;
					R(i, j) = 1;
				}
				else
				{
					L(i, j) = 0;
					R(i, j) = 0;
				}
			}

		for (int i = 0; i < N; i++)
		{
			temp = 0;
			for (int k = 0; k < i; k++)
				temp += L(i, k) * D(k, k) * R(k, i);
			D(i, i) = A(i, i) - temp;

			if (D(i, i) == 0)
				throw NOT_INVERTIBLE;

			for (int j = i+1; j < N; j++)
			{
				temp = 0;
				for (int k = 0; k < i; k++)
					temp += L(i, k) * D(k, k) * R(k, j);
				R(i, j) = (A(i, j) - temp) / D(i, i);
				
				temp = 0;
				for (int k = 0; k < i; k++)
					temp += L(j, k) * D(k, k) * R(k, i);
				L(j, i) = (A(j, i) - temp) / D(i, i);
			}
		}

		return { L, D, R };
	}

	vec solve(const mat& A, const vec& b)
	{
		return vec(1);
	}
}