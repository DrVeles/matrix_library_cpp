# Matrix Library C++

Описание на русском [тут](./README_RUS.md)

In this project, I am implementing the `s21_matrix_oop.h` library for working with matrices in the likeness of [matrix_library_c](https://github.com/DrVeles/matrix_library_c ), but this time using an object-oriented approach (see materials). The object-oriented approach allows you to implement a library for working with matrices in the form of a separate class, on the objects of which operations are defined, represented by both methods and standard operators +, -, *, etc.

## Compilation and testing

`s21_matrix_oop.a` - build a clean library.

### Testing

`test` - run function tests.

`leaks` - check the tested code for leaks.

`gcov_report` - view the code test coverage.

## Operations

Below is a brief description of the operations on matrices that are implemented by the library. 

### Constructors and destructors

| Method | Description |
| ----------- | ----------- |
| `S21Matrix()` | A basic constructor initializing a matrix with some predefined dimension. |  
| `S21Matrix(int rows, int cols)` | Parameterized constructor with the number of rows and columns. | 
| `S21Matrix(const S21Matrix& other)` | The copy constructor. |
| `S21Matrix(S21Matrix&& other)` | The transfer constructor. |
| `~S21Matrix()` | The destructor. |

### Operations (methods)

| Operation | Description | Exceptional situations |
| ----------- | ----------- | ----------- |
| `bool EqMatrix(const S21Matrix& other)` | Checks the matrices for equality among themselves. |  |
| `void SumMatrix(const S21Matrix& other)` | Adds a second matrix to the current one | different matrix dimensions. |
| `void SubMatrix(const S21Matrix& other)` | Subtracts from the current matrix another | different dimension of the matrices. |
| `void MulNumber(const double num)` | Multiplies the current matrix by a number. |  |
| `void MulMatrix(const S21Matrix& other)` | Multiplies the current matrix by the second one. | the number of columns of the first matrix is not equal to the number of rows of the second matrix. |
| `S21Matrix Transpose()` | Creates a new transposed matrix from the current one and returns it. |  |
| `S21Matrix CalcComplements()` | Calculates the matrix of algebraic complements of the current matrix and returns it. | The matrix is not square. |
| `double Determinant()` | Calculates and returns the determinant of the current matrix. | The matrix is not square. |
| `S21Matrix InverseMatrix()` | Calculates and returns the inverse matrix. | The determinant of the matrix is 0. |


### Operator overloads

| Operator | Description | Exceptional situations |
| ----------- | ----------- | ----------- |
| `+`      | Addition of two matrices. | Different matrix dimensions. |
| `-`   | Subtraction of one matrix from another. | Different matrix dimensions. |
| `*`  | Matrix multiplication and matrix multiplication by a number. | The number of columns of the first matrix does not equal the number of rows of the second matrix. |
| `==`  | Checks for matrices equality (`EqMatrix`). | |
| `=`  | Assignment of values from one matrix to another one. | |
| `+=`  | Addition assignment (`SumMatrix`) | different matrix dimensions. |
| `-=`  | Difference assignment (`SubMatrix`) | different matrix dimensions. |
| `*=`  | Multiplication assignment (`MulMatrix`/`MulNumber`). | The number of columns of the first matrix does not equal the number of rows of the second matrix. |
| `(int i, int j)`  | Indexation by matrix elements (row, column). | Index is outside the matrix. |
