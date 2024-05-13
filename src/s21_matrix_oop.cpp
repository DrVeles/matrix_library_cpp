#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() {
  rows_ = 1;
  cols_ = 1;
  matrix_ = new double* [rows_ * cols_] {};
}
S21Matrix::S21Matrix(int rows_cols) {
  if (rows_cols < 1) {
    throw std::length_error("Rows and cols must be greater than 0");
  }
  rows_ = cols_ = rows_cols;
  matrix_ = new double* [rows_ * cols_] {};
}

S21Matrix::S21Matrix(int rows, int cols) {
  if (rows < 1 or cols < 1) {
    throw std::length_error("Rows and cols must be greater than 0");
  }
  rows_ = rows;
  cols_ = cols;
  matrix_ = new double* [rows_ * cols_] {};
}

S21Matrix::S21Matrix(const S21Matrix& other) {
  cols_ = other.cols_;
  rows_ = other.rows_;
  matrix_ = other.matrix_;
}
S21Matrix::S21Matrix(S21Matrix&& other) {
  cols_ = other.cols_;
  rows_ = other.rows_;
  matrix_ = other.matrix_;

  other.rows_ = other.cols_ = 0;
  other.matrix_ = nullptr;
}

S21Matrix::~S21Matrix() {
  if (matrix_) {
    delete[] matrix_;
    rows_ = cols_ = 0;
  }
}
