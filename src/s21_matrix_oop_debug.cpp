#include "s21_matrix_oop.h"

int main() {
  S21Matrix a(2);
  a(0, 0) = 1;
  a(0, 1) = 2;
  a(1, 0) = 3;
  a(1, 1) = 4;
  a.setCols(3);

  a.printS21Matrix();

  a = a.Transpose();

  a.Transpose();

  std::cout << std::endl;
  a.printS21Matrix();
  std::cout << std::endl;

  return 0;
}