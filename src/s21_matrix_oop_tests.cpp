#include <gtest/gtest.h>

#include "s21_matrix_oop.h"

TEST(test_constructor, test_0) { S21Matrix a(10); }
TEST(test_constructor, test_1) { S21Matrix a; }
TEST(test_constructor, test_2) { S21Matrix a(1, 1); }
TEST(test_constructor, test_3) { ASSERT_ANY_THROW(S21Matrix a(1, 0)); }
TEST(test_constructor, test_4) { ASSERT_ANY_THROW(S21Matrix a(0, 1)); }
TEST(test_constructor, test_5) { ASSERT_ANY_THROW(S21Matrix a(0)); }

TEST(test_destructor, test_1) { S21Matrix a; }

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}