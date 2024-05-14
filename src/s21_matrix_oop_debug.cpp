#include "s21_matrix_oop.h"

int main() {
  S21Matrix a(2);
  a.setRows(1);
  a(0, 0) = 1;
  a(0, 1) = 2;

  S21Matrix b(2);
  b.setCols(1);
  b(0, 0) = 3;
  b(1, 0) = 4;

  a.MulMatrix(b);

  std::cout << a(0, 0) << std::endl;

  return 0;
}