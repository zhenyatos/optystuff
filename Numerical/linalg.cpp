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
}