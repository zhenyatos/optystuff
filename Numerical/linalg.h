#pragma once
#include "vec.h"
#include "mat.h"

namespace nric
{
	vec operator*(const mat& A, const vec& b);
}