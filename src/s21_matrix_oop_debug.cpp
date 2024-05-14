#include "s21_matrix_oop.h"

int main() {
  S21Matrix a(3, 3);
  a(1, 1) = 1;
  S21Matrix b(std::move(a));

  a.printS21Matrix();
  std::cout << std::endl;
  b.printS21Matrix();
  (&a)->~S21Matrix();
  (&a)->~S21Matrix();
  (&a)->~S21Matrix();
  (&a)->~S21Matrix();
  (&a)->~S21Matrix();
  (&a)->~S21Matrix();
  (&a)->~S21Matrix();
  (&a)->~S21Matrix();
  (&a)->~S21Matrix();
  (&a)->~S21Matrix();
  (&a)->~S21Matrix();
  (&a)->~S21Matrix();
  (&a)->~S21Matrix();
  (&a)->~S21Matrix();
  (&a)->~S21Matrix();
  (&a)->~S21Matrix();
  return 0;
}