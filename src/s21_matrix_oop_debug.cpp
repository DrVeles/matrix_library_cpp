#include "s21_matrix_oop.h"

int main() {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 1.0;
  matrix(0, 1) = 2.0;
  matrix(1, 0) = 3.0;
  matrix(1, 1) = 4.0;
  matrix.printS21Matrix();

  matrix.setRows(4);

  std::cout << std::endl;
  matrix.printS21Matrix();

  return 0;
}