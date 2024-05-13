#ifndef _S21_MATRIX_OOP_H_
#define _S21_MATRIX_OOP_H_

#include <iostream>

class S21Matrix {
 private:
  //====================== ATRIBUTES ==========================

  int rows_, cols_;
  double** matrix_;

 public:
  //========================= BAZE ============================

  // default matrix constructor
  S21Matrix();
  // square matrix constructor
  S21Matrix(int rows_cols);
  // regular matrix constructor
  S21Matrix(int rows, int cols);
  // copy constructor
  S21Matrix(const S21Matrix& other);
  // move constructor
  S21Matrix(S21Matrix&& other);
  // destructor
  ~S21Matrix();

  //================ ACCESSORS and MUTATORS ===================

  // getting rows from S21Matrix
  int getRows() const;

  // setting rows for S21Matrix
  void setRows(int rows);

  // getting cols from S21Matrix
  int getCols() const;

  // setting cols for S21Matrix
  void setCols(int cols);

  //==================== public METHODS =======================

  /**
   * @brief Check is equal matrix
   * @return `true` if equal, else `false`
   */
  bool EqMatrix(const S21Matrix& other);

  /**
   * @brief Adds the second matrix to the current one
   * @exception different matrix dimensions.
   */
  void SumMatrix(const S21Matrix& other);

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



  /**
   * @brief `+`	Addition of two matrices.	
   * @exception Different matrix dimensions.
   */ 
  S21Matrix operator+(const S21Matrix& other);

  /**
   * @brief `-` Subtraction of one matrix from another.
   * @exception Different matrix dimensions.
   */ 
  S21Matrix operator-(const S21Matrix& other);

  /**
   * @brief `*`	Matrix multiplication and matrix multiplication by a number.	
   * @exception The number of columns of the first matrix does not equal the number of rows of the second matrix.
   */ 
  S21Matrix operator*(const S21Matrix& other);

  /**
   * @brief `==` Checks for matrices equality (EqMatrix).
   */ 
  S21Matrix operator==(const S21Matrix& other);

  /**
   * @brief `=` S21Matrix& operator=(const S21Matrix& other);
   */ 
  S21Matrix& operator=(const S21Matrix& other);

  /**
   * @brief `+=`	Addition assignment (SumMatrix)
   * @exception 	Different matrix dimensions.
   */ 
  S21Matrix& operator+=(const S21Matrix& other);     

  /**
   * @brief `-=`	Addition assignment (SubMatrix)
   * @exception 	Different matrix dimensions.
   */ 
  S21Matrix& operator-=(const S21Matrix& other);     

  /**
   * @brief `*=`	Multiplication assignment (MulMatrix/MulNumber).
   * @exception 	The number of columns of the first matrix does not equal the number of rows of the second matrix.
   */ 
  S21Matrix& operator*=(const S21Matrix& other);   

  /**
   * @brief Indexation by matrix elements (row, column).
   * @param `i` row, `j` col
   * @return a link to an element with the index `[i][j]`
   * @exception Index is outside the matrix.
   */ 
  double& operator()(int i, int j); 

  //====================== My methods ===========================

  /**
   * @brief
   * @param
   * @return
   * @exception
   */ 
  void printS21Matrix(const S21Matrix& other);

};

#endif