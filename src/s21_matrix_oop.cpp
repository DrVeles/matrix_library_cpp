#include "s21_matrix_oop.h"

//========================= BAZE ============================

void S21Matrix::createMatrix(int rows, int cols) {
  if (rows < 1 or cols < 1) {
    throw std::length_error("Rows and cols must be greater than 0");
  }
  rows_ = rows;
  cols_ = cols;
  matrix_ = new double*[rows_];
  for (int i = 0; i < rows_; ++i) {
    matrix_[i] = new double[cols_]{};
  }
}

void S21Matrix::deleteMatrix() noexcept {
  for (int i = 0; i < rows_; i++) {
    delete[] matrix_[i];
  }
  delete[] matrix_;
  rows_ = 0;
  cols_ = 0;
}

S21Matrix::S21Matrix() { createMatrix(1, 1); }

S21Matrix::S21Matrix(int r_c) { createMatrix(r_c, r_c); }

S21Matrix::S21Matrix(int rows, int cols) { createMatrix(rows, cols); }

S21Matrix::S21Matrix(const S21Matrix& other) {
  this->createMatrix(other.cols_, other.rows_);
  for (int i = 0; i < cols_; i++) {
    for (int j = 0; j < rows_; j++) {
      this->matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

S21Matrix::S21Matrix(S21Matrix&& other) noexcept
    : rows_(other.rows_), cols_(other.cols_), matrix_(other.matrix_) {
  other.rows_ = 0;
  other.cols_ = 0;
  other.matrix_ = nullptr;
}

S21Matrix::~S21Matrix() { this->deleteMatrix(); }

//================ ACCESSORS and MUTATORS ===================

int S21Matrix::getRows() const { return rows_; }

int S21Matrix::getCols() const { return cols_; }
// setting rows for S21Matrix
void S21Matrix::setRows(int rows) { rows_ = rows; }

// setting cols for S21Matrix
void S21Matrix::setCols(int cols) { cols_ = cols; }

double& S21Matrix::operator()(int i, int j) {
  if (i < 0 or j < 0 or i >= rows_ or j >= cols_) {
    throw std::out_of_range("Matrix indices are out of range");
  }
  return matrix_[i][j];
}

void S21Matrix::printS21Matrix() const {
  if (matrix_ == nullptr) {
    std::cout << "NULL-matrix" << std::endl;
  } else {
    for (int i = 0; i < cols_; i++) {
      for (int j = 0; j < rows_; j++) {
        std::cout << matrix_[i][j] << ' ';
      }
      std::cout << std::endl;
    }
  }
}