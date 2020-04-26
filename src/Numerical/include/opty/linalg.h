#pragma once
#include "vec.h"
#include "mat.h"

namespace nric
{
	/*
		LINEAR ALGEBRA: matrix x vector operation
		OR applying operator with matrix A to 
		vector b
	*/
	vec operator*(const mat& A, const vec& b);

	/*
		LINEAR ALGEBRA: matrix x matrix operation
		OR operators with matrices A and B composition
	*/
	mat operator*(const mat& A, const mat& B);

	/*
		LINEAR ALGEBRA: LDR-decomposition algorithm
		@param	A - matrix to decompose
		@return [L, D, R]
	*/
	std::tuple<mat, mat, mat> LDR(const mat& A);

	/*
		LINEAR ALGEBRA: solve system of a linear 
		equations with SQUARE matrix 
		@param	A - system matrix
		@param	b - right side
		@return solution vector
	*/
	vec solve(const mat& A, const vec& b);

	/*
		LINEAR ALGEBRA: dot product
		of a and b  vectors
	*/
	double operator*(const vec& a, const vec& b);
}