#pragma once
#include "vec.h"
#include "mat.h"

namespace nric
{
	vec operator*(const mat& A, const vec& b);

	mat operator*(const mat& A, const mat& B);

	std::tuple<mat, mat, mat> LDR(const mat& A);

	vec solve(const mat& A, const vec& b);
}