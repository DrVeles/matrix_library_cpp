#include <gtest/gtest.h>

#include "s21_matrix_oop.h"

template <typename T>
void printType(const T& var) {
  std::cout << typeid(var).name() << std::endl;
}

int main() {
  std::cout << "HELLO world" << std::endl;

  return 0;
}