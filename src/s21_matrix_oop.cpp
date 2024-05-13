#include "s21_matrix_oop.h"

  S21Matrix::S21Matrix() {
		rows_ = 1; 
		cols_ = 1;
		matrix_ = new double*[rows_ * cols_]{};
  }
	S21Matrix::S21Matrix(int rows_cols) {
		if (rows_cols < 1) {
			throw std::excetion
		}
		rows_ = cols_ = rows_cols;
		matrix_ = new double*[rows_ * cols_]{};
  }

	S21Matrix::S21Matrix(int rows, int cols) {
		rows_ = rows;
		cols_ = cols;
		matrix_ = new double*[rows_ * cols_]{};
  }

  // copy constructor
	S21Matrix::S21Matrix(const S21Matrix& other);
  // move constructor
	S21Matrix::S21Matrix(S21Matrix&& other);
  // destructor
	S21Matrix::~S21Matrix() {
		if (matrix_) {
			deleteMatrix(matrix_);
		}
	}
