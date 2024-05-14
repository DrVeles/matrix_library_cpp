#include <gtest/gtest.h>

#include "s21_matrix_oop.h"

//======================= STRESS ============================
// class StressTest : public ::testing::TestWithParam<int> {};

// TEST_P(StressTest, t) {
//   int size = GetParam();
//   S21Matrix matrix(size, size);
//   // Optionally, perform additional operations or checks on the matrix
// }

// INSTANTIATE_TEST_SUITE_P(stress_test, StressTest, ::testing::Range(1, 10));

//========================= BAZE ============================

TEST(test_constructors, test_1) { S21Matrix a(10); }
TEST(test_constructors, test_2) { S21Matrix a(1, 1); }
TEST(test_constructors, test_3) { ASSERT_ANY_THROW(S21Matrix a(1, 0)); }
TEST(test_constructors, test_4) { ASSERT_ANY_THROW(S21Matrix a(0, 1)); }
TEST(test_constructors, test_5) { ASSERT_ANY_THROW(S21Matrix a(0)); }
TEST(test_constructors, test_6_copy) {
  S21Matrix original(3, 3);
  original(0, 0) = 1.0;
  original(1, 1) = 2.0;
  original(2, 2) = 3.0;

  S21Matrix copy(original);

  ASSERT_EQ(copy(0, 0), original(0, 0));
  ASSERT_EQ(copy(1, 1), original(1, 1));
  ASSERT_EQ(copy(2, 2), original(2, 2));
  ASSERT_EQ(copy.getRows(), original.getRows());
  ASSERT_EQ(copy.getCols(), original.getCols());
}

TEST(test_constructors, test_7_move) {
  S21Matrix original(3, 3);
  original(0, 0) = 1.0;
  original(1, 1) = 2.0;
  original(2, 2) = 3.0;

  S21Matrix moved(std::move(original));

  ASSERT_EQ(moved(0, 0), 1.0);
  ASSERT_EQ(moved(1, 1), 2.0);
  ASSERT_EQ(moved(2, 2), 3.0);
  ASSERT_EQ(moved.getRows(), 3);
  ASSERT_EQ(moved.getCols(), 3);
  ASSERT_EQ(original.getRows(), 0);
  ASSERT_EQ(original.getCols(), 0);
}

TEST(test_constructors, test_8_move) {
  S21Matrix original(3, 3);

  S21Matrix moved(std::move(original));

  ASSERT_EQ(moved.getRows(), 3);
  ASSERT_EQ(moved.getCols(), 3);
  ASSERT_EQ(original.getRows(), 0);
  ASSERT_EQ(original.getCols(), 0);
}

TEST(test_constructors, test_9) { S21Matrix a; }
TEST(test_constructors, test_10) { S21Matrix a; }

//================ ACCESSORS and MUTATORS ===================

TEST(test_accessors_mutators, link_access) {
  S21Matrix a;
  double& link_a0_0 = a(0, 0);
  link_a0_0 = 1;
  S21Matrix b(a);
  ASSERT_EQ(a(0, 0), b(0, 0));
}

TEST(test_accessors_mutators, IncreaseRows) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 1.0;
  matrix(0, 1) = 2.0;
  matrix(1, 0) = 3.0;
  matrix(1, 1) = 4.0;

  matrix.setRows(4);

  EXPECT_EQ(matrix.getRows(), 4);
  EXPECT_EQ(matrix.getCols(), 2);
  EXPECT_EQ(matrix(0, 0), 1.0);
  EXPECT_EQ(matrix(0, 1), 2.0);
  EXPECT_EQ(matrix(1, 0), 3.0);
  EXPECT_EQ(matrix(1, 1), 4.0);
}

TEST(test_accessors_mutators, DecreaseRows) {
  S21Matrix matrix(3, 2);
  matrix(0, 0) = 1.0;
  matrix(0, 1) = 2.0;
  matrix(1, 0) = 3.0;
  matrix(1, 1) = 4.0;
  matrix(2, 0) = 5.0;
  matrix(2, 1) = 6.0;

  matrix.setRows(2);

  EXPECT_EQ(matrix.getRows(), 2);
  EXPECT_EQ(matrix.getCols(), 2);
  EXPECT_EQ(matrix(0, 0), 1.0);
  EXPECT_EQ(matrix(0, 1), 2.0);
  EXPECT_EQ(matrix(1, 0), 3.0);
  EXPECT_EQ(matrix(1, 1), 4.0);
}

TEST(test_accessors_mutators, SameRows) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 1.0;
  matrix(0, 1) = 2.0;
  matrix(1, 0) = 3.0;
  matrix(1, 1) = 4.0;

  matrix.setRows(2);

  EXPECT_EQ(matrix.getRows(), 2);
  EXPECT_EQ(matrix.getCols(), 2);
  EXPECT_EQ(matrix(0, 0), 1.0);
  EXPECT_EQ(matrix(0, 1), 2.0);
  EXPECT_EQ(matrix(1, 0), 3.0);
  EXPECT_EQ(matrix(1, 1), 4.0);
}

TEST(test_accessors_mutators, SameCols) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 1.0;
  matrix(0, 1) = 2.0;
  matrix(1, 0) = 3.0;
  matrix(1, 1) = 4.0;

  matrix.setCols(2);

  EXPECT_EQ(matrix.getRows(), 2);
  EXPECT_EQ(matrix.getCols(), 2);
  EXPECT_EQ(matrix(0, 0), 1.0);
  EXPECT_EQ(matrix(0, 1), 2.0);
  EXPECT_EQ(matrix(1, 0), 3.0);
  EXPECT_EQ(matrix(1, 1), 4.0);
}

TEST(test_accessors_mutators, ZeroRows) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 1.0;
  matrix(0, 1) = 2.0;
  matrix(1, 0) = 3.0;
  matrix(1, 1) = 4.0;
  ASSERT_ANY_THROW(matrix.setRows(0));
}

TEST(test_accessors_mutators, OneRow) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 1.0;
  matrix(0, 1) = 2.0;
  matrix(1, 0) = 3.0;
  matrix(1, 1) = 4.0;

  matrix.setRows(1);

  EXPECT_EQ(matrix.getRows(), 1);
  EXPECT_EQ(matrix.getCols(), 2);
  EXPECT_EQ(matrix(0, 0), 1.0);
  EXPECT_EQ(matrix(0, 1), 2.0);
}

TEST(test_accessors_mutators, OneCol) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 1.0;
  matrix(0, 1) = 2.0;
  matrix(1, 0) = 3.0;
  matrix(1, 1) = 4.0;

  matrix.setCols(1);

  EXPECT_EQ(matrix.getCols(), 1);
  EXPECT_EQ(matrix.getRows(), 2);
  EXPECT_EQ(matrix(0, 0), 1.0);
  EXPECT_EQ(matrix(1, 0), 3.0);
}

TEST(test_accessors_mutators, test_2) { S21Matrix a; }

//==================== public METHODS =======================

TEST(test_methods, equal_matrix) {
  S21Matrix a;
  S21Matrix b;

  EXPECT_TRUE(a.EqMatrix(b));
}

TEST(test_methods, equal_matrix_false) {
  S21Matrix a;
  S21Matrix b;
  b.setCols(2);

  EXPECT_FALSE(a.EqMatrix(b));
}

TEST(test_methods, equal_matrix_false_2) {
  S21Matrix a;
  S21Matrix b;
  a(0, 0) = 1;

  EXPECT_FALSE(a.EqMatrix(b));
}

TEST(test_methods, sum_matrix_1) {
  S21Matrix a;
  S21Matrix b;
  a(0, 0) = 1;
  b(0, 0) = 1;
  a.SumMatrix(b);
  ASSERT_EQ((a)(0, 0), 2.0);
}

TEST(test_methods, sum_matrix_2) {
  S21Matrix a;
  S21Matrix b;
  a(0, 0) = 1;
  b(0, 0) = 1;
  a.setCols(2);
  a(0, 1) = 1;
  b.setCols(2);
  a.SumMatrix(b);

  ASSERT_EQ(a(0, 0), 2.0);
  ASSERT_EQ(a(0, 1), 1.0);
}

TEST(test_methods, sum_matrix_3) {
  S21Matrix a;
  S21Matrix b(2);
  a(0, 0) = 1;
  b(0, 0) = 1;

  ASSERT_ANY_THROW(a.SumMatrix(b););
}

TEST(test_methods, sub_matrix_1) {
  S21Matrix a;
  S21Matrix b;
  a(0, 0) = 1;
  b(0, 0) = 2;
  a.SubMatrix(b);
  ASSERT_EQ((a)(0, 0), -1.0);
}

TEST(test_methods, sub_matrix_2) {
  S21Matrix a;
  S21Matrix b;
  a(0, 0) = 1;
  b(0, 0) = 1;
  a.setCols(2);
  b.setCols(2);
  b(0, 1) = 1;
  a.SubMatrix(b);

  ASSERT_EQ(a(0, 0), 0.0);
  ASSERT_EQ(a(0, 1), -1.0);
}

TEST(test_methods, sub_matrix_3) {
  S21Matrix a;
  S21Matrix b(2);
  a(0, 0) = 1;
  b(0, 0) = 1;

  ASSERT_ANY_THROW(a.SubMatrix(b););
}

// =================== OPERATORS overloads ====================

TEST(MatrixAccessTest, ValidIndices) {
  S21Matrix matrix(3, 3);  // Создаем матрицу 3x3

  // Заполняем матрицу значениями
  matrix(0, 0) = 1.0;
  matrix(0, 1) = 2.0;
  matrix(0, 2) = 3.0;
  matrix(1, 0) = 4.0;
  matrix(1, 1) = 5.0;
  matrix(1, 2) = 6.0;
  matrix(2, 0) = 7.0;
  matrix(2, 1) = 8.0;
  matrix(2, 2) = 9.0;

  // Проверяем корректность доступа к элементам
  EXPECT_EQ(matrix(0, 0), 1.0);
  EXPECT_EQ(matrix(0, 1), 2.0);
  EXPECT_EQ(matrix(0, 2), 3.0);
  EXPECT_EQ(matrix(1, 0), 4.0);
  EXPECT_EQ(matrix(1, 1), 5.0);
  EXPECT_EQ(matrix(1, 2), 6.0);
  EXPECT_EQ(matrix(2, 0), 7.0);
  EXPECT_EQ(matrix(2, 1), 8.0);
  EXPECT_EQ(matrix(2, 2), 9.0);
}

TEST(MatrixAccessTest, InvalidIndices) {
  S21Matrix matrix(3, 3);  // Создаем матрицу 3x3

  // Проверяем выброс исключений при некорректном доступе
  EXPECT_THROW(matrix(-1, 0), std::out_of_range);
  EXPECT_THROW(matrix(0, -1), std::out_of_range);
  EXPECT_THROW(matrix(3, 0), std::out_of_range);
  EXPECT_THROW(matrix(0, 3), std::out_of_range);
  EXPECT_THROW(matrix(3, 3), std::out_of_range);
}

TEST(test_operators, test_1_copy) {
  S21Matrix a(3);
  a(1, 1) = 1;
  const double& c = a(1, 1);
  S21Matrix b = a;
  ASSERT_EQ(a(1, 1), b(1, 1));
  ASSERT_EQ(a(1, 1), c);
}

TEST(test_operators, test_2_copy) {
  S21Matrix a(3);
  a(1, 1) = 1;
  S21Matrix b;
  b = a;
  ASSERT_EQ(a(1, 1), b(1, 1));
}

TEST(test_operators, test_3_bad_access) {
  S21Matrix a(3);
  ASSERT_ANY_THROW(a(1, 4) = 5);
}

TEST(test_operators, test_4_bad_access) {
  S21Matrix a;
  ASSERT_ANY_THROW(a(1, 0) = 5);
}

TEST(test_operators, equal_matrix) {
  S21Matrix a;
  S21Matrix b;

  EXPECT_TRUE(a == b);
}

TEST(test_operators, sum_matrix_1) {
  S21Matrix a;
  S21Matrix b;
  a(0, 0) = 1;
  b(0, 0) = 1;

  ASSERT_EQ((a += b)(0, 0), 2.0);
}

TEST(test_operators, sum_matrix_2) {
  S21Matrix a;
  S21Matrix b;
  a(0, 0) = 1;
  b(0, 0) = 1;
  a.setCols(2);
  a(0, 1) = 1;
  b.setCols(2);

  ASSERT_EQ((a += b)(0, 0), 2.0);
  ASSERT_EQ((a += b)(0, 1), 1.0);
}

TEST(test_operators, sum_matrix_3) {
  S21Matrix a;
  S21Matrix b;
  a(0, 0) = 1;
  b(0, 0) = 1;
  S21Matrix c;

  c = a + b;

  ASSERT_EQ(c(0, 0), 2.0);
  ASSERT_EQ(a(0, 0), 1.0);
  ASSERT_EQ(b(0, 0), 1.0);
}

TEST(test_operators, sub_matrix_1) {
  S21Matrix a;
  S21Matrix b;
  a(0, 0) = 3;
  b(0, 0) = 1;

  ASSERT_EQ((a -= b)(0, 0), 2.0);
}

TEST(test_operators, sub_matrix_2) {
  S21Matrix a;
  S21Matrix b;
  a(0, 0) = 1;
  b(0, 0) = 3;
  a.setCols(2);
  b.setCols(2);
  b(0, 1) = 1;

  ASSERT_EQ((a -= b)(0, 0), -2.0);
  ASSERT_EQ(a(0, 1), -1.0);
}

TEST(test_operators, sub_matrix_3) {
  S21Matrix a;
  S21Matrix b;
  a(0, 0) = 1;
  b(0, 0) = 11;
  S21Matrix c;

  c = a - b;

  ASSERT_EQ(c(0, 0), -10.0);
  ASSERT_EQ(a(0, 0), 1.0);
  ASSERT_EQ(b(0, 0), 11.0);
}

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}