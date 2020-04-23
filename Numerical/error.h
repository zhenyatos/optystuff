namespace nric
{
	enum error 
	{ 
		WRONG_DIMENSION,		// Vector dimension is wrong for this operation
		DIFFERENT_ROW_NUM,		// Operands have different numbe of rows
		DIFFERENT_COL_NUM,		// Operands have different number of columns
		INVALID_MATRIX_MULT,	// Invalid operation (check for matrix dimensions)
		NOT_SQUARE_MATRIX,		// Matrix should be N x N
		NOT_INVERTIBLE			// Matrix can't be inversed
	};
}