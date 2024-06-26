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

TEST(test_accessors_mutators, increase_rows) {
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

TEST(test_accessors_mutators, decrease_rows) {
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

TEST(test_accessors_mutators, zero_rows) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 1.0;
  matrix(0, 1) = 2.0;
  matrix(1, 0) = 3.0;
  matrix(1, 1) = 4.0;
  ASSERT_ANY_THROW(matrix.setRows(0));
}

TEST(test_accessors_mutators, one_rows) {
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

TEST(test_accessors_mutators, one_cols) {
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

TEST(test_methods, mult_matrix_num) {
  S21Matrix a(2);
  a(0, 0) = 1;
  a(1, 1) = 2;
  double num = 1.1;
  a.MulNumber(num);

  ASSERT_EQ(a(0, 0), 1.1);
  ASSERT_EQ(a(1, 1), 2.2);
}

TEST(test_methods, mult_matrix_matrix) {
  S21Matrix a(2);
  a.setRows(1);
  a(0, 0) = 1;
  a(0, 1) = 2;

  S21Matrix b(2);
  b.setCols(1);
  b(0, 0) = 3;
  b(1, 0) = 4;

  a.MulMatrix(b);

  ASSERT_EQ(a(0, 0), 11);
  ASSERT_EQ(a.getCols(), 1);
  ASSERT_EQ(a.getRows(), 1);
}

TEST(test_methods, mult_matrix_matrix_exc) {
  S21Matrix a(2);
  a.setRows(1);
  a(0, 0) = 1;
  a(0, 1) = 2;

  S21Matrix b(3);
  b(0, 0) = 3;
  b(1, 0) = 4;

  ASSERT_ANY_THROW(a.MulMatrix(b));
}

TEST(test_methods, transpose_1) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 1.0;
  matrix(0, 1) = 2.0;
  matrix(1, 0) = 3.0;
  matrix(1, 1) = 4.0;

  matrix = matrix.Transpose();

  EXPECT_EQ(matrix.getCols(), 2);
  EXPECT_EQ(matrix.getRows(), 2);
  EXPECT_EQ(matrix(0, 0), 1.0);
  EXPECT_EQ(matrix(0, 1), 3.0);
  EXPECT_EQ(matrix(1, 0), 2.0);
  EXPECT_EQ(matrix(1, 1), 4.0);
}

TEST(test_methods, transpose_2) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 1.0;
  matrix(0, 1) = 2.0;
  matrix(1, 0) = 3.0;
  matrix(1, 1) = 4.0;
  matrix.setCols(3);

  matrix = matrix.Transpose();

  EXPECT_EQ(matrix.getCols(), 2);
  EXPECT_EQ(matrix.getRows(), 3);
  EXPECT_EQ(matrix(0, 0), 1.0);
  EXPECT_EQ(matrix(0, 1), 3.0);
  EXPECT_EQ(matrix(1, 0), 2.0);
  EXPECT_EQ(matrix(1, 1), 4.0);
  EXPECT_EQ(matrix(2, 0), 0.0);
  EXPECT_EQ(matrix(2, 1), 0.0);
}

TEST(test_methods, determinant_1) {
  S21Matrix matrix(3, 3);
  EXPECT_EQ(matrix.Determinant(), 0);
}

TEST(test_methods, determinant_2) {
  S21Matrix matrix(3, 3);
  for (int i = 0; i < 3; ++i) {
    matrix(i, i) = 1;
  }
  EXPECT_EQ(matrix.Determinant(), 1);
}

TEST(test_methods, determinant_3) {
  S21Matrix matrix(3, 3);
  matrix(0, 0) = 1;
  matrix(0, 1) = 2;
  matrix(0, 2) = 3;
  matrix(1, 0) = 4;
  matrix(1, 1) = 5;
  matrix(1, 2) = 6;
  matrix(2, 0) = 7;
  matrix(2, 1) = 8;
  matrix(2, 2) = 9;
  EXPECT_EQ(matrix.Determinant(), 0);
}

TEST(test_methods, determinant_4) {
  S21Matrix matrix(3, 3);
  matrix(0, 0) = 1;
  matrix(0, 1) = 2;
  matrix(0, 2) = 3;
  matrix(1, 0) = 0;
  matrix(1, 1) = 4;
  matrix(1, 2) = 5;
  matrix(2, 0) = 1;
  matrix(2, 1) = 0;
  matrix(2, 2) = 6;
  EXPECT_NEAR(matrix.Determinant(), 22, 1e-9);
}

TEST(test_methods, determinant_5) {
  S21Matrix matrix(4, 4);
  matrix(0, 0) = 1;
  matrix(0, 1) = 0;
  matrix(0, 2) = 2;
  matrix(0, 3) = -1;
  matrix(1, 0) = 3;
  matrix(1, 1) = 0;
  matrix(1, 2) = 0;
  matrix(1, 3) = 5;
  matrix(2, 0) = 2;
  matrix(2, 1) = 1;
  matrix(2, 2) = 4;
  matrix(2, 3) = -3;
  matrix(3, 0) = 1;
  matrix(3, 1) = 0;
  matrix(3, 2) = 5;
  matrix(3, 3) = 0;
  EXPECT_NEAR(matrix.Determinant(), 30, 1e-9);
}

TEST(test_methods, determinant_6_exc) {
  S21Matrix matrix(2, 3);
  matrix(0, 0) = 1;
  matrix(0, 1) = 2;
  matrix(0, 2) = 3;
  matrix(1, 0) = 4;
  matrix(1, 1) = 5;
  matrix(1, 2) = 6;
  EXPECT_THROW(matrix.Determinant(), std::logic_error);
}

TEST(test_methods, cal_components_1) {
  S21Matrix matrix(3, 3);

  matrix(0, 0) = 1;
  matrix(0, 1) = 2;
  matrix(0, 2) = 3;
  matrix(1, 0) = 0;
  matrix(1, 1) = 4;
  matrix(1, 2) = 5;
  matrix(2, 0) = 1;
  matrix(2, 1) = 0;
  matrix(2, 2) = 6;

  S21Matrix expected(3, 3);
  expected(0, 0) = 24;
  expected(0, 1) = 5;
  expected(0, 2) = -4;
  expected(1, 0) = -12;
  expected(1, 1) = 3;
  expected(1, 2) = 2;
  expected(2, 0) = -2;
  expected(2, 1) = -5;
  expected(2, 2) = 4;

  S21Matrix result = matrix.CalcComplements();
  ASSERT_TRUE(result == expected);
}

TEST(test_methods, cal_components_2) {
  S21Matrix matrix(2, 2);

  matrix(0, 0) = 4;
  matrix(0, 1) = 3;
  matrix(1, 0) = 3;
  matrix(1, 1) = 2;

  S21Matrix expected(2, 2);
  expected(0, 0) = 2;
  expected(0, 1) = -3;
  expected(1, 0) = -3;
  expected(1, 1) = 4;

  S21Matrix result = matrix.CalcComplements();
  ASSERT_TRUE(result == expected);
}

TEST(test_methods, cal_components_3) {
  S21Matrix matrix(1, 1);
  matrix(0, 0) = 5;

  S21Matrix expected(1, 1);
  expected(0, 0) = 1;

  S21Matrix result = matrix.CalcComplements();
  ASSERT_TRUE(result == expected);
}

TEST(test_methods, cal_components_4) {
  S21Matrix matrix(2, 3);
  matrix(0, 0) = 1;
  matrix(0, 1) = 2;
  matrix(0, 2) = 3;
  matrix(1, 0) = 4;
  matrix(1, 1) = 5;
  matrix(1, 2) = 6;

  EXPECT_THROW(matrix.CalcComplements(), std::invalid_argument);
}

TEST(test_methods, minor_1) {
  S21Matrix matrix(3, 3);
  S21Matrix expected_minor(2, 2);

  matrix(0, 0) = 1;
  matrix(0, 1) = 2;
  matrix(0, 2) = 3;
  matrix(1, 0) = 4;
  matrix(1, 1) = 5;
  matrix(1, 2) = 6;
  matrix(2, 0) = 7;
  matrix(2, 1) = 8;
  matrix(2, 2) = 9;

  expected_minor(0, 0) = 4;
  expected_minor(0, 1) = 6;
  expected_minor(1, 0) = 7;
  expected_minor(1, 1) = 9;

  S21Matrix minor = matrix.Minor(0, 1);

  ASSERT_TRUE(minor == expected_minor);
}

TEST(test_methods, minor_2) {
  S21Matrix matrix(4, 4);
  S21Matrix expected_minor(3, 3);

  matrix(0, 0) = 1;
  matrix(0, 1) = 2;
  matrix(0, 2) = 3;
  matrix(0, 3) = 4;
  matrix(1, 0) = 5;
  matrix(1, 1) = 6;
  matrix(1, 2) = 7;
  matrix(1, 3) = 8;
  matrix(2, 0) = 9;
  matrix(2, 1) = 10;
  matrix(2, 2) = 11;
  matrix(2, 3) = 12;
  matrix(3, 0) = 13;
  matrix(3, 1) = 14;
  matrix(3, 2) = 15;
  matrix(3, 3) = 16;

  expected_minor(0, 0) = 1;
  expected_minor(0, 1) = 2;
  expected_minor(0, 2) = 4;
  expected_minor(1, 0) = 9;
  expected_minor(1, 1) = 10;
  expected_minor(1, 2) = 12;
  expected_minor(2, 0) = 13;
  expected_minor(2, 1) = 14;
  expected_minor(2, 2) = 16;

  S21Matrix minor = matrix.Minor(1, 2);

  ASSERT_TRUE(minor == expected_minor);
}

TEST(test_methods, minor_3) {
  S21Matrix matrix(1, 1);

  ASSERT_ANY_THROW(matrix.Minor(0, 0));
}

TEST(test_methods, minor_4) {
  S21Matrix matrix(2, 2);
  S21Matrix expected_minor(1, 1);

  matrix(0, 0) = 1;
  matrix(0, 1) = 2;
  matrix(1, 0) = 3;
  matrix(1, 1) = 4;

  expected_minor(0, 0) = 4;

  S21Matrix minor = matrix.Minor(0, 0);

  ASSERT_TRUE(minor == expected_minor);
}

TEST(test_methods, inverse_1) {
  S21Matrix matrix(3, 3);

  matrix(0, 0) = 2;
  matrix(0, 1) = -1;
  matrix(0, 2) = 0;
  matrix(1, 0) = -1;
  matrix(1, 1) = 2;
  matrix(1, 2) = -1;
  matrix(2, 0) = 0;
  matrix(2, 1) = -1;
  matrix(2, 2) = 2;

  S21Matrix expected(3, 3);
  expected(0, 0) = 3.0 / 4;
  expected(0, 1) = 1.0 / 2;
  expected(0, 2) = 1.0 / 4;
  expected(1, 0) = 1.0 / 2;
  expected(1, 1) = 1;
  expected(1, 2) = 1.0 / 2;
  expected(2, 0) = 1.0 / 4;
  expected(2, 1) = 1.0 / 2;
  expected(2, 2) = 3.0 / 4;

  S21Matrix result = matrix.InverseMatrix();
  ASSERT_TRUE(result == expected);
}

TEST(test_methods, inverse_2) {
  S21Matrix matrix(2, 2);

  matrix(0, 0) = 4;
  matrix(0, 1) = 7;
  matrix(1, 0) = 2;
  matrix(1, 1) = 6;

  S21Matrix expected(2, 2);
  expected(0, 0) = 0.6;
  expected(0, 1) = -0.7;
  expected(1, 0) = -0.2;
  expected(1, 1) = 0.4;

  S21Matrix result = matrix.InverseMatrix();
  ASSERT_TRUE(result == expected);
}

TEST(test_methods, inverse_3) {
  S21Matrix matrix(2, 2);

  matrix(0, 0) = 1;
  matrix(0, 1) = 2;
  matrix(1, 0) = 2;
  matrix(1, 1) = 4;

  EXPECT_THROW(matrix.InverseMatrix(), std::invalid_argument);
}

TEST(test_methods, inverse_4) {
  S21Matrix matrix(1, 1);
  matrix(0, 0) = 5;

  S21Matrix expected(1, 1);
  expected(0, 0) = 0.2;

  S21Matrix result = matrix.InverseMatrix();
  ASSERT_TRUE(result == expected);
}

TEST(test_methods, inverse_5_exc) {
  S21Matrix matrix(2, 3);
  matrix(0, 0) = 1;
  matrix(0, 1) = 2;
  matrix(0, 2) = 3;
  matrix(1, 0) = 4;
  matrix(1, 1) = 5;
  matrix(1, 2) = 6;

  EXPECT_THROW(matrix.InverseMatrix(), std::invalid_argument);
}

// =================== OPERATORS overloads ====================

TEST(test_operators, access_1) {
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

TEST(test_operators, access_2_exc) {
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

TEST(test_operators, sum_matrix_4) {
  S21Matrix a(100, 100);
  S21Matrix b(100, 100);
  a(0, 0) = 1000.1;
  b(0, 0) = 1;
  S21Matrix c;

  c = a + b;

  ASSERT_EQ(c(0, 0), 1001.1);
  ASSERT_EQ(a(0, 0), 1000.1);
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

TEST(test_operators, sub_matrix_4) {
  S21Matrix a(2, 3);
  S21Matrix b(2, 3);
  a(0, 0) = 2;
  b(0, 0) = 11;
  S21Matrix c;

  c = a - b;

  ASSERT_EQ(c(0, 0), -9.0);
  ASSERT_EQ(a(0, 0), 2.0);
  ASSERT_EQ(b(0, 0), 11.0);
}

TEST(test_operators, mult_matrix_num_1) {
  S21Matrix a(2);
  double num = 2;

  a(0, 0) = 1;
  a(0, 1) = 2;
  a(1, 0) = 3;
  a(1, 1) = 4;

  a *= num;

  ASSERT_EQ(a(0, 0), 2);
  ASSERT_EQ(a(0, 1), 4);
  ASSERT_EQ(a(1, 0), 6);
  ASSERT_EQ(a(1, 1), 8);
  ASSERT_EQ(a.getCols(), 2);
  ASSERT_EQ(a.getRows(), 2);
}

TEST(test_operators, mult_matrix_num_2) {
  S21Matrix a(2);
  double num = 2;
  S21Matrix r;

  a(0, 0) = 1;
  a(0, 1) = 2;
  a(1, 0) = 3;
  a(1, 1) = 4;

  r = a * num;

  ASSERT_EQ(r(0, 0), 2);
  ASSERT_EQ(r(0, 1), 4);
  ASSERT_EQ(r(1, 0), 6);
  ASSERT_EQ(r(1, 1), 8);
  ASSERT_EQ(r.getCols(), 2);
  ASSERT_EQ(r.getRows(), 2);
}

TEST(test_operators, mult_matrix_matrix) {
  S21Matrix a(2);
  S21Matrix b(2);

  a(0, 0) = 1;
  a(0, 1) = 2;
  a(1, 0) = 3;
  a(1, 1) = 4;

  b(0, 0) = 1;
  b(0, 1) = 2;
  b(1, 0) = 3;
  b(1, 1) = 4;

  a *= b;

  ASSERT_EQ(a(0, 0), 7);
  ASSERT_EQ(a(0, 1), 10);
  ASSERT_EQ(a(1, 0), 15);
  ASSERT_EQ(a(1, 1), 22);
  ASSERT_EQ(a.getCols(), 2);
  ASSERT_EQ(a.getRows(), 2);
}

TEST(test_operators, mult_matrix_matrix_2) {
  S21Matrix a(2);
  S21Matrix b(2);
  S21Matrix c;

  a(0, 0) = 1;
  a(0, 1) = 2;
  a(1, 0) = 3;
  a(1, 1) = 4;

  b(0, 0) = 1;
  b(0, 1) = 2;
  b(1, 0) = 3;
  b(1, 1) = 4;

  c = a * b;

  EXPECT_EQ(c(0, 0), 7);
  EXPECT_EQ(c(0, 1), 10);
  EXPECT_EQ(c(1, 0), 15);
  EXPECT_EQ(c(1, 1), 22);
  EXPECT_EQ(c.getCols(), 2);
  EXPECT_EQ(c.getRows(), 2);
}

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}