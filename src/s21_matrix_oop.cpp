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
void S21Matrix::setRows(int rows) {
  S21Matrix temp_matrix(rows, this->cols_);
  int smallest_rows = (rows < this->rows_) ? rows : this->rows_;

  for (int i = 0; i < smallest_rows; i++) {
    for (int j = 0; j < this->cols_; j++) {
      temp_matrix.matrix_[i][j] = this->matrix_[i][j];
    }
  }
  this->deleteMatrix();
  this->createMatrix(rows, temp_matrix.cols_);
  *this = temp_matrix;
}

// setting cols for S21Matrix
void S21Matrix::setCols(int cols) {
  S21Matrix temp_matrix(this->rows_, cols);
  int smallest_cols = (cols < this->cols_) ? cols : this->cols_;

  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < smallest_cols; j++) {
      temp_matrix.matrix_[i][j] = this->matrix_[i][j];
    }
  }

  this->deleteMatrix();
  this->createMatrix(temp_matrix.rows_, cols);
  *this = temp_matrix;
}

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
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        std::cout << matrix_[i][j] << ' ';
      }
      std::cout << std::endl;
    }
  }
}

//==================== public METHODS =======================

bool S21Matrix::EqMatrix(const S21Matrix& other) noexcept {
  if (this->rows_ == other.rows_ and this->cols_ == other.cols_) {
    for (int i = 0; i < other.rows_; i++) {
      for (int j = 0; j < other.cols_; j++) {
        if (this->matrix_[i][j] != other.matrix_[i][j]) {
          return false;
        }
      }
    }
  } else {
    return false;
  }
  return true;
}


void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (this->rows_ != other.rows_ or this->cols_ != other.cols_) {
    throw std::invalid_argument("Different matrix dimensions");
  }

  for (int i = 0; i < other.rows_; i++) {
    for (int j = 0; j < other.cols_; j++) {
      this->matrix_[i][j] += other.matrix_[i][j];
    }
  }
}

/**
 * @brief Subtracts another matrix from the current one
 * @exception different matrix dimensions.
 */
void SubMatrix(const S21Matrix& other);

// Multiplies the current matrix by a number.
void MulNumber(const double num);

/**
 * @brief Multiplies the current matrix by the second matrix.
 * @exception The number of columns of the first matrix is not equal to the
 * number of rows of the second matrix.
 */
void MulMatrix(const S21Matrix& other);

/**
 * @brief Creates a new transposed matrix from the current one and returns it.
 */
S21Matrix Transpose();

/**
 * @brief Calculates the algebraic addition matrix of the current one and
 * returns it.
 * @exception The matrix is not square.
 */
S21Matrix CalcComplements();

/**
 * @brief Calculates and returns the determinant of the current matrix.
 * @exception The matrix is not square.
 */
double Determinant();

/**
 * @brief Calculates and returns the inverse matrix.
 * @exception Matrix determinant is 0.
 */
S21Matrix InverseMatrix();

// =================== OPERATORS overloads ====================

S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
  this->deleteMatrix();
  this->createMatrix(other.rows_, other.cols_);

  for (int i = 0; i < other.rows_; i++) {
    for (int j = 0; j < other.cols_; j++) {
      this->matrix_[i][j] = other.matrix_[i][j];
    }
  }

  return *this;
}

S21Matrix S21Matrix::operator+(const S21Matrix& other) {
  S21Matrix temp(other);
  temp.SumMatrix(*this);
  return temp;
}

/**
 * @brief `-` Subtraction of one matrix from another.
 * @exception Different matrix dimensions.
 */
// S21Matrix S21Matrix::operator-(const S21Matrix& other) {}

/**
 * @brief `*`	Matrix multiplication and matrix multiplication by a number.
 * @exception The number of columns of the first matrix does not equal the
 * number of rows of the second matrix.
 */
// S21Matrix S21Matrix::operator*(const S21Matrix& other) {}

/**
 * @brief `==` Checks for matrices equality (EqMatrix).
 */
bool S21Matrix::operator==(const S21Matrix& other) {
  return this->EqMatrix(other);
}

S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {
  SumMatrix(other);
  return *this;
}

/**
 * @brief `-=`	Addition assignment (SubMatrix)
 * @exception 	Different matrix dimensions.
 */
// S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {}

/**
 * @brief `*=`	Multiplication assignment (MulMatrix/MulNumber).
 * @exception 	The number of columns of the first matrix does not equal
 * the number of rows of the second matrix.
 */
// S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {}
