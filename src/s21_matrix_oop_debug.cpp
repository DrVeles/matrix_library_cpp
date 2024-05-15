#include "s21_matrix_oop.h"

int main() {
  S21Matrix matrix(1, 1);
  matrix(0, 0) = 5;

  S21Matrix expected(1, 1);
  expected(0, 0) = 1;

  S21Matrix result = matrix.CalcComplements();
  expected.printS21Matrix();
  std::cout << std::endl;
  matrix.printS21Matrix();
  std::cout << (result == expected) << std::endl;

  return 0;
}